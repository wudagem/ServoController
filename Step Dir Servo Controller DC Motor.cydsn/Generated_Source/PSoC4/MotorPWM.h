/*******************************************************************************
* File Name: MotorPWM.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the MotorPWM
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

#if !defined(CY_TCPWM_MotorPWM_H)
#define CY_TCPWM_MotorPWM_H


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
} MotorPWM_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  MotorPWM_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define MotorPWM_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define MotorPWM_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define MotorPWM_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define MotorPWM_QUAD_ENCODING_MODES            (0lu)
#define MotorPWM_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define MotorPWM_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define MotorPWM_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define MotorPWM_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define MotorPWM_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define MotorPWM_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define MotorPWM_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define MotorPWM_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define MotorPWM_TC_RUN_MODE                    (0lu)
#define MotorPWM_TC_COUNTER_MODE                (0lu)
#define MotorPWM_TC_COMP_CAP_MODE               (2lu)
#define MotorPWM_TC_PRESCALER                   (0lu)

/* Signal modes */
#define MotorPWM_TC_RELOAD_SIGNAL_MODE          (0lu)
#define MotorPWM_TC_COUNT_SIGNAL_MODE           (3lu)
#define MotorPWM_TC_START_SIGNAL_MODE           (0lu)
#define MotorPWM_TC_STOP_SIGNAL_MODE            (0lu)
#define MotorPWM_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define MotorPWM_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define MotorPWM_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define MotorPWM_TC_START_SIGNAL_PRESENT        (0lu)
#define MotorPWM_TC_STOP_SIGNAL_PRESENT         (0lu)
#define MotorPWM_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define MotorPWM_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define MotorPWM_PWM_KILL_EVENT                 (0lu)
#define MotorPWM_PWM_STOP_EVENT                 (0lu)
#define MotorPWM_PWM_MODE                       (4lu)
#define MotorPWM_PWM_OUT_N_INVERT               (0lu)
#define MotorPWM_PWM_OUT_INVERT                 (0lu)
#define MotorPWM_PWM_ALIGN                      (0lu)
#define MotorPWM_PWM_RUN_MODE                   (0lu)
#define MotorPWM_PWM_DEAD_TIME_CYCLE            (0lu)
#define MotorPWM_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define MotorPWM_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define MotorPWM_PWM_COUNT_SIGNAL_MODE          (3lu)
#define MotorPWM_PWM_START_SIGNAL_MODE          (0lu)
#define MotorPWM_PWM_STOP_SIGNAL_MODE           (0lu)
#define MotorPWM_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define MotorPWM_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define MotorPWM_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define MotorPWM_PWM_START_SIGNAL_PRESENT       (0lu)
#define MotorPWM_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define MotorPWM_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define MotorPWM_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define MotorPWM_TC_PERIOD_VALUE                (65535lu)
#define MotorPWM_TC_COMPARE_VALUE               (65535lu)
#define MotorPWM_TC_COMPARE_BUF_VALUE           (65535lu)
#define MotorPWM_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define MotorPWM_PWM_PERIOD_VALUE               (400lu)
#define MotorPWM_PWM_PERIOD_BUF_VALUE           (65535lu)
#define MotorPWM_PWM_PERIOD_SWAP                (0lu)
#define MotorPWM_PWM_COMPARE_VALUE              (200lu)
#define MotorPWM_PWM_COMPARE_BUF_VALUE          (65535lu)
#define MotorPWM_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define MotorPWM__LEFT 0
#define MotorPWM__RIGHT 1
#define MotorPWM__CENTER 2
#define MotorPWM__ASYMMETRIC 3

#define MotorPWM__X1 0
#define MotorPWM__X2 1
#define MotorPWM__X4 2

#define MotorPWM__PWM 4
#define MotorPWM__PWM_DT 5
#define MotorPWM__PWM_PR 6

#define MotorPWM__INVERSE 1
#define MotorPWM__DIRECT 0

#define MotorPWM__CAPTURE 2
#define MotorPWM__COMPARE 0

#define MotorPWM__TRIG_LEVEL 3
#define MotorPWM__TRIG_RISING 0
#define MotorPWM__TRIG_FALLING 1
#define MotorPWM__TRIG_BOTH 2

#define MotorPWM__INTR_MASK_TC 1
#define MotorPWM__INTR_MASK_CC_MATCH 2
#define MotorPWM__INTR_MASK_NONE 0
#define MotorPWM__INTR_MASK_TC_CC 3

