/*******************************************************************************
* File Name: PIDLoopTimer.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the PIDLoopTimer
*  component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PIDLoopTimer.h"

uint8 PIDLoopTimer_initVar = 0u;


/*******************************************************************************
* Function Name: PIDLoopTimer_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default PIDLoopTimer configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (PIDLoopTimer__QUAD == PIDLoopTimer_CONFIG)
        PIDLoopTimer_CONTROL_REG = PIDLoopTimer_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        PIDLoopTimer_TRIG_CONTROL1_REG  = PIDLoopTimer_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        PIDLoopTimer_SetInterruptMode(PIDLoopTimer_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        PIDLoopTimer_SetCounterMode(PIDLoopTimer_COUNT_DOWN);
        PIDLoopTimer_WritePeriod(PIDLoopTimer_QUAD_PERIOD_INIT_VALUE);
        PIDLoopTimer_WriteCounter(PIDLoopTimer_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (PIDLoopTimer__QUAD == PIDLoopTimer_CONFIG) */

    #if (PIDLoopTimer__TIMER == PIDLoopTimer_CONFIG)
        PIDLoopTimer_CONTROL_REG = PIDLoopTimer_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        PIDLoopTimer_TRIG_CONTROL1_REG  = PIDLoopTimer_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        PIDLoopTimer_SetInterruptMode(PIDLoopTimer_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        PIDLoopTimer_WritePeriod(PIDLoopTimer_TC_PERIOD_VALUE );

        #if (PIDLoopTimer__COMPARE == PIDLoopTimer_TC_COMP_CAP_MODE)
            PIDLoopTimer_WriteCompare(PIDLoopTimer_TC_COMPARE_VALUE);

            #if (1u == PIDLoopTimer_TC_COMPARE_SWAP)
                PIDLoopTimer_SetCompareSwap(1u);
                PIDLoopTimer_WriteCompareBuf(PIDLoopTimer_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == PIDLoopTimer_TC_COMPARE_SWAP) */
        #endif  /* (PIDLoopTimer__COMPARE == PIDLoopTimer_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (PIDLoopTimer_CY_TCPWM_V2 && PIDLoopTimer_TIMER_UPDOWN_CNT_USED && !PIDLoopTimer_CY_TCPWM_4000)
            PIDLoopTimer_WriteCounter(1u);
        #elif(PIDLoopTimer__COUNT_DOWN == PIDLoopTimer_TC_COUNTER_MODE)
            PIDLoopTimer_WriteCounter(PIDLoopTimer_TC_PERIOD_VALUE);
        #else
            PIDLoopTimer_WriteCounter(0u);
        #endif /* (PIDLoopTimer_CY_TCPWM_V2 && PIDLoopTimer_TIMER_UPDOWN_CNT_USED && !PIDLoopTimer_CY_TCPWM_4000) */
    #endif  /* (PIDLoopTimer__TIMER == PIDLoopTimer_CONFIG) */

    #if (PIDLoopTimer__PWM_SEL == PIDLoopTimer_CONFIG)
        PIDLoopTimer_CONTROL_REG = PIDLoopTimer_CTRL_PWM_BASE_CONFIG;

        #if (PIDLoopTimer__PWM_PR == PIDLoopTimer_PWM_MODE)
            PIDLoopTimer_CONTROL_REG |= PIDLoopTimer_CTRL_PWM_RUN_MODE;
            PIDLoopTimer_WriteCounter(PIDLoopTimer_PWM_PR_INIT_VALUE);
        #else
            PIDLoopTimer_CONTROL_REG |= PIDLoopTimer_CTRL_PWM_ALIGN | PIDLoopTimer_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (PIDLoopTimer_CY_TCPWM_V2 && PIDLoopTimer_PWM_UPDOWN_CNT_USED && !PIDLoopTimer_CY_TCPWM_4000)
                PIDLoopTimer_WriteCounter(1u);
            #elif (PIDLoopTimer__RIGHT == PIDLoopTimer_PWM_ALIGN)
                PIDLoopTimer_WriteCounter(PIDLoopTimer_PWM_PERIOD_VALUE);
            #else 
                PIDLoopTimer_WriteCounter(0u);
            #endif  /* (PIDLoopTimer_CY_TCPWM_V2 && PIDLoopTimer_PWM_UPDOWN_CNT_USED && !PIDLoopTimer_CY_TCPWM_4000) */
        #endif  /* (PIDLoopTimer__PWM_PR == PIDLoopTimer_PWM_MODE) */

        #if (PIDLoopTimer__PWM_DT == PIDLoopTimer_PWM_MODE)
            PIDLoopTimer_CONTROL_REG |= PIDLoopTimer_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (PIDLoopTimer__PWM_DT == PIDLoopTimer_PWM_MODE) */

        #if (PIDLoopTimer__PWM == PIDLoopTimer_PWM_MODE)
            PIDLoopTimer_CONTROL_REG |= PIDLoopTimer_CTRL_PWM_PRESCALER;
        #endif  /* (PIDLoopTimer__PWM == PIDLoopTimer_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        PIDLoopTimer_TRIG_CONTROL1_REG  = PIDLoopTimer_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        PIDLoopTimer_SetInterruptMode(PIDLoopTimer_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (PIDLoopTimer__PWM_PR == PIDLoopTimer_PWM_MODE)
            PIDLoopTimer_TRIG_CONTROL2_REG =
                    (PIDLoopTimer_CC_MATCH_NO_CHANGE    |
                    PIDLoopTimer_OVERLOW_NO_CHANGE      |
                    PIDLoopTimer_UNDERFLOW_NO_CHANGE);
        #else
            #if (PIDLoopTimer__LEFT == PIDLoopTimer_PWM_ALIGN)
                PIDLoopTimer_TRIG_CONTROL2_REG = PIDLoopTimer_PWM_MODE_LEFT;
            #endif  /* ( PIDLoopTimer_PWM_LEFT == PIDLoopTimer_PWM_ALIGN) */

            #if (PIDLoopTimer__RIGHT == PIDLoopTimer_PWM_ALIGN)
                PIDLoopTimer_TRIG_CONTROL2_REG = PIDLoopTimer_PWM_MODE_RIGHT;
            #endif  /* ( PIDLoopTimer_PWM_RIGHT == PIDLoopTimer_PWM_ALIGN) */

            #if (PIDLoopTimer__CENTER == PIDLoopTimer_PWM_ALIGN)
                PIDLoopTimer_TRIG_CONTROL2_REG = PIDLoopTimer_PWM_MODE_CENTER;
            #endif  /* ( PIDLoopTimer_PWM_CENTER == PIDLoopTimer_PWM_ALIGN) */

            #if (PIDLoopTimer__ASYMMETRIC == PIDLoopTimer_PWM_ALIGN)
                PIDLoopTimer_TRIG_CONTROL2_REG = PIDLoopTimer_PWM_MODE_ASYM;
            #endif  /* (PIDLoopTimer__ASYMMETRIC == PIDLoopTimer_PWM_ALIGN) */
        #endif  /* (PIDLoopTimer__PWM_PR == PIDLoopTimer_PWM_MODE) */

        /* Set other values from customizer */
        PIDLoopTimer_WritePeriod(PIDLoopTimer_PWM_PERIOD_VALUE );
        PIDLoopTimer_WriteCompare(PIDLoopTimer_PWM_COMPARE_VALUE);

        #if (1u == PIDLoopTimer_PWM_COMPARE_SWAP)
            PIDLoopTimer_SetCompareSwap(1u);
            PIDLoopTimer_WriteCompareBuf(PIDLoopTimer_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == PIDLoopTimer_PWM_COMPARE_SWAP) */

        #if (1u == PIDLoopTimer_PWM_PERIOD_SWAP)
            PIDLoopTimer_SetPeriodSwap(1u);
            PIDLoopTimer_WritePeriodBuf(PIDLoopTimer_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == PIDLoopTimer_PWM_PERIOD_SWAP) */
    #endif  /* (PIDLoopTimer__PWM_SEL == PIDLoopTimer_CONFIG) */
    
}


