
void FUN_14003281c(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  char local_res10 [8];
  
  if (param_2 != 0) {
    local_res10[0] = '\0';
    FUN_14002ebb0(param_2,0x2308,local_res10);
    if ((byte)(local_res10[0] - 1U) < 3) {
      uVar3 = 0;
      if (local_res10[0] == '\x01') {
        uVar3 = 0xf;
        uVar2 = 2;
      }
      else if (local_res10[0] == '\x02') {
        uVar3 = 1;
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
        if (local_res10[0] == '\x03') {
          uVar3 = 1;
          uVar2 = 0;
        }
      }
      *(undefined4 *)(param_2 + 0x3c) = uVar2;
      lVar1 = FUN_14002821c(param_1,0x18);
      if (lVar1 != 0) {
        FUN_14005470c(lVar1,uVar3);
      }
      if (*(longlong *)(param_2 + 0xb28) != 0) {
        FUN_140020e64(*(longlong *)(param_2 + 0xb28),0x1d);
      }
    }
    else if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
            ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
      FUN_1400209c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0xb,&DAT_1400602c8,
                    "CCommon::updateMicSelection");
    }
  }
  return;
}

