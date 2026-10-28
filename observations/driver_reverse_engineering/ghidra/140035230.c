
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_140035230(longlong param_1,longlong param_2,uint *param_3)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  undefined2 uVar16;
  longlong *plVar17;
  ulonglong uVar18;
  uint *puVar19;
  int iVar20;
  uint uVar21;
  longlong lVar22;
  longlong lVar23;
  ulonglong uVar24;
  int *piVar25;
  uint uVar26;
  int iVar27;
  int iVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  bool bVar31;
  undefined1 auStackY_198 [32];
  undefined4 uVar32;
  uint local_160;
  ulonglong local_130;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = DAT_1400698c0 ^ (ulonglong)auStackY_198;
  uVar18 = 0;
  iVar20 = 0;
  if ((param_2 == 0) || (1 < *(int *)(param_2 + 0x10) - 0xeU)) {
    return 0xc000000d;
  }
  uVar24 = 0xc000000d;
  lVar23 = *(longlong *)(param_1 + 0xb8);
  uVar21 = *(uint *)(lVar23 + 8);
  uVar26 = *(uint *)(lVar23 + 0x10);
  if ((*(uint *)(param_2 + 0x14) & 0x203) == 0) {
    return 0xc000000d;
  }
  plVar17 = (longlong *)KsGetFilterFromIrp(param_1);
  uVar2 = *(uint *)(param_2 + 0x14);
  lVar22 = *(longlong *)(*plVar17 + 0x28);
  lVar3 = *(longlong *)(lVar22 + 0x88);
  lVar4 = *(longlong *)(lVar3 + 0x2d0);
  if ((uVar2 >> 9 & 1) != 0) {
    if (*(int *)(param_2 + 0x10) == 0xf) {
      uVar32 = 0x201;
    }
    else {
      uVar24 = 0xc000000d;
      if (*(int *)(param_2 + 0x10) != 0xe) goto LAB_14003575f;
      uVar32 = 0x202;
    }
    uVar18 = FUN_14004d454(lVar3,param_1,param_2,param_3,uVar32,0xffff);
    return uVar18;
  }
  iVar28 = 0;
  if (((uVar2 & 2) != 0) && (*(int *)(param_2 + 0x10) == 0xe)) {
    if ((uVar26 < 0x20) || (*(uint *)(*plVar17 + 0x20) <= *(uint *)(param_2 + 0x18))) {
      *(undefined8 *)(param_1 + 0x38) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0xc000000d;
      return 0xc000000d;
    }
    iVar20 = *(int *)(lVar22 + 0x44 + (ulonglong)*(uint *)(param_2 + 0x18) * 0x90);
    *(undefined8 *)(param_1 + 0x38) = 0;
    if ((iVar20 - 1U & 0xfffffffd) != 0) {
      *(undefined4 *)(param_1 + 0x30) = 0xc00000bb;
      return 0xc00000bb;
    }
    uVar24 = 0xc0000272;
    if ((lVar3 == -0x350) || (param_3 == (uint *)0x0)) {
LAB_1400357e5:
      uVar24 = 0xc000000d;
      goto LAB_14003575f;
    }
    uVar21 = *param_3;
    if (uVar21 < 0x40) {
      uVar24 = 0xc0000023;
      goto LAB_14003575f;
    }
    if ((((*(longlong *)(param_3 + 4) != DAT_14005ffa0) ||
         (*(longlong *)(param_3 + 6) != DAT_14005ffa8)) ||
        (*(longlong *)(param_3 + 0xc) != DAT_14005ffc0)) ||
       (*(longlong *)(param_3 + 0xe) != DAT_14005ffc8)) goto LAB_14003575f;
    if ((*(int *)(lVar4 + 0x26b0) == 0x3b) || (*(int *)(lVar3 + 0x2d8) == 4)) {
      if (uVar21 == 0x40) {
        if ((((*(longlong *)(param_3 + 8) == DAT_14005ffb0) &&
             (*(longlong *)(param_3 + 10) == DAT_14005ffb8)) ||
            ((*(longlong *)(param_3 + 8) == DAT_140060f58 &&
             (*(longlong *)(param_3 + 10) == DAT_140060f60)))) ||
           ((*(longlong *)(param_3 + 8) == DAT_140060f68 &&
            (*(longlong *)(param_3 + 10) == DAT_140060f70)))) {
          uVar24 = 0;
        }
        else if ((*(longlong *)(param_3 + 8) == DAT_140060f78) &&
                (*(longlong *)(param_3 + 10) == DAT_140060f80)) {
          uVar24 = 0;
        }
        goto LAB_14003575f;
      }
    }
    else if ((*(longlong *)(param_3 + 8) != DAT_14005ffb0) ||
            (*(longlong *)(param_3 + 10) != DAT_14005ffb8)) goto LAB_14003575f;
    if (uVar21 < 0x52) goto LAB_1400357e5;
    if (*(int *)(lVar3 + 0x2d8) == 4) {
      if ((((*(longlong *)(param_3 + 8) != DAT_14005ffb0) ||
           (*(longlong *)(param_3 + 10) != DAT_14005ffb8)) &&
          ((*(longlong *)(param_3 + 8) != DAT_140060f58 ||
           (*(longlong *)(param_3 + 10) != DAT_140060f60)))) &&
         ((*(longlong *)(param_3 + 8) != DAT_140060f68 ||
          (*(longlong *)(param_3 + 10) != DAT_140060f70)))) {
        if (*(longlong *)(param_3 + 8) != DAT_140060f78) goto LAB_14003575f;
        bVar31 = *(longlong *)(param_3 + 10) == DAT_140060f80;
        goto LAB_14003556b;
      }
    }
    else {
      if (*(longlong *)(param_3 + 8) != DAT_14005ffb0) goto LAB_14003575f;
      bVar31 = *(longlong *)(param_3 + 10) == DAT_14005ffb8;
LAB_14003556b:
      if (!bVar31) goto LAB_14003575f;
    }
    if ((((*(uint *)(lVar4 + 0x2380) & 1) != 0) ||
        ((param_3[0x11] == 48000 && (*(short *)((longlong)param_3 + 0x4e) == 0x18)))) &&
       (*(uint *)(lVar3 + 0x360) != 0)) {
      uVar1 = *(ushort *)((longlong)param_3 + 0x4e);
      do {
        lVar23 = *(longlong *)(lVar3 + 0x368) + uVar18 * 0xac;
        uStack_d0 = *(undefined8 *)(lVar23 + 0x28);
        local_c8 = *(undefined8 *)(lVar23 + 0x30);
        uStack_c0 = *(undefined8 *)(lVar23 + 0x38);
        local_b8 = *(undefined8 *)(lVar23 + 0x40);
        uStack_b0 = *(undefined8 *)(lVar23 + 0x48);
        local_a8 = *(undefined8 *)(lVar23 + 0x50);
        uStack_a0 = *(undefined8 *)(lVar23 + 0x58);
        local_98 = *(undefined8 *)(lVar23 + 0x60);
        uStack_90 = *(undefined8 *)(lVar23 + 0x68);
        local_88 = *(undefined8 *)(lVar23 + 0x70);
        uStack_80 = *(undefined8 *)(lVar23 + 0x78);
        local_78 = *(undefined8 *)(lVar23 + 0x80);
        uStack_70 = *(undefined8 *)(lVar23 + 0x88);
        local_68 = *(undefined8 *)(lVar23 + 0x90);
        uStack_60 = *(undefined8 *)(lVar23 + 0x98);
        local_58 = *(undefined8 *)(lVar23 + 0xa0);
        local_50 = *(undefined4 *)(lVar23 + 0xa8);
        local_58._4_4_ = (uint)((ulonglong)*(undefined8 *)(lVar23 + 0xa0) >> 0x20);
        if (uVar1 == local_58._4_4_) {
          uVar26 = (uint)((ulonglong)*(undefined8 *)(lVar23 + 0x10) >> 0x20);
          if (*(ushort *)((longlong)param_3 + 0x42) == uVar26) {
            local_d8._0_4_ = (int)*(undefined8 *)(lVar23 + 0x20);
            iVar20 = 0;
            if (0 < (int)local_d8) {
              puVar19 = (uint *)((longlong)&local_d8 + 4);
              do {
                if (param_3[0x11] == *puVar19) {
                  if (((((*(uint *)(lVar4 + 0x2384) >> 0x12 & 1) != 0) &&
                       ((*(uint *)(lVar4 + 0x2394) & 0x100) != 0)) &&
                      ((*(int *)(lVar4 + 0x26b4) - 0xc9U < 2 ||
                       ((*(int *)(lVar4 + 0x26b4) == 0x85 || (*(short *)(lVar4 + 0x26a8) == 0x1b9b))
                       )))) && (((*(uint *)(lVar4 + 0x2388) & 4) == 0 && (6 < (int)uVar26))))
                  goto LAB_14003575f;
                  uVar24 = 0;
                  if (((*(int *)(lVar3 + 0x32c) != 0) && (*(int *)(lVar3 + 0x380) == 4)) &&
                     (*(ushort *)((longlong)param_3 + 0x42) == 2)) {
                    uVar24 = 0xc0000272;
                  }
                  if ((((*(longlong *)(param_3 + 8) != DAT_14005ffb0) ||
                       (*(longlong *)(param_3 + 10) != DAT_14005ffb8)) ||
                      ((uVar21 < 0x68 ||
                       ((*(ushort *)((longlong)param_3 + 0x52) == 0 ||
                        (*(ushort *)((longlong)param_3 + 0x52) <= uVar1)))))) &&
                     ((*(int *)(lVar3 + 0x2d8) == 4 ||
                      ((((short)param_3[0x14] != 0x16 ||
                        (*(ushort *)((longlong)param_3 + 0x52) == 0)) ||
                       (*(ushort *)((longlong)param_3 + 0x52) == uVar1)))))) {
                    if ((((int)uVar24 < 0) || ((uVar21 < 0x68 && ((short)param_3[0x14] != 0x16))))
                       || ((*(uint *)(lVar4 + 0x2384) >> 10 & 1) == 0)) goto LAB_14003575f;
                    if (((*(longlong *)(param_3 + 8) != DAT_14005ffb0) ||
                        (*(longlong *)(param_3 + 10) != DAT_14005ffb8)) ||
                       ((*(ushort *)((longlong)param_3 + 0x52) == 0 ||
                        (uVar1 == *(ushort *)((longlong)param_3 + 0x52))))) {
                      if (*(short *)((longlong)param_3 + 0x42) == 4) {
                        bVar31 = param_3[0x15] == 0x33;
                      }
                      else {
                        if (*(short *)((longlong)param_3 + 0x42) != 6) goto LAB_14003575f;
                        bVar31 = param_3[0x15] == 0x3f;
                      }
                      if (!bVar31) {
                        uVar24 = 0xc0000272;
                      }
                      goto LAB_14003575f;
                    }
                  }
                  uVar24 = 0xc0000272;
                  goto LAB_14003575f;
                }
                iVar20 = iVar20 + 1;
                puVar19 = puVar19 + 1;
              } while (iVar20 < (int)local_d8);
            }
          }
        }
        uVar26 = (int)uVar18 + 1;
        uVar18 = (ulonglong)uVar26;
      } while (uVar26 < *(uint *)(lVar3 + 0x360));
    }
    goto LAB_14003575f;
  }
  if ((uVar2 & 1) == 0) goto LAB_14003575f;
  if ((*(uint *)(lVar4 + 0x2384) & 0x400) == 0) {
LAB_1400358c5:
    if (*(int *)(lVar4 + 0x26b0) != 0x4a) {
      local_160 = 0;
      bVar31 = false;
      bVar6 = false;
      bVar8 = false;
      bVar7 = false;
      bVar9 = false;
      bVar11 = false;
      bVar12 = false;
      bVar13 = false;
      bVar14 = false;
      bVar15 = false;
      iVar27 = iVar28;
      if ((lVar3 != -0x350) &&
         (local_130 = (ulonglong)*(uint *)(lVar3 + 0x360), iVar27 = iVar20,
         *(uint *)(lVar3 + 0x360) != 0)) {
        lVar22 = *(longlong *)(lVar3 + 0x368);
        bVar10 = false;
        uVar24 = uVar18;
        uVar30 = uVar18;
        do {
          local_d8 = *(ulonglong *)(lVar22 + 0x20);
          uStack_d0 = *(undefined8 *)(lVar22 + 0x28);
          local_c8 = *(undefined8 *)(lVar22 + 0x30);
          uStack_c0 = *(undefined8 *)(lVar22 + 0x38);
          local_b8 = *(undefined8 *)(lVar22 + 0x40);
          uStack_b0 = *(undefined8 *)(lVar22 + 0x48);
          local_a8 = *(undefined8 *)(lVar22 + 0x50);
          uStack_a0 = *(undefined8 *)(lVar22 + 0x58);
          local_98 = *(undefined8 *)(lVar22 + 0x60);
          uStack_90 = *(undefined8 *)(lVar22 + 0x68);
          local_88 = *(undefined8 *)(lVar22 + 0x70);
          uStack_80 = *(undefined8 *)(lVar22 + 0x78);
          local_78 = *(undefined8 *)(lVar22 + 0x80);
          uStack_70 = *(undefined8 *)(lVar22 + 0x88);
          local_68 = *(undefined8 *)(lVar22 + 0x90);
          uStack_60 = *(undefined8 *)(lVar22 + 0x98);
          local_58 = *(undefined8 *)(lVar22 + 0xa0);
          uVar5 = local_58;
          local_50 = *(undefined4 *)(lVar22 + 0xa8);
          if (0 < (int)local_d8) {
            local_58._4_4_ = (uint)((ulonglong)*(undefined8 *)(lVar22 + 0xa0) >> 0x20);
            piVar25 = (int *)((longlong)&local_d8 + 4);
            uVar29 = local_d8 & 0xffffffff;
            bVar6 = bVar7;
            bVar9 = bVar10;
            do {
              iVar20 = *piVar25;
              if (iVar20 == 0xac44) {
                if (local_58._4_4_ == 0x10) {
                  uVar30 = 1;
                }
                else if (local_58._4_4_ == 0x18) {
                  uVar18 = 1;
                  local_160 = 1;
                  goto LAB_140035adf;
                }
LAB_140035ada:
                uVar18 = (ulonglong)local_160;
              }
              else {
                if (iVar20 != 48000) {
                  if (iVar20 == 96000) {
                    if (local_58._4_4_ != 0x10) {
                      uVar18 = (ulonglong)local_160;
                      if (local_58._4_4_ == 0x18) {
                        bVar8 = true;
                      }
                      goto LAB_140035adf;
                    }
                    bVar6 = true;
                  }
                  else if (iVar20 == 0x2ee00) {
                    if (local_58._4_4_ == 0x10) {
                      bVar9 = true;
                    }
                    else {
                      if (local_58._4_4_ != 0x18) {
                        uVar18 = (ulonglong)local_160;
                        if (local_58._4_4_ == 0x20) {
                          bVar12 = true;
                        }
                        goto LAB_140035adf;
                      }
                      bVar11 = true;
                    }
                  }
                  else if (iVar20 == 0x5dc00) {
                    if (local_58._4_4_ == 0x10) {
                      bVar13 = true;
                    }
                    else {
                      if (local_58._4_4_ != 0x18) {
                        uVar18 = (ulonglong)local_160;
                        if (local_58._4_4_ == 0x20) {
                          bVar15 = true;
                        }
                        goto LAB_140035adf;
                      }
                      bVar14 = true;
                    }
                  }
                  goto LAB_140035ada;
                }
                if (local_58._4_4_ == 0x10) {
                  uVar24 = 1;
                  goto LAB_140035ada;
                }
                uVar18 = (ulonglong)local_160;
                if (local_58._4_4_ == 0x18) {
                  bVar31 = true;
                }
              }
LAB_140035adf:
              piVar25 = piVar25 + 1;
              uVar29 = uVar29 - 1;
              bVar7 = bVar6;
              bVar10 = bVar9;
            } while (uVar29 != 0);
          }
          iVar20 = (int)uVar24;
          iVar27 = (int)uVar18;
          iVar28 = (int)uVar30;
          lVar22 = lVar22 + 0xac;
          local_130 = local_130 - 1;
          local_58 = uVar5;
        } while (local_130 != 0);
      }
      if (*(int *)(param_2 + 0x10) == 0xf) {
        if (uVar26 < 0x50) goto LAB_140035b56;
        if (uVar21 < 0x98) {
          *(undefined8 *)(param_1 + 0x38) = 0x98;
LAB_140035b76:
          uVar24 = (ulonglong)((-(uint)(uVar21 != 0) & 0x4000001e) + 0x80000005);
          goto LAB_14003575f;
        }
        uVar24 = 0xc000000d;
        if (((((param_3 == (uint *)0x0) ||
              (lVar23 = *(longlong *)(lVar23 + 0x20), *(int *)(lVar23 + 0x24) != 1)) ||
             (*(longlong *)(lVar23 + 0x30) != DAT_140060000)) ||
            (*(longlong *)(lVar23 + 0x38) != DAT_140060008)) ||
           (((*(longlong *)(lVar23 + 0x40) != DAT_14005ff90 ||
             (*(longlong *)(lVar23 + 0x48) != DAT_14005ff98)) &&
            ((*(longlong *)(lVar23 + 0x40) != DAT_14005ff80 ||
             (*(longlong *)(lVar23 + 0x48) != DAT_14005ff88)))))) goto LAB_14003575f;
        memset(param_3,0,0x98);
        *param_3 = 0x68;
        param_3[1] = 2;
        lVar22 = DAT_14005ffa8;
        *(longlong *)(param_3 + 4) = DAT_14005ffa0;
        *(longlong *)(param_3 + 6) = lVar22;
        lVar22 = DAT_14005ffb8;
        *(longlong *)(param_3 + 8) = DAT_14005ffb0;
        *(longlong *)(param_3 + 10) = lVar22;
        lVar22 = DAT_14005ffc8;
        *(longlong *)(param_3 + 0xc) = DAT_14005ffc0;
        *(longlong *)(param_3 + 0xe) = lVar22;
        param_3[0x10] = 0x2fffe;
        if (bVar31) {
          param_3[0x11] = 48000;
          goto LAB_140035d0a;
        }
        if (iVar20 != 0) {
          param_3[0x11] = 48000;
          goto LAB_140035d34;
        }
        if (local_160 != 0) {
          param_3[0x11] = 0xac44;
          goto LAB_140035d0a;
        }
        if (iVar28 == 0) {
          if (bVar6) {
            param_3[0x11] = 96000;
            goto LAB_140035d34;
          }
          if (bVar8) {
            param_3[0x11] = 96000;
            goto LAB_140035d0a;
          }
          if (bVar9) {
            param_3[0x11] = 0x2ee00;
            goto LAB_140035d34;
          }
          if (!bVar11) {
            if (!bVar12) {
              if (bVar13) {
                param_3[0x11] = 0x5dc00;
                goto LAB_140035d34;
              }
              if (bVar14) {
                param_3[0x11] = 0x5dc00;
              }
              else {
                if (bVar15) {
                  param_3[0x11] = 0x5dc00;
                  goto LAB_140035ce4;
                }
                if ((*(int *)(lVar4 + 0x26b0) - 1U & 0xfffffffd) == 0) goto LAB_140035d34;
              }
              goto LAB_140035d0a;
            }
            param_3[0x11] = 0x2ee00;
LAB_140035ce4:
            uVar16 = 0x20;
            uVar21 = 8;
            goto LAB_140035d3c;
          }
          param_3[0x11] = 0x2ee00;
LAB_140035d0a:
          *(undefined2 *)((longlong)param_3 + 0x4e) = 0x18;
          uVar21 = 6;
        }
        else {
          param_3[0x11] = 0xac44;
LAB_140035d34:
          uVar21 = 4;
          uVar16 = 0x10;
LAB_140035d3c:
          *(undefined2 *)((longlong)param_3 + 0x4e) = uVar16;
        }
        *(short *)(param_3 + 0x13) = (short)uVar21;
        param_3[2] = uVar21;
        param_3[0x12] = (uint)(ushort)param_3[0x13] * param_3[0x11];
        *(undefined2 *)(param_3 + 0x14) = 0x16;
        lVar3 = DAT_14005ffb8;
        lVar22 = DAT_14005ffb0;
        *(undefined2 *)((longlong)param_3 + 0x52) = *(undefined2 *)((longlong)param_3 + 0x4e);
        *(longlong *)(param_3 + 0x16) = lVar22;
        *(longlong *)(param_3 + 0x18) = lVar3;
        param_3[0x15] = 3;
        param_3[0x1b] = 1;
        param_3[0x1a] = 0x30;
        uVar5 = *(undefined8 *)(lVar23 + 0x30);
        *(undefined8 *)(param_3 + 0x1c) = *(undefined8 *)(lVar23 + 0x28);
        *(undefined8 *)(param_3 + 0x1e) = uVar5;
        uVar5 = *(undefined8 *)(lVar23 + 0x40);
        *(undefined8 *)(param_3 + 0x20) = *(undefined8 *)(lVar23 + 0x38);
        *(undefined8 *)(param_3 + 0x22) = uVar5;
        *(undefined8 *)(param_3 + 0x24) = *(undefined8 *)(lVar23 + 0x48);
        *(undefined8 *)(param_1 + 0x38) = 0x98;
      }
      else {
        uVar24 = 0xc000000d;
        if (*(int *)(param_2 + 0x10) != 0xe) goto LAB_14003575f;
        if (uVar26 < 0x20) {
LAB_140035b56:
          uVar24 = 0xc000000d;
          goto LAB_14003575f;
        }
        if (uVar21 < 0x68) {
          *(undefined8 *)(param_1 + 0x38) = 0x68;
          goto LAB_140035b76;
        }
        if (param_3 == (uint *)0x0) goto LAB_140035b56;
        param_3[0] = 0x68;
        param_3[1] = 0;
        param_3[3] = 0;
        lVar23 = DAT_14005ffa8;
        *(longlong *)(param_3 + 4) = DAT_14005ffa0;
        *(longlong *)(param_3 + 6) = lVar23;
        lVar23 = DAT_14005ffb8;
        *(longlong *)(param_3 + 8) = DAT_14005ffb0;
        *(longlong *)(param_3 + 10) = lVar23;
        lVar23 = DAT_14005ffc8;
        *(longlong *)(param_3 + 0xc) = DAT_14005ffc0;
        *(longlong *)(param_3 + 0xe) = lVar23;
        param_3[0x10] = 0x2fffe;
        param_3[0x15] = 3;
        if (bVar31) {
          param_3[0x11] = 48000;
          goto LAB_140035ede;
        }
        if (iVar20 != 0) {
          param_3[0x11] = 48000;
          goto LAB_140035f12;
        }
        if (iVar27 != 0) {
          param_3[0x11] = 0xac44;
          goto LAB_140035ede;
        }
        if (iVar28 == 0) {
          if (bVar7) {
            param_3[0x11] = 96000;
            goto LAB_140035f12;
          }
          if (bVar8) {
            param_3[0x11] = 96000;
            goto LAB_140035ede;
          }
          if (bVar9) {
            param_3[0x11] = 0x2ee00;
            goto LAB_140035f12;
          }
          if (bVar11) {
            param_3[0x11] = 0x2ee00;
LAB_140035ede:
            *(undefined2 *)((longlong)param_3 + 0x4e) = 0x18;
            uVar21 = 6;
          }
          else {
            if (!bVar12) {
              if (bVar13) {
                param_3[0x11] = 0x5dc00;
                goto LAB_140035f12;
              }
              if (bVar14) {
                param_3[0x11] = 0x5dc00;
              }
              else {
                if (bVar15) {
                  param_3[0x11] = 0x5dc00;
                  goto LAB_140035ef6;
                }
                if ((*(int *)(lVar4 + 0x26b0) - 1U & 0xfffffffd) == 0) goto LAB_140035f12;
              }
              goto LAB_140035ede;
            }
            param_3[0x11] = 0x2ee00;
LAB_140035ef6:
            *(undefined2 *)((longlong)param_3 + 0x4e) = 0x20;
            uVar21 = 8;
          }
        }
        else {
          param_3[0x11] = 0xac44;
LAB_140035f12:
          uVar21 = 4;
          *(undefined2 *)((longlong)param_3 + 0x4e) = 0x10;
        }
        *(short *)(param_3 + 0x13) = (short)uVar21;
        param_3[2] = uVar21;
        param_3[0x12] = (uint)(ushort)param_3[0x13] * param_3[0x11];
        *(undefined2 *)(param_3 + 0x14) = 0x16;
        lVar22 = DAT_14005ffb8;
        lVar23 = DAT_14005ffb0;
        *(undefined2 *)((longlong)param_3 + 0x52) = *(undefined2 *)((longlong)param_3 + 0x4e);
        *(longlong *)(param_3 + 0x16) = lVar23;
        *(longlong *)(param_3 + 0x18) = lVar22;
        *(undefined8 *)(param_1 + 0x38) = 0x68;
      }
      uVar24 = 0;
      goto LAB_14003575f;
    }
  }
  else {
    iVar27 = *(int *)(lVar4 + 0x26b4);
    if ((((((iVar27 - 0x4bU < 0x31) &&
           ((0x1400000000003U >> ((ulonglong)(iVar27 - 0x4bU) & 0x3f) & 1) != 0)) &&
          (*(int *)(lVar3 + 0x2d8) == 1)) ||
         ((iVar27 - 0x5aU < 0x38 &&
          ((0xffec00007fffffU >> ((ulonglong)(iVar27 - 0x5aU) & 0x3f) & 1) != 0)))) ||
        ((iVar27 - 0x1bU < 0x3d &&
         ((0x1ffc000000000005U >> ((ulonglong)(iVar27 - 0x1bU) & 0x3f) & 1) != 0)))) ||
       (((*(int *)(lVar4 + 0x26b0) == 0xb1 && (*(short *)(lVar4 + 0x26aa) == 0xdb0)) &&
        (*(uint *)(lVar3 + 0x2d8) < 2)))) goto LAB_1400358c5;
  }
  uVar24 = 0xc00000bb;
LAB_14003575f:
  *(int *)(param_1 + 0x30) = (int)uVar24;
  return uVar24;
}

