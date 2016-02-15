/*******************************************************************************
* File Name: SerialDataTimer.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the SerialDataTimer
*  component.
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

#if !defined(CY_TCPWM_SerialDataTimer_H)
#define CY_TCPWM_SerialDataTimer_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} SerialDataTimer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  SerialDataTimer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define SerialDataTimer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define SerialDataTimer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define SerialDataTimer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define SerialDataTimer_QUAD_ENCODING_MODES            (0lu)
#define SerialDataTimer_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define SerialDataTimer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define SerialDataTimer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define SerialDataTimer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define SerialDataTimer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define SerialDataTimer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define SerialDataTimer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define SerialDataTimer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define SerialDataTimer_TC_RUN_MODE                    (0lu)
#define SerialDataTimer_TC_COUNTER_MODE                (0lu)
#define SerialDataTimer_TC_COMP_CAP_MODE               (2lu)
#define SerialDataTimer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define SerialDataTimer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define SerialDataTimer_TC_COUNT_SIGNAL_MODE           (3lu)
#define SerialDataTimer_TC_START_SIGNAL_MODE           (0lu)
#define SerialDataTimer_TC_STOP_SIGNAL_MODE            (0lu)
#define SerialDataTimer_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define SerialDataTimer_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define SerialDataTimer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define SerialDataTimer_TC_START_SIGNAL_PRESENT        (0lu)
#define SerialDataTimer_TC_STOP_SIGNAL_PRESENT         (0lu)
#define SerialDataTimer_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define SerialDataTimer_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define SerialDataTimer_PWM_KILL_EVENT                 (0lu)
#define SerialDataTimer_PWM_STOP_EVENT                 (0lu)
#define SerialDataTimer_PWM_MODE                       (4lu)
#define SerialDataTimer_PWM_OUT_N_INVERT               (0lu)
#define SerialDataTimer_PWM_OUT_INVERT                 (0lu)
#define SerialDataTimer_PWM_ALIGN                      (0lu)
#define SerialDataTimer_PWM_RUN_MODE                   (0lu)
#define SerialDataTimer_PWM_DEAD_TIME_CYCLE            (0lu)
#define SerialDataTimer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define SerialDataTimer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define SerialDataTimer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define SerialDataTimer_PWM_START_SIGNAL_MODE          (0lu)
#define SerialDataTimer_PWM_STOP_SIGNAL_MODE           (0lu)
#define SerialDataTimer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define SerialDataTimer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define SerialDataTimer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define SerialDataTimer_PWM_START_SIGNAL_PRESENT       (0lu)
#define SerialDataTimer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define SerialDataTimer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define SerialDataTimer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define SerialDataTimer_TC_PERIOD_VALUE                (5lu)
#define SerialDataTimer_TC_COMPARE_VALUE               (65535lu)
#define SerialDataTimer_TC_COMPARE_BUF_VALUE           (65535lu)
#define SerialDataTimer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define SerialDataTimer_PWM_PERIOD_VALUE               (65535lu)
#define SerialDataTimer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define SerialDataTimer_PWM_PERIOD_SWAP                (0lu)
#define SerialDataTimer_PWM_COMPARE_VALUE              (65535lu)
#define SerialDataTimer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define SerialDataTimer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define SerialDataTimer__LEFT 0
#define SerialDataTimer__RIGHT 1
#define SerialDataTimer__CENTER 2
#define SerialDataTimer__ASYMMETRIC 3

#define SerialDataTimer__X1 0
#define SerialDataTimer__X2 1
#define SerialDataTimer__X4 2

#define SerialDataTimer__PWM 4
#define SerialDataTimer__PWM_DT 5
#define SerialDataTimer__PWM_PR 6

#define SerialDataTimer__INVERSE 1
#define SerialDataTimer__DIRECT 0

#define SerialDataTimer__CAPTURE 2
#define SerialDataTimer__COMPARE 0

#define SerialDataTimer__TRIG_LEVEL 3
#define SerialDataTimer__TRIG_RISING 0
#define SerialDataTimer__TRIG_FALLING 1
#define SerialDataTimer__TRIG_BOTH 2

#define SerialDataTimer__INTR_MASK_TC 1
#define SerialDataTimer__INTR_MASK_CC_MATCH 2
#define SerialDataTimer__INTR_MASK_NONE 0
#define SerialDataTimer__INTR_MASK_TC_CC 3

#define SerialDataTimer__UNCONFIG 8
#define SerialDataTimer__TIMER 1
#define SerialDataTimer__QUAD 3
#define SerialDataTimer__PWM_SEL 7

#define SerialDataTimer__COUNT_UP 0
#define SerialDataTimer__COUNT_DOWN 1
#define SerialDataTimer__COUNT_UPDOWN0 2
#define SerialDataTimer__COUNT_UPDOWN1 3


/* Prescaler */
#define SerialDataTimer_PRESCALE_DIVBY1                ((uint32)(0u << SerialDataTimer_PRESCALER_SHIFT))
#define SerialDataTimer_PRESCALE_DIVBY2                ((uint32)(1u << SerialDataTimer_PRESCALER_SHIFT))
#define SerialDataTimer_PRESCALE_DIVBY4                ((uint32)(2u << SerialDataTimer_PRESCALER_SHIFT))
#define SerialDataTimer_PRESCALE_DIVBY8                ((uint32)(3u << SerialDataTimer_PRESCALER_SHIFT))
#define SerialDataTimer_PRESCALE_DIVBY16               ((uint32)(4u << SerialDataTimer_PRESCALER_SHIFT))
#define SerialDataTimer_PRESCALE_DIVBY32               ((uint32)(5u << SerialDataTimer_PRESCALER_SHIFT))
#define SerialDataTimer_PRESCALE_DIVBY64               ((uint32)(6u << SerialDataTimer_PRESCALER_SHIFT))
#define SerialDataTimer_PRESCALE_DIVBY128              ((uint32)(7u << SerialDataTimer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define SerialDataTimer_MODE_TIMER_COMPARE             ((uint32)(SerialDataTimer__COMPARE         <<  \
                                                                  SerialDataTimer_MODE_SHIFT))
