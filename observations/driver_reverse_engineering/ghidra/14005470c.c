
uint FUN_14005470c(longlong param_1,uint param_2)

{
  ushort *puVar1;
  short sVar2;
  int iVar3;
  longlong lVar4;
  byte bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  undefined *puVar9;
  uint uVar10;
  longlong lVar11;
  int *piVar12;
  uint uVar13;
  undefined1 uVar14;
  int iVar15;
  uint unaff_EBP;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  int local_res8 [2];
  uint local_58;
  short local_54 [2];
  int local_50;
  uint local_4c;
  int local_48;
  
  puVar9 = PTR_LOOP_140067000;
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 8) != 0)) {
    uVar13 = *(uint *)(param_1 + 0x10);
    FUN_1400560ec(param_1,*(uint *)(param_1 + 0x20));
    FUN_1400560ec(param_1,param_2);
    FUN_14005627c(param_1,uVar13);
    FUN_140056e80(*(undefined8 *)(puVar9 + 0x18),10,&DAT_140061398,"CWidget::AssignDeviceType");
  }
  lVar11 = *(longlong *)(param_1 + 0x28);
  if ((param_1 == *(longlong *)(lVar11 + 0xe10)) && ((*(uint *)(lVar11 + 0x2380) & 0x4020000) != 0))
  {
    param_2 = 0x32;
  }
  uVar13 = *(uint *)(lVar11 + 0x2384);
  bVar18 = false;
  if ((uVar13 >> 0x13 & 1) != 0) {
    lVar4 = *(longlong *)(lVar11 + 0xe28);
    if ((((lVar4 != 0) && (param_1 != lVar4)) && (*(int *)(lVar4 + 0x20) == 0)) &&
       (bVar18 = false, (*(byte *)(lVar4 + 0x4c) & 2) != 0)) {
      bVar18 = true;
    }
    lVar4 = *(longlong *)(lVar11 + 0xe30);
    if (((lVar4 != 0) && (param_1 != lVar4)) &&
       ((*(int *)(lVar4 + 0x20) == 0 && ((*(byte *)(lVar4 + 0x4c) & 2) != 0)))) {
      bVar18 = true;
    }
    if (((uVar13 >> 0x14 & 1) == 0) && (*(int *)(param_1 + 0x10) == 0x18)) {
      uVar13 = *(uint *)(param_1 + 0x3c) & 0xffafffff | 0xa00000;
      *(uint *)(param_1 + 0x3c) = uVar13;
      *(ushort *)(param_1 + 0x4c) =
           *(ushort *)(param_1 + 0x4c) ^
           ((ushort)(uVar13 >> 0x10) & 0xfff0 ^ *(ushort *)(param_1 + 0x4c)) & 0xf0;
      return unaff_EBP;
    }
  }
  uVar10 = 0;
  local_50 = 0;
  bVar6 = false;
  bVar8 = false;
  local_res8[0] = 0;
  uVar17 = 0;
  uVar16 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0x2d8);
  bVar7 = false;
  local_4c = 0;
  local_48 = 0;
  if (((uVar13 >> 0x16 & 1) != 0) && (*(int *)(param_1 + 0x10) == 0x1f)) {
    if ((param_2 == 0x32) || (param_2 == 0x20)) {
      *(undefined4 *)(param_1 + 0x20) = 0x32;
      if (*(longlong *)(lVar11 + 0xe20) != 0) {
        puVar1 = (ushort *)(*(longlong *)(lVar11 + 0xe20) + 0x4c);
        *puVar1 = *puVar1 | 2;
        lVar11 = *(longlong *)(param_1 + 0x28);
        lVar4 = *(longlong *)(*(longlong *)(lVar11 + 0xe20) + 0x18);
        if (lVar4 != 0) {
          FUN_14003ccf0(lVar4);
          lVar11 = *(longlong *)(param_1 + 0x28);
        }
      }
      uVar10 = 1;
      FUN_140052e2c(lVar11,'\x02');
      param_2 = 0x32;
    }
    else if (param_2 == 2) {
      *(undefined4 *)(param_1 + 0x20) = 2;
      if (*(longlong *)(lVar11 + 0xe20) != 0) {
        puVar1 = (ushort *)(*(longlong *)(lVar11 + 0xe20) + 0x4c);
        *puVar1 = *puVar1 | 2;
        lVar11 = *(longlong *)(param_1 + 0x28);
        lVar4 = *(longlong *)(*(longlong *)(lVar11 + 0xe20) + 0x18);
        if (lVar4 != 0) {
          FUN_14003ccf0(lVar4);
          lVar11 = *(longlong *)(param_1 + 0x28);
        }
      }
      FUN_140052e2c(lVar11,'\x01');
      return unaff_EBP;
    }
  }
  lVar11 = *(longlong *)(param_1 + 0x28);
  uVar13 = 1;
  if (*(int *)(lVar11 + 0x26b0) == 5) {
    if (*(int *)(*(longlong *)(param_1 + 0x18) + 0x32c) == 0) {
      if (((param_2 != 0) && (param_2 != 1)) && (param_2 != 0x21)) goto LAB_1400549e1;
    }
    else if (((param_2 == 0) || (param_2 == 1)) || (param_2 == 0x21)) {
LAB_1400549e1:
      local_50 = 1;
    }
  }
  local_58 = 0;
  local_54[0] = 0;
  local_54[1] = 0;
  if (param_2 < 0x22) {
    if (param_2 == 0x21) {
      uVar16 = 10;
      if ((*(byte *)(param_1 + 0x4e) & 2) != 0) {
LAB_140054d0e:
        uVar10 = uVar13;
      }
    }
    else if (param_2 < 6) {
      if (param_2 == 5) {
        bVar7 = false;
        if (((*(uint *)(lVar11 + 0x2384) & 0x100000) != 0) &&
           (param_1 == *(longlong *)(lVar11 + 0xe48))) {
          FUN_140052368(lVar11,0xc);
          lVar11 = *(longlong *)(param_1 + 0x28);
          uVar10 = 1;
          local_res8[0] = 1;
          bVar7 = true;
        }
        if (((*(uint *)(lVar11 + 0x2388) & 1) != 0) && (param_1 == *(longlong *)(lVar11 + 0xe48))) {
          FUN_140052368(lVar11,1);
          FUN_140052368(*(longlong *)(param_1 + 0x28),0xc);
          if ((*(int *)(*(longlong *)(param_1 + 0x28) + 0x26b4) == 0x85) ||
             (*(short *)(*(longlong *)(param_1 + 0x28) + 0x26a8) == 0x1b9b)) {
            local_res8[0] = 0;
            bVar6 = true;
          }
          else {
            local_res8[0] = 1;
          }
          uVar10 = 1;
          bVar8 = true;
        }
      }
      else {
        if (param_2 == 0) {
          uVar16 = 7;
          if (param_1 == *(longlong *)(lVar11 + 0xe40)) {
            FUN_140052368(lVar11,3);
            *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x48) = 0;
          }
          else if (param_1 == *(longlong *)(lVar11 + 0xe48)) {
            FUN_140052368(lVar11,(*(uint *)(lVar11 + 0x2384) & 0x80400) != 0x80400);
            if (((*(uint *)(*(longlong *)(param_1 + 0x28) + 0x2384) & 0x100000) != 0) ||
               (iVar15 = *(int *)(*(longlong *)(param_1 + 0x28) + 0x26b4),
               iVar15 == 0x84 || iVar15 == 0x85)) {
              bVar7 = true;
            }
          }
          else if (param_1 == *(longlong *)(lVar11 + 0xe58)) {
            if (*(uint *)(param_1 + 0x20) < 2) {
              uVar14 = 0x12;
            }
            else {
              if (*(uint *)(param_1 + 0x20) != 6) goto LAB_140054c16;
              uVar14 = 0x15;
            }
            FUN_140052368(lVar11,uVar14);
          }
LAB_140054c16:
          bVar5 = *(byte *)(param_1 + 0x4e) & 1;
        }
        else {
          if (param_2 != 1) {
            if (param_2 == 2) goto LAB_140055169;
            if ((param_2 == 3) || (param_2 == 4)) goto LAB_140055096;
            goto LAB_140054ecf;
          }
          iVar15 = *(int *)(lVar11 + 0x26b0);
          if (((iVar15 == 0x34) || (iVar15 == 0x92)) || ((iVar15 == 0xb3 || (iVar15 == 0xb4)))) {
            iVar15 = *(int *)(param_1 + 0x10);
            if (iVar15 == 0x18) {
LAB_140054ab8:
              uVar16 = 6;
            }
            else if (iVar15 == 0x19) {
              if (*(int *)(lVar11 + 0x26b4) - 0x84U < 2) goto LAB_140054ab8;
            }
            else if (iVar15 == 0x38) {
              uVar16 = 8;
            }
            else if (iVar15 == 0x39) {
              uVar16 = 0xb;
            }
          }
          else {
            uVar16 = (-(uint)((*(uint *)(lVar11 + 0x2384) & 0x100000) != 0) & 2) + 6;
            if (bVar18) {
              uVar16 = 7;
            }
          }
          if (param_1 == *(longlong *)(lVar11 + 0xe48)) {
            FUN_140052368(lVar11,0);
            if (*(int *)(param_1 + 0x20) == 5) {
              FUN_140052368(*(longlong *)(param_1 + 0x28),0xd);
            }
            if (((*(uint *)(*(longlong *)(param_1 + 0x28) + 0x2384) & 0x100000) != 0) ||
               (*(int *)(*(longlong *)(param_1 + 0x28) + 0x26b4) - 0x84U < 2)) {
              bVar7 = true;
            }
          }
          else if (param_1 == *(longlong *)(lVar11 + 0xe60)) {
            FUN_140052368(lVar11,0xf);
            local_4c = *(uint *)(*(longlong *)(param_1 + 0x28) + 0x2384) >> 0x14 & 1;
            uVar17 = *(uint *)(*(longlong *)(param_1 + 0x28) + 0x2388) & 1;
          }
          else if (param_1 == *(longlong *)(lVar11 + 0xe58)) {
            if (*(int *)(param_1 + 0x20) == 6) {
              FUN_140052368(lVar11,0x15);
              lVar11 = *(longlong *)(param_1 + 0x28);
            }
            FUN_140052368(lVar11,0x13);
            uVar17 = 0;
            if ((*(byte *)(*(longlong *)(param_1 + 0x28) + 0x2388) & 1) != 0) {
              uVar17 = 1;
            }
          }
          bVar5 = *(byte *)(param_1 + 0x4e) & 2;
        }
        bVar8 = bVar7;
        if (bVar5 != 0) {
          uVar10 = 1;
        }
      }
    }
    else if (param_2 == 6) {
      if ((*(uint *)(lVar11 + 0x2384) & 0x100000) == 0) {
        if ((*(uint *)(lVar11 + 0x2388) & 1) != 0) {
          if (param_1 == *(longlong *)(lVar11 + 0xe60)) {
            FUN_140052368(lVar11,0xe);
LAB_140054e26:
            local_res8[0] = 1;
          }
          else {
            if (param_1 != *(longlong *)(lVar11 + 0xe58)) goto LAB_140054ecf;
            if (*(int *)(param_1 + 0x20) == 1) {
              FUN_140052368(lVar11,0x12);
              lVar11 = *(longlong *)(param_1 + 0x28);
            }
            FUN_140052368(lVar11,0x14);
            if ((*(int *)(*(longlong *)(param_1 + 0x28) + 0x26b4) != 0x85) &&
               (*(short *)(*(longlong *)(param_1 + 0x28) + 0x26a8) != 0x1b9b)) goto LAB_140054e26;
            local_res8[0] = 0;
            bVar6 = true;
          }
          uVar17 = 1;
          uVar10 = 1;
        }
      }
      else {
        bVar18 = param_1 == *(longlong *)(lVar11 + 0xe60);
        if (bVar18) {
          FUN_140052368(lVar11,0xe);
          uVar10 = 1;
          local_res8[0] = 1;
        }
        local_4c = (uint)bVar18;
      }
    }
    else {
      if (param_2 != 7) {
        if (param_2 == 0xf) {
          uVar16 = 8;
          goto LAB_140054d0e;
        }
        if (param_2 != 0x20) goto LAB_140054ecf;
        goto LAB_140054eaa;
      }
      if ((*(uint *)(lVar11 + 0x2384) & 0x400) != 0) {
        bVar6 = true;
        if (param_1 == *(longlong *)(lVar11 + 0xe40)) {
          FUN_140052368(lVar11,2);
          *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 0x48) = 1;
          lVar11 = *(longlong *)(param_1 + 0x28);
        }
        uVar10 = uVar13;
        if (param_1 == *(longlong *)(lVar11 + 0xe50)) {
          FUN_140052368(lVar11,0x11);
          local_48 = 1;
          uVar10 = 1;
        }
      }
    }
  }
  else if ((param_2 == 0x22) || (param_2 == 0x23)) {
LAB_140054e99:
    local_58 = (uint)(param_2 == 0x105);
LAB_140054eaa:
    local_54[0] = 1;
    local_54[1] = 0;
    if (((*(ushort *)(param_1 + 0x4e) >> 0xc & 1) != 0) &&
       (uVar10 = uVar13, *(longlong *)(lVar11 + 0xe10) == param_1)) {
      uVar16 = 0;
    }
    if (*(int *)(lVar11 + 0x26b0) == 5) {
      uVar16 = 0;
    }
  }
  else if (param_2 == 0x24) {
    if ((*(uint *)(lVar11 + 0x2384) & 0x400) != 0) {
      uVar16 = 0xb;
    }
  }
  else {
    if ((param_2 == 0x32) || (param_2 == 0x33)) goto LAB_140054e99;
    if (param_2 == 0x100) {
      uVar10 = uVar13;
      if (((*(uint *)(lVar11 + 0x2384) & 0x80400) == 0x80400) &&
         (uVar10 = 1, *(int *)(param_1 + 0x10) == 0x38)) {
        uVar16 = 6;
      }
    }
    else if (param_2 == 0x103) {
      local_58 = 1;
LAB_140055169:
      local_54[0] = 1;
      local_54[1] = 0;
      if ((*(byte *)(param_1 + 0x4e) & 4) != 0) {
        if ((*(longlong *)(lVar11 + 0xe10) == param_1) &&
           (((uVar16 = 0, *(int *)(lVar11 + 0x26b0) == 0x2d ||
             (*(short *)(lVar11 + 0x26a8) == 0x1571)) && (*(longlong *)(lVar11 + 0xe18) != 0)))) {
          puVar1 = (ushort *)(*(longlong *)(lVar11 + 0xe18) + 0x4c);
          *puVar1 = *puVar1 & 0xfffd;
          FUN_14003ccf0(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0xe18) + 0x18));
        }
        uVar10 = 1;
      }
      lVar11 = *(longlong *)(param_1 + 0x28);
      uVar13 = 0;
      if (*(int *)(lVar11 + 0x26b0) != 5) {
        uVar13 = uVar16;
      }
      uVar16 = uVar13;
      if ((param_1 == *(longlong *)(lVar11 + 0xe18)) &&
         ((*(uint *)(lVar11 + 0x24c0) & 0x100000) != 0)) {
        uVar16 = 6;
        uVar10 = 1;
      }
      if (param_1 == *(longlong *)(lVar11 + 0xe50)) {
        FUN_140052368(lVar11,0x10);
        local_48 = 1;
      }
    }
    else if (param_2 == 0x104) {
      local_58 = 2;
LAB_140055096:
      if ((*(byte *)(param_1 + 0x4e) & 0x10) != 0) {
        if ((*(longlong *)(lVar11 + 0xe10) == param_1) &&
           (((uVar16 = uVar13, *(int *)(lVar11 + 0x26b0) == 0x2d ||
             (*(short *)(lVar11 + 0x26a8) == 0x1571)) && (*(longlong *)(lVar11 + 0xe18) != 0)))) {
          puVar1 = (ushort *)(*(longlong *)(lVar11 + 0xe18) + 0x4c);
          *puVar1 = *puVar1 & 0xfffd;
          FUN_14003ccf0(*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0xe18) + 0x18));
          lVar11 = *(longlong *)(param_1 + 0x28);
          uVar16 = 1;
        }
        uVar10 = 1;
        if (((*(uint *)(lVar11 + 0x2384) & 0x40000) != 0) &&
           ((((*(int *)(lVar11 + 0x26b4) - 0xc9U < 2 || (*(int *)(lVar11 + 0x26b4) == 0x85)) ||
             (*(short *)(lVar11 + 0x26a8) == 0x1b9b)) && ((*(uint *)(lVar11 + 0x2388) & 4) == 0))))
        {
          uVar16 = 2 - ((*(uint *)(lVar11 + 0x2394) & 0x100) != 0);
        }
      }
      if (*(int *)(lVar11 + 0x26b0) == 5) {
        uVar16 = 1;
      }
    }
    else if (param_2 == 0x105) goto LAB_140054e99;
  }
