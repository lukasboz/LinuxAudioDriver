
undefined8 FUN_14003ac18(longlong *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong local_res10;
  longlong local_res18 [2];
  undefined1 local_88 [8];
  undefined8 local_80;
  undefined8 local_78;
  undefined1 local_70 [16];
  undefined4 local_60 [2];
  undefined8 local_58;
  undefined1 *local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  local_80 = 0;
  local_78 = 0;
  if ((*param_1 == 0) ||
     (local_res10 = param_2, local_res18[0] = param_3, local_res18[1] = param_4,
     iVar1 = IoOpenDeviceRegistryKey(*param_1,1,2,&local_80), iVar1 < 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = local_80;
    if (local_res10 != 0) {
      plVar4 = &local_res10;
      lVar2 = local_res10;
      do {
        RtlInitUnicodeString(local_70,lVar2);
        local_50 = local_70;
        local_60[0] = 0x30;
        local_48 = 0x240;
        local_40 = 0;
        uStack_38 = 0;
        local_58 = uVar3;
        iVar1 = ZwCreateKey(&local_78,0xf003f,local_60,0,0,0,local_88);
        ZwClose(uVar3);
        if (iVar1 < 0) {
          return 0;
        }
        plVar4 = plVar4 + 1;
        lVar2 = *plVar4;
        uVar3 = local_78;
      } while (lVar2 != 0);
    }
  }
  return uVar3;
}

