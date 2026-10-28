"""Read-only inventory of the supplied Realtek MDTR data and Windows INFs.

The MDTR structure is inferred from this package, with bounds and contiguity
validation. This tool records bytes and candidate identities, never USB writes.
Names such as FWSPI64 are retained labels, not proof of the driver's use of them.
"""

from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import io
import json
from pathlib import Path
import re
import struct
import zipfile


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def location(offset: int, size: int) -> dict:
    return {"offset": offset, "offset_hex": hex(offset), "size": size}


def identity(path: Path, data: bytes) -> dict:
    return {"path": str(path), "size": len(data), "sha256": digest(data)}


def span(data: bytes, start: int, size: int) -> bytes:
    if start < 0 or size < 0 or start + size > len(data):
        raise ValueError(f"Out-of-bounds range {start:#x}+{size:#x}")
    return data[start:start + size]


def strings(data: bytes, terms: tuple[str, ...]) -> list[dict]:
    rows = []
    for pattern, encoding in ((rb"[ -~]{6,}", "ascii"),
                              (rb"(?:[ -~]\x00){6,}", "utf-16le")):
        for match in re.finditer(pattern, data):
            value = match.group().decode(encoding)
            if any(term.casefold() in value.casefold() for term in terms):
                rows.append({**location(match.start(), len(match.group())),
                             "encoding": encoding, "text": value})
    return sorted(rows, key=lambda row: row["offset"])


def inspect_mdtr(path: Path, target_id: int) -> dict:
    data = path.read_bytes()
    magic, declared_size, mapping_count, profile_count = struct.unpack_from(
        "<4sIII", span(data, 0, 16)
    )
    if magic != b"MDTR" or declared_size != len(data):
        raise ValueError("Not a supported MDTR container, or size mismatch")
    # Both tables have 28-byte entries in the selected artifact.
    profile_table = 16 + 28 * mapping_count
    payload_start = profile_table + 28 * profile_count
    span(data, 16, 28 * (mapping_count + profile_count))
    mappings = []
    for index in range(mapping_count):
        offset = 16 + index * 28
        fields = struct.unpack_from("<7I", data, offset)
        if fields[5] >= profile_count:
            raise ValueError("Candidate profile index outside table")
        mappings.append({
            "index": index, **location(offset, 28),
            "raw_dwords": [hex(value) for value in fields],
            "candidate_id_start": f"{fields[0]:08x}",
            "candidate_id_end": f"{fields[1]:08x}",
            "candidate_vid": f"{fields[0] >> 16:04x}",
            "candidate_pid": f"{fields[0] & 0xffff:04x}",
            "candidate_profile_index": fields[5],
            "target_in_candidate_range": fields[0] <= target_id <= fields[1],
            "unknown_dwords_2_3_4_6": [hex(fields[n]) for n in (2, 3, 4, 6)],
        })
    profiles = []
    next_offset = payload_start
    for index in range(profile_count):
        table_offset = profile_table + index * 28
        offset, block_count, size = struct.unpack_from("<3I", data, table_offset)
        name_bytes = span(data, table_offset + 12, 16)
        name = name_bytes.split(b"\0", 1)[0].decode("ascii")
        profile = span(data, offset, size)
        if offset != next_offset:
            raise ValueError("Profile payloads are not contiguous")
        cursor = offset
        blocks = []
        for block_index in range(block_count):
            header = span(data, cursor, 36)
            label = header[:28].decode("utf-16le").split("\0", 1)[0]
            unknown, payload_size = struct.unpack_from("<II", header, 28)
            payload_offset = cursor + 36
            payload = span(data, payload_offset, payload_size)
            if payload_offset + payload_size > offset + size:
                raise ValueError("Block escapes profile")
            block = {
                "index": block_index, "label": label,
                "header_location": location(cursor, 36),
                "unknown_header_u32_at_28": hex(unknown),
                "payload_location": location(payload_offset, payload_size),
                "sha256": digest(payload), "first_32_bytes": payload[:32].hex(),
            }
            if payload.startswith(b"PK\x03\x04"):
                with zipfile.ZipFile(io.BytesIO(payload)) as archive:
                    if archive.testzip() is not None:
                        raise ValueError("Nested archive CRC failure")
                    block["nested_zip_members"] = [
                        {"path": member.filename, "size": member.file_size,
                         "sha256": digest(archive.read(member)),
                         "zip_relative_local_header": member.header_offset,
                         "compression_method": member.compress_type}
                        for member in archive.infolist()
                    ]
            block["microphone_label_strings"] = strings(
                payload, ("Microphone", "Rear Mic", "Front Mic")
            )
            for row in block["microphone_label_strings"]:
                row["absolute_offset"] = payload_offset + row["offset"]
                row["absolute_offset_hex"] = hex(row["absolute_offset"])
            blocks.append(block)
            cursor = payload_offset + payload_size
        if cursor != offset + size:
            raise ValueError("Block walk does not consume entire profile")
        profiles.append({
            "index": index, "name": name,
            "table_location": location(table_offset, 28),
            "name_field_hex": name_bytes.hex(),
            "payload_location": location(offset, size),
            "block_count": block_count, "sha256": digest(profile),
            "blocks": blocks,
        })
        next_offset = cursor
    if next_offset != len(data):
        raise ValueError("Unaccounted trailing bytes")
    return {
        "artifact": identity(path, data),
        "source": "Ordinary Python parser; not a REA Evidence record",
        "header": {"magic": "MDTR", "declared_size": declared_size,
                   "mapping_count": mapping_count, "profile_count": profile_count},
        "inferred_structure": {
            "mapping_table": location(16, 28 * mapping_count),
            "profile_table": location(profile_table, 28 * profile_count),
            "payloads": location(payload_start, len(data) - payload_start),
        },
        "validation": {"all_ranges_within_file": True,
                       "all_profile_and_block_ranges_contiguous": True,
                       "last_profile_ends_at_eof": True,
                       "nested_zip_crcs_checked": True},
        "target_id_candidate": f"{target_id:08x}",
        "target_mappings": [row for row in mappings if row["target_in_candidate_range"]],
        "block_label_counts": dict(Counter(block["label"] for profile in profiles
                                           for block in profile["blocks"])),
        "mappings": mappings, "profiles": profiles,
        "limitations": [
            "Container structure is inferred from the selected artifact; driver consumer semantics require code analysis.",
            "VID/PID and range/index meanings are candidates corroborated by adjacent human-readable device labels.",
            "Unknown header words are preserved without invented meanings.",
            "Firmware labels and strings do not establish installation, execution, or safe reuse on another device.",
        ],
    }


