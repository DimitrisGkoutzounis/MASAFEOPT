/*
 * quarc_visualization_kuka_kr_5_sixx_r850_demo.c
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
#include "rtwtypes.h"
#include "quarc_visualization_kuka_kr_5_sixx_r850_demo_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "quarc_visualization_kuka_kr_5_sixx_r850_demo_dt.h"

/* Block signals (default storage) */
B_quarc_visualization_kuka_kr_T quarc_visualization_kuka_kr_5_B;

/* Block states (default storage) */
DW_quarc_visualization_kuka_k_T quarc_visualization_kuka_kr__DW;

/* Real-time model */
static RT_MODEL_quarc_visualization__T quarc_visualization_kuka_kr__M_;
RT_MODEL_quarc_visualization__T *const quarc_visualization_kuka_kr__M =
  &quarc_visualization_kuka_kr__M_;

/* Model output function */
void quarc_visualization_kuka_kr_5_sixx_r850_demo_output(void)
{
  real_T rtb_IntegerDelay1[6];
  real_T rtb_Bias;
  int32_T i;

  /* S-Function (continuous_sigmoid_block): '<Root>/Continuous Sigmoid' */
  /* S-Function Block: quarc_visualization_kuka_kr_5_sixx_r850_demo/Continuous Sigmoid (continuous_sigmoid_block) */
  {
    if (1) {
      {
        real_T* params;

        /* Determine the correct step size for the output ports */
        params = &quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Sigmoid[0 *
          NUMBER_OF_SIGMOID_PARAMETERS];

        /*  Check if the target position has changed or if it is the first
           simulation step, in which case we need to compute the initial
           trajectory. */
        if (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Flag == 1 ||
            quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time == 0) {
          /*  Read the new position and reset the flag */
          params[SIGMOID_PARAMETER_XD] =
            quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Target;
          quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Flag = 0;

          /*  Calculate a single step using the new trajectory to account for the target
             change that occured at the previous sample (i.e., there is a one sample delay
             between the point where the target position changes and the trajectory changes
             based on the new target)    */
          if (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time == 0) {
            /*  Do not update the trajectory since we are at time 0 in simulation
               (leave t = 0)   */
          } else {
            /*  Set the relative time to one step size so that a single step
               is computed for the new trajectory  */

            /*  Set the default values in sigmoid_parameters to the trajectory
               state at the last time step.    */
            params[SIGMOID_PARAMETER_X0] =
              quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PPos;
            params[SIGMOID_PARAMETER_V0] =
              quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PVel;
            quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time = 0.01;
          }

          /*  Calculate the new trajectory    */
          sigmoid_calculate_trajectory(params, 0, params[SIGMOID_PARAMETER_X0],
            params[SIGMOID_PARAMETER_V0],
            quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MAcc,
            quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MVel);
        }

        /* Mark the target as not reached */
        quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o4 = 0;
        if (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time <
            params[SIGMOID_PARAMETER_T1]) {
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o3 =
            params[SIGMOID_PARAMETER_AP];
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o2 =
            params[SIGMOID_PARAMETER_V0] + params[SIGMOID_PARAMETER_AP] *
            quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time;
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1 =
            params[SIGMOID_PARAMETER_X0] + (params[SIGMOID_PARAMETER_V0] + 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time) *
            quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time;
        } else if (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time <
                   params[SIGMOID_PARAMETER_T2]) {
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o3 = 0;
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o2 =
            params[SIGMOID_PARAMETER_VP];
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1 =
            params[SIGMOID_PARAMETER_X1] + params[SIGMOID_PARAMETER_VP] *
            (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time -
             params[SIGMOID_PARAMETER_T1]);
        } else if (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time <
                   params[SIGMOID_PARAMETER_T3]) {
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o3 =
            -params[SIGMOID_PARAMETER_AP];
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o2 =
            params[SIGMOID_PARAMETER_VP] - params[SIGMOID_PARAMETER_AP] *
            (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time -
             params[SIGMOID_PARAMETER_T2]);
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1 =
            params[SIGMOID_PARAMETER_X2] + (params[SIGMOID_PARAMETER_VP] - 0.5 *
            params[SIGMOID_PARAMETER_AP] *
            (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time -
             params[SIGMOID_PARAMETER_T2])) *
            (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time -
             params[SIGMOID_PARAMETER_T2]);
        } else {
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o3 = 0;
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o2 = 0;
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1 =
            params[SIGMOID_PARAMETER_XD];/* always attainable */

          /* Mark the target as reached after the hold-off period */
          if ((quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time -
               params[SIGMOID_PARAMETER_T3]) >=
              params[SIGMOID_PARAMETER_HOLD_OFF])
            quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o4 = 1;/* Assert Done signal */
        }

        /*  Save the current position/velocity to be used next time step (possibly) */
        quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PPos =
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1;
        quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PVel =
          quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o2;

        /*  Increment the relative time RWork to the NEXT time step */
        quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time += 0.01;
      }
    }
  }

  /* Bias: '<Root>/Bias' incorporates:
   *  Gain: '<Root>/Gain'
   */
  rtb_Bias = quarc_visualization_kuka_kr_5_P.Gain_Gain *
    quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1 +
    quarc_visualization_kuka_kr_5_P.Bias_Bias;
  for (i = 0; i < 6; i++) {
    /* Gain: '<Root>/Degrees to  Radians' incorporates:
     *  Constant: '<Root>/Position A'
     *  Constant: '<Root>/Position B'
     *  Product: '<Root>/Product'
     *  Product: '<Root>/Product1'
     *  Sum: '<Root>/Sum'
     */
    quarc_visualization_kuka_kr_5_B.DegreestoRadians[i] =
      (quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1 *
       quarc_visualization_kuka_kr_5_P.PositionA_Value[i] + rtb_Bias *
       quarc_visualization_kuka_kr_5_P.PositionB_Value[i]) *
      quarc_visualization_kuka_kr_5_P.DegreestoRadians_Gain;
  }

  /* S-Function (visualization_set_variables_block): '<S3>/Visualization Set Variables1' */

  /* S-Function Block: quarc_visualization_kuka_kr_5_sixx_r850_demo/Robot 1/Visualization Set Variables1 (visualization_set_variables_block) */
  {
    t_error result;
    t_uint32 memory_size;
    t_single * memory_data;
    t_double current_time;
    current_time = quarc_visualization_kuka_kr__M->Timing.t[0];
    result = visualization_get_memory
      (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali,
       &memory_data, &memory_size);
    if (result == 0 && memory_data != NULL) {
      t_single * data;
      if (3 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[0];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) 0.0;
      data[2] = (t_single) quarc_visualization_kuka_kr_5_B.DegreestoRadians[0];
      if (6 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[3];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) quarc_visualization_kuka_kr_5_B.DegreestoRadians[1];
      data[2] = (t_single) 0.0;
      if (9 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[6];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) quarc_visualization_kuka_kr_5_B.DegreestoRadians[2];
      data[2] = (t_single) 0.0;
      if (12 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[9];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) 0.0;
      data[2] = (t_single) quarc_visualization_kuka_kr_5_B.DegreestoRadians[3];
      if (15 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[12];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) quarc_visualization_kuka_kr_5_B.DegreestoRadians[4];
      data[2] = (t_single) 0.0;
      if (18 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[15];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) 0.0;
      data[2] = (t_single) quarc_visualization_kuka_kr_5_B.DegreestoRadians[5];
      result = visualization_release_memory
        (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali);
      if (result == 0) {
        if (current_time -
            quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Prev >=
            0.01) {
          quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Prev =
            current_time;
          result = visualization_flush
            (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali);
        }
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_visualization_kuka_kr__M, _rt_error_message);
      return;
    }
  }

  /* Delay: '<Root>/Integer Delay' */
  for (i = 0; i < 6; i++) {
    rtb_IntegerDelay1[i] = quarc_visualization_kuka_kr__DW.IntegerDelay_DSTATE[i];
  }

  /* End of Delay: '<Root>/Integer Delay' */

  /* S-Function (visualization_set_variables_block): '<S4>/Visualization Set Variables1' */

  /* S-Function Block: quarc_visualization_kuka_kr_5_sixx_r850_demo/Robot 2/Visualization Set Variables1 (visualization_set_variables_block) */
  {
    t_error result;
    t_uint32 memory_size;
    t_single * memory_data;
    t_double current_time;
    current_time = quarc_visualization_kuka_kr__M->Timing.t[0];
    result = visualization_get_memory
      (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali,
       &memory_data, &memory_size);
    if (result == 0 && memory_data != NULL) {
      t_single * data;
      if (21 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[18];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) 0.0;
      data[2] = (t_single) rtb_IntegerDelay1[0];
      if (24 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[21];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) rtb_IntegerDelay1[1];
      data[2] = (t_single) 0.0;
      if (27 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[24];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) rtb_IntegerDelay1[2];
      data[2] = (t_single) 0.0;
      if (30 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[27];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) 0.0;
      data[2] = (t_single) rtb_IntegerDelay1[3];
      if (33 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[30];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) rtb_IntegerDelay1[4];
      data[2] = (t_single) 0.0;
      if (36 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[33];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) 0.0;
      data[2] = (t_single) rtb_IntegerDelay1[5];
      result = visualization_release_memory
        (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali);
      if (result == 0) {
        if (current_time -
            quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Pr_b >=
            0.01) {
          quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Pr_b =
            current_time;
          result = visualization_flush
            (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali);
        }
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_visualization_kuka_kr__M, _rt_error_message);
      return;
    }
  }

  /* Delay: '<Root>/Integer Delay1' */
  for (i = 0; i < 6; i++) {
    rtb_IntegerDelay1[i] =
      quarc_visualization_kuka_kr__DW.IntegerDelay1_DSTATE[i];
  }

  /* End of Delay: '<Root>/Integer Delay1' */

  /* S-Function (visualization_set_variables_block): '<S5>/Visualization Set Variables1' */

  /* S-Function Block: quarc_visualization_kuka_kr_5_sixx_r850_demo/Robot 3/Visualization Set Variables1 (visualization_set_variables_block) */
  {
    t_error result;
    t_uint32 memory_size;
    t_single * memory_data;
    t_double current_time;
    current_time = quarc_visualization_kuka_kr__M->Timing.t[0];
    result = visualization_get_memory
      (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali,
       &memory_data, &memory_size);
    if (result == 0 && memory_data != NULL) {
      t_single * data;
      if (39 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[36];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) 0.0;
      data[2] = (t_single) rtb_IntegerDelay1[0];
      if (42 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[39];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) rtb_IntegerDelay1[1];
      data[2] = (t_single) 0.0;
      if (45 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[42];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) rtb_IntegerDelay1[2];
      data[2] = (t_single) 0.0;
      if (48 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[45];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) 0.0;
      data[2] = (t_single) rtb_IntegerDelay1[3];
      if (51 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[48];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) rtb_IntegerDelay1[4];
      data[2] = (t_single) 0.0;
      if (54 > memory_size) {
        rtmSetErrorStatus(quarc_visualization_kuka_kr__M,
                          "Variable offset + length exceeds size of visualization memory!");
        return;
      }

      data = &memory_data[51];
      data[0] = (t_single) 0.0;
      data[1] = (t_single) 0.0;
      data[2] = (t_single) rtb_IntegerDelay1[5];
      result = visualization_release_memory
        (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali);
      if (result == 0) {
        if (current_time -
            quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Pr_g >=
            0.01) {
          quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Pr_g =
            current_time;
          result = visualization_flush
            (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali);
        }
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_visualization_kuka_kr__M, _rt_error_message);
      return;
    }
  }

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  quarc_visualization_kuka_kr_5_B.PulseGenerator =
    (quarc_visualization_kuka_kr__DW.clockTickCounter <
     quarc_visualization_kuka_kr_5_P.PulseGenerator_Duty) &&
    (quarc_visualization_kuka_kr__DW.clockTickCounter >= 0) ?
    quarc_visualization_kuka_kr_5_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (quarc_visualization_kuka_kr__DW.clockTickCounter >=
      quarc_visualization_kuka_kr_5_P.PulseGenerator_Period - 1.0) {
    quarc_visualization_kuka_kr__DW.clockTickCounter = 0;
  } else {
    quarc_visualization_kuka_kr__DW.clockTickCounter++;
  }
}

