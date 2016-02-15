/*******************************************************************************
* File Name: PIDLoopTimer.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the PIDLoopTimer
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

#if !defined(CY_TCPWM_PIDLoopTimer_H)
#define CY_TCPWM_PIDLoopTimer_H


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
} PIDLoopTimer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  PIDLoopTimer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define PIDLoopTimer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define PIDLoopTimer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define PIDLoopTimer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define PIDLoopTimer_QUAD_ENCODING_MODES            (0lu)
#define PIDLoopTimer_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define PIDLoopTimer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define PIDLoopTimer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define PIDLoopTimer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define PIDLoopTimer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define PIDLoopTimer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define PIDLoopTimer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define PIDLoopTimer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define PIDLoopTimer_TC_RUN_MODE                    (0lu)
#define PIDLoopTimer_TC_COUNTER_MODE                (0lu)
#define PIDLoopTimer_TC_COMP_CAP_MODE               (2lu)
#define PIDLoopTimer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define PIDLoopTimer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define PIDLoopTimer_TC_COUNT_SIGNAL_MODE           (3lu)
#define PIDLoopTimer_TC_START_SIGNAL_MODE           (0lu)
#define PIDLoopTimer_TC_STOP_SIGNAL_MODE            (0lu)
#define PIDLoopTimer_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define PIDLoopTimer_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define PIDLoopTimer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define PIDLoopTimer_TC_START_SIGNAL_PRESENT        (0lu)
#define PIDLoopTimer_TC_STOP_SIGNAL_PRESENT         (0lu)
#define PIDLoopTimer_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PIDLoopTimer_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define PIDLoopTimer_PWM_KILL_EVENT                 (0lu)
#define PIDLoopTimer_PWM_STOP_EVENT                 (0lu)
#define PIDLoopTimer_PWM_MODE                       (4lu)
#define PIDLoopTimer_PWM_OUT_N_INVERT               (0lu)
#define PIDLoopTimer_PWM_OUT_INVERT                 (0lu)
#define PIDLoopTimer_PWM_ALIGN                      (0lu)
#define PIDLoopTimer_PWM_RUN_MODE                   (0lu)
#define PIDLoopTimer_PWM_DEAD_TIME_CYCLE            (0lu)
#define PIDLoopTimer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define PIDLoopTimer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define PIDLoopTimer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define PIDLoopTimer_PWM_START_SIGNAL_MODE          (0lu)
#define PIDLoopTimer_PWM_STOP_SIGNAL_MODE           (0lu)
#define PIDLoopTimer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define PIDLoopTimer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define PIDLoopTimer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define PIDLoopTimer_PWM_START_SIGNAL_PRESENT       (0lu)
#define PIDLoopTimer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define PIDLoopTimer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PIDLoopTimer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define PIDLoopTimer_TC_PERIOD_VALUE                (300lu)
#define PIDLoopTimer_TC_COMPARE_VALUE               (65535lu)
#define PIDLoopTimer_TC_COMPARE_BUF_VALUE           (65535lu)
#define PIDLoopTimer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define PIDLoopTimer_PWM_PERIOD_VALUE               (65535lu)
#define PIDLoopTimer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define PIDLoopTimer_PWM_PERIOD_SWAP                (0lu)
#define PIDLoopTimer_PWM_COMPARE_VALUE              (65535lu)
#define PIDLoopTimer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define PIDLoopTimer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define PIDLoopTimer__LEFT 0
#define PIDLoopTimer__RIGHT 1
#define PIDLoopTimer__CENTER 2
#define PIDLoopTimer__ASYMMETRIC 3

#define PIDLoopTimer__X1 0
#define PIDLoopTimer__X2 1
#define PIDLoopTimer__X4 2

#define PIDLoopTimer__PWM 4
#define PIDLoopTimer__PWM_DT 5
#define PIDLoopTimer__PWM_PR 6

#define PIDLoopTimer__INVERSE 1
#define PIDLoopTimer__DIRECT 0

#define PIDLoopTimer__CAPTURE 2
#define PIDLoopTimer__COMPARE 0

#define PIDLoopTimer__TRIG_LEVEL 3
#define PIDLoopTimer__TRIG_RISING 0
#define PIDLoopTimer__TRIG_FALLING 1
#define PIDLoopTimer__TRIG_BOTH 2

#define PIDLoopTimer__INTR_MASK_TC 1
#define PIDLoopTimer__INTR_MASK_CC_MATCH 2
#define PIDLoopTimer__INTR_MASK_NONE 0
#define PIDLoopTimer__INTR_MASK_TC_CC 3

#define PIDLoopTimer__UNCONFIG 8
#define PIDLoopTimer__TIMER 1
#define PIDLoopTimer__QUAD 3
#define PIDLoopTimer__PWM_SEL 7

#define PIDLoopTimer__COUNT_UP 0
#define PIDLoopTimer__COUNT_DOWN 1
#define PIDLoopTimer__COUNT_UPDOWN0 2
#define PIDLoopTimer__COUNT_UPDOWN1 3


/* Prescaler */
#define PIDLoopTimer_PRESCALE_DIVBY1                ((uint32)(0u << PIDLoopTimer_PRESCALER_SHIFT))
#define PIDLoopTimer_PRESCALE_DIVBY2                ((uint32)(1u << PIDLoopTimer_PRESCALER_SHIFT))
#define PIDLoopTimer_PRESCALE_DIVBY4                ((uint32)(2u << PIDLoopTimer_PRESCALER_SHIFT))
#define PIDLoopTimer_PRESCALE_DIVBY8                ((uint32)(3u << PIDLoopTimer_PRESCALER_SHIFT))
#define PIDLoopTimer_PRESCALE_DIVBY16               ((uint32)(4u << PIDLoopTimer_PRESCALER_SHIFT))
#define PIDLoopTimer_PRESCALE_DIVBY32               ((uint32)(5u << PIDLoopTimer_PRESCALER_SHIFT))
#define PIDLoopTimer_PRESCALE_DIVBY64               ((uint32)(6u << PIDLoopTimer_PRESCALER_SHIFT))
#define PIDLoopTimer_PRESCALE_DIVBY128              ((uint32)(7u << PIDLoopTimer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define PIDLoopTimer_MODE_TIMER_COMPARE             ((uint32)(PIDLoopTimer__COMPARE         <<  \
                                                                  PIDLoopTimer_MODE_SHIFT))
