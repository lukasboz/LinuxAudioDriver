
longlong FUN_140035f64(longlong param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  short sVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined4 *_Dst;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  undefined4 *local_res8;
  uint local_48;
  undefined8 local_38;
  undefined4 local_30;
  
  *(undefined4 *)(param_1 + 0x2d8) = 0xc;
  *(undefined ***)(param_1 + 0xa0) = &PTR_FUN_140060ed8;
  *(undefined ***)(param_1 + 0xb8) = &PTR_FUN_140060ef8;
  *(undefined ***)(param_1 + 0xd0) = &PTR_FUN_140060ef8;
  *(undefined4 *)(param_1 + 0x25c) = 0;
  *(undefined ***)(param_1 + 0xe8) = &PTR_FUN_1400606d0;
  *(undefined ***)(param_1 + 0x100) = &PTR_FUN_140060f18;
  *(undefined ***)(param_1 + 0x118) = &PTR_FUN_1400606f0;
  *(undefined ***)(param_1 + 0x208) = &PTR_FUN_140060f38;
  *(undefined ***)(param_1 + 0x220) = &PTR_FUN_140060f38;
  *(undefined ***)(param_1 + 0x278) = &PTR_FUN_140060ef8;
  *(undefined8 *)(param_1 + 0x2e0) = &PTR_FUN_140060f48;
  *(undefined ***)(param_1 + 0x310) = &PTR_FUN_1400606f0;
  *(undefined ***)(param_1 + 0x358) = &PTR_FUN_140060eb8;
  *(undefined8 *)(param_1 + 0x2d0) = param_2;
  *(int *)(param_1 + 0x2c8) = param_3;
  *(undefined4 *)(param_1 + 0x338) = 0;
  FUN_1400370bc(param_1,param_3);
  FUN_140038d08(param_1);
  FUN_140038108(param_1);
  memset((void *)(param_1 + 0x130),0,0x68);
  KeInitializeMutex(param_1 + 0x290,0);
  KeInitializeMutex(param_1 + 0x3b8,0);
  *(undefined4 *)(param_1 + 0x3f4) = 0;
  *(undefined4 *)(param_1 + 0x23c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x240) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x244) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x24c) = 3;
  *(undefined8 *)(param_1 + 0x254) = 2;
  *(undefined4 *)(param_1 + 0x3a0) = 0;
  *(undefined4 *)(param_1 + 0x238) = 0;
  FUN_14004c5d4((undefined8 *)(param_1 + 0x388),FUN_14003b820,param_1,1000,0);
  FUN_14004c5d4((undefined8 *)(param_1 + 0x3a8),FUN_14003c7c0,param_1,100,0);
  lVar5 = *(longlong *)(param_1 + 0x2d0);
  sVar2 = *(short *)(lVar5 + 0x26a8);
  if ((((sVar2 == 0x4014) || (sVar2 == 0x4016)) || (sVar2 == 0x402e)) && (param_3 == 2)) {
    FUN_14004c5d4((undefined8 *)(param_1 + 0x390),FUN_140039aa0,param_1,1,0);
    lVar5 = *(longlong *)(param_1 + 0x2d0);
  }
  if ((*(int *)(lVar5 + 0x34) == 0) && (*(short *)(lVar5 + 0xe68) != 0)) {
    lVar5 = 0xf30;
    lVar6 = 0xe70;
    do {
      lVar4 = *(longlong *)(param_1 + 0x2d0);
      uVar1 = *(undefined8 *)(lVar6 + lVar4);
      uVar3 = *(undefined4 *)(lVar6 + 8 + lVar4);
      local_48 = (uint)uVar1;
      if ((local_48 >> 4 & 0xf) == *(uint *)(param_1 + 0x2c8)) {
        iVar7 = 0;
        if ((*(uint *)(lVar4 + 0x2384) & 0x2000) != 0) {
          iVar7 = *(int *)(lVar5 + lVar4);
        }
        _Dst = (undefined4 *)ExAllocatePoolWithTag(DAT_140075ba0,0xd0,0x57494754);
        if (_Dst == (undefined4 *)0x0) {
          local_res8 = (undefined4 *)0x0;
        }
        else {
          memset(_Dst,0,0xd0);
          local_38 = uVar1;
          local_30 = uVar3;
          local_res8 = FUN_140053be0(_Dst,param_1,(uint *)&local_38,iVar7);
          if (local_res8 != (undefined4 *)0x0) {
            FUN_1400246a0(param_1 + 0x2e0,&local_res8);
            FUN_1400246a0(*(longlong *)(param_1 + 0x2d0) + 0xfd0,&local_res8);
            local_res8[3] = *(int *)(*(longlong *)(param_1 + 0x2d0) + 0xfd8) + -1;
          }
        }
      }
      lVar6 = lVar6 + 0xc;
      lVar5 = lVar5 + 4;
    } while (lVar6 < 0xf30);
  }
  return param_1;
}

