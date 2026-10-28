
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_14003a868(short *param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  iVar2 = 0;
  if (*(uint *)(param_1 + 0x54) < 2) {
    return -0x3fffffff;
  }
  if (*(int *)(param_1 + 0x16c) == 0xc) {
    return -0x3fffffff;
  }
  lVar4 = *(longlong *)(param_1 + 0x168);
  if (((((*(uint *)(lVar4 + 0x2380) & 0x10000) != 0) && (*(int *)(param_1 + 0x196) != 0)) &&
      (*(int *)(param_1 + 0x174) != 0)) &&
     ((*(byte *)(**(longlong **)(param_1 + 0x178) + 0x4c) & 2) == 0)) {
    return -0x3fffffff;
  }
  if ((*(uint *)(lVar4 + 0x2384) & 0x400) == 0) goto LAB_14003aa22;
  if ((*(int *)(lVar4 + 0x26b0) == 0xb1) || (*(int *)(lVar4 + 0x26b0) == 0x42)) {
    if (*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar4 + 0xcb4)) {
      lVar3 = *(longlong *)(lVar4 + 0xe40);
      goto LAB_14003a91a;
    }
  }
  else if ((*(int *)(lVar4 + 0x26b4) - 0x80U < 2) &&
          (*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar4 + 0xcb0))) {
    lVar3 = *(longlong *)(lVar4 + 0xe50);
LAB_14003a91a:
    if ((lVar3 != 0) && (*(int *)(lVar3 + 0x20) == 7)) {
      return -0x3fffffff;
    }
  }
  if (((*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar4 + 0xcb0)) &&
      (((*(int *)(lVar4 + 0x26b4) == 0x85 || (*(short *)(lVar4 + 0x26a8) == 0x1b9b)) &&
       (lVar4 = FUN_14002821c(lVar4,0x21), lVar4 != 0)))) && (*(int *)(lVar4 + 0x20) == 7)) {
    return -0x3fffffff;
  }
  lVar4 = *(longlong *)(param_1 + 0x168);
  if (((*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar4 + 0xcb1)) &&
      ((*(int *)(lVar4 + 0x26b4) == 0x85 || (*(short *)(lVar4 + 0x26a8) == 0x1b9b)))) &&
     ((lVar4 = FUN_14002821c(lVar4,0x38), lVar4 != 0 && (*(int *)(lVar4 + 0x20) == 5)))) {
    return -0x3fffffff;
  }
  lVar4 = *(longlong *)(param_1 + 0x168);
  if (((*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar4 + 0xcb4)) &&
      ((*(int *)(lVar4 + 0x26b4) == 0x85 || (*(short *)(lVar4 + 0x26a8) == 0x1b9b)))) &&
     ((lVar4 = FUN_14002821c(lVar4,0x19), lVar4 != 0 && (*(int *)(lVar4 + 0x20) == 6)))) {
    return -0x3fffffff;
  }
LAB_14003aa22:
  lVar4 = *(longlong *)(param_1 + 0x168);
  if ((((*(int *)(lVar4 + 0x26b0) == 0xc3) &&
       (*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar4 + 0xcb1))) ||
      ((*(int *)(lVar4 + 0x26b4) == 0xce && (*(int *)(param_1 + 0x164) == 2)))) ||
     ((*(int *)(lVar4 + 0x26b0) == 0xc5 &&
      (*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar4 + 0xcb3))))) {
    return -0x3fffffff;
  }
  LOCK();
  iVar1 = *(int *)(param_1 + 0x194);
  *(int *)(param_1 + 0x194) = 1;
  UNLOCK();
  if (iVar1 == 0) {
    FUN_14003a6d8(param_1);
    KsAcquireDevice(*(undefined8 *)(*(longlong *)(param_1 + 0x168) + 0x26d8));
    puVar5 = FUN_14003a5ec((longlong)param_1);
    iVar2 = KsCreateFilterFactory
                      (*(undefined8 *)(*(longlong *)(param_1 + 0x168) + 0x26f0),param_1 + 0x98,
                       puVar5,0,CONCAT44(uVar8,8),0,0,param_1 + 0x138);
    if (-1 < iVar2) {
      memset(param_1,0,0xa0);
      FUN_14003b590((longlong)param_1,0x14005c6a0,L"PropertyStorePath",0x4e,(undefined8 *)param_1);
      iVar2 = KsFilterFactorySetDeviceClassesState(*(undefined8 *)(param_1 + 0x138),1);
      if (*(longlong *)(*(longlong *)(param_1 + 0x168) + 0xb20) != 0) {
        (*(code *)PTR__guard_dispatch_icall_14005f458)
                  (*(longlong *)(*(longlong *)(param_1 + 0x168) + 0xb20),param_1);
      }
    }
    KsReleaseDevice(*(undefined8 *)(*(longlong *)(param_1 + 0x168) + 0x26d8));
    if (*(int *)(param_1 + 0x196) == 0) {
      local_28 = _DAT_140061118;
      uStack_20 = _UNK_140061120;
      puVar5 = FUN_14003a5ec((longlong)param_1);
      puVar6 = &local_28;
    }
    else {
      local_38 = _DAT_140061128;
      uStack_30 = _UNK_140061130;
      puVar5 = FUN_14003a5ec((longlong)param_1);
      puVar6 = &local_38;
    }
    uVar7 = FUN_1400305a8(*(longlong *)(param_1 + 0x168),(undefined4 *)puVar6,(longlong)puVar5);
    local_18 = _DAT_1400602d8;
    uStack_10 = _UNK_1400602e0;
    puVar5 = FUN_14003a5ec(uVar7);
    param_1 = (short *)FUN_1400305a8(*(longlong *)(uVar7 + 0x2d0),(undefined4 *)&local_18,
                                     (longlong)puVar5);
  }
  FUN_14003c514(param_1);
  if ((*(uint *)(*(longlong *)(param_1 + 0x168) + 0x237c) >> 0xc & 1) == 0) {
    if ((*(uint *)(*(longlong *)(param_1 + 0x168) + 0x237c) & 0x10) != 0) {
      FUN_14003b864(param_1);
      return iVar2;
    }
    return iVar2;
  }
  return iVar2;
}

