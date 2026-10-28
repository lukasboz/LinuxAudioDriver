
int FUN_1400524f8(longlong param_1,short *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  int unaff_ESI;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar11;
  bool bVar12;
  undefined1 local_res10 [8];
  undefined1 local_res20;
  undefined1 uStackX_21;
  undefined1 local_res22;
  undefined4 in_stack_ffffffffffffff9c;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar13;
  short local_38 [8];
  int iVar10;
  
  uVar13 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  iVar10 = 0;
  iVar2 = 0;
  iVar9 = 0;
  if (param_2 == (short *)0x0) {
    return unaff_ESI;
  }
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 8) != 0)) {
    FUN_1400332e8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x11,&DAT_140061360,
                  "CCommon::NotifyFwToSetDACgain");
  }
  local_38[0] = 0;
  local_38[1] = 0;
  local_res20 = 0xff;
  uStackX_21 = 0xff;
  local_res22 = 0xff;
  iVar3 = 0;
  uVar1 = *(uint *)(param_1 + 0x26b0);
  iVar7 = 1;
  local_res10[0] = 1;
  iVar8 = 0;
  uVar5 = 0;
  uVar6 = 0;
  if ((uVar1 == 0x42) || (uVar1 == 0xa3)) {
    iVar8 = *(int *)(param_1 + 0x26b4);
    if ((iVar8 == 0x4b) || (iVar8 == 0x4c)) {
      bVar11 = *(int *)(param_2 + 0x164) == 4;
      goto LAB_140052a5c;
    }
    if (*(int *)(param_2 + 0x164) != 4) {
      if (*(int *)(param_2 + 0x164) != 5) goto LAB_140052a96;
      if ((((iVar8 == 0x4b) || (iVar8 == 0x4c)) || (iVar8 == 0x79)) ||
         ((iVar8 == 0x7b || (iVar7 = 1, iVar8 == 0x95)))) {
        iVar7 = iVar10;
      }
      if (param_3 == 0) {
LAB_1400527ea:
        uVar6 = 0x77;
        *(undefined2 *)(param_1 + 0xcbc) = 0;
      }
      else {
        iVar2 = iVar9;
        if (param_3 == 1) {
          uVar6 = 0x44;
          *(undefined2 *)(param_1 + 0xcbc) = 1;
        }
        else {
LAB_1400529df:
          if (param_3 == 2) {
            uVar6 = 0x11;
            *(undefined2 *)(param_1 + 0xcbc) = 2;
          }
          else {
            iVar3 = -0x3ffffff3;
          }
        }
      }
LAB_1400527f5:
      local_res20 = 0xff;
      uVar5 = local_res20;
      local_res20 = 0xff;
      uStackX_21 = uVar6;
      if (iVar7 == 0) {
        if (iVar2 != 0) {
          if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
             ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
            pwVar4 = FUN_14003a624(param_2,*(int *)(param_2 + 0x16c));
            FUN_140052f04(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x13,&DAT_140061360,
                          "CCommon::NotifyFwToSetDACgain",CONCAT44(in_stack_ffffffffffffff9c,0x3f0),
                          CONCAT44(uVar13,*(undefined4 *)(param_1 + 0x26b4)),pwVar4);
          }
          FUN_14003c4a8(param_2,10,local_38,4);
          FUN_14003c4a8(param_2,0xb,local_38,4);
          uVar5 = local_res20;
        }
        goto LAB_140052b2d;
      }
      goto LAB_140052a96;
    }
    if (param_3 == 0) {
      uVar6 = 0x66;
      *(undefined2 *)(param_1 + 0xcba) = 0;
    }
    else if (param_3 == 1) {
      uVar6 = 0x33;
      *(undefined2 *)(param_1 + 0xcba) = 1;
    }
    else {
      uVar6 = uVar5;
      if (param_3 == 2) {
        *(undefined2 *)(param_1 + 0xcba) = 2;
      }
    }
    bVar11 = iVar8 == 0x94;
    bVar12 = iVar8 == 0x95;
