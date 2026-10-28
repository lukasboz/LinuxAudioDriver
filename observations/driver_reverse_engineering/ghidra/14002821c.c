
longlong FUN_14002821c(longlong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  if (*(uint *)(param_1 + 0xfd8) != 0) {
    do {
      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0xfe0) + uVar3 * 8);
      if (*(int *)(lVar1 + 0x10) == param_2) {
        return lVar1;
      }
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(param_1 + 0xfd8));
  }
  return 0;
}