#define PIDLoopTimer_MODE_TIMER_CAPTURE             ((uint32)(PIDLoopTimer__CAPTURE         <<  \
                                                                  PIDLoopTimer_MODE_SHIFT))
#define PIDLoopTimer_MODE_QUAD                      ((uint32)(PIDLoopTimer__QUAD            <<  \
                                                                  PIDLoopTimer_MODE_SHIFT))
#define PIDLoopTimer_MODE_PWM                       ((uint32)(PIDLoopTimer__PWM             <<  \
                                                                  PIDLoopTimer_MODE_SHIFT))
#define PIDLoopTimer_MODE_PWM_DT                    ((uint32)(PIDLoopTimer__PWM_DT          <<  \
                                                                  PIDLoopTimer_MODE_SHIFT))
#define PIDLoopTimer_MODE_PWM_PR                    ((uint32)(PIDLoopTimer__PWM_PR          <<  \
                                                                  PIDLoopTimer_MODE_SHIFT))

/* Quad Modes */
#define PIDLoopTimer_MODE_X1                        ((uint32)(PIDLoopTimer__X1              <<  \
                                                                  PIDLoopTimer_QUAD_MODE_SHIFT))
#define PIDLoopTimer_MODE_X2                        ((uint32)(PIDLoopTimer__X2              <<  \
                                                                  PIDLoopTimer_QUAD_MODE_SHIFT))
#define PIDLoopTimer_MODE_X4                        ((uint32)(PIDLoopTimer__X4              <<  \
                                                                  PIDLoopTimer_QUAD_MODE_SHIFT))

/* Counter modes */
#define PIDLoopTimer_COUNT_UP                       ((uint32)(PIDLoopTimer__COUNT_UP        <<  \
                                                                  PIDLoopTimer_UPDOWN_SHIFT))
