
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_14004db18(longlong param_1,uint param_2,longlong param_3,uint *param_4)

{
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  undefined1 uVar4;
  short *psVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  uint *puVar13;
  bool bVar14;
  bool bVar15;
  undefined1 auStackY_208 [32];
  undefined1 local_1b8;
  short local_1b4 [2];
  undefined1 local_1b0;
  undefined1 local_1af;
  uint local_1ac;
  undefined4 local_1a8;
  int local_1a4;
  uint *local_1a0;
  longlong local_198;
  short *local_190;
  undefined8 local_188;
  longlong local_180;
  uint *local_178;
  undefined1 local_170 [8];
  undefined8 local_168;
  char local_158 [128];
  char local_d8 [128];
  ulonglong local_58;
  
  local_58 = DAT_1400698c0 ^ (ulonglong)auStackY_208;
  if (*(uint *)(param_1 + 0x210) <= param_2) {
    return -0x3ffffff3;
  }
  lVar11 = (ulonglong)param_2 * 0x98 + *(longlong *)(param_1 + 0x218);
  puVar3 = *(undefined **)(lVar11 + 8);
  if (puVar3 == &DAT_14005fd30) {
    local_1a4 = 0;
  }
  else {
    local_1a4 = *(int *)(param_3 + 0x20);
    if (local_1a4 == -1) {
      return -0x3ffffff3;
    }
  }
  iVar10 = local_1a4;
  if ((int)(uint)*(byte *)(*(longlong *)(lVar11 + 0x18) + 0x26) <= local_1a4) {
    return -0x3ffffff3;
  }
  local_1a8 = 1;
  local_1ac = param_2;
  local_198 = param_3;
  local_180 = lVar11;
  local_178 = param_4;
  if (puVar3 == &DAT_14005fd20) {
    local_1a0 = (uint *)(lVar11 + ((longlong)local_1a4 + 8) * 4);
    if (((*(int *)(*(longlong *)(param_1 + 0x2d0) + 0x26b4) == 0x11) &&
        ((*(int *)(param_1 + 0x2c8) - 1U & 0xfffffffd) == 0)) && (local_1a4 == 1)) {
      local_1a0 = (uint *)(lVar11 + 0x20);
    }
    puVar13 = local_1a0;
    if (*(longlong *)(param_1 + 0x390) != 0) {
      KeWaitForSingleObject(param_1 + 0x3b8,0,0);
      KeReleaseMutex(param_1 + 0x3b8,0);
    }
    local_1b8 = 2;
    local_1a8 = 2;
    if (((*(uint *)(local_198 + 0x14) & 2) == 0) || (param_4 == (uint *)0x0)) goto LAB_14004dcdd;
    iVar8 = (int)*(short *)(*(longlong *)(lVar11 + 0x18) + 0x2c);
    uVar2 = *param_4;
    uVar9 = iVar8 * 0x100;
    if ((int)uVar2 < (int)*(short *)(*(longlong *)(lVar11 + 0x18) + 0x2e) << 8) {
      return -0x3ffffff3;
    }
    bVar15 = SBORROW4(uVar2,uVar9);
    iVar8 = uVar2 + iVar8 * -0x100;
    bVar14 = uVar2 == uVar9;
LAB_14004de18:
    if (!bVar14 && bVar15 == iVar8 < 0) {
      return -0x3ffffff3;
    }
  }
  else {
    if (puVar3 == &DAT_14005fd10) {
      lVar12 = (longlong)local_1a4 + 0x18;
      local_1b8 = 1;
    }
    else {
      if ((puVar3 != &DAT_140061330) && (puVar3 != &DAT_140061108)) {
        if (puVar3 != &DAT_14005fd30) {
          return -0x3ffffff3;
        }
        local_1b8 = *(undefined1 *)(lVar11 + 0x94);
        puVar13 = (uint *)(lVar11 + 0x84);
        local_1a0 = puVar13;
        if (((*(uint *)(param_3 + 0x14) & 2) == 0) || (param_4 == (uint *)0x0)) goto LAB_14004dcdd;
        uVar2 = *param_4;
        if ((int)uVar2 < *(int *)(lVar11 + 0x8c)) {
          return -0x3ffffff3;
        }
        uVar9 = *(uint *)(lVar11 + 0x88);
        bVar15 = SBORROW4(uVar2,uVar9);
        iVar8 = uVar2 - uVar9;
        bVar14 = uVar2 == uVar9;
        goto LAB_14004de18;
      }
      local_1b8 = *(undefined1 *)(lVar11 + 0x94);
      lVar12 = (longlong)local_1a4 + 0x10;
    }
    puVar13 = (uint *)(lVar11 + lVar12 * 4);
    local_1a0 = puVar13;
    if ((((*(uint *)(param_3 + 0x14) & 2) != 0) && (param_4 != (uint *)0x0)) && (1 < *param_4)) {
      return -0x3ffffff3;
    }
  }
LAB_14004dcdd:
  uVar2 = local_1ac;
  iVar6 = 0;
  iVar8 = -0x3ffffff3;
  if (puVar13 != (uint *)0x0) {
    uVar9 = *(uint *)(local_198 + 0x14);
    if ((uVar9 >> 0x10 & 1) == 0) {
      if (param_4 == (uint *)0x0) {
        return -0x3ffffff3;
      }
    }
    else if (param_4 == (uint *)0x0) {
      iVar8 = RtlStringFromGUID(*(undefined8 *)(lVar11 + 8),&local_190);
      if (-1 < iVar8) {
        FUN_14002f25c(local_158,0x80,L"%ws,%d",local_188);
        bVar14 = FUN_14003b590(param_1,0x14005c340,local_158,4,(undefined8 *)puVar13);
        if ((!bVar14) && (*(longlong *)(*(longlong *)(param_1 + 0x2d0) + 0xb18) != 0)) {
          (*(code *)PTR__guard_dispatch_icall_14005f458)
                    (*(undefined8 *)(*(longlong *)(param_1 + 0x2d0) + 0xb18),param_1,lVar11,iVar10);
        }
        FUN_14004db18(param_1,uVar2,local_198,puVar13);
        RtlFreeUnicodeString(&local_190);
      }
      return 0;
    }
    if ((uVar9 & 2) == 0) {
      if ((uVar9 & 1) != 0) {
        *param_4 = *puVar13;
        iVar8 = iVar6;
      }
    }
    else {
      local_1b0 = *param_4 != 0;
      local_1b4[0] = 0;
      local_1af = *(undefined1 *)(*(longlong *)(lVar11 + 0x18) + 4);
      cVar7 = (char)iVar10 + '\x01';
      if (*(char *)(*(longlong *)(lVar11 + 0x18) + 0x26) == '\x01') {
        cVar7 = '\0';
      }
      local_1ac = CONCAT31(local_1ac._1_3_,cVar7);
      if (*(undefined **)(lVar11 + 8) == &DAT_14005fd20) {
        uVar2 = *param_4;
        local_1b4[0] = (short)(uVar2 + ((int)uVar2 >> 0x1f & 0xffU) >> 8);
        if ((int)uVar2 < (int)*(short *)(*(longlong *)(lVar11 + 0x18) + 0x2e) << 8) {
          return -0x3ffffff3;
        }
        if ((int)*(short *)(*(longlong *)(lVar11 + 0x18) + 0x2c) << 8 < (int)uVar2) {
          return -0x3ffffff3;
        }
        if ((*param_4 == 0x80000000) ||
           (lVar12 = *(longlong *)(lVar11 + 0x18), local_1b4[0] < *(short *)(lVar12 + 0x2e))) {
          lVar12 = *(longlong *)(lVar11 + 0x18);
          local_1b4[0] = *(short *)(lVar12 + 0x2e);
        }
        if (*(short *)(lVar12 + 0x30) != 0) {
          sVar1 = *(short *)(*(longlong *)(lVar11 + 0x18) + 0x30);
          local_1b4[0] = (local_1b4[0] / sVar1) * sVar1;
        }
        local_190 = local_1b4;
      }
      else if (*(undefined **)(lVar11 + 8) == &DAT_14005fd10) {
        local_190 = (short *)&local_1b0;
        *(uint *)(param_1 + 0x264) = (uint)(byte)local_1b0;
      }
      else {
        local_190 = (short *)&local_1b0;
      }
      bVar14 = true;
      if (((*(undefined **)(lVar11 + 8) == &DAT_14005fd20) && (*(int *)(param_1 + 0x32c) != 0)) &&
         (bVar14 = true, (*(byte *)(*(longlong *)(param_1 + 0x2d0) + 0x237c) & 2) != 0)) {
        bVar14 = false;
      }
      lVar12 = *(longlong *)(param_1 + 0x2d0);
      if ((((*(int *)(lVar12 + 0x26b4) != 0xbd) || (*(undefined **)(lVar11 + 8) != &DAT_14005fd10))
          || ((*(int *)(param_1 + 0x2d8) != 6 || (iVar10 != 1)))) && (bVar14)) {
        if (((*(uint *)(lVar12 + 0x2380) & 0x80000) != 0) && (*(int *)(lVar12 + 0x26e0) == 3)) {
          FUN_140053630(lVar12);
        }
        psVar5 = local_190;
        uVar2 = local_1ac;
        uVar4 = local_1af;
        iVar10 = 0;
        do {
          iVar6 = FUN_140031890(*(longlong *)(param_1 + 0x2d0),0x21,1,local_1b8,(char)uVar2,uVar4,
                                *(undefined1 *)(*(longlong *)(param_1 + 0x2d0) + 0x26f8),psVar5,
                                local_1a8,'\0');
          if (-1 < iVar6) break;
          FUN_14004cbac(100);
          iVar10 = iVar10 + 1;
        } while (iVar10 < 5);
        lVar11 = local_180;
        puVar13 = local_1a0;
        param_4 = local_178;
        iVar10 = local_1a4;
        if (iVar6 < 0) {
          return iVar6;
        }
      }
      *puVar13 = *param_4;
      if (((*(uint *)(local_198 + 0x14) >> 0x10 & 1) == 0) &&
         (iVar8 = RtlStringFromGUID(*(undefined8 *)(lVar11 + 8),local_170), -1 < iVar8)) {
        FUN_14002f25c(local_d8,0x80,L"%ws,%d",local_168);
        FUN_14003cd74(param_1,0x14005c340,local_d8,4,4,puVar13);
        RtlFreeUnicodeString(local_170);
      }
      iVar8 = iVar6;
      if (((*(longlong *)(*(longlong *)(param_1 + 0x2d0) + 0xb18) == 0) ||
          (iVar6 = (*(code *)PTR__guard_dispatch_icall_14005f458)
                             (*(undefined8 *)(*(longlong *)(param_1 + 0x2d0) + 0xb18),param_1,lVar11
                              ,iVar10), iVar6 < 0)) &&
         (*(longlong *)(*(longlong *)(param_1 + 0x2d0) + 0xb20) != 0)) {
        (*(code *)PTR__guard_dispatch_icall_14005f458)
                  (*(undefined8 *)(*(longlong *)(param_1 + 0x2d0) + 0xb20),param_1,lVar11,iVar10);
      }
    }
  }
  return iVar8;
}

