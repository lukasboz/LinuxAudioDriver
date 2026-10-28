
undefined4
FUN_140031ce8(longlong param_1,undefined2 param_2,undefined8 param_3,byte param_4,byte param_5)

{
  byte bVar1;
  undefined4 uVar2;
  byte local_res20 [8];
  undefined1 uStack0000000000000029;
  byte bStack000000000000002a;
  
  bVar1 = param_5;
  local_res20[0] = 0;
  if (param_5 != 0) {
    FUN_14002ddb0(param_1,param_2,param_3,local_res20);
    param_4 = param_4 | local_res20[0] & bVar1;
  }
  uStack0000000000000029 = (undefined1)param_3;
  param_5 = (byte)((ulonglong)param_3 >> 8);
  bStack000000000000002a = param_4;
  KeWaitForSingleObject(param_1 + 0xb30,0,0,0,0);
  uVar2 = FUN_14003190c(param_1,0x17,0x40,0x3e,param_2,0x100,&param_5,3,'\0');
  KeReleaseMutex(param_1 + 0xb30,0);
  return uVar2;
}

