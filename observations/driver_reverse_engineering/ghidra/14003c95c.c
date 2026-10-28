
void FUN_14003c95c(longlong param_1,int param_2)

{
  longlong lVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  bool bVar6;
  
  FUN_14003cbd8(param_1,param_2);
  FUN_14003c8b8(param_1,param_2);
  lVar1 = *(longlong *)(param_1 + 0x2d0);
  iVar3 = *(int *)(lVar1 + 0x26b0);
  if ((iVar3 == 0x42) || (iVar3 == 0xa3)) {
    bVar6 = (*(int *)(param_1 + 0x2c8) - 1U & 0xfffffffd) == 0;
LAB_14003ca95:
    if (!bVar6) {
      return;
    }
  }
  else if (iVar3 == 0xb1) {
    if ((((*(uint *)(lVar1 + 0x2384) & 0x80000) == 0) ||
        (*(uint *)(param_1 + 0x2c8) != (uint)*(byte *)(lVar1 + 0xcb3))) &&
       (*(uint *)(param_1 + 0x2c8) != (uint)*(byte *)(lVar1 + 0xcb1))) {
      bVar6 = *(uint *)(param_1 + 0x2c8) == (uint)*(byte *)(lVar1 + 0xcb4);
      goto LAB_14003ca95;
    }
  }
  else if (iVar3 == 0xb4) {
    if (((*(int *)(lVar1 + 0x26b4) - 0x84U < 2) &&
        (uVar4 = *(uint *)(param_1 + 0x2c8), uVar4 != *(byte *)(lVar1 + 0xcb1))) &&
       (uVar4 != *(byte *)(lVar1 + 0xcb4))) {
      if (uVar4 != *(byte *)(lVar1 + 0xcb2)) {
        return;
      }
      if (*(int *)(lVar1 + 0x26b4) != 0x85) {
        bVar6 = *(short *)(lVar1 + 0x26a8) == 0x1b9b;
        goto LAB_14003ca95;
      }
    }
  }
  else if (iVar3 != 0xcb) {
    if (*(int *)(param_1 + 0x2d8) == 8) {
      return;
    }
    if (*(int *)(param_1 + 0x2d8) == 0xb) {
      return;
    }
    if (*(short *)(lVar1 + 0xe68) == 0) {
      return;
    }
  }
  iVar3 = param_2;
  if (*(int *)(param_1 + 0x32c) == 0) {
LAB_14003cab2:
    if (((iVar3 != 0) && (iVar3 != 1)) && ((iVar3 != 2 && ((iVar3 != 3 && (iVar3 != 4))))))
    goto LAB_14003cace;
  }
  else if (param_2 != 6) {
    iVar3 = param_2 + -7;
    goto LAB_14003cab2;
  }
  *(int *)(param_1 + 0x2d8) = param_2;
LAB_14003cace:
  uVar5 = 0;
  if (*(int *)(param_1 + 0xa8) != 0) {
    do {
      lVar1 = *(longlong *)(param_1 + 0xb0);
      if ((*(uint *)(lVar1 + 0x44 + uVar5 * 0x90) & 0xfffffffb) == 0) {
        if (*(int *)(param_1 + 0x32c) == 0) {
          if ((param_2 == 0) || (((param_2 != 1 && (param_2 != 2)) && (param_2 != 3)))) {
            *(undefined **)(lVar1 + 0x48 + uVar5 * 0x90) = &DAT_140060f88;
            *(undefined **)(lVar1 + 0x50 + uVar5 * 0x90) = &DAT_140060f88;
          }
          else {
            *(undefined **)(lVar1 + 0x48 + uVar5 * 0x90) = &DAT_140060ff8;
            *(undefined **)(lVar1 + 0x50 + uVar5 * 0x90) = &DAT_140060ff8;
          }
        }
        else {
          if (param_2 == 7) {
            *(undefined **)(lVar1 + 0x48 + uVar5 * 0x90) = &DAT_140060fe8;
            puVar2 = &DAT_140061048;
          }
          else if (param_2 == 10) {
            *(undefined **)(lVar1 + 0x48 + uVar5 * 0x90) = &DAT_140061008;
            puVar2 = &DAT_140061008;
          }
          else {
            iVar3 = *(int *)(*(longlong *)(param_1 + 0x2d0) + 0x26b0);
            *(undefined **)(lVar1 + 0x48 + uVar5 * 0x90) = &DAT_140061018;
            if (iVar3 == 0x42) {
              puVar2 = &DAT_140061018;
            }
            else {
              puVar2 = &DAT_140061028;
              if (*(int *)(param_1 + 0x380) != 4) {
                puVar2 = &DAT_140061018;
              }
            }
          }
          *(undefined **)(lVar1 + 0x50 + uVar5 * 0x90) = puVar2;
        }
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(param_1 + 0xa8));
  }
  return;
}

