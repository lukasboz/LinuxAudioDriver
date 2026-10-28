
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_140053be0(undefined4 *param_1,longlong param_2,uint *param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined8 uVar5;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined4 local_a0;
  uint local_98 [20];
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  ulonglong local_38;
  
  local_38 = DAT_1400698c0 ^ (ulonglong)auStack_c8;
  uVar10 = *param_3;
  puVar13 = param_1 + 0xf;
  local_98[3] = 8;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined8 *)(param_1 + 0xc) = 0;
  param_1[0xe] = 0;
  param_1[0x13] = 0;
  local_98[0] = 0xe;
  local_98[8] = 0xe;
  local_98[2] = 2;
  local_98[9] = 0xe;
  local_98[10] = 0xe;
  uVar4 = param_3[2];
  local_98[0xb] = 0xe;
  local_98[0xc] = 0xe;
  local_98[0xd] = 0xe;
  local_98[0xe] = 0xe;
  uVar11 = param_3[1];
  local_98[7] = 3;
  puVar13[0] = 0;
  puVar13[1] = 0;
  param_1[0x11] = 0;
  uVar14 = uVar10 >> 0x14 & 0xf;
  *(longlong *)(param_1 + 6) = param_2;
  lVar9 = *(longlong *)(param_2 + 0x2d0);
  local_98[0xf] = 0xf;
  local_98[1] = 1;
  local_98[4] = 10;
  local_98[5] = 9;
  local_98[6] = 0xb;
  local_a8 = CONCAT44(uVar11,uVar10);
  *(longlong *)(param_1 + 10) = lVar9;
  param_1[4] = (uVar10 >> 0x1e) * 0x10 + (uVar10 >> 0x10 & 0xf);
  if (uVar14 == 0) {
    uVar10 = uVar10 & 0xff1fffff | 0x100000;
LAB_140053e16:
    *(undefined4 *)(param_2 + 0x330) = 1;
LAB_140053e1d:
    local_a8 = CONCAT44(uVar11,uVar10);
  }
  else {
    if (uVar14 == 3) {
      *(undefined4 *)(param_2 + 0x33c) = 1;
      uVar10 = uVar10 & 0xff1fffff | 0x100000;
      goto LAB_140053e1d;
    }
    if (uVar14 == 5) {
      uVar10 = uVar10 & 0xff2fffff | 0x200000;
      goto LAB_140053e16;
    }
    if (uVar14 == 9) {
      uVar3 = CONCAT44(uVar11,uVar10) & 0xffffffffff8fffff;
      local_a8 = uVar3 | 0x800000;
      if ((*(int *)(lVar9 + 0x26b4) == 0x84) ||
         (uVar11 = uVar10 & 0xff8fffff | 0x800000, *(int *)(lVar9 + 0x26b4) == 0x85)) {
        local_a8._4_4_ = (undefined4)(uVar3 >> 0x20);
        local_a8 = CONCAT44(local_a8._4_4_,uVar10) & 0xffffffffff8fffff | 0x900000;
        uVar11 = uVar10 & 0xff8fffff | 0x900000;
      }
      uVar10 = uVar11;
      *(uint *)(lVar9 + 0x2374) = *(uint *)(lVar9 + 0x2374) | 0x20;
      *(undefined4 *)(*(longlong *)(param_1 + 6) + 0x330) = 1;
    }
    else {
      if (uVar14 != 10) {
        if (uVar14 == 0xb) {
          iVar8 = *(int *)(lVar9 + 0x26b0);
          if ((((iVar8 == 0x42) || (iVar8 == 0x92)) || (iVar8 == 0xa3)) ||
             (((iVar8 == 0xb1 || (iVar8 == 0xb3)) || (iVar8 == 0xb4)))) {
            uVar10 = uVar10 & 0xffbfffff | 0xb00000;
          }
          else {
            uVar10 = uVar10 & 0xffafffff | 0xa00000;
          }
          *(uint *)(lVar9 + 0x2374) = *(uint *)(lVar9 + 0x2374) | 0x20;
          *(undefined4 *)(*(longlong *)(param_1 + 6) + 0x330) = 1;
        }
        else {
          if (uVar14 != 0xc) goto LAB_140053e22;
          uVar10 = uVar10 & 0xffafffff | 0xa00000;
          *(uint *)(lVar9 + 0x2374) = *(uint *)(lVar9 + 0x2374) | 0x20;
          *(undefined4 *)(*(longlong *)(param_1 + 6) + 0x340) = 1;
        }
        goto LAB_140053e1d;
      }
      if ((*(int *)(lVar9 + 0x26b0) == 0xbc) || (*(int *)(lVar9 + 0x26b4) == 0xcb)) {
        *(undefined4 *)(param_2 + 0x344) = 1;
      }
    }
  }