#define MotorPWM__UNCONFIG 8
#define MotorPWM__TIMER 1
#define MotorPWM__QUAD 3
#define MotorPWM__PWM_SEL 7

#define MotorPWM__COUNT_UP 0
#define MotorPWM__COUNT_DOWN 1
#define MotorPWM__COUNT_UPDOWN0 2
#define MotorPWM__COUNT_UPDOWN1 3


/* Prescaler */
#define MotorPWM_PRESCALE_DIVBY1                ((uint32)(0u << MotorPWM_PRESCALER_SHIFT))
#define MotorPWM_PRESCALE_DIVBY2                ((uint32)(1u << MotorPWM_PRESCALER_SHIFT))
#define MotorPWM_PRESCALE_DIVBY4                ((uint32)(2u << MotorPWM_PRESCALER_SHIFT))
#define MotorPWM_PRESCALE_DIVBY8                ((uint32)(3u << MotorPWM_PRESCALER_SHIFT))
#define MotorPWM_PRESCALE_DIVBY16               ((uint32)(4u << MotorPWM_PRESCALER_SHIFT))
#define MotorPWM_PRESCALE_DIVBY32               ((uint32)(5u << MotorPWM_PRESCALER_SHIFT))
#define MotorPWM_PRESCALE_DIVBY64               ((uint32)(6u << MotorPWM_PRESCALER_SHIFT))
#define MotorPWM_PRESCALE_DIVBY128              ((uint32)(7u << MotorPWM_PRESCALER_SHIFT))

/* TCPWM set modes */
#define MotorPWM_MODE_TIMER_COMPARE             ((uint32)(MotorPWM__COMPARE         <<  \
                                                                  MotorPWM_MODE_SHIFT))
#define MotorPWM_MODE_TIMER_CAPTURE             ((uint32)(MotorPWM__CAPTURE         <<  \
                                                                  MotorPWM_MODE_SHIFT))
#define MotorPWM_MODE_QUAD                      ((uint32)(MotorPWM__QUAD            <<  \
                                                                  MotorPWM_MODE_SHIFT))
#define MotorPWM_MODE_PWM                       ((uint32)(MotorPWM__PWM             <<  \
                                                                  MotorPWM_MODE_SHIFT))
#define MotorPWM_MODE_PWM_DT                    ((uint32)(MotorPWM__PWM_DT          <<  \
                                                                  MotorPWM_MODE_SHIFT))
#define MotorPWM_MODE_PWM_PR                    ((uint32)(MotorPWM__PWM_PR          <<  \
                                                                  MotorPWM_MODE_SHIFT))

/* Quad Modes */
#define MotorPWM_MODE_X1                        ((uint32)(MotorPWM__X1              <<  \
                                                                  MotorPWM_QUAD_MODE_SHIFT))
#define MotorPWM_MODE_X2                        ((uint32)(MotorPWM__X2              <<  \
                                                                  MotorPWM_QUAD_MODE_SHIFT))
#define MotorPWM_MODE_X4                        ((uint32)(MotorPWM__X4              <<  \
                                                                  MotorPWM_QUAD_MODE_SHIFT))

/* Counter modes */
#define MotorPWM_COUNT_UP                       ((uint32)(MotorPWM__COUNT_UP        <<  \
                                                                  MotorPWM_UPDOWN_SHIFT))
#define MotorPWM_COUNT_DOWN                     ((uint32)(MotorPWM__COUNT_DOWN      <<  \
                                                                  MotorPWM_UPDOWN_SHIFT))
#define MotorPWM_COUNT_UPDOWN0                  ((uint32)(MotorPWM__COUNT_UPDOWN0   <<  \
                                                                  MotorPWM_UPDOWN_SHIFT))
#define MotorPWM_COUNT_UPDOWN1                  ((uint32)(MotorPWM__COUNT_UPDOWN1   <<  \
                                                                  MotorPWM_UPDOWN_SHIFT))

/* PWM output invert */
#define MotorPWM_INVERT_LINE                    ((uint32)(MotorPWM__INVERSE         <<  \
                                                                  MotorPWM_INV_OUT_SHIFT))
#define MotorPWM_INVERT_LINE_N                  ((uint32)(MotorPWM__INVERSE         <<  \
                                                                  MotorPWM_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define MotorPWM_TRIG_RISING                    ((uint32)MotorPWM__TRIG_RISING)