/* Model update function */
void quarc_visualization_kuka_kr_5_sixx_r850_demo_update(void)
{
  int32_T i;

  /* Update for S-Function (continuous_sigmoid_block): '<Root>/Continuous Sigmoid' */
  if (1) {
    {
      if (quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Target !=
          quarc_visualization_kuka_kr_5_B.PulseGenerator) {
        quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Target =
          quarc_visualization_kuka_kr_5_B.PulseGenerator;
        quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Flag = 1;
      }

      if (quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_VMax !=
          quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MVel) {
        quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MVel =
          quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_VMax;
        quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Flag = 1;
      }

      if (quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_AMax !=
          quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MAcc) {
        quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MAcc =
          quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_AMax;
        quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Flag = 1;
      }
    }
  }

  /* Update for Delay: '<Root>/Integer Delay' */
  for (i = 0; i < 2994; i++) {
    quarc_visualization_kuka_kr__DW.IntegerDelay_DSTATE[i] =
      quarc_visualization_kuka_kr__DW.IntegerDelay_DSTATE[i + 6];
  }

  for (i = 0; i < 6; i++) {
    quarc_visualization_kuka_kr__DW.IntegerDelay_DSTATE[i + 2994] =
      quarc_visualization_kuka_kr_5_B.DegreestoRadians[i];
  }

  /* End of Update for Delay: '<Root>/Integer Delay' */

  /* Update for Delay: '<Root>/Integer Delay1' */
  for (i = 0; i < 5994; i++) {
    quarc_visualization_kuka_kr__DW.IntegerDelay1_DSTATE[i] =
      quarc_visualization_kuka_kr__DW.IntegerDelay1_DSTATE[i + 6];
  }

  for (i = 0; i < 6; i++) {
    quarc_visualization_kuka_kr__DW.IntegerDelay1_DSTATE[i + 5994] =
      quarc_visualization_kuka_kr_5_B.DegreestoRadians[i];
  }

  /* End of Update for Delay: '<Root>/Integer Delay1' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++quarc_visualization_kuka_kr__M->Timing.clockTick0)) {
    ++quarc_visualization_kuka_kr__M->Timing.clockTickH0;
  }

  quarc_visualization_kuka_kr__M->Timing.t[0] =
    quarc_visualization_kuka_kr__M->Timing.clockTick0 *
    quarc_visualization_kuka_kr__M->Timing.stepSize0 +
    quarc_visualization_kuka_kr__M->Timing.clockTickH0 *
    quarc_visualization_kuka_kr__M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void quarc_visualization_kuka_kr_5_sixx_r850_demo_initialize(void)
{
  /* Start for S-Function (visualization_initialize_block): '<Root>/Visualization Initialize' */

  /* S-Function Block: quarc_visualization_kuka_kr_5_sixx_r850_demo/Visualization Initialize (visualization_initialize_block) */
  {
    t_error result;
    result = visualization_open(
      "shmem://quarc_visualization_kuka_kr_5_sixx_r850_demo:1?private=visual",
      "", 0, quarc_visualization_kuka_kr_5_P.VisualizationInitialize_variabl, 18,
      quarc_visualization_kuka_kr_5_P.VisualizationInitialize_initial, 54,
      quarc_visualization_kuka_kr_5_P.VisualizationInitialize_serve_d,
      quarc_visualization_kuka_kr_5_P.VisualizationInitialize_server_,
      &quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_visualization_kuka_kr__M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (continuous_sigmoid_block): '<Root>/Continuous Sigmoid' */

  /* S-Function Block: quarc_visualization_kuka_kr_5_sixx_r850_demo/Continuous Sigmoid (continuous_sigmoid_block) */
  {
    real_T* params;
    params = &quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Sigmoid[0 *
      NUMBER_OF_SIGMOID_PARAMETERS];
    params[SIGMOID_PARAMETER_T1] = 0;
    params[SIGMOID_PARAMETER_T2] = 0;
    params[SIGMOID_PARAMETER_T3] = 0;
    params[SIGMOID_PARAMETER_X0] =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_XI;
    params[SIGMOID_PARAMETER_X1] =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_XI;
    params[SIGMOID_PARAMETER_X2] =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_XI;
    params[SIGMOID_PARAMETER_XD] =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_XI;
    params[SIGMOID_PARAMETER_V0] =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_VI;
    params[SIGMOID_PARAMETER_VP] = 0;
    params[SIGMOID_PARAMETER_AP] = 0;
    params[SIGMOID_PARAMETER_HOLD_OFF] =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_Hold;
    quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time = 0;
    quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Target =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_XI;
    quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PPos =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_XI;
    quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PVel =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_VI;
    quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Flag = 0;
    quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MVel =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_VMax;
    quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MAcc =
      quarc_visualization_kuka_kr_5_P.ContinuousSigmoid_AMax;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  quarc_visualization_kuka_kr__DW.clockTickCounter = 0;

  {
    int32_T i;

    /* InitializeConditions for Delay: '<Root>/Integer Delay' */
    for (i = 0; i < 3000; i++) {
      quarc_visualization_kuka_kr__DW.IntegerDelay_DSTATE[i] =
        quarc_visualization_kuka_kr_5_P.IntegerDelay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Integer Delay' */

    /* InitializeConditions for Delay: '<Root>/Integer Delay1' */
    for (i = 0; i < 6000; i++) {
      quarc_visualization_kuka_kr__DW.IntegerDelay1_DSTATE[i] =
        quarc_visualization_kuka_kr_5_P.IntegerDelay1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Integer Delay1' */
  }
}

/* Model terminate function */
void quarc_visualization_kuka_kr_5_sixx_r850_demo_terminate(void)
{
  /* Terminate for S-Function (visualization_initialize_block): '<Root>/Visualization Initialize' */

  /* S-Function Block: quarc_visualization_kuka_kr_5_sixx_r850_demo/Visualization Initialize (visualization_initialize_block) */
  {
    if (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali != NULL)
    {
      visualization_close
        (quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali);
      quarc_visualization_kuka_kr__DW.VisualizationInitialize_Visuali = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  quarc_visualization_kuka_kr_5_sixx_r850_demo_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  quarc_visualization_kuka_kr_5_sixx_r850_demo_update();
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
  quarc_visualization_kuka_kr_5_sixx_r850_demo_initialize();
}

void MdlTerminate(void)
{
  quarc_visualization_kuka_kr_5_sixx_r850_demo_terminate();
}

/* Registration function */
RT_MODEL_quarc_visualization__T *quarc_visualization_kuka_kr_5_sixx_r850_demo
  (void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)quarc_visualization_kuka_kr__M, 0,
                sizeof(RT_MODEL_quarc_visualization__T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      quarc_visualization_kuka_kr__M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "quarc_visualization_kuka_kr__M points to
       static memory which is guaranteed to be non-NULL" */
    quarc_visualization_kuka_kr__M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    quarc_visualization_kuka_kr__M->Timing.sampleTimes =
      (&quarc_visualization_kuka_kr__M->Timing.sampleTimesArray[0]);
    quarc_visualization_kuka_kr__M->Timing.offsetTimes =
      (&quarc_visualization_kuka_kr__M->Timing.offsetTimesArray[0]);

    /* task periods */
    quarc_visualization_kuka_kr__M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    quarc_visualization_kuka_kr__M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(quarc_visualization_kuka_kr__M,
             &quarc_visualization_kuka_kr__M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = quarc_visualization_kuka_kr__M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    quarc_visualization_kuka_kr__M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(quarc_visualization_kuka_kr__M, -1);
  quarc_visualization_kuka_kr__M->Timing.stepSize0 = 0.01;

  /* External mode info */
  quarc_visualization_kuka_kr__M->Sizes.checksums[0] = (4058088639U);
  quarc_visualization_kuka_kr__M->Sizes.checksums[1] = (1727139711U);
  quarc_visualization_kuka_kr__M->Sizes.checksums[2] = (233583810U);
  quarc_visualization_kuka_kr__M->Sizes.checksums[3] = (1734278102U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    quarc_visualization_kuka_kr__M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(quarc_visualization_kuka_kr__M->extModeInfo,
      &quarc_visualization_kuka_kr__M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(quarc_visualization_kuka_kr__M->extModeInfo,
                        quarc_visualization_kuka_kr__M->Sizes.checksums);
    rteiSetTPtr(quarc_visualization_kuka_kr__M->extModeInfo, rtmGetTPtr
                (quarc_visualization_kuka_kr__M));
  }

  quarc_visualization_kuka_kr__M->solverInfoPtr =
    (&quarc_visualization_kuka_kr__M->solverInfo);
  quarc_visualization_kuka_kr__M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&quarc_visualization_kuka_kr__M->solverInfo, 0.01);
  rtsiSetSolverMode(&quarc_visualization_kuka_kr__M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  quarc_visualization_kuka_kr__M->blockIO = ((void *)
    &quarc_visualization_kuka_kr_5_B);

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      quarc_visualization_kuka_kr_5_B.DegreestoRadians[i] = 0.0;
    }

    quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o1 = 0.0;
    quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o2 = 0.0;
    quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o3 = 0.0;
    quarc_visualization_kuka_kr_5_B.ContinuousSigmoid_o4 = 0.0;
    quarc_visualization_kuka_kr_5_B.PulseGenerator = 0.0;
  }

  /* parameters */
  quarc_visualization_kuka_kr__M->defaultParam = ((real_T *)
    &quarc_visualization_kuka_kr_5_P);

  /* states (dwork) */
  quarc_visualization_kuka_kr__M->dwork = ((void *)
    &quarc_visualization_kuka_kr__DW);
  (void) memset((void *)&quarc_visualization_kuka_kr__DW, 0,
                sizeof(DW_quarc_visualization_kuka_k_T));

  {
    int32_T i;
    for (i = 0; i < 3000; i++) {
      quarc_visualization_kuka_kr__DW.IntegerDelay_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 6000; i++) {
      quarc_visualization_kuka_kr__DW.IntegerDelay1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Sigmoid[i] = 0.0;
    }
  }

  quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Time = 0.0;
  quarc_visualization_kuka_kr__DW.ContinuousSigmoid_Target = 0.0;
  quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PPos = 0.0;
  quarc_visualization_kuka_kr__DW.ContinuousSigmoid_PVel = 0.0;
  quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MVel = 0.0;
  quarc_visualization_kuka_kr__DW.ContinuousSigmoid_MAcc = 0.0;
  quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Prev = 0.0;
  quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Pr_b = 0.0;
  quarc_visualization_kuka_kr__DW.VisualizationSetVariables1_Pr_g = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    quarc_visualization_kuka_kr__M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  quarc_visualization_kuka_kr__M->Sizes.numContStates = (0);/* Number of continuous states */
  quarc_visualization_kuka_kr__M->Sizes.numY = (0);/* Number of model outputs */
  quarc_visualization_kuka_kr__M->Sizes.numU = (0);/* Number of model inputs */
  quarc_visualization_kuka_kr__M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  quarc_visualization_kuka_kr__M->Sizes.numSampTimes = (1);/* Number of sample times */
  quarc_visualization_kuka_kr__M->Sizes.numBlocks = (17);/* Number of blocks */
  quarc_visualization_kuka_kr__M->Sizes.numBlockIO = (6);/* Number of block outputs */
  quarc_visualization_kuka_kr__M->Sizes.numBlockPrms = (105);/* Sum of parameter "widths" */
  return quarc_visualization_kuka_kr__M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
