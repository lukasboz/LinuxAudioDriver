
void FUN_14003a6d8(short *param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x108) != 0) {
    do {
      uVar2 = 0;
      lVar3 = (ulonglong)uVar1 * 0x98 + *(longlong *)(param_1 + 0x10c);
      if (*(char *)(*(longlong *)(lVar3 + 0x18) + 0x26) != '\0') {
        do {
          uStack_20 = 0;
          local_28 = 0x1000200000000;
          local_18 = (ulonglong)uVar2;
          local_38 = 0;
          uStack_30 = 0;
          FUN_14004db18((longlong)param_1,uVar1,(longlong)&local_38,(uint *)0x0);
          if ((*(uint *)(*(longlong *)(param_1 + 0x168) + 0x2374) & 0x200) != 0) {
            FUN_14004d7e8(param_1,uVar1,(longlong)&local_38,(int *)0x0);
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(byte *)(*(longlong *)(lVar3 + 0x18) + 0x26));
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x108));
  }
  return;
}

