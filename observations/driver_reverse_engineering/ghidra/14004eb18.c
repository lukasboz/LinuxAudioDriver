
void FUN_14004eb18(short param_1,short param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 uVar3;
  short *psVar4;
  uint uVar5;
  
  uVar1 = 0;
  psVar4 = &DAT_140068a72;
  uVar3 = 0;
  uVar5 = 0;
  while ((param_1 != psVar4[-1] || (param_2 != *psVar4))) {
    uVar5 = uVar5 + 1;
    psVar4 = psVar4 + 8;
    if (0xdd < uVar5) {
LAB_14004eb6a:
      *param_3 = uVar1;
      *param_4 = uVar3;
      return;
    }
  }
  lVar2 = (longlong)(int)uVar5;
  uVar1 = *(undefined4 *)(&DAT_140068a74 + lVar2 * 0x10);
  uVar3 = *(undefined4 *)(&DAT_140068a78 + lVar2 * 0x10);
  *param_5 = *(undefined4 *)(&DAT_140068a7c + lVar2 * 0x10);
  goto LAB_14004eb6a;
}

