
void FUN_14002ebec(longlong param_1,undefined2 param_2,byte param_3,byte param_4)

{
  byte local_res18 [8];
  byte local_res20 [8];
  
  local_res20[0] = 0;
  local_res18[0] = param_3;
  if (param_4 != 0) {
    FUN_14002ebb0(param_1,param_2,local_res20);
    local_res18[0] = local_res18[0] | local_res20[0] & param_4;
  }
  FUN_14003190c(param_1,0x17,0x40,0x24,0,param_2,local_res18,1,'\0');
  return;
}