LAB_140053e22:
  if (*(short *)(*(longlong *)(param_1 + 10) + 0xe68) == 0x5651) {
    *param_1 = 1;
  }
  uVar11 = 0;
  *(ulonglong *)(param_1 + 0xc) = local_a8;
  puVar1 = param_1 + 8;
  param_1[0xe] = uVar4;
  iVar8 = (uVar10 >> 0x1e) * 0x10 + (uVar10 >> 0x10 & 0xf);
  param_1[4] = iVar8;
  if ((param_1[0xc] & 0x30000000) == 0x10000000) {
    uVar11 = 0x80000000;
  }
  param_1[0xc] = uVar11 | param_1[0xc] & 0x3ff1ffff | 0x10000;
  *(undefined8 *)puVar13 = *(undefined8 *)(param_1 + 0xc);
  param_1[0x11] = param_1[0xe];
  uVar5 = FUN_14004c75c(*(longlong *)(*(longlong *)(param_1 + 10) + 0x150),iVar8,puVar1);
  if ((int)uVar5 < 0) {
    local_a8 = *(ulonglong *)(param_1 + 0xc);
    local_a0 = param_1[0xe];
    iVar8 = FUN_140055f24(param_1,(uint *)&local_a8);
    param_1[8] = iVar8;
  }
  else {
    FUN_140055f90(param_1,puVar13,param_1[8]);
  }
  lVar9 = *(longlong *)(param_1 + 10);
  uVar4 = *(uint *)(lVar9 + 0xe6c);
  local_98[0x10] = local_98[(ulonglong)uVar4 & 0xf];
  local_98[0x11] = local_98[(ulonglong)(uVar4 >> 4) & 0xf];
  local_98[0x12] = local_98[(ulonglong)(uVar4 >> 8) & 0xf];
  local_98[0x13] = local_98[(ulonglong)(uVar4 >> 0xc) & 0xf];
  local_48 = local_98[(ulonglong)(uVar4 >> 0x10) & 0xf];
  local_44 = local_98[(ulonglong)(uVar4 >> 0x14) & 0xf];
  local_40 = local_98[(ulonglong)(uVar4 >> 0x18) & 0xf];
  local_3c = local_98[uVar4 >> 0x1c];
  param_1[0x1c] = param_1[0xc];
  uVar6 = ((ushort)(uVar10 >> 10) & 1) << 3 | ~(ushort)((uint)param_1[0xc] >> 8) & 1 |
          *(ushort *)(param_1 + 0x13) & 0xfff6;
  uVar6 = (~uVar6 * 2 ^ uVar6) & 2 ^ uVar6;
  uVar6 = (((ushort)(*puVar13 >> 0x14) & 0xf | 0x10) << 3 | uVar6 & 2) * 2 | uVar6 & 0xff0b;
  *(ushort *)(param_1 + 0x13) = uVar6;
  param_1[0x12] = (-(uint)((uVar10 & 0x100) != 0) & 0xfffc0000) + 0x80000;
  if ((uVar6 & 8) != 0) {
    *(uint *)(lVar9 + 0x2390) = *(uint *)(lVar9 + 0x2390) | 0x200;
    lVar9 = *(longlong *)(param_1 + 10);
  }
  uVar4 = uVar10 >> 0x14 & 0xf;
  if (uVar4 == 1) {
    if ((*(ushort *)(param_1 + 0x13) & 8) != 0) {
      if (((*(short *)(lVar9 + 0x26aa) == 0xbda) &&
          (uVar6 = *(short *)(lVar9 + 0x26a8) + 0xbfec, uVar6 < 0x1b)) &&
         ((0x4000005U >> (uVar6 & 0x1f) & 1) != 0)) {
        *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) & 0xfffb;
      }
      else {
        *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 4;
      }
    }
    if ((*(uint *)(lVar9 + 0x2384) & 0x400) != 0) {
      if (param_1[4] == 0x37) {
        *(ushort *)(param_1 + 0x13) = *(ushort *)(param_1 + 0x13) & 0xfeff;
      }
      uVar4 = *puVar1;
      if ((uVar4 != 3) && (uVar4 != 4)) {
        if (uVar4 == 5) {
          *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 0x20;
          goto LAB_140054450;
        }
        if (uVar4 == 6) {
          *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 0x40;
          goto LAB_140054450;
        }
        if (uVar4 == 7) {
          *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 0x80;
          goto LAB_140054450;
        }
      }
    }
    *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 0x10;
    goto LAB_140054450;
  }
  if (uVar4 == 2) {
    if (param_1[4] != 0x1f) {
      *(undefined4 **)(lVar9 + 0xe20) = param_1;
      uVar6 = *(ushort *)((longlong)param_1 + 0x4e);
      uVar7 = uVar6 | 4;
      *(ushort *)((longlong)param_1 + 0x4e) = uVar7;
      if ((*(byte *)(param_1 + 0x13) & 8) != 0) {
        uVar7 = uVar6 | 0x14;
        *(ushort *)((longlong)param_1 + 0x4e) = uVar7;
      }
      lVar9 = *(longlong *)(param_1 + 10);
      iVar8 = *(int *)(lVar9 + 0x26b4);
      if (iVar8 == 0x92) {
        uVar7 = uVar7 & 0xffef;
        *(ushort *)((longlong)param_1 + 0x4e) = uVar7;
        iVar8 = *(int *)(lVar9 + 0x26b4);
      }
      if ((iVar8 == 0x80) || (iVar8 == 0x81)) {
        *(ushort *)((longlong)param_1 + 0x4e) = uVar7 & 0xffef | 0x80;
        *(undefined4 **)(lVar9 + 0xe50) = param_1;
        lVar9 = *(longlong *)(param_1 + 10);
      }
      if ((((*(int *)(lVar9 + 0x26b4) - 0xc9U < 2) || (*(int *)(lVar9 + 0x26b4) == 0x85)) ||
          (*(short *)(lVar9 + 0x26a8) == 0x1b9b)) &&
         ((*(ushort *)((longlong)param_1 + 0x4e) =
                *(ushort *)((longlong)param_1 + 0x4e) & 0xffef | 0x80,
          *(int *)(lVar9 + 0x26b4) == 0x85 || (*(short *)(lVar9 + 0x26a8) == 0x1b9b)))) {
        *(undefined4 **)(lVar9 + 0xe50) = param_1;
      }
      goto LAB_140054450;
    }
    *(undefined4 **)(lVar9 + 0xe38) = param_1;
    uVar6 = *(ushort *)((longlong)param_1 + 0x4e);
    uVar10 = uVar10 & 0xff2fffff | 0x200000;
    *(ushort *)((longlong)param_1 + 0x4e) = uVar6 | 4;
    if ((*(byte *)(param_1 + 0x13) & 8) != 0) {
      *(ushort *)((longlong)param_1 + 0x4e) = uVar6 | 0x404;
    }
    uVar11 = 0xfffcffff;
    uVar4 = 0xc0000;
  }
  else {
    if (uVar4 != 4) {
      if (uVar4 == 8) {
        uVar6 = *(ushort *)((longlong)param_1 + 0x4e);
        uVar7 = uVar6 | 1;
        *(ushort *)((longlong)param_1 + 0x4e) = uVar7;
        if ((*(byte *)(param_1 + 0x13) & 8) == 0) goto LAB_140054450;
        if ((uVar10 >> 0xb & 1) != 0) {
          uVar7 = uVar6 | 3;
          *(ushort *)((longlong)param_1 + 0x4e) = uVar7;
        }
        if ((*(uint *)(lVar9 + 0x2384) & 0x400) != 0) {
          uVar7 = uVar7 | 0x80;
          *(ushort *)((longlong)param_1 + 0x4e) = uVar7;
        }
        if (1 < *(int *)(lVar9 + 0x26b4) - 0x84U) goto LAB_140054450;
        uVar6 = uVar7 & 0xff7f | 0x42;
      }
      else {
        if (uVar4 == 9) {
          if (((*(uint *)(lVar9 + 0x2384) & 0x400) != 0) || (*(int *)(lVar9 + 0x26b4) == 0x92)) {
            *(undefined4 **)(lVar9 + 0xe28) = param_1;
            lVar9 = *(longlong *)(param_1 + 10);
          }
          uVar7 = *(ushort *)((longlong)param_1 + 0x4e);
          *(ushort *)((longlong)param_1 + 0x4e) = uVar7 | 2;
          if ((*(byte *)(param_1 + 0x13) & 8) == 0) goto LAB_140054450;
          uVar6 = uVar7 | 3;
          *(ushort *)((longlong)param_1 + 0x4e) = uVar6;
          if ((*(uint *)(lVar9 + 0x2384) & 0x100000) == 0) {
            if ((*(uint *)(lVar9 + 0x2388) & 1) != 0) {
              uVar6 = uVar7 & 0xfffe | 2;
              goto LAB_1400541da;
            }
          }
          else {
LAB_1400541da:
            uVar6 = uVar6 | 0x20;
            *(ushort *)((longlong)param_1 + 0x4e) = uVar6;
          }
          uVar4 = *(int *)(lVar9 + 0x26b4) - 0x84;
LAB_1400541ee:
          if (1 < uVar4) goto LAB_140054450;
        }
        else {
          if (uVar4 != 10) {
            if (uVar4 != 0xb) goto LAB_140054450;
            if (((*(uint *)(lVar9 + 0x2384) & 0x400) != 0) || (*(int *)(lVar9 + 0x26b4) == 0x92)) {
              *(undefined4 **)(lVar9 + 0xe28) = param_1;
              lVar9 = *(longlong *)(param_1 + 10);
            }
            uVar6 = *(ushort *)((longlong)param_1 + 0x4e);
            *(ushort *)((longlong)param_1 + 0x4e) = uVar6 | 2;
            if ((*(byte *)(param_1 + 0x13) & 8) == 0) goto LAB_140054450;
            *(ushort *)((longlong)param_1 + 0x4e) = uVar6 | 3;
            if ((*(uint *)(lVar9 + 0x2384) & 0x100000) != 0) {
              uVar6 = uVar6 | 0x23;
              goto LAB_1400541fb;
            }
            if ((*(uint *)(lVar9 + 0x2388) & 1) == 0) goto LAB_140054450;
            uVar6 = uVar6 & 0xfffe | 0x22;
            *(ushort *)((longlong)param_1 + 0x4e) = uVar6;
            if (*(int *)(lVar9 + 0x26b4) == 0x84) goto LAB_1400541f7;
            uVar4 = *(int *)(lVar9 + 0x26b4) - 0xc9;
            goto LAB_1400541ee;
          }
          *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 2;
          if ((*(uint *)(lVar9 + 0x2384) & 0x400) != 0) {
            *(undefined4 **)(lVar9 + 0xe30) = param_1;
            lVar9 = *(longlong *)(param_1 + 10);
          }
          if ((*(byte *)(param_1 + 0x13) & 8) == 0) goto LAB_140054450;
          if ((*(uint *)(lVar9 + 0x2384) & 0x100000) != 0) {
            *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 0x40;
            *(undefined4 **)(lVar9 + 0xe60) = param_1;
            goto LAB_140054450;
          }
          uVar6 = *(ushort *)((longlong)param_1 + 0x4e);
          if ((*(uint *)(lVar9 + 0x2388) & 1) != 0) {
            *(ushort *)((longlong)param_1 + 0x4e) = uVar6 | 0x40;
            *(undefined4 **)(lVar9 + 0xe60) = param_1;
            if (*(int *)(*(longlong *)(param_1 + 10) + 0x26b4) - 0xc9U < 2) {
              *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 1;
            }
            goto LAB_140054450;
          }
        }
LAB_1400541f7:
        uVar6 = uVar6 | 1;
      }
LAB_1400541fb:
      *(ushort *)((longlong)param_1 + 0x4e) = uVar6;
      goto LAB_140054450;
    }
    param_1[0x12] = 0x700;
    *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 0x100;
    uVar11 = 0xfff5ffff;
    uVar4 = 0x50000;
  }
  param_1[0xc] = param_1[0xc] & uVar11 | uVar4;
  *puVar13 = *puVar13 & uVar11 | uVar4;
