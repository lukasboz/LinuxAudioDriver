
undefined4 FUN_14003c72c(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  uVar2 = 0;
  LOCK();
  iVar1 = *(int *)(param_1 + 0x328);
  *(int *)(param_1 + 0x328) = 0;
  UNLOCK();
  if (iVar1 == 1) {
    KsAcquireDevice(*(undefined8 *)(*(longlong *)(param_1 + 0x2d0) + 0x26d8));
    uVar2 = 0;
    if (*(longlong *)(param_1 + 0x270) != 0) {
      KsFilterFactorySetDeviceClassesState(*(longlong *)(param_1 + 0x270),0);
      lVar3 = KsGetParent(*(undefined8 *)(param_1 + 0x270));
      uVar2 = KsFreeObjectCreateItemsByContext
                        (**(undefined8 **)(*(longlong *)(lVar3 + 0x18) + 0x40),
                         *(undefined8 *)(param_1 + 0x270));
      *(undefined8 *)(param_1 + 0x270) = 0;
    }
    KsReleaseDevice(*(undefined8 *)(*(longlong *)(param_1 + 0x2d0) + 0x26d8));
  }
  return uVar2;
}

