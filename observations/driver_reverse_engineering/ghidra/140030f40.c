
undefined8 FUN_140030f40(longlong param_1,longlong param_2)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  wchar_t *pwVar4;
  
  if (param_2 == 0) {
    return 0xc000000d;
  }
  iVar2 = *(int *)(param_2 + 0x10);
  uVar1 = *(ushort *)(param_2 + 0x4c);
  if (iVar2 == 0x18) {
    *(uint *)(param_1 + 0x44) = ((ushort)~uVar1 & 2) << 4 | 0x18;
LAB_14003104e:
    lVar3 = param_1 + 0x44;
    pwVar4 = L"redirected_recording_widget_id";
  }
  else {
    if (iVar2 == 0x21) {
      *(uint *)(param_1 + 0x40) = (-(uint)((uVar1 & 2) != 0) & 0xffffffea) + 0x37;
    }
    else {
      if (iVar2 != 0x37) {
        if (iVar2 != 0x38) {
          return 0;
        }
        if (((uVar1 & 2) != 0) ||
           ((((*(undefined4 *)(param_1 + 0x44) = 0x18, (*(uint *)(param_1 + 0x2394) & 0x8000) != 0
              && (*(short *)(param_1 + 0x26aa) == 0xdb0)) &&
             ((*(int *)(param_1 + 0x26b0) == 0xb1 || (*(int *)(param_1 + 0x26b0) == 0x42)))) &&
            (lVar3 = FUN_14002821c(param_1,0x18), (*(byte *)(lVar3 + 0x4c) & 2) == 0)))) {
          *(undefined4 *)(param_1 + 0x44) = 0x38;
        }
        goto LAB_14003104e;
      }
      if ((uVar1 & 2) == 0) {
        *(undefined4 *)(param_1 + 0x40) = 0x21;
      }
    }
    lVar3 = param_1 + 0x40;
    pwVar4 = L"redirected_playback_widget_id";
  }
  FUN_140031bac((longlong *)(param_1 + 0x2348),0x14005b7c0,pwVar4,4,4,lVar3,0);
  return 0;
}

