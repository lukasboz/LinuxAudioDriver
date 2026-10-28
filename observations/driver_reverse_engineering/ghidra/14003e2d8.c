
undefined8 * FUN_14003e2d8(undefined8 *param_1,longlong param_2)

{
  uint *puVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  char cVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  ulonglong uVar13;
  longlong lVar14;
  int iVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  bool bVar22;
  char local_res8 [8];
  byte local_res10 [8];
  ulonglong local_res18;
  uint local_res20;
  ulonglong local_68;
  ulonglong local_58;
  
  uVar16 = 0;
  *param_1 = &PTR_FUN_1400611c8;
  param_1[1] = param_2;
  uVar8 = *(uint *)(param_2 + 0x26b0);
  local_res18 = local_res18 & 0xffffffff00000000;
  iVar15 = 9;
  iVar9 = 0;
  if (uVar8 < 0x3f) {
    if (uVar8 == 0x3e) {
      *(uint *)(param_2 + 0x2384) = *(uint *)(param_2 + 0x2384) | 4;
      *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x40;
      *(undefined2 *)(param_1[1] + 0xc0) = 0x7e3;
      *(undefined2 *)(param_1[1] + 0xc2) = 3;
      *(undefined2 *)(param_1[1] + 0xc4) = 0x1f;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x40;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
      lVar11 = param_1[1];
      *(undefined8 *)(lVar11 + 0xe70) = 0x40a80110;
      *(undefined4 *)(lVar11 + 0xe78) = 0;
      local_58 = 0x40370120;
LAB_14003eee1:
      lVar11 = param_1[1];
      *(ulonglong *)(lVar11 + 0xe7c) = local_58;
      *(undefined4 *)(lVar11 + 0xe84) = 0;
      return param_1;
    }
    if (uVar8 < 0x24) {
      if (uVar8 == 0x23) {
LAB_14003f26b:
        *(undefined2 *)(param_2 + 0xe68) = 0x4042;
LAB_14003f278:
        lVar11 = param_1[1];
        goto LAB_14003f27c;
      }
      if (uVar8 < 0x10) {
        if (uVar8 == 0xf) {
          *(uint *)(param_2 + 0x2384) = *(uint *)(param_2 + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
          do {
            uVar8 = (int)uVar16 + 1;
            uVar16 = (ulonglong)uVar8;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | uVar8;
          } while ((int)uVar8 < 2);
          *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
          *(undefined4 *)(param_1[1] + 0xadc) = 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x50a80110;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x40370130;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff1 | 1;
          lVar11 = param_1[1];
          uVar8 = *(uint *)(lVar11 + 0xe6c) & 0xffffff6f | 0x60;
          goto LAB_14003eb3f;
        }
        if (uVar8 < 9) {
          if (uVar8 != 8) {
            if (uVar8 == 1) {
LAB_14003e56f:
              FUN_1400285e4(param_2);
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) & 0xffbfffff;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) & 0xffffffbf;
              *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xfffffdff;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
              *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) | 0x100;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe7c) = 0x421a3020;
              *(undefined4 *)(lVar11 + 0xe84) = 0;
              *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) | 0x100;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
              *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
              lVar11 = param_1[1];
              if ((*(uint *)(lVar11 + 0x237c) & 1) != 0) {
                *(uint *)(lVar11 + 0x237c) = *(uint *)(lVar11 + 0x237c) | 2;
                *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
                *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffdff;
                *(undefined4 *)(param_1[1] + 0xad8) = 0x24;
                *(undefined4 *)(param_1[1] + 0xadc) = 0xc;
                lVar11 = param_1[1];
              }
              *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) | 0x200;
              FUN_14004c5d4((undefined8 *)(param_1[1] + 0xd8),FUN_1400311c0,param_1[1],4000,0);
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffff7;
              return param_1;
            }
            if (uVar8 == 2) {
LAB_14003e493:
              *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
              *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              lVar11 = param_1[1];
              *(undefined4 *)(lVar11 + 0xe7c) = 0x82211c20;
              *(undefined8 *)(lVar11 + 0xe80) = 0;
              *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xfffffbff;
              *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
              *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
              lVar11 = param_1[1];
              if ((*(uint *)(lVar11 + 0x237c) & 1) != 0) {
                *(uint *)(lVar11 + 0x2374) = *(uint *)(lVar11 + 0x2374) | 0x200;
                *(undefined4 *)(param_1[1] + 0xad8) = 0x24;
                *(undefined4 *)(param_1[1] + 0xadc) = 0xc;
                lVar11 = param_1[1];
              }
              *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) | 0x200;
              return param_1;
            }
            if (uVar8 == 3) goto LAB_14003e56f;
            if (uVar8 == 4) goto LAB_14003e493;
            if (uVar8 == 6) {
              *(undefined2 *)(param_2 + 0xe68) = 0x4040;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              lVar11 = param_1[1];
              *(undefined4 *)(lVar11 + 0xe7c) = 0x82211c20;
              *(undefined8 *)(lVar11 + 0xe80) = 0;
              *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xfffffbff;
              *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
              *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
              *(undefined4 *)(param_1[1] + 0xad8) = 0x24;
              *(undefined4 *)(param_1[1] + 0xadc) = 0xc;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) & 0xfff7ffff;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x200;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
              lVar11 = param_1[1];
              goto LAB_14003e481;
            }
            goto LAB_140043e58;
          }
          *(undefined2 *)(param_2 + 0xe68) = 0x4050;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x40a80010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x40c20120;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe88) = 0x80210030;
          *(undefined4 *)(lVar11 + 0xe90) = 0;
        }
        else {
          if (uVar8 == 9) {
            FUN_1400304b8(param_2,0x4040,1,0,1,1);
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe70) = 0x40a80010;
            *(undefined4 *)(lVar11 + 0xe78) = 0;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe7c) = 0x40c20120;
            *(undefined4 *)(lVar11 + 0xe84) = 0;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe88) = 0x80210030;
            *(undefined4 *)(lVar11 + 0xe90) = 0;
            goto LAB_140044fea;
          }
          if (uVar8 == 0xb) {
            *(undefined2 *)(param_2 + 0xe68) = 0x4050;
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          }
          else {
            if (uVar8 != 0xc) {
              if (uVar8 == 0xd) goto LAB_14004163d;
              if (uVar8 == 0xe) {
                *(uint *)(param_2 + 0x2384) = *(uint *)(param_2 + 0x2384) & 0xfffffffb;
                *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
                *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
                *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
                *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
                *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
                *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffffe;
                *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 2;
                *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x2000000;
                *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffdff;
                *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
                *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
                *(undefined4 *)(param_1[1] + 0xadc) = 1;
                *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
                lVar11 = param_1[1];
                *(undefined8 *)(lVar11 + 0xe70) = 0x50c20110;
                *(undefined4 *)(lVar11 + 0xe78) = 0;
                lVar11 = param_1[1];
                *(undefined8 *)(lVar11 + 0xe7c) = 0x40a80020;
                *(undefined4 *)(lVar11 + 0xe84) = 0;
                lVar11 = param_1[1];
                *(undefined8 *)(lVar11 + 0xe88) = 0x40370130;
                *(undefined4 *)(lVar11 + 0xe90) = 0;
                lVar11 = param_1[1];
                *(undefined8 *)(lVar11 + 0xe94) = 0x82211840;
                *(undefined4 *)(lVar11 + 0xe9c) = 0;
                *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff1 | 1;
                *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff6f | 0x60;
                *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf00;
                *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xfffffbff;
                *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
                *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
                *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffffd;
                *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x2000;
                iVar15 = *(int *)(param_1[1] + 0x26b4);
                if ((iVar15 != 0x11) && (iVar15 != 0x12)) {
                  return param_1;
                }
                *(undefined2 *)(param_1[1] + 0xe68) = 0x4050;
                *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xfffffffd;
                *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffdff;
                goto LAB_14003e951;
              }
              goto LAB_140043e58;
            }
            *(undefined2 *)(param_2 + 0xe68) = 0x4032;
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          }
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x40a80010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x80210020;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
        }
LAB_14003e756:
        lVar11 = param_1[1];
        goto LAB_140044fee;
      }
      if (uVar8 < 0x1d) {
        if (uVar8 == 0x1c) {
          FUN_1400304b8(param_2,0x4050,1,0,0,1);
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x40a80010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          local_58 = 0x80210020;
          goto LAB_14003eee1;
        }
        if (uVar8 == 0x13) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x8000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x80000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x40a80010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x80210020;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          goto LAB_140044fea;
        }
        if (uVar8 == 0x14) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4050;
          *(undefined4 *)(param_1[1] + 0xe6c) = 0;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x41893010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          *(undefined4 *)(param_1[1] + 0xf30) = 0x30100;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x41a89020;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          *(undefined4 *)(param_1[1] + 0xf34) = 0x30500;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe88) = 0xc1174030;
          *(undefined4 *)(lVar11 + 0xe90) = 0;
          *(undefined4 *)(param_1[1] + 0xf38) = 0x30300;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffff7;
          goto LAB_14003ec24;
        }
        if (uVar8 == 0x15) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4050;
          *(undefined4 *)(param_1[1] + 0xe6c) = 0;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          *(undefined4 *)(param_1[1] + 0xf30) = 0x80000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0xc2174120;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          *(undefined4 *)(param_1[1] + 0xf34) = 0x80000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe88) = 0x82211030;
          *(undefined4 *)(lVar11 + 0xe90) = 0;
          *(undefined4 *)(param_1[1] + 0xf38) = 0x30000;
        }
        else {
          if ((uVar8 != 0x16) && (uVar8 != 0x1a)) goto LAB_140043e58;
          FUN_1400304b8(param_2,0x4032,1,0,0,1);
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
          *(undefined4 *)(param_1[1] + 0xe6c) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          *(undefined4 *)(param_1[1] + 0xf30) = 0x80000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x82211020;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          *(undefined4 *)(param_1[1] + 0xf34) = 0x30000;
        }
        *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
