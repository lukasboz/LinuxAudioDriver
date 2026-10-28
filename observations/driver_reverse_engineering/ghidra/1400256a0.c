
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1400256a0(longlong param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  longlong *plVar3;
  int *piVar4;
  bool bVar5;
  bool bVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar11;
  wchar_t *pwVar12;
  longlong lVar13;
  ushort uVar14;
  short sVar15;
  short sVar16;
  int *piVar17;
  longlong lVar18;
  undefined1 auStackY_1a8 [32];
  uint *puVar19;
  undefined8 uVar20;
  int local_144;
  uint local_140;
  uint local_13c;
  char local_138 [256];
  ulonglong local_38;
  int *piVar10;
  undefined4 uVar21;
  
  local_38 = DAT_1400698c0 ^ (ulonglong)auStackY_1a8;
  if ((*(int *)(param_1 + 0x26e0) - 1U & 0xfffffffd) != 0) {
    return;
  }
  local_144 = param_2;
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 8) != 0)) {
    FUN_140032b00(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x27,&DAT_1400602c8,
                  "CCommon::CheckJDStatus");
  }
  piVar17 = (int *)0x0;
  bVar6 = false;
  if ((*(int *)(param_1 + 0xbf8) != 0) && (*(uint *)(param_1 + 0xfd8) != 0)) {
    plVar3 = *(longlong **)(param_1 + 0xfe0);
    piVar10 = piVar17;
    do {
      if (*(int *)(plVar3[(longlong)piVar10] + 0x10) == 0x37) {
        lVar13 = *plVar3;
        *plVar3 = plVar3[(longlong)piVar10];
        *(longlong *)(*(longlong *)(param_1 + 0xfe0) + (longlong)piVar10 * 8) = lVar13;
        break;
      }
      uVar8 = (int)piVar10 + 1;
      piVar10 = (int *)(ulonglong)uVar8;
    } while (uVar8 < *(uint *)(param_1 + 0xfd8));
  }
  piVar10 = piVar17;
  bVar5 = false;
  if (*(int *)(param_1 + 0xfd8) != 0) {
    do {
      bVar6 = bVar5;
      if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
         ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
        FUN_140032b00(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x28,&DAT_1400602c8,
                      "CCommon::CheckJDStatus");
      }
      piVar4 = *(int **)(*(longlong *)(param_1 + 0xfe0) + (longlong)piVar17 * 8);
      if ((piVar4 != (int *)0x0) && (piVar4 != *(int **)(param_1 + 0xe18))) {
        local_140 = 0;
        local_13c = 4;
        FUN_14002f25c(local_138,0x100,L"widget_%d",piVar17);
        puVar19 = &local_140;
        uVar11 = FUN_14002db9c((longlong *)(param_1 + 0x2348),0x14005b7c0,local_138,&local_13c,
                               (undefined8 *)puVar19,0,1);
        uVar21 = (undefined4)((ulonglong)puVar19 >> 0x20);
        if ((int)uVar11 < 0) {
          if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
             ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
            pwVar12 = FUN_14005627c(piVar4,piVar4[4]);
            uVar20 = CONCAT44(uVar21,0x1c4b);
            FUN_140032c84(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x2a,&DAT_1400602c8,
                          "CCommon::CheckJDStatus",uVar20,pwVar12);
            uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
          }
        }
        else {
          *(ushort *)(piVar4 + 0x13) =
               ((short)local_140 * 2 ^ *(ushort *)(piVar4 + 0x13)) & 2 ^ *(ushort *)(piVar4 + 0x13);
          if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
             ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
            pwVar12 = FUN_14005627c(piVar4,piVar4[4]);
            uVar20 = CONCAT44(uVar21,0x1c47);
            FUN_140032d7c(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x29,&DAT_1400602c8,
                          "CCommon::CheckJDStatus",uVar20,pwVar12);
            uVar21 = (undefined4)((ulonglong)uVar20 >> 0x20);
          }
        }
        FUN_140055b90(piVar4);
        local_140 = *(ushort *)(piVar4 + 0x13) >> 1 & 1;
        if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
           ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
          pwVar12 = FUN_14005627c(piVar4,piVar4[4]);
          FUN_140032d7c(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x2b,&DAT_1400602c8,
                        "CCommon::CheckJDStatus",CONCAT44(uVar21,0x1c54),pwVar12);
        }
        FUN_140031bac((longlong *)(param_1 + 0x2348),0x14005b7c0,local_138,4,4,&local_140,0);
        if ((((*(uint *)(param_1 + 0x2384) & 0x40000) != 0) &&
            ((*(uint *)(param_1 + 0x2394) & 0x100) == 0)) && (piVar4[4] == 0x37)) {
          FUN_14003ccf0(*(longlong *)(piVar4 + 6));
        }
        if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
           ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
          FUN_14005627c(piVar4,piVar4[4]);
          FUN_1400331a8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x2d,&DAT_1400602c8,
                        "CCommon::CheckJDStatus");
        }
        iVar9 = local_144;
        uVar7 = *(ushort *)(piVar4 + 0x13);
        if (((((byte)uVar7 >> 1 ^ (byte)uVar7) & 2) != 0) && (*(longlong *)(piVar4 + 6) != 0)) {
          if ((*(longlong *)(param_1 + 0xb28) != 0) && (local_144 == 0)) {
            if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
               ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
              FUN_14005627c(piVar4,piVar4[4]);
              FUN_140033080(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x2e,&DAT_1400602c8,
                            "CCommon::CheckJDStatus");
              uVar7 = *(ushort *)(piVar4 + 0x13);
            }
            iVar2 = *(int *)(param_1 + 0x26b4);
            if (iVar2 == 0x7d) {
              if ((*(int *)(*(longlong *)(piVar4 + 6) + 0x2c8) != 1) || ((uVar7 & 2) == 0))
              goto LAB_140025c9b;
              bVar6 = true;
              piVar10 = piVar4;
            }
            else {
              if (iVar2 == 0x8d) {
                if (piVar4[4] == 0x1f) {
                  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
                     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
                    FUN_14005627c(piVar4,0x1f);
                    FUN_140032f70(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x2f,&DAT_1400602c8,
                                  "CCommon::CheckJDStatus");
                  }
                  FUN_140020e64(*(longlong *)(param_1 + 0xb28),piVar4[3]);
                  if (((*(byte *)(piVar4 + 0x13) & 2) == 0) &&
                     (lVar13 = FUN_14002821c(param_1,0x21), lVar13 != 0)) {
                    FUN_14003ccf0(*(longlong *)(lVar13 + 0x18));
                  }
                  goto LAB_140025dac;
                }
LAB_140025c9b:
                if (*(short *)(param_1 + 0x26a8) == 0x1b9b) goto LAB_140025caa;
              }
              else {
                if (iVar2 != 0x85) goto LAB_140025c9b;
LAB_140025caa:
                if (piVar4[4] - 0x3aU < 2) {
                  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
                     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
                    FUN_14005627c(piVar4,piVar4[4]);
                    FUN_140032f70(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x30,&DAT_1400602c8,
                                  "CCommon::CheckJDStatus");
                  }
                  goto LAB_140025dac;
                }
              }
              if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
                 ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
                FUN_14005627c(piVar4,piVar4[4]);
                FUN_140032f70(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x31,&DAT_1400602c8,
                              "CCommon::CheckJDStatus");
              }
              FUN_140020e64(*(longlong *)(param_1 + 0xb28),piVar4[3]);
            }
          }
