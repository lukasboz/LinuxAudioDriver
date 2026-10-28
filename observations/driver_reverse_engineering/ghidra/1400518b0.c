
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1400518b0(longlong param_1,short *param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  short *psVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint *puVar7;
  ushort uVar8;
  uint uVar9;
  ushort *puVar10;
  wchar_t *pwVar11;
  uint uVar12;
  double dVar13;
  undefined1 auStackY_b8 [32];
  uint local_68;
  uint local_64;
  int local_60;
  uint local_5c;
  uint local_58 [2];
  short *local_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = DAT_1400698c0 ^ (ulonglong)auStackY_b8;
  uVar12 = 0;
  if ((param_2 == (short *)0x0) && (*(int *)(param_1 + 0x26b0) != 0xa3)) {
    return 0xc000000d;
  }
  local_60 = 0;
  if (param_2 != (short *)0x0) {
    local_60 = *(int *)(param_2 + 0x164);
  }
  local_48 = 0;
  local_50 = param_2;
  uVar5 = FUN_14003197c(param_1,0x17,0x6d,0,2,&local_48,8);
  local_5c = (uint)uVar5;
  if ((int)local_5c < 0) {
    return uVar5;
  }
  puVar10 = (ushort *)&local_48;
  do {
    bVar3 = false;
    uVar8 = *puVar10 >> 8 | *puVar10 << 8;
    uVar1 = *(uint *)(param_1 + 0x2384);
    *puVar10 = uVar8;
    if ((uVar1 & 0x4000) == 0) goto LAB_140051b27;
    if (uVar12 == 3) {
      if (*(int *)(param_1 + 0x26b4) == 0x94) {
        bVar3 = uVar8 < 9;
        uVar8 = uVar8 - 9;
LAB_140051b01:
        *puVar10 = uVar8;
        goto LAB_140051b27;
      }
      if (*(int *)(param_1 + 0x26b4) != 0x82) goto LAB_140051ac3;
      uVar6 = FUN_140017680(param_1);
      bVar3 = (int)(uint)*puVar10 < -(int)uVar6;
      uVar6 = FUN_140017680(param_1);
      uVar8 = (short)uVar6 + *puVar10;
      *puVar10 = uVar8;
      if (uVar8 < 0x96) goto LAB_140051b27;
      dVar13 = (double)uVar8 * _DAT_140061378;
      if (dVar13 <= _DAT_140061380) goto LAB_140051a0a;
LAB_140051b2d:
      *puVar10 = 0x3fe;
    }
    else {
      if ((uVar12 == 1) &&
         ((*(int *)(param_1 + 0x26b4) - 0x8eU < 3 || (*(int *)(param_1 + 0x26b4) == 0x85)))) {
        uVar6 = FUN_140017680(param_1);
        bVar3 = (int)(uint)*puVar10 < -(int)uVar6;
        uVar6 = FUN_140017680(param_1);
        uVar8 = (short)uVar6 + *puVar10;
        iVar2 = *(int *)(param_1 + 0x26b4);
        *puVar10 = uVar8;
        if (iVar2 == 0x85) {
          if ((ushort)(uVar8 - 0x32) < 0xfb) {
            dVar13 = (double)uVar8 * _DAT_140061370;
LAB_140051a0a:
            uVar8 = (ushort)(int)dVar13;
            goto LAB_140051b21;
          }
          if (300 < uVar8) goto LAB_140051ab2;
        }
        else if (0x59 < uVar8) {
LAB_140051ab2:
          dVar13 = (double)uVar8 * _DAT_140061378;
          goto LAB_140051a0a;
        }
      }
      else {
LAB_140051ac3:
        if (*(short *)(param_1 + 0x26a8) == 0x1b9b) {
          uVar6 = FUN_140017680(param_1);
          bVar3 = (int)(uint)*puVar10 < -(int)uVar6;
          uVar6 = FUN_140017680(param_1);
          uVar8 = (short)uVar6 + *puVar10;
          *puVar10 = uVar8;
          if ((ushort)(uVar8 - 0x32) < 0x1f) {
            uVar8 = uVar8 + 4;
            goto LAB_140051b01;
          }
          goto LAB_140051b27;
        }
        uVar6 = FUN_140017680(param_1);
        bVar3 = (int)(uint)*puVar10 < -(int)uVar6;
        uVar6 = FUN_140017680(param_1);
        uVar8 = (short)uVar6 + *puVar10;
LAB_140051b21:
        *puVar10 = uVar8;
      }
LAB_140051b27:
      if (0x3fe < uVar8) goto LAB_140051b2d;
    }
    psVar4 = local_50;
    uVar1 = local_5c;
    iVar2 = local_60;
    if (bVar3) {
      *puVar10 = 0;
    }
    uVar12 = uVar12 + 1;
    puVar10 = puVar10 + 1;
  } while (uVar12 < 4);
  *(undefined8 *)(param_1 + 0x26bc) = local_48;
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
    FUN_1400333a0(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0xe,&DAT_140061360,
                  "CCommon::GetImpedanceSensingResultFromFW");
  }
  uVar12 = *(uint *)(param_1 + 0x26b0);
  uVar8 = (ushort)local_48;
  uVar9 = (uint)local_48;
  if (uVar12 == 0x42) {
    if (iVar2 == 4) {
      if (0x3fe < uVar8) goto LAB_140051ef9;
      uVar9 = uVar9 & 0xffff;
    }
    else {
      if ((iVar2 != 5) || (0x3fe < local_48._2_2_)) goto LAB_140051ef9;
      uVar9 = (uint)local_48._2_2_;
    }
    *(uint *)(psVar4 + 0x136) = uVar9;
    if ((*(int *)(param_1 + 0x26b4) == 0x83) || (*(int *)(param_1 + 0x26b4) == 0x86)) {
      if (0x38d < uVar9) {
        uVar9 = 0x3fe;
      }
      *(uint *)(psVar4 + 0x136) = uVar9;
    }
  }
  else {
    if (((uVar12 != 0xb3) && (0xb0 < uVar12)) && (uVar12 < 0xb6)) {
      if (*(uint *)(psVar4 + 0x164) == (uint)*(byte *)(param_1 + 0xcb2)) {
        if (0x3fe < uVar8) goto LAB_140051ef9;
        uVar9 = uVar9 & 0xffff;
        puVar7 = (uint *)(psVar4 + 0x136);
        *puVar7 = uVar9;
        uVar12 = *(uint *)(param_1 + 0x26b4);
        if (((uVar12 == 0x86) || (uVar12 < 0x84)) || (0x91 < uVar12)) {
          if (0x3fe < uVar9) {
            uVar9 = 0x3fe;
          }
          *puVar7 = uVar9;
        }
        if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
           ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
          FUN_1400209c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0xf,&DAT_140061360,
                        "CCommon::GetImpedanceSensingResultFromFW");
        }
        FUN_14003c4e0(psVar4,0xe,(short *)puVar7,4);
        local_68 = 0;
        local_58[0] = 4;
        uVar5 = FUN_14002db9c((longlong *)(param_1 + 0x2348),0x14005b7c0,L"InstallDriverSPK",
                              local_58,(undefined8 *)&local_68,0,1);
        if ((int)uVar5 < 0) goto LAB_140051ef9;
        local_68 = *puVar7;
        pwVar11 = L"InstallDriverSPK";
        puVar7 = &local_68;
      }
      else {
        if ((*(uint *)(psVar4 + 0x164) != (uint)*(byte *)(param_1 + 0xcb0)) ||
           (0x3fe < local_48._2_2_)) goto LAB_140051ef9;
        puVar7 = (uint *)(psVar4 + 0x136);
        *puVar7 = (uint)local_48._2_2_;
        uVar12 = *(uint *)(param_1 + 0x26b4);
        if ((uVar12 == 0x86) || ((uVar12 < 0x84 || (0x91 < uVar12)))) {
          uVar12 = (uint)local_48._2_2_;
          if (0x3fe < local_48._2_2_) {
            uVar12 = 0x3fe;
          }
          *puVar7 = uVar12;
        }
        if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
           ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
          FUN_1400209c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x10,&DAT_140061360,
                        "CCommon::GetImpedanceSensingResultFromFW");
        }
        FUN_14003c4e0(psVar4,0xe,(short *)puVar7,4);
        local_64 = 0;
        local_58[1] = 4;
        uVar5 = FUN_14002db9c((longlong *)(param_1 + 0x2348),0x14005b7c0,L"InstallDriverHP",
                              local_58 + 1,(undefined8 *)&local_64,0,1);
        if ((int)uVar5 < 0) goto LAB_140051ef9;
        local_64 = *puVar7;
        pwVar11 = L"InstallDriverHP";
        puVar7 = &local_64;
      }
      FUN_140031bac((longlong *)(param_1 + 0x2348),0x14005b7c0,pwVar11,4,4,puVar7,0);
      goto LAB_140051ef9;
    }
    if (((uVar12 != 0xa3) || (iVar2 != 4)) || (0x3fe < uVar8)) goto LAB_140051ef9;
    uVar9 = uVar9 & 0xffff;
    *(uint *)(psVar4 + 0x136) = uVar9;
    if (*(int *)(param_1 + 0x26b4) == 0x82) {
      if (0x38d < uVar9) {
        uVar9 = 0x3fe;
      }
      *(uint *)(psVar4 + 0x136) = uVar9;
    }
  }
  FUN_14003c4e0(psVar4,0xe,psVar4 + 0x136,4);
LAB_140051ef9:
  return (ulonglong)uVar1;
}