LAB_14003ec24:
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x80000;
        *(undefined4 *)(param_1[1] + 0xbf0) = 1;
        return param_1;
      }
      if (uVar8 == 0x1e) {
        *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
        *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
        return param_1;
      }
      if (uVar8 == 0x1f) {
        *(undefined2 *)(param_2 + 0xe68) = 0x4042;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x200;
        return param_1;
      }
      if (uVar8 == 0x20) {
        *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
        *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
        lVar11 = param_1[1];
        *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
        *(undefined4 *)(lVar11 + 0xe78) = 0;
        *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) | 0x100;
        lVar11 = param_1[1];
        *(undefined8 *)(lVar11 + 0xe7c) = 0x421a3020;
        *(undefined4 *)(lVar11 + 0xe84) = 0;
        *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) | 0x100;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x40;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x10000000;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 1;
        return param_1;
      }
      if (uVar8 == 0x21) {
        *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 0x80000;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
        *(undefined2 *)(param_1[1] + 0xe68) = 0x4042;
        lVar11 = param_1[1];
        *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
        *(undefined4 *)(lVar11 + 0xe78) = 0;
        *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) | 0x100;
        lVar11 = param_1[1];
        *(undefined8 *)(lVar11 + 0xe7c) = 0x421a3020;
        *(undefined4 *)(lVar11 + 0xe84) = 0;
        *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) | 0x100;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x40;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 2;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
        iVar9 = 1;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 1;
        *(undefined4 *)(param_1[1] + 0x1fc8) = 0x18;
        *(undefined4 *)(param_1[1] + 0x1fcc) = 6;
        lVar11 = 0x1fe0;
        lVar12 = 0x1fd0;
        *(undefined4 *)(param_1[1] + 0x1fc4) = 48000;
        do {
          *(int *)(lVar12 + param_1[1]) = iVar15;
          iVar15 = iVar15 + 1;
          lVar12 = lVar12 + 4;
        } while (lVar12 < 0x1fe0);
        do {
          *(int *)(lVar11 + param_1[1]) = iVar9;
          iVar9 = iVar9 + 1;
          lVar11 = lVar11 + 4;
        } while (lVar11 < 0x1fe8);
        return param_1;
      }
      if (uVar8 == 0x22) {
        *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 0x80000;
        *(undefined2 *)(param_1[1] + 0xe68) = 0x4042;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
        *(undefined4 *)(param_1[1] + 0x2488) = 0x15;
        *(undefined4 *)(param_1[1] + 0x2498) = 600;
        *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) | 8;
        *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) & 0xffffbfff;
        *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) & 0xfffffbff;
        *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) & 0xffffffef;
        *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) | 0x20;
        return param_1;
      }
    }
    else {
      if (uVar8 < 0x34) {
        if (uVar8 == 0x33) {
LAB_14003f764:
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
        }
        else {
          if (0x2d < uVar8) {
            if (uVar8 == 0x2e) {
              FUN_1400304b8(param_2,0x4050,1,0,1,1);
              *(undefined2 *)(param_1[1] + 0x26ac) = 0x1028;
              *(undefined4 *)(param_1[1] + 0x25a4) = 1;
              lVar11 = param_1[1];
              *(undefined4 *)(lVar11 + 0xe70) = 0xc1174210;
              *(undefined8 *)(lVar11 + 0xe74) = 0;
              *(undefined4 *)(param_1[1] + 0xf30) = 0x30000;
              *(uint *)(param_1[1] + 0x1004) = *(uint *)(param_1[1] + 0x1004) | 0x200;
              *(undefined4 *)(param_1[1] + 0x1034) = 1;
              return param_1;
            }
            if (uVar8 == 0x2f) {
              FUN_1400304b8(param_2,0x4050,1,0,1,1);
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x800;
              *(undefined4 *)(param_1[1] + 0x25a4) = 1;
              *(uint *)(param_1[1] + 0x2434) = *(uint *)(param_1[1] + 0x2434) | 0x10000000;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 2;
              lVar11 = param_1[1];
              if ((*(uint *)(lVar11 + 0x2374) & 2) == 0) {
                *(uint *)(lVar11 + 0x2380) = *(uint *)(lVar11 + 0x2380) | 0x20000;
              }
              else {
                *(uint *)(lVar11 + 0x2374) = *(uint *)(lVar11 + 0x2374) | 1;
              }
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x42a80010;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              *(undefined4 *)(param_1[1] + 0xf30) = 0x80000;
              lVar11 = param_1[1];
              local_58 = (ulonglong)((*(uint *)(lVar11 + 0x2374) & 2) << 9) | 0x82210020;
              *(ulonglong *)(lVar11 + 0xe7c) = local_58;
              *(undefined4 *)(lVar11 + 0xe84) = 0;
              *(undefined4 *)(param_1[1] + 0xf34) = 0x30000;
              goto LAB_140044fea;
            }
            if (uVar8 == 0x30) {
              *(undefined2 *)(param_2 + 0xe68) = 0x4042;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
              *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
              *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
              FUN_140029788(param_1[1]);
              FUN_140029cac(param_1[1]);
              FUN_140027fb8(param_1[1]);
              return param_1;
            }
            if (uVar8 == 0x31) goto LAB_14003f26b;
            if (uVar8 != 0x32) goto LAB_140043e58;
            goto LAB_14003f764;
          }
          if (uVar8 == 0x2d) {
            FUN_1400304b8(param_2,0x4050,1,0,1,1);
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x800;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 2;
            *(undefined2 *)(param_1[1] + 0x26ac) = 0x1028;
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x8000;
            local_res8[0] = '\0';
            local_res10[0] = 0;
            lVar11 = param_1[1];
            if (*(ushort *)(lVar11 + 0x2754) < 0x11) {
              *(undefined1 *)(lVar11 + 0xcb1) = 1;
              if (*(uint *)(lVar11 + 0x38) < 4) {
                *(undefined1 *)(param_1[1] + 0xcb6) = 0;
                *(undefined1 *)(param_1[1] + 0xcb8) = 2;
LAB_14003f557:
                *(undefined1 *)(param_1[1] + 0xcb0) = 3;
                goto LAB_14003f566;
              }
              *(undefined1 *)(param_1[1] + 0xcb6) = 2;
              lVar11 = param_1[1];
            }
            else {
              FUN_14002ebb0(lVar11,0xfec6,local_res8);
              cVar5 = local_res8[0];
              FUN_14002ebb0(param_1[1],0xfec7,local_res10);
              if (-1 < cVar5) {
                local_res18._0_4_ = 0;
                if (-1 < cVar5) {
                  *(undefined1 *)(param_1[1] + 0xcb1) = 0;
                  *(undefined1 *)(param_1[1] + 0xcb6) = 0;
                  local_res18._0_4_ = 0;
                  if ((local_res10[0] & 1) == 0) {
                    *(undefined1 *)(param_1[1] + 0xcb8) = 0;
                    *(undefined1 *)(param_1[1] + 0xcb0) = 1;
                  }
                  else {
                    *(undefined1 *)(param_1[1] + 0xcb8) = 1;
                    *(undefined1 *)(param_1[1] + 0xcb0) = 2;
                  }
                }
                goto LAB_14003f566;
              }
              *(undefined1 *)(param_1[1] + 0xcb1) = 1;
              *(undefined1 *)(param_1[1] + 0xcb6) = 2;
              lVar11 = param_1[1];
              if ((local_res10[0] & 1) == 0) {
                *(undefined1 *)(lVar11 + 0xcb8) = 0;
                goto LAB_14003f557;
              }
            }
            *(undefined1 *)(lVar11 + 0xcb8) = 3;
            *(undefined1 *)(param_1[1] + 0xcb0) = 4;
LAB_14003f566:
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x2000;
            lVar11 = param_1[1];
            if ((*(uint *)(lVar11 + 0x2374) & 2) == 0) {
              *(uint *)(lVar11 + 0x2380) = *(uint *)(lVar11 + 0x2380) | 0x20000;
            }
            else {
              *(uint *)(lVar11 + 0x2374) = *(uint *)(lVar11 + 0x2374) | 1;
            }
            *(undefined4 *)(param_1[1] + 0x25a4) = 1;
            lVar11 = param_1[1];
            bVar22 = *(byte *)(lVar11 + 0xcb1) != 0;
            if (bVar22) {
              local_58 = (ulonglong)((*(byte *)(lVar11 + 0xcb1) & 0xf | 0x42a8900) << 4);
              *(ulonglong *)(lVar11 + 0xe70) = local_58;
              *(undefined4 *)(lVar11 + 0xe78) = (undefined4)local_res18;
              *(undefined4 *)(param_1[1] + 0xf30) = 0x80000;
              *(uint *)(param_1[1] + 0x1004) = *(uint *)(param_1[1] + 0x1004) | 0x20;
              *(uint *)(param_1[1] + 0x1024) = (uint)*(byte *)(param_1[1] + 0xcb1);
              lVar11 = param_1[1];
            }
            uVar13 = (ulonglong)bVar22;
            uVar16 = uVar13;
            if (*(byte *)(lVar11 + 0xcb6) != 0) {
              local_68 = (ulonglong)((*(byte *)(lVar11 + 0xcb6) & 0xf | 0xfded9310) << 4);
              uVar16 = (ulonglong)(bVar22 + 1);
              *(ulonglong *)(lVar11 + 0xe70 + uVar13 * 0xc) = local_68;
              *(undefined4 *)(lVar11 + 0xe78 + uVar13 * 0xc) = 0;
              *(undefined4 *)(param_1[1] + 0xf30 + uVar13 * 4) = 0x80000;
              lVar11 = param_1[1];
            }
            if (*(byte *)(lVar11 + 0xcb8) != 0) {
              local_res18._0_4_ = 1;
              local_58 = (ulonglong)((*(byte *)(lVar11 + 0xcb8) & 0xf | 0xfde37110) << 4);
              *(ulonglong *)(lVar11 + 0xe70 + uVar16 * 0xc) = local_58;
              *(undefined4 *)(lVar11 + 0xe78 + uVar16 * 0xc) = 1;
              *(undefined4 *)(param_1[1] + 0xf30 + uVar16 * 4) = 0x80000;
              *(uint *)(param_1[1] + 0x1004) = *(uint *)(param_1[1] + 0x1004) | 1;
              uVar16 = (ulonglong)((int)uVar16 + 1);
              *(uint *)(param_1[1] + 0x1010) = (uint)*(byte *)(param_1[1] + 0xcb8);
              lVar11 = param_1[1];
            }
            if (*(byte *)(lVar11 + 0xcb0) != 0) {
              uVar8 = (*(byte *)(lVar11 + 0xcb0) & 0xf | 0xf8221100) << 4;
              if ((*(uint *)(lVar11 + 0x2374) & 2) != 0) {
                uVar8 = uVar8 | 0x400;
              }
              local_58 = (ulonglong)uVar8;
              *(ulonglong *)(lVar11 + 0xe70 + uVar16 * 0xc) = local_58;
              *(undefined4 *)(lVar11 + 0xe78 + uVar16 * 0xc) = (undefined4)local_res18;
              *(undefined4 *)(param_1[1] + 0xf30 + uVar16 * 4) = 0x30000;
              *(uint *)(param_1[1] + 0x1004) = *(uint *)(param_1[1] + 0x1004) | 2;
              *(uint *)(param_1[1] + 0x1014) = (uint)*(byte *)(param_1[1] + 0xcb0);
              lVar11 = param_1[1];
            }
            *(uint *)(lVar11 + 0xe6c) = *(uint *)(lVar11 + 0xe6c) | 0xf;
            return param_1;
          }
          if (uVar8 == 0x24) {
            *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
            *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
            *(undefined4 *)(lVar11 + 0xe78) = 0;
            *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) | 0x100;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
          }
          else {
            if (uVar8 == 0x25) {
              *(undefined2 *)(param_2 + 0xe68) = 0x4040;
              goto LAB_14003f278;
            }
            if (uVar8 == 0x26) {
              *(undefined2 *)(param_2 + 0xe68) = 0x4042;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x8000;
              *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
              lVar11 = param_1[1];
              goto LAB_14003f36d;
            }
            if (uVar8 != 0x27) {
              if (uVar8 == 0x28) {
                *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
                lVar11 = param_1[1];
                goto LAB_1400448e6;
              }
              goto LAB_140043e58;
            }
            *(undefined2 *)(param_2 + 0xe68) = 0x4040;
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          }
        }
        lVar11 = param_1[1];
        goto LAB_140044829;
      }
      if (uVar8 < 0x3a) {
        if (uVar8 == 0x39) {
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4050;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
          lVar11 = param_1[1];
LAB_14003fc3b:
          *(uint *)(lVar11 + 0x2380) = *(uint *)(lVar11 + 0x2380) | 0x80000;
          return param_1;
        }
        if (uVar8 == 0x34) {
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 0x80000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x42a80010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe7c) = 0xc1a80020;
          *(undefined8 *)(lVar11 + 0xe80) = 0;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe88) = 0xc1a90030;
          *(undefined8 *)(lVar11 + 0xe8c) = 0;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe94) = 0xc2170040;
          *(undefined8 *)(lVar11 + 0xe98) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xea0) = 0x81210050;
          *(undefined4 *)(lVar11 + 0xea8) = 0;
          return param_1;
        }
        if (uVar8 == 0x35) {
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 0x80000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x40a20010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x50c80120;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe88) = 0x80210030;
          *(undefined8 *)(lVar11 + 0xe8c) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe94) = 0x40370140;
          *(undefined4 *)(lVar11 + 0xe9c) = 0;
          lVar11 = param_1[1];
          goto LAB_140044999;
        }
        if (uVar8 == 0x36) {
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4050;
          lVar11 = param_1[1];
          goto LAB_140044cdf;
        }
        if (uVar8 == 0x37) {
          local_58._0_4_ = 0x80210010;
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4042;
          goto LAB_14003fa58;
        }
        if (uVar8 == 0x38) {
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
          *(undefined4 *)(param_1[1] + 0xad8) = 0x24;
          *(undefined4 *)(param_1[1] + 0xadc) = 0xc;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe7c) = 0x82211c20;
          *(undefined8 *)(lVar11 + 0xe80) = 0;
          *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xfffffbff;
          goto LAB_14003e756;
        }
      }
      else {
        if (uVar8 == 0x3a) {
          local_58._0_4_ = 0x82211820;
          *(undefined2 *)(param_2 + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x80000;
LAB_14003fa58:
          lVar11 = param_1[1];
          local_58 = (ulonglong)(uint)local_58;
LAB_14003fa60:
          *(ulonglong *)(lVar11 + 0xe70) = local_58;
          goto LAB_140044889;
        }
        if (uVar8 == 0x3b) {
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 0x80000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          lVar11 = param_1[1];
          goto LAB_14003fe61;
        }
        if (uVar8 == 0x3c) {
          *(uint *)(param_2 + 0x2384) = *(uint *)(param_2 + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 2;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x2000000;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
          *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
          *(undefined4 *)(param_1[1] + 0xadc) = 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x50c20110;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x40a80020;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe88) = 0x40370130;
          *(undefined4 *)(lVar11 + 0xe90) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe94) = 0x82211840;
          *(undefined4 *)(lVar11 + 0xe9c) = 0;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff1 | 1;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff6f | 0x60;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf00;
          *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xfffffbff;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffffd;
          return param_1;
        }
        if (uVar8 == 0x3d) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
          *(undefined4 *)(param_1[1] + 0x2488) = 0x15;
          *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) | 8;
          *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) & 0xffffbfff;
          lVar11 = param_1[1];
          goto LAB_14003fccb;
        }
      }
    }
    goto LAB_140043e58;
  }
  if (uVar8 < 0x93) {
    if (uVar8 == 0x92) {
      FUN_1400304b8(param_2,0x4050,1,0,1,1);
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 2;
      *(undefined4 *)(param_1[1] + 0x25a4) = 0x1f;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
      *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
      *(undefined4 *)(param_1[1] + 0xadc) = 10;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x1000;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
      *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) | 1;
      *(uint *)(param_1[1] + 0x2480) = *(uint *)(param_1[1] + 0x2480) | 0x40;
      *(undefined1 *)(param_1[1] + 0xcb7) = 1;
      lVar11 = param_1[1];
      *(undefined8 *)(lVar11 + 0xe70) = 0x42a81010;
      *(undefined4 *)(lVar11 + 0xe78) = 0;
      *(undefined4 *)(param_1[1] + 0xf30) = 0x80000;
      lVar11 = param_1[1];
      *(undefined4 *)(lVar11 + 0xe7c) = 0xc2b89020;
      *(undefined8 *)(lVar11 + 0xe80) = 0;
      *(undefined4 *)(param_1[1] + 0xf34) = 0x30100;
      lVar11 = param_1[1];
      *(undefined4 *)(lVar11 + 0xe88) = 0x82214430;
      *(undefined8 *)(lVar11 + 0xe8c) = 0;
      *(undefined4 *)(param_1[1] + 0xf38) = 0x30000;
      lVar11 = param_1[1];
      *(undefined8 *)(lVar11 + 0xe94) = 0x414e1140;
      *(undefined4 *)(lVar11 + 0xe9c) = 0;
      *(undefined4 *)(param_1[1] + 0xf3c) = 0x700;
      *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
      *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffffbf | 0xb0;
      lVar11 = param_1[1];
      uVar8 = *(uint *)(lVar11 + 0xe6c) & 0xfffff2ff | 0x200;
LAB_14003eb3f:
      *(uint *)(lVar11 + 0xe6c) = uVar8;
      return param_1;
    }
    if (uVar8 < 0x46) {
      if (uVar8 != 0x45) {
        if (uVar8 == 0x40) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4050;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
          goto LAB_140044cdb;
        }
        if (uVar8 == 0x41) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x80000;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
          *(undefined4 *)(param_1[1] + 0x2488) = 0x15;
          goto LAB_140044fb1;
        }
        if (uVar8 == 0x42) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4050;
          *(undefined4 *)(param_1[1] + 0xfc8) = 0x1220;
          *(undefined1 *)(param_1[1] + 0xe6a) = 0x1c;
          *(undefined4 *)(param_1[1] + 0xe6c) = 0;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x8000;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x400;
          *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) | 0x10000000;
          *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) | 0x200;
          *(uint *)(param_1[1] + 0x23f4) = *(uint *)(param_1[1] + 0x23f4) | 0x100;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) & 0xffffefff;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
          *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
          *(undefined4 *)(param_1[1] + 0xadc) = 10;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
          lVar11 = param_1[1];
          if (*(short *)(lVar11 + 0x26aa) == 0xdb0) {
            *(uint *)(lVar11 + 0x2394) = *(uint *)(lVar11 + 0x2394) | 0x8000;
            lVar11 = param_1[1];
          }
          *(undefined1 *)(lVar11 + 0xcb0) = 5;
          lVar11 = param_1[1];
          *(uint *)(lVar11 + 0xe70) = (*(byte *)(lVar11 + 0xcb0) & 0xf | 0xf8221400) << 4;
          *(undefined8 *)(lVar11 + 0xe74) = 0;
          *(undefined4 *)(param_1[1] + 0xf30) = 0x30000;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe7c) = 0xc1174240;
          *(undefined8 *)(lVar11 + 0xe80) = 0;
          *(undefined4 *)(param_1[1] + 0xf34) = 0x30300;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe88) = 0xc11b1041;
          *(undefined8 *)(lVar11 + 0xe8c) = 0;
          *(undefined4 *)(param_1[1] + 0xf38) = 0x30200;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe94) = 0xc11a7042;
          *(undefined8 *)(lVar11 + 0xe98) = 0;
          *(undefined4 *)(param_1[1] + 0xf3c) = 0x30000;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xea0) = 0xc11c2043;
          *(undefined8 *)(lVar11 + 0xea4) = 0;
          *(undefined4 *)(param_1[1] + 0xf40) = 0x80000;
          *(undefined1 *)(param_1[1] + 0xcb4) = 1;
          lVar11 = param_1[1];
          *(uint *)(lVar11 + 0xeac) = (*(byte *)(lVar11 + 0xcb4) & 0xf | 0x4189340) << 4;
          *(undefined8 *)(lVar11 + 0xeb0) = 0;
          *(undefined4 *)(param_1[1] + 0xf44) = 0x30100;
          *(undefined1 *)(param_1[1] + 0xcb3) = 2;
          lVar11 = param_1[1];
          *(uint *)(lVar11 + 0xeb8) = (*(byte *)(lVar11 + 0xcb3) & 0xf | 0x41a8900) << 4;
          *(undefined8 *)(lVar11 + 0xebc) = 0;
          *(undefined4 *)(param_1[1] + 0xf48) = 0x30500;
          *(undefined1 *)(param_1[1] + 0xcb1) = 3;
          lVar11 = param_1[1];
          *(uint *)(lVar11 + 0xec4) = (*(byte *)(lVar11 + 0xcb1) & 0xf | 0xfc2b8940) << 4;
          *(undefined8 *)(lVar11 + 0xec8) = 0;
          *(undefined4 *)(param_1[1] + 0xf4c) = 0x30100;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xed0) = 0x414e1560;
          *(undefined4 *)(lVar11 + 0xed8) = 0;
          *(undefined4 *)(param_1[1] + 0xf50) = 0x700;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff3 | 3;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff4f | 0x40;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffff6ff | 0x600;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffff1fff | 0x1000;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfff2ffff | 0x20000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 8;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x800;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x400;
          *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) & 0xffffffbf;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x4000;
          *(uint *)(param_1[1] + 0x23a0) = *(uint *)(param_1[1] + 0x23a0) | 1;
          *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x100;
          lVar11 = param_1[1];
          iVar15 = *(int *)(lVar11 + 0x26b4);
          if (iVar15 == 0x42) {
            *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) & 0xffffbfff;
            lVar11 = param_1[1];
            if (*(ushort *)(lVar11 + 0x2754) < 0x811) {
              uVar8 = *(uint *)(lVar11 + 0x2374) & 0xfffffbff;
            }
            else {
              uVar8 = *(uint *)(lVar11 + 0x2374) | 0x400;
            }
            *(uint *)(lVar11 + 0x2374) = uVar8;
            return param_1;
          }
          if ((iVar15 != 0x4b) && (iVar15 != 0x4c)) {
            if ((iVar15 == 0x79) || (iVar15 == 0x7b)) {
              *(uint *)(lVar11 + 0x2390) = *(uint *)(lVar11 + 0x2390) | 0x40;
              lVar11 = param_1[1];
              if (*(int *)(lVar11 + 0x26b4) == 0x7b) {
                *(uint *)(lVar11 + 0x2380) = *(uint *)(lVar11 + 0x2380) | 0x1000;
                lVar11 = param_1[1];
              }
              *(uint *)(lVar11 + 0x237c) = *(uint *)(lVar11 + 0x237c) & 0xfffffbff;
            }
            else {
              if ((iVar15 == 0x83) || (iVar15 == 0x86)) {
                if (iVar15 == 0x86) {
                  *(undefined4 *)(lVar11 + 0x25a4) = 0x1e;
                  *(uint *)(param_1[1] + 0x24f4) = *(uint *)(param_1[1] + 0x24f4) | 0x2000000;
                }
                else {
                  *(undefined4 *)(lVar11 + 0x25a4) = 0x1f;
                  *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xfffffbff;
                }
                *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
                *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x8000;
                *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
                *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
                *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff3fff | 0x3000;
                *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff6fff | 0x6000;
                *(uint *)(param_1[1] + 0xeb8) = *(uint *)(param_1[1] + 0xeb8) & 0xffff9fff | 0x9000;
                *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff4fff | 0x4000;
                *(uint *)(param_1[1] + 0xed0) = *(uint *)(param_1[1] + 0xed0) & 0xffff6fff | 0x6000;
                *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) | 0x200;
                return param_1;
              }
              if (iVar15 != 0x95) {
                if (iVar15 != 0xab) {
                  return param_1;
                }
                *(uint *)(lVar11 + 0x2374) = *(uint *)(lVar11 + 0x2374) & 0xfffffbff;
                *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) & 0xefffffff;
                *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) & 0xffffffbf;
                *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
                *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
                *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff3fff | 0x3000;
                *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff6fff | 0x6000;
                *(uint *)(param_1[1] + 0xeb8) = *(uint *)(param_1[1] + 0xeb8) & 0xffff9fff | 0x9000;
                *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff4fff | 0x4000;
                *(uint *)(param_1[1] + 0xed0) = *(uint *)(param_1[1] + 0xed0) & 0xffff6fff | 0x6000;
                lVar11 = param_1[1];
                goto LAB_14003fc3b;
              }
              *(undefined4 *)(lVar11 + 0x25a4) = 0x28;
              *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
            }
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
            *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
            *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff3fff | 0x3000;
            *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff6fff | 0x6000;
            *(uint *)(param_1[1] + 0xeb8) = *(uint *)(param_1[1] + 0xeb8) & 0xffff9fff | 0x9000;
            *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff4fff | 0x4000;
            return param_1;
          }
          if (iVar15 == 0x4c) {
            *(undefined4 *)(lVar11 + 0x25a4) = 0x15;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
            *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
            *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff3fff | 0x3000;
            *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff6fff | 0x6000;
            *(uint *)(param_1[1] + 0xeb8) = *(uint *)(param_1[1] + 0xeb8) & 0xffff9fff | 0x9000;
            lVar11 = param_1[1];
            uVar8 = *(uint *)(lVar11 + 0xe7c) & 0xffff4fff | 0x4000;
          }
          else {
            *(undefined4 *)(lVar11 + 0x25a4) = 0x16;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
            *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
            *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff1fff | 0x1000;
            *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff1fff | 0x1000;
            *(uint *)(param_1[1] + 0xeb8) = *(uint *)(param_1[1] + 0xeb8) & 0xffff1fff | 0x1000;
            lVar11 = param_1[1];
            uVar8 = *(uint *)(lVar11 + 0xe7c) & 0xffff5fff | 0x5000;
          }
          *(uint *)(lVar11 + 0xe7c) = uVar8;
