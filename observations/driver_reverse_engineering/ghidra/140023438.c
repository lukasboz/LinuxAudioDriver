
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 * FUN_140023438(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  void *_Dst;
  ulonglong uVar7;
  longlong lVar8;
  void *pvVar9;
  bool bVar10;
  bool bVar11;
  undefined1 auStackY_428 [32];
  int local_3e8 [4];
  undefined8 local_3d8;
  undefined8 uStack_3d0;
  undefined4 local_3c8;
  undefined4 uStack_3c4;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  undefined4 local_3b8;
  undefined4 uStack_3b4;
  undefined4 uStack_3b0;
  undefined4 uStack_3ac;
  undefined4 local_3a8;
  undefined4 uStack_3a4;
  undefined4 uStack_3a0;
  undefined4 uStack_39c;
  undefined4 local_398;
  undefined4 uStack_394;
  undefined4 uStack_390;
  undefined4 uStack_38c;
  undefined4 local_388;
  undefined4 uStack_384;
  uint local_378 [2];
  undefined1 local_370 [24];
  undefined4 local_358;
  uint local_354;
  uint local_350;
  uint local_34c;
  char local_23e;
  undefined8 local_238 [64];
  ulonglong local_38;
  
  local_38 = DAT_1400698c0 ^ (ulonglong)auStackY_428;
  FUN_140057e8c(param_1,(undefined8 *)0x0);
  pvVar9 = (void *)0x0;
  *param_1 = &PTR_FUN_140060710;
  param_1[3] = &PTR_FUN_1400606d0;
  puVar5 = param_1 + 0x1ce;
  *(undefined4 *)((longlong)param_1 + 0xe6c) = 0;
  lVar8 = 0x10;
  do {
    *puVar5 = 0;
    *(undefined4 *)(puVar5 + 1) = 0;
    puVar5 = (undefined8 *)((longlong)puVar5 + 0xc);
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  *(undefined8 *)((longlong)param_1 + 0x1004) = 0;
  param_1[0x1fa] = &PTR_FUN_1400606f0;
  param_1[0x1fd] = &PTR_FUN_140060700;
  FUN_14004be84(param_1 + 0x210);
  FUN_14004be84(param_1 + 0x297);
  *(undefined4 *)(param_1 + 0x46b) = 0;
  *(undefined4 *)(param_1 + 0x472) = 0;
  param_1[0x4db] = param_2;
  *(undefined4 *)((longlong)param_1 + 0x2394) = 0xffff;
  param_1[0x15e] = 0;
  param_1[0x15f] = 0;
  param_1[0x160] = 0;
  param_1[0x4e7] = 0;
  param_1[0x4e8] = 0;
  *(undefined4 *)(param_1 + 0x4e9) = 0;
  *(undefined4 *)(param_1 + 0x4dc) = 1;
  *(undefined4 *)(param_1 + 0x15b) = 0x1e;
  *(undefined4 *)((longlong)param_1 + 0xadc) = 1;
  param_1[0x4dd] = *(undefined8 *)(param_2 + 0x20);
  param_1[0x4de] = *(undefined8 *)(param_2 + 0x18);
  *(undefined4 *)((longlong)param_1 + 0x2394) = 0;
  *(uint *)(param_1 + 0x472) = *(uint *)(param_1 + 0x472) | 0x4000;
  *(uint *)(param_1 + 0x485) = *(uint *)(param_1 + 0x485) | 0x400000;
  *(uint *)((longlong)param_1 + 0x24f4) = *(uint *)((longlong)param_1 + 0x24f4) | 0x2000000;
  *(uint *)(param_1 + 0x498) = *(uint *)(param_1 + 0x498) | 4;
  *(uint *)((longlong)param_1 + 0x23b4) = *(uint *)((longlong)param_1 + 0x23b4) | 0x400;
  *(undefined4 *)(param_1 + 0x491) = 0x14;
  *(undefined4 *)(param_1 + 8) = 0x21;
  *(undefined8 *)((longlong)param_1 + 0x44) = 0x38;
  param_1[0x196] = 0;
  *(undefined1 *)(param_1 + 0x197) = 0;
  param_1[0x46c] = 0;
  *(undefined4 *)(param_1 + 0x46b) = 0;
  *(undefined4 *)(param_1 + 0x46d) = 0;
  *(undefined4 *)((longlong)param_1 + 0x4c) = 1;
  *(undefined4 *)((longlong)param_1 + 0x25a4) = 1;
  param_1[0x162] = 0;
  param_1[0x409] = 0;
  param_1[0x40a] = 0;
  param_1[0x40b] = 0;
  memset(param_1 + 0x3fc,0,0x68);
  *(undefined4 *)(param_1 + 0x3fa) = 5;
  *(undefined4 *)((longlong)param_1 + 0x1fd4) = 6;
  *(undefined4 *)(param_1 + 0x3fb) = 1;
  *(undefined4 *)((longlong)param_1 + 0x1fdc) = 2;
  *(undefined4 *)((longlong)param_1 + 0xf4) = 0x30000;
  *(undefined4 *)(param_1 + 0x1e) = 0x30000;
  *(undefined4 *)(param_1 + 0x3f8) = 1;
  *(undefined4 *)(param_1 + 0x3f9) = 0x18;
  *(undefined4 *)((longlong)param_1 + 0x1fcc) = 4;
  *(undefined4 *)((longlong)param_1 + 0x1fc4) = 48000;
  *(undefined4 *)((longlong)param_1 + 0x26e4) = 0;
  *(undefined8 *)((longlong)param_1 + 0x274c) = 0;
  *(undefined4 *)((longlong)param_1 + 0x2754) = 0;
  param_1[0x40c] = 0;
  param_1[0x40d] = 0;
  puVar6 = (undefined4 *)ExAllocatePoolWithTag(DAT_140075ba0,4,0x6f7368);
  param_1[0x40e] = puVar6;
  *puVar6 = 0;
  param_1[0x40f] = 0;
  param_1[0x410] = 0;
  param_1[0x3f4] = 0;
  param_1[0x4e0] = 0;
  *(undefined4 *)((longlong)param_1 + 0x5c) = 0xffff;
  param_1[0x4e1] = 0;
  param_1[0x4e3] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x163] = 0;
  param_1[0x164] = 0;
  param_1[0x175] = 0;
  param_1[0x176] = 0;
  param_1[0x178] = 0;
  param_1[0x177] = 0;
  *(undefined4 *)(param_1 + 0x17e) = 0;
  param_1[0x17b] = 0;
  *(undefined4 *)(param_1 + 0x42e) = 0;
  *(undefined4 *)(param_1 + 0x1a) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined2 *)((longlong)param_1 + 0x26ac) = 0;
  _Dst = (void *)ExAllocatePoolWithTag(DAT_140075ba0,0x600,0x6d457674);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x600);
    *(undefined8 **)((longlong)_Dst + 0x5f0) = param_1;
    pvVar9 = _Dst;
  }
  param_1[0x165] = pvVar9;
  KeInitializeMutex(param_1 + 0x166,0);
  KeInitializeMutex(param_1 + 0x16d,0);
  KeInitializeMutex(param_1 + 0x1a3,0);
  KeInitializeMutex(param_1 + 0x1aa,0);
  KeInitializeMutex(param_1 + 0x1b2,0);
  KeInitializeMutex(param_1 + 0x1bb,0);
  KeInitializeSpinLock(param_1 + 0x1b9);
  KeInitializeSpinLock(param_1 + 0x1ba);
  KeInitializeSpinLock(param_1 + 0x1b1);
  puVar5 = param_1 + 0x463;
  RtlInitUnicodeString(puVar5,0);
  RtlInitUnicodeString(param_1 + 0x465,u_rtUsbInterface_140067010);
  RtlInitUnicodeString(param_1 + 0x467,u__rtUsbInterface_140067030);
  puVar1 = param_1 + 0x4bd;
  RtlInitUnicodeString(puVar1,0);
  RtlInitUnicodeString(param_1 + 0x4bf,u_rtUsbInterface4UI_140067050);
  RtlInitUnicodeString(param_1 + 0x4c1,u__rtUsbInterface4UI_140067078);
  RtlInitUnicodeString(param_1 + 0x4c3,0);
  RtlInitUnicodeString(param_1 + 0x4c5,u_rtUsbInterfaceForForte_1400670a0);
  RtlInitUnicodeString(param_1 + 0x4c7,u__rtUsbInterfaceForForte_1400670d0);
  RtlInitUnicodeString(param_1 + 0x4c9,0);
  RtlInitUnicodeString(param_1 + 0x4cb,u_rtUsbInterfaceForMBSkuFront_140067100);
  RtlInitUnicodeString(param_1 + 0x4cd,u__rtUsbInterfaceForMBSkuFront_140067138);
  RtlInitUnicodeString(param_1 + 0x4cf,0);
  RtlInitUnicodeString(param_1 + 0x4d1,u_rtUsbInterfaceForMBSkuRear_140067178);
  RtlInitUnicodeString(param_1 + 0x4d3);
  local_3d8 = 0x58;
  uStack_3d0 = 0;
  local_3c8 = 0x73647561;
  uStack_3c4 = 0x100000;
  uStack_3c0 = 0xaa000080;
  uStack_3bc = 0x719b3800;
  param_1[0xd] = 0x58;
  param_1[0xe] = 0;
  uStack_394 = 0x18;
  param_1[0xf] = 0x10000073647561;
  param_1[0x10] = 0x719b3800aa000080;
  uStack_390 = 0x18;
  local_3b8 = 1;
  uStack_38c = 48000;
  local_388 = 48000;
  uStack_3b4 = 0x100000;
  uStack_3b0 = 0xaa000080;
  uStack_3ac = 0x719b3800;
  param_1[0x11] = 0x10000000000001;
  param_1[0x12] = 0x719b3800aa000080;
  local_3a8 = 0x5589f81;
  uStack_3a4 = 0x11cec356;
  uStack_3a0 = 0xaa0001bf;
  uStack_39c = 0x5a595500;
  param_1[0x13] = 0x11cec35605589f81;
  param_1[0x14] = 0x5a595500aa0001bf;
  local_398 = 2;
  param_1[0x15] = 0x1800000002;
  param_1[0x16] = 0xbb8000000018;
  param_1[0x17] = CONCAT44(uStack_384,48000);
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  *(undefined2 *)((longlong)param_1 + 0x26fc) = 0;
  param_1[0x36b] = 0;
  param_1[0x36c] = 0;
  param_1[0x371] = 0;
  param_1[0x372] = 0;
  param_1[0x36f] = 0;
  param_1[0x370] = 0;
  memset(param_1 + 0x21,0,0x46);
  param_1[0x3f5] = 0;
  param_1[0x3f6] = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  param_1[0x3f7] = 0;
  param_1[0x368] = 0;
  param_1[0x369] = 0;
  param_1[0x36a] = 0;
  *(uint *)(param_1 + 0x470) = *(uint *)(param_1 + 0x470) | 0x1000000;
  *(uint *)((longlong)param_1 + 0x2384) = *(uint *)((longlong)param_1 + 0x2384) & 0xfdffffff;
  RtlInitUnicodeString(param_1 + 0x1f,L"Realtek USB Audio");
  RtlInitUnicodeString(local_370);
  lVar8 = MmGetSystemRoutineAddress(local_370);
  if (lVar8 == 0) goto LAB_140023c5c;
  local_358 = 0x11c;
  memset(&local_354,0,0x118);
  (*(code *)PTR__guard_dispatch_icall_14005f458)(&local_358);
  uVar3 = *(uint *)(param_1 + 0x46e);
  if (local_23e != '\x01') {
    uVar3 = uVar3 | 1;
  }
  if (5 < local_354) {
    uVar3 = uVar3 | 2;
  }
  if (((local_354 == 6) && (local_350 != 0)) || (6 < local_354)) {
    uVar3 = uVar3 | 4;
  }
  if (((local_354 == 6) && (1 < local_350)) || (6 < local_354)) {
    uVar3 = uVar3 | 8;
  }
  if (((local_354 == 6) && (2 < local_350)) || (6 < local_354)) {
    uVar3 = uVar3 | 0x10;
  }
  bVar10 = local_354 < 10;
  bVar11 = local_354 == 10;
  if (bVar11) {
    if (local_350 != 0) {
      bVar10 = false;
      bVar11 = true;
      goto LAB_140023b25;
    }
LAB_140023b27:
    uVar2 = uVar3 | 0x20;
    if (0x295a < local_34c) {
      uVar2 = uVar3 | 0x60;
    }
    uVar3 = uVar2;
    if (0x3839 < local_34c) {
      uVar3 = uVar3 | 0x80;
    }
    if (0x47b9 < local_34c) {
      uVar3 = uVar3 | 0x200;
    }
    if (21999 < local_34c) {
      uVar3 = uVar3 | 0x400;
    }
  }
  else {
LAB_140023b25:
    if (!bVar10 && !bVar11) goto LAB_140023b27;
  }
  *(uint *)(param_1 + 0x46e) = uVar3 & 0xfffff7ff;
  if ((uVar3 & 0x20) != 0) {
    local_3e8[0] = 0;
    local_378[0] = 4;
    uVar7 = FUN_14002db9c(param_1 + 0x469,0x14005b7c0,L"Win10Cloud",local_378,
                          (undefined8 *)local_3e8,0,1);
    if ((int)uVar7 < 0) {
      iVar4 = FUN_140028fc8(param_1,L"EditionID",local_238,
                            L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion")
      ;
      if ((-1 < iVar4) && (lVar8 = RtlCompareMemory(local_238,L"Cloud",0xc), lVar8 == 0xc)) {
        local_3e8[0] = 1;
      }
      FUN_140031bac(param_1 + 0x469,0x14005b7c0,L"Win10Cloud",4,4,local_3e8,0);
    }
    *(uint *)(param_1 + 0x46e) =
         *(uint *)(param_1 + 0x46e) ^ (local_3e8[0] << 0xb ^ *(uint *)(param_1 + 0x46e)) & 0x800;
  }
LAB_140023c5c:
  KeInitializeEvent(param_1 + 0x4e4,0,0);
  KeInitializeEvent(param_1 + 0x1a0,0,0);
  iVar4 = IoRegisterDeviceInterface(param_1[0x4dd],&DAT_140060258,param_1 + 0x465,puVar5);
  if (-1 < iVar4) {
    IoSetDeviceInterfaceState(puVar5,1);
  }
  iVar4 = IoRegisterDeviceInterface(param_1[0x4dd],&DAT_140060288,param_1 + 0x4bf,puVar1);
  if (-1 < iVar4) {
    IoSetDeviceInterfaceState(puVar1,1);
  }
  *(undefined4 *)(param_1 + 0x4d6) = 0;
  *(undefined4 *)(param_1 + 6) = 1;
  return param_1;
}

