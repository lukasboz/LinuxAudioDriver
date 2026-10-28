
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1400303ec(longlong param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  undefined1 auStack_68 [32];
  uint local_48 [2];
  uint local_40 [4];
  uint local_30;
  ulonglong local_20;
  
  local_20 = DAT_1400698c0 ^ (ulonglong)auStack_68;
  if (param_5 != 0) {
    FUN_140028248(param_1,param_2,param_3,local_48);
    param_4 = param_4 | local_48[0] & param_5;
  }
  local_40[0] = param_2 << 0x14 | param_3 | 0x50000;
  local_30 = param_2 << 0x14 | param_4 | 0x40000;
  FUN_14002ff18(param_1,2,(longlong)local_40);
  return;
}