#define SerialDataTimer_MODE_TIMER_CAPTURE             ((uint32)(SerialDataTimer__CAPTURE         <<  \
                                                                  SerialDataTimer_MODE_SHIFT))
#define SerialDataTimer_MODE_QUAD                      ((uint32)(SerialDataTimer__QUAD            <<  \
                                                                  SerialDataTimer_MODE_SHIFT))
#define SerialDataTimer_MODE_PWM                       ((uint32)(SerialDataTimer__PWM             <<  \
                                                                  SerialDataTimer_MODE_SHIFT))
#define SerialDataTimer_MODE_PWM_DT                    ((uint32)(SerialDataTimer__PWM_DT          <<  \
                                                                  SerialDataTimer_MODE_SHIFT))
#define SerialDataTimer_MODE_PWM_PR                    ((uint32)(SerialDataTimer__PWM_PR          <<  \
                                                                  SerialDataTimer_MODE_SHIFT))

/* Quad Modes */
#define SerialDataTimer_MODE_X1                        ((uint32)(SerialDataTimer__X1              <<  \
                                                                  SerialDataTimer_QUAD_MODE_SHIFT))
#define SerialDataTimer_MODE_X2                        ((uint32)(SerialDataTimer__X2              <<  \
                                                                  SerialDataTimer_QUAD_MODE_SHIFT))
#define SerialDataTimer_MODE_X4                        ((uint32)(SerialDataTimer__X4              <<  \
                                                                  SerialDataTimer_QUAD_MODE_SHIFT))

/* Counter modes */
#define SerialDataTimer_COUNT_UP                       ((uint32)(SerialDataTimer__COUNT_UP        <<  \
                                                                  SerialDataTimer_UPDOWN_SHIFT))
#define SerialDataTimer_COUNT_DOWN                     ((uint32)(SerialDataTimer__COUNT_DOWN      <<  \
                                                                  SerialDataTimer_UPDOWN_SHIFT))
