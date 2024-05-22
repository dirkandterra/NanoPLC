TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM Demo
  VAR
    DO1 AT %QX0.0 : BOOL;
    DO2 AT %QX0.1 : BOOL;
    DO3 AT %QX0.2 : BOOL;
    DO4 AT %QX0.3 : BOOL;
    DO5 AT %QX0.4 : BOOL;
    DO6 AT %QX0.5 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
  END_VAR
  VAR
    DI1 AT %IX0.0 : BOOL;
    DI2 AT %IX0.1 : BOOL;
    DI3 AT %IX0.2 : BOOL;
    DI4 AT %IX0.3 : BOOL;
    DI5 AT %IX0.4 : BOOL;
    DI6 AT %IX0.5 : BOOL;
    DI7 AT %IX0.6 : BOOL;
    DI8 AT %IX0.7 : BOOL;
  END_VAR
  VAR
    RelayReset : BOOL;
    TON1 : TON;
    TON2 : TON;
    TON3 : TON;
    TON4 : TON;
    TON5 : TON;
  END_VAR

  TON0(EN := TRUE, IN := NOT(DI1), PT := T#250ms);
  DO1 := NOT(RelayReset) AND (DO1 OR TON0.Q);
  TON1(IN := NOT(DI2), PT := T#250ms);
  DO2 := NOT(RelayReset) AND (DO2 OR TON1.Q);
  TON2(IN := NOT(DI3), PT := T#250ms);
  DO3 := NOT(RelayReset) AND (DO3 OR TON2.Q);
  TON3(IN := NOT(DI4), PT := T#250ms);
  DO4 := NOT(RelayReset) AND (DO4 OR TON3.Q);
  TON4(IN := NOT(DI5), PT := T#250ms);
  DO5 := NOT(RelayReset) AND (DO5 OR TON4.Q);
  TON5(IN := NOT(DI6), PT := T#250ms);
  DO6 := NOT(RelayReset) AND (DO6 OR TON5.Q);
  RelayReset := NOT(DI7) OR NOT(DI8);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Demo;
  END_RESOURCE
END_CONFIGURATION
