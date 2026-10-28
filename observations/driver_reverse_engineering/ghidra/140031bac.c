
bool FUN_140031bac(longlong *param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
                  undefined4 param_5,undefined8 param_6,longlong param_7)

{
  int iVar1;
  bool bVar2;
  undefined1 local_res8 [8];
  longlong local_88;
  longlong local_80;
  undefined1 local_78 [16];
  undefined1 local_68 [16];
  undefined4 local_58 [2];
  longlong local_50;
  undefined1 *local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_88 = 0;
  if ((*param_1 == 0) ||
     ((param_7 == 0 &&
      (iVar1 = IoOpenDeviceRegistryKey(*param_1,1,2,&local_80), param_7 = local_80, iVar1 < 0)))) {
LAB_140031cc9:
    bVar2 = false;
  }
  else {
    if (param_2 != 0) {
      RtlInitUnicodeString(local_78,param_2);
      local_48 = local_78;
      local_58[0] = 0x30;
      local_40 = 0x240;
      local_38 = 0;
      uStack_30 = 0;
      local_50 = param_7;
      iVar1 = ZwCreateKey(&local_88,0xf003f,local_58,0,0,0,local_res8);
      ZwClose(param_7);
      param_7 = local_88;
      if (iVar1 < 0) goto LAB_140031cc9;
    }
    RtlInitUnicodeString(local_68,param_3);
    iVar1 = ZwSetValueKey(param_7,local_68,0,param_4,param_6,param_5);
    bVar2 = -1 < iVar1;
    ZwClose(param_7);
  }
  return bVar2;
}

