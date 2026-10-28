
wchar_t * FUN_14005627c(undefined8 param_1,uint param_2)

{
  if (param_2 < 0x22) {
    if (param_2 == 0x21) {
      return L"WIDGET_ID_HP_OUT";
    }
    if (param_2 == 0) {
      return L"WIDGET_ID_INVALID";
    }
    if (param_2 == 0x12) {
      return L"WIDGET_ID_DMIC";
    }
    if (param_2 == 0x17) {
      return L"WIDGET_ID_I2S_OUT";
    }
    if (param_2 == 0x18) {
      return L"WIDGET_ID_MIC_IN";
    }
    if (param_2 == 0x19) {
      return L"WIDGET_ID_LINE_IN";
    }
    if (param_2 == 0x1e) {
      return L"WIDGET_ID_SPDIF_OUT";
    }
    if (param_2 == 0x1f) {
      return L"WIDGET_ID_TYPE_C_HEADSET";
    }
  }
  else {
    if (param_2 == 0x36) {
      return L"WIDGET_ID_STEREO_MIXER";
    }
    if (param_2 == 0x37) {
      return L"WIDGET_ID_SPK_OUT";
    }
    if (param_2 == 0x38) {
      return L"WIDGET_ID_MIC_IN2";
    }
    if (param_2 == 0x39) {
      return L"WIDGET_ID_MIC_IN3";
    }
    if (param_2 == 0x3a) {
      return L"WIDGET_ID_SPK_OUT_CENLFE";
    }
    if (param_2 == 0x3b) {
      return L"WIDGET_ID_SPK_OUT_SURR";
    }
    if (param_2 == 0x3c) {
      return L"WIDGET_ID_SPK_OUT_SIDE";
    }
  }
  return L"UNKNOWN";
}

