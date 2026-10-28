
void FUN_1400325f4(longlong param_1,int param_2)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar2 = FUN_14002821c(param_1,0x38);
  lVar3 = FUN_14002821c(param_1,0x18);
  if (lVar2 == 0) {
    return;
  }
  if (lVar3 == 0) {
    return;
  }
  if (param_2 == 2) {
    *(ushort *)(lVar2 + 0x4e) = *(ushort *)(lVar2 + 0x4e) & 0xffdf | 1;
    if ((*(int *)(lVar2 + 0x20) == 0xf) || (uVar4 = 0, *(int *)(lVar2 + 0x20) == 1)) {
      uVar4 = 1;
    }
  }
  else {
    if (param_2 != 4) {
      if ((param_2 - 6U & 0xfffffffd) != 0) {
        return;
      }
      uVar4 = 5;
      *(ushort *)(lVar2 + 0x4e) = *(ushort *)(lVar2 + 0x4e) & 0xfffe | 0x20;
      if (*(int *)(lVar2 + 0x20) == 1) {
        uVar4 = 1;
      }
      uVar4 = FUN_14005470c(lVar2,uVar4);
      uVar1 = *(ushort *)(lVar3 + 0x4e) & 0xfffe | 0x40;
      uVar4 = uVar4 + 6;
      if (*(int *)(lVar3 + 0x20) == 1) {
        uVar4 = 1;
      }
      goto LAB_14003270f;
    }
    *(ushort *)(lVar2 + 0x4e) = *(ushort *)(lVar2 + 0x4e) & 0xfffe | 0x20;
    uVar4 = 5;
    if (*(int *)(lVar2 + 0x20) == 1) {
      uVar4 = 1;
    }
  }
  uVar4 = FUN_14005470c(lVar2,uVar4);
  uVar1 = *(ushort *)(lVar3 + 0x4e) & 0xffbf | 1;
  uVar4 = CONCAT31((int3)(uVar4 >> 8),*(int *)(lVar3 + 0x20) == 1);
LAB_14003270f:
  *(ushort *)(lVar3 + 0x4e) = uVar1;
  FUN_14005470c(lVar3,uVar4);
  return;
}

