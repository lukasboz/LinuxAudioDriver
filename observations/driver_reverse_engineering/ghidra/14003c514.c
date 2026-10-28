
void FUN_14003c514(short *param_1)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  wchar_t *pwVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x168);
  if (lVar2 == 0) {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x16c);
  if ((((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) || (iVar1 == 3)) {
    if ((*(uint *)(lVar2 + 0x2380) & 0x100000) == 0) {
      return;
    }
    uVar3 = *(uint *)(lVar2 + 0x2370);
    if ((uVar3 & 0x20) != 0) {
      FUN_14003bf88(param_1,0x14005d2f0,L"{C18E2F7E-933D-4965-B7D1-1EEF228D2AF3}",0,1,7,0);
      FUN_14003bf88(param_1,0x14005cf20,L"{C18E2F7E-933D-4965-B7D1-1EEF228D2AF3}",0,1,7,0);
      pwVar4 = L"{C18E2F7E-933D-4965-B7D1-1EEF228D2AF3}";
      goto LAB_14003c6c6;
    }
  }
  else {
    if (((iVar1 != 6) && (iVar1 != 8)) && ((iVar1 != 10 && (iVar1 != 0xb)))) {
      return;
    }
    if ((*(uint *)(lVar2 + 0x2380) & 0x200000) == 0) {
      return;
    }
    uVar3 = *(uint *)(lVar2 + 0x2370);
    if ((uVar3 & 0x20) != 0) {
      FUN_14003bf88(param_1,0x14005d2f0,L"{C18E2F7E-933D-4965-B7D1-1EEF228D2AF3}",0,1,7,0);
      FUN_14003bf88(param_1,0x14005cf20,L"{C18E2F7E-933D-4965-B7D1-1EEF228D2AF3}",0,1,7,0);
      pwVar4 = L"{C18E2F7E-933D-4965-B7D1-1EEF228D2AF3}";
      goto LAB_14003c6c6;
    }
  }
  if ((uVar3 & 0x10) == 0) {
    return;
  }
  FUN_14003bf88(param_1,0x14005d2f0,L"{C18E2F7E-933D-4965-B7D1-1EEF228D2AF3}",0,1,7,0);
  FUN_14003bf88(param_1,0x14005cf20,L"{C18E2F7E-933D-4965-B7D1-1EEF228D2AF3}",0,1,7,0);
  pwVar4 = L"{C18E2F7E-933D-4965-B7D1-1EEF228D2AF3}";
LAB_14003c6c6:
  FUN_14003bf88(param_1,0x14005cf80,pwVar4,0,1,7,0);
  return;
}