LAB_1400407d1:
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
          return param_1;
        }
        if (uVar8 != 0x43) {
          if (uVar8 != 0x44) goto LAB_140043e58;
          goto LAB_14003ffa6;
        }
      }
      *(undefined2 *)(param_2 + 0xe68) = 0x4042;
      lVar11 = param_1[1];
LAB_14003f27c:
      *(uint *)(lVar11 + 0x2380) = *(uint *)(lVar11 + 0x2380) | 1;
      return param_1;
    }
    if (uVar8 == 0x46) {
      *(undefined2 *)(param_2 + 0xe68) = 0x4042;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
LAB_140040a14:
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
      lVar11 = param_1[1];
LAB_14003fe61:
      *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) | 0x20;
      return param_1;
    }
    if (uVar8 == 0x47) {
LAB_14003ffa6:
      *(undefined2 *)(param_2 + 0xe68) = 0x4042;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
LAB_140044825:
      lVar11 = param_1[1];
LAB_140044829:
      *(uint *)(lVar11 + 0x237c) = *(uint *)(lVar11 + 0x237c) | 1;
      return param_1;
    }
    if (uVar8 != 0x48) {
      if (uVar8 == 0x49) {
        *(undefined2 *)(param_2 + 0xe68) = 0x4042;
        *(undefined4 *)(param_1[1] + 0xfc8) = 0x1220;
        *(undefined1 *)(param_1[1] + 0xe6a) = 0x1c;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
        goto LAB_140044a6e;
      }
      if (uVar8 == 0x4a) {
        FUN_1400304b8(param_2,0x4050,1,0,1,1);
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
        lVar11 = param_1[1];
        *(undefined4 *)(lVar11 + 0xe70) = 0xd0c80110;
        *(undefined8 *)(lVar11 + 0xe74) = 0;
        lVar11 = param_1[1];
        *(undefined8 *)(lVar11 + 0xe7c) = 0x40a80020;
        *(undefined4 *)(lVar11 + 0xe84) = 0;
        lVar11 = param_1[1];
        *(undefined4 *)(lVar11 + 0xe88) = 0x80210030;
        *(undefined8 *)(lVar11 + 0xe8c) = 0;
        lVar11 = param_1[1];
        *(undefined8 *)(lVar11 + 0xe94) = 0xd0170140;
        *(undefined4 *)(lVar11 + 0xe9c) = 0;
        return param_1;
      }
      goto LAB_140043e58;
    }
    *(undefined2 *)(param_2 + 0xe68) = 0x4042;
    *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
    *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
    *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
  }
  else {
    if (uVar8 < 0xba) {
      if (uVar8 == 0xb9) {
        FUN_1400304b8(param_2,0x4050,1,1,1,1);
        FUN_140030480(param_1[1]);
        lVar11 = param_1[1];
LAB_14003f36d:
        *(uint *)(lVar11 + 0x237c) = *(uint *)(lVar11 + 0x237c) | 0x10;
        return param_1;
      }
      if (uVar8 < 0xb1) {
        if (uVar8 == 0xb0) {
          FUN_1400304b8(param_2,0x4032,1,0,0,1);
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x800;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 4;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 8;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
          *(undefined4 *)(param_1[1] + 0xad8) = 0x24;
          *(undefined4 *)(param_1[1] + 0xadc) = 0xc;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20000000;
          do {
            uVar8 = (int)uVar16 + 1;
            uVar16 = (ulonglong)uVar8;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | uVar8;
          } while ((int)uVar8 < 2);
          *(uint *)(param_1[1] + 0x24c0) = *(uint *)(param_1[1] + 0x24c0) | 0x100000;
          *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) | 0x100;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
          *(undefined4 *)(param_1[1] + 0x25a4) = 1;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x41a81010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x81211420;
          *(undefined4 *)(lVar11 + 0xe84) = (undefined4)local_res18;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
          if ((*(uint *)(param_1[1] + 0x2370) & 0x800) == 0) {
            return param_1;
          }
          puVar1 = (uint *)(param_1[1] + 0x2374);
          *puVar1 = *puVar1 & 0xfffffffe;
          lVar11 = 0xe70;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
          do {
            *(uint *)(lVar11 + param_1[1]) = *(uint *)(lVar11 + param_1[1]) & 0xfffffbff;
            lVar11 = lVar11 + 0xc;
          } while (lVar11 < 0xe88);
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff0;
          return param_1;
        }
        if (uVar8 == 0x9f) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4050;
          *(undefined4 *)(param_1[1] + 0xe6c) = 0;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x10000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x400;
          *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) | 0x10000000;
          *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) & 0xffffffbf;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x4000;
          *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) | 0x200;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) & 0xffffefff;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x82214210;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          *(undefined4 *)(param_1[1] + 0xf30) = 0x30000;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff2 | 2;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x800;
          lVar11 = param_1[1];
          if (*(int *)(lVar11 + 0x26b4) == 0x7d) {
            *(undefined4 *)(lVar11 + 0x25a4) = 0x1f;
            *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x8000;
            return param_1;
          }
          if (*(int *)(lVar11 + 0x26b4) != 0x93) {
            return param_1;
          }
          *(undefined4 *)(lVar11 + 0x25a4) = 0x28;
          return param_1;
        }
        if (uVar8 == 0xa0) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
          *(undefined4 *)(param_1[1] + 0x2488) = 0x15;
          *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) | 8;
          *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) & 0xffffbfff;
          lVar11 = param_1[1];
LAB_14003fccb:
          *(uint *)(lVar11 + 0x2390) = *(uint *)(lVar11 + 0x2390) & 0xfffffbff;
          return param_1;
        }
        if (uVar8 == 0xa1) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4042;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          goto LAB_140044cdb;
        }
        if (uVar8 == 0xa3) {
          uVar8 = 0;
          *(undefined2 *)(param_2 + 0xe68) = 0x4050;
          *(undefined4 *)(param_1[1] + 0xfc8) = 0x1220;
          *(undefined1 *)(param_1[1] + 0xe6a) = 0x1c;
          *(undefined4 *)(param_1[1] + 0xe6c) = 0;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
          do {
            uVar8 = uVar8 + 1;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | uVar8;
          } while ((int)uVar8 < 2);
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x8000;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x400;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x400;
          *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) | 0x10000000;
          *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) | 0x200;
          *(uint *)(param_1[1] + 0x23f4) = *(uint *)(param_1[1] + 0x23f4) | 0x100;
          *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) & 0xffffffbf;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x4000;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) & 0xffffefff;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
          *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
          *(undefined4 *)(param_1[1] + 0xadc) = 10;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x10000;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe70) = 0xc1174240;
          *(undefined8 *)(lVar11 + 0xe74) = 0;
          *(undefined4 *)(param_1[1] + 0xf30) = 0x30300;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe7c) = 0xc11b1041;
          *(undefined8 *)(lVar11 + 0xe80) = 0;
          *(undefined4 *)(param_1[1] + 0xf34) = 0x30200;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe88) = 0xc11a7042;
          *(undefined8 *)(lVar11 + 0xe8c) = 0;
          *(undefined4 *)(param_1[1] + 0xf38) = 0x30000;
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe94) = 0xc11c2043;
          *(undefined8 *)(lVar11 + 0xe98) = 0;
          *(undefined4 *)(param_1[1] + 0xf3c) = 0x80000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xea0) = 0x41893410;
          *(undefined4 *)(lVar11 + 0xea8) = 0;
          *(undefined4 *)(param_1[1] + 0xf40) = 0x30100;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xeac) = 0x41a89020;
          *(undefined4 *)(lVar11 + 0xeb4) = 0;
          *(undefined4 *)(param_1[1] + 0xf44) = 0x30500;
          *(undefined1 *)(param_1[1] + 0xcb1) = 3;
          lVar11 = param_1[1];
          *(uint *)(lVar11 + 0xeb8) = (*(byte *)(lVar11 + 0xcb1) & 0xf | 0xfc2b8940) << 4;
          *(undefined8 *)(lVar11 + 0xebc) = 0;
          *(undefined4 *)(param_1[1] + 0xf48) = 0x30100;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xec4) = 0x414e1550;
          *(undefined4 *)(lVar11 + 0xecc) = 0;
          *(undefined4 *)(param_1[1] + 0xf4c) = 0x700;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff3 | 3;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff4f | 0x40;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffff6ff | 0x600;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffff1fff | 0x1000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 8;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x800;
          lVar11 = param_1[1];
          if (*(int *)(lVar11 + 0x26b4) != 0x82) {
            if (*(int *)(lVar11 + 0x26b4) != 0x94) {
              return param_1;
            }
            *(undefined4 *)(lVar11 + 0x25a4) = 0x28;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
            *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff1fff | 0x1000;
            *(uint *)(param_1[1] + 0xea0) = *(uint *)(param_1[1] + 0xea0) & 0xffff3fff | 0x3000;
            *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff6fff | 0x6000;
            *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff9fff | 0x9000;
            *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) & 0xffff4fff | 0x4000;
            return param_1;
          }
          *(undefined4 *)(lVar11 + 0x25a4) = 0x1f;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
          *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x8000;
          *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff1fff | 0x1000;
          *(uint *)(param_1[1] + 0xea0) = *(uint *)(param_1[1] + 0xea0) & 0xffff3fff | 0x3000;
          *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff6fff | 0x6000;
          *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff9fff | 0x9000;
          *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) & 0xffff4fff | 0x4000;
          *(uint *)(param_1[1] + 0xec4) = *(uint *)(param_1[1] + 0xec4) & 0xffff6fff | 0x6000;
          return param_1;
        }
        if (uVar8 == 0xa4) {
          uVar6 = 0x5683;
        }
        else {
          if (uVar8 != 0xa8) {
            if (uVar8 == 0xa9) goto LAB_140043af9;
            if (uVar8 == 0xaf) {
              FUN_1400304b8(param_2,0x4032,1,0,0,1);
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x800;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 4;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 8;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20000000;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
              *(undefined4 *)(param_1[1] + 0xad8) = 0x24;
              *(undefined4 *)(param_1[1] + 0xadc) = 0xc;
              *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) | 0x200;
              *(undefined4 *)(param_1[1] + 0x25a4) = 1;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x41a81410;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe7c) = 0x81211420;
              *(undefined4 *)(lVar11 + 0xe84) = (undefined4)local_res18;
              *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff2 | 2;
              *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff4f | 0x40;
              if ((*(uint *)(param_1[1] + 0x2370) & 0x800) == 0) {
                return param_1;
              }
              puVar1 = (uint *)(param_1[1] + 0x2374);
              *puVar1 = *puVar1 & 0xfffffffe;
              lVar11 = 0xe70;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
              do {
                *(uint *)(lVar11 + param_1[1]) = *(uint *)(lVar11 + param_1[1]) & 0xfffffbff;
                lVar11 = lVar11 + 0xc;
              } while (lVar11 < 0xe88);
              return param_1;
            }
            goto LAB_140043e58;
          }
          uVar6 = 0x5686;
        }
        *(undefined2 *)(param_2 + 0xe68) = uVar6;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
        lVar11 = param_1[1];