#define PIDLoopTimer_COUNT_DOWN                     ((uint32)(PIDLoopTimer__COUNT_DOWN      <<  \
                                                                  PIDLoopTimer_UPDOWN_SHIFT))
#define PIDLoopTimer_COUNT_UPDOWN0                  ((uint32)(PIDLoopTimer__COUNT_UPDOWN0   <<  \
                                                                  PIDLoopTimer_UPDOWN_SHIFT))
#define PIDLoopTimer_COUNT_UPDOWN1                  ((uint32)(PIDLoopTimer__COUNT_UPDOWN1   <<  \
                                                                  PIDLoopTimer_UPDOWN_SHIFT))

/* PWM output invert */
#define PIDLoopTimer_INVERT_LINE                    ((uint32)(PIDLoopTimer__INVERSE         <<  \
                                                                  PIDLoopTimer_INV_OUT_SHIFT))
#define PIDLoopTimer_INVERT_LINE_N                  ((uint32)(PIDLoopTimer__INVERSE         <<  \
                                                                  PIDLoopTimer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define PIDLoopTimer_TRIG_RISING                    ((uint32)PIDLoopTimer__TRIG_RISING)
#define PIDLoopTimer_TRIG_FALLING                   ((uint32)PIDLoopTimer__TRIG_FALLING)
#define PIDLoopTimer_TRIG_BOTH                      ((uint32)PIDLoopTimer__TRIG_BOTH)
#define PIDLoopTimer_TRIG_LEVEL                     ((uint32)PIDLoopTimer__TRIG_LEVEL)

/* Interrupt mask */
#define PIDLoopTimer_INTR_MASK_TC                   ((uint32)PIDLoopTimer__INTR_MASK_TC)
#define PIDLoopTimer_INTR_MASK_CC_MATCH             ((uint32)PIDLoopTimer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define PIDLoopTimer_CC_MATCH_SET                   (0x00u)
#define PIDLoopTimer_CC_MATCH_CLEAR                 (0x01u)
#define PIDLoopTimer_CC_MATCH_INVERT                (0x02u)
#define PIDLoopTimer_CC_MATCH_NO_CHANGE             (0x03u)
#define PIDLoopTimer_OVERLOW_SET                    (0x00u)
#define PIDLoopTimer_OVERLOW_CLEAR                  (0x04u)
#define PIDLoopTimer_OVERLOW_INVERT                 (0x08u)
#define PIDLoopTimer_OVERLOW_NO_CHANGE              (0x0Cu)
#define PIDLoopTimer_UNDERFLOW_SET                  (0x00u)
#define PIDLoopTimer_UNDERFLOW_CLEAR                (0x10u)
#define PIDLoopTimer_UNDERFLOW_INVERT               (0x20u)
#define PIDLoopTimer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define PIDLoopTimer_PWM_MODE_LEFT                  (PIDLoopTimer_CC_MATCH_CLEAR        |   \
                                                         PIDLoopTimer_OVERLOW_SET           |   \
                                                         PIDLoopTimer_UNDERFLOW_NO_CHANGE)
#define PIDLoopTimer_PWM_MODE_RIGHT                 (PIDLoopTimer_CC_MATCH_SET          |   \
                                                         PIDLoopTimer_OVERLOW_NO_CHANGE     |   \
                                                         PIDLoopTimer_UNDERFLOW_CLEAR)
#define PIDLoopTimer_PWM_MODE_ASYM                  (PIDLoopTimer_CC_MATCH_INVERT       |   \
                                                         PIDLoopTimer_OVERLOW_SET           |   \
                                                         PIDLoopTimer_UNDERFLOW_CLEAR)

#if (PIDLoopTimer_CY_TCPWM_V2)
    #if(PIDLoopTimer_CY_TCPWM_4000)
        #define PIDLoopTimer_PWM_MODE_CENTER                (PIDLoopTimer_CC_MATCH_INVERT       |   \
                                                                 PIDLoopTimer_OVERLOW_NO_CHANGE     |   \
                                                                 PIDLoopTimer_UNDERFLOW_CLEAR)
    #else
        #define PIDLoopTimer_PWM_MODE_CENTER                (PIDLoopTimer_CC_MATCH_INVERT       |   \
                                                                 PIDLoopTimer_OVERLOW_SET           |   \
                                                                 PIDLoopTimer_UNDERFLOW_CLEAR)
    #endif /* (PIDLoopTimer_CY_TCPWM_4000) */
