
void FUN_1400304b8(longlong param_1,undefined2 param_2,uint param_3,int param_4,uint param_5,
                  int param_6)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x2380) =
       *(uint *)(param_1 + 0x2380) ^ (param_3 ^ *(uint *)(param_1 + 0x2380)) & 1;
  *(uint *)(param_1 + 0x237c) =
       *(uint *)(param_1 + 0x237c) ^ (param_5 ^ *(uint *)(param_1 + 0x237c)) & 1;
  uVar1 = *(uint *)(param_1 + 0x2384);
  *(undefined2 *)(param_1 + 0xe68) = param_2;
  *(uint *)(param_1 + 0x2374) =
       *(uint *)(param_1 + 0x2374) ^ (param_4 << 8 ^ *(uint *)(param_1 + 0x2374)) & 0x100;
  if (param_6 != 0) {
    uVar1 = uVar1 | 0x8024;
  }
  *(uint *)(param_1 + 0x2384) = uVar1 | 8;
  return;
}