LAB_14003e481:
        *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) | 0x8000;
        return param_1;
      }
      if (uVar8 != 0xb1) {
        if (uVar8 == 0xb2) {
          FUN_1400304b8(param_2,0x4080,1,0,1,1);
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x1000;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
          *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
          *(undefined4 *)(param_1[1] + 0xadc) = 10;
          *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) | 0x10000000;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x4000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x400;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000000;
          lVar11 = param_1[1];
          if (*(int *)(lVar11 + 0x38) == 3) {
            *(undefined1 *)(lVar11 + 0xcb6) = 1;
            *(undefined1 *)(param_1[1] + 0xcb3) = 2;
            *(undefined1 *)(param_1[1] + 0xcb2) = 3;
          }
          else {
            *(undefined1 *)(lVar11 + 0xcb6) = 0;
            *(undefined1 *)(param_1[1] + 0xcb3) = 1;
            *(undefined1 *)(param_1[1] + 0xcb2) = 2;
          }
          lVar11 = param_1[1];
          bVar22 = *(byte *)(lVar11 + 0xcb6) != 0;
          if (bVar22) {
            *(uint *)(lVar11 + 0xe70) = (*(byte *)(lVar11 + 0xcb6) & 0xf | 0xfded9310) << 4;
            *(undefined8 *)(lVar11 + 0xe74) = 0;
            *(undefined4 *)(param_1[1] + 0xf30) = 0x80000;
            lVar11 = param_1[1];
          }
          uVar16 = (ulonglong)bVar22;
          *(uint *)(lVar11 + 0xe70 + uVar16 * 0xc) =
               (*(byte *)(lVar11 + 0xcb3) & 0xf | 0x41a8900) << 4;
          *(undefined8 *)(lVar11 + 0xe74 + uVar16 * 0xc) = 0;
          *(undefined4 *)(param_1[1] + 0xf30 + uVar16 * 4) = 0x30500;
          lVar11 = param_1[1];
          local_58 = (ulonglong)((*(byte *)(lVar11 + 0xcb2) & 0xf | 0xfc117400) << 4);
          uVar8 = bVar22 + 1;
          *(ulonglong *)(lVar11 + 0xe70 + (ulonglong)uVar8 * 0xc) = local_58;
          *(undefined4 *)(lVar11 + 0xe78 + (ulonglong)uVar8 * 0xc) = 0;
          *(undefined4 *)(param_1[1] + 0xf30 + (ulonglong)uVar8 * 4) = 0x30300;
          if (*(int *)(param_1[1] + 0x26b4) != 0x96) {
            return param_1;
          }
          *(undefined4 *)(param_1[1] + 0x25a4) = 0x28;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
LAB_14003e951:
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
          return param_1;
        }
        if (uVar8 == 0xb3) {
          FUN_1400304b8(param_2,0x4080,1,0,1,1);
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
          *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
          *(undefined4 *)(param_1[1] + 0xadc) = 10;
          lVar11 = param_1[1];
          if (*(int *)(lVar11 + 0x26b4) == 0xcd) {
            *(undefined1 *)(lVar11 + 0xcb1) = 1;
            *(undefined1 *)(param_1[1] + 0xcb0) = 2;
            lVar11 = param_1[1];
          }
          bVar2 = *(byte *)(lVar11 + 0xcb1);
          if (bVar2 != 0) {
            local_58 = (ulonglong)((bVar2 & 0xf | 0xfc2b8900) << 4);
            *(ulonglong *)(lVar11 + 0xe70) = local_58;
            *(undefined4 *)(lVar11 + 0xe78) = 0;
            *(undefined4 *)(param_1[1] + 0xf30) = 0x30100;
            lVar11 = param_1[1];
          }
          uVar16 = (ulonglong)(bVar2 != 0);
          if (*(byte *)(lVar11 + 0xcb0) != 0) {
            local_58 = (ulonglong)((*(byte *)(lVar11 + 0xcb0) & 0xf | 0xf8221400) << 4);
            *(ulonglong *)(lVar11 + 0xe70 + uVar16 * 0xc) = local_58;
            *(undefined4 *)(lVar11 + 0xe78 + uVar16 * 0xc) = 0;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar16 * 4) = 0x30000;
            lVar11 = param_1[1];
          }
          if (*(int *)(lVar11 + 0x26b4) != 0xcd) {
            return param_1;
          }
          *(undefined4 *)(lVar11 + 0x25a4) = 0x1f;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
          *(uint *)(param_1[1] + 0x24c0) = *(uint *)(param_1[1] + 0x24c0) & 0xfffffffb;
          return param_1;
        }
        if (uVar8 == 0xb4) {
          FUN_1400304b8(param_2,0x4080,1,0,1,1);
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x400;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x400;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x4000;
          *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) | 0x10000000;
          *(uint *)(param_1[1] + 0x23a0) = *(uint *)(param_1[1] + 0x23a0) | 1;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000000;
          *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) | 0x200;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x800;
          *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
          *(undefined4 *)(param_1[1] + 0xadc) = 10;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x1000;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 8;
          lVar11 = param_1[1];
          iVar15 = *(int *)(lVar11 + 0x26b4);
          if (iVar15 == 0x9d) {
            *(undefined1 *)(lVar11 + 0xcb6) = 0;
            *(undefined1 *)(param_1[1] + 0xcb1) = 1;
            *(undefined1 *)(param_1[1] + 0xcb3) = 2;
            *(undefined1 *)(param_1[1] + 0xcb2) = 3;
            *(undefined1 *)(param_1[1] + 0xcb0) = 4;
            *(undefined1 *)(param_1[1] + 0xcb5) = 0;
          }
          else if (iVar15 - 0x7eU < 4) {
            *(undefined1 *)(lVar11 + 0xcb6) = 0;
            *(undefined1 *)(param_1[1] + 0xcb3) = 1;
            uVar13 = uVar16;
            do {
              cVar5 = (char)uVar16;
              uVar8 = (int)uVar16 + 1;
              uVar16 = (ulonglong)uVar8;
              *(char *)(uVar13 + 0xcb1 + param_1[1]) = cVar5 + '\x02';
              uVar13 = uVar13 + 1;
            } while ((int)uVar8 < 2);
            *(undefined1 *)(param_1[1] + 0xcb0) = 4;
            *(undefined1 *)(param_1[1] + 0xcb5) = 5;
            *(uint *)(param_1[1] + 0x2388) = *(uint *)(param_1[1] + 0x2388) | 1;
          }
          else if (iVar15 - 0x84U < 2) {
            *(undefined1 *)(lVar11 + 0xcb6) = 1;
            *(undefined1 *)(param_1[1] + 0xcb4) = 2;
            do {
              cVar5 = (char)iVar9;
              iVar9 = iVar9 + 1;
              *(char *)(uVar16 + 0xcb1 + param_1[1]) = cVar5 + '\x03';
              uVar16 = uVar16 + 1;
            } while (iVar9 < 2);
            *(undefined1 *)(param_1[1] + 0xcb0) = 5;
            *(undefined1 *)(param_1[1] + 0xcb5) = 6;
            *(uint *)(param_1[1] + 0x2388) = *(uint *)(param_1[1] + 0x2388) | 1;
            *(undefined4 *)(param_1[1] + 0x25a4) = 0x1f;
            *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x8000;
            *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
            *(uint *)(param_1[1] + 0x2388) = *(uint *)(param_1[1] + 0x2388) | 2;
            *(undefined4 *)(param_1[1] + 0xcdc) = 1;
            *(undefined4 *)(param_1[1] + 0xaec) = 1;
          }
          else if (iVar15 - 0xc9U < 2) {
            if (*(int *)(lVar11 + 0x38) == 6) {
              *(undefined1 *)(lVar11 + 0xcb6) = 1;
              *(undefined1 *)(param_1[1] + 0xcb4) = 2;
              do {
                cVar5 = (char)iVar9;
                iVar9 = iVar9 + 1;
                *(char *)(uVar16 + 0xcb1 + param_1[1]) = cVar5 + '\x03';
                uVar16 = uVar16 + 1;
              } while (iVar9 < 2);
              *(undefined1 *)(param_1[1] + 0xcb0) = 5;
              *(undefined1 *)(param_1[1] + 0xcb5) = 6;
            }
            else {
              *(undefined1 *)(lVar11 + 0xcb6) = 0;
              *(undefined1 *)(param_1[1] + 0xcb4) = 1;
              uVar13 = uVar16;
              do {
                cVar5 = (char)uVar16;
                uVar8 = (int)uVar16 + 1;
                uVar16 = (ulonglong)uVar8;
                *(char *)(uVar13 + 0xcb1 + param_1[1]) = cVar5 + '\x02';
                uVar13 = uVar13 + 1;
              } while ((int)uVar8 < 2);
              *(undefined1 *)(param_1[1] + 0xcb0) = 4;
              *(undefined1 *)(param_1[1] + 0xcb5) = 5;
            }
            *(undefined4 *)(param_1[1] + 0x25a4) = 0x14;
            *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
            *(uint *)(param_1[1] + 0x2388) = *(uint *)(param_1[1] + 0x2388) | 1;
            *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x40000;
            *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
          }
          else {
            *(undefined1 *)(lVar11 + 0xcb6) = 1;
            *(undefined1 *)(param_1[1] + 0xcb1) = 2;
            *(undefined1 *)(param_1[1] + 0xcb3) = 3;
            *(undefined1 *)(param_1[1] + 0xcb2) = 4;
            *(undefined1 *)(param_1[1] + 0xcb0) = 5;
            *(undefined1 *)(param_1[1] + 0xcb5) = 6;
          }
          lVar11 = param_1[1];
          bVar2 = *(byte *)(lVar11 + 0xcb6);
          if (bVar2 != 0) {
            *(uint *)(lVar11 + 0xe70) = (bVar2 & 0xf | 0xfded9310) << 4;
            *(undefined8 *)(lVar11 + 0xe74) = 0;
            *(undefined4 *)(param_1[1] + 0xf30) = 0x80000;
            lVar11 = param_1[1];
          }
          uVar10 = (uint)(bVar2 != 0);
          uVar8 = (*(byte *)(lVar11 + 0xcb0) & 0xf | 0xf8221400) << 4;
          if ((*(int *)(lVar11 + 0x26b4) - 0x84U < 2) || (*(int *)(lVar11 + 0x26b4) == 0x7f)) {
            uVar8 = uVar8 | 0x200;
          }
          uVar21 = (ulonglong)uVar10;
          uVar13 = (ulonglong)(uVar10 + 1);
          *(uint *)(lVar11 + 0xe70 + uVar21 * 0xc) = uVar8;
          *(undefined8 *)(lVar11 + 0xe74 + uVar21 * 0xc) = 0;
          *(undefined4 *)(param_1[1] + 0xf30 + uVar21 * 4) = 0x30000;
          lVar11 = param_1[1];
          *(uint *)(lVar11 + 0xe70 + uVar13 * 0xc) =
               (*(byte *)(lVar11 + 0xcb2) & 0xf | 0xfc117420) << 4;
          *(undefined8 *)(lVar11 + 0xe74 + uVar13 * 0xc) = 0;
          *(undefined4 *)(param_1[1] + 0xf30 + uVar13 * 4) = 0x30300;
          uVar17 = (ulonglong)(uVar10 + 2);
          lVar11 = param_1[1];
          uVar16 = uVar17;
          if (*(byte *)(lVar11 + 0xcb3) != 0) {
            *(uint *)(lVar11 + 0xe70 + uVar17 * 0xc) =
                 (*(byte *)(lVar11 + 0xcb3) & 0xf | 0x41a8900) << 4;
            *(undefined4 *)(lVar11 + 0xe74 + uVar17 * 0xc) = 0;
            *(undefined4 *)(lVar11 + 0xe78 + uVar17 * 0xc) = 0;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar17 * 4) = 0x30500;
            uVar16 = (ulonglong)(uVar10 + 3);
            lVar11 = param_1[1];
          }
          uVar18 = uVar16;
          if (*(byte *)(lVar11 + 0xcb4) != 0) {
            uVar8 = *(byte *)(lVar11 + 0xcb4) & 0xf;
            uVar10 = uVar8 | 0x4089000;
            if ((*(int *)(lVar11 + 0x26b4) - 0x84U < 2) || (*(int *)(lVar11 + 0x26b4) - 0xc9U < 2))
            {
              uVar10 = uVar8 | 0x40a8000;
            }
            *(uint *)(lVar11 + 0xe70 + uVar16 * 0xc) = uVar10 << 4 | 0x1009000;
            *(undefined4 *)(lVar11 + 0xe74 + uVar16 * 0xc) = 0;
            *(undefined4 *)(lVar11 + 0xe78 + uVar16 * 0xc) = 0;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar16 * 4) = 0x30100;
            uVar18 = (ulonglong)((int)uVar16 + 1);
            lVar11 = param_1[1];
          }
          uVar19 = uVar18;
          if (*(byte *)(lVar11 + 0xcb1) != 0) {
            *(uint *)(lVar11 + 0xe70 + uVar18 * 0xc) =
                 (*(byte *)(lVar11 + 0xcb1) & 0xf | 0xfc2b8900) << 4;
            *(undefined4 *)(lVar11 + 0xe74 + uVar18 * 0xc) = 0;
            *(undefined4 *)(lVar11 + 0xe78 + uVar18 * 0xc) = 0;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar18 * 4) = 0x30200;
            uVar19 = (ulonglong)((int)uVar18 + 1);
            lVar11 = param_1[1];
          }
          uVar20 = uVar19;
          if (*(byte *)(lVar11 + 0xcb5) != 0) {
            local_68 = (ulonglong)((*(byte *)(lVar11 + 0xcb5) & 0xf | 0x414e110) << 4);
            *(ulonglong *)(lVar11 + 0xe70 + uVar19 * 0xc) = local_68;
            *(undefined4 *)(lVar11 + 0xe78 + uVar19 * 0xc) = 0;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar19 * 4) = 0x700;
            *(uint *)(param_1[1] + 0xe70 + uVar19 * 0xc) =
                 *(uint *)(param_1[1] + 0xe70 + uVar19 * 0xc) & 0xffff6fff | 0x6000;
            uVar20 = (ulonglong)((int)uVar19 + 1);
            lVar11 = param_1[1];
          }
          if ((*(uint *)(lVar11 + 0x2388) & 1) != 0) {
            puVar1 = (uint *)(lVar11 + 0xe70 + uVar17 * 0xc);
            *puVar1 = *puVar1 | 0x400;
            puVar1 = (uint *)(param_1[1] + (uVar18 + 0x134) * 0xc);
            *puVar1 = *puVar1 | 0x400;
            lVar11 = param_1[1];
            *(uint *)(lVar11 + 0xe70 + uVar20 * 0xc) =
                 (*(byte *)(lVar11 + 0xcb2) & 0xf) << 4 | 0xc11a1002;
            *(undefined8 *)(lVar11 + 0xe74 + uVar20 * 0xc) = 0;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar20 * 4) = 0x80000;
            uVar18 = (ulonglong)((int)uVar20 + 1);
            lVar11 = param_1[1];
            local_68 = (ulonglong)((*(byte *)(lVar11 + 0xcb2) & 0xf) << 4) | 0xc21b1001;
            *(ulonglong *)(lVar11 + 0xe70 + uVar18 * 0xc) = local_68;
            *(undefined4 *)(lVar11 + 0xe78 + uVar18 * 0xc) = 0;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar18 * 4) = 0x80000;
            uVar20 = (ulonglong)((int)uVar20 + 2);
            lVar11 = param_1[1];
          }
          iVar15 = *(int *)(lVar11 + 0x26b4);
          local_res18 = 0;
          if ((((iVar15 - 0x80U < 2) || (iVar15 - 0xc9U < 2)) || (iVar15 == 0x85)) ||
             (*(short *)(lVar11 + 0x26a8) == 0x1b9b)) {
            puVar1 = (uint *)(lVar11 + 0xe70 + uVar21 * 0xc);
            *puVar1 = *puVar1 | 0x400;
            lVar11 = param_1[1];
            local_68 = (ulonglong)((*(byte *)(lVar11 + 0xcb2) & 0xf) << 4) | 0xc21c4003;
            *(ulonglong *)(lVar11 + 0xe70 + uVar20 * 0xc) = local_68;
            *(undefined4 *)(lVar11 + 0xe78 + uVar20 * 0xc) = 0;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar20 * 4) = 0x80000;
            lVar11 = param_1[1];
            local_res18 = uVar20;
          }
          *(uint *)(lVar11 + 0xe6c) = *(uint *)(lVar11 + 0xe6c) & 0xfffffff4 | 4;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff6f | 0x60;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffff1ff | 0x100;
          *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffff2fff | 0x2000;
          lVar11 = param_1[1];
          if ((*(int *)(lVar11 + 0x26b4) - 0x9bU < 2) || (*(int *)(lVar11 + 0x26b4) == 0x9d)) {
            *(undefined4 *)(lVar11 + 0x25a4) = 0x28;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
            lVar11 = param_1[1];
          }
          if ((*(int *)(lVar11 + 0x26b4) - 0x7eU < 3) || (*(int *)(lVar11 + 0x26b4) == 0x81)) {
            *(uint *)(lVar11 + 0x2390) = *(uint *)(lVar11 + 0x2390) | 0x40;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar13 * 4) = 0x30500;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar17 * 4) = 0x30300;
            *(uint *)(param_1[1] + (uVar19 + 0x134) * 0xc) =
                 *(uint *)(param_1[1] + (uVar19 + 0x134) * 0xc) & 0xffff1fff | 0x1000;
            lVar11 = param_1[1];
            if (*(int *)(lVar11 + 0x26b4) == 0x7f) {
              *(undefined4 *)(lVar11 + 0xf30 + uVar13 * 4) = 0x30300;
              *(undefined4 *)(param_1[1] + 0xf30 + uVar17 * 4) = 0x30500;
              *(uint *)(param_1[1] + 0x2388) = *(uint *)(param_1[1] + 0x2388) | 8;
              *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) | 0x40;
              *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) & 0xefffffff;
              lVar11 = param_1[1];
            }
          }
          if ((*(int *)(lVar11 + 0x26b4) == 0x7e) || (*(int *)(lVar11 + 0x26b4) == 0x7f)) {
            *(uint *)(lVar11 + 0x2480) = *(uint *)(lVar11 + 0x2480) | 0x20000;
            lVar11 = param_1[1];
          }
          if (*(int *)(lVar11 + 0x26b4) == 0x85) {
            *(uint *)(lVar11 + 0x2378) = *(uint *)(lVar11 + 0x2378) | 0x400;
            *(uint *)(param_1[1] + 0x24c0) = *(uint *)(param_1[1] + 0x24c0) & 0xfffffffb;
            puVar1 = (uint *)(param_1[1] + 0xe70 + uVar21 * 0xc);
            *puVar1 = *puVar1 & 0xfffffbff;
            *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x40000;
            *(uint *)(param_1[1] + 0x2388) = *(uint *)(param_1[1] + 0x2388) | 4;
            lVar11 = param_1[1];
          }
          if (*(short *)(lVar11 + 0x26a8) == 0x1b9b) {
            puVar1 = (uint *)(lVar11 + 0xe70 + uVar21 * 0xc);
            *puVar1 = *puVar1 & 0xfffffbff;
            *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x40000;
            *(uint *)(param_1[1] + 0x2388) = *(uint *)(param_1[1] + 0x2388) | 4;
            lVar11 = param_1[1];
          }
          if ((*(int *)(lVar11 + 0x26b4) == 0xc9) || (*(int *)(lVar11 + 0x26b4) == 0xca)) {
            *(uint *)(lVar11 + 0xe70 + uVar17 * 0xc) =
                 *(uint *)(lVar11 + 0xe70 + uVar17 * 0xc) & 0xffff1fff | 0x1000;
            *(uint *)(param_1[1] + 0xe70 + uVar13 * 0xc) =
                 *(uint *)(param_1[1] + 0xe70 + uVar13 * 0xc) & 0xffff1fff | 0x1000;
            *(uint *)(param_1[1] + (local_res18 + 0x134) * 0xc) =
                 *(uint *)(param_1[1] + (local_res18 + 0x134) * 0xc) & 0xffff1fff | 0x1000;
            puVar1 = (uint *)(param_1[1] + 0xe70 + uVar21 * 0xc);
            *puVar1 = *puVar1 & 0xfffffbff;
            *(undefined4 *)(param_1[1] + 0xf30 + uVar16 * 4) = 0x30500;
            lVar11 = param_1[1];
          }
          if ((*(uint *)(lVar11 + 0x2384) & 0x40000) != 0) {
            if ((*(uint *)(lVar11 + 0x2388) & 4) == 0) {
              uVar8 = *(uint *)(lVar11 + 0x2394) | 0x400;
            }
            else {
              uVar8 = *(uint *)(lVar11 + 0x2394) & 0xfffffbff;
            }
            *(uint *)(lVar11 + 0x2394) = uVar8;
          }
          if ((*(uint *)(param_1[1] + 0x2388) & 4) != 0) {
            return param_1;
          }
          puVar1 = (uint *)(param_1[1] + 0x2394);
          *puVar1 = *puVar1 | 0x100;
          return param_1;
        }
        if (uVar8 == 0xb5) {
          FUN_1400304b8(param_2,0x4080,1,0,1,1);
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x400;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x400;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x4000;
          *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) | 0x10000000;
          *(uint *)(param_1[1] + 0x23a0) = *(uint *)(param_1[1] + 0x23a0) | 1;
          *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x100;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000000;
          *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) | 0x200;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x800;
          *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
          *(undefined4 *)(param_1[1] + 0xadc) = 10;
          *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x1000;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 8;
          *(undefined1 *)(param_1[1] + 0xcb6) = 1;
          *(undefined1 *)(param_1[1] + 0xcb4) = 2;
          *(undefined1 *)(param_1[1] + 0xcb3) = 3;
          *(undefined1 *)(param_1[1] + 0xcb2) = 4;
          lVar11 = param_1[1];
          *(uint *)(lVar11 + 0xe70) = (*(byte *)(lVar11 + 0xcb2) & 0xf | 0xfc117420) << 4;
          *(undefined8 *)(lVar11 + 0xe74) = 0;
          *(undefined4 *)(param_1[1] + 0xf30) = 0x30300;
          lVar11 = param_1[1];
          *(uint *)(lVar11 + 0xe7c) = (*(byte *)(lVar11 + 0xcb4) & 0xf | 0x4189300) << 4;
          *(undefined8 *)(lVar11 + 0xe80) = 0;
          *(undefined4 *)(param_1[1] + 0xf34) = 0x30100;
          lVar11 = param_1[1];
          local_58 = (ulonglong)((*(byte *)(lVar11 + 0xcb3) & 0xf | 0x41a8900) << 4);
          *(ulonglong *)(lVar11 + 0xe88) = local_58;
          *(undefined4 *)(lVar11 + 0xe90) = 0;
          *(undefined4 *)(param_1[1] + 0xf38) = 0x30500;
          if (*(int *)(param_1[1] + 0x26b4) != 0x9e) {
            return param_1;
          }
          *(undefined4 *)(param_1[1] + 0x25a4) = 0x28;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
          goto LAB_1400407d1;
        }
        if (uVar8 == 0xb6) {
          FUN_1400304b8(param_2,0x4050,1,1,1,1);
          local_58 = 0xd0330130;
        }
        else {
          if (uVar8 == 0xb7) {
LAB_14004163d:
            uVar6 = 0x4042;
            uVar8 = 1;
            goto LAB_14004164f;
          }
          if (uVar8 != 0xb8) goto LAB_140043e58;
          FUN_1400304b8(param_2,0x4042,1,1,1,1);
          local_58 = 0x40a80110;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
        }
        lVar11 = param_1[1];
        goto LAB_14003fa60;
      }
      *(uint *)(param_2 + 0x2384) = *(uint *)(param_2 + 0x2384) & 0xfffbffff;
      uVar8 = 6;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x80000;
      lVar11 = param_1[1];
      iVar15 = *(int *)(lVar11 + 0x26b4);
      if (iVar15 == 0x8d) {
        *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) | 0x400000;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x800000;
        lVar11 = param_1[1];
        iVar15 = *(int *)(lVar11 + 0x38);
        if ((*(uint *)(lVar11 + 0x2384) & 0x800000) == 0) {
LAB_140042806:
          if (iVar15 == 6) {
            *(undefined1 *)(lVar11 + 0xcb6) = 1;
            goto LAB_140042819;
          }
          *(undefined1 *)(lVar11 + 0xcb6) = 0;
          *(undefined1 *)(param_1[1] + 0xcb4) = 1;
          *(undefined1 *)(param_1[1] + 0xcb3) = 2;
          *(undefined1 *)(param_1[1] + 0xcb2) = 3;
          *(undefined1 *)(param_1[1] + 0xcb0) = 4;
          *(undefined1 *)(param_1[1] + 0xcb5) = 5;
        }
        else {
          uVar13 = uVar16;
          if (iVar15 == 7) {
            do {
              cVar5 = (char)uVar16;
              uVar10 = (int)uVar16 + 1;
              uVar16 = (ulonglong)uVar10;
              *(char *)(uVar13 + 0xcb6 + param_1[1]) = cVar5 + '\x01';
              uVar13 = uVar13 + 1;
            } while ((int)uVar10 < 2);
            *(undefined1 *)(param_1[1] + 0xcb4) = 3;
            *(undefined1 *)(param_1[1] + 0xcb3) = 4;
            *(undefined1 *)(param_1[1] + 0xcb2) = 5;
            *(undefined1 *)(param_1[1] + 0xcb0) = 6;
            *(undefined1 *)(param_1[1] + 0xcb5) = 7;
          }
          else {
            do {
              *(char *)(uVar13 + 0xcb6 + param_1[1]) = (char)uVar16;
              uVar10 = (int)uVar16 + 1;
              uVar16 = (ulonglong)uVar10;
              uVar13 = uVar13 + 1;
            } while ((int)uVar10 < 2);
LAB_140042819:
            *(undefined1 *)(param_1[1] + 0xcb4) = 2;
            *(undefined1 *)(param_1[1] + 0xcb3) = 3;
            *(undefined1 *)(param_1[1] + 0xcb2) = 4;
            *(undefined1 *)(param_1[1] + 0xcb0) = 5;
            *(undefined1 *)(param_1[1] + 0xcb5) = 6;
          }
        }
      }
      else {
        if ((iVar15 == 0x8a) || (iVar15 - 0x74U < 5)) {
          if (*(int *)(lVar11 + 0x38) == 5) {
            *(undefined1 *)(lVar11 + 0xcb6) = 1;
            *(undefined1 *)(param_1[1] + 0xcb4) = 2;
            *(undefined1 *)(param_1[1] + 0xcb3) = 3;
            *(undefined1 *)(param_1[1] + 0xcb2) = 4;
            *(undefined1 *)(param_1[1] + 0xcb0) = 5;
          }
          else {
            *(undefined1 *)(lVar11 + 0xcb6) = 0;
            *(undefined1 *)(param_1[1] + 0xcb4) = 1;
            *(undefined1 *)(param_1[1] + 0xcb3) = 2;
            *(undefined1 *)(param_1[1] + 0xcb2) = 3;
            *(undefined1 *)(param_1[1] + 0xcb0) = 4;
          }
LAB_14004295b:
          *(undefined1 *)(param_1[1] + 0xcb5) = 0;
        }
        else {
          if (iVar15 != 0x8b && iVar15 != 0x8c) {
            if ((iVar15 - 0x1bU & 0xfffffffd) != 0) {
              iVar15 = *(int *)(lVar11 + 0x38);
              goto LAB_140042806;
            }
            *(undefined1 *)(lVar11 + 0xcb6) = 1;
            *(undefined1 *)(param_1[1] + 0xcb4) = 2;
            *(undefined1 *)(param_1[1] + 0xcb3) = 3;
            *(undefined1 *)(param_1[1] + 0xcb2) = 4;
            *(undefined1 *)(param_1[1] + 0xcb0) = 5;
            *(undefined1 *)(param_1[1] + 0xcb8) = 6;
            goto LAB_14004295b;
          }
          *(undefined1 *)(lVar11 + 0xcb6) = 1;
          *(undefined1 *)(param_1[1] + 0xcb4) = 2;
          *(undefined1 *)(param_1[1] + 0xcb3) = 3;
          *(undefined1 *)(param_1[1] + 0xcb2) = 4;
          *(undefined1 *)(param_1[1] + 0xcb0) = 5;
          *(undefined1 *)(param_1[1] + 0xcb5) = 6;
        }
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x100000;
      }
      lVar11 = param_1[1];
      if ((*(uint *)(lVar11 + 0x2384) & 0x40000) != 0) {
        *(uint *)(lVar11 + 0x2394) = *(uint *)(lVar11 + 0x2394) | 0x400;
        lVar11 = param_1[1];
      }
      *(undefined2 *)(lVar11 + 0xe68) = 0x4080;
      *(undefined4 *)(param_1[1] + 0xfc8) = 0x1220;
      *(undefined1 *)(param_1[1] + 0xe6a) = 0x1c;
      *(undefined4 *)(param_1[1] + 0xe6c) = 0;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x8000;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x400;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x400;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x4000;
      *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) | 0x10000000;
      *(uint *)(param_1[1] + 0x23a0) = *(uint *)(param_1[1] + 0x23a0) | 1;
      *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x100;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000000;
      *(uint *)(param_1[1] + 0x2390) = *(uint *)(param_1[1] + 0x2390) | 0x200;
      *(uint *)(param_1[1] + 0x23f4) = *(uint *)(param_1[1] + 0x23f4) | 0x100;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x1000;
      lVar11 = param_1[1];
      if (*(int *)(lVar11 + 0x26b4) == 0x90) {
        *(uint *)(lVar11 + 0x2378) = *(uint *)(lVar11 + 0x2378) | 0x400;
        lVar11 = param_1[1];
      }
      if (*(short *)(lVar11 + 0x26aa) == 0xdb0) {
        *(uint *)(lVar11 + 0x2394) = *(uint *)(lVar11 + 0x2394) | 0x8000;
        lVar11 = param_1[1];
      }
      iVar15 = *(int *)(lVar11 + 0x26b4);
      if ((((iVar15 == 0x1b) || (iVar15 == 0x1d)) || (iVar15 == 0x4d)) ||
         ((iVar15 == 0x4e || (iVar15 == 0x8e)))) {
        *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) & 0xffffefff;
        lVar11 = param_1[1];
      }
      *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) | 0x2000;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
      *(undefined4 *)(param_1[1] + 0xad8) = 0x1e;
      *(undefined4 *)(param_1[1] + 0xadc) = 10;
      lVar11 = param_1[1];
      *(uint *)(lVar11 + 0xe70) = (*(byte *)(lVar11 + 0xcb0) & 0xf | 0xf8221400) << 4;
      *(undefined8 *)(lVar11 + 0xe74) = 0;
      *(undefined4 *)(param_1[1] + 0xf30) = 0x30000;
      lVar11 = param_1[1];
      *(uint *)(lVar11 + 0xe7c) = (*(byte *)(lVar11 + 0xcb2) & 0xf | 0xfc117420) << 4;
      *(undefined8 *)(lVar11 + 0xe80) = 0;
      *(undefined4 *)(param_1[1] + 0xf34) = 0x30300;
      lVar11 = param_1[1];
      *(uint *)(lVar11 + 0xe88) = (*(byte *)(lVar11 + 0xcb2) & 0xf) << 4 | 0xc11b1001;
      *(undefined8 *)(lVar11 + 0xe8c) = 0;
      *(undefined4 *)(param_1[1] + 0xf38) = 0x30200;
      lVar11 = param_1[1];
      *(uint *)(lVar11 + 0xe94) = (*(byte *)(lVar11 + 0xcb2) & 0xf) << 4 | 0xc11a7002;
      *(undefined8 *)(lVar11 + 0xe98) = 0;
      *(undefined4 *)(param_1[1] + 0xf3c) = 0x30000;
      lVar11 = param_1[1];
      *(uint *)(lVar11 + 0xea0) = (*(byte *)(lVar11 + 0xcb2) & 0xf) << 4 | 0xc11c2003;
      *(undefined8 *)(lVar11 + 0xea4) = 0;
      *(undefined4 *)(param_1[1] + 0xf40) = 0x80000;
      lVar11 = param_1[1];
      *(uint *)(lVar11 + 0xeac) = (*(byte *)(lVar11 + 0xcb3) & 0xf | 0x41a8900) << 4;
      *(undefined8 *)(lVar11 + 0xeb0) = 0;
      *(undefined4 *)(param_1[1] + 0xf44) = 0x30500;
      lVar11 = param_1[1];
      if (*(byte *)(lVar11 + 0xcb6) != 0) {
        uVar8 = 7;
        *(uint *)(lVar11 + 0xeb8) = (*(byte *)(lVar11 + 0xcb6) & 0xf | 0xfded9310) << 4;
        *(undefined8 *)(lVar11 + 0xebc) = 0;
        *(undefined4 *)(param_1[1] + 0xf48) = 0x80000;
        lVar11 = param_1[1];
      }
      uVar16 = (ulonglong)uVar8;
      *(uint *)(lVar11 + 0xe70 + uVar16 * 0xc) = (*(byte *)(lVar11 + 0xcb4) & 0xf | 0x4189340) << 4;
      *(undefined4 *)(lVar11 + 0xe74 + uVar16 * 0xc) = 0;
      *(undefined4 *)(lVar11 + 0xe78 + uVar16 * 0xc) = 0;
      *(undefined4 *)(param_1[1] + 0xf30 + uVar16 * 4) = 0x30100;
      uVar10 = uVar8 + 1;
      lVar11 = param_1[1];
      local_res20 = uVar8 + 2;
      lVar12 = (ulonglong)uVar10 + 0x134;
      if ((*(uint *)(lVar11 + 0x2384) & 0x80000) == 0) {
        bVar2 = *(byte *)(lVar11 + 0xcb1);
      }
      else {
        bVar2 = *(byte *)(lVar11 + 0xcb3);
      }
      *(uint *)(lVar11 + lVar12 * 0xc) = (bVar2 & 0xf | 0xfc2b8940) << 4;
      *(undefined4 *)(lVar11 + 4 + lVar12 * 0xc) = 0;
      *(undefined4 *)(lVar11 + 8 + lVar12 * 0xc) = 0;
      *(undefined4 *)(param_1[1] + 0xf30 + (ulonglong)uVar10 * 4) = 0x30100;
      lVar11 = param_1[1];
      if (*(byte *)(lVar11 + 0xcb5) != 0) {
        lVar12 = (ulonglong)local_res20 + 0x134;
        *(uint *)(lVar11 + lVar12 * 0xc) = (*(byte *)(lVar11 + 0xcb5) & 0xf | 0x414e150) << 4;
        *(undefined4 *)(lVar11 + 4 + lVar12 * 0xc) = 0;
        *(undefined4 *)(lVar11 + 8 + lVar12 * 0xc) = 0;
        local_res18._0_4_ = 0x700;
        uVar7 = 0x80000;
        if (*(int *)(param_1[1] + 0x26b4) != 0x91) {
          uVar7 = (undefined4)local_res18;
        }
        *(undefined4 *)(param_1[1] + 0xf30 + (ulonglong)local_res20 * 4) = uVar7;
        *(uint *)(param_1[1] + lVar12 * 0xc) =
             *(uint *)(param_1[1] + lVar12 * 0xc) & 0xffff6fff | 0x6000;
        lVar11 = param_1[1];
        local_res20 = uVar8 + 3;
      }
      if ((*(uint *)(lVar11 + 0x2384) >> 0x16 & 1) != 0) {
        if ((*(uint *)(lVar11 + 0x2384) >> 0x17 & 1) == 0) {
          bVar2 = *(byte *)(lVar11 + 0xcb0);
        }
        else {
          bVar2 = *(byte *)(lVar11 + 0xcb7);
        }
        uVar13 = (ulonglong)local_res20;
        local_58 = (ulonglong)((bVar2 & 0xf | 0x402f000) << 4) | 0x1001400;
        *(ulonglong *)(lVar11 + 0xe70 + uVar13 * 0xc) = local_58;
        *(undefined4 *)(lVar11 + 0xe78 + uVar13 * 0xc) = 0;
        local_res20 = local_res20 + 1;
        *(undefined4 *)(param_1[1] + 0xf30 + uVar13 * 4) = 0x30400;
        lVar11 = param_1[1];
      }
      *(uint *)(lVar11 + 0xe6c) = *(uint *)(lVar11 + 0xe6c) & 0xfffffff3 | 3;
      *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff4f | 0x40;
      *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffff6ff | 0x600;
      *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffff1fff | 0x1000;
      *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfff2ffff | 0x20000;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 8;
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x800;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x400;
      *(uint *)(param_1[1] + 0x23a0) = *(uint *)(param_1[1] + 0x23a0) | 1;
      *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x100;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
      *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
      lVar12 = uVar16 * 3 + 0x39c;
      *(uint *)(param_1[1] + lVar12 * 4) = *(uint *)(param_1[1] + lVar12 * 4) & 0xffff3fff | 0x3000;
      *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff6fff | 0x6000;
      *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff9fff | 0x9000;
      *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff4fff | 0x4000;
      lVar11 = param_1[1];
      if (*(int *)(lVar11 + 0x26b4) == 0x87) {
        *(undefined4 *)(lVar11 + 0x25a4) = 0x1e;
        *(uint *)(param_1[1] + 0x24f4) = *(uint *)(param_1[1] + 0x24f4) | 0x2000000;
        *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x8000;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000000;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xfffff7ff;
      }
      else {
        if (9 < *(int *)(lVar11 + 0x26b4) - 0x88U) goto LAB_14004308b;
        *(undefined4 *)(lVar11 + 0x25a4) = 0x1f;
        *(uint *)(param_1[1] + 0x24f4) = *(uint *)(param_1[1] + 0x24f4) | 0x2000000;
        *(uint *)(param_1[1] + 0x2394) = *(uint *)(param_1[1] + 0x2394) | 0x8000;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x2000000;
        lVar11 = param_1[1];
        if (*(int *)(lVar11 + 0x26b4) - 0x8bU < 2) {
          *(uint *)(lVar11 + 0x237c) = *(uint *)(lVar11 + 0x237c) & 0xfffff7ff;
        }
        else {
          *(uint *)(lVar11 + 0x237c) = *(uint *)(lVar11 + 0x237c) | 0x800;
        }
      }
      *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) | 0x200;