#define SerialDataTimer_COUNT_UPDOWN0                  ((uint32)(SerialDataTimer__COUNT_UPDOWN0   <<  \
                                                                  SerialDataTimer_UPDOWN_SHIFT))
#define SerialDataTimer_COUNT_UPDOWN1                  ((uint32)(SerialDataTimer__COUNT_UPDOWN1   <<  \
                                                                  SerialDataTimer_UPDOWN_SHIFT))

/* PWM output invert */
#define SerialDataTimer_INVERT_LINE                    ((uint32)(SerialDataTimer__INVERSE         <<  \
                                                                  SerialDataTimer_INV_OUT_SHIFT))
#define SerialDataTimer_INVERT_LINE_N                  ((uint32)(SerialDataTimer__INVERSE         <<  \
                                                                  SerialDataTimer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define SerialDataTimer_TRIG_RISING                    ((uint32)SerialDataTimer__TRIG_RISING)
#define SerialDataTimer_TRIG_FALLING                   ((uint32)SerialDataTimer__TRIG_FALLING)
#define SerialDataTimer_TRIG_BOTH                      ((uint32)SerialDataTimer__TRIG_BOTH)
#define SerialDataTimer_TRIG_LEVEL                     ((uint32)SerialDataTimer__TRIG_LEVEL)

/* Interrupt mask */
#define SerialDataTimer_INTR_MASK_TC                   ((uint32)SerialDataTimer__INTR_MASK_TC)
#define SerialDataTimer_INTR_MASK_CC_MATCH             ((uint32)SerialDataTimer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define SerialDataTimer_CC_MATCH_SET                   (0x00u)
#define SerialDataTimer_CC_MATCH_CLEAR                 (0x01u)
#define SerialDataTimer_CC_MATCH_INVERT                (0x02u)
#define SerialDataTimer_CC_MATCH_NO_CHANGE             (0x03u)
#define SerialDataTimer_OVERLOW_SET                    (0x00u)
#define SerialDataTimer_OVERLOW_CLEAR                  (0x04u)
#define SerialDataTimer_OVERLOW_INVERT                 (0x08u)
#define SerialDataTimer_OVERLOW_NO_CHANGE              (0x0Cu)
#define SerialDataTimer_UNDERFLOW_SET                  (0x00u)
#define SerialDataTimer_UNDERFLOW_CLEAR                (0x10u)
#define SerialDataTimer_UNDERFLOW_INVERT               (0x20u)
#define SerialDataTimer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define SerialDataTimer_PWM_MODE_LEFT                  (SerialDataTimer_CC_MATCH_CLEAR        |   \
                                                         SerialDataTimer_OVERLOW_SET           |   \
                                                         SerialDataTimer_UNDERFLOW_NO_CHANGE)
#define SerialDataTimer_PWM_MODE_RIGHT                 (SerialDataTimer_CC_MATCH_SET          |   \
                                                         SerialDataTimer_OVERLOW_NO_CHANGE     |   \
                                                         SerialDataTimer_UNDERFLOW_CLEAR)
#define SerialDataTimer_PWM_MODE_ASYM                  (SerialDataTimer_CC_MATCH_INVERT       |   \
                                                         SerialDataTimer_OVERLOW_SET           |   \
                                                         SerialDataTimer_UNDERFLOW_CLEAR)

#if (SerialDataTimer_CY_TCPWM_V2)
    #if(SerialDataTimer_CY_TCPWM_4000)
        #define SerialDataTimer_PWM_MODE_CENTER                (SerialDataTimer_CC_MATCH_INVERT       |   \
                                                                 SerialDataTimer_OVERLOW_NO_CHANGE     |   \
                                                                 SerialDataTimer_UNDERFLOW_CLEAR)
    #else
        #define SerialDataTimer_PWM_MODE_CENTER                (SerialDataTimer_CC_MATCH_INVERT       |   \
                                                                 SerialDataTimer_OVERLOW_SET           |   \
                                                                 SerialDataTimer_UNDERFLOW_CLEAR)
    #endif /* (SerialDataTimer_CY_TCPWM_4000) */
