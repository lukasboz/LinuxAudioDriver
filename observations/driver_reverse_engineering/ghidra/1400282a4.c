
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1400282a4(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_108 [32];
  undefined4 local_e8 [9];
  uint local_c4;
  undefined1 *local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_66;
  undefined1 local_48 [2];
  ushort local_46;
  ulonglong local_38;
  
  local_38 = DAT_1400698c0 ^ (ulonglong)auStack_108;
  if (*(longlong *)(param_1 + 0x2708) == 0) {
    local_c0 = local_48;
    local_e8[0] = 0xb0088;
    local_c4 = 9;
    local_b8 = 0;
    local_66 = 0x200;
    local_b0 = 0;
    iVar1 = FUN_14002fdd0(param_1,local_e8,0xfffffffffd050f80);
    if (-1 < iVar1) {
      uVar2 = ExAllocatePoolWithTag(DAT_140075ba0,local_46,0x50434444);
      local_e8[0] = 0xb0088;
      local_b8 = 0;
      local_66 = 0x200;
      local_b0 = 0;
      local_c4 = (uint)local_46;
      local_c0 = (undefined1 *)uVar2;
      iVar1 = FUN_14002fdd0(param_1,local_e8,0xfffffffffd050f80);
      if (-1 < iVar1) {
        *(undefined8 *)(param_1 + 0x2708) = uVar2;
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

