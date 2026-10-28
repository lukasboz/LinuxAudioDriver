
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140028248(longlong param_1,int param_2,uint param_3,undefined4 *param_4)

{
  undefined1 auStack_58 [32];
  uint local_38 [4];
  uint local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = DAT_1400698c0 ^ (ulonglong)auStack_58;
  local_28 = param_2 << 0x14 | 0xc0000;
  local_38[0] = param_2 << 0x14 | param_3 | 0x50000;
  FUN_14002ff18(param_1,2,(longlong)local_38);
  *param_4 = local_20;
  return;
}

