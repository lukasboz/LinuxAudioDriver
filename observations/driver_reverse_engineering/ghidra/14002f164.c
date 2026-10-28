
void FUN_14002f164(longlong param_1)

{
  ulonglong uVar1;
  int local_res8 [2];
  uint local_res10 [2];
  
  if ((*(uint *)(param_1 + 0x2378) & 0x400) != 0) {
    if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
       ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
      FUN_14001b4c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x18,&DAT_1400602c8,
                    "CCommon::RestoreSettingsFromRegistryForHarmonicTuning");
    }
    local_res8[0] = 0;
    local_res10[0] = 4;
    uVar1 = FUN_14002db9c((longlong *)(param_1 + 0x2348),0x14005b7c0,L"Harmonic_mode",local_res10,
                          (undefined8 *)local_res8,0,1);
    if ((int)uVar1 < 0) {
      if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
         ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
        FUN_14001b4c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x19,&DAT_1400602c8,
                      "CCommon::RestoreSettingsFromRegistryForHarmonicTuning");
      }
    }
    else {
      FUN_14003051c(param_1,local_res8[0]);
    }
  }
  return;
}

