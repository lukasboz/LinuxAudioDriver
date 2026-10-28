
void FUN_140055f90(undefined8 param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  
  if (param_3 < 0x21) {
    if (param_3 != 0x20) {
      if (param_3 < 6) {
        if (param_3 == 5) {
LAB_140056039:
          *param_2 = param_3 - 4 & 0xf | *param_2 & 0xff1ffff0 | 0x100000;
          return;
        }
        if (param_3 == 0) {
          uVar1 = *param_2 & 0xff8ffff0 | 0x800000;
          goto LAB_1400560e9;
        }
        if (param_3 != 1) {
          if (param_3 == 2) {
            uVar1 = *param_2 & 0xff2ffff0 | 0x200000;
          }
          else {
            if ((param_3 != 3) && (param_3 != 4)) {
              return;
            }
            uVar1 = *param_2 & 0xff1ffff0 | 0x100000;
          }
          goto LAB_1400560e9;
        }
      }
      else {
        if ((param_3 == 6) || (param_3 == 7)) goto LAB_140056039;
        if (param_3 == 8) {
          uVar1 = *param_2 & 0xff4ffff0 | 0x400000;
          goto LAB_1400560e9;
        }
        if (param_3 != 0xf) {
          return;
        }
      }
      uVar1 = *param_2 & 0xffaffff0 | 0xa00000;
      goto LAB_1400560e9;
    }
  }
  else if (param_3 != 0x22) {
    if (param_3 != 0x23) {
      if (param_3 == 0x24) {
        uVar1 = *param_2 & 0xffdffff1 | 0xd00001;
        goto LAB_1400560e9;
      }
      if (param_3 == 0x32) goto LAB_1400560dd;
      if (param_3 != 0x33) {
        if (param_3 == 0x103) {
          uVar1 = *param_2 & 0xff2ffffd | 0x20000d;
        }
        else if (param_3 == 0x104) {
          uVar1 = *param_2 & 0xff0ffffd | 0xd;
        }
        else if (param_3 == 0x105) {
          uVar1 = *param_2 & 0xff2ffffe | 0x20000e;
        }
        else {
          if (param_3 != 0x106) {
            return;
          }
          uVar1 = *param_2 & 0xff0ffff2 | 2;
        }
        goto LAB_1400560e9;
      }
    }
    uVar1 = *param_2 & 0xff2ffffb | 0x20000b;
    goto LAB_1400560e9;
  }
LAB_1400560dd:
  uVar1 = *param_2 & 0xff2ffffa | 0x20000a;
LAB_1400560e9:
  *param_2 = uVar1;
  return;
}