LAB_14004308b:
      lVar11 = param_1[1];
      uVar8 = *(int *)(lVar11 + 0x26b4) - 0x88;
      if (((uVar8 < 10) && ((0x38bU >> (uVar8 & 0x1f) & 1) != 0)) ||
         (*(int *)(lVar11 + 0x26b4) == 0x8c)) {
        *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) | 0x1000000;
        lVar11 = param_1[1];
      }
      if (((((ushort)(*(short *)(lVar11 + 0x26a8) + 0xe5aeU) < 2) ||
           (*(short *)(lVar11 + 0x26a8) == 10000)) || (*(int *)(lVar11 + 0x26b4) == 0x89)) ||
         (*(int *)(lVar11 + 0x26b4) == 0x90)) {
        *(uint *)(lVar11 + 0x24c0) = *(uint *)(lVar11 + 0x24c0) & 0xfffffffb;
        lVar11 = param_1[1];
      }
      if (*(short *)(lVar11 + 0x26a8) == 0x4039) {
        *(uint *)(lVar11 + 0x2380) = *(uint *)(lVar11 + 0x2380) | 0x80000;
        *(undefined4 *)(param_1[1] + 0xbf0) = 1;
        lVar11 = param_1[1];
      }
      if ((*(int *)(lVar11 + 0x26b4) == 0x89) || (*(int *)(lVar11 + 0x26b4) == 0x90)) {
        *(uint *)(lVar11 + 0x2388) = *(uint *)(lVar11 + 0x2388) | 2;
        *(undefined4 *)(param_1[1] + 0xcdc) = 1;
        *(undefined4 *)(param_1[1] + 0xaec) = 1;
        lVar11 = param_1[1];
      }
      uVar8 = *(int *)(lVar11 + 0x26b4) - 0x4d;
      if (((uVar8 < 0x2a) && ((0x3f6ffffe7ffU >> ((ulonglong)uVar8 & 0x3f) & 1) != 0)) ||
         (*(int *)(lVar11 + 0x26b4) == 0x77)) {
        *(undefined4 *)(lVar11 + 0x25a4) = 0x14;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
        *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + lVar12 * 4) =
             *(uint *)(param_1[1] + lVar12 * 4) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff5fff | 0x5000;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x1000000;
        lVar11 = param_1[1];
        if (*(int *)(lVar11 + 0x26b4) == 0x54) {
          *(uint *)(lVar11 + 0x2380) = *(uint *)(lVar11 + 0x2380) | 0x80000;
          *(undefined4 *)(param_1[1] + 0xbf0) = 1;
          *(undefined4 *)(param_1[1] + 0xbf8) = 1;
          lVar11 = param_1[1];
        }
        if (*(short *)(lVar11 + 0x26a8) == -0x6193) {
          *(undefined4 *)(lVar11 + 0x25a4) = 0x15;
          lVar11 = param_1[1];
        }
      }
      if ((*(int *)(lVar11 + 0x26b4) - 0x58U < 2) || (*(int *)(lVar11 + 0x26b4) == 0x6d)) {
        *(undefined4 *)(lVar11 + 0x25a4) = 0x15;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
        *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + lVar12 * 4) =
             *(uint *)(param_1[1] + lVar12 * 4) & 0xffff3fff | 0x3000;
        *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff6fff | 0x6000;
        *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff9fff | 0x9000;
        *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff4fff | 0x4000;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x1000000;
        lVar11 = param_1[1];
      }
      if (*(int *)(lVar11 + 0x26b4) == 0x70) {
        *(undefined4 *)(lVar11 + 0x25a4) = 0x15;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
        *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) =
             *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff5fff | 0x5000;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x1000000;
        lVar11 = param_1[1];
      }
      if (*(int *)(lVar11 + 0x26b4) == 0x78) {
        *(undefined4 *)(lVar11 + 0x25a4) = 0x16;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
        *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) =
             *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff5fff | 0x5000;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x1000000;
        lVar11 = param_1[1];
      }
      if ((*(int *)(lVar11 + 0x26b4) - 0x97U < 3) || (*(int *)(lVar11 + 0x26b4) == 0x9a)) {
        *(undefined4 *)(lVar11 + 0x25a4) = 0x28;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x400;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
        *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) =
             *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) & 0xffff3fff | 0x3000;
        *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff6fff | 0x6000;
        *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff9fff | 0x9000;
        *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff4fff | 0x4000;
        lVar11 = param_1[1];
      }
      if ((*(int *)(lVar11 + 0x26b4) == 0x99) || (*(int *)(lVar11 + 0x26b4) == 0x9a)) {
        *(uint *)(lVar11 + 0x2384) = *(uint *)(lVar11 + 0x2384) | 0x200000;
        *(undefined4 *)(param_1[1] + 0xf40) = 0x30400;
        puVar1 = (uint *)(param_1[1] + 0xe70 + uVar16 * 0xc);
        *puVar1 = *puVar1 & 0xfffffbff;
        lVar11 = param_1[1];
      }
      if (*(int *)(lVar11 + 0x26b4) == 0xac) {
        *(uint *)(lVar11 + 0x2374) = *(uint *)(lVar11 + 0x2374) & 0xfffffbff;
        *(uint *)(param_1[1] + 0x24fc) = *(uint *)(param_1[1] + 0x24fc) & 0xefffffff;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
        *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) =
             *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) & 0xffff3fff | 0x3000;
        *(uint *)(param_1[1] + 0xe94) = *(uint *)(param_1[1] + 0xe94) & 0xffff6fff | 0x6000;
        *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff9fff | 0x9000;
        *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xffff4fff | 0x4000;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x80000;
        lVar11 = param_1[1];
      }
      if (*(int *)(lVar11 + 0x26b4) == 0x7c) {
        puVar1 = (uint *)(lVar11 + ((ulonglong)uVar10 + 0x134) * 0xc);
        *puVar1 = *puVar1 & 0xfffffbff;
        lVar11 = param_1[1];
      }
      if ((*(uint *)(lVar11 + 0x2384) & 0x100000) == 0) {
        return param_1;
      }
      *(uint *)(lVar11 + 0xe7c) = *(uint *)(lVar11 + 0xe7c) & 0xffff4fff | 0x4000;
      lVar11 = uVar16 + 0x134;
      *(undefined4 *)(param_1[1] + 0xf34) = 0x30300;
      *(undefined4 *)(param_1[1] + 0xf38) = 0x80000;
      *(undefined4 *)(param_1[1] + 0xf3c) = 0x80000;
      *(undefined4 *)(param_1[1] + 0xf40) = 0x80000;
      *(uint *)(param_1[1] + lVar11 * 0xc) =
           *(uint *)(param_1[1] + lVar11 * 0xc) & 0xffff3fff | 0x3000;
      *(undefined4 *)(param_1[1] + 0xf30 + uVar16 * 4) = 0x30100;
      *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff9fff | 0x9000;
      *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) | 0x400;
      *(undefined4 *)(param_1[1] + 0xf44) = 0x30500;
      lVar12 = param_1[1];
      if ((*(int *)(lVar12 + 0x26b4) - 0x74U < 3) || (*(int *)(lVar12 + 0x26b4) == 0x77)) {
        *(uint *)(lVar12 + 0xe7c) = *(uint *)(lVar12 + 0xe7c) & 0xffff5fff | 0x5000;
        *(uint *)(param_1[1] + lVar11 * 0xc) =
             *(uint *)(param_1[1] + lVar11 * 0xc) & 0xffff1fff | 0x1000;
        *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff1fff | 0x1000;
        lVar12 = param_1[1];
      }
      if ((*(int *)(lVar12 + 0x26b4) - 0x1bU & 0xfffffffd) != 0) {
        return param_1;
      }
      *(uint *)(lVar12 + 0xe7c) = *(uint *)(lVar12 + 0xe7c) & 0xffff3fff | 0x3000;
      uVar13 = (ulonglong)local_res20;
      *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) =
           *(uint *)(param_1[1] + 0xe70 + uVar16 * 0xc) & 0xffff4fff | 0x4000;
      *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) & 0xffff9fff | 0x9000;
      *(undefined4 *)(param_1[1] + 0xf34) = 0x30100;
      *(undefined4 *)(param_1[1] + 0xf38) = 0x80000;
      *(undefined4 *)(param_1[1] + 0xf3c) = 0x80000;
      *(undefined4 *)(param_1[1] + 0xf40) = 0x80000;
      *(undefined4 *)(param_1[1] + 0xf30 + uVar16 * 4) = 0x30300;
      *(undefined4 *)(param_1[1] + 0xf44) = 0x30500;
      lVar11 = param_1[1];
      *(undefined8 *)(lVar11 + 0xe70 + uVar13 * 0xc) = 0xd0330160;
      *(undefined4 *)(lVar11 + 0xe78 + uVar13 * 0xc) = 0;
      *(undefined4 *)(param_1[1] + 0xf30 + uVar13 * 4) = 0x80000;
      *(uint *)(param_1[1] + 0xeac) = *(uint *)(param_1[1] + 0xeac) | 0x400;
      return param_1;
    }
    if (0xc3 < uVar8) {
      if (uVar8 != 0xc4) {
        if (uVar8 == 0xc5) {
          FUN_1400304b8(param_2,0x4050,1,0,1,1);
          *(undefined2 *)(param_1[1] + 0x26ac) = 0x1028;
          *(undefined4 *)(param_1[1] + 0x25a4) = 1;
          *(undefined1 *)(param_1[1] + 0xcb3) = 1;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x41a89010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          *(undefined4 *)(param_1[1] + 0xf30) = 0x80000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0xc1174220;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          *(undefined4 *)(param_1[1] + 0xf34) = 0x30000;
          *(uint *)(param_1[1] + 0x1004) = *(uint *)(param_1[1] + 0x1004) | 0x200;
          *(undefined4 *)(param_1[1] + 0x1034) = 2;
          return param_1;
        }
        if (uVar8 == 0xc6) {
          uVar6 = 0x4050;
          uVar8 = 0;
          goto LAB_14004164f;
        }
        if (uVar8 == 199) {
          FUN_1400304b8(param_2,0x4050,1,1,0,1);
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffeff;
          return param_1;
        }
        if (uVar8 == 0xcb) {
          FUN_1400304b8(param_2,0x4032,1,1,0,1);
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x40a80010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          *(undefined1 *)(param_1[1] + 0xcb1) = 1;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffeff;
          *(uint *)(param_1[1] + 0x2434) = *(uint *)(param_1[1] + 0x2434) | 0x100;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
          goto LAB_14003ec24;
        }
        if (uVar8 == 0xce) {
          FUN_1400304b8(param_2,0x4052,1,1,1,1);
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x40a80110;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe7c) = 0x100;
          *(undefined4 *)(lVar11 + 0xe84) = 0;
          *(undefined4 *)(param_1[1] + 0xf34) = 0x80000;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe88) = 0x80210130;
          *(undefined4 *)(lVar11 + 0xe90) = 0;
          return param_1;
        }
        if (uVar8 == 0xcf) {
          FUN_1400304b8(param_2,0x4042,1,1,0,0);
          *(uint *)(param_1[1] + 0x2388) = *(uint *)(param_1[1] + 0x2388) | 0x10;
          return param_1;
        }
        goto LAB_140043e58;
      }
      FUN_1400304b8(param_2,0x4042,1,0,1,1);
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
LAB_140044fb1:
      lVar11 = param_1[1];
      *(undefined8 *)(lVar11 + 0xe70) = 0x40a80010;
      *(undefined4 *)(lVar11 + 0xe78) = 0;
      lVar11 = param_1[1];
      *(undefined8 *)(lVar11 + 0xe7c) = 0x80210020;
      *(undefined4 *)(lVar11 + 0xe84) = 0;
