
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1400482f0(longlong param_1,longlong param_2,longlong param_3,uint param_4)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  undefined1 auStackY_108 [32];
  int local_d8 [2];
  undefined1 local_d0 [8];
  undefined8 local_c8;
  char local_b8 [128];
  ulonglong local_38;
  
  local_38 = DAT_1400698c0 ^ (ulonglong)auStackY_108;
  uVar5 = (ulonglong)param_4;
  iVar6 = 0;
  local_d8[0] = 0;
  if (param_2 == 0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  lVar4 = *(longlong *)(param_1 + 8);
  iVar10 = 0;
  iVar9 = 0;
  iVar11 = 1;
  uVar2 = *(uint *)(lVar4 + 0x26b0);
  iVar7 = iVar9;
  if (uVar2 < 0x93) {
    if (uVar2 == 0x92) goto LAB_140048413;
    if (uVar2 < 0x2e) {
      if (uVar2 == 0x2d) {
        if (*(uint *)(param_2 + 0x2d8) != 2) {
          local_d8[0] = iVar6;
          if (*(uint *)(param_2 + 0x2d8) < 2) {
            local_d8[0] = -0x140000;
          }
          goto LAB_1400486f0;
        }
        goto LAB_1400486e8;
      }
      if (((uVar2 - 2 & 0xfffffff9) == 0) && (uVar2 != 8)) {
        bVar12 = *(int *)(param_2 + 0x2d8) == 6;
LAB_140048383:
        iVar7 = iVar10;
        if ((!bVar12) || (iVar7 = iVar9, *(undefined **)(param_3 + 8) != &DAT_14005fd20))
        goto LAB_14004870b;
        local_d8[0] = 0x60000;
        iVar10 = iVar11;
      }
      else {
        if (uVar2 == 0xe) goto LAB_140048473;
        if (((uVar2 != 0x1a) || (*(int *)(param_2 + 0x2d8) != 0)) ||
           (*(undefined **)(param_3 + 8) != &DAT_14005fd20)) goto LAB_14004870b;
        local_d8[0] = -0x5e666;
        iVar10 = iVar11;
      }
      goto LAB_1400486f6;
    }
    if (uVar2 == 0x2e) {
      local_d8[0] = iVar6;
      if (*(int *)(param_2 + 0x2d8) == 1) {
        local_d8[0] = -0x140000;
      }
      goto LAB_1400486f0;
    }
    if (uVar2 == 0x2f) {
      if (*(undefined **)(param_3 + 8) != &DAT_14005fd20) goto LAB_14004870b;
      if (*(int *)(param_2 + 0x32c) == 0) {
        if (*(int *)(param_2 + 0x2d8) == 0) {
          iVar8 = -0x140000;
          local_d8[0] = iVar8;
          iVar6 = iVar8;
        }
        else {
          iVar8 = -0x60000;
          local_d8[0] = iVar8;
          iVar6 = iVar8;
        }
      }
      else {
        iVar8 = 0xa0000;
        local_d8[0] = iVar8;
        iVar6 = iVar8;
      }
    }
    else {
      if (uVar2 != 0x3c) {
        if (uVar2 != 0x42) goto LAB_14004870b;
        goto LAB_140048413;
      }
LAB_140048473:
      iVar8 = 0x140000;
      local_d8[0] = 0x140000;
      iVar6 = 0x140000;
      if ((*(uint *)(lVar4 + 0x2374) & 0x200) != 0) {
        iVar8 = 0;
        local_d8[0] = 0;
        iVar6 = 0;
      }
      iVar3 = *(int *)(param_2 + 0x2d8);
      if ((iVar3 == 1) || (iVar3 == 2)) {
        local_d8[0] = -0x26666;
        if (*(int *)(lVar4 + 0x26b4) != 0x3c) {
          local_d8[0] = -0x44ccc;
        }
        goto LAB_1400486f0;
      }
      if ((iVar3 != 8) || (*(undefined **)(param_3 + 8) != &DAT_14005fd20)) goto LAB_14004870b;
    }
    iVar7 = *(short *)(*(longlong *)(param_3 + 0x18) + 0x2c) * 0x100;
    bVar12 = SBORROW4(iVar7,iVar6);
    iVar6 = iVar7 - iVar6;
  }
  else {
    if (uVar2 != 0xa3) {
      if ((uVar2 == 0xaf) || (uVar2 == 0xb0)) {
        local_d8[0] = iVar6;
        if (*(int *)(param_2 + 0x2d8) == 0) {
          local_d8[0] = -0x106666;
        }
        goto LAB_1400486f0;
      }
      if (((uVar2 != 0xb1) && (uVar2 != 0xb4)) && (uVar2 != 0xb5)) {
        if (uVar2 == 0xbc) {
          if ((*(int *)(param_2 + 0x2d8) != 6) || (*(undefined **)(param_3 + 8) != &DAT_14005fd20))
          goto LAB_14004870b;
          local_d8[0] = 0xfcccc;
          iVar10 = iVar11;
        }
        else {
          if (uVar2 != 0xbd) {
            if (uVar2 != 0xcb) goto LAB_14004870b;
            bVar12 = (*(int *)(param_2 + 0x2d8) - 6U & 0xfffffffd) == 0;
            goto LAB_140048383;
          }
          if ((*(int *)(param_2 + 0x2d8) != 1) || (*(undefined **)(param_3 + 8) != &DAT_14005fd20))
          goto LAB_14004870b;
          local_d8[0] = -0x10cccc;
          iVar10 = iVar11;
        }
        goto LAB_1400486f6;
      }
    }
LAB_140048413:
    iVar6 = *(int *)(param_2 + 0x2d8);
    if (iVar6 == 1) {
      uVar2 = *(uint *)(lVar4 + 0x26b4);
      if (uVar2 < 0x6c) {
        if (uVar2 != 0x6b) {
          if (uVar2 < 0x5c) {
            if (uVar2 == 0x5b) goto LAB_1400486e8;
            if (uVar2 < 0x54) {
              if ((uVar2 == 0x53) || (uVar2 == 0x4b)) goto LAB_1400486e8;
              iVar6 = uVar2 - 0x4c;
              bVar12 = iVar6 == 0;
            }
            else {
              iVar6 = uVar2 - 0x54;
              bVar12 = iVar6 == 0;
            }
          }
          else if (uVar2 < 100) {
            if (uVar2 == 99) goto LAB_1400486e8;
            iVar6 = uVar2 - 0x5c;
            bVar12 = iVar6 == 0;
          }
          else {
            iVar6 = uVar2 - 100;
            bVar12 = iVar6 == 0;
          }
LAB_140048662:
          if ((((!bVar12) && (iVar6 != 1)) && (iVar6 != 2)) &&
             (((iVar6 != 3 && (iVar6 != 4)) && ((iVar6 != 5 && (iVar6 != 6)))))) goto LAB_1400486f0;
        }
      }
      else if (uVar2 < 0xca) {
        if (uVar2 != 0xc9) {
          if (uVar2 < 0x84) {
            if (uVar2 != 0x83) {
              if (uVar2 < 0x74) {
                if (uVar2 != 0x73) {
                  iVar6 = uVar2 - 0x6c;
                  bVar12 = iVar6 == 0;
                  goto LAB_140048662;
                }
              }
              else if (((uVar2 != 0x74) && (uVar2 != 0x75)) &&
                      ((uVar2 != 0x76 && ((uVar2 != 0x77 && (uVar2 != 0x78)))))) {
                if (uVar2 != 0x82) goto LAB_1400486f0;
                goto LAB_1400486c4;
              }
              goto LAB_1400486e8;
            }
          }
          else if ((((0x8b < uVar2) || (uVar2 == 0x8b)) || (uVar2 == 0x84)) ||
                  ((uVar2 == 0x85 || (uVar2 != 0x86)))) goto LAB_1400486f0;
LAB_1400486c4:
          local_d8[0] = -0x5e666;
          goto LAB_1400486f0;
        }
      }
      else if (uVar2 != 0xca) goto LAB_1400486f0;
LAB_1400486e8:
      local_d8[0] = -0x60000;
    }
    else if ((iVar6 == 6) || (iVar6 == 8)) {
      local_d8[0] = 0x86666;
      if (*(int *)(lVar4 + 0x26b4) == 0x5b) {
        local_d8[0] = 0xc0000;
      }
      if ((*(int *)(lVar4 + 0x26b4) - 0x7eU < 4) && (iVar6 == 8)) {
        local_d8[0] = 0xc0000;
      }
    }
LAB_1400486f0:
    iVar10 = iVar9;
    if (*(undefined **)(param_3 + 8) != &DAT_14005fd20) goto LAB_14004870b;
LAB_1400486f6:
    iVar7 = *(short *)(*(longlong *)(param_3 + 0x18) + 0x2c) * 0x100;
    bVar12 = SBORROW4(iVar7,local_d8[0]);
    iVar6 = iVar7 - local_d8[0];
    iVar8 = local_d8[0];
  }
  if (bVar12 == iVar6 < 0) {
    iVar7 = iVar8;
  }
  *(int *)(param_3 + 0x20 + uVar5 * 4) = iVar7;
  iVar7 = iVar10;
LAB_14004870b:
  sVar1 = *(short *)(*(longlong *)(param_1 + 8) + 0x26a8);
  if (sVar1 == 0x929) {
    if ((*(undefined **)(param_3 + 8) == &DAT_14005fd20) && (*(int *)(param_2 + 0x32c) == 0)) {
      *(undefined4 *)(param_3 + 0x20 + uVar5 * 4) = 0xffd30000;
    }
  }
  else if (sVar1 == 0x400d) {
    if (*(undefined **)(param_3 + 8) == &DAT_14005fd20) {
      *(undefined4 *)(param_3 + 0x20 + uVar5 * 4) = 0xe9999;
    }
    else if ((*(undefined **)(param_3 + 8) == &DAT_14005fd30) && (*(int *)(param_2 + 0x32c) != 0)) {
      iVar6 = 0x14;
      if (*(int *)(*(longlong *)(param_1 + 8) + 0xad8) == 1) {
        iVar6 = iVar11;
      }
      *(int *)(param_3 + 0x84) = iVar6;
    }
  }
  else if (((sVar1 == 0x4802) && (*(undefined **)(param_3 + 8) == &DAT_14005fd20)) &&
          (*(int *)(param_2 + 0x32c) == 0)) {
    *(undefined4 *)(param_3 + 0x20 + uVar5 * 4) = 0;
  }
  if ((iVar7 != 0) && (iVar6 = RtlStringFromGUID(*(undefined8 *)(param_3 + 8),local_d0), -1 < iVar6)
     ) {
    FUN_14002f25c(local_b8,0x80,L"%ws,%d",local_c8);
    FUN_14003cd74(param_2,0x14005c340,local_b8,4,4,local_d8);
    RtlFreeUnicodeString(local_d0);
  }
  return;
}

