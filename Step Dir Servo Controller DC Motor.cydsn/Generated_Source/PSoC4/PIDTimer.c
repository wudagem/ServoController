/*******************************************************************************
* File Name: PIDTimer.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the PIDTimer
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

#include "PIDTimer.h"

uint8 PIDTimer_initVar = 0u;


/*******************************************************************************
* Function Name: PIDTimer_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default PIDTimer configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (PIDTimer__QUAD == PIDTimer_CONFIG)
        PIDTimer_CONTROL_REG = PIDTimer_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        PIDTimer_TRIG_CONTROL1_REG  = PIDTimer_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        PIDTimer_SetInterruptMode(PIDTimer_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        PIDTimer_SetCounterMode(PIDTimer_COUNT_DOWN);
        PIDTimer_WritePeriod(PIDTimer_QUAD_PERIOD_INIT_VALUE);
        PIDTimer_WriteCounter(PIDTimer_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (PIDTimer__QUAD == PIDTimer_CONFIG) */

    #if (PIDTimer__TIMER == PIDTimer_CONFIG)
        PIDTimer_CONTROL_REG = PIDTimer_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        PIDTimer_TRIG_CONTROL1_REG  = PIDTimer_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        PIDTimer_SetInterruptMode(PIDTimer_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        PIDTimer_WritePeriod(PIDTimer_TC_PERIOD_VALUE );

        #if (PIDTimer__COMPARE == PIDTimer_TC_COMP_CAP_MODE)
            PIDTimer_WriteCompare(PIDTimer_TC_COMPARE_VALUE);

            #if (1u == PIDTimer_TC_COMPARE_SWAP)
                PIDTimer_SetCompareSwap(1u);
                PIDTimer_WriteCompareBuf(PIDTimer_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == PIDTimer_TC_COMPARE_SWAP) */
        #endif  /* (PIDTimer__COMPARE == PIDTimer_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (PIDTimer_CY_TCPWM_V2 && PIDTimer_TIMER_UPDOWN_CNT_USED && !PIDTimer_CY_TCPWM_4000)
            PIDTimer_WriteCounter(1u);
        #elif(PIDTimer__COUNT_DOWN == PIDTimer_TC_COUNTER_MODE)
            PIDTimer_WriteCounter(PIDTimer_TC_PERIOD_VALUE);
        #else
            PIDTimer_WriteCounter(0u);
        #endif /* (PIDTimer_CY_TCPWM_V2 && PIDTimer_TIMER_UPDOWN_CNT_USED && !PIDTimer_CY_TCPWM_4000) */
    #endif  /* (PIDTimer__TIMER == PIDTimer_CONFIG) */

    #if (PIDTimer__PWM_SEL == PIDTimer_CONFIG)
        PIDTimer_CONTROL_REG = PIDTimer_CTRL_PWM_BASE_CONFIG;

        #if (PIDTimer__PWM_PR == PIDTimer_PWM_MODE)
            PIDTimer_CONTROL_REG |= PIDTimer_CTRL_PWM_RUN_MODE;
            PIDTimer_WriteCounter(PIDTimer_PWM_PR_INIT_VALUE);
        #else
            PIDTimer_CONTROL_REG |= PIDTimer_CTRL_PWM_ALIGN | PIDTimer_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (PIDTimer_CY_TCPWM_V2 && PIDTimer_PWM_UPDOWN_CNT_USED && !PIDTimer_CY_TCPWM_4000)
                PIDTimer_WriteCounter(1u);
            #elif (PIDTimer__RIGHT == PIDTimer_PWM_ALIGN)
                PIDTimer_WriteCounter(PIDTimer_PWM_PERIOD_VALUE);
            #else 
                PIDTimer_WriteCounter(0u);
            #endif  /* (PIDTimer_CY_TCPWM_V2 && PIDTimer_PWM_UPDOWN_CNT_USED && !PIDTimer_CY_TCPWM_4000) */
        #endif  /* (PIDTimer__PWM_PR == PIDTimer_PWM_MODE) */

        #if (PIDTimer__PWM_DT == PIDTimer_PWM_MODE)
            PIDTimer_CONTROL_REG |= PIDTimer_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (PIDTimer__PWM_DT == PIDTimer_PWM_MODE) */

        #if (PIDTimer__PWM == PIDTimer_PWM_MODE)
            PIDTimer_CONTROL_REG |= PIDTimer_CTRL_PWM_PRESCALER;
        #endif  /* (PIDTimer__PWM == PIDTimer_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        PIDTimer_TRIG_CONTROL1_REG  = PIDTimer_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        PIDTimer_SetInterruptMode(PIDTimer_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (PIDTimer__PWM_PR == PIDTimer_PWM_MODE)
            PIDTimer_TRIG_CONTROL2_REG =
                    (PIDTimer_CC_MATCH_NO_CHANGE    |
                    PIDTimer_OVERLOW_NO_CHANGE      |
                    PIDTimer_UNDERFLOW_NO_CHANGE);
        #else
            #if (PIDTimer__LEFT == PIDTimer_PWM_ALIGN)
                PIDTimer_TRIG_CONTROL2_REG = PIDTimer_PWM_MODE_LEFT;
            #endif  /* ( PIDTimer_PWM_LEFT == PIDTimer_PWM_ALIGN) */

            #if (PIDTimer__RIGHT == PIDTimer_PWM_ALIGN)
                PIDTimer_TRIG_CONTROL2_REG = PIDTimer_PWM_MODE_RIGHT;
            #endif  /* ( PIDTimer_PWM_RIGHT == PIDTimer_PWM_ALIGN) */

            #if (PIDTimer__CENTER == PIDTimer_PWM_ALIGN)
                PIDTimer_TRIG_CONTROL2_REG = PIDTimer_PWM_MODE_CENTER;
            #endif  /* ( PIDTimer_PWM_CENTER == PIDTimer_PWM_ALIGN) */

            #if (PIDTimer__ASYMMETRIC == PIDTimer_PWM_ALIGN)
                PIDTimer_TRIG_CONTROL2_REG = PIDTimer_PWM_MODE_ASYM;
            #endif  /* (PIDTimer__ASYMMETRIC == PIDTimer_PWM_ALIGN) */
        #endif  /* (PIDTimer__PWM_PR == PIDTimer_PWM_MODE) */

        /* Set other values from customizer */
        PIDTimer_WritePeriod(PIDTimer_PWM_PERIOD_VALUE );
        PIDTimer_WriteCompare(PIDTimer_PWM_COMPARE_VALUE);

        #if (1u == PIDTimer_PWM_COMPARE_SWAP)
            PIDTimer_SetCompareSwap(1u);
            PIDTimer_WriteCompareBuf(PIDTimer_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == PIDTimer_PWM_COMPARE_SWAP) */

        #if (1u == PIDTimer_PWM_PERIOD_SWAP)
            PIDTimer_SetPeriodSwap(1u);
            PIDTimer_WritePeriodBuf(PIDTimer_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == PIDTimer_PWM_PERIOD_SWAP) */
    #endif  /* (PIDTimer__PWM_SEL == PIDTimer_CONFIG) */
    
}


