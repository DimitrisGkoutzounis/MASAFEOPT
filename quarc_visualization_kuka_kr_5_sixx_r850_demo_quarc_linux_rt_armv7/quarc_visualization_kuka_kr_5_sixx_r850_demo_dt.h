/*
 * quarc_visualization_kuka_kr_5_sixx_r850_demo_dt.h
 *
 * Code generation for model "quarc_visualization_kuka_kr_5_sixx_r850_demo".
 *
 * Model version              : 1.86
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Sep 24 18:06:10 2024
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
  sizeof(t_visualization),
  sizeof(t_timeout),
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
  "t_visualization",
  "t_timeout",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1), 0, 0, 11
  }
  ,

  { (char_T *)(&quarc_visualization_kuka_kr__DW.SystemTimebase_PreviousTime), 16,
    0, 1 },

  { (char_T *)(&quarc_visualization_kuka_kr__DW.IntegerDelay_DSTATE[0]), 0, 0,
    9020 },

  { (char_T *)(&quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali),
    15, 0, 1 },

  { (char_T *)(&quarc_visualization_kuka_kr__DW.VisualizationInitialize_PWORK[0]),
    11, 0, 5 },

  { (char_T *)(&quarc_visualization_kuka_kr__DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Flag), 3, 0, 1
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&quarc_visualization_kuka_kr_5_P.VisualizationInitialize_client_),
    6, 0, 4 },

  { (char_T *)(&quarc_visualization_kuka_kr_5_P.VisualizationInitialize_initial
               [0]), 1, 0, 54 },

  { (char_T *)(&quarc_visualization_kuka_kr_5_P.VisualizationInitialize_variabl
               [0]), 7, 0, 18 },

  { (char_T *)(&quarc_visualization_kuka_kr_5_P.VisualizationInitialize_close_o),
    8, 0, 1 },

  { (char_T *)(&quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_XI), 0, 0, 26
  },

  { (char_T *)(&quarc_visualization_kuka_kr_5_P.SystemTimebase_StopOnOverrun), 8,
    0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] quarc_visualization_kuka_kr_5_sixx_r850_demo_dt.h */