#else
    #define PIDLoopTimer_PWM_MODE_CENTER                (PIDLoopTimer_CC_MATCH_INVERT       |   \
                                                             PIDLoopTimer_OVERLOW_NO_CHANGE     |   \
                                                             PIDLoopTimer_UNDERFLOW_CLEAR)
#endif /* (PIDLoopTimer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define PIDLoopTimer_CMD_CAPTURE                    (0u)
#define PIDLoopTimer_CMD_RELOAD                     (8u)
#define PIDLoopTimer_CMD_STOP                       (16u)
#define PIDLoopTimer_CMD_START                      (24u)

/* Status */
#define PIDLoopTimer_STATUS_DOWN                    (1u)
#define PIDLoopTimer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   PIDLoopTimer_Init(void);
void   PIDLoopTimer_Enable(void);
void   PIDLoopTimer_Start(void);
void   PIDLoopTimer_Stop(void);

void   PIDLoopTimer_SetMode(uint32 mode);
void   PIDLoopTimer_SetCounterMode(uint32 counterMode);
void   PIDLoopTimer_SetPWMMode(uint32 modeMask);
void   PIDLoopTimer_SetQDMode(uint32 qdMode);

void   PIDLoopTimer_SetPrescaler(uint32 prescaler);
void   PIDLoopTimer_TriggerCommand(uint32 mask, uint32 command);
void   PIDLoopTimer_SetOneShot(uint32 oneShotEnable);
uint32 PIDLoopTimer_ReadStatus(void);

void   PIDLoopTimer_SetPWMSyncKill(uint32 syncKillEnable);
void   PIDLoopTimer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   PIDLoopTimer_SetPWMDeadTime(uint32 deadTime);
void   PIDLoopTimer_SetPWMInvert(uint32 mask);

void   PIDLoopTimer_SetInterruptMode(uint32 interruptMask);
uint32 PIDLoopTimer_GetInterruptSourceMasked(void);
uint32 PIDLoopTimer_GetInterruptSource(void);
void   PIDLoopTimer_ClearInterrupt(uint32 interruptMask);
void   PIDLoopTimer_SetInterrupt(uint32 interruptMask);

void   PIDLoopTimer_WriteCounter(uint32 count);
uint32 PIDLoopTimer_ReadCounter(void);

uint32 PIDLoopTimer_ReadCapture(void);
uint32 PIDLoopTimer_ReadCaptureBuf(void);

void   PIDLoopTimer_WritePeriod(uint32 period);
uint32 PIDLoopTimer_ReadPeriod(void);
void   PIDLoopTimer_WritePeriodBuf(uint32 periodBuf);
uint32 PIDLoopTimer_ReadPeriodBuf(void);

void   PIDLoopTimer_WriteCompare(uint32 compare);
uint32 PIDLoopTimer_ReadCompare(void);
void   PIDLoopTimer_WriteCompareBuf(uint32 compareBuf);
uint32 PIDLoopTimer_ReadCompareBuf(void);

void   PIDLoopTimer_SetPeriodSwap(uint32 swapEnable);
void   PIDLoopTimer_SetCompareSwap(uint32 swapEnable);

void   PIDLoopTimer_SetCaptureMode(uint32 triggerMode);
void   PIDLoopTimer_SetReloadMode(uint32 triggerMode);
void   PIDLoopTimer_SetStartMode(uint32 triggerMode);
void   PIDLoopTimer_SetStopMode(uint32 triggerMode);
void   PIDLoopTimer_SetCountMode(uint32 triggerMode);

