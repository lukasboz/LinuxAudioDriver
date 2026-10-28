
undefined4 FUN_140030218(longlong param_1,uint param_2)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  short *psVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
    FUN_14001b4c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x15,&DAT_1400602c8,
                  "CCommon::SetAmplifyLevel");
  }
  iVar2 = *(int *)(param_1 + 0x26b0);
  if (iVar2 == 0x42) {
    psVar1 = (short *)FUN_140028130(param_1,4);
    if (psVar1 != (short *)0x0) {
      FUN_1400524f8(param_1,psVar1,param_2 & 0xffff);
      uVar3 = extraout_EAX_01;
    }
    psVar1 = (short *)FUN_140028130(param_1,5);
    if (psVar1 == (short *)0x0) {
      return uVar3;
    }
    param_2 = param_2 >> 0x10;
  }
  else {
    if (iVar2 == 0x9f) {
      iVar2 = 1;
    }
    else {
      if (iVar2 != 0xa3) {
        if ((((iVar2 != 0xb1) && (iVar2 != 0xb2)) && (iVar2 != 0xb4)) && (iVar2 != 0xb5)) {
          return 0;
        }
        if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
           ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
          FUN_1400332e8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x16,&DAT_1400602c8,
                        "CCommon::SetAmplifyLevel");
        }
        psVar1 = (short *)FUN_140028130(param_1,(uint)*(byte *)(param_1 + 0xcb2));
        if (psVar1 != (short *)0x0) {
          FUN_1400524f8(param_1,psVar1,param_2 & 0xffff);
          uVar3 = extraout_EAX;
        }
        psVar1 = (short *)FUN_140028130(param_1,(uint)*(byte *)(param_1 + 0xcb0));
        if (psVar1 == (short *)0x0) {
          return uVar3;
        }
        FUN_1400524f8(param_1,psVar1,param_2 >> 0x10);
        if (*(int *)(param_1 + 0x26b4) != 0x85) {
          return extraout_EAX_00;
        }
        FUN_14003051c(param_1,*(int *)(param_1 + 0xcc0));
        return extraout_EAX_00;
      }
      iVar2 = 4;
    }
    psVar1 = (short *)FUN_140028130(param_1,iVar2);
    if (psVar1 == (short *)0x0) {
      return 0;
    }
  }
  FUN_1400524f8(param_1,psVar1,param_2 & 0xffff);
  return extraout_EAX_02;
}