/*******************************************************************************
* Function Name: PIDTimer_Enable
********************************************************************************
*
* Summary:
*  Enables the PIDTimer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    PIDTimer_BLOCK_CONTROL_REG |= PIDTimer_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (PIDTimer__PWM_SEL == PIDTimer_CONFIG)
        #if (0u == PIDTimer_PWM_START_SIGNAL_PRESENT)
            PIDTimer_TriggerCommand(PIDTimer_MASK, PIDTimer_CMD_START);
        #endif /* (0u == PIDTimer_PWM_START_SIGNAL_PRESENT) */
    #endif /* (PIDTimer__PWM_SEL == PIDTimer_CONFIG) */

    #if (PIDTimer__TIMER == PIDTimer_CONFIG)
        #if (0u == PIDTimer_TC_START_SIGNAL_PRESENT)
            PIDTimer_TriggerCommand(PIDTimer_MASK, PIDTimer_CMD_START);
        #endif /* (0u == PIDTimer_TC_START_SIGNAL_PRESENT) */
    #endif /* (PIDTimer__TIMER == PIDTimer_CONFIG) */
    
    #if (PIDTimer__QUAD == PIDTimer_CONFIG)
        #if (0u != PIDTimer_QUAD_AUTO_START)
            PIDTimer_TriggerCommand(PIDTimer_MASK, PIDTimer_CMD_RELOAD);
        #endif /* (0u != PIDTimer_QUAD_AUTO_START) */
    #endif  /* (PIDTimer__QUAD == PIDTimer_CONFIG) */
}


