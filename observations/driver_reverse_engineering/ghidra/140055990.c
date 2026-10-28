
void FUN_140055990(longlong param_1)

{
  ushort *puVar1;
  short sVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  byte bVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  
  lVar7 = *(longlong *)(param_1 + 0x28);
  if (*(longlong *)(lVar7 + 0xb18) == 0) {
    *(ushort *)(param_1 + 0x4c) = *(ushort *)(param_1 + 0x4c) | 6;
  }
  else {
    iVar11 = *(int *)(lVar7 + 0xba0);
    if (*(int *)(lVar7 + 0xba0) == 0) {
      iVar11 = 1;
    }
    iVar10 = -1;
    do {
      iVar6 = (*(code *)PTR__guard_dispatch_icall_14005f458)
                        (*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0xb18),
                         *(undefined8 *)(param_1 + 0x18),param_1);
      iVar5 = iVar6;
      if ((iVar10 != -1) && (iVar5 = iVar10, iVar10 != iVar6)) {
        return;
      }
      iVar10 = iVar5;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    lVar7 = *(longlong *)(param_1 + 0x28);
    uVar9 = (*(ushort *)(param_1 + 0x4c) & 2 | (ushort)iVar6 & 1) * 2 |
            *(ushort *)(param_1 + 0x4c) & 0xfff9;
    *(ushort *)(param_1 + 0x4c) = uVar9;
    if (((*(uint *)(lVar7 + 0x2384) & 0xc0000) != 0) &&
       (bVar8 = (byte)uVar9, ((bVar8 >> 1 ^ bVar8) & 2) != 0)) {
      FUN_140030f40(lVar7,param_1);
      lVar7 = *(longlong *)(param_1 + 0x28);
    }
  }
  if (param_1 != *(longlong *)(lVar7 + 0xe10)) {
    return;
  }
  lVar3 = *(longlong *)(lVar7 + 0xe18);
  if (lVar3 == 0) {
    return;
  }
  if ((*(uint *)(lVar7 + 0x2380) & 0x4000000) == 0) {
    return;
  }
  lVar4 = *(longlong *)(lVar7 + 0xb20);
  if (lVar4 == 0) {
    return;
  }
  sVar2 = *(short *)(lVar7 + 0xe68);
  if ((sVar2 == 0x4040) || (sVar2 == 0x4042)) {
    if ((*(byte *)(param_1 + 0x4c) & 2) == 0) goto LAB_140055b46;
    FUN_14001cd24(lVar4);
  }
  else {
    if (sVar2 != 0x4050) {
      return;
    }
    if ((*(byte *)(param_1 + 0x4c) & 2) == 0) {
LAB_140055b46:
      uVar9 = *(ushort *)(lVar3 + 0x4c);
      *(ushort *)(lVar3 + 0x4c) = (uVar9 * 2 ^ uVar9) & 4 ^ uVar9;
      goto LAB_140055b60;
    }
    FUN_14001ee30(lVar4);
  }
  if ((*(int *)(lVar4 + 0x1f0) == 1) || (*(int *)(lVar4 + 0x1f0) == 2)) {
    lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0xe18);
    uVar9 = *(ushort *)(lVar7 + 0x4c);
    *(ushort *)(lVar7 + 0x4c) = (uVar9 * 2 ^ uVar9) & 4 ^ uVar9;
    puVar1 = (ushort *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0xe18) + 0x4c);
    *puVar1 = *puVar1 | 2;
    return;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0xe18);
  uVar9 = *(ushort *)(lVar7 + 0x4c);
  *(ushort *)(lVar7 + 0x4c) = (uVar9 * 2 ^ uVar9) & 4 ^ uVar9;
LAB_140055b60:
  puVar1 = (ushort *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0xe18) + 0x4c);
  *puVar1 = *puVar1 & 0xfffd;
  return;
}