#define MotorPWM_TRIG_FALLING                   ((uint32)MotorPWM__TRIG_FALLING)
#define MotorPWM_TRIG_BOTH                      ((uint32)MotorPWM__TRIG_BOTH)
#define MotorPWM_TRIG_LEVEL                     ((uint32)MotorPWM__TRIG_LEVEL)

/* Interrupt mask */
#define MotorPWM_INTR_MASK_TC                   ((uint32)MotorPWM__INTR_MASK_TC)
#define MotorPWM_INTR_MASK_CC_MATCH             ((uint32)MotorPWM__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define MotorPWM_CC_MATCH_SET                   (0x00u)
#define MotorPWM_CC_MATCH_CLEAR                 (0x01u)
#define MotorPWM_CC_MATCH_INVERT                (0x02u)
#define MotorPWM_CC_MATCH_NO_CHANGE             (0x03u)
#define MotorPWM_OVERLOW_SET                    (0x00u)
#define MotorPWM_OVERLOW_CLEAR                  (0x04u)
#define MotorPWM_OVERLOW_INVERT                 (0x08u)
#define MotorPWM_OVERLOW_NO_CHANGE              (0x0Cu)
#define MotorPWM_UNDERFLOW_SET                  (0x00u)
#define MotorPWM_UNDERFLOW_CLEAR                (0x10u)
#define MotorPWM_UNDERFLOW_INVERT               (0x20u)
#define MotorPWM_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define MotorPWM_PWM_MODE_LEFT                  (MotorPWM_CC_MATCH_CLEAR        |   \
                                                         MotorPWM_OVERLOW_SET           |   \
                                                         MotorPWM_UNDERFLOW_NO_CHANGE)
#define MotorPWM_PWM_MODE_RIGHT                 (MotorPWM_CC_MATCH_SET          |   \
                                                         MotorPWM_OVERLOW_NO_CHANGE     |   \
                                                         MotorPWM_UNDERFLOW_CLEAR)
#define MotorPWM_PWM_MODE_ASYM                  (MotorPWM_CC_MATCH_INVERT       |   \
                                                         MotorPWM_OVERLOW_SET           |   \
                                                         MotorPWM_UNDERFLOW_CLEAR)

#if (MotorPWM_CY_TCPWM_V2)
    #if(MotorPWM_CY_TCPWM_4000)
        #define MotorPWM_PWM_MODE_CENTER                (MotorPWM_CC_MATCH_INVERT       |   \
                                                                 MotorPWM_OVERLOW_NO_CHANGE     |   \
                                                                 MotorPWM_UNDERFLOW_CLEAR)
    #else
        #define MotorPWM_PWM_MODE_CENTER                (MotorPWM_CC_MATCH_INVERT       |   \
                                                                 MotorPWM_OVERLOW_SET           |   \
                                                                 MotorPWM_UNDERFLOW_CLEAR)
    #endif /* (MotorPWM_CY_TCPWM_4000) */
#else
    #define MotorPWM_PWM_MODE_CENTER                (MotorPWM_CC_MATCH_INVERT       |   \
                                                             MotorPWM_OVERLOW_NO_CHANGE     |   \
                                                             MotorPWM_UNDERFLOW_CLEAR)
#endif /* (MotorPWM_CY_TCPWM_NEW) */

/* Command operations without condition */
#define MotorPWM_CMD_CAPTURE                    (0u)
#define MotorPWM_CMD_RELOAD                     (8u)
#define MotorPWM_CMD_STOP                       (16u)
#define MotorPWM_CMD_START                      (24u)

/* Status */
#define MotorPWM_STATUS_DOWN                    (1u)
#define MotorPWM_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   MotorPWM_Init(void);
void   MotorPWM_Enable(void);
void   MotorPWM_Start(void);
void   MotorPWM_Stop(void);

void   MotorPWM_SetMode(uint32 mode);
void   MotorPWM_SetCounterMode(uint32 counterMode);
void   MotorPWM_SetPWMMode(uint32 modeMask);
void   MotorPWM_SetQDMode(uint32 qdMode);

void   MotorPWM_SetPrescaler(uint32 prescaler);
void   MotorPWM_TriggerCommand(uint32 mask, uint32 command);
void   MotorPWM_SetOneShot(uint32 oneShotEnable);
uint32 MotorPWM_ReadStatus(void);

void   MotorPWM_SetPWMSyncKill(uint32 syncKillEnable);
void   MotorPWM_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   MotorPWM_SetPWMDeadTime(uint32 deadTime);
void   MotorPWM_SetPWMInvert(uint32 mask);

