
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140031138(longlong param_1,int param_2,byte param_3)

{
  undefined1 auStack_48 [32];
  uint local_28 [4];
  ulonglong local_18;
  
  local_18 = DAT_1400698c0 ^ (ulonglong)auStack_48;
  local_28[0] = param_2 << 0x14 | (uint)param_3 | 0x70800;
  FUN_14002ff18(param_1,1,(longlong)local_28);
  return;
}

