
int FUN_14002ff18(longlong param_1,uint param_2,longlong param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  byte bVar7;
  undefined1 uVar8;
  ushort uVar9;
  undefined2 uVar10;
  uint *puVar11;
  uint local_res8 [2];
  uint local_res10 [2];
  ulonglong local_res20;
  
  uVar5 = (ulonglong)param_2;
  iVar3 = -0x3fffffff;
  KeWaitForSingleObject(param_1 + 0xb30,0,0,0,0);
  if (0 < (int)param_2) {
    puVar11 = (uint *)(param_3 + 8);
    do {
      puVar4 = (ulonglong *)local_res10;
      *puVar11 = 0;
      uVar2 = puVar11[-2];
      uVar1 = (uVar2 & 0xff0000) >> 8;
      local_res10[0] = uVar2 >> 0x18 | uVar1 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      local_res20 = (ulonglong)local_res10[0];
      uVar1 = uVar1 & 0x800;
      if (*(int *)(param_1 + 0xfc8) == 0x1220) {
        bVar7 = -(uVar1 != 0);
        uVar9 = -(ushort)(uVar1 != 0) & 0x400;
        if (uVar1 != 0) {
          puVar4 = &local_res20;
        }
        uVar2 = -(uint)(uVar1 != 0) & 4;
      }
      else {
        bVar7 = -(uVar1 != 0) & 0x1a;
        uVar9 = 0;
        uVar2 = 0;
      }
      iVar3 = FUN_14003190c(param_1,0x17,0x40,bVar7 + 0x3e,(ushort)*(byte *)(param_1 + 0xe6a),uVar9,
                            puVar4,uVar2 + 4,'\0');
      if ((-1 < iVar3) && ((local_res10[0] & 0x800) != 0)) {
        local_res8[0] = 0;
        if (*(int *)(param_1 + 0xfc8) == 0x1220) {
          uVar8 = 0x3d;
          puVar4 = &local_res20;
          uVar10 = 0x400;
          uVar6 = 8;
        }
        else {
          uVar10 = 0;
          puVar4 = (ulonglong *)local_res8;
          uVar8 = 0x59;
          uVar6 = 4;
        }
        iVar3 = FUN_14003190c(param_1,0x17,0xc0,uVar8,(ushort)*(byte *)(param_1 + 0xe6a),uVar10,
                              puVar4,uVar6,'\x01');
        if (-1 < iVar3) {
          uVar2 = local_res8[0];
          if (*(int *)(param_1 + 0xfc8) == 0x1220) {
            uVar2 = (uint)local_res20;
          }
          *puVar11 = (uVar2 & 0xff0000 | uVar2 >> 0x10) >> 8 | (uVar2 & 0xff00 | uVar2 << 0x10) << 8
          ;
        }
      }
      puVar11 = puVar11 + 4;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  KeReleaseMutex(param_1 + 0xb30,0);
  return iVar3;
}

