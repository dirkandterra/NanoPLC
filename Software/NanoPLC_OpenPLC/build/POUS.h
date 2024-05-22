#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM DEMO
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(BOOL,DO1)
  __DECLARE_LOCATED(BOOL,DO2)
  __DECLARE_LOCATED(BOOL,DO3)
  __DECLARE_LOCATED(BOOL,DO4)
  __DECLARE_LOCATED(BOOL,DO5)
  __DECLARE_LOCATED(BOOL,DO6)
  TON TON0;
  __DECLARE_LOCATED(BOOL,DI1)
  __DECLARE_LOCATED(BOOL,DI2)
  __DECLARE_LOCATED(BOOL,DI3)
  __DECLARE_LOCATED(BOOL,DI4)
  __DECLARE_LOCATED(BOOL,DI5)
  __DECLARE_LOCATED(BOOL,DI6)
  __DECLARE_LOCATED(BOOL,DI7)
  __DECLARE_LOCATED(BOOL,DI8)
  __DECLARE_VAR(BOOL,RELAYRESET)
  TON TON1;
  TON TON2;
  TON TON3;
  TON TON4;
  TON TON5;

} DEMO;

void DEMO_init__(DEMO *data__, BOOL retain);
// Code part
void DEMO_body__(DEMO *data__);
#endif //__POUS_H
