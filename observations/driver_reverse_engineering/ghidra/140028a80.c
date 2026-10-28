
int FUN_140028a80(longlong param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  byte local_res8 [8];
  undefined4 local_c8 [9];
  undefined4 local_a4;
  longlong local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_46;
  
  if (*(longlong *)(param_1 + 0x2700) == 0) {
    lVar5 = ExAllocatePoolWithTag(DAT_140075ba0,0x12,0x43555342);
    if (lVar5 == 0) {
      iVar3 = -0x3fffff66;
    }
    else {
      local_c8[0] = 0xb0088;
      local_a4 = 0x12;
      local_98 = 0;
      local_46 = 0x100;
      local_90 = 0;
      local_a0 = lVar5;
      iVar3 = FUN_14002fdd0(param_1,local_c8,0xfffffffffd050f80);
      if ((-1 < iVar3) && (iVar3 != 0x102)) {
        sVar1 = *(short *)(lVar5 + 8);
        *(short *)(param_1 + 0x26aa) = sVar1;
        sVar2 = *(short *)(lVar5 + 10);
        *(short *)(param_1 + 0x26a8) = sVar2;
        *(undefined2 *)(param_1 + 0x26ae) = *(undefined2 *)(lVar5 + 0xc);
        *(undefined2 *)(param_1 + 0x26d0) = *(undefined2 *)(lVar5 + 0xc);
        FUN_14004eb18(sVar1,sVar2,(int *)(param_1 + 0x26b0),(undefined4 *)(param_1 + 0x26b4),
                      (undefined4 *)(param_1 + 0x30));
        if (*(int *)(param_1 + 0x26b0) == 0xc0) {
          local_res8[0] = 0;
          iVar4 = FUN_14002ebb0(param_1,0xfe22,local_res8);
          if ((-1 < iVar4) && ((local_res8[0] & 0xf0) == 0xe0)) {
            *(undefined4 *)(param_1 + 0x26b4) = 0xc1;
          }
        }
        *(longlong *)(param_1 + 0x2700) = lVar5;
      }
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

