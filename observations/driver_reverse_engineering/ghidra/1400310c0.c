
undefined8 FUN_1400310c0(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  undefined1 uVar3;
  
  if ((*(uint *)(param_1 + 0x2384) & 0x40000) != 0) {
    lVar1 = FUN_14002821c(param_1,0x21);
    if ((*(uint *)(param_1 + 0x2394) & 0x100) == 0) {
      if (lVar1 == 0) goto LAB_140031110;
      if ((*(byte *)(lVar1 + 0x4c) & 2) == 0) {
        cVar2 = '\a';
      }
      else {
        cVar2 = (*(int *)(lVar1 + 0x20) == 7) + '\x06';
      }
    }
    else {
      cVar2 = '\b';
    }
    FUN_140052368(param_1,cVar2);
  }
LAB_140031110:
  if ((*(uint *)(param_1 + 0x2384) & 0x80000) != 0) {
    uVar3 = 9;
    if (*(int *)(param_1 + 0x44) != 0x38) {
      uVar3 = 10;
    }
    FUN_140052368(param_1,uVar3);
  }
  return 0;
}

