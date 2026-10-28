
int FUN_140025400(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  *(undefined4 *)(param_1 + 0x38) = 0;
  iVar2 = 0;
  if ((*(longlong *)(param_1 + 0x2708) != 0) &&
     (uVar3 = (ulonglong)*(byte *)(*(longlong *)(param_1 + 0x2708) + 4), iVar2 = 0, uVar3 != 0)) {
    lVar4 = 0;
    do {
      lVar1 = USBD_ParseConfigurationDescriptorEx
                        (*(undefined8 *)(param_1 + 0x2708),*(undefined8 *)(param_1 + 0x2708),
                         *(undefined1 *)
                          (*(longlong *)(*(longlong *)(param_1 + 0x2718) + lVar4 * 8) + 2),0,1,2,
                         0xffffffff);
      iVar2 = *(int *)(param_1 + 0x38);
      if (lVar1 != 0) {
        iVar2 = iVar2 + 1;
        *(int *)(param_1 + 0x38) = iVar2;
      }
      lVar4 = lVar4 + 1;
    } while (lVar4 < (longlong)uVar3);
  }
  return iVar2;
}