void   MotorPWM_SetInterruptMode(uint32 interruptMask);
uint32 MotorPWM_GetInterruptSourceMasked(void);
uint32 MotorPWM_GetInterruptSource(void);
void   MotorPWM_ClearInterrupt(uint32 interruptMask);
void   MotorPWM_SetInterrupt(uint32 interruptMask);

void   MotorPWM_WriteCounter(uint32 count);
uint32 MotorPWM_ReadCounter(void);

uint32 MotorPWM_ReadCapture(void);
uint32 MotorPWM_ReadCaptureBuf(void);

void   MotorPWM_WritePeriod(uint32 period);
uint32 MotorPWM_ReadPeriod(void);
void   MotorPWM_WritePeriodBuf(uint32 periodBuf);
uint32 MotorPWM_ReadPeriodBuf(void);

void   MotorPWM_WriteCompare(uint32 compare);
uint32 MotorPWM_ReadCompare(void);
void   MotorPWM_WriteCompareBuf(uint32 compareBuf);
uint32 MotorPWM_ReadCompareBuf(void);

void   MotorPWM_SetPeriodSwap(uint32 swapEnable);
void   MotorPWM_SetCompareSwap(uint32 swapEnable);

void   MotorPWM_SetCaptureMode(uint32 triggerMode);
void   MotorPWM_SetReloadMode(uint32 triggerMode);
void   MotorPWM_SetStartMode(uint32 triggerMode);
void   MotorPWM_SetStopMode(uint32 triggerMode);
void   MotorPWM_SetCountMode(uint32 triggerMode);

void   MotorPWM_SaveConfig(void);
void   MotorPWM_RestoreConfig(void);
void   MotorPWM_Sleep(void);
void   MotorPWM_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define MotorPWM_BLOCK_CONTROL_REG              (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define MotorPWM_BLOCK_CONTROL_PTR              ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define MotorPWM_COMMAND_REG                    (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define MotorPWM_COMMAND_PTR                    ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define MotorPWM_INTRRUPT_CAUSE_REG             (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define MotorPWM_INTRRUPT_CAUSE_PTR             ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define MotorPWM_CONTROL_REG                    (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__CTRL )
#define MotorPWM_CONTROL_PTR                    ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__CTRL )
#define MotorPWM_STATUS_REG                     (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__STATUS )
#define MotorPWM_STATUS_PTR                     ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__STATUS )
#define MotorPWM_COUNTER_REG                    (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__COUNTER )
#define MotorPWM_COUNTER_PTR                    ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__COUNTER )
#define MotorPWM_COMP_CAP_REG                   (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__CC )
#define MotorPWM_COMP_CAP_PTR                   ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__CC )
#define MotorPWM_COMP_CAP_BUF_REG               (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define MotorPWM_COMP_CAP_BUF_PTR               ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define MotorPWM_PERIOD_REG                     (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__PERIOD )
#define MotorPWM_PERIOD_PTR                     ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__PERIOD )
#define MotorPWM_PERIOD_BUF_REG                 (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define MotorPWM_PERIOD_BUF_PTR                 ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define MotorPWM_TRIG_CONTROL0_REG              (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define MotorPWM_TRIG_CONTROL0_PTR              ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define MotorPWM_TRIG_CONTROL1_REG              (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define MotorPWM_TRIG_CONTROL1_PTR              ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define MotorPWM_TRIG_CONTROL2_REG              (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define MotorPWM_TRIG_CONTROL2_PTR              ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define MotorPWM_INTERRUPT_REQ_REG              (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__INTR )
#define MotorPWM_INTERRUPT_REQ_PTR              ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__INTR )
#define MotorPWM_INTERRUPT_SET_REG              (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__INTR_SET )
#define MotorPWM_INTERRUPT_SET_PTR              ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__INTR_SET )
#define MotorPWM_INTERRUPT_MASK_REG             (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define MotorPWM_INTERRUPT_MASK_PTR             ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define MotorPWM_INTERRUPT_MASKED_REG           (*(reg32 *) MotorPWM_cy_m0s8_tcpwm_1__INTR_MASKED )
#define MotorPWM_INTERRUPT_MASKED_PTR           ( (reg32 *) MotorPWM_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define MotorPWM_MASK                           ((uint32)MotorPWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define MotorPWM_RELOAD_CC_SHIFT                (0u)
#define MotorPWM_RELOAD_PERIOD_SHIFT            (1u)
#define MotorPWM_PWM_SYNC_KILL_SHIFT            (2u)
#define MotorPWM_PWM_STOP_KILL_SHIFT            (3u)
#define MotorPWM_PRESCALER_SHIFT                (8u)
#define MotorPWM_UPDOWN_SHIFT                   (16u)
#define MotorPWM_ONESHOT_SHIFT                  (18u)
#define MotorPWM_QUAD_MODE_SHIFT                (20u)
#define MotorPWM_INV_OUT_SHIFT                  (20u)
#define MotorPWM_INV_COMPL_OUT_SHIFT            (21u)
#define MotorPWM_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define MotorPWM_RELOAD_CC_MASK                 ((uint32)(MotorPWM_1BIT_MASK        <<  \
                                                                            MotorPWM_RELOAD_CC_SHIFT))
#define MotorPWM_RELOAD_PERIOD_MASK             ((uint32)(MotorPWM_1BIT_MASK        <<  \
                                                                            MotorPWM_RELOAD_PERIOD_SHIFT))