/*******************************************************************************
* Function Name: PIDTimer_Start
********************************************************************************
*
* Summary:
*  Initializes the PIDTimer with default customizer
*  values when called the first time and enables the PIDTimer.
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
*  PIDTimer_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time PIDTimer_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the PIDTimer_Start() routine.
*
*******************************************************************************/
void PIDTimer_Start(void)
{
    if (0u == PIDTimer_initVar)
    {
        PIDTimer_Init();
        PIDTimer_initVar = 1u;
    }

    PIDTimer_Enable();
}


/*******************************************************************************
* Function Name: PIDTimer_Stop
********************************************************************************
*
* Summary:
*  Disables the PIDTimer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_BLOCK_CONTROL_REG &= (uint32)~PIDTimer_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the PIDTimer. This function is used when
*  configured as a generic PIDTimer and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the PIDTimer to operate in
*   Values:
*   - PIDTimer_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - PIDTimer_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - PIDTimer_MODE_QUAD - Quadrature decoder
*         - PIDTimer_MODE_PWM - PWM
*         - PIDTimer_MODE_PWM_DT - PWM with dead time
*         - PIDTimer_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_MODE_MASK;
    PIDTimer_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - PIDTimer_MODE_X1 - Counts on phi 1 rising
*         - PIDTimer_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - PIDTimer_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_QUAD_MODE_MASK;
    PIDTimer_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - PIDTimer_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - PIDTimer_PRESCALE_DIVBY2    - Divide by 2
*         - PIDTimer_PRESCALE_DIVBY4    - Divide by 4
*         - PIDTimer_PRESCALE_DIVBY8    - Divide by 8
*         - PIDTimer_PRESCALE_DIVBY16   - Divide by 16
*         - PIDTimer_PRESCALE_DIVBY32   - Divide by 32
*         - PIDTimer_PRESCALE_DIVBY64   - Divide by 64
*         - PIDTimer_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_PRESCALER_MASK;
    PIDTimer_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PIDTimer runs
*  continuously or stops when terminal count is reached.  By default the
*  PIDTimer operates in the continuous mode.
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
void PIDTimer_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_ONESHOT_MASK;
    PIDTimer_CONTROL_REG |= ((uint32)((oneShotEnable & PIDTimer_1BIT_MASK) <<
                                                               PIDTimer_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetPWMMode
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
void PIDTimer_SetPWMMode(uint32 modeMask)
{
    PIDTimer_TRIG_CONTROL2_REG = (modeMask & PIDTimer_6BIT_MASK);
}



/*******************************************************************************
* Function Name: PIDTimer_SetPWMSyncKill
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
void PIDTimer_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_PWM_SYNC_KILL_MASK;
    PIDTimer_CONTROL_REG |= ((uint32)((syncKillEnable & PIDTimer_1BIT_MASK)  <<
                                               PIDTimer_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetPWMStopOnKill
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
void PIDTimer_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_PWM_STOP_KILL_MASK;
    PIDTimer_CONTROL_REG |= ((uint32)((stopOnKillEnable & PIDTimer_1BIT_MASK)  <<
                                                         PIDTimer_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetPWMDeadTime
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
void PIDTimer_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_PRESCALER_MASK;
    PIDTimer_CONTROL_REG |= ((uint32)((deadTime & PIDTimer_8BIT_MASK) <<
                                                          PIDTimer_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetPWMInvert
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
*         - PIDTimer_INVERT_LINE   - Inverts the line output
*         - PIDTimer_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_INV_OUT_MASK;
    PIDTimer_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: PIDTimer_WriteCounter
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
void PIDTimer_WriteCounter(uint32 count)
{
    PIDTimer_COUNTER_REG = (count & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_ReadCounter
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
uint32 PIDTimer_ReadCounter(void)
{
    return (PIDTimer_COUNTER_REG & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - PIDTimer_COUNT_UP       - Counts up
*     - PIDTimer_COUNT_DOWN     - Counts down
*     - PIDTimer_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - PIDTimer_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_UPDOWN_MASK;
    PIDTimer_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_WritePeriod
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
void PIDTimer_WritePeriod(uint32 period)
{
    PIDTimer_PERIOD_REG = (period & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_ReadPeriod
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
uint32 PIDTimer_ReadPeriod(void)
{
    return (PIDTimer_PERIOD_REG & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_SetCompareSwap
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
void PIDTimer_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_RELOAD_CC_MASK;
    PIDTimer_CONTROL_REG |= (swapEnable & PIDTimer_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_WritePeriodBuf
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
void PIDTimer_WritePeriodBuf(uint32 periodBuf)
{
    PIDTimer_PERIOD_BUF_REG = (periodBuf & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_ReadPeriodBuf
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
uint32 PIDTimer_ReadPeriodBuf(void)
{
    return (PIDTimer_PERIOD_BUF_REG & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_SetPeriodSwap
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
void PIDTimer_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_CONTROL_REG &= (uint32)~PIDTimer_RELOAD_PERIOD_MASK;
    PIDTimer_CONTROL_REG |= ((uint32)((swapEnable & PIDTimer_1BIT_MASK) <<
                                                            PIDTimer_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_WriteCompare
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
void PIDTimer_WriteCompare(uint32 compare)
{
    #if (PIDTimer_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (PIDTimer_CY_TCPWM_4000) */

    #if (PIDTimer_CY_TCPWM_4000)
        currentMode = ((PIDTimer_CONTROL_REG & PIDTimer_UPDOWN_MASK) >> PIDTimer_UPDOWN_SHIFT);

        if (((uint32)PIDTimer__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)PIDTimer__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (PIDTimer_CY_TCPWM_4000) */
    
    PIDTimer_COMP_CAP_REG = (compare & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_ReadCompare
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
uint32 PIDTimer_ReadCompare(void)
{
    #if (PIDTimer_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (PIDTimer_CY_TCPWM_4000) */

    #if (PIDTimer_CY_TCPWM_4000)
        currentMode = ((PIDTimer_CONTROL_REG & PIDTimer_UPDOWN_MASK) >> PIDTimer_UPDOWN_SHIFT);
        
        regVal = PIDTimer_COMP_CAP_REG;
        
        if (((uint32)PIDTimer__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)PIDTimer__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & PIDTimer_16BIT_MASK);
    #else
        return (PIDTimer_COMP_CAP_REG & PIDTimer_16BIT_MASK);
    #endif /* (PIDTimer_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: PIDTimer_WriteCompareBuf
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
void PIDTimer_WriteCompareBuf(uint32 compareBuf)
{
    #if (PIDTimer_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (PIDTimer_CY_TCPWM_4000) */

    #if (PIDTimer_CY_TCPWM_4000)
        currentMode = ((PIDTimer_CONTROL_REG & PIDTimer_UPDOWN_MASK) >> PIDTimer_UPDOWN_SHIFT);

        if (((uint32)PIDTimer__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)PIDTimer__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (PIDTimer_CY_TCPWM_4000) */
    
    PIDTimer_COMP_CAP_BUF_REG = (compareBuf & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_ReadCompareBuf
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
uint32 PIDTimer_ReadCompareBuf(void)
{
    #if (PIDTimer_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (PIDTimer_CY_TCPWM_4000) */

    #if (PIDTimer_CY_TCPWM_4000)
        currentMode = ((PIDTimer_CONTROL_REG & PIDTimer_UPDOWN_MASK) >> PIDTimer_UPDOWN_SHIFT);

        regVal = PIDTimer_COMP_CAP_BUF_REG;
        
        if (((uint32)PIDTimer__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)PIDTimer__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & PIDTimer_16BIT_MASK);
    #else
        return (PIDTimer_COMP_CAP_BUF_REG & PIDTimer_16BIT_MASK);
    #endif /* (PIDTimer_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: PIDTimer_ReadCapture
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
uint32 PIDTimer_ReadCapture(void)
{
    return (PIDTimer_COMP_CAP_REG & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_ReadCaptureBuf
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
uint32 PIDTimer_ReadCaptureBuf(void)
{
    return (PIDTimer_COMP_CAP_BUF_REG & PIDTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: PIDTimer_SetCaptureMode
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
*     - PIDTimer_TRIG_LEVEL     - Level
*     - PIDTimer_TRIG_RISING    - Rising edge
*     - PIDTimer_TRIG_FALLING   - Falling edge
*     - PIDTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_TRIG_CONTROL1_REG &= (uint32)~PIDTimer_CAPTURE_MASK;
    PIDTimer_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PIDTimer_TRIG_LEVEL     - Level
*     - PIDTimer_TRIG_RISING    - Rising edge
*     - PIDTimer_TRIG_FALLING   - Falling edge
*     - PIDTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_TRIG_CONTROL1_REG &= (uint32)~PIDTimer_RELOAD_MASK;
    PIDTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PIDTimer_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PIDTimer_TRIG_LEVEL     - Level
*     - PIDTimer_TRIG_RISING    - Rising edge
*     - PIDTimer_TRIG_FALLING   - Falling edge
*     - PIDTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_TRIG_CONTROL1_REG &= (uint32)~PIDTimer_START_MASK;
    PIDTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PIDTimer_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PIDTimer_TRIG_LEVEL     - Level
*     - PIDTimer_TRIG_RISING    - Rising edge
*     - PIDTimer_TRIG_FALLING   - Falling edge
*     - PIDTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_TRIG_CONTROL1_REG &= (uint32)~PIDTimer_STOP_MASK;
    PIDTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PIDTimer_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - PIDTimer_TRIG_LEVEL     - Level
*     - PIDTimer_TRIG_RISING    - Rising edge
*     - PIDTimer_TRIG_FALLING   - Falling edge
*     - PIDTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_TRIG_CONTROL1_REG &= (uint32)~PIDTimer_COUNT_MASK;
    PIDTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << PIDTimer_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_TriggerCommand
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
*     - PIDTimer_CMD_CAPTURE    - Trigger Capture/Switch command
*     - PIDTimer_CMD_RELOAD     - Trigger Reload/Index command
*     - PIDTimer_CMD_STOP       - Trigger Stop/Kill command
*     - PIDTimer_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    PIDTimer_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: PIDTimer_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the PIDTimer.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - PIDTimer_STATUS_DOWN    - Set if counting down
*     - PIDTimer_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 PIDTimer_ReadStatus(void)
{
    return ((PIDTimer_STATUS_REG >> PIDTimer_RUNNING_STATUS_SHIFT) |
            (PIDTimer_STATUS_REG & PIDTimer_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: PIDTimer_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - PIDTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetInterruptMode(uint32 interruptMask)
{
    PIDTimer_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: PIDTimer_GetInterruptSourceMasked
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
*     - PIDTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PIDTimer_GetInterruptSourceMasked(void)
{
    return (PIDTimer_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: PIDTimer_GetInterruptSource
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
*     - PIDTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 PIDTimer_GetInterruptSource(void)
{
    return (PIDTimer_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: PIDTimer_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - PIDTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_ClearInterrupt(uint32 interruptMask)
{
    PIDTimer_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: PIDTimer_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - PIDTimer_INTR_MASK_TC       - Terminal count mask
*     - PIDTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void PIDTimer_SetInterrupt(uint32 interruptMask)
{
    PIDTimer_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
