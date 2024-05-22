void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void DEMO_init__(DEMO *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__QX0_0,data__->DO1,retain)
  __INIT_LOCATED_VALUE(data__->DO1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->DO2,retain)
  __INIT_LOCATED_VALUE(data__->DO2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->DO3,retain)
  __INIT_LOCATED_VALUE(data__->DO3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_3,data__->DO4,retain)
  __INIT_LOCATED_VALUE(data__->DO4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->DO5,retain)
  __INIT_LOCATED_VALUE(data__->DO5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_5,data__->DO6,retain)
  __INIT_LOCATED_VALUE(data__->DO6,__BOOL_LITERAL(FALSE))
  TON_init__(&data__->TON0,retain);
  __INIT_LOCATED(BOOL,__IX0_0,data__->DI1,retain)
  __INIT_LOCATED_VALUE(data__->DI1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1,data__->DI2,retain)
  __INIT_LOCATED_VALUE(data__->DI2,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_2,data__->DI3,retain)
  __INIT_LOCATED_VALUE(data__->DI3,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_3,data__->DI4,retain)
  __INIT_LOCATED_VALUE(data__->DI4,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_4,data__->DI5,retain)
  __INIT_LOCATED_VALUE(data__->DI5,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_5,data__->DI6,retain)
  __INIT_LOCATED_VALUE(data__->DI6,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_6,data__->DI7,retain)
  __INIT_LOCATED_VALUE(data__->DI7,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_7,data__->DI8,retain)
  __INIT_LOCATED_VALUE(data__->DI8,__BOOL_LITERAL(FALSE))
  __INIT_VAR(data__->RELAYRESET,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  TON_init__(&data__->TON3,retain);
  TON_init__(&data__->TON4,retain);
  TON_init__(&data__->TON5,retain);
}

// Code part
void DEMO_body__(DEMO *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TON0.,IN,,!(__GET_LOCATED(data__->DI1,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_LOCATED(data__->,DO1,,(!(__GET_VAR(data__->RELAYRESET,)) && (__GET_LOCATED(data__->DO1,) || __GET_VAR(data__->TON0.Q,))));
  __SET_VAR(data__->TON1.,IN,,!(__GET_LOCATED(data__->DI2,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_LOCATED(data__->,DO2,,(!(__GET_VAR(data__->RELAYRESET,)) && (__GET_LOCATED(data__->DO2,) || __GET_VAR(data__->TON1.Q,))));
  __SET_VAR(data__->TON2.,IN,,!(__GET_LOCATED(data__->DI3,)));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TON_body__(&data__->TON2);
  __SET_LOCATED(data__->,DO3,,(!(__GET_VAR(data__->RELAYRESET,)) && (__GET_LOCATED(data__->DO3,) || __GET_VAR(data__->TON2.Q,))));
  __SET_VAR(data__->TON3.,IN,,!(__GET_LOCATED(data__->DI4,)));
  __SET_VAR(data__->TON3.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TON_body__(&data__->TON3);
  __SET_LOCATED(data__->,DO4,,(!(__GET_VAR(data__->RELAYRESET,)) && (__GET_LOCATED(data__->DO4,) || __GET_VAR(data__->TON3.Q,))));
  __SET_VAR(data__->TON4.,IN,,!(__GET_LOCATED(data__->DI5,)));
  __SET_VAR(data__->TON4.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TON_body__(&data__->TON4);
  __SET_LOCATED(data__->,DO5,,(!(__GET_VAR(data__->RELAYRESET,)) && (__GET_LOCATED(data__->DO5,) || __GET_VAR(data__->TON4.Q,))));
  __SET_VAR(data__->TON5.,IN,,!(__GET_LOCATED(data__->DI6,)));
  __SET_VAR(data__->TON5.,PT,,__time_to_timespec(1, 250, 0, 0, 0, 0));
  TON_body__(&data__->TON5);
  __SET_LOCATED(data__->,DO6,,(!(__GET_VAR(data__->RELAYRESET,)) && (__GET_LOCATED(data__->DO6,) || __GET_VAR(data__->TON5.Q,))));
  __SET_VAR(data__->,RELAYRESET,,(!(__GET_LOCATED(data__->DI7,)) || !(__GET_LOCATED(data__->DI8,))));

  goto __end;

__end:
  return;
} // DEMO_body__() 