#define MotorPWM_PWM_SYNC_KILL_MASK             ((uint32)(MotorPWM_1BIT_MASK        <<  \
                                                                            MotorPWM_PWM_SYNC_KILL_SHIFT))
#define MotorPWM_PWM_STOP_KILL_MASK             ((uint32)(MotorPWM_1BIT_MASK        <<  \
                                                                            MotorPWM_PWM_STOP_KILL_SHIFT))
#define MotorPWM_PRESCALER_MASK                 ((uint32)(MotorPWM_8BIT_MASK        <<  \
                                                                            MotorPWM_PRESCALER_SHIFT))
#define MotorPWM_UPDOWN_MASK                    ((uint32)(MotorPWM_2BIT_MASK        <<  \
                                                                            MotorPWM_UPDOWN_SHIFT))
#define MotorPWM_ONESHOT_MASK                   ((uint32)(MotorPWM_1BIT_MASK        <<  \
                                                                            MotorPWM_ONESHOT_SHIFT))
#define MotorPWM_QUAD_MODE_MASK                 ((uint32)(MotorPWM_3BIT_MASK        <<  \
                                                                            MotorPWM_QUAD_MODE_SHIFT))
#define MotorPWM_INV_OUT_MASK                   ((uint32)(MotorPWM_2BIT_MASK        <<  \
                                                                            MotorPWM_INV_OUT_SHIFT))
#define MotorPWM_MODE_MASK                      ((uint32)(MotorPWM_3BIT_MASK        <<  \
                                                                            MotorPWM_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define MotorPWM_CAPTURE_SHIFT                  (0u)
#define MotorPWM_COUNT_SHIFT                    (2u)
#define MotorPWM_RELOAD_SHIFT                   (4u)
#define MotorPWM_STOP_SHIFT                     (6u)
#define MotorPWM_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define MotorPWM_CAPTURE_MASK                   ((uint32)(MotorPWM_2BIT_MASK        <<  \
                                                                  MotorPWM_CAPTURE_SHIFT))
#define MotorPWM_COUNT_MASK                     ((uint32)(MotorPWM_2BIT_MASK        <<  \
                                                                  MotorPWM_COUNT_SHIFT))
#define MotorPWM_RELOAD_MASK                    ((uint32)(MotorPWM_2BIT_MASK        <<  \
                                                                  MotorPWM_RELOAD_SHIFT))
#define MotorPWM_STOP_MASK                      ((uint32)(MotorPWM_2BIT_MASK        <<  \
                                                                  MotorPWM_STOP_SHIFT))
#define MotorPWM_START_MASK                     ((uint32)(MotorPWM_2BIT_MASK        <<  \
                                                                  MotorPWM_START_SHIFT))

/* MASK */
#define MotorPWM_1BIT_MASK                      ((uint32)0x01u)
#define MotorPWM_2BIT_MASK                      ((uint32)0x03u)
#define MotorPWM_3BIT_MASK                      ((uint32)0x07u)
#define MotorPWM_6BIT_MASK                      ((uint32)0x3Fu)
#define MotorPWM_8BIT_MASK                      ((uint32)0xFFu)
#define MotorPWM_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define MotorPWM_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define MotorPWM_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(MotorPWM_QUAD_ENCODING_MODES     << MotorPWM_QUAD_MODE_SHIFT))       |\
         ((uint32)(MotorPWM_CONFIG                  << MotorPWM_MODE_SHIFT)))

