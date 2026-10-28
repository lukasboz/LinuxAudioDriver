
void FUN_14003c8b8(longlong param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x328) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x2e8) == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x25c) = 0;
  if (param_2 == 4) {
    uVar2 = 0x2000200;
  }
  else {
    if (param_2 != 6) {
      if (param_2 == 7) {
        uVar2 = 0xc000000;
        goto LAB_14003c909;
      }
      if (param_2 != 8) goto LAB_14003c910;
    }
    uVar2 = 0x8000001;
  }
LAB_14003c909:
  *(uint *)(param_1 + 0x25c) = uVar2;
LAB_14003c910:
  bVar1 = *(byte *)(**(longlong **)(param_1 + 0x2f0) + 0x33) & 0xf;
  if ((bVar1 != 1) && (bVar1 == 2)) {
    uVar2 = uVar2 | 2;
  }
  uVar2 = (*(uint *)(param_1 + 0x32c) & 1) << 6 | uVar2;
  *(uint *)(param_1 + 0x25c) = uVar2;
  *(uint *)(param_1 + 0x25c) =
       *(uint *)(**(longlong **)(param_1 + 0x2f0) + 0x30) >> 10 & 0x3c | uVar2;
  return;
}

