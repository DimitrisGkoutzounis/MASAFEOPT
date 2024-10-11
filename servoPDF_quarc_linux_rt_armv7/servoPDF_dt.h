/*
 * servoPDF_dt.h
 *
 * Code generation for model "servoPDF".
 *
 * Model version              : 14.66
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Oct 10 15:11:30 2024
 *
 * Target selection: quarc_linux_rt_armv7.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_card),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "t_card",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&servoPDF_B.countstorad), 0, 0, 9 }
  ,

  { (char_T *)(&servoPDF_DW.HILInitialize_AOVoltages), 0, 0, 6 },

  { (char_T *)(&servoPDF_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&servoPDF_DW.HILRead_PWORK), 11, 0, 9 },

  { (char_T *)(&servoPDF_DW.HILInitialize_DOStates), 6, 0, 7 },

  { (char_T *)(&servoPDF_DW.HILInitialize_POSortedChans), 7, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&servoPDF_P.t_run), 0, 0, 6 },

  { (char_T *)(&servoPDF_P.HILRead_analog_channels), 7, 0, 3 },

  { (char_T *)(&servoPDF_P.HILInitialize_OOTerminate), 0, 0, 35 },

  { (char_T *)(&servoPDF_P.HILInitialize_EIInitial), 6, 0, 5 },

  { (char_T *)(&servoPDF_P.HILInitialize_AIChannels), 7, 0, 7 },

  { (char_T *)(&servoPDF_P.HILInitialize_Active), 8, 0, 37 },

  { (char_T *)(&servoPDF_P.Switch_CurrentSetting), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] servoPDF_dt.h */