LAB_14005271f:
    if ((bVar11 || bVar12) && (*(int *)(param_1 + 0xce8) == -0x80000000)) {
      uVar6 = 0x33;
    }
LAB_140052a92:
    uStackX_21 = 0xff;
    local_res20 = uVar6;
  }
  else if (((uVar1 == 0xb3) || (uVar1 < 0xb1)) || (0xb5 < uVar1)) {
    if (uVar1 == 0x9f) {
      if (*(int *)(param_1 + 0x26b4) == 0x93) {
        if (*(int *)(param_2 + 0x164) == 1) {
          if (param_3 == 0) {
            local_res10[0] = 4;
            *(undefined2 *)(param_1 + 0xcba) = 0;
          }
          else if (param_3 == 1) {
            local_res10[0] = 3;
            *(undefined2 *)(param_1 + 0xcba) = 1;
          }
          else if (param_3 == 2) {
            local_res10[0] = 2;
            *(undefined2 *)(param_1 + 0xcba) = 2;
          }
          if (*(int *)(param_1 + 0xce8) == -0x80000000) {
            local_res10[0] = 1;
          }
        }
        iVar3 = FUN_1400319c0(param_1,0x17,0x6c,0,8,local_res10,1);
        uVar5 = local_res20;
        goto LAB_140052b2d;
      }
      if (*(int *)(param_2 + 0x164) != 1) goto LAB_140052a96;
      if (param_3 != 0) {
        if (param_3 == 1) {
          uVar6 = 9;
          goto LAB_140052a7d;
        }
        goto LAB_140052a67;
      }
      uVar6 = 0x12;
LAB_140052a8a:
      *(undefined2 *)(param_1 + 0xcba) = 0;
      goto LAB_140052a92;
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x26b4);
    if (uVar1 < 0x65) {
      if (uVar1 != 100) {
        if (uVar1 < 0x59) {
          if (uVar1 == 0x58) goto LAB_1400528b1;
          if (uVar1 < 0x53) {
            if (uVar1 == 0x52) goto LAB_1400528b1;
            iVar2 = uVar1 - 0x4d;
            bVar11 = iVar2 == 0;
          }
          else {
            iVar2 = uVar1 - 0x53;
            bVar11 = iVar2 == 0;
          }
        }
        else if (uVar1 < 0x5f) {
          if (uVar1 == 0x5e) goto LAB_1400528b1;
          iVar2 = uVar1 - 0x59;
          bVar11 = iVar2 == 0;
        }
        else {
          iVar2 = uVar1 - 0x5f;
          bVar11 = iVar2 == 0;
        }
LAB_140052615:
        if (!bVar11) {
          iVar2 = iVar2 + -1;
LAB_14005261e:
          if (((iVar2 != 0) && (iVar2 != 1)) && (iVar2 != 2)) {
            bVar11 = iVar2 == 3;
            goto LAB_1400526c5;
          }
        }
      }
    }
    else if (uVar1 < 0xca) {
      if (uVar1 != 0xc9) {
        if (uVar1 < 0x70) {
          if (uVar1 != 0x6f) {
            if (0x6a < uVar1) {
              iVar2 = uVar1 - 0x6b;
              goto LAB_14005261e;
            }
            if (uVar1 != 0x6a) {
              iVar2 = uVar1 - 0x65;
              bVar11 = iVar2 == 0;
              goto LAB_140052615;
            }
          }
        }
        else if ((((uVar1 != 0x70) && (uVar1 != 0x71)) && (uVar1 != 0x72)) && (uVar1 != 0x73)) {
          iVar2 = uVar1 - 0x74;
          bVar11 = iVar2 == 0;
          goto LAB_140052615;
        }
      }
    }
    else {
      bVar11 = uVar1 == 0xca;
LAB_1400526c5:
      if (!bVar11) {
        if (*(uint *)(param_2 + 0x164) == (uint)*(byte *)(param_1 + 0xcb2)) {
          if (param_3 == 0) {
            uVar6 = 0x66;
            *(undefined2 *)(param_1 + 0xcba) = 0;
          }
          else if (param_3 == 1) {
            uVar6 = 0x33;
            *(undefined2 *)(param_1 + 0xcba) = 1;
          }
          else {
            uVar6 = uVar5;
            if (param_3 == 2) {
              *(undefined2 *)(param_1 + 0xcba) = 2;
            }
          }
          bVar11 = uVar1 - 0x96 < 8;
          bVar12 = uVar1 - 0x96 == 8;
          goto LAB_14005271f;
        }
        if (*(uint *)(param_2 + 0x164) != (uint)*(byte *)(param_1 + 0xcb0)) goto LAB_140052a96;
        iVar2 = iVar10;
        if (uVar1 < 0x90) {
          if ((((uVar1 == 0x8f) || (uVar1 == 0x85)) ||
              ((uVar1 == 0x87 ||
               ((((uVar1 == 0x88 || (uVar1 == 0x89)) || (uVar1 == 0x8a)) ||
                ((uVar1 == 0x8b || (uVar1 == 0x8c)))))))) ||
             ((uVar1 == 0x8d || (iVar7 = 1, uVar1 == 0x8e)))) {
LAB_14005278a:
            iVar2 = 1;
            goto LAB_14005278d;
          }
        }
        else {
          if ((uVar1 == 0x90) || (uVar1 == 0x91)) goto LAB_14005278a;
          if (((uVar1 != 0x97) &&
              (((iVar2 = iVar8, uVar1 != 0x98 && (uVar1 != 0x99)) && (uVar1 != 0x9a)))) &&
             (((uVar1 != 0x9b && (uVar1 != 0x9c)) && (uVar1 != 0x9d)))) goto LAB_140052790;
LAB_14005278d:
          iVar7 = iVar10;
        }
LAB_140052790:
        if (param_3 == 0) {
          local_38[0] = 0;
          local_38[1] = -9;
          goto LAB_1400527ea;
        }
        if (param_3 != 1) goto LAB_1400529df;
        uVar6 = 0x44;
        *(undefined2 *)(param_1 + 0xcbc) = 1;
        local_38[0] = -0x8000;
        local_38[1] = -5;
        iVar3 = iVar9;
        goto LAB_1400527f5;
      }
    }
LAB_1400528b1:
    bVar11 = *(uint *)(param_2 + 0x164) == (uint)*(byte *)(param_1 + 0xcb2);
LAB_140052a5c:
    if (bVar11) {
      if (param_3 == 0) {
        uVar6 = 0x44;
        goto LAB_140052a8a;
      }
      if (param_3 == 1) {
        uVar6 = 0x22;
LAB_140052a7d:
        *(undefined2 *)(param_1 + 0xcba) = 1;
      }
      else {
LAB_140052a67:
        if (param_3 == 2) {
          *(undefined2 *)(param_1 + 0xcba) = 2;
        }
      }
      goto LAB_140052a92;
    }
  }
LAB_140052a96:
  iVar3 = FUN_1400319c0(param_1,0x17,0x6c,0,5,&local_res20,3);
  uVar5 = local_res20;
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
    FUN_140032e8c(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x12,&DAT_140061360,
                  "CCommon::NotifyFwToSetDACgain");
    uVar5 = local_res20;
  }
LAB_140052b2d:
  local_res20 = uVar5;
  if (iVar3 < 0) {
    if ((*(int *)(param_1 + 0x26b0) == 0x42) || (*(int *)(param_1 + 0x26b0) == 0x9f)) {
      *(uint *)(param_1 + 0x2378) = *(uint *)(param_1 + 0x2378) | 0x40;
    }
  }
  else {
    *(uint *)(param_1 + 0x2378) = *(uint *)(param_1 + 0x2378) & 0xffffffbf;
    FUN_140031bac((longlong *)(param_1 + 0x2348),0x14005b7c0,L"AMP_Level",3,4,param_1 + 0xcba,0);
  }
  return unaff_ESI;
}

