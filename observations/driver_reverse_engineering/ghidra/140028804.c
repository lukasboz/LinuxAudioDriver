
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140028804(longlong param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  undefined1 auStack_98 [32];
  undefined1 local_78 [4];
  byte local_74;
  byte local_73;
  byte local_38;
  byte local_35;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2c;
  byte local_2b;
  byte local_2a;
  byte local_29;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  ulonglong local_18;
  
  local_18 = DAT_1400698c0 ^ (ulonglong)auStack_98;
  memset(local_78,0,0x54);
  FUN_140028978(param_1,0,(longlong)local_78,0x54);
  if ((local_38 & 0xf) == 0) {
    if (((local_30 & 0xf) != 0) && ((local_30 & 0xf) != 0xb)) goto LAB_14002886a;
  }
  local_30 = local_38;
LAB_14002886a:
  if (local_30 >> 4 == 2) {
    uVar5 = 0;
    uVar2 = (ushort)local_29;
    uVar6 = 0;
    uVar3 = (ushort)local_2a;
    uVar1 = (ushort)local_2b;
    uVar4 = (ushort)local_2c;
  }
  else if (local_30 >> 4 == 3) {
    uVar2 = (ushort)local_2a;
    uVar5 = (ushort)local_27 * 0x100 + (ushort)local_28;
    uVar6 = (ushort)local_25 * 0x100 + (ushort)local_26;
    uVar3 = (ushort)local_2b * 0x100 + (ushort)local_2c;
    uVar4 = (ushort)(local_29 & 0xf);
    uVar1 = (ushort)(local_29 >> 4);
  }
  else {
    uVar5 = 0;
    uVar3 = (ushort)local_73;
    uVar1 = (ushort)local_35;
    uVar6 = (ushort)local_74;
    uVar2 = (ushort)local_31;
    uVar4 = (ushort)local_32;
  }
  *param_2 = uVar1;
  param_2[1] = uVar4;
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  param_2[4] = uVar6;
  param_2[5] = uVar5;
  *(undefined8 *)(param_1 + 0x274c) = *(undefined8 *)param_2;
  *(undefined4 *)(param_1 + 0x2754) = *(undefined4 *)(param_2 + 4);
  return 1;
}