LAB_140025dac:
          uVar7 = *(ushort *)(piVar4 + 0x13);
          uVar8 = *(uint *)(param_1 + 0x2380);
          if ((((byte)uVar7 & 10) == 10) && ((uVar8 & 0x400) == 0)) {
            if (*(int *)(param_1 + 0xb0c) == 0) {
LAB_140026002:
              FUN_14005470c((longlong)piVar4,piVar4[8]);
            }
            else {
              piVar4[2] = 1;
            }
          }
          else {
            if (((uVar8 & 0x4020000) != 0) && (((uVar7 & 2) != 0 && ((uVar8 & 0x400) != 0))))
            goto LAB_140026002;
            if ((uVar7 & 1) != 0) {
              if (((*(int *)(param_1 + 0x26b4) != 0x7d) ||
                  (*(int *)(*(longlong *)(piVar4 + 6) + 0x2c8) != 1)) || ((uVar7 & 2) == 0)) {
                FUN_14003ccf0(*(longlong *)(piVar4 + 6));
                uVar8 = *(uint *)(param_1 + 0x2380);
              }
              if ((uVar8 & 0x400) != 0) {
                uVar7 = *(ushort *)(piVar4 + 0x13);
                *(ushort *)(piVar4 + 0x13) = (uVar7 * 2 ^ uVar7) & 4 ^ uVar7;
              }
            }
          }
          if (((iVar9 == 0) && ((*(byte *)(piVar4 + 0x13) & 2) != 0)) &&
             ((piVar4[4] == 0x1a && (((byte)*(undefined4 *)(param_1 + 0x2380) & 6) == 6)))) {
            FUN_140056a0c(piVar4,0,1,0);
          }
          if (((*(short *)(param_1 + 0x26a8) == 0x4008) && ((*(byte *)(piVar4 + 0x13) & 2) != 0)) &&
             (piVar4[4] == 0x21)) {
            FUN_1400303ec(param_1,0x20,8,0xd,0xfffffff2);
          }
        }
      }
      uVar8 = (int)piVar17 + 1;
      piVar17 = (int *)(ulonglong)uVar8;
      bVar5 = bVar6;
    } while (uVar8 < *(uint *)(param_1 + 0xfd8));
  }
  sVar16 = 0;
  bVar5 = false;
  if ((*(longlong *)(param_1 + 0xe18) != 0) && (*(longlong *)(param_1 + 0xe10) != 0)) {
    uVar7 = *(ushort *)(*(longlong *)(param_1 + 0xe10) + 0x4c);
    uVar14 = uVar7 >> 1 & 1;
    if (((uVar7 >> 2 & 1) != uVar14) || ((*(uint *)(param_1 + 0x2380) >> 0x11 & 1) != 0)) {
      if (((uVar7 & 8) == 0) || (uVar8 = *(uint *)(param_1 + 0x24c0), (uVar8 >> 0x14 & 1) != 0)) {
        sVar15 = 0;
        if ((uVar7 & 2) != 0) {
          local_144 = 0;
          if (*(short *)(param_1 + 0xe68) == 0x288) {
            FUN_140028248(param_1,0x20,0x50,&local_144);
            if (((byte)local_144 & 0x70) == 0x70) {
              sVar16 = 1;
            }
          }
          sVar15 = sVar16;
          if ((((((*(uint *)(param_1 + 0x2380) & 0x4020000) != 0) ||
                ((*(uint *)(param_1 + 0x24c0) >> 0x14 & 1) != 0)) &&
               (uVar7 = *(short *)(param_1 + 0xe68) + 0xbfce, uVar7 < 0x1f)) &&
              (((0x40014001U >> (uVar7 & 0x1f) & 1) != 0 && (*(longlong *)(param_1 + 0xb20) != 0))))
             && ((iVar9 = (*(code *)PTR__guard_dispatch_icall_14005f458)
                                    (*(longlong *)(param_1 + 0xb20),*(undefined8 *)(param_1 + 0xe18)
                                     ,&local_13c), -1 < iVar9 &&
                 ((local_13c == 1 || (sVar15 = 0, local_13c == 2)))))) {
            sVar15 = 1;
          }
        }
        uVar7 = *(ushort *)(*(longlong *)(param_1 + 0xe18) + 0x4c);
        *(ushort *)(*(longlong *)(param_1 + 0xe18) + 0x4c) = (uVar7 * 2 ^ uVar7) & 4 ^ uVar7;
        *(ushort *)(*(longlong *)(param_1 + 0xe18) + 0x4c) =
             sVar15 * 2 | *(ushort *)(*(longlong *)(param_1 + 0xe18) + 0x4c) & 0xfffd;
        lVar13 = *(longlong *)(*(longlong *)(param_1 + 0xe18) + 0x18);
        if (lVar13 != 0) {
          FUN_14003ccf0(lVar13);
        }
        if (((*(uint *)(param_1 + 0x2380) & 0x80000) != 0) &&
           (lVar13 = *(longlong *)(*(longlong *)(param_1 + 0xe10) + 0x18), lVar13 != 0)) {
          FUN_14003ccf0(lVar13);
        }
      }
      else {
        if (((uVar14 == 0) && ((*(uint *)(param_1 + 0x2380) & 0x4020000) == 0)) &&
           (*(int *)(param_1 + 0x2170) != 0)) {
          bVar5 = true;
        }
        if (((char)*(undefined4 *)(param_1 + 0x2378) < '\0') && ((uVar7 & 2) == 0)) {
          bVar5 = true;
          if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
             (bVar5 = true, (*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
            FUN_140032b00(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x32,&DAT_1400602c8,
                          "CCommon::CheckJDStatus");
            uVar8 = *(uint *)(param_1 + 0x24c0);
            bVar5 = true;
          }
        }
        if ((((uVar8 >> 0x14 & 1) == 0) || (*(longlong *)(param_1 + 0xe10) == 0)) ||
           ((*(byte *)(*(longlong *)(param_1 + 0xe10) + 0x4c) & 2) != 0)) {
          if (!bVar5) goto LAB_1400261a5;
        }
        else if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
                ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
          FUN_140032b00(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x33,&DAT_1400602c8,
                        "CCommon::CheckJDStatus");
        }
        lVar13 = *(longlong *)(param_1 + 0xe18);
        if (lVar13 != 0) {
          uVar7 = *(ushort *)(lVar13 + 0x4c);
          *(ushort *)(lVar13 + 0x4c) = (uVar7 * 2 ^ uVar7) & 4 ^ uVar7;
          puVar1 = (ushort *)(*(longlong *)(param_1 + 0xe18) + 0x4c);
          *puVar1 = *puVar1 ^ (*(ushort *)(*(longlong *)(param_1 + 0xe10) + 0x4c) ^
                              *(ushort *)(*(longlong *)(param_1 + 0xe18) + 0x4c)) & 2;
          lVar13 = *(longlong *)(param_1 + 0xe18);
          if (*(longlong *)(lVar13 + 0x18) != 0) {
            lVar18 = *(longlong *)(param_1 + 0xb28);
            if (lVar18 != 0) {
              if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
                 ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
                FUN_14005627c(lVar13,*(uint *)(lVar13 + 0x10));
                FUN_140032f70(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x34,&DAT_1400602c8,
                              "CCommon::CheckJDStatus");
                lVar13 = *(longlong *)(param_1 + 0xe18);
                lVar18 = *(longlong *)(param_1 + 0xb28);
              }
              FUN_140020e64(lVar18,*(uint *)(lVar13 + 0xc));
              lVar13 = *(longlong *)(param_1 + 0xe18);
            }
            FUN_14003ccf0(*(longlong *)(lVar13 + 0x18));
          }
        }
      }
    }
  }
LAB_1400261a5:
  if ((*(uint *)(param_1 + 0x2374) & 0x10) != 0) {
    FUN_1400303ec(param_1,0x20,0x33,1,0xfffffffe);
  }
  if ((*(uint *)(param_1 + 0x2380) & 0x40000000) != 0) {
    FUN_140029ec8(param_1,0);
  }
  if ((*(uint *)(param_1 + 0x2384) & 0x10000) != 0) {
    FUN_140029ec8(param_1,0);
  }
  if ((bVar6) && (piVar10 != (int *)0x0)) {
    FUN_14004cbac(4000);
    if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
       ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 4) != 0)) {
      FUN_14005627c(piVar10,piVar10[4]);
      FUN_140032f70(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x35,&DAT_1400602c8,
                    "CCommon::CheckJDStatus");
    }
    FUN_140020e64(*(longlong *)(param_1 + 0xb28),piVar10[3]);
    FUN_14003ccf0(*(longlong *)(piVar10 + 6));
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  return;
}

