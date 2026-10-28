"""Extract the Windows 11 USB audio payload and record reproducible identity.

This does not execute or install anything from the driver package.
"""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import zipfile


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def inspect(archive: Path, output: Path) -> dict:
    output.mkdir(parents=True, exist_ok=True)
    root = output.resolve()
    files = []
    with zipfile.ZipFile(archive) as source:
        for info in source.infolist():
            if info.is_dir() or not info.filename.startswith("Win11/USBAud/Win64/"):
                continue
            name = PurePosixPath(info.filename)
            if name.is_absolute() or ".." in name.parts or ":" in info.filename:
                raise ValueError(f"Unsafe archive entry: {info.filename}")
            target = output.joinpath(*name.parts)
            if not target.resolve().is_relative_to(root):
                raise ValueError(f"Entry escapes extraction root: {info.filename}")
            data = source.read(info)
            if target.exists() and target.read_bytes() != data:
                raise ValueError(f"Refusing to overwrite changed file: {target}")
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(data)
            record = {
                "path": info.filename,
                "size": len(data),
                "sha256": sha256(data),
                "crc32": f"{info.CRC:08x}",
            }
            counterpart = info.filename.replace("Win11/", "Win10/", 1)
            if counterpart in source.namelist():
                record["windows_10_identical"] = source.read(counterpart) == data
            files.append(record)
    with archive.open("rb") as stream:
        digest = hashlib.file_digest(stream, "sha256").hexdigest()
    manifest = {
        "archive": archive.name,
        "archive_size": archive.stat().st_size,
        "archive_sha256": digest,
        "scope": "Windows 11 USB audio payload; no installers executed",
        "files": files,
    }
    (output.parent / "package-manifest.json").write_text(
        json.dumps(manifest, indent=2) + "\n", encoding="utf-8"
    )
    return manifest


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("archive", type=Path)
    parser.add_argument(
        "--output", type=Path,
        default=Path("observations/driver_reverse_engineering/package"),
    )
    args = parser.parse_args()
    manifest = inspect(args.archive, args.output)
    print(json.dumps({
        "archive_sha256": manifest["archive_sha256"],
        "extracted_files": len(manifest["files"]),
        "output": str(args.output.resolve()),
    }, indent=2))


if __name__ == "__main__":
    main()