#else
    #define SerialDataTimer_PWM_MODE_CENTER                (SerialDataTimer_CC_MATCH_INVERT       |   \
                                                             SerialDataTimer_OVERLOW_NO_CHANGE     |   \
                                                             SerialDataTimer_UNDERFLOW_CLEAR)
#endif /* (SerialDataTimer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define SerialDataTimer_CMD_CAPTURE                    (0u)
#define SerialDataTimer_CMD_RELOAD                     (8u)
#define SerialDataTimer_CMD_STOP                       (16u)
#define SerialDataTimer_CMD_START                      (24u)

/* Status */
#define SerialDataTimer_STATUS_DOWN                    (1u)
#define SerialDataTimer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   SerialDataTimer_Init(void);
void   SerialDataTimer_Enable(void);
void   SerialDataTimer_Start(void);
void   SerialDataTimer_Stop(void);

void   SerialDataTimer_SetMode(uint32 mode);
void   SerialDataTimer_SetCounterMode(uint32 counterMode);
void   SerialDataTimer_SetPWMMode(uint32 modeMask);
void   SerialDataTimer_SetQDMode(uint32 qdMode);

void   SerialDataTimer_SetPrescaler(uint32 prescaler);
void   SerialDataTimer_TriggerCommand(uint32 mask, uint32 command);
void   SerialDataTimer_SetOneShot(uint32 oneShotEnable);
uint32 SerialDataTimer_ReadStatus(void);

void   SerialDataTimer_SetPWMSyncKill(uint32 syncKillEnable);
void   SerialDataTimer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   SerialDataTimer_SetPWMDeadTime(uint32 deadTime);
void   SerialDataTimer_SetPWMInvert(uint32 mask);

void   SerialDataTimer_SetInterruptMode(uint32 interruptMask);
uint32 SerialDataTimer_GetInterruptSourceMasked(void);
uint32 SerialDataTimer_GetInterruptSource(void);
void   SerialDataTimer_ClearInterrupt(uint32 interruptMask);
void   SerialDataTimer_SetInterrupt(uint32 interruptMask);

void   SerialDataTimer_WriteCounter(uint32 count);
uint32 SerialDataTimer_ReadCounter(void);

uint32 SerialDataTimer_ReadCapture(void);
uint32 SerialDataTimer_ReadCaptureBuf(void);

void   SerialDataTimer_WritePeriod(uint32 period);
uint32 SerialDataTimer_ReadPeriod(void);
void   SerialDataTimer_WritePeriodBuf(uint32 periodBuf);
uint32 SerialDataTimer_ReadPeriodBuf(void);

void   SerialDataTimer_WriteCompare(uint32 compare);
uint32 SerialDataTimer_ReadCompare(void);
void   SerialDataTimer_WriteCompareBuf(uint32 compareBuf);
uint32 SerialDataTimer_ReadCompareBuf(void);

void   SerialDataTimer_SetPeriodSwap(uint32 swapEnable);
void   SerialDataTimer_SetCompareSwap(uint32 swapEnable);

void   SerialDataTimer_SetCaptureMode(uint32 triggerMode);
void   SerialDataTimer_SetReloadMode(uint32 triggerMode);
void   SerialDataTimer_SetStartMode(uint32 triggerMode);
void   SerialDataTimer_SetStopMode(uint32 triggerMode);
void   SerialDataTimer_SetCountMode(uint32 triggerMode);

