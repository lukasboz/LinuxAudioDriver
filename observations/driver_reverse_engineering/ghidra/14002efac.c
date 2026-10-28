
void FUN_14002efac(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  bool bVar3;
  wchar_t *pwVar4;
  uint uVar5;
  longlong lVar6;
  byte *pbVar7;
  undefined4 uVar8;
  
  if ((*(uint *)(param_1 + 0x2384) & 0x1000) != 0) {
    if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
       ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
      FUN_14001b4c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x1b,&DAT_1400602c8,
                    "CCommon::RestoreSettingsFromRegistryForDsd");
    }
    uVar5 = 0;
    if (*(int *)(param_1 + 0xff0) != 0) {
      lVar6 = 0;
      do {
        lVar2 = *(longlong *)(lVar6 + *(longlong *)(param_1 + 0xff8));
        if ((lVar2 != 0) && ((*(int *)(lVar2 + 0x2d8) == 0 || (*(int *)(lVar2 + 0x2d8) == 1)))) {
          pbVar1 = (byte *)(lVar2 + 0x248);
          pbVar7 = pbVar1;
          bVar3 = FUN_14003b590(lVar2,0,L"dsd_mode",4,(undefined8 *)pbVar1);
          uVar8 = (undefined4)((ulonglong)pbVar7 >> 0x20);
          if (bVar3) {
            if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
               ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
              pwVar4 = FUN_14003a624(lVar2,*(int *)(lVar2 + 0x2d8));
              FUN_140032c84(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x1c,&DAT_1400602c8,
                            "CCommon::RestoreSettingsFromRegistryForDsd",CONCAT44(uVar8,0x1284),
                            pwVar4);
            }
            if (*(int *)pbVar1 != 0) {
              FUN_140052c3c(param_1,lVar2,*pbVar1);
              *(undefined4 *)(param_1 + 0xcac) = *(undefined4 *)pbVar1;
            }
          }
          else if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
                  ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
            pwVar4 = FUN_14003a624(lVar2,*(int *)(lVar2 + 0x2d8));
            FUN_140032ba0(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x1d,&DAT_1400602c8,
                          "CCommon::RestoreSettingsFromRegistryForDsd",CONCAT44(uVar8,0x128d),pwVar4
                         );
          }
        }
        uVar5 = uVar5 + 1;
        lVar6 = lVar6 + 8;
      } while (uVar5 < *(uint *)(param_1 + 0xff0));
    }
  }
  return;
}