LAB_140054ecf:
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
    FUN_14003a624(*(undefined8 *)(param_1 + 0x18),uVar16);
    FUN_140056d10(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0xb,&DAT_140061398,
                  "CWidget::AssignDeviceType");
  }
  bVar18 = true;
  if (uVar10 == 0) {
    if (((*(int *)(*(longlong *)(param_1 + 0x28) + 0x26b0) == 6) ||
        ((*(uint *)(*(longlong *)(param_1 + 0x28) + 0x2380) >> 0x11 & 1) != 0)) &&
       (*(int *)(*(longlong *)(param_1 + 0x18) + 0x2d8) == 0)) {
      FUN_14003ccf0(*(longlong *)(param_1 + 0x18));
    }
    goto LAB_1400558b4;
  }
  if (param_2 != 0x100) {
    *(uint *)(param_1 + 0x20) = param_2;
    FUN_140055f90(param_1,(uint *)(param_1 + 0x3c),param_2);
    *(ushort *)(param_1 + 0x4c) =
         *(ushort *)(param_1 + 0x4c) ^
         ((ushort)((uint)*(undefined4 *)(param_1 + 0x3c) >> 0x10) & 0xfff0 ^
         *(ushort *)(param_1 + 0x4c)) & 0xf0;
    FUN_14004cc3c(*(longlong **)(*(longlong *)(param_1 + 0x28) + 0x150),*(uint *)(param_1 + 0x10),
                  *(undefined4 *)(param_1 + 0x20));
    if (*(int *)(*(short **)(param_1 + 0x18) + 0x196) == 0) {
      FUN_14003c4a8(*(short **)(param_1 + 0x18),7,(short *)&local_58,4);
      FUN_14003c4a8(*(short **)(param_1 + 0x18),0,local_54,4);
    }
  }
  lVar11 = *(longlong *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 8) = 0;
  lVar4 = *(longlong *)(lVar11 + 0xb20);
  if (lVar4 != 0) {
    if (*(longlong *)(lVar11 + 0xe10) == param_1) {
      (*(code *)PTR__guard_dispatch_icall_14005f458)(lVar4,param_2);
      lVar11 = *(longlong *)(param_1 + 0x28);
      if (*(int *)(lVar11 + 0x26b4) == 0x92) {
        FUN_140055990(*(longlong *)(lVar11 + 0xe10));
        if ((*(byte *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0xe10) + 0x4c) & 2) != 0) {
          (*(code *)PTR__guard_dispatch_icall_14005f458)
                    (*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0xb20),param_1);
        }
      }
      else {
        (*(code *)PTR__guard_dispatch_icall_14005f458)(*(undefined8 *)(lVar11 + 0xb20),param_2);
      }
      (*(code *)PTR__guard_dispatch_icall_14005f458)
                (*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0xb20),param_2);
      if (((((*(uint *)(*(longlong *)(param_1 + 0x28) + 0x2374) & 1) != 0) ||
           (sVar2 = *(short *)(*(longlong *)(param_1 + 0x28) + 0xe68), sVar2 == 0x4040)) ||
          (sVar2 == 0x4042)) || ((sVar2 == 0x4050 || (sVar2 == 0x4080)))) {
        FUN_14003a6d8(*(short **)(param_1 + 0x18));
      }
    }
    else if (((*(int *)(lVar11 + 0x26b4) == 0x92) && (*(longlong *)(lVar11 + 0xe28) == param_1)) ||
            (((*(byte *)(param_1 + 0x4c) & 8) != 0 &&
             ((*(int *)(lVar11 + 0x26b0) != 5 || (*(int *)(lVar11 + 0x5c) != 0x22)))))) {
      (*(code *)PTR__guard_dispatch_icall_14005f458)(lVar4,param_1);
    }
  }
  iVar15 = local_res8[0];
  lVar11 = *(longlong *)(param_1 + 0x28);
  if (((*(uint *)(lVar11 + 0x2380) & 0x10000) == 0) ||
     (lVar4 = *(longlong *)(param_1 + 0x18), *(int *)(lVar4 + 0x32c) == 0)) {
    lVar4 = *(longlong *)(param_1 + 0x18);
    if ((*(int *)(lVar4 + 0x32c) == 0) || (uVar16 == *(uint *)(lVar4 + 0x2d8))) {
      iVar3 = *(int *)(lVar11 + 0x26b0);
      if (iVar3 == 5) {
        if (local_50 != 0) {
          FUN_14003c72c(lVar4);
          FUN_14003c95c(*(longlong *)(param_1 + 0x18),uVar16);
          FUN_14003a868(*(short **)(param_1 + 0x18));
          iVar15 = local_res8[0];
        }
      }
      else if (iVar3 == 0x2d) {
        if (((*(uint *)(lVar4 + 0x2c8) == (uint)*(byte *)(lVar11 + 0xcb0)) &&
            (*(uint *)(lVar4 + 0x2d8) != uVar16)) && (uVar16 < 2)) {
          FUN_14003c72c(lVar4);
          FUN_14003c95c(*(longlong *)(param_1 + 0x18),uVar16);
          FUN_14003a868(*(short **)(param_1 + 0x18));
          iVar15 = local_res8[0];
        }
      }
      else if ((iVar3 == 0x42) || (iVar3 == 0xa3)) {
        if (*(int *)(lVar4 + 0x2c8) == 1) {
          if (bVar6) {
            FUN_14003c72c(lVar4);
            iVar15 = local_res8[0];
          }
          else if (*(int *)(lVar4 + 0x328) == 0) {
            FUN_14003c95c(lVar4,uVar16);
            FUN_14003a868(*(short **)(param_1 + 0x18));
            iVar15 = local_res8[0];
          }
        }
      }
      else if (iVar3 == 0xb1) {
        if ((*(uint *)(lVar4 + 0x2c8) == (uint)*(byte *)(lVar11 + 0xcb4)) ||
           ((((*(uint *)(lVar11 + 0x2384) >> 0x14 & 1) != 0 &&
             ((*(uint *)(lVar11 + 0x2384) >> 0x13 & 1) != 0)) &&
            (*(uint *)(lVar4 + 0x2c8) == (uint)*(byte *)(lVar11 + 0xcb3))))) {
          if (local_res8[0] == 0) {
            if (bVar6) {
              FUN_14003c72c(lVar4);
            }
            else if (*(int *)(lVar4 + 0x328) == 0) {
              FUN_14003c95c(lVar4,uVar16);
              FUN_14003a868(*(short **)(param_1 + 0x18));
            }
          }
          if ((bVar7) &&
             (piVar12 = (int *)FUN_14002821c(*(longlong *)(param_1 + 0x28),0x3b),
             piVar12 != (int *)0x0)) {
            FUN_140055b90(piVar12);
          }
          if (local_4c != 0) {
            piVar12 = (int *)FUN_14002821c(*(longlong *)(param_1 + 0x28),0x3a);
LAB_1400555d7:
            if (piVar12 != (int *)0x0) {
              FUN_140055b90(piVar12);
            }
          }
        }
      }
      else if (((*(uint *)(lVar11 + 0x2388) & 1) != 0) &&
              (((uVar13 = *(uint *)(lVar4 + 0x2c8), uVar13 == *(byte *)(lVar11 + 0xcb3) ||
                (uVar13 == *(byte *)(lVar11 + 0xcb1))) || (uVar13 == *(byte *)(lVar11 + 0xcb4))))) {
        if (local_res8[0] == 0) {
          if (bVar6) {
            FUN_14003c72c(lVar4);
          }
          else if (*(int *)(lVar4 + 0x328) == 0) {
            FUN_14003c95c(lVar4,uVar16);
            FUN_14003a868(*(short **)(param_1 + 0x18));
          }
        }
        if ((bVar8) &&
           (piVar12 = (int *)FUN_14002821c(*(longlong *)(param_1 + 0x28),0x3b),
           piVar12 != (int *)0x0)) {
          FUN_140055b90(piVar12);
        }
        if (uVar17 != 0) {
          piVar12 = (int *)FUN_14002821c(*(longlong *)(param_1 + 0x28),0x3a);
          goto LAB_1400555d7;
        }
      }
      lVar11 = *(longlong *)(param_1 + 0x28);
      if ((((*(uint *)(lVar11 + 0x2384) & 0x40000) != 0) &&
          (*(int *)(lVar11 + 0x26b4) == 0xc9 || *(int *)(lVar11 + 0x26b4) == 0xca)) &&
         ((lVar4 = *(longlong *)(param_1 + 0x18),
          *(uint *)(lVar4 + 0x2c8) == (uint)*(byte *)(lVar11 + 0xcb2) &&
          (*(uint *)(lVar4 + 0x2d8) != uVar16)))) {
        FUN_14003c72c(lVar4);
        FUN_14003c95c(*(longlong *)(param_1 + 0x18),uVar16);
        FUN_14003a868(*(short **)(param_1 + 0x18));
        lVar11 = FUN_14002821c(*(longlong *)(param_1 + 0x28),0x37);
        if (lVar11 != 0) {
          if ((*(byte *)(lVar11 + 0x4c) & 2) == 0) {
            local_res8[0] = -1;
            FUN_14003c4e0(*(short **)(param_1 + 0x18),0xe,(short *)local_res8,4);
          }
          else {
            FUN_14003a308(*(short **)(param_1 + 0x18),
                          *(uint *)(*(longlong *)(param_1 + 0x28) + 0x2384) >> 0x19 & 1,0);
          }
        }
      }
      if ((local_48 != 0) &&
         (lVar11 = *(longlong *)(param_1 + 0x18),
         *(uint *)(lVar11 + 0x2c8) == (uint)*(byte *)(*(longlong *)(param_1 + 0x28) + 0xcb0))) {
        if (iVar15 == 0) {
          if (bVar6) {
            FUN_14003c72c(lVar11);
          }
          else if (*(int *)(lVar11 + 0x328) == 0) {
            FUN_14003c95c(lVar11,uVar16);
            FUN_14003a868(*(short **)(param_1 + 0x18));
          }
        }
        piVar12 = (int *)FUN_14002821c(*(longlong *)(param_1 + 0x28),0x3c);
        if (piVar12 != (int *)0x0) {
          FUN_140055b90(piVar12);
        }
      }
      FUN_14003ccf0(*(longlong *)(param_1 + 0x18));
    }
    else {
      FUN_14003c72c(lVar4);
      if (!bVar6) {
        FUN_14003c95c(*(longlong *)(param_1 + 0x18),uVar16);
        FUN_14003a868(*(short **)(param_1 + 0x18));
        if ((*(int *)(*(longlong *)(param_1 + 0x28) + 0x26b4) == 0x85) ||
           (*(short *)(*(longlong *)(param_1 + 0x28) + 0x26a8) == 0x1b9b)) {
          FUN_1400395d8(*(short **)(param_1 + 0x18));
        }
      }
    }
  }
  else if (param_2 == 0x100) {
    FUN_14003c72c(lVar4);
  }
  else {
    FUN_14003c95c(lVar4,uVar16);
    FUN_14003a868(*(short **)(param_1 + 0x18));
  }
  lVar11 = *(longlong *)(param_1 + 0x28);
  if (param_1 == *(longlong *)(lVar11 + 0xe18)) {
    puVar1 = (ushort *)(*(longlong *)(lVar11 + 0xe18) + 0x4c);
    *puVar1 = *puVar1 & 0xfffd;
    lVar11 = *(longlong *)(param_1 + 0x28);
  }
  if ((((((param_2 == 0x22) || (param_2 == 0x23)) || (param_2 == 0x32)) || (param_2 == 0x33)) &&
      (((*(ushort *)(param_1 + 0x4e) >> 0xc & 1) != 0 && (*(longlong *)(lVar11 + 0xe18) != 0)))) &&
     (((-1 < (char)*(undefined4 *)(lVar11 + 0x2378) ||
       ((lVar4 = *(longlong *)(lVar11 + 0xe10), lVar4 == 0 || ((*(byte *)(lVar4 + 0x4c) & 2) == 0)))
       ) || (bVar18 = false, *(int *)(lVar4 + 0xcc) - 1U < 2)))) {
    uVar13 = 1;
    puVar1 = (ushort *)(*(longlong *)(lVar11 + 0xe18) + 0x4c);
    *puVar1 = *puVar1 | 2;
    if ((*(uint *)(*(longlong *)(param_1 + 0x28) + 0x2380) >> 0x19 & 1) != 0) {
      uVar13 = 0x21;
    }
    FUN_14005470c(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0xe18),uVar13);
    bVar18 = true;
  }
  lVar11 = *(longlong *)(param_1 + 0x28);
  if (((param_1 == *(longlong *)(lVar11 + 0xe10)) && (*(longlong *)(lVar11 + 0xe18) != 0)) &&
     (bVar18)) {
    if (((*(uint *)(lVar11 + 0x2374) & 2) != 0) && (param_2 < 2)) {
      puVar1 = (ushort *)(*(longlong *)(lVar11 + 0xe18) + 0x4c);
      *puVar1 = *puVar1 | 2;
      lVar11 = *(longlong *)(param_1 + 0x28);
    }
    FUN_14005470c(*(longlong *)(lVar11 + 0xe18),param_2);
    lVar11 = *(longlong *)(param_1 + 0x28);
  }
  if (*(longlong *)(lVar11 + 0xb28) != 0) {
    FUN_140020e64(*(longlong *)(lVar11 + 0xb28),0x16);
  }
LAB_1400558b4:
  puVar9 = PTR_LOOP_140067000;
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 0x20) != 0)) {
    FUN_1400560ec(param_1,*(uint *)(param_1 + 0x20));
    FUN_140056bd0(*(undefined8 *)(puVar9 + 0x18),0xc,&DAT_140061398,"CWidget::AssignDeviceType");
  }
  lVar11 = *(longlong *)(param_1 + 0x28);
  if (((((char)*(undefined4 *)(lVar11 + 0x2378) < '\0') && (param_2 == 0x22)) &&
      (lVar4 = *(longlong *)(lVar11 + 0xe10), lVar4 != 0)) &&
     ((param_1 == lVar4 && ((*(byte *)(lVar4 + 0x4c) & 10) == 10)))) {
    *(undefined4 *)(lVar11 + 0x4c) = 1;
  }
  return unaff_EBP;
}

