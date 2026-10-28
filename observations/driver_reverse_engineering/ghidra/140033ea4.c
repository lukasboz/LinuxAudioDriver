
undefined8 * FUN_140033ea4(undefined8 *param_1,longlong param_2)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_1400607f0;
  uVar3 = 0;
  param_1[4] = 0;
  param_1[2] = param_2;
  *(uint *)(param_2 + 0x2434) = *(uint *)(param_2 + 0x2434) | 0x10000000;
  *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x20;
  lVar2 = param_1[1];
  sVar1 = *(short *)(lVar2 + 0x26a8);
  if (sVar1 == 0x4001) {
    *(undefined4 *)(lVar2 + 0xad8) = 1;
    *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x40;
    *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x10;
    *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
    *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
    *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
    lVar2 = param_1[1];
    *(undefined8 *)(lVar2 + 0xe70) = 0x42a89010;
    *(undefined4 *)(lVar2 + 0xe78) = 0;
    lVar2 = param_1[1];
    *(undefined4 *)(lVar2 + 0xe7c) = 0x82211c20;
    *(undefined8 *)(lVar2 + 0xe80) = 0;
    lVar2 = param_1[1];
    *(undefined8 *)(lVar2 + 0xe88) = 0x421a3030;
    *(undefined4 *)(lVar2 + 0xe90) = 0;
    *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
    *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff1f | 0x10;
    *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffff0ff;
    *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x800000;
    FUN_1400345e0((longlong)param_1,1);
    return param_1;
  }
  if (sVar1 == 0x4008) {
    *(undefined4 *)(lVar2 + 0xad8) = 1;
    *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x10;
    *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
    do {
      uVar3 = uVar3 + 1;
      *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | uVar3;
    } while ((int)uVar3 < 2);
    *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x800000;
    *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
    lVar2 = param_1[1];
    *(undefined8 *)(lVar2 + 0xe70) = 0x42a89010;
    *(undefined4 *)(lVar2 + 0xe78) = 0;
    lVar2 = param_1[1];
    *(undefined4 *)(lVar2 + 0xe7c) = 0x82211c20;
    *(undefined8 *)(lVar2 + 0xe80) = 0;
  }
  else {
    if (sVar1 != 0x400e) {
      if ((sVar1 == 0x4014) || (sVar1 == 0x4016)) {
LAB_140033f1f:
        *(uint *)(lVar2 + 0x2380) = *(uint *)(lVar2 + 0x2380) | 0x800000;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x200;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 4;
        *(undefined4 *)(param_1[1] + 0xad8) = 1;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x40;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x10;
        *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
        *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
        *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 2;
        *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
        lVar2 = param_1[1];
        *(undefined8 *)(lVar2 + 0xe70) = 0x42a89010;
        *(undefined4 *)(lVar2 + 0xe78) = 0;
        lVar2 = param_1[1];
        *(undefined4 *)(lVar2 + 0xe7c) = 0x82211c20;
        *(undefined8 *)(lVar2 + 0xe80) = 0;
        lVar2 = param_1[1];
        *(undefined8 *)(lVar2 + 0xe88) = 0x421a3030;
        *(undefined4 *)(lVar2 + 0xe90) = 0;
        *(uint *)(param_1[1] + 0xe88) = *(uint *)(param_1[1] + 0xe88) | 0x400;
        *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
        *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff1f | 0x10;
        *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffff0ff;
        FUN_1400345e0((longlong)param_1,1);
        *(undefined4 *)(param_1[1] + 0xba0) = 3;
        return param_1;
      }
      if (sVar1 != 0x402d) {
        if (sVar1 != 0x402e) {
          return param_1;
        }
        goto LAB_140033f1f;
      }
    }
    *(uint *)(lVar2 + 0x2380) = *(uint *)(lVar2 + 0x2380) | 0x2000000;
    *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x800000;
    *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 0x10000;
    *(uint *)(param_1[1] + 0x237c) = *(uint *)(param_1[1] + 0x237c) | 1;
    *(undefined4 *)(param_1[1] + 0xad8) = 1;
    *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 0x10;
    *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 1;
    *(undefined2 *)(param_1[1] + 0xe68) = 0x288;
    *(uint *)(param_1[1] + 0x2374) = *(uint *)(param_1[1] + 0x2374) | 2;
    *(uint *)(param_1[1] + 0x2380) = *(uint *)(param_1[1] + 0x2380) | 2;
    *(undefined4 *)(param_1[1] + 0x25a4) = 1;
    lVar2 = param_1[1];
    *(undefined8 *)(lVar2 + 0xe7c) = 0x42a81c20;
    *(undefined4 *)(lVar2 + 0xe84) = 0;
    lVar2 = param_1[1];
    *(undefined8 *)(lVar2 + 0xe88) = 0x82511c30;
    *(undefined4 *)(lVar2 + 0xe90) = 0;
    lVar2 = param_1[1];
    *(undefined8 *)(lVar2 + 0xe70) = 0x50c21910;
    *(undefined4 *)(lVar2 + 0xe78) = 0;
  }
  *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) | 0xf;
  *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xffffff0f;
  *(uint *)(param_1[1] + 0xe6c) = *(uint *)(param_1[1] + 0xe6c) & 0xfffff0ff;
  return param_1;
}

