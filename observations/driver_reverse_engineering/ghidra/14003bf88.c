
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_14003bf88(short *param_1,longlong param_2,short *param_3,uint param_4,int param_5,
                 int param_6,int param_7)

{
  bool bVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  undefined *puVar5;
  longlong lVar6;
  undefined7 extraout_var;
  longlong lVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  wchar_t *pwVar12;
  undefined8 uVar13;
  short *psVar14;
  undefined1 auStackY_d18 [32];
  longlong local_cd8;
  int local_cd0;
  uint local_ccc;
  wchar_t *local_cc8;
  undefined1 local_cc0 [8];
  longlong local_cb8;
  longlong local_cb0;
  undefined1 local_ca8 [16];
  undefined4 local_c98 [2];
  undefined8 local_c90;
  undefined1 *local_c88;
  undefined4 local_c80;
  undefined8 local_c78;
  undefined8 uStack_c70;
  undefined1 local_c68 [16];
  char local_c58 [1024];
  char local_858 [1024];
  char local_458 [1024];
  ulonglong local_58;
  
  local_58 = DAT_1400698c0 ^ (ulonglong)auStackY_d18;
  pwVar12 = L"Capture";
  local_cc8 = L"Render";
  iVar9 = 4;
  local_cd0 = param_5;
  iVar2 = -0x3fffffff;
  if (*(int *)(param_1 + 0x196) != 0) {
    local_cc8 = L"Capture";
  }
  psVar14 = (short *)0x0;
  if ((param_2 == 0) || (param_3 == (short *)0x0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    if (param_6 == 0) {
      param_6 = 4 - (uint)(param_4 != 4);
    }
    local_cb0 = param_2;
    if (param_6 == 3) {
      iVar9 = param_4 + 8;
      psVar3 = (short *)ExAllocatePoolWithTag(DAT_140075ba0,iVar9,0x704b6579);
      if (psVar3 == (short *)0x0) {
        return -0x3fffffff;
      }
      psVar3[0] = 0x41;
      psVar3[1] = 0;
      *(uint *)(psVar3 + 2) = param_4;
      FUN_14005b100((undefined8 *)(psVar3 + 4),(undefined8 *)param_3,(ulonglong)param_4);
    }
    else {
      psVar3 = (short *)0x0;
      if ((param_6 == 7) && (iVar9 = 0, psVar4 = param_3, psVar3 = psVar14, *param_3 != 0)) {
        do {
          lVar6 = -1;
          do {
            lVar6 = lVar6 + 1;
          } while (psVar4[lVar6] != 0);
          iVar10 = iVar9 + (int)lVar6 + 1;
          lVar6 = -1;
          do {
            lVar7 = lVar6;
            lVar6 = lVar7 + 1;
          } while (psVar4[lVar6] != 0);
          psVar4 = psVar4 + lVar7 + 2;
          iVar9 = iVar10;
        } while (*psVar4 != 0);
        iVar9 = 0;
        if (iVar10 != 0) {
          iVar9 = iVar10 * 2 + 2;
        }
      }
    }
    uVar11 = 0;
    if (*param_1 == 0) {
      if (param_7 == 0) {
        puVar5 = FUN_14003a5ec((longlong)param_1);
        lVar6 = FUN_14003ac18((longlong *)(*(longlong *)(param_1 + 0x168) + 0x2348),(longlong)puVar5
                              ,0,pwVar12);
        pwVar12 = L"Properties";
        if (psVar3 != (short *)0x0) {
          param_3 = psVar3;
        }
        if (local_cd0 != 0) {
          pwVar12 = L"FxProperties";
        }
        bVar1 = FUN_140031bac((longlong *)(*(longlong *)(param_1 + 0x168) + 0x2348),
                              (longlong)pwVar12,local_cb0,param_6,iVar9,param_3,lVar6);
        if (bVar1) {
          iVar2 = 0;
        }
      }
    }
    else {
      if (((*(longlong *)(param_1 + 0x168) == 0) ||
          ((*(uint *)(*(longlong *)(param_1 + 0x168) + 0x2370) >> 10 & 1) == 0)) ||
         (local_ccc = 2, local_cd0 == 0)) {
        local_ccc = 1;
      }
      do {
        local_cd8 = 0;
        memset(local_858,0,0x400);
        memset(local_458,0,0x400);
        pcVar8 = local_c58;
        if (uVar11 == 1) {
          FUN_14002f25c(pcVar8,0x400,
                        L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\MMDevices\\Audio\\%ws\\%ws\\%ws\\{12325c6d-6d93-4ab3-bff6-d04968d361dd}\\Default"
                        ,local_cc8);
          FUN_14002f25c(local_858,0x400,
                        L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\MMDevices\\Audio\\%ws\\%ws\\%ws\\{12325c6d-6d93-4ab3-bff6-d04968d361dd}"
                        ,local_cc8);
          pcVar8 = local_458;
          pwVar12 = 
          L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\MMDevices\\Audio\\%ws\\%ws\\%ws\\{12325c6d-6d93-4ab3-bff6-d04968d361dd}\\Default"
          ;
        }
        else {
          pwVar12 = 
          L"\\Registry\\Machine\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\MMDevices\\Audio\\%ws\\%ws\\%ws"
          ;
        }
        FUN_14002f25c(pcVar8,0x400,pwVar12,local_cc8);
        RtlInitUnicodeString(local_cc0,local_cb0);
        RtlInitUnicodeString(local_ca8,local_c58);
        local_c98[0] = 0x30;
        local_c90 = 0;
        local_c88 = local_ca8;
        local_c80 = 0x240;
        local_c78 = 0;
        uStack_c70 = 0;
        iVar2 = ZwOpenKey(&local_cd8,0xf003f,local_c98);
        if ((uVar11 == 1) && (iVar2 == -0x3fffffcc)) {
          RtlInitUnicodeString(local_ca8,local_858);
          local_c98[0] = 0x30;
          local_c88 = local_ca8;
          local_c90 = 0;
          local_c80 = 0x240;
          local_c78 = 0;
          uStack_c70 = 0;
          iVar2 = ZwCreateKey(&local_cd8,0x20006,local_c98,0);
          if (-1 < iVar2) {
            ZwClose(local_cd8);
            RtlInitUnicodeString(local_ca8,local_458);
            local_c98[0] = 0x30;
            local_c88 = local_ca8;
            local_c90 = 0;
            local_c80 = 0x240;
            local_c78 = 0;
            uStack_c70 = 0;
            iVar2 = ZwCreateKey(&local_cd8,0x20006,local_c98,0);
            goto LAB_14003c387;
          }
        }
        else {
LAB_14003c387:
          if (-1 < iVar2) {
            if ((param_7 != 0) &&
               (bVar1 = FUN_14004c0e0(local_cd8,local_cb8), (int)CONCAT71(extraout_var,bVar1) == 0))
            {
              ZwClose(local_cd8);
              iVar2 = -0x3fffffff;
              break;
            }
            if (param_6 == 1) {
              RtlInitUnicodeString(local_c68,param_3);
              uVar13 = 1;
LAB_14003c42c:
              iVar2 = ZwSetValueKey(local_cd8,local_cc0,0,uVar13);
            }
            else {
              if (param_6 == 3) {
                uVar13 = 3;
                goto LAB_14003c42c;
              }
              if (param_6 == 4) {
                uVar13 = 4;
                goto LAB_14003c42c;
              }
              if (param_6 == 7) {
                uVar13 = 7;
                goto LAB_14003c42c;
              }
              if (param_6 == 0x7fffffff) {
                iVar2 = ZwDeleteValueKey(local_cd8);
              }
            }
            ZwClose(local_cd8);
          }
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < local_ccc);
    }
    if (psVar3 != (short *)0x0) {
      ExFreePoolWithTag(psVar3,0);
    }
  }
  return iVar2;
}

