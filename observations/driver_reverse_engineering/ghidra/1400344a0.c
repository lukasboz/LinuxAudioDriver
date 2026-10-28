
longlong * FUN_1400344a0(longlong param_1,longlong param_2,longlong param_3,uint param_4)

{
  short sVar1;
  char cVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  
  sVar1 = *(short *)(*(longlong *)(param_1 + 8) + 0x26a8);
  if ((((sVar1 == 0x4001) || (sVar1 == 0x4008)) || (sVar1 == 0x4014)) ||
     ((sVar1 == 0x4016 || (sVar1 == 0x402e)))) {
    if ((*(undefined **)(param_3 + 8) == &DAT_14005fd20) && (*(int *)(param_2 + 0x32c) != 0)) {
      *(undefined4 *)(param_3 + 0x20 + (ulonglong)param_4 * 4) = 0xa0000;
    }
    else if ((*(undefined **)(param_3 + 8) == &DAT_14005fd30) && (*(int *)(param_2 + 0x32c) != 0)) {
      uVar3 = 0x14;
      if (*(int *)(*(longlong *)(param_1 + 8) + 0xad8) == 1) {
        uVar3 = 1;
      }
      *(undefined4 *)(param_3 + 0x84) = uVar3;
    }
  }
  plVar5 = *(longlong **)(param_1 + 8);
  sVar1 = (short)plVar5[0x4d5];
  if (((((sVar1 == 0x4001) || (sVar1 == 0x4008)) || (sVar1 == 0x400e)) ||
      (((sVar1 == 0x4014 || (sVar1 == 0x402d)) || (sVar1 == 0x402e)))) &&
     (((*(undefined **)(param_3 + 8) == &DAT_14005fd20 && (*(int *)(param_2 + 0x32c) == 0)) &&
      (*(int *)(param_2 + 0x2e8) != 0)))) {
    plVar5 = *(longlong **)(param_2 + 0x2f0);
    if (*plVar5 != 0) {
      uVar4 = CONCAT71((int7)((ulonglong)plVar5 >> 8),*(undefined1 *)(*plVar5 + 0x4e)) &
              0xffffffffffffff04;
      cVar2 = (char)uVar4;
      plVar5 = (longlong *)CONCAT71((int7)(uVar4 >> 8),-cVar2);
      *(uint *)(param_3 + 0x20 + (ulonglong)param_4 * 4) =
           (-(uint)(cVar2 != '\0') & 0xfff20000) - 0x60000;
    }
  }
  return plVar5;
}