/*******************************************************************************
* Function Name: PIDLoopTimer_Enable
********************************************************************************
*
* Summary:
*  Enables the PIDLoopTimer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    PIDLoopTimer_BLOCK_CONTROL_REG |= PIDLoopTimer_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (PIDLoopTimer__PWM_SEL == PIDLoopTimer_CONFIG)
        #if (0u == PIDLoopTimer_PWM_START_SIGNAL_PRESENT)
            PIDLoopTimer_TriggerCommand(PIDLoopTimer_MASK, PIDLoopTimer_CMD_START);
        #endif /* (0u == PIDLoopTimer_PWM_START_SIGNAL_PRESENT) */
    #endif /* (PIDLoopTimer__PWM_SEL == PIDLoopTimer_CONFIG) */

    #if (PIDLoopTimer__TIMER == PIDLoopTimer_CONFIG)
        #if (0u == PIDLoopTimer_TC_START_SIGNAL_PRESENT)
            PIDLoopTimer_TriggerCommand(PIDLoopTimer_MASK, PIDLoopTimer_CMD_START);
        #endif /* (0u == PIDLoopTimer_TC_START_SIGNAL_PRESENT) */
    #endif /* (PIDLoopTimer__TIMER == PIDLoopTimer_CONFIG) */
    
    #if (PIDLoopTimer__QUAD == PIDLoopTimer_CONFIG)
        #if (0u != PIDLoopTimer_QUAD_AUTO_START)
            PIDLoopTimer_TriggerCommand(PIDLoopTimer_MASK, PIDLoopTimer_CMD_RELOAD);
        #endif /* (0u != PIDLoopTimer_QUAD_AUTO_START) */
    #endif  /* (PIDLoopTimer__QUAD == PIDLoopTimer_CONFIG) */
}


