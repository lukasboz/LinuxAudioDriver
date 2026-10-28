
uint FUN_140056348(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  longlong *plVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  uint uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  uint local_res8 [2];
  
  uVar8 = 0;
  uVar7 = 0;
  if (((*(byte *)(param_1 + 0x4c) & 2) == 0) || (uVar10 = 1, *(int *)(param_1 + 8) != 0)) {
    uVar10 = uVar7;
  }
  lVar4 = *(longlong *)(param_1 + 0x28);
  uVar11 = *(uint *)(lVar4 + 0x2384);
  if ((uVar11 >> 10 & 1) != 0) {
    if (((uVar11 >> 0x16 & 1) != 0) && (*(longlong *)(lVar4 + 0xe38) != 0)) {
      if (*(int *)(param_1 + 0x10) == 0x21) {
        uVar10 = uVar10 | *(ushort *)(*(longlong *)(lVar4 + 0xe38) + 0x4c) >> 1 & 1;
      }
      if ((((uVar11 >> 0x17 & 1) != 0) && (*(int *)(param_1 + 0x10) == 0x1f)) &&
         (*(int *)(param_1 + 0x20) == 2)) {
        return 0;
      }
    }
    if ((((uVar11 & 0x40000) == 0) || ((*(uint *)(lVar4 + 0x2394) & 0x100) != 0)) ||
       (*(int *)(param_1 + 0x10) != 0x37)) {
      if (((uVar11 >> 0x13 & 1) != 0) && ((*(int *)(param_1 + 0x10) - 0x18U & 0xffffffdf) == 0)) {
        uVar10 = uVar7;
        if (*(uint *)(lVar4 + 0xfd8) != 0) {
          plVar12 = *(longlong **)(lVar4 + 0xfe0);
          uVar14 = (ulonglong)*(uint *)(lVar4 + 0xfd8);
          uVar6 = uVar8;
          do {
            lVar2 = *plVar12;
            if (*(int *)(lVar2 + 0x10) == 0x18) {
              uVar8 = (ulonglong)(*(ushort *)(lVar2 + 0x4c) >> 1 & 1);
              if (((uVar11 >> 0x14 & 1) != 0) && (*(int *)(lVar2 + 0x20) != 1)) {
                uVar8 = 0;
              }
            }
            else if ((((*(int *)(lVar2 + 0x10) == 0x38) &&
                      (uVar6 = (ulonglong)(*(ushort *)(lVar2 + 0x4c) >> 1 & 1),
                      (uVar11 >> 0x14 & 1) != 0)) && (1 < *(uint *)(lVar2 + 0x20))) &&
                    (*(uint *)(lVar2 + 0x20) != 0xf)) {
              uVar6 = 0;
            }
            uVar10 = (uint)uVar6;
            uVar7 = (uint)uVar8;
            plVar12 = plVar12 + 1;
            uVar14 = uVar14 - 1;
          } while (uVar14 != 0);
        }
        uVar10 = uVar10 | uVar7;
        if ((uVar11 >> 0x16 & 1) == 0) {
          return uVar10;
        }
        lVar4 = *(longlong *)(lVar4 + 0xe38);
        if (lVar4 == 0) {
          return uVar10;
        }
        if ((uVar11 >> 0x17 & 1) == 0) {
          if ((*(int *)(lVar4 + 0x20) != 0x20) && (*(int *)(lVar4 + 0x20) != 0x32)) {
            return uVar10;
          }
          return uVar10 | *(ushort *)(lVar4 + 0x4c) >> 1 & 1;
        }
        return uVar10;
      }
      if (((*(uint *)(lVar4 + 0x2388) & 1) != 0) &&
         (iVar3 = *(int *)(param_1 + 0x10), (iVar3 - 0x18U & 0xffffffdf) == 0)) {
        uVar11 = uVar7;
        uVar9 = uVar7;
        if (*(uint *)(lVar4 + 0xfd8) != 0) {
          plVar12 = *(longlong **)(lVar4 + 0xfe0);
          uVar6 = (ulonglong)*(uint *)(lVar4 + 0xfd8);
          do {
            lVar4 = *plVar12;
            if (*(int *)(lVar4 + 0x10) == 0x18) {
              uVar8 = (ulonglong)
                      (-(uint)(*(uint *)(lVar4 + 0x20) < 2) & *(ushort *)(lVar4 + 0x4c) >> 1 & 1);
            }
            else if (*(int *)(lVar4 + 0x10) == 0x38) {
              uVar11 = *(ushort *)(lVar4 + 0x4c) >> 1 & 1;
              if ((1 < *(uint *)(lVar4 + 0x20)) && (*(uint *)(lVar4 + 0x20) != 0xf)) {
                uVar11 = uVar7;
              }
            }
            uVar9 = (uint)uVar8;
            plVar12 = plVar12 + 1;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        if (iVar3 != 0x38) {
          if (iVar3 == 0x18) {
            return uVar9;
          }
          return uVar10;
        }
        return uVar11;
      }
    }
    else if ((*(int *)(lVar4 + 0x26b4) != 0x85) && (*(short *)(lVar4 + 0x26a8) != 0x1b9b)) {
      local_res8[0] = 0;
      uVar6 = uVar8;
      uVar14 = uVar8;
      uVar10 = uVar7;
      if (*(int *)(lVar4 + 0xfd8) != 0) {
        do {
          lVar2 = *(longlong *)(uVar14 + *(longlong *)(lVar4 + 0xfe0));
          if (*(int *)(lVar2 + 0x10) == 0x21) {
            FUN_1400283a4(lVar4,*(undefined1 *)(*(longlong *)(lVar2 + 0x18) + 0x260),local_res8);
            lVar4 = *(longlong *)(param_1 + 0x28);
          }
          else if (*(int *)(lVar2 + 0x10) == 0x37) {
            uVar8 = (ulonglong)(*(ushort *)(lVar2 + 0x4c) >> 1 & 1);
          }
          uVar7 = (uint)uVar8;
          uVar11 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar11;
          uVar14 = uVar14 + 8;
          uVar10 = local_res8[0];
        } while (uVar11 < *(uint *)(lVar4 + 0xfd8));
      }
      return uVar10 | uVar7;
    }
    if (*(int *)(param_1 + 0x10) == 0x37) {
      lVar2 = *(longlong *)(param_1 + 0x18);
      uVar16 = 0;
      uVar10 = -(uint)((uVar11 & 0x40000) != 0) & uVar10;
      uVar9 = uVar16;
      uVar15 = uVar16;
      if (*(uint *)(lVar2 + 0x2e8) != 0) {
        plVar12 = *(longlong **)(lVar2 + 0x2f0);
        uVar13 = (ulonglong)*(uint *)(lVar2 + 0x2e8);
        uVar6 = uVar8;
        uVar14 = uVar8;
        uVar17 = uVar8;
        uVar18 = uVar8;
        do {
          lVar5 = *plVar12;
          iVar3 = *(int *)(lVar5 + 0x10);
          if (iVar3 == 0x37) {
            uVar14 = (ulonglong)(*(ushort *)(lVar5 + 0x4c) >> 1 & 1);
          }
          else if (iVar3 == 0x3a) {
            if (((uVar11 >> 0x14 & 1) == 0) && ((*(uint *)(lVar4 + 0x2388) & 1) == 0)) {
              uVar1 = *(ushort *)(lVar5 + 0x4c);
            }
            else {
              lVar5 = *(longlong *)(lVar4 + 0xe60);
              if (((lVar5 == 0) || (*(int *)(lVar5 + 0x20) != 6)) &&
                 ((lVar5 = *(longlong *)(lVar4 + 0xe58), lVar5 == 0 || (*(int *)(lVar5 + 0x20) != 6)
                  ))) goto LAB_140056723;
              uVar1 = *(ushort *)(lVar5 + 0x4c);
            }
            uVar6 = (ulonglong)(uVar1 >> 1 & 1);
          }
          else if (iVar3 == 0x3b) {
            if (((uVar11 >> 0x14 & 1) == 0) && ((*(uint *)(lVar4 + 0x2388) & 1) == 0)) {
              uVar1 = *(ushort *)(lVar5 + 0x4c);
            }
            else {
              lVar5 = *(longlong *)(lVar4 + 0xe48);
              if ((lVar5 == 0) || (*(int *)(lVar5 + 0x20) != 5)) goto LAB_140056723;
              uVar1 = *(ushort *)(lVar5 + 0x4c);
            }
            uVar18 = (ulonglong)(uVar1 >> 1 & 1);
          }
          else if (iVar3 == 0x3c) {
            if ((uVar11 >> 0x15 & 1) == 0) {
              lVar5 = *(longlong *)(lVar4 + 0xe40);
              if (((lVar5 == 0) || (*(int *)(lVar5 + 0x20) != 7)) &&
                 ((lVar5 = *(longlong *)(lVar4 + 0xe50), lVar5 == 0 || (*(int *)(lVar5 + 0x20) != 7)
                  ))) goto LAB_140056723;
              uVar1 = *(ushort *)(lVar5 + 0x4c);
            }
            else {
              uVar1 = *(ushort *)(lVar5 + 0x4c);
            }
            uVar17 = (ulonglong)(uVar1 >> 1 & 1);
          }
LAB_140056723:
          uVar7 = (uint)uVar18;
          uVar15 = (uint)uVar14;
          uVar9 = (uint)uVar6;
          uVar16 = (uint)uVar17;
          plVar12 = plVar12 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      FUN_14003b590(lVar2,0,L"current_channel_number",4,(undefined8 *)(lVar2 + 0x254));
      FUN_14003b590(*(longlong *)(param_1 + 0x18),0,L"channel_config.ActiveSpeakerPositions",4,
                    (undefined8 *)(*(longlong *)(param_1 + 0x18) + 0x24c));
      iVar3 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x254);
      if (iVar3 == 4) {
        uVar10 = uVar10 | uVar7;
      }
      else {
        if (iVar3 != 6) {
          if (iVar3 != 8) goto LAB_14005679e;
          uVar10 = uVar10 | uVar16;
        }
        uVar10 = uVar10 | uVar7 | uVar9;
      }
LAB_14005679e:
      uVar10 = uVar10 | uVar15;
    }
  }
  lVar4 = *(longlong *)(param_1 + 0x28);
  if (param_1 == *(longlong *)(lVar4 + 0xe18)) {
    if ((((char)*(undefined4 *)(lVar4 + 0x2378) < '\0') &&
        (lVar2 = *(longlong *)(lVar4 + 0xe10), lVar2 != 0)) &&
       ((*(byte *)(lVar2 + 0x4c) & 10) == 10)) {
      if (1 < *(int *)(lVar2 + 0xcc) - 1U) {
        return 0;
      }
    }
    else if (((*(int *)(lVar4 + 0x26b0) != 5) ||
             ((*(byte *)(*(longlong *)(lVar4 + 0xe10) + 0x4c) & 2) == 0)) ||
            ((*(int *)(lVar4 + 0x5c) != 0 && (*(int *)(lVar4 + 0x5c) != 1)))) {
      lVar2 = *(longlong *)(lVar4 + 0xe10);
      if ((lVar2 == 0) || ((*(ushort *)(lVar2 + 0x4c) & 2) == 0)) {
        if ((*(uint *)(lVar4 + 0x2380) >> 0x11 & 1) != 0) {
          return 0;
        }
        if ((*(uint *)(lVar4 + 0x2380) >> 0x1a & 1) != 0) {
          return 0;
        }
        return uVar10;
      }
      if ((*(ushort *)(lVar2 + 0x4c) & 8) == 0) {
        if (((*(uint *)(lVar4 + 0x2380) >> 0x11 & 1) == 0) &&
           ((*(uint *)(lVar4 + 0x2380) >> 0x1a & 1) == 0)) {
          return uVar10;
        }
        if (*(longlong *)(lVar4 + 0xb20) == 0) {
          return uVar10;
        }
        iVar3 = (*(code *)PTR__guard_dispatch_icall_14005f458)
                          (*(longlong *)(lVar4 + 0xb20),param_1,local_res8);
        if (-1 < iVar3) {
          if ((local_res8[0] != 1) && (local_res8[0] != 2)) {
            return uVar10;
          }
          return 1;
        }
        return uVar10;
      }
      iVar3 = *(int *)(lVar2 + 0x20);
      if (iVar3 == 0) {
LAB_1400568b6:
        if ((*(uint *)(lVar4 + 0x2374) & 2) != 0) goto LAB_1400568c2;
      }
      else {
        if (iVar3 == 1) {
LAB_14005686b:
          if ((*(uint *)(lVar4 + 0x2380) & 0x20000) == 0) goto LAB_1400568c2;
          if ((((*(short *)(lVar4 + 0xe68) + 0xbfc0U & 0xffed) == 0) &&
              (*(short *)(lVar4 + 0xe68) != 0x4052)) && (*(longlong *)(lVar4 + 0xb20) != 0)) {
            return *(ushort *)(param_1 + 0x4c) >> 1 & 1;
          }
          goto LAB_1400568b6;
        }
        if (iVar3 != 2) {
          if ((((iVar3 != 0x22) && (iVar3 != 0x23)) && (iVar3 != 0x32)) &&
             ((iVar3 != 0x33 && (iVar3 != 0x105)))) {
            return 0;
          }
          goto LAB_14005686b;
        }
      }
      if ((*(uint *)(lVar4 + 0x24c0) & 0x100000) != 0) {
        local_res8[0] = 0;
        if (((*(longlong *)(lVar4 + 0xb20) != 0) &&
            (iVar3 = (*(code *)PTR__guard_dispatch_icall_14005f458)
                               (*(longlong *)(lVar4 + 0xb20),param_1,local_res8), -1 < iVar3)) &&
           ((local_res8[0] == 1 || (uVar8 = 0, local_res8[0] == 2)))) {
          uVar8 = 1;
        }
      }
      goto LAB_1400568c8;
    }
    uVar7 = 1;
  }
  else {
    if (param_1 != *(longlong *)(lVar4 + 0xe10)) {
      return uVar10;
    }
    if ((*(byte *)(param_1 + 0x4c) & 10) != 10) {
      return uVar10;
    }
    uVar7 = *(uint *)(param_1 + 0x20);
    if (uVar7 < 0x33) {
      if ((((uVar7 != 0x32) && (uVar7 != 2)) && (uVar7 != 3)) && (uVar7 != 4)) {
        iVar3 = uVar7 - 0x22;
LAB_1400569f6:
        if ((iVar3 != 0) && (iVar3 != 1)) {
          return 0;
        }
      }
    }
    else if ((uVar7 != 0x33) && (uVar7 != 0x103)) {
      iVar3 = uVar7 - 0x104;
      goto LAB_1400569f6;
    }
LAB_1400568c2:
    uVar8 = (ulonglong)(*(int *)(param_1 + 8) == 0);
LAB_1400568c8:
    uVar7 = (uint)uVar8;
  }
  return uVar7;
}

