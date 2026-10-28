
wchar_t * FUN_14003a624(undefined8 param_1,int param_2)

{
  if (param_2 < 7) {
    if (param_2 == 6) {
      return L"eMic";
    }
    if (param_2 == 0) {
      return L"eHeadPhone";
    }
    if (param_2 == 1) {
      return L"eSpker";
    }
    if (param_2 == 2) {
      return L"eInternalSpk";
    }
    if (param_2 == 3) {
      return L"e2ndSpker";
    }
    if (param_2 == 4) {
      return L"eSPDIF";
    }
    if (param_2 == 5) {
      return L"eReservered";
    }
  }
  else {
    if (param_2 == 7) {
      return L"eLineIn";
    }
    if (param_2 == 8) {
      return L"e2ndMic";
    }
    if (param_2 == 9) {
      return L"e2ndLineIn";
    }
    if (param_2 == 10) {
      return L"eHeadsetMic";
    }
    if (param_2 == 0xb) {
      return L"e3rdMic";
    }
    if (param_2 == 0xc) {
      return L"eDeviceTypeCount";
    }
  }
  return L"ERROR";
}

