
wchar_t * FUN_1400560ec(undefined8 param_1,uint param_2)

{
  if (param_2 < 0x10) {
    if (param_2 == 0xf) {
      return L"WidgetTypeMicIn2";
    }
    if (param_2 < 6) {
      if (param_2 == 5) {
        return L"WidgetTypeSurr";
      }
      if (param_2 == 0) {
        return L"WidgetTypeLineIn";
      }
      if (param_2 == 1) {
        return L"WidgetTypeMicIn";
      }
      if (param_2 == 2) {
        return L"WidgetTypeHeadPhone";
      }
      if (param_2 == 3) {
        return L"WidgetTypeLineOut";
      }
      if (param_2 == 4) {
        return L"WidgetTypeFront";
      }
    }
    else {
      if (param_2 == 6) {
        return L"WidgetTypeCenter";
      }
      if (param_2 == 7) {
        return L"WidgetTypeSide";
      }
      if (param_2 == 8) {
        return L"WidgetTypeSpdifOut";
      }
      if (param_2 == 9) {
        return L"WidgetTypeSpdifIn";
      }
      if (param_2 == 10) {
        return L"WidgetTypeAUX";
      }
    }
  }
  else if (param_2 < 0x34) {
    if (param_2 == 0x33) {
      return L"WidgetTypeCTIAHeadset";
    }
    if (param_2 == 0x20) {
      return L"WidgetTypeHeadSetHPMic";
    }
    if (param_2 == 0x21) {
      return L"WidgetTypeHeadSetMic";
    }
    if (param_2 == 0x22) {
      return L"WidgetTypeHeadSetOMTP";
    }
    if (param_2 == 0x23) {
      return L"WidgetTypeHeadSetCTIA";
    }
    if (param_2 == 0x24) {
      return L"WidgetTypeStereoMix";
    }
    if (param_2 == 0x30) {
      return L"WidgetTypeMicOfHeadset";
    }
    if (param_2 == 0x31) {
      return L"WidgetTypeHpOfHeadset";
    }
    if (param_2 == 0x32) {
      return L"WidgetTypeOMTPHeadset";
    }
  }
  else {
    if (param_2 == 0x100) {
      return L"WidgetTypeSplitDevice";
    }
    if (param_2 == 0x101) {
      return L"WidgetTypeExtAntenna";
    }
    if (param_2 == 0x103) {
      return L"WidgetTypeSkullcandyHp";
    }
    if (param_2 == 0x104) {
      return L"WidgetTypeDellSpk";
    }
    if (param_2 == 0x105) {
      return L"WidgetTypeSkullcandyHeadset";
    }
    if (param_2 == 0x106) {
      return L"WidgetTypeInternalSubwoofer";
    }
    if (param_2 == 0xffff) {
      return L"WidgetTypeUnKnown";
    }
  }
  return L"UNKNOWN";
}

