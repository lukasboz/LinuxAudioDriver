
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14004ef6c(longlong param_1)

{
  int iVar1;
  undefined8 *puVar2;
  uint *puVar3;
  void *_Dst;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 auStack_1b8 [32];
  wchar_t *local_198;
  longlong local_188;
  longlong local_180;
  uint local_178;
  uint local_174;
  int local_170;
  undefined8 local_168;
  ulonglong uStack_160;
  undefined1 local_148 [16];
  wchar_t local_138 [4];
  wchar_t awStack_130 [4];
  wchar_t local_128 [4];
  undefined1 local_120 [232];
  ulonglong local_38;
  
  if (param_1 == 0) {
    return;
  }
  local_38 = DAT_1400698c0 ^ (ulonglong)auStack_1b8;
  local_180 = 0;
  local_170 = 0;
  local_138 = (wchar_t  [4])u_RTUSBAIODAT_14005dc00._0_8_;
  awStack_130 = (wchar_t  [4])u_RTUSBAIODAT_14005dc00._8_8_;
  local_128 = (wchar_t  [4])u_RTUSBAIODAT_14005dc00._16_8_;
  local_188 = param_1;
  memset(local_120,0,0xe8);
  if (*(int *)(param_1 + 0x2368) == 0) {
    local_198 = L"2393";
    FUN_14002f25c((char *)local_138,0x100,L"%ws.%ws",local_138);
  }
  else {
    FUN_14002f25c((char *)local_138,0x100,L"%ws",local_138);
  }
  iVar1 = FUN_14004ece8(&local_188,(longlong)local_138,*(int *)(param_1 + 0x2368));
  lVar9 = local_180;
  if ((iVar1 < 0) || (local_180 == 0)) goto LAB_14004f24f;
  uVar4 = local_174 + 0x10;
  if (local_178 < uVar4) goto LAB_14004f24f;
  local_148 = *(undefined1 (*) [16])((ulonglong)local_174 + local_180);
  uVar5 = local_148._8_4_;
  uVar8 = uVar5 * 0x1c;
  local_174 = uVar4;
  if (((local_148._0_4_ != 0x5254444d) ||
      (local_148._0_8_ >> 0x20 < (ulonglong)(local_148._12_4_ * 0x1c + uVar8) + 0x10)) ||
     (puVar2 = (undefined8 *)ExAllocatePoolWithTag(1,uVar8), lVar9 = local_180,
     puVar2 == (undefined8 *)0x0)) goto LAB_14004f24f;
  if (local_180 != 0) {
    uVar4 = uVar8 + local_174;
    if (uVar4 <= local_178) {
      FUN_14005b100(puVar2,(undefined8 *)(local_180 + (ulonglong)local_174),(ulonglong)uVar8);
      uVar6 = 0;
      do {
        if ((uint)uVar6 == uVar5) {
          uVar8 = *(uint *)(param_1 + 0x2574);
          if (uVar8 != 0) {
LAB_14004f16d:
            if (uVar8 <= (uint)local_148._12_4_) {
LAB_14004f177:
              uVar4 = uVar4 + uVar8 * 0x1c;
              if (local_178 < uVar4) {
                uVar4 = local_178;
              }
              if (uVar4 + 0x1c <= local_178) {
                local_168 = *(undefined8 *)((ulonglong)uVar4 + lVar9);
                uVar6 = ((undefined8 *)((ulonglong)uVar4 + lVar9))[1];
                uVar4 = (uint)uVar6;
                uStack_160 = uVar6;
                _Dst = (void *)ExAllocatePoolWithTag(1,(uVar6 & 0xffffffff) + 0x24,0x5254444d);
                *(void **)(param_1 + 0x26c8) = _Dst;
                if (_Dst != (void *)0x0) {
                  memset(_Dst,0,(uVar6 & 0xffffffff) + 0x24);
                  uVar8 = (uint)local_168;
                  if (local_178 < (uint)local_168) {
                    uVar8 = local_178;
                  }
                  if (local_178 < uVar8 + uVar4) goto LAB_14004f226;
                  FUN_14005b100(*(undefined8 **)(param_1 + 0x26c8),
                                (undefined8 *)((ulonglong)uVar8 + lVar9),uVar6 & 0xffffffff);
                  lVar7 = *(longlong *)(param_1 + 0x26c8);
                  uVar5 = 0;
                  uVar8 = *(uint *)(lVar7 + 0x20);
                  if (uVar8 != 0) goto LAB_14004f20a;
                  goto LAB_14004f226;
                }
              }
            }
          }
          break;
        }
        puVar3 = (uint *)(uVar6 * 0x1c + (longlong)puVar2);
        if (((*puVar3 == 0) ||
            ((*puVar3 <= *(uint *)(param_1 + 0x26a8) && (*(uint *)(param_1 + 0x26a8) <= puVar3[1])))
            ) && ((*(int *)(param_1 + 0x26a8) != 0x17ef306f ||
                  ((*(int *)(param_1 + 0x2740) == 0 || (puVar3[4] == 0x4032)))))) {
          uVar8 = puVar3[5];
          if (uVar8 != 0) goto LAB_14004f16d;
          goto LAB_14004f177;
        }
        uVar8 = (uint)uVar6 + 1;
        uVar6 = (ulonglong)uVar8;
      } while (uVar8 <= uVar5);
    }
  }
  goto LAB_14004f23d;
  while (uVar8 = *(uint *)(lVar7 + 0x20), uVar8 != 0) {
LAB_14004f20a:
    uVar5 = uVar5 + uVar8;
    lVar7 = lVar7 + 0x24 + (ulonglong)uVar8;
    if (uVar4 < uVar5) break;
  }
  if ((uVar5 == 0) || (uVar4 < uVar5)) {
LAB_14004f226:
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x26c8),0);
    *(undefined8 *)(param_1 + 0x26c8) = 0;
  }
LAB_14004f23d:
  ExFreePoolWithTag(puVar2,0);
LAB_14004f24f:
  if ((local_170 == 0) && (lVar9 != 0)) {
    ExFreePoolWithTag(lVar9,0);
  }
  return;
}