LAB_140044fea:
      lVar11 = param_1[1];
LAB_140044fee:
      *(uint *)(lVar11 + 0xe6c) = *(uint *)(lVar11 + 0xe6c) | 0xf;
      return param_1;
    }
    if (uVar8 == 0xc3) {
      *(undefined1 *)(param_2 + 0xcb1) = 1;
      return param_1;
    }
    if (uVar8 == 0xba) {
      FUN_1400304b8(param_2,0x4032,1,1,1,1);
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x40;
      *(undefined2 *)(param_1[1] + 0xc0) = 0x7e5;
      *(undefined2 *)(param_1[1] + 0xc2) = 0xc;
      *(undefined2 *)(param_1[1] + 0xc4) = 0x1f;
      FUN_140030480(param_1[1]);
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) & 0xffffffef;
      *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) | 0x200;
      return param_1;
    }
    if (uVar8 == 0xbb) {
      FUN_1400304b8(param_2,0x4050,1,1,1,1);
      *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x40;
      *(undefined2 *)(param_1[1] + 0xc0) = 0x7e5;
      *(undefined2 *)(param_1[1] + 0xc2) = 6;
      *(undefined2 *)(param_1[1] + 0xc4) = 0x1e;
LAB_140043b31:
      FUN_140030480(param_1[1]);
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x200;
      *(undefined4 *)(param_1[1] + 0xad8) = 0x28;
      *(undefined4 *)(param_1[1] + 0xadc) = 10;
      return param_1;
    }
    if (uVar8 == 0xbc) {
      FUN_1400304b8(param_2,0x4042,0,1,1,1);
      FUN_140030480(param_1[1]);
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 2;
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x8000;
      FUN_14004c5d4((undefined8 *)(param_1[1] + 0xe8),FUN_140027fb0,param_1[1],500,0);
      lVar11 = param_1[1];
      *(undefined8 *)(lVar11 + 0xe70) = 0x40a80110;
      *(undefined4 *)(lVar11 + 0xe78) = 0;
      return param_1;
    }
    if (uVar8 == 0xbd) {
      FUN_1400304b8(param_2,0x4032,1,1,1,1);
      FUN_140030480(param_1[1]);
      *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 0x10;
      *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) | 0x200;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) & 0xfffffff7;
      uVar13 = uVar16;
      do {
        cVar5 = (char)uVar16;
        uVar8 = (int)uVar16 + 1;
        uVar16 = (ulonglong)uVar8;
        *(char *)(uVar13 + 0xcb1 + param_1[1]) = cVar5 + '\x01';
        uVar13 = uVar13 + 1;
      } while ((int)uVar8 < 2);
      lVar11 = param_1[1];
      *(uint *)(lVar11 + 0xe70) = (*(byte *)(lVar11 + 0xcb1) & 0xf | 0x40a8010) << 4;
      *(undefined8 *)(lVar11 + 0xe74) = 0;
      lVar11 = param_1[1];
      local_58 = (ulonglong)((*(byte *)(lVar11 + 0xcb2) & 0xf | 0xfc017010) << 4);
      *(ulonglong *)(lVar11 + 0xe7c) = local_58;
      *(undefined4 *)(lVar11 + 0xe84) = 0;
      return param_1;
    }
    if (uVar8 == 0xbe) {
      FUN_1400304b8(param_2,0x4050,1,1,1,1);
      goto LAB_140043b31;
    }
    if (uVar8 == 0xbf) {
LAB_140043af9:
      uVar6 = 0x4032;
      uVar8 = 0;
LAB_14004164f:
      FUN_1400304b8(param_2,uVar6,1,1,uVar8,1);
      return param_1;
    }
    if (uVar8 == 0xc0) {
      if (*(int *)(param_2 + 0x26b4) != 0xc1) {
        *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
        *(undefined2 *)(param_1[1] + 0xe68) = 0x4042;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
        lVar11 = param_1[1];
        *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
        *(undefined4 *)(lVar11 + 0xe78) = 0;
        lVar11 = param_1[1];
        *(undefined4 *)(lVar11 + 0xe7c) = 0x82211c20;
        *(undefined8 *)(lVar11 + 0xe80) = 0;
        *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xfffffbff;
        *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x80000;
        goto LAB_140040a14;
      }
      FUN_1400304b8(param_2,0x4032,1,0,0,1);
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x80000;
      goto LAB_140044fb1;
    }
    if (uVar8 == 0xc2) {
      FUN_1400304b8(param_2,0x4050,1,0,0,1);
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x800;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 4;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 8;
      do {
        uVar8 = (int)uVar16 + 1;
        uVar16 = (ulonglong)uVar8;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | uVar8;
      } while ((int)uVar8 < 2);
      *(undefined4 *)(param_1[1] + 0x25a4) = 1;
      *(uint *)(param_1[1] + 0x24c0) = *(uint *)(param_1[1] + 0x24c0) & 0xfffffffb;
      lVar11 = param_1[1];
      *(undefined8 *)(lVar11 + 0xe70) = 0x42a81010;
      *(undefined4 *)(lVar11 + 0xe78) = 0;
      lVar11 = param_1[1];
      *(undefined8 *)(lVar11 + 0xe7c) = 0x82211420;
      *(undefined4 *)(lVar11 + 0xe84) = 0;
      *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
      goto LAB_14003ec24;
    }
