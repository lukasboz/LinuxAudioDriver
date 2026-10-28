
longlong FUN_14003ccf0(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x2d0);
  if ((*(uint *)(lVar1 + 0x2370) & 8) == 0) {
    lVar1 = FUN_14002daec(lVar1);
    return lVar1;
  }
  if (((*(uint *)(lVar1 + 0x2380) >> 0xc & 1) != 0) && (*(longlong *)(param_1 + 0x388) != 0)) {
    lVar1 = FUN_14004ccf8(*(longlong *)(param_1 + 0x388));
    return lVar1;
  }
  LOCK();
  lVar1 = *(longlong *)(param_1 + 0x300);
  bVar2 = lVar1 == 0;
  if (bVar2) {
    *(longlong *)(param_1 + 0x300) = 0;
    lVar1 = 0;
  }
  UNLOCK();
  if (!bVar2) {
    lVar1 = KsGenerateEvents(*(undefined8 *)(param_1 + 0x300),&DAT_140060e98,1,0,0,0,0);
  }
  return lVar1;
}