def inspect_infs(root: Path, hardware_id: str) -> list[dict]:
    rows = []
    for path in sorted(root.rglob("*.inf")):
        data = path.read_bytes()
        encoding = "utf-16" if data.startswith((b"\xff\xfe", b"\xfe\xff")) else "utf-8-sig"
        text = data.decode(encoding)
        offset = 0
        section = ""
        matches = []
        for number, line in enumerate(text.splitlines(keepends=True), 1):
            stripped = line.strip()
            if stripped.startswith("[") and stripped.endswith("]"):
                section = stripped[1:-1]
            if hardware_id.casefold() in line.casefold():
                matches.append({"line": number, "section": section, "text": stripped})
            offset += len(line)
        rows.append({"artifact": identity(path, data), "target_matches": matches})
    return rows


def inspect_ancillary(root: Path, evidence_root: Path, target_id: int) -> list[dict]:
    rows = []
    for filename in ("service-conf-resources.json", "service-res-resources.json",
                     "cfg-resources.json"):
        evidence_path = evidence_root / filename
        if not evidence_path.exists():
            continue
        evidence = json.loads(evidence_path.read_text(encoding="utf-8-sig"))
        result = evidence["normalized_result"]
        binary = Path(result["artifact"]["path"])
        data = binary.read_bytes()
        if digest(data) != result["artifact"]["sha256"]:
            raise ValueError("PE resource Evidence source changed")
        resources = []
        for resource in result["resources"]:
            if resource["type"].get("name") not in ("DAT", "TXT", "REGISTRY"):
                continue
            loc = resource["payload"]["location"]
            payload = span(data, loc["offset"], loc["bytes"])
            if digest(payload) != resource["payload"]["sha256"]:
                raise ValueError("PE resource payload digest mismatch")
            item = {"type": resource["type"].get("name"),
                    "name": resource["name"],
                    "payload_location": location(loc["offset"], loc["bytes"]),
                    "sha256": digest(payload)}
            if item["type"] == "TXT":
                item["text"] = payload.decode("ascii")
            resources.append(item)
        rows.append({"artifact": identity(binary, data),
                     "rea_evidence_id": evidence["evidence_id"],
                     "resources": resources,
                     "target_le_u32_offsets": [m.start() for m in re.finditer(
                         re.escape(struct.pack("<I", target_id)), data)]})
    for filename in ("RtkApi64U.dll", "RtkAudUService64.exe"):
        binary = root / "Realtek" / "RealtekService_771.8" / filename
        data = binary.read_bytes()
        rows.append({"artifact": identity(binary, data),
                     "source": "Ordinary string scan; not native behavior evidence",
                     "strings": strings(data, ("MicBoost", "MicBias", "JackRetask",
                                               "SetRetask", "VolCtrl_AsBoost"))})
    return rows


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(
        "observations/driver_reverse_engineering/package/Win11/USBAud/Win64"))
    parser.add_argument("--target", default="0b05:1b9b")
    parser.add_argument("--output", type=Path, default=Path(
        "observations/driver_reverse_engineering/configuration-inventory.json"))
    args = parser.parse_args()
    vid, pid = (int(value, 16) for value in args.target.split(":"))
    if not (0 <= vid <= 0xffff and 0 <= pid <= 0xffff):
        raise ValueError("USB VID/PID out of bounds")
    target_id = (vid << 16) | pid
    result = {
        "dat": inspect_mdtr(args.root / "RTUSBAIODAT.DAT", target_id),
        "infs": inspect_infs(args.root, f"VID_{vid:04X}&PID_{pid:04X}"),
        "ancillary": inspect_ancillary(args.root, args.output.parent, target_id),
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"output": str(args.output.resolve()),
                      "dat_sha256": result["dat"]["artifact"]["sha256"],
                      "mapping_count": len(result["dat"]["mappings"]),
                      "profile_count": len(result["dat"]["profiles"]),
                      "target_mappings": result["dat"]["target_mappings"],
                      "block_labels": result["dat"]["block_label_counts"]}, indent=2))


if __name__ == "__main__":
    main()
