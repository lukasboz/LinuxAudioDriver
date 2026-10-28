
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1400375b8(longlong param_1,uint param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  ushort uVar5;
  uint uVar6;
  undefined4 uVar7;
  byte *pbVar8;
  ulonglong uVar9;
  uint uVar10;
  char *pcVar12;
  bool bVar13;
  bool bVar14;
  undefined1 auStack_1c8 [32];
  undefined4 local_1a8;
  undefined *local_198;
  undefined *local_190;
  undefined *local_188;
  char *local_180;
  ulonglong local_110;
  undefined4 local_108;
  undefined1 local_104;
  undefined *local_f8;
  undefined *local_f0 [2];
  char *local_e0;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  ulonglong uVar11;
  
  local_48 = DAT_1400698c0 ^ (ulonglong)auStack_1c8;
  uVar9 = 0;
  bVar14 = false;
  if (*(uint *)(param_1 + 0xf0) != 0) {
    uVar11 = uVar9;
    do {
      pcVar12 = (char *)(uVar11 * 0xb0 + *(longlong *)(param_1 + 0xf8));
      bVar1 = pcVar12[4];
      if (bVar1 == param_2) {
        if (pcVar12 == (char *)0x0) {
          return 0xc000000d;
        }
        local_1a8 = param_4;
        memset(&local_198,0,0x98);
        cVar2 = *pcVar12;
        uVar10 = 0xffffffff;
        local_58 = 0;
        uStack_50 = 0;
        if (cVar2 == '\x02') {
          local_198 = (undefined *)0x0;
          if (*(short *)(pcVar12 + 2) == 0x101) {
            local_190 = &DAT_140061098;
            local_198 = &DAT_1400675a8;
          }
          else {
            local_190 = &DAT_140060318;
          }
          uVar10 = *(uint *)(param_1 + 0x210);
          local_188 = (undefined *)0x0;
          local_180 = pcVar12;
          FUN_140036e40(param_1 + 0x208,&local_198);
          FUN_140036e40(param_1 + 0x220,&local_198);
          local_58 = (ulonglong)uVar10;
          uStack_50 = CONCAT44(param_4,param_3);
          FUN_140036d68(param_1 + 0xb8,&local_58);
          FUN_140036d68(param_1 + 0xd0,&local_58);
          iVar3 = FUN_14003849c(param_1,pcVar12);
          local_58 = CONCAT44(iVar3,0xffffffff);
          uStack_50 = CONCAT44(1,uVar10);
          FUN_140036d68(param_1 + 0xb8,&local_58);
          FUN_140036d68(param_1 + 0xd0,&local_58);
          return 0xc000000d;
        }
        if (cVar2 == '\x03') {
          uVar10 = *(uint *)(param_1 + 0x210);
          local_190 = &DAT_140061088;
          local_198 = (undefined *)0x0;
          local_188 = (undefined *)0x0;
          local_180 = pcVar12;
          FUN_140036e40(param_1 + 0x208,&local_198);
          FUN_140036e40(param_1 + 0x220,&local_198);
          local_58 = (ulonglong)uVar10;
          uStack_50 = CONCAT44(param_4,param_3);
          FUN_140036d68(param_1 + 0xb8,&local_58);
          FUN_140036d68(param_1 + 0xd0,&local_58);
          param_3 = uVar10;
        }
        else {
          if (cVar2 == '\x04') {
            uVar10 = *(uint *)(param_1 + 0x210);
            local_190 = &DAT_1400610c8;
            local_188 = &DAT_140061068;
            local_198 = (undefined *)0x0;
            local_180 = pcVar12;
            FUN_140036e40(param_1 + 0x208,&local_198);
            FUN_140036e40(param_1 + 0x220,&local_198);
            local_58 = (ulonglong)uVar10;
            uStack_50 = CONCAT44(local_1a8,param_3);
            FUN_140036d68(param_1 + 0xb8,&local_58);
            FUN_140036d68(param_1 + 0xd0,&local_58);
            if (pcVar12[5] == '\0') {
              return 0xc000000d;
            }
            pbVar8 = (byte *)(pcVar12 + 6);
            do {
              uVar6 = (int)uVar9 + 1;
              FUN_1400375b8(param_1,(uint)*pbVar8,uVar10,uVar6);
              pbVar8 = pbVar8 + 1;
              uVar9 = (ulonglong)uVar6;
            } while ((int)uVar6 < (int)(uint)(byte)pcVar12[5]);
            return 0xc000000d;
          }
          if (cVar2 == '\x05') {
            uVar10 = *(uint *)(param_1 + 0x210);
            local_198 = &DAT_140067b00;
            local_190 = &DAT_1400610a8;
            local_188 = &DAT_1400610b8;
            local_180 = pcVar12;
            FUN_140036e40(param_1 + 0x208,&local_198);
            FUN_140036e40(param_1 + 0x220,&local_198);
            local_58 = (ulonglong)uVar10;
            uStack_50 = CONCAT44(local_1a8,param_3);
            FUN_140036d68(param_1 + 0xb8,&local_58);
            FUN_140036d68(param_1 + 0xd0,&local_58);
            if (pcVar12[5] == '\0') {
              return 0xc000000d;
            }
            pbVar8 = (byte *)(pcVar12 + 6);
            do {
              uVar6 = (int)uVar9 + 1;
              FUN_1400375b8(param_1,(uint)*pbVar8,uVar10,uVar6);
              pbVar8 = pbVar8 + 1;
              uVar9 = (ulonglong)uVar6;
            } while ((int)uVar6 < (int)(uint)(byte)pcVar12[5]);
            return 0xc000000d;
          }
          if (cVar2 != '\x06') {
            if ((cVar2 != '\b') && (cVar2 != '\t')) {
              return 0xc000000d;
            }
            goto LAB_140037ff3;
          }
          lVar4 = *(longlong *)(param_1 + 0x2d0);
          *(byte *)(param_1 + 0x262) = bVar1;
          uVar5 = *(ushort *)(pcVar12 + 0x34);
          uVar7 = 1;
          if (((*(char *)(lVar4 + 0x26fc) == '\0') || (*(char *)(lVar4 + 0x26fc) == ' ')) &&
             (uVar10 = 0xffffffff, (uVar5 & 1) != 0)) {
            uVar10 = param_3;
            if ((*(uint *)(lVar4 + 0x2374) & 0x200) != 0) {
              iVar3 = *(int *)(lVar4 + 0x26b0);
              if (iVar3 != 0xe) {
                if (((iVar3 - 1U & 0xfffffffd) == 0) && (bVar14 = false, pcVar12[4] == '\x03')) {
                  bVar14 = true;
                }
                if ((((iVar3 - 2U & 0xfffffff9) == 0) && (iVar3 != 8)) && (pcVar12[4] == '\x03')) {
                  bVar14 = true;
                }
                if (iVar3 != 0x38) goto LAB_140037723;
                if (pcVar12[4] == '\x03') {
                  bVar14 = true;
                  goto LAB_1400377d2;
                }
                goto LAB_140037877;
              }
              if (pcVar12[4] != '\x03') goto LAB_140037924;
              bVar14 = true;
LAB_140037723:
              if (iVar3 == 0xbb) {
                if (pcVar12[4] != '\x13') goto LAB_140037877;
                bVar14 = true;
LAB_14003773c:
                if (iVar3 != 0xaf) goto LAB_1400377eb;
                if (pcVar12[4] != '\a') goto LAB_140037877;
                bVar14 = true;
LAB_140037756:
                if ((iVar3 == 0x42) || (iVar3 == 0xa3)) {
                  iVar3 = (byte)pcVar12[4] - 0x14;
LAB_140037870:
                  if ((iVar3 != 0) && (iVar3 != 1)) goto LAB_140037877;
                }
                else {
                  if (iVar3 == 0xb1) {
                    if ((*(uint *)(lVar4 + 0x2384) & 0x80000) == 0) {
                      bVar13 = (pcVar12[4] - 0x19U & 0xfd) == 0;
                    }
                    else {
                      bVar13 = pcVar12[4] == '\x1c';
                    }
LAB_14003784c:
                    if (bVar13) {
LAB_14003784e:
                      bVar14 = true;
                    }
                  }
                  else {
                    if ((iVar3 == 0xb2) || (iVar3 == 0xb3)) {
LAB_140037847:
                      bVar13 = pcVar12[4] == '\x1c';
                      goto LAB_14003784c;
                    }
                    if (iVar3 == 0xb4) {
                      if ((byte)pcVar12[4] != 0x1a) {
                        iVar3 = (byte)pcVar12[4] - 0x1b;
                        goto LAB_140037870;
                      }
                      if (*(int *)(lVar4 + 0x26b4) != 0xc9 && *(int *)(lVar4 + 0x26b4) != 0xca)
                      goto LAB_140037877;
                      goto LAB_14003784e;
                    }
                    if (iVar3 == 0xb5) goto LAB_140037847;
                    if (iVar3 == 0x92) {
                      bVar13 = (pcVar12[4] - 0x13U & 0xfd) == 0;
                      goto LAB_140037864;
                    }
                  }
LAB_140037877:
                  if (!bVar14) goto LAB_140037924;
                }
              }
              else {
LAB_1400377d2:
                if (iVar3 != 0xbe) goto LAB_14003773c;
                if (pcVar12[4] != '\x13') goto LAB_140037877;
                bVar14 = true;
LAB_1400377eb:
                if (iVar3 != 0xb0) goto LAB_140037756;
                bVar13 = pcVar12[4] == '\a';
LAB_140037864:
                if (!bVar13) goto LAB_140037877;
              }
              uVar10 = *(uint *)(param_1 + 0x210);
              local_198 = &DAT_140067950;
              local_190 = &DAT_14005fd20;
              local_188 = &DAT_14005feb0;
              local_110 = (ulonglong)*(uint *)(lVar4 + 0xad8);
              local_108 = *(undefined4 *)(lVar4 + 0xadc);
              *(uint *)(param_1 + 0x244) = uVar10;
              local_180 = pcVar12;
              FUN_140036e40(param_1 + 0x208,&local_198);
              FUN_140036e40(param_1 + 0x220,&local_198);
              local_58 = (ulonglong)uVar10;
              uStack_50 = CONCAT44(param_4,param_3);
              FUN_140036d68(param_1 + 0xb8,&local_58);
              FUN_140036d68(param_1 + 0xd0,&local_58);
              param_4 = 1;
            }
LAB_140037924:
            lVar4 = *(longlong *)(param_1 + 0x2d0);
            if (*(int *)(lVar4 + 0x26b4) == 0x11) {
              if ((*(int *)(param_1 + 0x2c8) - 1U & 0xfffffffd) == 0) {
LAB_14003797e:
                memset(local_f0,0,0x90);
                local_f8 = &DAT_140067728;
                local_f0[0] = &DAT_14005fd20;
                pcVar12[0x2c] = '\0';
                pcVar12[0x2d] = '\0';
                pcVar12[0x2e] = '\0';
                pcVar12[0x2f] = -0x60;
                pcVar12[0x30] = '\0';
                pcVar12[0x31] = '\x01';
                uVar6 = *(uint *)(param_1 + 0x210);
                local_e0 = pcVar12;
                FUN_140036e40(param_1 + 0x208,&local_f8);
                FUN_140036e40(param_1 + 0x220,&local_198);
                local_58 = (ulonglong)uVar6;
                uStack_50 = CONCAT44(param_4,uVar10);
                FUN_140036d68(param_1 + 0xb8,&local_58);
                FUN_140036d68(param_1 + 0xd0,&local_58);
                lVar4 = *(longlong *)(param_1 + 0x2d0);
                param_4 = uVar7;
                uVar10 = uVar6;
                if ((*(uint *)(lVar4 + 0x237c) & 0x2000) != 0) {
                  *(undefined4 *)(param_1 + 0x34c) = 1;
                }
              }
            }
            else if (((*(int *)(lVar4 + 0x26b4) == 0x2d) &&
                     (*(uint *)(param_1 + 0x2c8) == (uint)*(byte *)(lVar4 + 0xcb8))) &&
                    ((*(uint *)(lVar4 + 0x237c) & 0x2000) != 0)) goto LAB_14003797e;
            local_198 = &DAT_140067a30;
            local_188 = &DAT_1400610d8;
            local_190 = &DAT_14005fd10;
            if (((*(int *)(lVar4 + 0x26b0) == 0x42) || (*(int *)(lVar4 + 0x26b0) == 0xa3)) &&
               (local_188 = &DAT_1400610e8, pcVar12[4] != '\x13')) {
              local_188 = &DAT_1400610d8;
            }
            param_3 = *(uint *)(param_1 + 0x210);
            *(uint *)(param_1 + 0x23c) = param_3;
            local_180 = pcVar12;
            FUN_140036e40(param_1 + 0x208,&local_198);
            FUN_140036e40(param_1 + 0x220,&local_198);
            local_58 = (ulonglong)param_3;
            uStack_50 = CONCAT44(param_4,uVar10);
            FUN_140036d68(param_1 + 0xb8,&local_58);
            FUN_140036d68(param_1 + 0xd0,&local_58);
            lVar4 = *(longlong *)(param_1 + 0x2d0);
            uVar5 = *(ushort *)(pcVar12 + 0x34);
            param_4 = uVar7;
            uVar10 = param_3;
          }
          if (*(char *)(lVar4 + 0x26fc) == '\0') {
            if ((uVar5 & 2) == 0) {
              bVar1 = pcVar12[0x36] & 2;
joined_r0x000140037b34:
              if (bVar1 == 0) goto LAB_140037c09;
            }
LAB_140037b3a:
            local_198 = &DAT_140067728;
            if ((*(int *)(lVar4 + 0x26b0) == 199) &&
               (local_198 = &DAT_140067798, pcVar12[4] != '\x13')) {
              local_198 = &DAT_140067728;
            }
            local_190 = &DAT_14005fd20;
            local_188 = &DAT_14005fd20;
            if (((*(int *)(lVar4 + 0x26b0) == 0x42) || (*(int *)(lVar4 + 0x26b0) == 0xa3)) &&
               (local_188 = &DAT_1400610f8, pcVar12[4] != '\x13')) {
              local_188 = &DAT_14005fd20;
            }
            uVar10 = *(uint *)(param_1 + 0x210);
            *(uint *)(param_1 + 0x240) = uVar10;
            local_180 = pcVar12;
            FUN_140036e40(param_1 + 0x208,&local_198);
            FUN_140036e40(param_1 + 0x220,&local_198);
            local_58 = (ulonglong)uVar10;
            uStack_50 = CONCAT44(param_4,param_3);
            FUN_140036d68(param_1 + 0xb8,&local_58);
            FUN_140036d68(param_1 + 0xd0,&local_58);
            uVar5 = *(ushort *)(pcVar12 + 0x34);
            param_4 = uVar7;
            param_3 = uVar10;
          }
          else if (*(char *)(lVar4 + 0x26fc) == ' ') {
            if (((uVar5 & 4) == 0) && ((pcVar12[0x36] & 4U) == 0)) {
              bVar1 = pcVar12[0x38] & 4;
              goto joined_r0x000140037b34;
            }
            goto LAB_140037b3a;
          }
LAB_140037c09:
          uVar6 = param_3;
          if (((uVar5 == 0) && (uVar5 = 0, *(short *)(pcVar12 + 0x36) == 0)) &&
             (*(short *)(pcVar12 + 0x38) == 0)) {
            uVar6 = *(uint *)(param_1 + 0x210);
            local_198 = (undefined *)0x0;
            local_190 = &DAT_14005fd30;
            local_188 = &DAT_14005fd30;
            local_180 = pcVar12;
            FUN_140036e40(param_1 + 0x208,&local_198);
            FUN_140036e40(param_1 + 0x220,&local_198);
            local_58 = (ulonglong)uVar6;
            uStack_50 = CONCAT44(param_4,param_3);
            FUN_140036d68(param_1 + 0xb8,&local_58);
            FUN_140036d68(param_1 + 0xd0,&local_58);
            uVar5 = *(ushort *)(pcVar12 + 0x34);
            param_4 = uVar7;
            uVar10 = uVar6;
          }
          param_3 = uVar10;
          if (((uVar5 & 0x200) != 0) ||
             ((*(uint *)(*(longlong *)(param_1 + 0x2d0) + 0x2374) & 0x40) != 0)) {
            lVar4 = *(longlong *)(param_1 + 0x2d0);
            bVar14 = true;
            if ((*(short *)(lVar4 + 0x26aa) == 0x103c) &&
               ((bVar14 = true, *(short *)(lVar4 + 0x26a8) == -0x7cf6 && ((uVar5 & 0x200) == 0)))) {
              bVar14 = pcVar12[4] == '\x03';
            }
            iVar3 = *(int *)(lVar4 + 0x26b0);
            bVar13 = false;
            if (iVar3 != 0x21) {
              bVar13 = bVar14;
            }
            if ((iVar3 - 0x2aU < 2) || (iVar3 == 0x2c)) {
              bVar13 = (bool)(*(int *)(param_1 + 0x32c) != 0 & bVar13);
            }
            if (((1 < iVar3 - 0xafU) || ((*(uint *)(lVar4 + 0x2374) & 0x200) == 0)) && (bVar13)) {
              local_104 = 10;
              local_198 = &DAT_140067648;
              local_188 = &DAT_140061108;
              local_190 = &DAT_14005fd30;
              if (((*(uint *)(lVar4 + 0x2374) & 1) == 0) || (*(uint *)(lVar4 + 0xad8) < 0xb)) {
                local_110 = 1;
                local_108 = 1;
              }
              else {
                local_110 = (ulonglong)*(uint *)(lVar4 + 0xad8);
                local_108 = 10;
              }
              param_3 = *(uint *)(param_1 + 0x210);
              *(undefined4 *)(param_1 + 0x348) = 1;
              local_180 = pcVar12;
              FUN_140036e40(param_1 + 0x208,&local_198);
              FUN_140036e40(param_1 + 0x220,&local_198);
              local_58 = (ulonglong)param_3;
              uStack_50 = CONCAT44(param_4,uVar6);
              FUN_140036d68(param_1 + 0xb8,&local_58);
              FUN_140036d68(param_1 + 0xd0,&local_58);
            }
          }
        }
        param_4 = 1;
LAB_140037ff3:
        FUN_1400375b8(param_1,(uint)(byte)pcVar12[6],param_3,param_4);
        return 0xc000000d;
      }
      uVar10 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar10;
    } while (uVar10 < *(uint *)(param_1 + 0xf0));
  }
  return 0xc000000d;
}

