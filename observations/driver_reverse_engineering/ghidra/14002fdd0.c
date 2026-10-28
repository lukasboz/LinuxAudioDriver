
int FUN_14002fdd0(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  byte in_CR8;
  int local_res8 [2];
  undefined8 local_res10;
  int local_58 [4];
  undefined1 local_48 [32];
  
  KeInitializeEvent(local_48,0,0);
  lVar5 = IoBuildDeviceIoControlRequest
                    (0x220003,*(undefined8 *)(param_1 + 0x26e8),0,0,0,0,1,local_48,local_58);
  *(undefined8 *)(*(longlong *)(lVar5 + 0xb8) + -0x40) = param_2;
  local_res8[0] = 0;
  lVar1 = *(longlong *)(lVar5 + 0xb8);
  *(code **)(lVar1 + -0x10) = FUN_140029e40;
  *(int **)(lVar1 + -8) = local_res8;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  iVar3 = IofCallDriver(*(undefined8 *)(param_1 + 0x26e8),lVar5);
  if (((iVar3 == 0x103) && (in_CR8 < 2)) &&
     (local_res10 = param_3, iVar4 = KeWaitForSingleObject(local_48,0,0,0,&local_res10),
     iVar2 = local_res8[0], iVar3 = local_58[0], iVar4 == 0x102)) {
    LOCK();
    local_res8[0] = 1;
    UNLOCK();
    if (iVar2 == 0) {
      IoCancelIrp(lVar5);
      iVar3 = local_res8[0];
      LOCK();
      local_res8[0] = 2;
      UNLOCK();
      if (iVar3 == 3) {
        IofCompleteRequest(lVar5,0);
      }
    }
    KeWaitForSingleObject(local_48,0,0,0,0);
    iVar3 = -0x3fffff4b;
  }
  return iVar3;
}

