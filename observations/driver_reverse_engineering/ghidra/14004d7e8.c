
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14004d7e8(short *param_1,uint param_2,longlong param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  int *piVar9;
  int iVar10;
  undefined1 auStackY_1a8 [32];
  int local_178;
  uint local_174;
  longlong local_170;
  undefined1 local_168 [8];
  undefined8 local_160;
  undefined1 local_158 [8];
  undefined8 local_150;
  char local_148 [128];
  char local_c8 [128];
  ulonglong local_48;
  
  local_48 = DAT_1400698c0 ^ (ulonglong)auStackY_1a8;
  uVar8 = 0xc000000d;
  if (param_2 < *(uint *)(param_1 + 0x108)) {
    lVar7 = (ulonglong)param_2 * 0x98 + *(longlong *)(param_1 + 0x10c);
    if (*(undefined **)(lVar7 + 8) == &DAT_14005fd30) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_3 + 0x20);
      if (iVar4 == -1) {
        return 0xc000000d;
      }
    }
    if (iVar4 < (int)(uint)*(byte *)(*(longlong *)(lVar7 + 0x18) + 0x26)) {
      if ((*(undefined **)(lVar7 + 8) == &DAT_14005fd20) &&
         (*(undefined **)(lVar7 + 0x10) == &DAT_14005feb0)) {
        uVar2 = *(uint *)(param_3 + 0x14);
        iVar10 = *(int *)(lVar7 + 0x88) << 0x10;
        iVar6 = *(int *)(lVar7 + 0x8c) << 0x10;
        piVar1 = (int *)(lVar7 + 0x20 + (longlong)iVar4 * 4);
        if (((((uVar2 & 2) == 0) || (param_4 == (int *)0x0)) ||
            ((iVar6 <= *param_4 && (*param_4 <= iVar10)))) && (piVar1 != (int *)0x0)) {
          local_174 = param_2;
          local_170 = param_3;
          if (((uVar2 >> 0x10 & 1) == 0) || (param_4 != (int *)0x0)) {
            if ((uVar2 & 2) != 0) {
              if (param_4 == (int *)0x0) {
                return 0xc000000d;
              }
              local_178 = *param_4;
              if (local_178 < iVar6) {
                return 0xc000000d;
              }
              if (iVar10 < local_178) {
                return 0xc000000d;
              }
              if (*(int *)(lVar7 + 0x90) != 0) {
                local_178 = local_178 - local_178 % *(int *)(lVar7 + 0x90);
              }
              *(int *)(lVar7 + 0x20 + (longlong)iVar4 * 4) = local_178;
              if (iVar4 == 0) {
                piVar9 = (int *)(lVar7 + 0x24);
                for (lVar5 = 7; lVar5 != 0; lVar5 = lVar5 + -1) {
                  *piVar9 = local_178;
                  piVar9 = piVar9 + 1;
                }
                lVar5 = *(longlong *)(param_1 + 0x168);
                if ((*(int *)(lVar5 + 0x26b0) - 0xafU < 2) || (*(int *)(lVar5 + 0x26b4) == 7)) {
                  if (*(longlong *)(lVar5 + 0xb20) != 0) {
                    (*(code *)PTR__guard_dispatch_icall_14005f458)
                              (*(longlong *)(lVar5 + 0xb20),param_1);
                  }
                }
                else {
                  FUN_14003c4a8(param_1,6,(short *)&local_178,4);
                }
              }
              *piVar1 = *param_4;
              if ((*(uint *)(local_170 + 0x14) >> 0x10 & 1) != 0) {
                return 0;
              }
              iVar4 = RtlStringFromGUID(*(undefined8 *)(lVar7 + 8),local_158);
              if (iVar4 < 0) {
                return 0;
              }
              FUN_14002f25c(local_c8,0x80,L"%ws2,%d",local_150);
              FUN_14003cd74((longlong)param_1,0x14005c340,local_c8,4,4,piVar1);
              RtlFreeUnicodeString(local_158);
              return 0;
            }
            if ((uVar2 & 1) == 0) {
              return 0xc000000d;
            }
            *param_4 = *piVar1;
          }
          else {
            iVar6 = RtlStringFromGUID(*(undefined8 *)(lVar7 + 8),local_168);
            if (-1 < iVar6) {
              FUN_14002f25c(local_148,0x80,L"%ws2,%d",local_160);
              bVar3 = FUN_14003b590((longlong)param_1,0x14005c340,local_148,4,(undefined8 *)piVar1);
              if ((!bVar3) && (*(longlong *)(*(longlong *)(param_1 + 0x168) + 0xb18) != 0)) {
                (*(code *)PTR__guard_dispatch_icall_14005f458)
                          (*(undefined8 *)(*(longlong *)(param_1 + 0x168) + 0xb18),param_1,lVar7,
                           iVar4);
              }
              FUN_14004d7e8(param_1,local_174,local_170,piVar1);
              RtlFreeUnicodeString(local_168);
            }
          }
          uVar8 = 0;
        }
      }
      else {
        uVar8 = 0xc00000bb;
      }
    }
  }
  return uVar8;
}