LAB_140043e58:
    sVar3 = *(short *)(param_2 + 0x26aa);
    if (sVar3 == 0x17ef) {
      if (*(short *)(param_2 + 0x26a8) != 0x3064) {
        return param_1;
      }
      goto LAB_14004478a;
    }
    if (sVar3 != 0x18d1) {
      if (sVar3 == 0x5bdb) {
        *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
LAB_140044d15:
        *(undefined2 *)(param_1[1] + 0xe68) = 0x4042;
        return param_1;
      }
      uVar4 = *(ushort *)(param_2 + 0x26a8);
      if (uVar4 < 0x4826) {
        if (uVar4 == 0x4825) {
LAB_140044714:
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
          *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
LAB_14004481a:
          *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
          goto LAB_140044825;
        }
        if (uVar4 < 0x400e) {
          if (uVar4 == 0x400d) {
            *(undefined4 *)(param_2 + 0xad8) = 1;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x10;
            do {
              uVar8 = (int)uVar16 + 1;
              uVar16 = (ulonglong)uVar8;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | uVar8;
            } while ((int)uVar8 < 2);
LAB_140044125:
            *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
LAB_1400445c1:
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
            *(undefined4 *)(lVar11 + 0xe78) = 0;
            lVar11 = param_1[1];
            *(undefined4 *)(lVar11 + 0xe7c) = 0x82211c20;
            *(undefined8 *)(lVar11 + 0xe80) = 0;
            goto LAB_140044b9d;
          }
          if (uVar4 < 0x4007) {
            if (uVar4 == 0x4006) {
              return param_1;
            }
            if (uVar4 == 0x929) {
              *(undefined4 *)(param_2 + 0x160) = 500;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x80000;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x2000;
              *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
              lVar11 = param_1[1];
              *(undefined4 *)(lVar11 + 0xe70) = 0x81211c10;
              *(undefined8 *)(lVar11 + 0xe74) = 0;
              *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff2 | 2;
              goto LAB_140044ba8;
            }
            if (uVar4 == 0x4000) {
              return param_1;
            }
            if (uVar4 == 0x4002) {
              *(undefined1 *)(param_2 + 0xe6a) = 0x34;
              *(undefined2 *)(param_1[1] + 0xe68) = 0x5651;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              goto LAB_140044c7c;
            }
            if (uVar4 == 0x4003) {
              *(undefined2 *)(param_2 + 0xe68) = 0x288;
LAB_140044218:
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              lVar11 = param_1[1];
              *(undefined4 *)(lVar11 + 0xe7c) = 0x82211c20;
              *(undefined8 *)(lVar11 + 0xe80) = 0;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe88) = 0x421a3030;
              *(undefined4 *)(lVar11 + 0xe90) = 0;
              *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
              lVar11 = param_1[1];
              uVar8 = *(uint *)(lVar11 + 0xe6c) & 0xffffff1f | 0x10;
              goto LAB_140044cb9;
            }
            if (uVar4 == 0x4005) {
              *(undefined2 *)(param_2 + 0xe68) = 0x288;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
              *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x8000;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              lVar11 = param_1[1];
              *(undefined4 *)(lVar11 + 0xe7c) = 0x82211020;
              goto LAB_140043f56;
            }
          }
          else {
            if (uVar4 == 0x4007) {
              return param_1;
            }
            if (uVar4 == 0x4009) {
              return param_1;
            }
            if (uVar4 == 0x400a) {
              *(undefined4 *)(param_2 + 0x2488) = 0x15;
              *(undefined4 *)(param_1[1] + 0x2498) = 500;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 8;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x10;
              do {
                uVar8 = (int)uVar16 + 1;
                uVar16 = (ulonglong)uVar8;
                *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | uVar8;
              } while ((int)uVar8 < 2);
              goto LAB_140044125;
            }
            if (uVar4 == 0x400b) {
              *(uint *)(param_2 + 0x2374) = *(uint *)(param_2 + 0x2374) | 0x10;
              *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
              *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x42a81c10;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe7c) = 0x42ba9c20;
              *(undefined4 *)(lVar11 + 0xe84) = 0;
              lVar11 = param_1[1];
              *(undefined4 *)(lVar11 + 0xe88) = 0x82211c30;
              *(undefined8 *)(lVar11 + 0xe8c) = 0;
              *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
              lVar11 = param_1[1];
              uVar8 = *(uint *)(lVar11 + 0xe6c) & 0xffffff6f | 0x60;
              goto LAB_140044cb9;
            }
          }
        }
        else if (uVar4 < 0x4041) {
          if (uVar4 == 0x4040) {
            uVar8 = *(uint *)(param_2 + 0x2380) & 0xfffffffe;
            if (*(char *)(param_2 + 0x26fc) == ' ') {
              uVar8 = *(uint *)(param_2 + 0x2380) | 1;
            }
            *(uint *)(param_2 + 0x2380) = uVar8;
            *(undefined4 *)(param_1[1] + 0x2488) = 0x15;
            *(undefined4 *)(param_1[1] + 0x2498) = 500;
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 8;
            *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
            goto LAB_1400445c1;
          }
          if (uVar4 == 0x400f) {
            *(undefined4 *)(param_2 + 0x2488) = 0x15;
            *(undefined4 *)(param_1[1] + 0x2498) = 500;
            *(undefined4 *)(param_1[1] + 0xad8) = 1;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x10;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
            *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 2;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe70) = 0x42a81c10;
            *(undefined4 *)(lVar11 + 0xe78) = 0;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe7c) = 0x82211c20;
            *(undefined4 *)(lVar11 + 0xe84) = 0;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe88) = 0x42374830;
            *(undefined4 *)(lVar11 + 0xe90) = 0;
            *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
            lVar11 = param_1[1];
            uVar8 = *(uint *)(lVar11 + 0xe6c) & 0xffffff7f | 0x70;
            goto LAB_140044cb9;
          }
          if (uVar4 == 0x4010) {
            *(uint *)(param_2 + 0x2374) = *(uint *)(param_2 + 0x2374) | 0x10;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
            *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
            *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
            *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x8000;
            *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe70) = 0x42a89110;
            *(undefined4 *)(lVar11 + 0xe78) = 0;
            lVar11 = param_1[1];
            *(undefined4 *)(lVar11 + 0xe7c) = 0x82211120;
