
ulonglong FUN_1400283a4(longlong param_1,undefined1 param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  undefined4 local_res20;
  undefined2 local_res24;
  
  local_res20 = 0;
  local_res24 = 0;
  uVar1 = FUN_140031890(param_1,0xa1,1,2,0,param_2,0,&local_res20,6,'\x01');
  if ((int)uVar1 < 0) {
    if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
       ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
      FUN_140032b00(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x26,&DAT_1400602c8,
                    "CCommon::GetConnectorStatus");
    }
  }
  else if ((char)local_res20 != '\0') {
    *param_3 = 1;
    return uVar1;
  }
  *param_3 = 0;
  return uVar1 & 0xffffffff;
}