/*******************************************************************************
* Function Name: PIDLoopTimer_Start
********************************************************************************
*
* Summary:
*  Initializes the PIDLoopTimer with default customizer
*  values when called the first time and enables the PIDLoopTimer.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PIDLoopTimer_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time PIDLoopTimer_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the PIDLoopTimer_Start() routine.
*
*******************************************************************************/
void PIDLoopTimer_Start(void)
{
    if (0u == PIDLoopTimer_initVar)
    {
        PIDLoopTimer_Init();
        PIDLoopTimer_initVar = 1u;
    }

    PIDLoopTimer_Enable();
}


/*******************************************************************************
* Function Name: PIDLoopTimer_Stop
********************************************************************************
*
* Summary:
*  Disables the PIDLoopTimer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_BLOCK_CONTROL_REG &= (uint32)~PIDLoopTimer_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the PIDLoopTimer. This function is used when
*  configured as a generic PIDLoopTimer and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the PIDLoopTimer to operate in
*   Values:
*   - PIDLoopTimer_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - PIDLoopTimer_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - PIDLoopTimer_MODE_QUAD - Quadrature decoder
*         - PIDLoopTimer_MODE_PWM - PWM
*         - PIDLoopTimer_MODE_PWM_DT - PWM with dead time
*         - PIDLoopTimer_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_MODE_MASK;
    PIDLoopTimer_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - PIDLoopTimer_MODE_X1 - Counts on phi 1 rising
*         - PIDLoopTimer_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - PIDLoopTimer_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_QUAD_MODE_MASK;
    PIDLoopTimer_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - PIDLoopTimer_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - PIDLoopTimer_PRESCALE_DIVBY2    - Divide by 2
*         - PIDLoopTimer_PRESCALE_DIVBY4    - Divide by 4
*         - PIDLoopTimer_PRESCALE_DIVBY8    - Divide by 8
*         - PIDLoopTimer_PRESCALE_DIVBY16   - Divide by 16
*         - PIDLoopTimer_PRESCALE_DIVBY32   - Divide by 32
*         - PIDLoopTimer_PRESCALE_DIVBY64   - Divide by 64
*         - PIDLoopTimer_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_PRESCALER_MASK;
    PIDLoopTimer_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PIDLoopTimer runs
*  continuously or stops when terminal count is reached.  By default the
*  PIDLoopTimer operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_ONESHOT_MASK;
    PIDLoopTimer_CONTROL_REG |= ((uint32)((oneShotEnable & PIDLoopTimer_1BIT_MASK) <<
                                                               PIDLoopTimer_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetPWMMode(uint32 modeMask)
{
    PIDLoopTimer_TRIG_CONTROL2_REG = (modeMask & PIDLoopTimer_6BIT_MASK);
}



/*******************************************************************************
* Function Name: PIDLoopTimer_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_PWM_SYNC_KILL_MASK;
    PIDLoopTimer_CONTROL_REG |= ((uint32)((syncKillEnable & PIDLoopTimer_1BIT_MASK)  <<
                                               PIDLoopTimer_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_PWM_STOP_KILL_MASK;
    PIDLoopTimer_CONTROL_REG |= ((uint32)((stopOnKillEnable & PIDLoopTimer_1BIT_MASK)  <<
                                                         PIDLoopTimer_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_PRESCALER_MASK;
    PIDLoopTimer_CONTROL_REG |= ((uint32)((deadTime & PIDLoopTimer_8BIT_MASK) <<
                                                          PIDLoopTimer_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - PIDLoopTimer_INVERT_LINE   - Inverts the line output
*         - PIDLoopTimer_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_INV_OUT_MASK;
    PIDLoopTimer_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: PIDLoopTimer_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_WriteCounter(uint32 count)
{
    PIDLoopTimer_COUNTER_REG = (count & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 PIDLoopTimer_ReadCounter(void)
{
    return (PIDLoopTimer_COUNTER_REG & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - PIDLoopTimer_COUNT_UP       - Counts up
*     - PIDLoopTimer_COUNT_DOWN     - Counts down
*     - PIDLoopTimer_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - PIDLoopTimer_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_UPDOWN_MASK;
    PIDLoopTimer_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_WritePeriod(uint32 period)
{
    PIDLoopTimer_PERIOD_REG = (period & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 PIDLoopTimer_ReadPeriod(void)
{
    return (PIDLoopTimer_PERIOD_REG & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_RELOAD_CC_MASK;
    PIDLoopTimer_CONTROL_REG |= (swapEnable & PIDLoopTimer_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_WritePeriodBuf(uint32 periodBuf)
{
    PIDLoopTimer_PERIOD_BUF_REG = (periodBuf & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 PIDLoopTimer_ReadPeriodBuf(void)
{
    return (PIDLoopTimer_PERIOD_BUF_REG & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_CONTROL_REG &= (uint32)~PIDLoopTimer_RELOAD_PERIOD_MASK;
    PIDLoopTimer_CONTROL_REG |= ((uint32)((swapEnable & PIDLoopTimer_1BIT_MASK) <<
                                                            PIDLoopTimer_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void PIDLoopTimer_WriteCompare(uint32 compare)
{
    #if (PIDLoopTimer_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (PIDLoopTimer_CY_TCPWM_4000) */

    #if (PIDLoopTimer_CY_TCPWM_4000)
        currentMode = ((PIDLoopTimer_CONTROL_REG & PIDLoopTimer_UPDOWN_MASK) >> PIDLoopTimer_UPDOWN_SHIFT);

        if (((uint32)PIDLoopTimer__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)PIDLoopTimer__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (PIDLoopTimer_CY_TCPWM_4000) */
    
    PIDLoopTimer_COMP_CAP_REG = (compare & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 PIDLoopTimer_ReadCompare(void)
{
    #if (PIDLoopTimer_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (PIDLoopTimer_CY_TCPWM_4000) */

    #if (PIDLoopTimer_CY_TCPWM_4000)
        currentMode = ((PIDLoopTimer_CONTROL_REG & PIDLoopTimer_UPDOWN_MASK) >> PIDLoopTimer_UPDOWN_SHIFT);
        
        regVal = PIDLoopTimer_COMP_CAP_REG;
        
        if (((uint32)PIDLoopTimer__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)PIDLoopTimer__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & PIDLoopTimer_16BIT_MASK);
    #else
        return (PIDLoopTimer_COMP_CAP_REG & PIDLoopTimer_16BIT_MASK);
    #endif /* (PIDLoopTimer_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: PIDLoopTimer_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void PIDLoopTimer_WriteCompareBuf(uint32 compareBuf)
{
    #if (PIDLoopTimer_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (PIDLoopTimer_CY_TCPWM_4000) */

    #if (PIDLoopTimer_CY_TCPWM_4000)
        currentMode = ((PIDLoopTimer_CONTROL_REG & PIDLoopTimer_UPDOWN_MASK) >> PIDLoopTimer_UPDOWN_SHIFT);

        if (((uint32)PIDLoopTimer__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)PIDLoopTimer__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (PIDLoopTimer_CY_TCPWM_4000) */
    
    PIDLoopTimer_COMP_CAP_BUF_REG = (compareBuf & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 PIDLoopTimer_ReadCompareBuf(void)
{
    #if (PIDLoopTimer_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (PIDLoopTimer_CY_TCPWM_4000) */

    #if (PIDLoopTimer_CY_TCPWM_4000)
        currentMode = ((PIDLoopTimer_CONTROL_REG & PIDLoopTimer_UPDOWN_MASK) >> PIDLoopTimer_UPDOWN_SHIFT);

        regVal = PIDLoopTimer_COMP_CAP_BUF_REG;
        
        if (((uint32)PIDLoopTimer__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)PIDLoopTimer__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & PIDLoopTimer_16BIT_MASK);
    #else
        return (PIDLoopTimer_COMP_CAP_BUF_REG & PIDLoopTimer_16BIT_MASK);
    #endif /* (PIDLoopTimer_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: PIDLoopTimer_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 PIDLoopTimer_ReadCapture(void)
{
    return (PIDLoopTimer_COMP_CAP_REG & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 PIDLoopTimer_ReadCaptureBuf(void)
{
    return (PIDLoopTimer_COMP_CAP_BUF_REG & PIDLoopTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PIDLoopTimer_TRIG_LEVEL     - Level
*     - PIDLoopTimer_TRIG_RISING    - Rising edge
*     - PIDLoopTimer_TRIG_FALLING   - Falling edge
*     - PIDLoopTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_TRIG_CONTROL1_REG &= (uint32)~PIDLoopTimer_CAPTURE_MASK;
    PIDLoopTimer_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PIDLoopTimer_TRIG_LEVEL     - Level
*     - PIDLoopTimer_TRIG_RISING    - Rising edge
*     - PIDLoopTimer_TRIG_FALLING   - Falling edge
*     - PIDLoopTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_TRIG_CONTROL1_REG &= (uint32)~PIDLoopTimer_RELOAD_MASK;
    PIDLoopTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PIDLoopTimer_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PIDLoopTimer_TRIG_LEVEL     - Level
*     - PIDLoopTimer_TRIG_RISING    - Rising edge
*     - PIDLoopTimer_TRIG_FALLING   - Falling edge
*     - PIDLoopTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_TRIG_CONTROL1_REG &= (uint32)~PIDLoopTimer_START_MASK;
    PIDLoopTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PIDLoopTimer_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PIDLoopTimer_TRIG_LEVEL     - Level
*     - PIDLoopTimer_TRIG_RISING    - Rising edge
*     - PIDLoopTimer_TRIG_FALLING   - Falling edge
*     - PIDLoopTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_TRIG_CONTROL1_REG &= (uint32)~PIDLoopTimer_STOP_MASK;
    PIDLoopTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PIDLoopTimer_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PIDLoopTimer_TRIG_LEVEL     - Level
*     - PIDLoopTimer_TRIG_RISING    - Rising edge
*     - PIDLoopTimer_TRIG_FALLING   - Falling edge
*     - PIDLoopTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_TRIG_CONTROL1_REG &= (uint32)~PIDLoopTimer_COUNT_MASK;
    PIDLoopTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PIDLoopTimer_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - PIDLoopTimer_CMD_CAPTURE    - Trigger Capture/Switch command
*     - PIDLoopTimer_CMD_RELOAD     - Trigger Reload/Index command
*     - PIDLoopTimer_CMD_STOP       - Trigger Stop/Kill command
*     - PIDLoopTimer_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDLoopTimer_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the PIDLoopTimer.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - PIDLoopTimer_STATUS_DOWN    - Set if counting down
*     - PIDLoopTimer_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 PIDLoopTimer_ReadStatus(void)
{
    return ((PIDLoopTimer_STATUS_REG >> PIDLoopTimer_RUNNING_STATUS_SHIFT) |
            (PIDLoopTimer_STATUS_REG & PIDLoopTimer_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - PIDLoopTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDLoopTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetInterruptMode(uint32 interruptMask)
{
    PIDLoopTimer_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: PIDLoopTimer_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - PIDLoopTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDLoopTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PIDLoopTimer_GetInterruptSourceMasked(void)
{
    return (PIDLoopTimer_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - PIDLoopTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDLoopTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PIDLoopTimer_GetInterruptSource(void)
{
    return (PIDLoopTimer_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: PIDLoopTimer_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - PIDLoopTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDLoopTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_ClearInterrupt(uint32 interruptMask)
{
    PIDLoopTimer_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: PIDLoopTimer_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - PIDLoopTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDLoopTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PIDLoopTimer_SetInterrupt(uint32 interruptMask)
{
    PIDLoopTimer_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
