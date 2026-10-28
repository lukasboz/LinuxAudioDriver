
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_140026590(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  undefined7 extraout_var;
  undefined8 uVar12;
  undefined7 extraout_var_00;
  longlong lVar13;
  ushort uVar14;
  undefined2 uVar15;
  int iVar16;
  byte bVar17;
  ushort uVar18;
  undefined1 auStackY_128 [32];
  byte local_f8;
  byte local_f7;
  byte local_f6 [2];
  int local_f4;
  char local_f0 [8];
  ushort local_e8;
  ushort local_e6;
  ushort local_e4;
  ushort local_e2;
  ushort local_e0;
  ushort local_de;
  short local_d8;
  short local_d6;
  short local_d4;
  short local_d2;
  short local_d0;
  short local_ce;
  ushort local_c8;
  ushort local_c6;
  ushort local_c4;
  ushort local_c2;
  ushort local_c0;
  ushort local_be;
  undefined1 local_b8 [8];
  short local_b0;
  short sStack_ae;
  short sStack_ac;
  short sStack_aa;
  undefined4 local_a8;
  ushort local_a0 [8];
  undefined8 local_90;
  undefined8 local_88 [2];
  undefined8 local_78;
  undefined8 uStack_70;
  char local_68;
  undefined1 uStack_67;
  char cStack_66;
  char cStack_65;
  undefined1 uStack_64;
  char cStack_63;
  undefined2 uStack_62;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  
  local_38 = DAT_1400698c0 ^ (ulonglong)auStackY_128;
  iVar9 = 0;
  iVar16 = 0;
  uVar11 = FUN_140026410(param_1,*(short *)(param_1 + 0x26aa),*(short *)(param_1 + 0x26a8));
  if ((int)uVar11 == 0) goto LAB_140026d43;
  local_f4 = 0;
  FUN_14002ebb0(param_1,0xc2a8,local_f0);
  if (local_f0[0] != '\b') {
    iVar9 = iVar16;
    if (((local_f0[0] - 0x10U & 0xe7) != 0) || (local_f0[0] == '(')) goto LAB_140026d43;
    *(undefined4 *)(param_1 + 0x34) = 1;
    DbgPrint("fw_run_in_rom_otp_mode");
    lVar1 = param_1 + 0x2348;
    iVar9 = FUN_14002e8cc(lVar1,0x14005c210,L"Status",local_b8,(undefined8 *)&local_f4);
    if (iVar9 == -0x3fffffcc) {
      FUN_14003235c(lVar1,0x14005c210,L"Status",4,4,(longlong)&local_f4);
    }
    iVar10 = FUN_140029ab4(param_1);
    if ((local_f4 != 2) && (iVar9 = iVar16, iVar10 == 0)) goto LAB_140026d43;
    FUN_14002e820(param_1);
    iVar9 = iVar16;
    if (((*(uint *)(param_1 + 0x2380) & 0x20000000) == 0) || (*(longlong *)(param_1 + 0xaf0) == 0))
    goto LAB_140026d43;
    uVar11 = FUN_14002f3a8(param_1);
    if ((int)uVar11 != 0) {
      memset(&local_78,0,0x40);
      uVar11 = FUN_14002f8f4(param_1,2,0xf000,0x40,(longlong)&local_78);
      if ((int)uVar11 != 0) {
        if (((local_68 == '\x03') && (cStack_66 == '\x03')) ||
           ((cStack_65 == '\x03' && (cStack_63 == '\x03')))) {
          lVar13 = *(longlong *)(param_1 + 0xaf0);
          uVar2 = *(undefined1 *)(lVar13 + 0xf000);
          *(undefined8 *)(lVar13 + 0xf000) = local_78;
          *(undefined8 *)(lVar13 + 0xf008) = uStack_70;
          *(ulonglong *)(lVar13 + 0xf010) =
               CONCAT26(uStack_62,
                        CONCAT15(cStack_63,
                                 CONCAT14(uStack_64,
                                          CONCAT13(cStack_65,
                                                   CONCAT12(cStack_66,CONCAT11(uStack_67,local_68)))
                                         )));
          *(undefined8 *)(lVar13 + 0xf018) = uStack_60;
          *(undefined8 *)(lVar13 + 0xf020) = local_58;
          *(undefined8 *)(lVar13 + 0xf028) = uStack_50;
          *(undefined8 *)(lVar13 + 0xf030) = local_48;
          *(undefined8 *)(lVar13 + 0xf038) = uStack_40;
          *(undefined1 *)(*(longlong *)(param_1 + 0xaf0) + 0xf000) = uVar2;
        }
        bVar4 = FUN_14002f7d8(param_1);
        if ((int)CONCAT71(extraout_var_00,bVar4) != 0) {
          uVar11 = FUN_14002fae0(param_1,2,0,0x10000,*(undefined8 **)(param_1 + 0xaf0));
          if ((int)uVar11 != 0) {
            lVar13 = ExAllocatePoolWithTag(DAT_140075ba0,0x10000);
            *(longlong *)(param_1 + 0xaf8) = lVar13;
            if (lVar13 != 0) {
              uVar11 = FUN_14002f8f4(param_1,2,0,0x10000,lVar13);
              if ((int)uVar11 != 0) {
                iVar9 = memcmp(*(void **)(param_1 + 0xaf8),*(void **)(param_1 + 0xaf0),0x10000);
                if (iVar9 == 0) {
                  uVar11 = FUN_14002f5c8(param_1);
                  if ((int)uVar11 != 0) {
                    FUN_140027c28(lVar1,0x14005c210,L"Status");
                    FUN_140027c28(lVar1,0x14005c210,L"CheckSysTime");
                    FUN_140027c28(lVar1,0x14005c210,L"CheckTickTime");
                    goto LAB_140026d21;
                  }
                }
                else {
                  local_88[0] = 0;
                  FUN_14002fae0(param_1,1,0xf000,1,local_88);
                  FUN_14002f5c8(param_1);
                }
              }
            }
          }
        }
      }
    }
    iVar9 = -0x3ffffb67;
    goto LAB_140026d43;
  }
  bVar4 = true;
  uVar11 = FUN_140028804(param_1,&local_e8);
  bVar3 = FUN_1400293b4(param_1,local_a0);
  uVar14 = (ushort)local_a0._0_8_;
  uVar18 = (ushort)local_a0._8_4_;
  uVar5 = SUB82(local_a0._0_8_,2);
  uVar6 = SUB82(local_a0._0_8_,4);
  uVar7 = SUB82(local_a0._0_8_,6);
  uVar8 = SUB42(local_a0._8_4_,2);
  if ((*(int *)(param_1 + 0x26b4) == 0xc6) &&
     (((((uVar14 < local_e8 || (uVar5 < local_e6)) || (uVar6 < local_e4)) ||
       ((uVar7 < local_e2 || (uVar18 < local_e0)))) || (uVar8 < local_de)))) {
    bVar4 = false;
  }
  if (((int)uVar11 == 0) || ((int)CONCAT71(extraout_var,bVar3) == 0)) goto LAB_140026d43;
  if ((local_e8 == uVar14) &&
     ((((local_e6 == uVar5 && (local_e4 == uVar6)) && (local_e2 == uVar7)) &&
      ((local_e0 == uVar18 && (local_de == uVar8)))))) {
    uVar11 = FUN_1400284d8(param_1,(undefined8 *)&local_d8);
    uVar12 = FUN_140029348(param_1,&local_b0);
    DbgPrint("fwVerDspDEV %d,%d,%d,%d,%d \n",local_d8,local_d6,local_d4);
    DbgPrint("fwVerDspUPD %d,%d,%d,%d,%d \n",local_b0,sStack_ae,sStack_ac);
    iVar9 = iVar16;
    if (((int)uVar11 != 0) && ((int)uVar12 != 0)) {
      if (((local_d8 == local_b0) &&
          (((local_d6 == sStack_ae && (local_d4 == sStack_ac)) && (local_d2 == sStack_aa)))) &&
         ((local_d0 == (short)local_a8 && (local_ce == (short)((uint)local_a8 >> 0x10))))) {
        if (*(longlong *)(param_1 + 0xb00) != 0) {
          ExFreePoolWithTag(*(longlong *)(param_1 + 0xb00),0);
          *(undefined8 *)(param_1 + 0xb00) = 0;
        }
      }
      else {
        iVar9 = FUN_14002783c(FUN_140026440,param_1,(undefined8 *)(param_1 + 0x2758));
        if ((iVar9 < 0) &&
           (*(undefined8 *)(param_1 + 0x2758) = 0, *(longlong *)(param_1 + 0xb00) != 0)) {
          ExFreePoolWithTag(*(undefined8 *)(param_1 + 0xb00),0);
          *(undefined8 *)(param_1 + 0xb00) = 0;
        }
      }
    }
    goto LAB_140026d43;
  }
  iVar9 = iVar16;
  if (((*(uint *)(param_1 + 0x2380) & 0x20000000) == 0) || (!bVar4)) goto LAB_140026d43;
  if (*(int *)(param_1 + 0x2738) == 0) {
    lVar1 = param_1 + 0x2348;
    FUN_14002e8cc(lVar1,0x14005c210,L"Status",local_b8,(undefined8 *)&local_f4);
    iVar9 = FUN_140029ab4(param_1);
    if ((local_f4 != 1) || (iVar9 == 0)) {
      local_f4 = 1;
      FUN_14003235c(lVar1,0x14005c210,L"Status",4,4,(longlong)&local_f4);
      iVar9 = iVar16;
      goto LAB_140026d43;
    }
    FUN_14002f3a8(param_1);
    local_90 = 0;
    FUN_14002fae0(param_1,1,0xf000,1,&local_90);
    FUN_14002f5c8(param_1);
    local_f4 = 2;
    FUN_14003235c(lVar1,0x14005c210,L"Status",4,4,(longlong)&local_f4);
  }
  else {
    FUN_1400286cc(param_1,&local_c8);
    if ((((local_c8 != uVar14) || (local_c6 != uVar5)) || (local_c4 != uVar6)) ||
       (((local_c2 != uVar7 || (local_c0 != uVar18)) || (local_be != uVar8)))) {
      iVar9 = FUN_14002783c(FUN_140026550,param_1,(undefined8 *)(param_1 + 0x2760));
      if (iVar9 < 0) {
        *(undefined8 *)(param_1 + 0x2760) = 0;
      }
      goto LAB_140026d43;
    }
    if (*(int *)(param_1 + 0x2744) == 0) {
      if (*(int *)(param_1 + 0x2740) == 0) goto LAB_140026d21;
      local_f7 = 0;
      FUN_14002ebb0(param_1,0,&local_f7);
      local_f7 = local_f7 | 1;
      FUN_14002ebec(param_1,0,local_f7,0);
      FUN_14004cbac(0x14);
      bVar17 = local_f7 & 0xfe;
      uVar15 = 0;
      local_f7 = bVar17;
    }
    else {
      local_f6[0] = 0;
      local_f8 = 0;
      FUN_14002ebb0(param_1,0xf970,local_f6);
      uVar15 = 0xf971;
      FUN_14002ebb0(param_1,0xf971,&local_f8);
      local_f8 = local_f8 | 1;
      local_f6[0] = local_f6[0] | 1;
      FUN_14002ebec(param_1,0xf970,local_f6[0],0);
      FUN_14002ebec(param_1,0xf971,local_f8,0);
      FUN_14004cbac(0x14);
      FUN_14002ebec(param_1,0xf970,local_f6[0],0);
      bVar17 = local_f8;
    }
    FUN_14002ebec(param_1,uVar15,bVar17,0);
  }
LAB_140026d21:
  FUN_14002ec78(param_1,6,9);
  FUN_14004cbac(200);
  iVar9 = -0x3ffffb67;
LAB_140026d43:
  if (*(int *)(param_1 + 0x2738) == 0) {
    if (*(longlong *)(param_1 + 0xaf8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0xaf8),0);
      *(undefined8 *)(param_1 + 0xaf8) = 0;
    }
    if (*(longlong *)(param_1 + 0xaf0) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0xaf0),0);
      *(undefined8 *)(param_1 + 0xaf0) = 0;
    }
  }
  return iVar9;
}

