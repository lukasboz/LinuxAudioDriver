
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140028978(longlong param_1,uint param_2,longlong param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined1 auStackY_98 [32];
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = DAT_1400698c0 ^ (ulonglong)auStackY_98;
  uVar4 = param_4 >> 0x1f & 7;
  uVar1 = param_4 + uVar4;
  iVar2 = (uVar1 & 7) - uVar4;
  for (uVar4 = param_2; uVar4 < ((int)uVar1 >> 3) + param_2; uVar4 = uVar4 + 1) {
    uVar3 = FUN_14003190c(param_1,0x17,0xc0,7,(ushort)uVar4 & 0xff,(short)param_2,
                          (ulonglong)((uVar4 - param_2) * 8) + param_3,8,'\x01');
    if ((int)uVar3 < 0) {
      return uVar3;
    }
  }
  if (iVar2 != 0) {
    uVar3 = FUN_14003190c(param_1,0x17,0xc0,7,(ushort)uVar4 & 0xff,(short)param_2,&local_48,8,'\x01'
                         );
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    FUN_14005b100((undefined8 *)((ulonglong)((uVar4 - param_2) * 8) + param_3),&local_48,
                  (longlong)iVar2);
  }
  return 0;
}