void   PIDLoopTimer_SaveConfig(void);
void   PIDLoopTimer_RestoreConfig(void);
void   PIDLoopTimer_Sleep(void);
void   PIDLoopTimer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define PIDLoopTimer_BLOCK_CONTROL_REG              (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PIDLoopTimer_BLOCK_CONTROL_PTR              ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PIDLoopTimer_COMMAND_REG                    (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PIDLoopTimer_COMMAND_PTR                    ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PIDLoopTimer_INTRRUPT_CAUSE_REG             (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PIDLoopTimer_INTRRUPT_CAUSE_PTR             ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PIDLoopTimer_CONTROL_REG                    (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__CTRL )
#define PIDLoopTimer_CONTROL_PTR                    ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__CTRL )
#define PIDLoopTimer_STATUS_REG                     (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__STATUS )
#define PIDLoopTimer_STATUS_PTR                     ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__STATUS )
#define PIDLoopTimer_COUNTER_REG                    (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__COUNTER )
#define PIDLoopTimer_COUNTER_PTR                    ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__COUNTER )
#define PIDLoopTimer_COMP_CAP_REG                   (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__CC )
#define PIDLoopTimer_COMP_CAP_PTR                   ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__CC )
#define PIDLoopTimer_COMP_CAP_BUF_REG               (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define PIDLoopTimer_COMP_CAP_BUF_PTR               ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define PIDLoopTimer_PERIOD_REG                     (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__PERIOD )
#define PIDLoopTimer_PERIOD_PTR                     ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__PERIOD )
#define PIDLoopTimer_PERIOD_BUF_REG                 (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PIDLoopTimer_PERIOD_BUF_PTR                 ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PIDLoopTimer_TRIG_CONTROL0_REG              (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PIDLoopTimer_TRIG_CONTROL0_PTR              ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PIDLoopTimer_TRIG_CONTROL1_REG              (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PIDLoopTimer_TRIG_CONTROL1_PTR              ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PIDLoopTimer_TRIG_CONTROL2_REG              (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PIDLoopTimer_TRIG_CONTROL2_PTR              ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PIDLoopTimer_INTERRUPT_REQ_REG              (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__INTR )
#define PIDLoopTimer_INTERRUPT_REQ_PTR              ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__INTR )
#define PIDLoopTimer_INTERRUPT_SET_REG              (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define PIDLoopTimer_INTERRUPT_SET_PTR              ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define PIDLoopTimer_INTERRUPT_MASK_REG             (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define PIDLoopTimer_INTERRUPT_MASK_PTR             ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define PIDLoopTimer_INTERRUPT_MASKED_REG           (*(reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define PIDLoopTimer_INTERRUPT_MASKED_PTR           ( (reg32 *) PIDLoopTimer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define PIDLoopTimer_MASK                           ((uint32)PIDLoopTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define PIDLoopTimer_RELOAD_CC_SHIFT                (0u)
#define PIDLoopTimer_RELOAD_PERIOD_SHIFT            (1u)
#define PIDLoopTimer_PWM_SYNC_KILL_SHIFT            (2u)
#define PIDLoopTimer_PWM_STOP_KILL_SHIFT            (3u)
#define PIDLoopTimer_PRESCALER_SHIFT                (8u)
#define PIDLoopTimer_UPDOWN_SHIFT                   (16u)
#define PIDLoopTimer_ONESHOT_SHIFT                  (18u)
#define PIDLoopTimer_QUAD_MODE_SHIFT                (20u)
#define PIDLoopTimer_INV_OUT_SHIFT                  (20u)
#define PIDLoopTimer_INV_COMPL_OUT_SHIFT            (21u)
#define PIDLoopTimer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define PIDLoopTimer_RELOAD_CC_MASK                 ((uint32)(PIDLoopTimer_1BIT_MASK        <<  \
                                                                            PIDLoopTimer_RELOAD_CC_SHIFT))
#define PIDLoopTimer_RELOAD_PERIOD_MASK             ((uint32)(PIDLoopTimer_1BIT_MASK        <<  \
                                                                            PIDLoopTimer_RELOAD_PERIOD_SHIFT))
#define PIDLoopTimer_PWM_SYNC_KILL_MASK             ((uint32)(PIDLoopTimer_1BIT_MASK        <<  \
                                                                            PIDLoopTimer_PWM_SYNC_KILL_SHIFT))
#define PIDLoopTimer_PWM_STOP_KILL_MASK             ((uint32)(PIDLoopTimer_1BIT_MASK        <<  \
                                                                            PIDLoopTimer_PWM_STOP_KILL_SHIFT))