void   SerialDataTimer_SaveConfig(void);
void   SerialDataTimer_RestoreConfig(void);
void   SerialDataTimer_Sleep(void);
void   SerialDataTimer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define SerialDataTimer_BLOCK_CONTROL_REG              (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define SerialDataTimer_BLOCK_CONTROL_PTR              ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define SerialDataTimer_COMMAND_REG                    (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define SerialDataTimer_COMMAND_PTR                    ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define SerialDataTimer_INTRRUPT_CAUSE_REG             (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define SerialDataTimer_INTRRUPT_CAUSE_PTR             ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define SerialDataTimer_CONTROL_REG                    (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__CTRL )
#define SerialDataTimer_CONTROL_PTR                    ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__CTRL )
#define SerialDataTimer_STATUS_REG                     (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__STATUS )
#define SerialDataTimer_STATUS_PTR                     ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__STATUS )
#define SerialDataTimer_COUNTER_REG                    (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__COUNTER )
#define SerialDataTimer_COUNTER_PTR                    ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__COUNTER )
#define SerialDataTimer_COMP_CAP_REG                   (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__CC )
#define SerialDataTimer_COMP_CAP_PTR                   ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__CC )
#define SerialDataTimer_COMP_CAP_BUF_REG               (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define SerialDataTimer_COMP_CAP_BUF_PTR               ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define SerialDataTimer_PERIOD_REG                     (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__PERIOD )
#define SerialDataTimer_PERIOD_PTR                     ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__PERIOD )
#define SerialDataTimer_PERIOD_BUF_REG                 (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define SerialDataTimer_PERIOD_BUF_PTR                 ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define SerialDataTimer_TRIG_CONTROL0_REG              (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define SerialDataTimer_TRIG_CONTROL0_PTR              ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define SerialDataTimer_TRIG_CONTROL1_REG              (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define SerialDataTimer_TRIG_CONTROL1_PTR              ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define SerialDataTimer_TRIG_CONTROL2_REG              (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define SerialDataTimer_TRIG_CONTROL2_PTR              ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define SerialDataTimer_INTERRUPT_REQ_REG              (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__INTR )
#define SerialDataTimer_INTERRUPT_REQ_PTR              ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__INTR )
#define SerialDataTimer_INTERRUPT_SET_REG              (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define SerialDataTimer_INTERRUPT_SET_PTR              ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define SerialDataTimer_INTERRUPT_MASK_REG             (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define SerialDataTimer_INTERRUPT_MASK_PTR             ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define SerialDataTimer_INTERRUPT_MASKED_REG           (*(reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define SerialDataTimer_INTERRUPT_MASKED_PTR           ( (reg32 *) SerialDataTimer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define SerialDataTimer_MASK                           ((uint32)SerialDataTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define SerialDataTimer_RELOAD_CC_SHIFT                (0u)
#define SerialDataTimer_RELOAD_PERIOD_SHIFT            (1u)
#define SerialDataTimer_PWM_SYNC_KILL_SHIFT            (2u)
#define SerialDataTimer_PWM_STOP_KILL_SHIFT            (3u)
#define SerialDataTimer_PRESCALER_SHIFT                (8u)
#define SerialDataTimer_UPDOWN_SHIFT                   (16u)
#define SerialDataTimer_ONESHOT_SHIFT                  (18u)
#define SerialDataTimer_QUAD_MODE_SHIFT                (20u)
#define SerialDataTimer_INV_OUT_SHIFT                  (20u)
#define SerialDataTimer_INV_COMPL_OUT_SHIFT            (21u)
#define SerialDataTimer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define SerialDataTimer_RELOAD_CC_MASK                 ((uint32)(SerialDataTimer_1BIT_MASK        <<  \
                                                                            SerialDataTimer_RELOAD_CC_SHIFT))
#define SerialDataTimer_RELOAD_PERIOD_MASK             ((uint32)(SerialDataTimer_1BIT_MASK        <<  \
                                                                            SerialDataTimer_RELOAD_PERIOD_SHIFT))
#define SerialDataTimer_PWM_SYNC_KILL_MASK             ((uint32)(SerialDataTimer_1BIT_MASK        <<  \
                                                                            SerialDataTimer_PWM_SYNC_KILL_SHIFT))
#define SerialDataTimer_PWM_STOP_KILL_MASK             ((uint32)(SerialDataTimer_1BIT_MASK        <<  \
                                                                            SerialDataTimer_PWM_STOP_KILL_SHIFT))