LAB_140054450:
  iVar8 = 0;
  puVar13 = local_98 + 0x10;
  iVar12 = 0x30000;
  do {
    uVar4 = *puVar13;
    if (uVar14 == uVar4) {
      lVar9 = *(longlong *)(param_1 + 10);
      if ((*(uint *)(lVar9 + 0x2384) & 0x400) != 0) {
        if (uVar4 == 8) {
          if ((uVar10 & 0xf00000) == 0x800000) {
            *(undefined4 **)(lVar9 + 0xe40) = param_1;
          }
        }
        else if (uVar4 == 0xb) {
          if ((uVar10 & 0xf00000) == 0xb00000) {
            *(undefined4 **)(lVar9 + 0xe48) = param_1;
          }
        }
        else if (((uVar4 == 10) && (*(int *)(lVar9 + 0x26b4) - 0x84U < 2)) &&
                ((uVar10 & 0xf00000) == 0xa00000)) {
          *(undefined4 **)(lVar9 + 0xe58) = param_1;
          *(undefined8 *)(*(longlong *)(param_1 + 10) + 0xe60) = 0;
        }
      }
      param_1[0x12] = (iVar8 + 0x300) * 0x100;
      break;
    }
    if (uVar4 == 0xf) {
      uVar4 = uVar10 >> 0x14 & 0xf;
      if ((uVar4 == 1) || (uVar4 == 2)) {
        if ((uVar4 != 1) || (*(int *)(*(longlong *)(param_1 + 10) + 0x26b0) == 0x2d)) {
          *(undefined4 **)(*(longlong *)(param_1 + 10) + 0xe10) = param_1;
          *(uint *)(*(longlong *)(param_1 + 10) + 0x24ec) =
               *(uint *)(*(longlong *)(param_1 + 10) + 0x24ec) | 1;
          *(uint *)(*(longlong *)(param_1 + 10) + 0x2378) =
               *(uint *)(*(longlong *)(param_1 + 10) + 0x2378) | 4;
          lVar9 = *(longlong *)(param_1 + 10);
          iVar2 = param_1[0x12];
          if ((*(uint *)(lVar9 + 0x2384) & 0x2000) == 0) {
            iVar2 = iVar12;
          }
          param_1[0x12] = iVar2;
          if ((*(byte *)(param_1 + 0x13) & 8) != 0) {
            if ((*(uint *)(lVar9 + 0x24c0) & 0x100000) == 0) {
              uVar6 = *(ushort *)((longlong)param_1 + 0x4e);
              if ((*(uint *)(lVar9 + 0x2374) & 2) != 0) {
                uVar6 = uVar6 | 3;
              }
              uVar7 = uVar6 | 0x1000;
              *(ushort *)((longlong)param_1 + 0x4e) = uVar7;
              if ((*(int *)(lVar9 + 0x26b0) == 0x2d) && (*(char *)(lVar9 + 0xcb1) == '\0')) {
                uVar7 = uVar6 & 0xeffc;
                *(ushort *)((longlong)param_1 + 0x4e) = uVar7;
              }
              if (*(int *)(lVar9 + 0x26b4) == 0x92) {
                *(ushort *)((longlong)param_1 + 0x4e) = uVar7 & 0xfffc;
              }
            }
            else if ((*(int *)(lVar9 + 0x26b0) != 0xb0) && ((*(uint *)(lVar9 + 0x2374) & 2) != 0)) {
              *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 3;
            }
          }
          if ((*(uint *)(lVar9 + 0x2380) & 0x4020000) != 0) {
            *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 0x400;
            *puVar1 = 0x32;
          }
        }
      }
      else if ((((uVar4 == 10) && (lVar9 = *(longlong *)(param_1 + 6), *(int *)(lVar9 + 0x330) == 0)
                ) && (*(int *)(lVar9 + 0x334) == 0)) && (*(int *)(lVar9 + 0x340) == 0)) {
        *(undefined4 **)(*(longlong *)(param_1 + 10) + 0xe18) = param_1;
        if ((*(uint *)(*(longlong *)(param_1 + 10) + 0x2374) & 2) != 0) {
          *(ushort *)((longlong)param_1 + 0x4e) = *(ushort *)((longlong)param_1 + 0x4e) | 3;
        }
        param_1[0x12] = 0x80000;
      }
    }
    iVar8 = iVar8 + 1;
    iVar12 = iVar12 + 0x100;
    puVar13 = puVar13 + 1;
  } while (iVar12 < 0x30800);
  if (param_4 != 0) {
    param_1[0x12] = param_4;
  }
  if (*(longlong *)(*(longlong *)(param_1 + 10) + 0xb18) != 0) {
    (*(code *)PTR__guard_dispatch_icall_14005f458)
              (*(longlong *)(*(longlong *)(param_1 + 10) + 0xb18),param_1);
  }
  param_1[0x32] = 1;
  FUN_14005470c((longlong)param_1,*puVar1);
  return param_1;
}