#define PIDLoopTimer_PRESCALER_MASK                 ((uint32)(PIDLoopTimer_8BIT_MASK        <<  \
                                                                            PIDLoopTimer_PRESCALER_SHIFT))
#define PIDLoopTimer_UPDOWN_MASK                    ((uint32)(PIDLoopTimer_2BIT_MASK        <<  \
                                                                            PIDLoopTimer_UPDOWN_SHIFT))
#define PIDLoopTimer_ONESHOT_MASK                   ((uint32)(PIDLoopTimer_1BIT_MASK        <<  \
                                                                            PIDLoopTimer_ONESHOT_SHIFT))
#define PIDLoopTimer_QUAD_MODE_MASK                 ((uint32)(PIDLoopTimer_3BIT_MASK        <<  \
                                                                            PIDLoopTimer_QUAD_MODE_SHIFT))
#define PIDLoopTimer_INV_OUT_MASK                   ((uint32)(PIDLoopTimer_2BIT_MASK        <<  \
                                                                            PIDLoopTimer_INV_OUT_SHIFT))
#define PIDLoopTimer_MODE_MASK                      ((uint32)(PIDLoopTimer_3BIT_MASK        <<  \
                                                                            PIDLoopTimer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define PIDLoopTimer_CAPTURE_SHIFT                  (0u)
#define PIDLoopTimer_COUNT_SHIFT                    (2u)
#define PIDLoopTimer_RELOAD_SHIFT                   (4u)
#define PIDLoopTimer_STOP_SHIFT                     (6u)
#define PIDLoopTimer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define PIDLoopTimer_CAPTURE_MASK                   ((uint32)(PIDLoopTimer_2BIT_MASK        <<  \
                                                                  PIDLoopTimer_CAPTURE_SHIFT))
#define PIDLoopTimer_COUNT_MASK                     ((uint32)(PIDLoopTimer_2BIT_MASK        <<  \
                                                                  PIDLoopTimer_COUNT_SHIFT))
#define PIDLoopTimer_RELOAD_MASK                    ((uint32)(PIDLoopTimer_2BIT_MASK        <<  \
                                                                  PIDLoopTimer_RELOAD_SHIFT))
#define PIDLoopTimer_STOP_MASK                      ((uint32)(PIDLoopTimer_2BIT_MASK        <<  \
                                                                  PIDLoopTimer_STOP_SHIFT))
#define PIDLoopTimer_START_MASK                     ((uint32)(PIDLoopTimer_2BIT_MASK        <<  \
                                                                  PIDLoopTimer_START_SHIFT))

/* MASK */
#define PIDLoopTimer_1BIT_MASK                      ((uint32)0x01u)
#define PIDLoopTimer_2BIT_MASK                      ((uint32)0x03u)
#define PIDLoopTimer_3BIT_MASK                      ((uint32)0x07u)
#define PIDLoopTimer_6BIT_MASK                      ((uint32)0x3Fu)
#define PIDLoopTimer_8BIT_MASK                      ((uint32)0xFFu)
#define PIDLoopTimer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define PIDLoopTimer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define PIDLoopTimer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(PIDLoopTimer_QUAD_ENCODING_MODES     << PIDLoopTimer_QUAD_MODE_SHIFT))       |\
         ((uint32)(PIDLoopTimer_CONFIG                  << PIDLoopTimer_MODE_SHIFT)))

#define PIDLoopTimer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(PIDLoopTimer_PWM_STOP_EVENT          << PIDLoopTimer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(PIDLoopTimer_PWM_OUT_INVERT          << PIDLoopTimer_INV_OUT_SHIFT))         |\
         ((uint32)(PIDLoopTimer_PWM_OUT_N_INVERT        << PIDLoopTimer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(PIDLoopTimer_PWM_MODE                << PIDLoopTimer_MODE_SHIFT)))

#define PIDLoopTimer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(PIDLoopTimer_PWM_RUN_MODE         << PIDLoopTimer_ONESHOT_SHIFT))
            
#define PIDLoopTimer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(PIDLoopTimer_PWM_ALIGN            << PIDLoopTimer_UPDOWN_SHIFT))