#define SerialDataTimer_PRESCALER_MASK                 ((uint32)(SerialDataTimer_8BIT_MASK        <<  \
                                                                            SerialDataTimer_PRESCALER_SHIFT))
#define SerialDataTimer_UPDOWN_MASK                    ((uint32)(SerialDataTimer_2BIT_MASK        <<  \
                                                                            SerialDataTimer_UPDOWN_SHIFT))
#define SerialDataTimer_ONESHOT_MASK                   ((uint32)(SerialDataTimer_1BIT_MASK        <<  \
                                                                            SerialDataTimer_ONESHOT_SHIFT))
#define SerialDataTimer_QUAD_MODE_MASK                 ((uint32)(SerialDataTimer_3BIT_MASK        <<  \
                                                                            SerialDataTimer_QUAD_MODE_SHIFT))
#define SerialDataTimer_INV_OUT_MASK                   ((uint32)(SerialDataTimer_2BIT_MASK        <<  \
                                                                            SerialDataTimer_INV_OUT_SHIFT))
#define SerialDataTimer_MODE_MASK                      ((uint32)(SerialDataTimer_3BIT_MASK        <<  \
                                                                            SerialDataTimer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define SerialDataTimer_CAPTURE_SHIFT                  (0u)
#define SerialDataTimer_COUNT_SHIFT                    (2u)
#define SerialDataTimer_RELOAD_SHIFT                   (4u)
#define SerialDataTimer_STOP_SHIFT                     (6u)
#define SerialDataTimer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define SerialDataTimer_CAPTURE_MASK                   ((uint32)(SerialDataTimer_2BIT_MASK        <<  \
                                                                  SerialDataTimer_CAPTURE_SHIFT))
#define SerialDataTimer_COUNT_MASK                     ((uint32)(SerialDataTimer_2BIT_MASK        <<  \
                                                                  SerialDataTimer_COUNT_SHIFT))
#define SerialDataTimer_RELOAD_MASK                    ((uint32)(SerialDataTimer_2BIT_MASK        <<  \
                                                                  SerialDataTimer_RELOAD_SHIFT))
#define SerialDataTimer_STOP_MASK                      ((uint32)(SerialDataTimer_2BIT_MASK        <<  \
                                                                  SerialDataTimer_STOP_SHIFT))
#define SerialDataTimer_START_MASK                     ((uint32)(SerialDataTimer_2BIT_MASK        <<  \
                                                                  SerialDataTimer_START_SHIFT))

/* MASK */
#define SerialDataTimer_1BIT_MASK                      ((uint32)0x01u)
#define SerialDataTimer_2BIT_MASK                      ((uint32)0x03u)
#define SerialDataTimer_3BIT_MASK                      ((uint32)0x07u)
#define SerialDataTimer_6BIT_MASK                      ((uint32)0x3Fu)
#define SerialDataTimer_8BIT_MASK                      ((uint32)0xFFu)
#define SerialDataTimer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define SerialDataTimer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define SerialDataTimer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(SerialDataTimer_QUAD_ENCODING_MODES     << SerialDataTimer_QUAD_MODE_SHIFT))       |\
         ((uint32)(SerialDataTimer_CONFIG                  << SerialDataTimer_MODE_SHIFT)))

#define SerialDataTimer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(SerialDataTimer_PWM_STOP_EVENT          << SerialDataTimer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(SerialDataTimer_PWM_OUT_INVERT          << SerialDataTimer_INV_OUT_SHIFT))         |\
         ((uint32)(SerialDataTimer_PWM_OUT_N_INVERT        << SerialDataTimer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(SerialDataTimer_PWM_MODE                << SerialDataTimer_MODE_SHIFT)))

#define SerialDataTimer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(SerialDataTimer_PWM_RUN_MODE         << SerialDataTimer_ONESHOT_SHIFT))
            
#define SerialDataTimer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(SerialDataTimer_PWM_ALIGN            << SerialDataTimer_UPDOWN_SHIFT))

