
int FUN_14004f5fc(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  longlong lVar5;
  int iVar6;
  undefined4 uVar7;
  void *_Dst;
  short *psVar8;
  int iVar9;
  longlong lVar10;
  uint uVar11;
  
  if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
     ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 8) != 0)) {
    FUN_14001b4c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x12,&DAT_140061340,
                  "CRenderPin::AcquireHardwareResources");
  }
  if ((char)param_1[0x10] == '\0') {
    lVar10 = *param_1;
    plVar2 = *(longlong **)(param_1[0x43] + 0x60);
    lVar5 = plVar2[1];
    *(longlong *)((longlong)param_1 + 0x17c) = *plVar2;
    *(longlong *)((longlong)param_1 + 0x184) = lVar5;
    lVar5 = plVar2[3];
    *(longlong *)((longlong)param_1 + 0x18c) = plVar2[2];
    *(longlong *)((longlong)param_1 + 0x194) = lVar5;
    lVar5 = plVar2[5];
    *(longlong *)((longlong)param_1 + 0x19c) = plVar2[4];
    *(longlong *)((longlong)param_1 + 0x1a4) = lVar5;
    uVar7 = *(undefined4 *)((longlong)plVar2 + 0x34);
    lVar5 = plVar2[7];
    uVar4 = *(undefined4 *)((longlong)plVar2 + 0x3c);
    *(int *)((longlong)param_1 + 0x1ac) = (int)plVar2[6];
    *(undefined4 *)(param_1 + 0x36) = uVar7;
    *(int *)((longlong)param_1 + 0x1b4) = (int)lVar5;
    *(undefined4 *)(param_1 + 0x37) = uVar4;
    uVar7 = *(undefined4 *)((longlong)plVar2 + 0x44);
    lVar5 = plVar2[9];
    uVar4 = *(undefined4 *)((longlong)plVar2 + 0x4c);
    *(int *)((longlong)param_1 + 0x1bc) = (int)plVar2[8];
    *(undefined4 *)(param_1 + 0x38) = uVar7;
    *(int *)((longlong)param_1 + 0x1c4) = (int)lVar5;
    *(undefined4 *)(param_1 + 0x39) = uVar4;
    *(short *)((longlong)param_1 + 0x1cc) = (short)plVar2[10];
    if ((*(uint *)(lVar10 + 0x2374) & 1) != 0) {
      if (*(longlong *)(lVar10 + 0xb18) != 0) {
        iVar6 = (*(code *)PTR__guard_dispatch_icall_14005f458)
                          (*(longlong *)(lVar10 + 0xb18),param_1[1],plVar2);
        lVar10 = *param_1;
        if (iVar6 != -0x3fffff45) goto LAB_14004f710;
      }
      if (*(longlong *)(lVar10 + 0xb20) != 0) {
        (*(code *)PTR__guard_dispatch_icall_14005f458)
                  (*(longlong *)(lVar10 + 0xb20),param_1[1],plVar2);
        lVar10 = *param_1;
      }
    }
LAB_14004f710:
    plVar1 = param_1 + 1;
    if ((*(uint *)(lVar10 + 0x2374) & 1) == 0) {
LAB_14004f741:
      psVar8 = (short *)*plVar1;
LAB_14004f76e:
      FUN_14003a6d8(psVar8);
    }
    else {
      psVar8 = (short *)*plVar1;
      if (*(int *)(psVar8 + 0x16c) == 0) goto LAB_14004f741;
      if (((*(uint *)(lVar10 + 0x2380) & 0x200) == 0) || (*(int *)(psVar8 + 0x16c) != 1))
      goto LAB_14004f76e;
    }
    if ((param_1[0x13] != 0) && (param_1[0x11] != 0)) {
      *(undefined4 *)(param_1 + 0x14) = 1;
      iVar6 = FUN_140050c64(param_1,plVar2);
      if (iVar6 < 0) {
        if ((undefined **)PTR_LOOP_140067000 == &PTR_LOOP_140067000) {
          return iVar6;
        }
        if ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 0x10) == 0) {
          return iVar6;
        }
        FUN_1400209c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x13,&DAT_140061340,
                      "CRenderPin::AcquireHardwareResources");
        return iVar6;
      }
      lVar10 = *param_1;
      *(undefined4 *)((longlong)param_1 + 0xac) = 0;
      *(undefined4 *)(param_1 + 0x15) = 0;
      if (*(char *)(lVar10 + 0x26fc) == ' ') {
        *(undefined4 *)(param_1 + 0x16) = 0x50;
        uVar11 = ((uint)(*(ushort *)((longlong)plVar2 + 0x4e) >> 3) *
                  (uint)*(ushort *)((longlong)plVar2 + 0x42) * *(int *)((longlong)plVar2 + 0x44)) /
                 100;
        *(uint *)(param_1 + 0x17) = uVar11;
        if (*(int *)((longlong)plVar2 + 0x44) == 0xac44) {
          *(uint *)(param_1 + 0x15) =
               (uint)(*(ushort *)((longlong)plVar2 + 0x4e) >> 3) *
               (uint)*(ushort *)((longlong)plVar2 + 0x42) * 5;
          *(uint *)((longlong)param_1 + 0xac) =
               (uint)(*(ushort *)((longlong)plVar2 + 0x4e) >> 3) *
               (uint)*(ushort *)((longlong)plVar2 + 0x42) * 6;
        }
        iVar6 = (int)((ulonglong)uVar11 / 0x50);
        if ((uVar11 != (uVar11 / 0x50) * 0x50) && (((ulonglong)uVar11 / 0x50 & 1) != 0)) {
          iVar6 = iVar6 + -1;
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x16) = 10;
        uVar3 = (ulonglong)
                ((uint)(*(ushort *)((longlong)plVar2 + 0x4e) >> 3) *
                 (uint)*(ushort *)((longlong)plVar2 + 0x42) * *(int *)((longlong)plVar2 + 0x44)) /
                100;
        *(int *)(param_1 + 0x17) = (int)uVar3;
        iVar6 = (int)(uVar3 / 10);
      }
      *(int *)((longlong)param_1 + 0xa4) = iVar6;
      *(undefined4 *)((longlong)param_1 + 0x36c) = 8;
      uVar11 = *(uint *)(lVar10 + 0x26b0);
      if (uVar11 < 0xa4) {
        if (uVar11 == 0xa3) {
LAB_14004f92b:
          uVar7 = *(undefined4 *)((longlong)param_1 + 0x36c);
          if ((*(byte *)(lVar10 + 0x2384) & 0x20) != 0) {
            uVar7 = 4;
          }
        }
        else {
          if (((uVar11 != 3) && (uVar11 != 0xe)) && ((uVar11 != 0x1f && (uVar11 != 0x2f)))) {
            if ((uVar11 != 0x42) && (uVar11 != 0x9f)) {
LAB_14004f97b:
              if ((*(uint *)(lVar10 + 0x2384) & 0x20) != 0) {
                if ((*(char *)(lVar10 + 0x26fc) != '\0') && (*(char *)(lVar10 + 0x26fc) == ' '))
                goto LAB_14004fa0b;
                *(undefined4 *)((longlong)param_1 + 0x36c) = 4;
              }
              goto LAB_14004fa11;
            }
            goto LAB_14004f92b;
          }
          uVar7 = *(undefined4 *)((longlong)param_1 + 0x36c);
          if ((*(byte *)(lVar10 + 0x2384) & 0x20) != 0) {
            uVar7 = 2;
          }
        }
LAB_14004f94e:
        *(undefined4 *)((longlong)param_1 + 0x36c) = uVar7;
      }
      else if (uVar11 == 0xa4) {
        if ((*(uint *)(lVar10 + 0x2384) & 0x20) != 0) {
LAB_14004fa0b:
          *(undefined4 *)((longlong)param_1 + 0x36c) = 2;
        }
      }
      else if (((uVar11 == 0xb1) || (uVar11 == 0xb4)) || (uVar11 == 0xb5)) {
        if ((((*(uint *)(lVar10 + 0x2384) & 0x20) != 0) && (*(int *)(lVar10 + 0xcac) == 0)) &&
           ((*(undefined4 *)((longlong)param_1 + 0x36c) = 4, *(int *)(lVar10 + 0x26b4) != 0x85 &&
            (*(short *)(lVar10 + 0x26a8) != 0x1b9b)))) {
          uVar7 = 4;
          if (*(short *)(lVar10 + 0x26aa) == 0xb05) {
            uVar7 = 2;
          }
          goto LAB_14004f94e;
        }
      }
      else if (uVar11 != 0xcf) goto LAB_14004f97b;