#define MotorPWM_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(MotorPWM_PWM_STOP_EVENT          << MotorPWM_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(MotorPWM_PWM_OUT_INVERT          << MotorPWM_INV_OUT_SHIFT))         |\
         ((uint32)(MotorPWM_PWM_OUT_N_INVERT        << MotorPWM_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(MotorPWM_PWM_MODE                << MotorPWM_MODE_SHIFT)))

#define MotorPWM_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(MotorPWM_PWM_RUN_MODE         << MotorPWM_ONESHOT_SHIFT))
            
#define MotorPWM_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(MotorPWM_PWM_ALIGN            << MotorPWM_UPDOWN_SHIFT))

#define MotorPWM_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(MotorPWM_PWM_KILL_EVENT      << MotorPWM_PWM_SYNC_KILL_SHIFT))

#define MotorPWM_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(MotorPWM_PWM_DEAD_TIME_CYCLE  << MotorPWM_PRESCALER_SHIFT))

#define MotorPWM_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(MotorPWM_PWM_PRESCALER        << MotorPWM_PRESCALER_SHIFT))

#define MotorPWM_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(MotorPWM_TC_PRESCALER            << MotorPWM_PRESCALER_SHIFT))       |\
         ((uint32)(MotorPWM_TC_COUNTER_MODE         << MotorPWM_UPDOWN_SHIFT))          |\
         ((uint32)(MotorPWM_TC_RUN_MODE             << MotorPWM_ONESHOT_SHIFT))         |\
         ((uint32)(MotorPWM_TC_COMP_CAP_MODE        << MotorPWM_MODE_SHIFT)))
        
#define MotorPWM_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(MotorPWM_QUAD_PHIA_SIGNAL_MODE   << MotorPWM_COUNT_SHIFT))           |\
         ((uint32)(MotorPWM_QUAD_INDEX_SIGNAL_MODE  << MotorPWM_RELOAD_SHIFT))          |\
         ((uint32)(MotorPWM_QUAD_STOP_SIGNAL_MODE   << MotorPWM_STOP_SHIFT))            |\
         ((uint32)(MotorPWM_QUAD_PHIB_SIGNAL_MODE   << MotorPWM_START_SHIFT)))

#define MotorPWM_PWM_SIGNALS_MODES                                                              \
        (((uint32)(MotorPWM_PWM_SWITCH_SIGNAL_MODE  << MotorPWM_CAPTURE_SHIFT))         |\
         ((uint32)(MotorPWM_PWM_COUNT_SIGNAL_MODE   << MotorPWM_COUNT_SHIFT))           |\
         ((uint32)(MotorPWM_PWM_RELOAD_SIGNAL_MODE  << MotorPWM_RELOAD_SHIFT))          |\
         ((uint32)(MotorPWM_PWM_STOP_SIGNAL_MODE    << MotorPWM_STOP_SHIFT))            |\
         ((uint32)(MotorPWM_PWM_START_SIGNAL_MODE   << MotorPWM_START_SHIFT)))

#define MotorPWM_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(MotorPWM_TC_CAPTURE_SIGNAL_MODE  << MotorPWM_CAPTURE_SHIFT))         |\
         ((uint32)(MotorPWM_TC_COUNT_SIGNAL_MODE    << MotorPWM_COUNT_SHIFT))           |\
         ((uint32)(MotorPWM_TC_RELOAD_SIGNAL_MODE   << MotorPWM_RELOAD_SHIFT))          |\
         ((uint32)(MotorPWM_TC_STOP_SIGNAL_MODE     << MotorPWM_STOP_SHIFT))            |\
         ((uint32)(MotorPWM_TC_START_SIGNAL_MODE    << MotorPWM_START_SHIFT)))
        
#define MotorPWM_TIMER_UPDOWN_CNT_USED                                                          \
                ((MotorPWM__COUNT_UPDOWN0 == MotorPWM_TC_COUNTER_MODE)                  ||\
                 (MotorPWM__COUNT_UPDOWN1 == MotorPWM_TC_COUNTER_MODE))

#define MotorPWM_PWM_UPDOWN_CNT_USED                                                            \
                ((MotorPWM__CENTER == MotorPWM_PWM_ALIGN)                               ||\
                 (MotorPWM__ASYMMETRIC == MotorPWM_PWM_ALIGN))               
        
#define MotorPWM_PWM_PR_INIT_VALUE              (1u)
#define MotorPWM_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_MotorPWM_H */

/* [] END OF FILE */
