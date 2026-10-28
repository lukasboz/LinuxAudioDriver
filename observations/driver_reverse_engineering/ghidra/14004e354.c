
undefined8 FUN_14004e354(longlong param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  char cVar7;
  uint uVar8;
  undefined8 uVar9;
  
  uVar9 = 0xc000000d;
  if (param_2 != -1) {
    if ((param_2 == 0) || (param_2 == 3)) {
      *(undefined4 *)(param_1 + 0x254) = 2;
    }
    else if (param_2 == 0x33) {
      *(undefined4 *)(param_1 + 0x254) = 4;
    }
    else if (param_2 == 0x3f) {
      *(undefined4 *)(param_1 + 0x254) = 6;
    }
    else {
      if (param_2 != 0x63f) goto LAB_14004e42c;
      *(undefined4 *)(param_1 + 0x254) = 8;
    }
    *(int *)(param_1 + 0x24c) = param_2;
    uVar9 = 0;
    FUN_14003cd74(param_1,0,L"current_channel_number",4,4,param_1 + 0x254);
    FUN_14003cd74(param_1,0,L"channel_config.ActiveSpeakerPositions",4,4,(int *)(param_1 + 0x24c));
    FUN_14003ccf0(param_1);
  }
LAB_14004e42c:
  uVar8 = 7;
  if (((((*(int *)(*(longlong *)(param_1 + 0x2d0) + 0x26b4) - 0x79U & 0xfffffffd) == 0) &&
       (*(int *)(param_1 + 0x2d8) == 1)) &&
      (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x2d0) + 0xe40), lVar5 != 0)) &&
     (((char)*(ushort *)(lVar5 + 0x4e) < '\0' && ((*(ushort *)(lVar5 + 0x4e) & 1) != 0)))) {
    uVar4 = FUN_14004d0c4(param_1);
    if (uVar4 < 8) {
      if ((uVar4 == 6) && (*(int *)(param_1 + 0x24c) == 0x60f)) goto LAB_14004e495;
      uVar8 = 0;
    }
    else {
      uVar8 = 7;
    }
    uVar8 = FUN_14005470c(lVar5,uVar8);
  }
LAB_14004e495:
  lVar5 = *(longlong *)(param_1 + 0x2d0);
  if ((*(uint *)(lVar5 + 0x2388) & 4) != 0) {
    if (*(uint *)(param_1 + 0x254) < 8) {
      *(uint *)(lVar5 + 0x2394) = *(uint *)(lVar5 + 0x2394) | 0x100;
    }
    else {
      *(uint *)(lVar5 + 0x2394) = *(uint *)(lVar5 + 0x2394) & 0xfffffeff;
    }
    FUN_140031bac((longlong *)(*(longlong *)(param_1 + 0x2d0) + 0x2348),0x14005b7c0,L"JackConfig",3,
                  4,*(longlong *)(param_1 + 0x2d0) + 0x2394,0);
    lVar5 = *(longlong *)(param_1 + 0x2d0);
  }
  if (3 < *(int *)(lVar5 + 0x26b4) - 0x7eU) goto LAB_14004e5bd;
  lVar6 = *(longlong *)(lVar5 + 0xe48);
  lVar3 = *(longlong *)(lVar5 + 0xe60);
  lVar5 = *(longlong *)(lVar5 + 0xe50);
  iVar2 = *(int *)(param_1 + 0x254);
  if (lVar6 != 0) {
    uVar8 = 5;
    if (iVar2 == 2) {
      uVar8 = 0xf;
    }
    uVar8 = FUN_14005470c(lVar6,uVar8);
    lVar5 = CONCAT44((int)((ulonglong)lVar5 >> 0x20),uVar8);
    *(ushort *)(lVar6 + 0x4c) = *(ushort *)(lVar6 + 0x4c) & 0xfff7;
  }
  if (lVar3 != 0) {
    if ((iVar2 - 2U & 0xfffffffd) == 0) {
      uVar8 = 1;
LAB_14004e57d:
      uVar8 = FUN_14005470c(lVar3,uVar8);
      lVar5 = CONCAT44((int)((ulonglong)lVar5 >> 0x20),uVar8);
    }
    else if ((iVar2 - 6U & 0xfffffffd) == 0) {
      uVar8 = 6;
      goto LAB_14004e57d;
    }
    *(ushort *)(lVar3 + 0x4c) = *(ushort *)(lVar3 + 0x4c) & 0xfff7;
  }
  if (lVar5 != 0) {
    uVar8 = 2;
    if (iVar2 == 8) {
      uVar8 = 7;
    }
    uVar8 = FUN_14005470c(lVar5,uVar8);
    puVar1 = (ushort *)(CONCAT44((int)((ulonglong)lVar5 >> 0x20),uVar8) + 0x4c);
    *puVar1 = *puVar1 & 0xfff7;
  }
  uVar8 = 7;
LAB_14004e5bd:
  lVar5 = *(longlong *)(param_1 + 0x2d0);
  if ((*(int *)(lVar5 + 0x26b4) == 0x84) || (*(int *)(lVar5 + 0x26b4) == 0x85)) {
    FUN_1400325f4(lVar5,*(int *)(param_1 + 0x254));
    lVar5 = *(longlong *)(param_1 + 0x2d0);
  }
  if (((*(int *)(lVar5 + 0x26b4) - 0xc9U < 2) || (*(int *)(lVar5 + 0x26b4) == 0x85)) ||
     (*(short *)(lVar5 + 0x26a8) == 0x1b9b)) {
    lVar5 = FUN_14002821c(lVar5,0x21);
    iVar2 = *(int *)(param_1 + 0x254);
    if (lVar5 != 0) {
      if ((*(uint *)(*(longlong *)(param_1 + 0x2d0) + 0x2394) & 0x100) == 0) {
        uVar4 = 2;
        if (iVar2 == 8) {
          uVar4 = uVar8;
        }
        uVar8 = FUN_14005470c(lVar5,uVar4);
        lVar6 = *(longlong *)(param_1 + 0x2d0);
        if ((*(byte *)(lVar5 + 0x4c) & 2) == 0) {
          cVar7 = (char)uVar8;
        }
        else {
          cVar7 = (iVar2 == 8) + '\x06';
        }
      }
      else {
        FUN_14005470c(lVar5,2);
        lVar6 = *(longlong *)(param_1 + 0x2d0);
        cVar7 = '\b';
      }
      FUN_140052368(lVar6,cVar7);
    }
  }
  if (((*(uint *)(*(longlong *)(param_1 + 0x2d0) + 0x2388) & 4) != 0) &&
     (lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x2d0) + 3000), lVar5 != 0)) {
    FUN_14004cb60(lVar5);
    FUN_14004ccf8(*(longlong *)(*(longlong *)(param_1 + 0x2d0) + 3000));
  }
  return uVar9;
}