LAB_140043f56:
            *(undefined8 *)(lVar11 + 0xe80) = 0;
            goto LAB_140044c91;
          }
          if (uVar4 == 0x4011) {
            *(uint *)(param_2 + 0x2374) = *(uint *)(param_2 + 0x2374) | 0x10;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 4;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 8;
            *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe70) = 0x41a89810;
            *(undefined4 *)(lVar11 + 0xe78) = 0;
            lVar11 = param_1[1];
            *(undefined4 *)(lVar11 + 0xe88) = 0x81211430;
            *(undefined8 *)(lVar11 + 0xe8c) = 0;
            lVar11 = param_1[1];
            *(undefined4 *)(lVar11 + 0xe7c) = 0x429a1820;
            *(undefined8 *)(lVar11 + 0xe80) = 0;
            *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff2 | 2;
            *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff4f | 0x40;
            *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffff3ff | 0x300;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
            return param_1;
          }
          if (uVar4 == 0x4015) {
            *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 0x40;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
            *(undefined4 *)(param_1[1] + 0xad8) = 1;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x10;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
            *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 2;
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 2;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe70) = 0x42a81c10;
            *(undefined4 *)(lVar11 + 0xe78) = 0;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe88) = 0x82511c30;
            *(undefined4 *)(lVar11 + 0xe90) = 0;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe7c) = 0x52c21920;
            *(undefined4 *)(lVar11 + 0xe84) = 0;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe94) = 0x52371940;
            *(undefined4 *)(lVar11 + 0xe9c) = 0;
            goto LAB_140044b9d;
          }
          if (uVar4 == 0x4021) {
            *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 0x200;
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 4;
            *(undefined4 *)(param_1[1] + 0xad8) = 1;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x40;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x10;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
            *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 2;
            *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
            goto LAB_140044218;
          }
        }
        else {
          if ((uVar4 == 0x4802) || (uVar4 == 0x4803)) {
            *(uint *)(param_2 + 0x2374) = *(uint *)(param_2 + 0x2374) | 0x100;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
            *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
            *(uint *)(param_1[1] + 0x2378) = *(uint *)(param_1[1] + 0x2378) | 2;
            lVar11 = param_1[1];
            *(undefined4 *)(lVar11 + 0xe70) = 0x82111910;
            *(undefined8 *)(lVar11 + 0xe74) = 0;
            *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff0;
            goto LAB_140044ba8;
          }
          if (uVar4 == 0x480c) {
            *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 0x40;
            *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
            *(undefined4 *)(param_1[1] + 0xad8) = 1;
            *(undefined4 *)(param_1[1] + 0x160) = 500;
            *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
            *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe7c) = 0x42c21d20;
            *(undefined4 *)(lVar11 + 0xe84) = 0;
            lVar11 = param_1[1];
            *(undefined8 *)(lVar11 + 0xe70) = 0x42a81c10;
            *(undefined4 *)(lVar11 + 0xe78) = 0;
            lVar11 = param_1[1];
            *(undefined4 *)(lVar11 + 0xe88) = 0x82211c30;
            *(undefined8 *)(lVar11 + 0xe8c) = 0;
LAB_140044c91:
            *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffffff2 | 2;
            lVar11 = param_1[1];
            uVar8 = *(uint *)(lVar11 + 0xe6c) & 0xffffff4f | 0x40;
LAB_140044cb9:
            *(uint *)(lVar11 + 0xe6c) = uVar8;
            goto LAB_140044bb6;
          }
          if (uVar4 == 0x481c) goto LAB_14004478a;
        }
LAB_140044a30:
        if (0x1ff < (ushort)(uVar4 + 0xb600)) {
          return param_1;
        }
        *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
        *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x100;
LAB_140044a6e:
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 4;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 0x20;
        *(uint *)(param_1[1] + 0x2384) = *(uint *)(param_1[1] + 0x2384) | 8;
        return param_1;
      }
      if (uVar4 < 0x4892) {
        if (uVar4 != 0x4891) {
          if (uVar4 < 0x4864) {
            if (uVar4 != 0x4863) {
              if (uVar4 == 0x482f) {
                *(uint *)(param_2 + 0x2374) = *(uint *)(param_2 + 0x2374) | 0x100;
                do {
                  uVar8 = (int)uVar16 + 1;
                  uVar16 = (ulonglong)uVar8;
                  *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | uVar8;
                } while ((int)uVar8 < 2);
                *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 4;
                *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
                *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
                lVar11 = param_1[1];
                *(undefined8 *)(lVar11 + 0xe70) = 0x42a81d10;
LAB_140044889:
                *(undefined4 *)(lVar11 + 0xe78) = 0;
                return param_1;
              }
              if (uVar4 != 0x4831) {
                if ((uVar4 == 0x4833) || (uVar4 == 0x4837)) {
                  *(uint *)(param_2 + 0x2374) = *(uint *)(param_2 + 0x2374) | 0x100;
                  goto LAB_14004481a;
                }
                if (uVar4 != 0x4854) goto LAB_140044a30;
              }
LAB_14004478a:
              *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
              *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20000;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              lVar11 = param_1[1];
              *(undefined4 *)(lVar11 + 0xe7c) = 0x82211c20;
              *(undefined8 *)(lVar11 + 0xe80) = 0;
              *(uint *)(param_1[1] + 0xe7c) = *(uint *)(param_1[1] + 0xe7c) & 0xfffffbff;
              goto LAB_140044fea;
            }
          }
          else if (uVar4 != 0x4864) {
            if (uVar4 == 0x4868) {
              *(uint *)(param_2 + 0x2384) = *(uint *)(param_2 + 0x2384) | 4;
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 1;
              *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
              *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
              do {
                uVar8 = (int)uVar16 + 1;
                uVar16 = (ulonglong)uVar8;
                *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | uVar8;
              } while ((int)uVar8 < 2);
              *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x2000000;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe70) = 0x50c20110;
              *(undefined4 *)(lVar11 + 0xe78) = 0;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe7c) = 0x40a80020;
              *(undefined4 *)(lVar11 + 0xe84) = 0;
              lVar11 = param_1[1];
              *(undefined8 *)(lVar11 + 0xe88) = 0x40370130;
              *(undefined4 *)(lVar11 + 0xe90) = 0;
              lVar11 = param_1[1];
              *(undefined4 *)(lVar11 + 0xe94) = 0x82211c40;
              *(undefined8 *)(lVar11 + 0xe98) = 0;
              lVar11 = param_1[1];
LAB_140044999:
              *(uint *)(lVar11 + 0xe6c) = *(uint *)(lVar11 + 0xe6c) & 0xfffffff1 | 1;
              *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff6f | 0x60;
              *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf00;
              return param_1;
            }
            if (uVar4 == 0x4872) goto LAB_140044714;
            if (uVar4 != 0x4890) goto LAB_140044a30;
            goto LAB_1400448be;
          }
LAB_140044cc4:
          *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
          goto LAB_140044cd0;
        }
      }
      else if (uVar4 != 0x4899) {
        if (uVar4 == 0x4990) {
          *(undefined4 *)(param_2 + 0x2488) = 0x15;
          *(undefined4 *)(param_1[1] + 0x2498) = 500;
          *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 8;
          goto LAB_140044d15;
        }
        if ((((uVar4 == 0x4a01) || (uVar4 == 0x4a03)) || (uVar4 == 0x4a04)) ||
           ((uVar4 == 0x4a05 || (uVar4 == 0x4a06)))) goto LAB_140044cc4;
        if (uVar4 == 0x7810) {
          *(undefined2 *)(param_2 + 0xe68) = 0x4040;
          *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
          lVar11 = param_1[1];
          *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
          *(undefined4 *)(lVar11 + 0xe78) = 0;
          *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) & 0xffff1fff | 0x1000;
          *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) & 0xfff3ffff | 0x30000;
          *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) & 0x3fffffff | 0x40000000;
          *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) & 0xfdffffff | 0xd000000;
          *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) & 0xdfffffff | 0x10000000;
LAB_140044c7c:
          lVar11 = param_1[1];
          *(undefined4 *)(lVar11 + 0xe7c) = 0x82211020;
          *(undefined8 *)(lVar11 + 0xe80) = 0;
          goto LAB_140044c91;
        }
        if (uVar4 != 0x830a) goto LAB_140044a30;
        *(undefined4 *)(param_2 + 0x2488) = 0x15;
        lVar12 = 0xe70;
        *(undefined4 *)(param_1[1] + 0x2498) = 500;
        *(undefined4 *)(param_1[1] + 0x25a4) = 1;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 8;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x40;
        *(undefined4 *)(param_1[1] + 0xad8) = 1;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x800;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 2;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
        *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x1000;
        lVar11 = param_1[1];
        *(undefined8 *)(lVar11 + 0xe70) = 0x42a89010;
        *(undefined4 *)(lVar11 + 0xe78) = 0;
        *(uint *)(param_1[1] + 0xe70) = *(uint *)(param_1[1] + 0xe70) | 0x400;
        lVar11 = param_1[1];
        *(undefined4 *)(lVar11 + 0xe7c) = 0x82211c20;
        lVar14 = 0xe70;
        *(undefined8 *)(lVar11 + 0xe80) = 0;
        do {
          *(uint *)(lVar14 + param_1[1]) = *(uint *)(lVar14 + param_1[1]) & 0xf1ffffff | 0x1000000;
          lVar14 = lVar14 + 0xc;
        } while (lVar14 < 0xe88);
        do {
          *(uint *)(lVar12 + param_1[1]) = *(uint *)(lVar12 + param_1[1]) & 0xffff1fff | 0x1000;
          lVar12 = lVar12 + 0xc;
        } while (lVar12 < 0xe88);
LAB_140044b9d:
        *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
LAB_140044ba8:
        *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff0f;
LAB_140044bb6:
        *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffff0ff;
        return param_1;
      }
LAB_1400448be:
      *(undefined4 *)(param_2 + 0x2488) = 0x15;
      *(undefined4 *)(param_1[1] + 0x2498) = 500;
      *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 8;
      lVar11 = param_1[1];
LAB_1400448e6:
      *(undefined2 *)(lVar11 + 0xe68) = 0x4040;
      return param_1;
    }
    *(uint *)(param_2 + 0x2380) = *(uint *)(param_2 + 0x2380) | 1;
    *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x400;
LAB_140044cd0:
    *(undefined2 *)(param_1[1] + 0xe68) = 0x4040;
  }
LAB_140044cdb:
  lVar11 = param_1[1];
LAB_140044cdf:
  *(uint *)(lVar11 + 0x2374) = *(uint *)(lVar11 + 0x2374) | 0x100;
  return param_1;
}

