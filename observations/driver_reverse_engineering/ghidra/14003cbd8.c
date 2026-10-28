
void FUN_14003cbd8(longlong param_1,int param_2)

{
  undefined8 uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x244) != -1) {
    if ((param_2 - 7U & 0xfffffffd) == 0) {
      if (*(int *)(param_1 + 0x238) == 1) {
        *(undefined8 *)(param_1 + 0x178) = *(undefined8 *)(param_1 + 0x230);
        *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0xd8);
        *(undefined8 *)(param_1 + 0x188) = *(undefined8 *)(param_1 + 0xe0);
        *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x228);
        return;
      }
      uVar4 = 0;
      uVar2 = 0;
      if (*(int *)(param_1 + 0x228) != 0) {
        lVar3 = 0;
        do {
          if (*(undefined **)(lVar3 + 0x10 + *(longlong *)(param_1 + 0x230)) == &DAT_14005feb0) {
            *(undefined8 *)(lVar3 + *(longlong *)(param_1 + 0x230)) = 0;
            *(undefined **)(lVar3 + 0x10 + *(longlong *)(param_1 + 0x230)) = &DAT_140061088;
            *(undefined **)(lVar3 + 8 + *(longlong *)(param_1 + 0x230)) = &DAT_140061088;
          }
          uVar2 = *(uint *)(param_1 + 0x228);
          uVar4 = uVar4 + 1;
          lVar3 = lVar3 + 0x98;
        } while (uVar4 < uVar2);
      }
      *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0xd8);
      *(undefined8 *)(param_1 + 0x188) = *(undefined8 *)(param_1 + 0xe0);
      uVar1 = *(undefined8 *)(param_1 + 0x230);
      *(uint *)(param_1 + 0x170) = uVar2;
      *(undefined4 *)(param_1 + 0x238) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0xc0);
      *(undefined8 *)(param_1 + 0x188) = *(undefined8 *)(param_1 + 200);
      *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 0x210);
      uVar1 = *(undefined8 *)(param_1 + 0x218);
    }
    *(undefined8 *)(param_1 + 0x178) = uVar1;
  }
  return;
}

