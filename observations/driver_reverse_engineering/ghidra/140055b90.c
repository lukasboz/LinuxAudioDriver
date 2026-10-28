
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140055b90(int *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined *puVar3;
  uint uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  wchar_t *pwVar8;
  byte bVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  undefined1 auStackY_88 [32];
  undefined4 in_stack_ffffffffffffff9c;
  uint local_38 [4];
  ulonglong local_28;
  
  local_28 = DAT_1400698c0 ^ (ulonglong)auStackY_88;
  uVar10 = *(ushort *)(param_1 + 0x13);
  if (((uVar10 & 1) == 0) ||
     (lVar1 = *(longlong *)(param_1 + 10), *(longlong *)(lVar1 + 0x2180) == 0)) goto LAB_140055cbc;
  if (((*(uint *)(lVar1 + 0x2394) & 0x8080) != 0x8080) ||
     (lVar2 = *(longlong *)(param_1 + 6), lVar2 == 0)) goto LAB_140055d32;
  if (((*(short *)(lVar1 + 0x26aa) == 0xdb0) &&
      ((*(int *)(lVar1 + 0x26b0) == 0xb1 || (*(int *)(lVar1 + 0x26b0) == 0x42)))) &&
     (((uVar11 = *(uint *)(lVar2 + 0x2c8), uVar11 == *(byte *)(lVar1 + 0xcb1) ||
       (uVar11 == *(byte *)(lVar1 + 0xcb0))) ||
      ((((*(uint *)(lVar1 + 0x2384) >> 0x13 & 1) != 0 && (uVar11 == *(byte *)(lVar1 + 0xcb3))) &&
       (param_1[4] == 0x38)))))) goto LAB_140055cbc;
  uVar11 = *(uint *)(lVar1 + 0x26b4);
  if (uVar11 < 0x8a) {
    if (uVar11 != 0x89) {
      if (uVar11 == 0x7d) {
        bVar13 = *(int *)(lVar2 + 0x2c8) == 1;
      }
      else {
        iVar6 = uVar11 - 0x82;
        if (iVar6 != 0) goto LAB_140055c81;
        bVar13 = *(uint *)(lVar2 + 0x2c8) == (uint)*(byte *)(lVar1 + 0xcb1);
      }
      if (!bVar13) goto LAB_140055d32;
      goto LAB_140055cbc;
    }
  }
  else if ((uVar11 != 0x8a) && (iVar6 = uVar11 - 0x8b, iVar6 != 0)) {
LAB_140055c81:
    if (((iVar6 != 1) && (iVar6 != 2)) &&
       ((iVar6 != 3 && (((iVar6 != 4 && (iVar6 != 5)) && (iVar6 != 6)))))) goto LAB_140055d32;
  }
  uVar11 = *(uint *)(lVar2 + 0x2c8);
  if (((uVar11 != *(byte *)(lVar1 + 0xcb1)) && (uVar11 != *(byte *)(lVar1 + 0xcb0))) &&
     (((*(uint *)(lVar1 + 0x2384) >> 0x13 & 1) == 0 ||
      ((uVar11 != *(byte *)(lVar1 + 0xcb3) || (param_1[4] != 0x38)))))) {
LAB_140055d32:
    if (*param_1 == 0) {
      uVar5 = *(short *)(lVar1 + 0xe68) + 0xbfce;
      if (((0x1e < uVar5) || ((0x40014001U >> (uVar5 & 0x1f) & 1) == 0)) &&
         (*(short *)(lVar1 + 0xe68) != 0x4080)) {
        local_38[1] = 0;
        local_38[2] = 0;
        local_38[3] = 0;
        local_38[0] = param_1[4] << 0x14 | 0xf0900;
        iVar6 = *(int *)(lVar1 + 0xba0);
        if (iVar6 == 0) {
          iVar6 = 1;
        }
        uVar12 = 0xffffffff;
        uVar11 = uVar10 >> 1 & 1;
        do {
          iVar7 = FUN_14002ff18(*(longlong *)(param_1 + 10),1,(longlong)local_38);
          uVar4 = uVar12;
          if (iVar7 < 0) {
            if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
               ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
              FUN_1400332e8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0xd,&DAT_140061398,
                            "CWidget::ChkPlugState");
            }
          }
          else {
            uVar11 = local_38[2] >> 0x1f;
            uVar4 = uVar11;
            if ((uVar12 != 0xffffffff) && (uVar4 = uVar12, uVar12 != uVar11)) {
              return;
            }
          }
          uVar12 = uVar4;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        uVar10 = (*(ushort *)(param_1 + 0x13) & 2 | (ushort)uVar11) * 2 |
                 *(ushort *)(param_1 + 0x13) & 0xfff9;
        bVar9 = (byte)uVar10;
        *(ushort *)(param_1 + 0x13) = uVar10;
        puVar3 = PTR_LOOP_140067000;
        if (((((bVar9 >> 1 ^ bVar9) & 2) != 0) &&
            ((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000)) &&
           ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
          pwVar8 = FUN_14005627c(param_1,param_1[4]);
          FUN_140056aac(*(undefined8 *)(puVar3 + 0x18),0xe,&DAT_140061398,"CWidget::ChkPlugState",
                        CONCAT44(in_stack_ffffffffffffff9c,0x9c2),pwVar8);
        }
        lVar1 = *(longlong *)(param_1 + 10);
        if (-1 < (char)*(undefined4 *)(lVar1 + 0x2378)) {
          return;
        }
        if ((*(ushort *)(param_1 + 0x13) & 4) != 0) {
          return;
        }
        if ((*(ushort *)(param_1 + 0x13) & 2) == 0) {
          return;
        }
        if (param_1 != *(int **)(lVar1 + 0xe10)) {
          return;
        }
        *(undefined4 *)(lVar1 + 0x4c) = 0;
        return;
      }
    }
    FUN_140055990((longlong)param_1);
    return;
  }
LAB_140055cbc:
  *(ushort *)(param_1 + 0x13) = uVar10 | 6;
  return;
}

