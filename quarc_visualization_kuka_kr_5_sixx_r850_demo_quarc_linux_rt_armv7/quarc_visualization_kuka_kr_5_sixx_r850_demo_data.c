/*
 * quarc_visualization_kuka_kr_5_sixx_r850_demo_data.c
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

#include "quarc_visualization_kuka_kr_5_sixx_r850_demo.h"

/* Block parameters (default storage) */
P_quarc_visualization_kuka_kr_T quarc_visualization_kuka_kr_5_P = {
  /* Mask Parameter: VisualizationInitialize_client_
   * Referenced by: '<Root>/Visualization Initialize'
   */
  1000000,

  /* Mask Parameter: VisualizationInitialize_clien_o
   * Referenced by: '<Root>/Visualization Initialize'
   */
  1000,

  /* Mask Parameter: VisualizationInitialize_server_
   * Referenced by: '<Root>/Visualization Initialize'
   */
  1000,

  /* Mask Parameter: VisualizationInitialize_serve_d
   * Referenced by: '<Root>/Visualization Initialize'
   */
  1000000,

  /* Mask Parameter: VisualizationInitialize_initial
   * Referenced by: '<Root>/Visualization Initialize'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F },

  /* Mask Parameter: VisualizationInitialize_variabl
   * Referenced by: '<Root>/Visualization Initialize'
   */
  { 41U, 51U, 61U, 71U, 81U, 91U, 121U, 131U, 141U, 151U, 161U, 171U, 191U, 201U,
    211U, 221U, 231U, 241U },

  /* Mask Parameter: VisualizationInitialize_close_o
   * Referenced by: '<Root>/Visualization Initialize'
   */
  true,

  /* Expression: initial_position
   * Referenced by: '<Root>/Continuous Sigmoid'
   */
  0.0,

  /* Expression: initial_velocity
   * Referenced by: '<Root>/Continuous Sigmoid'
   */
  0.0,

  /* Expression: hold_off
   * Referenced by: '<Root>/Continuous Sigmoid'
   */
  0.5,

  /* Expression: i_max_velocity
   * Referenced by: '<Root>/Continuous Sigmoid'
   */
  5.0,

  /* Expression: i_max_acceleration
   * Referenced by: '<Root>/Continuous Sigmoid'
   */
  2.0,

  /* Expression: [-180 -45 135 -160 45 90]
   * Referenced by: '<Root>/Position A'
   */
  { -180.0, -45.0, 135.0, -160.0, 45.0, 90.0 },

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Bias'
   */
  1.0,

  /* Expression: [0 0 0 0 0 0]
   * Referenced by: '<Root>/Position B'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pi/180
   * Referenced by: '<Root>/Degrees to  Radians'
   */
  0.017453292519943295,

  /* Expression: 0.0
   * Referenced by: '<Root>/Integer Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Integer Delay1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  400.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  200.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: SystemTimebase_StopOnOverrun
   * Referenced by: '<Root>/System Timebase'
   */
  false,

  /* Computed Parameter: VisualizationInitialize_OpenVie
   * Referenced by: '<Root>/Visualization Initialize'
   */
  true
};
