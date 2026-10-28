
int FUN_140055f24(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0xf;
  uVar1 = *param_2 >> 0x14 & 0xf;
  if ((uVar1 == 0) || (uVar1 == 1)) {
    iVar2 = (*param_2 & 0xf) + 4;
  }
  else if (uVar1 == 2) {
    iVar2 = 2;
  }
  else if (uVar1 == 4) {
    iVar2 = 8;
  }
  else if ((uVar1 == 8) || (uVar1 == 9)) {
    iVar2 = 0;
  }
  else if (uVar1 == 10) {
    iVar2 = 1;
  }
  else if (uVar1 != 0xb) {
    if (uVar1 == 0xd) {
      iVar2 = 0x24;
    }
    else {
      iVar2 = 0xffff;
    }
  }
  return iVar2;
}

