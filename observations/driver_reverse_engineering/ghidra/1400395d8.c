
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1400395d8(short *param_1)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  char cVar5;
  wchar_t *pwVar6;
  undefined1 auStackY_278 [32];
  char local_238 [4];
  undefined4 local_234;
  uint local_230 [2];
  wchar_t local_228 [256];
  ulonglong local_28;
  
  local_28 = DAT_1400698c0 ^ (ulonglong)auStackY_278;
  lVar2 = *(longlong *)(param_1 + 0x168);
  iVar3 = -0x3fffffff;
  if (lVar2 == 0) {
    return -0x3ffffff3;
  }
  iVar1 = *(int *)(lVar2 + 0x26b0);
  if (iVar1 == 0xe) {
    iVar3 = *(int *)(param_1 + 0x164);
    local_234 = 0;
    if (iVar3 == 1) {
      pwVar6 = L"Internal Microphone";
    }
    else if (iVar3 == 2) {
      pwVar6 = L"Headset Microphone";
    }
    else if (iVar3 == 3) {
      pwVar6 = L"Internal Speaker";
    }
    else {
      if (iVar3 != 4) {
        return -0x3fffffff;
      }
      pwVar6 = L"Headphone";
    }
    iVar3 = FUN_14003bf88(param_1,0x14005c7a0,pwVar6,0,0,1,1);
    if (iVar3 < 0) {
      return iVar3;
    }
    if (*param_1 == 0) {
      return iVar3;
    }
    local_234 = 1;
    FUN_14003cd74((longlong)param_1,0,L"CustomizedEndpointName",4,4,&local_234);
    return iVar3;
  }
  if ((iVar1 != 0x42) && ((0x11 < iVar1 - 0xa3U || ((0x24001U >> (iVar1 - 0xa3U & 0x1f) & 1) == 0)))
     ) {
    if (iVar1 == 0xf) {
      if (*(int *)(param_1 + 0x164) == 1) {
        pwVar6 = L"Internal Microphone";
      }
      else {
        if (*(int *)(param_1 + 0x164) != 2) {
          return -0x3fffffff;
        }
        pwVar6 = L"Internal Speaker";
      }
    }
    else if (iVar1 == 0x34) {
      local_238[0] = '\0';
      memset(local_228,0,0x200);
      iVar3 = *(int *)(param_1 + 0x164);
      local_230[0] = 0x200;
      if (iVar3 == 1) {
        cVar5 = '\a';
      }
      else if (iVar3 == 2) {
        cVar5 = '\b';
      }
      else {
        if (iVar3 != 3) {
          return -0x3fffffff;
        }
        cVar5 = '\t';
      }
      uVar4 = FUN_14003a5a0((longlong)param_1,cVar5,local_238);
      if ((int)uVar4 < 0) {
        return (int)uVar4;
      }
      iVar3 = FUN_1400291d8(*(longlong *)(param_1 + 0x168),local_238[0],(undefined8 *)local_228,
                            local_230);
      if (iVar3 < 0) {
        return iVar3;
      }
      pwVar6 = local_228;
    }
    else if (iVar1 == 0xbc) {
      if (*(int *)(param_1 + 0x16c) != 6) {
        return -0x3fffffff;
      }
      pwVar6 = L"HP Envy USB Microphone";
    }
    else if (iVar1 == 0x2e) {
      if (*(int *)(param_1 + 0x16c) != 1) {
        return -0x3fffffff;
      }
      pwVar6 = L"Line Out";
    }
    else {
      if (iVar1 != 0x2d) {
        return -0x3fffffff;
      }
      if (*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar2 + 0xcb8)) {
        pwVar6 = L"Internal Speakers";
      }
      else {
        if (*(uint *)(param_1 + 0x164) != (uint)*(byte *)(lVar2 + 0xcb0)) {
          return -0x3fffffff;
        }
        if (*(int *)(param_1 + 0x16c) != 1) {
          return -0x3fffffff;
        }
        pwVar6 = L"External Speakers";
      }
    }
    goto LAB_140039994;
  }
  if ((*(int *)(lVar2 + 0x26b4) == 0x7b) || (*(int *)(lVar2 + 0x26b4) - 0x7eU < 4)) {
    if (*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar2 + 0xcb1)) {
      pwVar6 = L"Mic in at front panel (Pink)";
    }
    else {
      if (*(uint *)(param_1 + 0x164) != (uint)*(byte *)(lVar2 + 0xcb3)) goto LAB_1400398f0;
      pwVar6 = L"Mic in at rear panel (Pink)";
    }
    iVar3 = FUN_14003bf88(param_1,0x14005c7a0,pwVar6,0,0,1,1);
  }
LAB_1400398f0:
  lVar2 = *(longlong *)(param_1 + 0x168);
  if ((*(int *)(lVar2 + 0x26b4) == 0x85) || (*(short *)(lVar2 + 0x26a8) == 0x1b9b)) {
    if (*(uint *)(param_1 + 0x164) == (uint)*(byte *)(lVar2 + 0xcb1)) {
      pwVar6 = L"Front Mic";
      if (*(int *)(param_1 + 0x16c) != 8) {
        pwVar6 = L"Front Line";
      }
    }
    else {
      if (*(uint *)(param_1 + 0x164) != (uint)*(byte *)(lVar2 + 0xcb4)) goto LAB_140039984;
      pwVar6 = L"Rear Mic";
      if (*(int *)(param_1 + 0x16c) != 6) {
        pwVar6 = L"Rear Line";
      }
    }
    iVar3 = FUN_14003bf88(param_1,0x14005c7a0,pwVar6,0,0,1,1);
  }
LAB_140039984:
  if (*(int *)(param_1 + 0x16c) != 4) {
    return iVar3;
  }
  pwVar6 = L"Realtek Digital Output";
LAB_140039994:
  iVar3 = FUN_14003bf88(param_1,0x14005c7a0,pwVar6,0,0,1,1);
  return iVar3;
}