#define PIDLoopTimer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(PIDLoopTimer_PWM_KILL_EVENT      << PIDLoopTimer_PWM_SYNC_KILL_SHIFT))

#define PIDLoopTimer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(PIDLoopTimer_PWM_DEAD_TIME_CYCLE  << PIDLoopTimer_PRESCALER_SHIFT))

#define PIDLoopTimer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(PIDLoopTimer_PWM_PRESCALER        << PIDLoopTimer_PRESCALER_SHIFT))

#define PIDLoopTimer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(PIDLoopTimer_TC_PRESCALER            << PIDLoopTimer_PRESCALER_SHIFT))       |\
         ((uint32)(PIDLoopTimer_TC_COUNTER_MODE         << PIDLoopTimer_UPDOWN_SHIFT))          |\
         ((uint32)(PIDLoopTimer_TC_RUN_MODE             << PIDLoopTimer_ONESHOT_SHIFT))         |\
         ((uint32)(PIDLoopTimer_TC_COMP_CAP_MODE        << PIDLoopTimer_MODE_SHIFT)))
        
#define PIDLoopTimer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(PIDLoopTimer_QUAD_PHIA_SIGNAL_MODE   << PIDLoopTimer_COUNT_SHIFT))           |\
         ((uint32)(PIDLoopTimer_QUAD_INDEX_SIGNAL_MODE  << PIDLoopTimer_RELOAD_SHIFT))          |\
         ((uint32)(PIDLoopTimer_QUAD_STOP_SIGNAL_MODE   << PIDLoopTimer_STOP_SHIFT))            |\
         ((uint32)(PIDLoopTimer_QUAD_PHIB_SIGNAL_MODE   << PIDLoopTimer_START_SHIFT)))

#define PIDLoopTimer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(PIDLoopTimer_PWM_SWITCH_SIGNAL_MODE  << PIDLoopTimer_CAPTURE_SHIFT))         |\
         ((uint32)(PIDLoopTimer_PWM_COUNT_SIGNAL_MODE   << PIDLoopTimer_COUNT_SHIFT))           |\
         ((uint32)(PIDLoopTimer_PWM_RELOAD_SIGNAL_MODE  << PIDLoopTimer_RELOAD_SHIFT))          |\
         ((uint32)(PIDLoopTimer_PWM_STOP_SIGNAL_MODE    << PIDLoopTimer_STOP_SHIFT))            |\
         ((uint32)(PIDLoopTimer_PWM_START_SIGNAL_MODE   << PIDLoopTimer_START_SHIFT)))

#define PIDLoopTimer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(PIDLoopTimer_TC_CAPTURE_SIGNAL_MODE  << PIDLoopTimer_CAPTURE_SHIFT))         |\
         ((uint32)(PIDLoopTimer_TC_COUNT_SIGNAL_MODE    << PIDLoopTimer_COUNT_SHIFT))           |\
         ((uint32)(PIDLoopTimer_TC_RELOAD_SIGNAL_MODE   << PIDLoopTimer_RELOAD_SHIFT))          |\
         ((uint32)(PIDLoopTimer_TC_STOP_SIGNAL_MODE     << PIDLoopTimer_STOP_SHIFT))            |\
         ((uint32)(PIDLoopTimer_TC_START_SIGNAL_MODE    << PIDLoopTimer_START_SHIFT)))
        
#define PIDLoopTimer_TIMER_UPDOWN_CNT_USED                                                          \
                ((PIDLoopTimer__COUNT_UPDOWN0 == PIDLoopTimer_TC_COUNTER_MODE)                  ||\
                 (PIDLoopTimer__COUNT_UPDOWN1 == PIDLoopTimer_TC_COUNTER_MODE))

#define PIDLoopTimer_PWM_UPDOWN_CNT_USED                                                            \
                ((PIDLoopTimer__CENTER == PIDLoopTimer_PWM_ALIGN)                               ||\
                 (PIDLoopTimer__ASYMMETRIC == PIDLoopTimer_PWM_ALIGN))               
        
#define PIDLoopTimer_PWM_PR_INIT_VALUE              (1u)
#define PIDLoopTimer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_PIDLoopTimer_H */

/* [] END OF FILE */
