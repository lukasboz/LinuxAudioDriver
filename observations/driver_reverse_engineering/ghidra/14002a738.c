
int FUN_14002a738(longlong param_1,longlong param_2)

{
  ushort *puVar1;
  uint *puVar2;
  short *psVar3;
  byte *pbVar4;
  longlong lVar5;
  longlong lVar6;
  ushort uVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  longlong lVar13;
  byte *pbVar14;
  longlong *plVar15;
  longlong *plVar16;
  undefined4 *puVar17;
  undefined6 extraout_var;
  undefined8 uVar18;
  undefined4 *puVar19;
  short sVar20;
  uint uVar21;
  byte *pbVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  longlong *plVar25;
  longlong lVar26;
  bool bVar27;
  uint local_res8;
  uint local_58;
  longlong local_50 [3];
  
  plVar15 = (longlong *)(param_1 + 0x2348);
  *(undefined4 *)(param_1 + 0x50) = 1;
  *plVar15 = *(longlong *)(param_2 + 0x20);
  iVar9 = FUN_140028a80(param_1);
  *(undefined2 *)(param_1 + 0x2352) = *(undefined2 *)(param_1 + 0x26a8);
  *(undefined2 *)(param_1 + 0x2350) = *(undefined2 *)(param_1 + 0x26aa);
  FUN_140025538(param_1);
  plVar25 = (longlong *)0x0;
  if (*(longlong *)(param_1 + 0x2360) != 0) {
    puVar2 = (uint *)(param_1 + 0x2358);
    uVar11 = FUN_14002db9c(plVar15,0,L"DriverInstallPath",puVar2,(undefined8 *)0x0,0,2);
    if ((int)uVar11 == -0x7ffffffb) {
      puVar12 = (undefined8 *)ExAllocatePoolWithTag(DAT_140075ba0,*puVar2,0x44494e50);
      *(undefined8 **)(param_1 + 0x2360) = puVar12;
      uVar11 = FUN_14002db9c(plVar15,0,L"DriverInstallPath",puVar2,puVar12,0,2);
      if (-1 < (int)uVar11) {
        *(undefined4 *)(param_1 + 0x2368) = 1;
      }
    }
  }
  if (-1 < iVar9) {
    FUN_14004ef6c(param_1);
    iVar9 = FUN_1400282a4(param_1);
    if (-1 < iVar9) {
      FUN_14004b200(param_1);
    }
  }
  lVar13 = *(longlong *)(param_1 + 0x2708);
  if (lVar13 != 0) {
    lVar13 = USBD_ParseConfigurationDescriptorEx(lVar13,lVar13,0xffffffff,0xffffffff,1,1,0xffffffff)
    ;
    if (lVar13 != 0) {
      *(undefined1 *)(param_1 + 0x26fc) = *(undefined1 *)(lVar13 + 7);
    }
    pbVar22 = *(byte **)(param_1 + 0x2708);
    if (pbVar22 != (byte *)0x0) {
      pbVar4 = pbVar22 + (ulonglong)*(ushort *)(pbVar22 + 2) * 9;
      do {
        pbVar14 = (byte *)USBD_ParseDescriptors
                                    (*(longlong *)(param_1 + 0x2708),
                                     *(undefined2 *)(*(longlong *)(param_1 + 0x2708) + 2),pbVar22,
                                     0x24);
        if ((pbVar14 == (byte *)0x0) || (pbVar4 < pbVar14)) break;
        pbVar22 = pbVar14 + *pbVar14;
        if (*(char *)(param_1 + 0x26fc) == '\0') {
          bVar27 = pbVar14[2] == 8;
LAB_14002a8ea:
          if (bVar27) {
            *(byte *)(param_1 + 0x26fd) = pbVar14[3];
            break;
          }
        }
        else if (*(char *)(param_1 + 0x26fc) == ' ') {
          bVar27 = pbVar14[2] == 9;
          goto LAB_14002a8ea;
        }
      } while (pbVar22 != (byte *)0x0);
    }
  }
  iVar9 = FUN_140026590(param_1);
  if (iVar9 == -0x3ffffb67) {
    return -0x3ffffd2e;
  }
  if (iVar9 < 0) goto LAB_14002b547;
  if (*(longlong *)(param_1 + 0x158) == 0) {
    puVar12 = (undefined8 *)ExAllocatePoolWithTag(DAT_140075ba0,8,0x43525950);
    plVar15 = plVar25;
    if (puVar12 != (undefined8 *)0x0) {
      *puVar12 = 0;
      plVar15 = FUN_1400334d4(puVar12);
    }
    *(longlong **)(param_1 + 0x158) = plVar15;
    if (plVar15 != (longlong *)0x0) goto code_r0x00014002a970;
LAB_14002a963:
    iVar9 = -0x3fffff66;
    goto LAB_14002b547;
  }
code_r0x00014002a970:
  iVar9 = FUN_140033648(*(undefined8 **)(param_1 + 0x158));
  if (iVar9 < 0) goto LAB_14002b547;
  if (*(longlong *)(param_1 + 0x150) == 0) {
    plVar16 = (longlong *)ExAllocatePoolWithTag(DAT_140075ba0,0x28,0x70696e6d);
    plVar15 = plVar25;
    if (plVar16 != (longlong *)0x0) {
      *plVar16 = 0;
      plVar16[1] = 0;
      plVar16[2] = 0;
      plVar16[3] = 0;
      plVar16[4] = 0;
      plVar15 = FUN_14004be1c(plVar16,param_1);
    }
    *(longlong **)(param_1 + 0x150) = plVar15;
    if (plVar15 == (longlong *)0x0) goto LAB_14002a963;
  }
  FUN_14004c84c(*(longlong **)(param_1 + 0x150));
  psVar3 = (short *)(param_1 + 0xe68);
  FUN_14003190c(param_1,0x17,0xc0,0x25,0,0xff80,psVar3,0x164,'\x01');
  if (*psVar3 == 0) {
    *(undefined1 *)(param_1 + 0xe6a) = 0x38;
    puVar19 = (undefined4 *)(param_1 + 0xf30);
    puVar17 = (undefined4 *)(param_1 + 0xe78);
    lVar13 = 0x10;
    do {
      *(undefined8 *)(puVar17 + -2) = 0;
      *puVar17 = 0;
      puVar17 = puVar17 + 3;
      *puVar19 = 0;
      puVar19 = puVar19 + 1;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
  }
  *(uint *)(param_1 + 0x2374) = *(uint *)(param_1 + 0x2374) | 0xc;
  FUN_140028804(param_1,(ushort *)local_50);
  FUN_140025400(param_1);
  FUN_1400294fc(param_1);
  plVar15 = (longlong *)(param_1 + 0xb18);
  if (*plVar15 != 0) {
    (*(code *)PTR__guard_dispatch_icall_14005f458)(*plVar15,1);
    *plVar15 = 0;
  }
  if (*(int *)(param_1 + 0x26b0) == 0xad) {
LAB_14002ab51:
    FUN_14003da2c(plVar15,param_1);
  }
  else {
    if (*(short *)(param_1 + 0x26aa) == 0x4c5) {
      sVar20 = *(short *)(param_1 + 0x26a8);
      if (((sVar20 == 0x14a3) || (sVar20 == 0x1570)) || (sVar20 == 0x1571)) goto LAB_14002ab51;
    }
    else if (*(short *)(param_1 + 0x26aa) == 0xbda) {
      uVar7 = *(ushort *)(param_1 + 0x26a8);
      if (uVar7 < 0x4017) {
        if (((uVar7 == 0x4016) || ((uVar7 == 0x4001 || (uVar7 == 0x4008)))) ||
           ((uVar7 != 0x400b && ((uVar7 == 0x400e || (uVar7 == 0x4014)))))) {
LAB_14002ab32:
          FUN_1400343d8(plVar15,param_1);
          goto LAB_14002ab5c;
        }
      }
      else if ((uVar7 == 0x402d) || (uVar7 == 0x402e)) goto LAB_14002ab32;
    }
    FUN_140046a88(plVar15,param_1);
  }
LAB_14002ab5c:
  if ((*(uint *)(param_1 + 0x2374) & 1) == 0) {
    *(uint *)(param_1 + 0x2374) = *(uint *)(param_1 + 0x2374) & 0xffffffef;
  }
  if ((*plVar15 != 0) && (*psVar3 == 0)) {
    (*(code *)PTR__guard_dispatch_icall_14005f458)(*plVar15,1);
    *plVar15 = 0;
  }
  if (*(int *)(param_1 + 0x2488) == 0x15) {
    *(uint *)(param_1 + 0x2434) = *(uint *)(param_1 + 0x2434) & 0xefffffff;
    *(uint *)(param_1 + 0x2390) = *(uint *)(param_1 + 0x2390) & 0xffffbfff;
  }
  FUN_14002ed34(param_1);
  IoRegisterPlugPlayNotification
            (2,1,&DAT_1400602d8,*(undefined8 *)(*(longlong *)(param_1 + 0x26e8) + 8),FUN_14002a4d0,
             param_1,param_1 + 0x1b18);
  IoRegisterPlugPlayNotification
            (2,1,&DAT_140060268,*(undefined8 *)(*(longlong *)(param_1 + 0x26e8) + 8),FUN_14002a330,
             param_1,param_1 + 0x1b20);
  if ((*(uint *)(param_1 + 0x2380) & 0x40000000) != 0) {
    IoRegisterPlugPlayNotification
              (2,1,&DAT_140060298,*(undefined8 *)(*(longlong *)(param_1 + 0x26e8) + 8),FUN_14002a6a0
               ,param_1,param_1 + 0x1b28);
  }
  FUN_1400276ac(param_1);
  FUN_140025214(param_1);
  plVar15 = (longlong *)(param_1 + 0xb20);
  if (*plVar15 != 0) {
    (*(code *)PTR__guard_dispatch_icall_14005f458)();
    if (*plVar15 != 0) {
      (*(code *)PTR__guard_dispatch_icall_14005f458)(*plVar15,1);
      *plVar15 = 0;
    }
  }
  sVar20 = *psVar3;
  if (sVar20 == 0x288) {
    FUN_1400184c0(plVar15,param_1);
    if ((*(short *)(param_1 + 0x26a8) == 0x402d) || (*(short *)(param_1 + 0x26a8) == 0x400e)) {
      FUN_140031138(param_1,0x18,0);
      FUN_1400303ec(param_1,0x20,0x19,0x300,0xfffffcff);
    }
  }
  else if (sVar20 == 0x4032) {
    FUN_140019e04(plVar15,param_1);
  }
  else if ((sVar20 == 0x4040) || (sVar20 == 0x4042)) {
    FUN_14001bb98(plVar15,param_1);
  }
  else if (sVar20 == 0x4050) {
    FUN_14001dc88(plVar15,param_1);
  }
  local_58 = 0;
  if (*(int *)(param_1 + 0xff0) != 0) {
    do {
      uVar21 = (uint)plVar25;
      psVar3 = *(short **)(*(longlong *)(param_1 + 0xff8) + (longlong)plVar25 * 8);
      if (psVar3 != (short *)0x0) {
        FUN_140038270((longlong)psVar3);
        local_res8 = 0;
        if (*(int *)(psVar3 + 0x174) != 0) {
          local_50[0] = 0;
          do {
            lVar26 = local_50[0];
            lVar13 = *(longlong *)(local_50[0] + *(longlong *)(psVar3 + 0x178));
            if (lVar13 != 0) {
              uVar21 = local_res8;
              if (((*(int *)(param_1 + 0x26b4) == 0x92) && (*(int *)(lVar13 + 0x10) == 0x38)) &&
                 (FUN_140055990(lVar13), (*(byte *)(lVar13 + 0x4c) & 2) != 0)) {
                uVar21 = FUN_14005470c(lVar13,*(uint *)(lVar13 + 0x20));
              }
              if (((*(byte *)(lVar13 + 0x4c) & 8) != 0) ||
                 ((*(uint *)(param_1 + 0x2384) & 0x400) != 0)) {
                uVar21 = FUN_14005470c(lVar13,*(uint *)(lVar13 + 0x20));
              }
              if ((*(int *)(param_1 + 0x26b4) - 0x7eU < 4) && (*(int *)(psVar3 + 0x16c) == 1)) {
                FUN_14003b590((longlong)psVar3,0,L"current_channel_number",4,
                              (undefined8 *)(psVar3 + 0x12a));
                FUN_14003b590((longlong)psVar3,0,L"channel_config.ActiveSpeakerPositions",4,
                              (undefined8 *)(psVar3 + 0x126));
                lVar5 = *(longlong *)(*(longlong *)(psVar3 + 0x168) + 0xe48);
                lVar6 = *(longlong *)(*(longlong *)(psVar3 + 0x168) + 0xe60);
                iVar10 = *(int *)(psVar3 + 0x12a);
                lVar26 = local_50[0];
                if (iVar10 == 2) {
                  uVar21 = local_res8;
                  if ((lVar5 != 0) && (lVar6 != 0)) {
                    iVar10 = *(int *)(lVar13 + 0x10);
                    if (iVar10 == 0x3b) {
                      uVar21 = 0xf;
LAB_14002aea5:
                      uVar21 = FUN_14005470c(lVar5,uVar21);
                      puVar1 = (ushort *)(CONCAT44((int)((ulonglong)lVar5 >> 0x20),uVar21) + 0x4c);
                      *puVar1 = *puVar1 & 0xfff7;
                      lVar26 = local_50[0];
                      uVar21 = local_res8;
                    }
                    else {
LAB_14002aeb8:
                      uVar21 = local_res8;
                      if (iVar10 == 0x3a) {
                        uVar21 = 1;
LAB_14002af06:
                        FUN_14005470c(lVar6,uVar21);
                        *(ushort *)(lVar6 + 0x4c) = *(ushort *)(lVar6 + 0x4c) & 0xfff7;
                        lVar26 = local_50[0];
                        uVar21 = local_res8;
                      }
                    }
                  }
                }
                else if (iVar10 == 4) {
                  uVar21 = local_res8;
                  if ((lVar5 != 0) && (lVar6 != 0)) {
                    iVar10 = *(int *)(lVar13 + 0x10);
                    if (iVar10 != 0x3b) goto LAB_14002aeb8;
LAB_14002aeda:
                    uVar21 = 5;
                    goto LAB_14002aea5;
                  }
                }
                else {
                  uVar21 = local_res8;
                  if ((((iVar10 - 6U & 0xfffffffd) == 0) && (lVar5 != 0)) && (lVar6 != 0)) {
                    if (*(int *)(lVar13 + 0x10) == 0x3b) goto LAB_14002aeda;
                    if (*(int *)(lVar13 + 0x10) == 0x3a) {
                      uVar21 = 6;
                      goto LAB_14002af06;
                    }
                  }
                }
              }
              local_res8 = uVar21;
              if (((*(int *)(param_1 + 0x26b4) == 0x84 || *(int *)(param_1 + 0x26b4) == 0x85) &&
                  (*(int *)(psVar3 + 0x16c) == 1)) && (*(int *)(lVar13 + 0x20) == 4)) {
                FUN_14003b590((longlong)psVar3,0,L"current_channel_number",4,
                              (undefined8 *)(psVar3 + 0x12a));
                lVar13 = *(longlong *)(*(longlong *)(psVar3 + 0x168) + 0xe48);
                lVar5 = *(longlong *)(*(longlong *)(psVar3 + 0x168) + 0xe58);
                if ((lVar13 != 0) && (lVar5 != 0)) {
                  iVar10 = *(int *)(psVar3 + 0x12a);
                  if (iVar10 == 2) {
                    *(ushort *)(lVar5 + 0x4e) = *(ushort *)(lVar5 + 0x4e) & 0xffbf | 1;
                    uVar7 = *(ushort *)(lVar13 + 0x4e) & 0xffdf | 1;
                  }
                  else {
                    if (iVar10 == 4) {
                      *(ushort *)(lVar5 + 0x4e) = *(ushort *)(lVar5 + 0x4e) & 0xffbf | 1;
                      uVar7 = *(ushort *)(lVar13 + 0x4e);
                    }
                    else {
                      if (iVar10 != 6) goto LAB_14002b014;
                      *(ushort *)(lVar5 + 0x4e) = *(ushort *)(lVar5 + 0x4e) & 0xfffe | 0x40;
                      uVar7 = *(ushort *)(lVar13 + 0x4e);
                    }
                    uVar7 = uVar7 & 0xfffe | 0x20;
                  }
                  *(ushort *)(lVar13 + 0x4e) = uVar7;
                }
              }
            }
LAB_14002b014:
            local_res8 = local_res8 + 1;
            local_50[0] = lVar26 + 8;
            uVar21 = local_58;
          } while (local_res8 < *(uint *)(psVar3 + 0x174));
        }
        FUN_14003a868(psVar3);
        FUN_1400395d8(psVar3);
        FUN_1400399e4((longlong)psVar3);
        FUN_140039420(psVar3);
        FUN_14003bd84(psVar3);
        FUN_14003c8b8((longlong)psVar3,*(int *)(psVar3 + 0x16c));
      }
      local_58 = uVar21 + 1;
      plVar25 = (longlong *)(ulonglong)local_58;
    } while (local_58 < *(uint *)(param_1 + 0xff0));
  }
  if (*(short *)(param_1 + 0xe68) != 0) {
    if ((*(uint *)(param_1 + 0x2374) & 1) != 0) {
      if ((*(uint *)(param_1 + 0x2374) & 0x10) != 0) {
        iVar10 = 4;
        do {
          uVar8 = FUN_140026db4(param_1);
          if ((int)CONCAT62(extraout_var,uVar8) != 0) break;
          FUN_14004cbac(0x32);
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
      *(undefined4 *)(param_1 + 0xae0) = 1;
    }
    plVar15 = (longlong *)(param_1 + 0xba8);
    if ((*plVar15 != 0) && (FUN_14004cd08(*plVar15), *plVar15 != 0)) {
      lVar13 = *plVar15;
      if (lVar13 != 0) {
        FUN_14004beb0(lVar13);
        ExFreePoolWithTag(lVar13,0);
      }
      *plVar15 = 0;
    }
    uVar24 = 500;
    if ((*(uint *)(param_1 + 0x2374) >> 8 & 1) == 0) {
      if ((char)*(uint *)(param_1 + 0x2374) < '\0') {
        FUN_14004c5d4(plVar15,FUN_140029c00,param_1,500,1);
        if (*plVar15 != 0) {
          FUN_14004ccf8(*plVar15);
        }
      }
      else if (*(longlong *)(param_1 + 0x2180) != 0) {
        uVar18 = FUN_14004adb8(param_1);
        iVar9 = (int)uVar18;
        if (-1 < iVar9) {
          uVar11 = FUN_14004b76c(param_1);
          iVar9 = (int)uVar11;
          iVar10 = 0;
          if ((iVar9 == 0x103) || (iVar10 = iVar9, -1 < iVar9)) {
            iVar9 = iVar10;
            if (*(int *)(param_1 + 0x160) == 0) {
              uVar23 = 100;
            }
            else {
              uVar23 = *(undefined4 *)(param_1 + 0x160);
            }
            FUN_14004c5d4(plVar15,FUN_140029c00,param_1,uVar23,0);
            goto LAB_14002b1e1;
          }
        }
        FUN_14004ae74(param_1);
        *(undefined8 *)(param_1 + 0x2180) = 0;
      }
    }
LAB_14002b1e1:
    iVar10 = FUN_140017430(param_1,1);
    FUN_1400271fc(param_1,1);
    plVar15 = (longlong *)(param_1 + 0xbb0);
    if (*plVar15 == 0) {
      FUN_14004c5d4(plVar15,FUN_140029c00,param_1,3000,0);
    }
    if (((*(uint *)(param_1 + 0x2388) & 4) != 0) && (*(longlong *)(param_1 + 3000) == 0)) {
      FUN_14004c5d4((longlong *)(param_1 + 3000),FUN_140031870,param_1,1000,0);
    }
    plVar25 = (longlong *)(param_1 + 0xbc0);
    if (*plVar25 == 0) {
      uVar23 = 4000;
      if (*(int *)(param_1 + 0x26b4) == 0xac) {
        uVar23 = 5000;
      }
      FUN_14004c5d4(plVar25,FUN_140031850,param_1,uVar23,0);
    }
    if ((*(uint *)(param_1 + 0x2384) & 0x10000) != 0) {
      if (*(int *)(param_1 + 0x26b0) == 0x9f) {
        iVar9 = IoRegisterDeviceInterface
                          (*(undefined8 *)(param_1 + 0x26e8),&DAT_140060248,param_1 + 0x2658,
                           param_1 + 0x2648);
        if (-1 < iVar9) {
          IoSetDeviceInterfaceState(param_1 + 0x2648,1);
        }
        iVar9 = IoRegisterPlugPlayNotification
                          (2,1,&DAT_140060238,*(undefined8 *)(*(longlong *)(param_1 + 0x26e8) + 8),
                           FUN_14002a6e0,param_1,param_1 + 0x1b30);
      }
      else if (*(int *)(param_1 + 0x26b0) == 0xa3) {
        iVar9 = IoRegisterDeviceInterface
                          (*(undefined8 *)(param_1 + 0x26e8),&DAT_140060238,param_1 + 0x2688,
                           param_1 + 0x2678);
        if (-1 < iVar9) {
          iVar9 = IoSetDeviceInterfaceState(param_1 + 0x2678,1);
        }
      }
    }
    if (iVar10 < 0) {
      FUN_1400256a0(param_1,1);
    }
    else if ((*plVar15 != 0) && (FUN_14004ccf8(*plVar15), *plVar25 != 0)) {
      FUN_14004ccf8(*plVar25);
    }
    FUN_140032924(param_1);
    FUN_1400310c0(param_1);
    if ((*(uint *)(param_1 + 0x237c) & 1) != 0) {
      FUN_14002ea98(param_1);
      FUN_14002e5cc(param_1);
      FUN_14002eb24(param_1);
    }
    if ((*(uint *)(param_1 + 0x2384) & 1) != 0) {
      FUN_1400280b0(param_1);
    }
    FUN_14002eedc(param_1);
    FUN_14002efac(param_1);
    FUN_14002f164(param_1);
    if (((*(short *)(param_1 + 0x26aa) == 0xb05) && (*(int *)(param_1 + 0x26b0) == 0xb1)) ||
       (*(int *)(param_1 + 0x26b4) == 0x84 || *(int *)(param_1 + 0x26b4) == 0x85)) {
      uVar21 = *(int *)(param_1 + 0x26b4) - 0x84;
      if ((0xc < uVar21) || ((0x1023U >> (uVar21 & 0x1f) & 1) == 0)) {
        uVar24 = 1000;
      }
      FUN_14004c5d4((undefined8 *)(param_1 + 0xce0),FUN_140030150,param_1,uVar24,0);
    }
    if ((*(uint *)(param_1 + 0x2388) & 2) == 0) {
      FUN_140027e54(param_1);
    }
  }
  if ((*(uint *)(param_1 + 0x2374) & 1) != 0) {
    FUN_14003190c(param_1,0x17,0x40,0x48,1,0,0,0,'\0');
  }
  if (((*(uint *)(param_1 + 0x2380) & 0x10400000) != 0) || ((*(uint *)(param_1 + 0x2384) & 2) != 0))
  {
    iVar9 = FUN_14003190c(param_1,0x17,0x40,0x4b,1,0,0,0,'\0');
  }
LAB_14002b547:
  if ((*(uint *)(param_1 + 0x2380) & 0x80000) != 0) {
    FUN_14004c5d4((undefined8 *)(param_1 + 0xcf8),FUN_140053630,param_1,3000,0);
    if (*(int *)(param_1 + 0xbf0) == 0) {
      uVar18 = PoRegisterDeviceForIdleDetection(*(undefined8 *)(param_2 + 0x20),1,1,3);
      *(undefined8 *)(param_1 + 0xb10) = uVar18;
    }
    else if (*(int *)(param_1 + 0xbf0) == 1) {
      FUN_14004c5d4((longlong *)(param_1 + 0xbc8),FUN_140053060,param_1,10000,1);
      lVar13 = *(longlong *)(param_1 + 0xbc8);
      if (lVar13 != 0) {
        FUN_14004ccf8(lVar13);
      }
      FUN_140053278(param_1);
    }
  }
  if ((*(uint *)(param_1 + 0x2380) & 0x400000) != 0) {
    iVar9 = IoRegisterDeviceInterface
                      (*(undefined8 *)(param_1 + 0x26e8),&DAT_140060298,param_1 + 0x2628,
                       param_1 + 0x2618);
    if (-1 < iVar9) {
      iVar9 = IoSetDeviceInterfaceState(param_1 + 0x2618,1);
    }
  }
  if ((*(uint *)(param_1 + 0x2380) & 0x40000000) != 0) {
    FUN_14004c5d4((undefined8 *)(param_1 + 0xcf0),FUN_140029ec0,param_1,1000,0);
  }
  FUN_140025490(param_1);
  if (*(int *)(param_1 + 0x26b0) == 0x16) {
    FUN_14002ebec(param_1,0x506,0x10,0xef);
    FUN_14002ebec(param_1,0x508,0x10,0xef);
  }
  if (*(int *)(param_1 + 0x26b4) == 0x2d) {
    iVar10 = FUN_140032738(param_1,0x28);
    sVar20 = (-(ushort)(iVar10 != 0) & 0xfffd) + 0x2b;
    *(short *)(param_1 + 0x2088) = sVar20;
    FUN_140031ce8(param_1,sVar20,0x11,2,0xfc);
  }
  if (*(int *)(param_1 + 0xcdc) != 0) {
    *(undefined4 *)(param_1 + 0xcd8) = 1;
    KeInitializeEvent(param_1 + 0x1b00,0,0);
    FUN_14004c5d4((undefined8 *)(param_1 + 0xcd0),FUN_14002ec70,param_1,3000,0);
    lVar13 = *(longlong *)(param_1 + 0xce0);
    if (lVar13 != 0) {
      if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
         ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
        FUN_14001b4c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x14,&DAT_1400602c8,
                      "CCommon::PnpStart");
        lVar13 = *(longlong *)(param_1 + 0xce0);
      }
      FUN_14004ccf8(lVar13);
    }
  }
  if ((*(uint *)(param_1 + 0x2434) & 0x100) != 0) {
    FUN_14003281c(param_1,param_1);
  }
  FUN_140053164(param_1);
  return iVar9;
}

