
void FUN_140032924(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  
  if ((*(uint *)(param_1 + 0x2384) & 0x40000) == 0) {
    return;
  }
  lVar3 = FUN_14002821c(param_1,0x37);
  lVar4 = FUN_14002821c(param_1,0x21);
  uVar6 = (undefined4)((ulonglong)lVar4 >> 0x20);
  if ((*(uint *)(param_1 + 0x2394) & 0x100) == 0) {
    iVar7 = 0;
    if (lVar3 != 0) {
      uVar5 = FUN_14005470c(lVar3,4);
      lVar4 = CONCAT44(uVar6,uVar5);
      lVar2 = *(longlong *)(lVar3 + 0x18);
      if (lVar2 != 0) {
        FUN_14003b590(lVar2,0,L"current_channel_number",4,(undefined8 *)(lVar2 + 0x254));
        iVar7 = *(int *)(*(longlong *)(lVar3 + 0x18) + 0x254);
      }
    }
    FUN_14004cbac(400);
    if (lVar4 != 0) {
      uVar5 = 2;
      if (iVar7 == 8) {
        uVar5 = 7;
      }
      uVar5 = FUN_14005470c(lVar4,uVar5);
      FUN_14003c72c(*(longlong *)(CONCAT44((int)((ulonglong)lVar4 >> 0x20),uVar5) + 0x18));
    }
    if (*(int *)(param_1 + 0x26b4) == 0x85) goto LAB_140032aa1;
    sVar1 = *(short *)(param_1 + 0x26a8);
  }
  else {
    if (lVar4 != 0) {
      uVar5 = FUN_14005470c(lVar4,2);
      FUN_14003a868(*(short **)(CONCAT44(uVar6,uVar5) + 0x18));
    }
    FUN_14004cbac(400);
    iVar7 = 0;
    if (lVar3 != 0) {
      FUN_14005470c(lVar3,4);
      lVar4 = *(longlong *)(lVar3 + 0x18);
      iVar7 = 0;
      if (lVar4 != 0) {
        FUN_14003b590(lVar4,0,L"current_channel_number",4,(undefined8 *)(lVar4 + 0x254));
        iVar7 = *(int *)(*(longlong *)(lVar3 + 0x18) + 0x254);
      }
    }
    if (*(int *)(param_1 + 0x26b4) == 0x85) goto LAB_140032aa1;
    sVar1 = *(short *)(param_1 + 0x26a8);
  }
  if (sVar1 != 0x1b9b) {
    return;
  }
LAB_140032aa1:
  FUN_1400325f4(param_1,iVar7);
  return;
}

