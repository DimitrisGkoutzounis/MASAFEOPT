/*
 * servoPDF.c
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

#include "servoPDF.h"
#include "servoPDF_private.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>
#include "servoPDF_dt.h"

/* Block signals (default storage) */
B_servoPDF_T servoPDF_B;

/* Continuous states */
X_servoPDF_T servoPDF_X;

/* Disabled State Vector */
XDis_servoPDF_T servoPDF_XDis;

/* Block states (default storage) */
DW_servoPDF_T servoPDF_DW;

/* Real-time model */
static RT_MODEL_servoPDF_T servoPDF_M_;
RT_MODEL_servoPDF_T *const servoPDF_M = &servoPDF_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  servoPDF_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    real_T q;
    q = fabs(u0 / u1);
    if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/* Model output function */
void servoPDF_output(void)
{
  /* local block i/o variables */
  real_T rtb_HILRead_o1;
  real_T Clock_tmp;
  real_T rtb_step;
  real_T tmp;
  if (rtmIsMajorTimeStep(servoPDF_M)) {
    /* set solver stop time */
    if (!(servoPDF_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&servoPDF_M->solverInfo,
                            ((servoPDF_M->Timing.clockTickH0 + 1) *
        servoPDF_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&servoPDF_M->solverInfo,
                            ((servoPDF_M->Timing.clockTick0 + 1) *
        servoPDF_M->Timing.stepSize0 + servoPDF_M->Timing.clockTickH0 *
        servoPDF_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(servoPDF_M)) {
    servoPDF_M->Timing.t[0] = rtsiGetT(&servoPDF_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(servoPDF_M)) {
    /* S-Function (hil_read_block): '<S1>/HIL Read' */

    /* S-Function Block: servoPDF/DC-servo/HIL Read (hil_read_block) */
    {
      t_error result = hil_read(servoPDF_DW.HILInitialize_Card,
        &servoPDF_P.HILRead_analog_channels, 1U,
        &servoPDF_P.HILRead_encoder_channels, 1U,
        NULL, 0U,
        NULL, 0U,
        &servoPDF_DW.HILRead_AnalogBuffer,
        &servoPDF_DW.HILRead_EncoderBuffer,
        NULL,
        NULL
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
      } else {
        rtb_HILRead_o1 = servoPDF_DW.HILRead_AnalogBuffer;
        rtb_step = servoPDF_DW.HILRead_EncoderBuffer;
      }
    }

    /* Gain: '<S1>/counts to rad' */
    servoPDF_B.countstorad = servoPDF_P.countstorad_Gain * rtb_step;

    /* DiscretePulseGenerator: '<Root>/step' */
    rtb_step = (servoPDF_DW.clockTickCounter < servoPDF_P.step_Duty) &&
      (servoPDF_DW.clockTickCounter >= 0) ? servoPDF_P.step_Amp : 0.0;
    if (servoPDF_DW.clockTickCounter >= servoPDF_P.step_Period - 1.0) {
      servoPDF_DW.clockTickCounter = 0;
    } else {
      servoPDF_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/step' */

    /* Gain: '<Root>/magnitude  (rad)' */
    servoPDF_B.magnituderad = servoPDF_P.magnituderad_Gain * rtb_step;
  }

  /* Clock: '<Root>/Clock' incorporates:
   *  Clock: '<S2>/Clock'
   */
  Clock_tmp = servoPDF_M->Timing.t[0];

  /* Clock: '<Root>/Clock' */
  servoPDF_B.Clock = Clock_tmp;

  /* ManualSwitch: '<Root>/Switch' */
  if (servoPDF_P.Switch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Switch' */
    servoPDF_B.theta_d = servoPDF_B.magnituderad;
  } else {
    /* ManualSwitch: '<Root>/Switch' incorporates:
     *  Constant: '<S2>/Constant'
     *  Lookup_n-D: '<S2>/Look-Up Table1'
     *  Math: '<S2>/Math Function'
     *  S-Function (sfun_tstart): '<S2>/startTime'
     *  Sum: '<S2>/Sum'
     */
    servoPDF_B.theta_d = look1_binlxpw(rt_remd_snf(Clock_tmp - (0.0),
      servoPDF_P.Constant_Value), servoPDF_P.LookUpTable1_bp01Data,
      servoPDF_P.triangular_rep_seq_y, 4U);
  }

  /* End of ManualSwitch: '<Root>/Switch' */
  if (rtmIsMajorTimeStep(servoPDF_M)) {
  }

  /* TransferFcn: '<Root>/Filtered Derivative' */
  servoPDF_B.FilteredDerivative = 0.0;
  servoPDF_B.FilteredDerivative += servoPDF_P.FilteredDerivative_C *
    servoPDF_X.FilteredDerivative_CSTATE;
  servoPDF_B.FilteredDerivative += servoPDF_P.FilteredDerivative_D *
    servoPDF_B.countstorad;
  if (rtmIsMajorTimeStep(servoPDF_M)) {
  }

  /* Switch: '<Root>/Switch3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch2'
   */
  if (servoPDF_B.Clock > servoPDF_P.t_run) {
    rtb_step = servoPDF_P.Constant2_Value;
    Clock_tmp = servoPDF_P.Constant_Value_b;
    tmp = servoPDF_P.Constant1_Value;
  } else {
    rtb_step = servoPDF_B.theta_d;
    Clock_tmp = servoPDF_B.ModelArgument;
    tmp = servoPDF_B.ModelArgument1;
  }

  /* Sum: '<Root>/Sum3' incorporates:
   *  Product: '<Root>/Product1'
   *  Product: '<Root>/Product2'
   *  Sum: '<Root>/Sum1'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch2'
   *  Switch: '<Root>/Switch3'
   */
  servoPDF_B.u = (rtb_step - servoPDF_B.countstorad) * Clock_tmp -
    servoPDF_B.FilteredDerivative * tmp;

  /* Saturate: '<Root>/Saturation1' */
  if (servoPDF_B.u > servoPDF_P.Saturation1_UpperSat) {
    /* Saturate: '<Root>/Saturation1' */
    servoPDF_B.Vm = servoPDF_P.Saturation1_UpperSat;
  } else if (servoPDF_B.u < servoPDF_P.Saturation1_LowerSat) {
    /* Saturate: '<Root>/Saturation1' */
    servoPDF_B.Vm = servoPDF_P.Saturation1_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation1' */
    servoPDF_B.Vm = servoPDF_B.u;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(servoPDF_M)) {
    /* S-Function (hil_write_block): '<S1>/HIL Write' */

    /* S-Function Block: servoPDF/DC-servo/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(servoPDF_DW.HILInitialize_Card,
                         &servoPDF_P.HILWrite_analog_channels, 1U,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         &servoPDF_B.Vm,
                         NULL,
                         NULL,
                         NULL
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
      }
    }

    /* ToWorkspace: '<Root>/To Workspace1' */
    if (rtmIsMajorTimeStep(servoPDF_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (servoPDF_DW.ToWorkspace1_PWORK.LoggedData),
                      &servoPDF_B.Clock, 0);
    }

    /* ToWorkspace: '<Root>/To Workspace2' */
    if (rtmIsMajorTimeStep(servoPDF_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (servoPDF_DW.ToWorkspace2_PWORK.LoggedData), &servoPDF_B.u,
                      0);
    }

    /* ToWorkspace: '<Root>/To Workspace3' */
    if (rtmIsMajorTimeStep(servoPDF_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (servoPDF_DW.ToWorkspace3_PWORK.LoggedData),
                      &servoPDF_B.countstorad, 0);
    }

    /* ToWorkspace: '<Root>/To Workspace4' */
    if (rtmIsMajorTimeStep(servoPDF_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (servoPDF_DW.ToWorkspace4_PWORK.LoggedData),
                      &servoPDF_B.FilteredDerivative, 0);
    }

    /* ToWorkspace: '<Root>/To Workspace5' */
    if (rtmIsMajorTimeStep(servoPDF_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (servoPDF_DW.ToWorkspace5_PWORK.LoggedData),
                      &servoPDF_B.Vm, 0);
    }

    /* ToWorkspace: '<Root>/To Workspace8' */
    if (rtmIsMajorTimeStep(servoPDF_M)) {
      rt_UpdateLogVar((LogVar *)(LogVar*)
                      (servoPDF_DW.ToWorkspace8_PWORK.LoggedData),
                      &servoPDF_B.theta_d, 0);
    }
  }
}

/* Model update function */
void servoPDF_update(void)
{
  if (rtmIsMajorTimeStep(servoPDF_M)) {
    rt_ertODEUpdateContinuousStates(&servoPDF_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++servoPDF_M->Timing.clockTick0)) {
    ++servoPDF_M->Timing.clockTickH0;
  }

  servoPDF_M->Timing.t[0] = rtsiGetSolverStopTime(&servoPDF_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++servoPDF_M->Timing.clockTick1)) {
      ++servoPDF_M->Timing.clockTickH1;
    }

    servoPDF_M->Timing.t[1] = servoPDF_M->Timing.clockTick1 *
      servoPDF_M->Timing.stepSize1 + servoPDF_M->Timing.clockTickH1 *
      servoPDF_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void servoPDF_derivatives(void)
{
  XDot_servoPDF_T *_rtXdot;
  _rtXdot = ((XDot_servoPDF_T *) servoPDF_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Filtered Derivative' */
  _rtXdot->FilteredDerivative_CSTATE = servoPDF_P.FilteredDerivative_A *
    servoPDF_X.FilteredDerivative_CSTATE;
  _rtXdot->FilteredDerivative_CSTATE += servoPDF_B.countstorad;
}

/* Model initialize function */
void servoPDF_initialize(void)
{
  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace1' */
  {
    int_T dimensions[1] = { 1 };

    servoPDF_DW.ToWorkspace1_PWORK.LoggedData = rt_CreateLogVar(
      servoPDF_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(servoPDF_M),
      servoPDF_M->Timing.stepSize0,
      (&rtmGetErrorStatus(servoPDF_M)),
      "t",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (servoPDF_DW.ToWorkspace1_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace2' */
  {
    int_T dimensions[1] = { 1 };

    servoPDF_DW.ToWorkspace2_PWORK.LoggedData = rt_CreateLogVar(
      servoPDF_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(servoPDF_M),
      servoPDF_M->Timing.stepSize0,
      (&rtmGetErrorStatus(servoPDF_M)),
      "u",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (servoPDF_DW.ToWorkspace2_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace3' */
  {
    int_T dimensions[1] = { 1 };

    servoPDF_DW.ToWorkspace3_PWORK.LoggedData = rt_CreateLogVar(
      servoPDF_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(servoPDF_M),
      servoPDF_M->Timing.stepSize0,
      (&rtmGetErrorStatus(servoPDF_M)),
      "theta",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (servoPDF_DW.ToWorkspace3_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace4' */
  {
    int_T dimensions[1] = { 1 };

    servoPDF_DW.ToWorkspace4_PWORK.LoggedData = rt_CreateLogVar(
      servoPDF_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(servoPDF_M),
      servoPDF_M->Timing.stepSize0,
      (&rtmGetErrorStatus(servoPDF_M)),
      "theta_dot",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (servoPDF_DW.ToWorkspace4_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace5' */
  {
    int_T dimensions[1] = { 1 };

    servoPDF_DW.ToWorkspace5_PWORK.LoggedData = rt_CreateLogVar(
      servoPDF_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(servoPDF_M),
      servoPDF_M->Timing.stepSize0,
      (&rtmGetErrorStatus(servoPDF_M)),
      "Vm",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (servoPDF_DW.ToWorkspace5_PWORK.LoggedData == (NULL))
      return;
  }

  /* SetupRuntimeResources for ToWorkspace: '<Root>/To Workspace8' */
  {
    int_T dimensions[1] = { 1 };

    servoPDF_DW.ToWorkspace8_PWORK.LoggedData = rt_CreateLogVar(
      servoPDF_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(servoPDF_M),
      servoPDF_M->Timing.stepSize0,
      (&rtmGetErrorStatus(servoPDF_M)),
      "theta_d",
      SS_DOUBLE,
      0,
      0,
      0,
      1,
      1,
      dimensions,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      0.001,
      1);
    if (servoPDF_DW.ToWorkspace8_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: servoPDF/DC-servo/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qab_controls", "0", &servoPDF_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(servoPDF_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(servoPDF_DW.HILInitialize_Card, " ",
      2);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(servoPDF_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(servoPDF_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(servoPDF_M, _rt_error_message);
      return;
    }

    if ((servoPDF_P.HILInitialize_AIPStart && !is_switching) ||
        (servoPDF_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(servoPDF_DW.HILInitialize_Card,
        &servoPDF_P.HILInitialize_AIChannels, 1U,
        &servoPDF_P.HILInitialize_AILow, &servoPDF_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }
    }

    if ((servoPDF_P.HILInitialize_AOPStart && !is_switching) ||
        (servoPDF_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(servoPDF_DW.HILInitialize_Card,
        &servoPDF_P.HILInitialize_AOChannels, 1U,
        &servoPDF_P.HILInitialize_AOLow, &servoPDF_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }
    }

    if ((servoPDF_P.HILInitialize_AOStart && !is_switching) ||
        (servoPDF_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(servoPDF_DW.HILInitialize_Card,
        &servoPDF_P.HILInitialize_AOChannels, 1U,
        &servoPDF_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(servoPDF_DW.HILInitialize_Card, NULL, 0U,
      &servoPDF_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(servoPDF_M, _rt_error_message);
      return;
    }

    if ((servoPDF_P.HILInitialize_DOStart && !is_switching) ||
        (servoPDF_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(servoPDF_DW.HILInitialize_Card,
        &servoPDF_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &servoPDF_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }
    }

    if ((servoPDF_P.HILInitialize_EIPStart && !is_switching) ||
        (servoPDF_P.HILInitialize_EIPEnter && is_switching)) {
      servoPDF_DW.HILInitialize_QuadratureModes[0] =
        servoPDF_P.HILInitialize_EIQuadrature;
      servoPDF_DW.HILInitialize_QuadratureModes[1] =
        servoPDF_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode(servoPDF_DW.HILInitialize_Card,
        servoPDF_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode *)
        &servoPDF_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }
    }

    if ((servoPDF_P.HILInitialize_EIStart && !is_switching) ||
        (servoPDF_P.HILInitialize_EIEnter && is_switching)) {
      servoPDF_DW.HILInitialize_InitialEICounts[0] =
        servoPDF_P.HILInitialize_EIInitial;
      servoPDF_DW.HILInitialize_InitialEICounts[1] =
        servoPDF_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(servoPDF_DW.HILInitialize_Card,
        servoPDF_P.HILInitialize_EIChannels, 2U,
        &servoPDF_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }
    }

    if ((servoPDF_P.HILInitialize_POPStart && !is_switching) ||
        (servoPDF_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;
      result = hil_set_pwm_mode(servoPDF_DW.HILInitialize_Card,
        &servoPDF_P.HILInitialize_POChannels, 1U, (t_pwm_mode *)
        &servoPDF_P.HILInitialize_POModes);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }

      if (servoPDF_P.HILInitialize_POModes == PWM_DUTY_CYCLE_MODE ||
          servoPDF_P.HILInitialize_POModes == PWM_ONE_SHOT_MODE ||
          servoPDF_P.HILInitialize_POModes == PWM_TIME_MODE ||
          servoPDF_P.HILInitialize_POModes == PWM_RAW_MODE) {
        servoPDF_DW.HILInitialize_POSortedChans =
          servoPDF_P.HILInitialize_POChannels;
        servoPDF_DW.HILInitialize_POSortedFreqs =
          servoPDF_P.HILInitialize_POFrequency;
        num_duty_cycle_modes++;
      } else {
        servoPDF_DW.HILInitialize_POSortedChans =
          servoPDF_P.HILInitialize_POChannels;
        servoPDF_DW.HILInitialize_POSortedFreqs =
          servoPDF_P.HILInitialize_POFrequency;
        num_frequency_modes++;
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(servoPDF_DW.HILInitialize_Card,
          &servoPDF_DW.HILInitialize_POSortedChans, num_duty_cycle_modes,
          &servoPDF_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(servoPDF_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(servoPDF_DW.HILInitialize_Card,
          &servoPDF_DW.HILInitialize_POSortedChans, num_frequency_modes,
          &servoPDF_DW.HILInitialize_POSortedFreqs);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(servoPDF_M, _rt_error_message);
          return;
        }
      }

      result = hil_set_pwm_configuration(servoPDF_DW.HILInitialize_Card,
        &servoPDF_P.HILInitialize_POChannels, 1U,
        (t_pwm_configuration *) &servoPDF_P.HILInitialize_POConfiguration,
        (t_pwm_alignment *) &servoPDF_P.HILInitialize_POAlignment,
        (t_pwm_polarity *) &servoPDF_P.HILInitialize_POPolarity);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }

      result = hil_set_pwm_deadband(servoPDF_DW.HILInitialize_Card,
        &servoPDF_P.HILInitialize_POChannels, 1U,
        &servoPDF_P.HILInitialize_POLeading,
        &servoPDF_P.HILInitialize_POTrailing);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }
    }

    if ((servoPDF_P.HILInitialize_POStart && !is_switching) ||
        (servoPDF_P.HILInitialize_POEnter && is_switching)) {
      result = hil_write_pwm(servoPDF_DW.HILInitialize_Card,
        &servoPDF_P.HILInitialize_POChannels, 1U,
        &servoPDF_P.HILInitialize_POInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for DiscretePulseGenerator: '<Root>/step' */
  servoPDF_DW.clockTickCounter = 0;

  /* InitializeConditions for TransferFcn: '<Root>/Filtered Derivative' */
  servoPDF_X.FilteredDerivative_CSTATE = 0.0;
}

/* Model terminate function */
void servoPDF_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: servoPDF/DC-servo/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(servoPDF_DW.HILInitialize_Card);
    hil_monitor_stop_all(servoPDF_DW.HILInitialize_Card);
    is_switching = false;
    if ((servoPDF_P.HILInitialize_AOTerminate && !is_switching) ||
        (servoPDF_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((servoPDF_P.HILInitialize_DOTerminate && !is_switching) ||
        (servoPDF_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((servoPDF_P.HILInitialize_POTerminate && !is_switching) ||
        (servoPDF_P.HILInitialize_POExit && is_switching)) {
      num_final_pwm_outputs = 1U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        || num_final_digital_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(servoPDF_DW.HILInitialize_Card
                         , &servoPDF_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , &servoPDF_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , &servoPDF_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , NULL, 0
                         , &servoPDF_P.HILInitialize_AOFinal
                         , &servoPDF_P.HILInitialize_POFinal
                         , (t_boolean *) &servoPDF_P.HILInitialize_DOFinal
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(servoPDF_DW.HILInitialize_Card,
            &servoPDF_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &servoPDF_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(servoPDF_DW.HILInitialize_Card,
            &servoPDF_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &servoPDF_P.HILInitialize_POFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(servoPDF_DW.HILInitialize_Card,
            &servoPDF_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &servoPDF_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(servoPDF_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(servoPDF_DW.HILInitialize_Card);
    hil_monitor_delete_all(servoPDF_DW.HILInitialize_Card);
    hil_close(servoPDF_DW.HILInitialize_Card);
    servoPDF_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  servoPDF_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  servoPDF_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  servoPDF_initialize();
}

void MdlTerminate(void)
{
  servoPDF_terminate();
}

/* Registration function */
RT_MODEL_servoPDF_T *servoPDF(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)servoPDF_M, 0,
                sizeof(RT_MODEL_servoPDF_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&servoPDF_M->solverInfo,
                          &servoPDF_M->Timing.simTimeStep);
    rtsiSetTPtr(&servoPDF_M->solverInfo, &rtmGetTPtr(servoPDF_M));
    rtsiSetStepSizePtr(&servoPDF_M->solverInfo, &servoPDF_M->Timing.stepSize0);
    rtsiSetdXPtr(&servoPDF_M->solverInfo, &servoPDF_M->derivs);
    rtsiSetContStatesPtr(&servoPDF_M->solverInfo, (real_T **)
                         &servoPDF_M->contStates);
    rtsiSetNumContStatesPtr(&servoPDF_M->solverInfo,
      &servoPDF_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&servoPDF_M->solverInfo,
      &servoPDF_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&servoPDF_M->solverInfo,
      &servoPDF_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&servoPDF_M->solverInfo,
      &servoPDF_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&servoPDF_M->solverInfo, (boolean_T**)
      &servoPDF_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&servoPDF_M->solverInfo, (&rtmGetErrorStatus
      (servoPDF_M)));
    rtsiSetRTModelPtr(&servoPDF_M->solverInfo, servoPDF_M);
  }

  rtsiSetSimTimeStep(&servoPDF_M->solverInfo, MAJOR_TIME_STEP);
  servoPDF_M->intgData.f[0] = servoPDF_M->odeF[0];
  servoPDF_M->contStates = ((real_T *) &servoPDF_X);
  servoPDF_M->contStateDisabled = ((boolean_T *) &servoPDF_XDis);
  servoPDF_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&servoPDF_M->solverInfo, (void *)&servoPDF_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&servoPDF_M->solverInfo, false);
  rtsiSetSolverName(&servoPDF_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = servoPDF_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "servoPDF_M points to
       static memory which is guaranteed to be non-NULL" */
    servoPDF_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    servoPDF_M->Timing.sampleTimes = (&servoPDF_M->Timing.sampleTimesArray[0]);
    servoPDF_M->Timing.offsetTimes = (&servoPDF_M->Timing.offsetTimesArray[0]);

    /* task periods */
    servoPDF_M->Timing.sampleTimes[0] = (0.0);
    servoPDF_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    servoPDF_M->Timing.offsetTimes[0] = (0.0);
    servoPDF_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(servoPDF_M, &servoPDF_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = servoPDF_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    servoPDF_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(servoPDF_M, 5.99);
  servoPDF_M->Timing.stepSize0 = 0.001;
  servoPDF_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    servoPDF_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(servoPDF_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(servoPDF_M->rtwLogInfo, (NULL));
    rtliSetLogT(servoPDF_M->rtwLogInfo, "");
    rtliSetLogX(servoPDF_M->rtwLogInfo, "");
    rtliSetLogXFinal(servoPDF_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(servoPDF_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(servoPDF_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(servoPDF_M->rtwLogInfo, 0);
    rtliSetLogDecimation(servoPDF_M->rtwLogInfo, 1);
    rtliSetLogY(servoPDF_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(servoPDF_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(servoPDF_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  servoPDF_M->Sizes.checksums[0] = (3931983829U);
  servoPDF_M->Sizes.checksums[1] = (3282753930U);
  servoPDF_M->Sizes.checksums[2] = (2208456370U);
  servoPDF_M->Sizes.checksums[3] = (308127812U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    servoPDF_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(servoPDF_M->extModeInfo,
      &servoPDF_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(servoPDF_M->extModeInfo, servoPDF_M->Sizes.checksums);
    rteiSetTPtr(servoPDF_M->extModeInfo, rtmGetTPtr(servoPDF_M));
  }

  servoPDF_M->solverInfoPtr = (&servoPDF_M->solverInfo);
  servoPDF_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&servoPDF_M->solverInfo, 0.001);
  rtsiSetSolverMode(&servoPDF_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  servoPDF_M->blockIO = ((void *) &servoPDF_B);
  (void) memset(((void *) &servoPDF_B), 0,
                sizeof(B_servoPDF_T));

  /* parameters */
  servoPDF_M->defaultParam = ((real_T *)&servoPDF_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &servoPDF_X;
    servoPDF_M->contStates = (x);
    (void) memset((void *)&servoPDF_X, 0,
                  sizeof(X_servoPDF_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &servoPDF_XDis;
    servoPDF_M->contStateDisabled = (xdis);
    (void) memset((void *)&servoPDF_XDis, 0,
                  sizeof(XDis_servoPDF_T));
  }

  /* states (dwork) */
  servoPDF_M->dwork = ((void *) &servoPDF_DW);
  (void) memset((void *)&servoPDF_DW, 0,
                sizeof(DW_servoPDF_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    servoPDF_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  servoPDF_M->Sizes.numContStates = (1);/* Number of continuous states */
  servoPDF_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  servoPDF_M->Sizes.numY = (0);        /* Number of model outputs */
  servoPDF_M->Sizes.numU = (0);        /* Number of model inputs */
  servoPDF_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  servoPDF_M->Sizes.numSampTimes = (2);/* Number of sample times */
  servoPDF_M->Sizes.numBlocks = (35);  /* Number of blocks */
  servoPDF_M->Sizes.numBlockIO = (9);  /* Number of block outputs */
  servoPDF_M->Sizes.numBlockPrms = (94);/* Sum of parameter "widths" */
  return servoPDF_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
