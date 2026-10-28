
void FUN_14002eedc(longlong param_1)

{
  ulonglong uVar1;
  uint local_res8 [2];
  uint local_res10 [6];
  
  local_res8[0] = 0;
  local_res10[0] = 4;
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
    FUN_14001b4c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x1a,&DAT_1400602c8,
                  "CCommon::RestoreSettingsFromRegistryForAmpLevel");
  }
  uVar1 = FUN_14002db9c((longlong *)(param_1 + 0x2348),0x14005b7c0,L"AMP_Level",local_res10,
                        (undefined8 *)local_res8,0,1);
  if ((int)uVar1 < 0) {
    *(undefined4 *)(param_1 + 0xcc4) = 0;
  }
  else {
    *(uint *)(param_1 + 0xcba) = local_res8[0];
    *(undefined4 *)(param_1 + 0xcc4) = 1;
    if ((*(uint *)(param_1 + 0x2388) & 2) == 0) {
      FUN_140030218(param_1,local_res8[0]);
      return;
    }
  }
  return;
}