LAB_14004fa11:
      if ((*(uint *)(lVar10 + 0x2384) & 0x1000) != 0) {
        *(undefined4 *)(*plVar1 + 0x248) = *(undefined4 *)(lVar10 + 0xcac);
        FUN_14003cd74(*plVar1,0,L"dsd_mode",4,4,*plVar1 + 0x248);
        lVar10 = *param_1;
      }
      *(undefined4 *)(lVar10 + 0xcac) = 0;
      lVar10 = *param_1;
      if (((((*(uint *)(lVar10 + 0x2384) >> 10 & 1) != 0) &&
           ((*(uint *)(lVar10 + 0x2384) >> 0x15 & 1) == 0)) && (*(int *)(lVar10 + 0x48) != 0)) &&
         (*(int *)(*plVar1 + 0x2d8) == 1)) {
        FUN_140052368(lVar10,2);
        lVar10 = *param_1;
      }
      iVar6 = *(int *)((longlong)param_1 + 0x36c);
      if ((*(uint *)(lVar10 + 0x2384) & 0x20) == 0) {
        iVar9 = iVar6 * (int)param_1[0x17];
        if ((*(uint *)(lVar10 + 0x2388) & 0x10) != 0) {
          iVar9 = iVar9 * 400;
        }
      }
      else {
        iVar9 = iVar6 * (int)param_1[0x17] * 400;
      }
      *(int *)((longlong)param_1 + 0xb4) = iVar9;
      *(int *)(param_1 + 0x6d) = iVar6;
      _Dst = (void *)ExAllocatePoolWithTag
                               (DAT_140075ba0,*(undefined4 *)((longlong)param_1 + 0xb4),0x42554646);
      param_1[0x19] = (longlong)_Dst;
      if (_Dst == (void *)0x0) {
        if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
           ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 0x10) != 0)) {
          FUN_1400209c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x14,&DAT_140061340,
                        "CRenderPin::AcquireHardwareResources");
        }
        goto LAB_14004fb9d;
      }
      memset(_Dst,0,(ulonglong)*(uint *)((longlong)param_1 + 0xb4));
      *(undefined4 *)(param_1 + 0x6e) = 0;
      *(undefined4 *)(param_1 + 0x1a) = *(undefined4 *)((longlong)param_1 + 0xb4);
    }
    if (((undefined **)PTR_LOOP_140067000 != &PTR_LOOP_140067000) &&
       ((*(uint *)(PTR_LOOP_140067000 + 0x2c) & 0x10) != 0)) {
      FUN_1400209c8(*(undefined8 *)(PTR_LOOP_140067000 + 0x18),0x15,&DAT_140061340,
                    "CRenderPin::AcquireHardwareResources");
    }
    iVar6 = 0;
  }
  else {
LAB_14004fb9d:
    iVar6 = -0x3fffffff;
  }
  return iVar6;
}

