
void FUN_14002ed34(longlong param_1)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  int iVar4;
  uint local_res8 [2];
  int local_res10 [2];
  undefined4 local_res18 [4];
  
  local_res10[0] = 0;
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
    FUN_14001b4c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x17,&DAT_1400602c8,
                  "CCommon::RestoreSettingsFromRegistry");
  }
  local_res18[0] = 0xffff;
  local_res8[0] = 4;
  plVar1 = (longlong *)(param_1 + 0x2348);
  uVar3 = FUN_14002db9c(plVar1,0x14005b7c0,L"JackConfig",local_res8,(undefined8 *)local_res18,0,1);
  if (-1 < (int)uVar3) {
    *(undefined4 *)(param_1 + 0x2394) = local_res18[0];
  }
  local_res8[0] = 4;
  FUN_14002db9c(plVar1,0x14005b7c0,L"redirected_playback_widget_id",local_res8,
                (undefined8 *)(param_1 + 0x40),0,1);
  FUN_14002db9c(plVar1,0x14005b7c0,L"redirected_recording_widget_id",local_res8,
                (undefined8 *)(param_1 + 0x44),0,1);
  local_res8[0] = 4;
  uVar3 = FUN_14002db9c(plVar1,0x14005b7c0,L"JackConfig.DisFPJD",local_res8,
                        (undefined8 *)local_res10,0,1);
  if (-1 < (int)uVar3) {
    if (local_res10[0] == 0) {
      uVar2 = *(uint *)(param_1 + 0x2394) & 0xffffff7f;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x2394) | 0x80;
    }
    *(uint *)(param_1 + 0x2394) = uVar2;
  }
  local_res8[0] = 4;
  uVar3 = FUN_14002db9c(plVar1,0x14005b7c0,L"DisableSmartAmpFunction",local_res8,
                        (undefined8 *)local_res10,0,1);
  iVar4 = -0x80000000;
  if (-1 < (int)uVar3) {
    iVar4 = local_res10[0];
  }
  *(int *)(param_1 + 0xce8) = iVar4;
  return;
}

