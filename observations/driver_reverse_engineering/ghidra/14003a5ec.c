
undefined * FUN_14003a5ec(longlong param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2d8);
  if (iVar1 < 0xc) {
    if (((*(int *)(param_1 + 0x32c) != 0) && (*(int *)(param_1 + 0x330) != 0)) && (iVar1 < 8)) {
      iVar1 = iVar1 + 2;
    }
    return (&PTR_u_WaveOut1_1400671f0)[iVar1];
  }
  return (undefined *)0x0;
}