#define SerialDataTimer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(SerialDataTimer_PWM_KILL_EVENT      << SerialDataTimer_PWM_SYNC_KILL_SHIFT))

#define SerialDataTimer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(SerialDataTimer_PWM_DEAD_TIME_CYCLE  << SerialDataTimer_PRESCALER_SHIFT))

#define SerialDataTimer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(SerialDataTimer_PWM_PRESCALER        << SerialDataTimer_PRESCALER_SHIFT))

#define SerialDataTimer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(SerialDataTimer_TC_PRESCALER            << SerialDataTimer_PRESCALER_SHIFT))       |\
         ((uint32)(SerialDataTimer_TC_COUNTER_MODE         << SerialDataTimer_UPDOWN_SHIFT))          |\
         ((uint32)(SerialDataTimer_TC_RUN_MODE             << SerialDataTimer_ONESHOT_SHIFT))         |\
         ((uint32)(SerialDataTimer_TC_COMP_CAP_MODE        << SerialDataTimer_MODE_SHIFT)))
        
#define SerialDataTimer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(SerialDataTimer_QUAD_PHIA_SIGNAL_MODE   << SerialDataTimer_COUNT_SHIFT))           |\
         ((uint32)(SerialDataTimer_QUAD_INDEX_SIGNAL_MODE  << SerialDataTimer_RELOAD_SHIFT))          |\
         ((uint32)(SerialDataTimer_QUAD_STOP_SIGNAL_MODE   << SerialDataTimer_STOP_SHIFT))            |\
         ((uint32)(SerialDataTimer_QUAD_PHIB_SIGNAL_MODE   << SerialDataTimer_START_SHIFT)))

#define SerialDataTimer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(SerialDataTimer_PWM_SWITCH_SIGNAL_MODE  << SerialDataTimer_CAPTURE_SHIFT))         |\
         ((uint32)(SerialDataTimer_PWM_COUNT_SIGNAL_MODE   << SerialDataTimer_COUNT_SHIFT))           |\
         ((uint32)(SerialDataTimer_PWM_RELOAD_SIGNAL_MODE  << SerialDataTimer_RELOAD_SHIFT))          |\
         ((uint32)(SerialDataTimer_PWM_STOP_SIGNAL_MODE    << SerialDataTimer_STOP_SHIFT))            |\
         ((uint32)(SerialDataTimer_PWM_START_SIGNAL_MODE   << SerialDataTimer_START_SHIFT)))

#define SerialDataTimer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(SerialDataTimer_TC_CAPTURE_SIGNAL_MODE  << SerialDataTimer_CAPTURE_SHIFT))         |\
         ((uint32)(SerialDataTimer_TC_COUNT_SIGNAL_MODE    << SerialDataTimer_COUNT_SHIFT))           |\
         ((uint32)(SerialDataTimer_TC_RELOAD_SIGNAL_MODE   << SerialDataTimer_RELOAD_SHIFT))          |\
         ((uint32)(SerialDataTimer_TC_STOP_SIGNAL_MODE     << SerialDataTimer_STOP_SHIFT))            |\
         ((uint32)(SerialDataTimer_TC_START_SIGNAL_MODE    << SerialDataTimer_START_SHIFT)))
        
#define SerialDataTimer_TIMER_UPDOWN_CNT_USED                                                          \
                ((SerialDataTimer__COUNT_UPDOWN0 == SerialDataTimer_TC_COUNTER_MODE)                  ||\
                 (SerialDataTimer__COUNT_UPDOWN1 == SerialDataTimer_TC_COUNTER_MODE))

#define SerialDataTimer_PWM_UPDOWN_CNT_USED                                                            \
                ((SerialDataTimer__CENTER == SerialDataTimer_PWM_ALIGN)                               ||\
                 (SerialDataTimer__ASYMMETRIC == SerialDataTimer_PWM_ALIGN))               
        
#define SerialDataTimer_PWM_PR_INIT_VALUE              (1u)
#define SerialDataTimer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_SerialDataTimer_H */

/* [] END OF FILE */
