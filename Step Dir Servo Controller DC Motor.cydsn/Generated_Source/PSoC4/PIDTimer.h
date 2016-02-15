/*******************************************************************************
* File Name: PIDTimer.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the PIDTimer
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

#if !defined(CY_TCPWM_PIDTimer_H)
#define CY_TCPWM_PIDTimer_H


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
} PIDTimer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  PIDTimer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define PIDTimer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define PIDTimer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define PIDTimer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define PIDTimer_QUAD_ENCODING_MODES            (0lu)
#define PIDTimer_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define PIDTimer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define PIDTimer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define PIDTimer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define PIDTimer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define PIDTimer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define PIDTimer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define PIDTimer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define PIDTimer_TC_RUN_MODE                    (0lu)
#define PIDTimer_TC_COUNTER_MODE                (0lu)
#define PIDTimer_TC_COMP_CAP_MODE               (2lu)
#define PIDTimer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define PIDTimer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define PIDTimer_TC_COUNT_SIGNAL_MODE           (3lu)
#define PIDTimer_TC_START_SIGNAL_MODE           (0lu)
#define PIDTimer_TC_STOP_SIGNAL_MODE            (0lu)
#define PIDTimer_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define PIDTimer_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define PIDTimer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define PIDTimer_TC_START_SIGNAL_PRESENT        (0lu)
#define PIDTimer_TC_STOP_SIGNAL_PRESENT         (0lu)
#define PIDTimer_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PIDTimer_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define PIDTimer_PWM_KILL_EVENT                 (0lu)
#define PIDTimer_PWM_STOP_EVENT                 (0lu)
#define PIDTimer_PWM_MODE                       (4lu)
#define PIDTimer_PWM_OUT_N_INVERT               (0lu)
#define PIDTimer_PWM_OUT_INVERT                 (0lu)
#define PIDTimer_PWM_ALIGN                      (0lu)
#define PIDTimer_PWM_RUN_MODE                   (0lu)
#define PIDTimer_PWM_DEAD_TIME_CYCLE            (0lu)
#define PIDTimer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define PIDTimer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define PIDTimer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define PIDTimer_PWM_START_SIGNAL_MODE          (0lu)
#define PIDTimer_PWM_STOP_SIGNAL_MODE           (0lu)
#define PIDTimer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define PIDTimer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define PIDTimer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define PIDTimer_PWM_START_SIGNAL_PRESENT       (0lu)
#define PIDTimer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define PIDTimer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PIDTimer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define PIDTimer_TC_PERIOD_VALUE                (4800lu)
#define PIDTimer_TC_COMPARE_VALUE               (65535lu)
#define PIDTimer_TC_COMPARE_BUF_VALUE           (65535lu)
#define PIDTimer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define PIDTimer_PWM_PERIOD_VALUE               (65535lu)
#define PIDTimer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define PIDTimer_PWM_PERIOD_SWAP                (0lu)
#define PIDTimer_PWM_COMPARE_VALUE              (65535lu)
#define PIDTimer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define PIDTimer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define PIDTimer__LEFT 0
#define PIDTimer__RIGHT 1
#define PIDTimer__CENTER 2
#define PIDTimer__ASYMMETRIC 3

#define PIDTimer__X1 0
#define PIDTimer__X2 1
#define PIDTimer__X4 2

#define PIDTimer__PWM 4
#define PIDTimer__PWM_DT 5
#define PIDTimer__PWM_PR 6

#define PIDTimer__INVERSE 1
#define PIDTimer__DIRECT 0

#define PIDTimer__CAPTURE 2
#define PIDTimer__COMPARE 0

#define PIDTimer__TRIG_LEVEL 3
#define PIDTimer__TRIG_RISING 0
#define PIDTimer__TRIG_FALLING 1
#define PIDTimer__TRIG_BOTH 2

#define PIDTimer__INTR_MASK_TC 1
#define PIDTimer__INTR_MASK_CC_MATCH 2
#define PIDTimer__INTR_MASK_NONE 0
#define PIDTimer__INTR_MASK_TC_CC 3

#define PIDTimer__UNCONFIG 8
#define PIDTimer__TIMER 1
#define PIDTimer__QUAD 3
#define PIDTimer__PWM_SEL 7

#define PIDTimer__COUNT_UP 0
#define PIDTimer__COUNT_DOWN 1
#define PIDTimer__COUNT_UPDOWN0 2
#define PIDTimer__COUNT_UPDOWN1 3


/* Prescaler */
#define PIDTimer_PRESCALE_DIVBY1                ((uint32)(0u << PIDTimer_PRESCALER_SHIFT))
#define PIDTimer_PRESCALE_DIVBY2                ((uint32)(1u << PIDTimer_PRESCALER_SHIFT))
#define PIDTimer_PRESCALE_DIVBY4                ((uint32)(2u << PIDTimer_PRESCALER_SHIFT))
#define PIDTimer_PRESCALE_DIVBY8                ((uint32)(3u << PIDTimer_PRESCALER_SHIFT))
#define PIDTimer_PRESCALE_DIVBY16               ((uint32)(4u << PIDTimer_PRESCALER_SHIFT))
#define PIDTimer_PRESCALE_DIVBY32               ((uint32)(5u << PIDTimer_PRESCALER_SHIFT))
#define PIDTimer_PRESCALE_DIVBY64               ((uint32)(6u << PIDTimer_PRESCALER_SHIFT))
#define PIDTimer_PRESCALE_DIVBY128              ((uint32)(7u << PIDTimer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define PIDTimer_MODE_TIMER_COMPARE             ((uint32)(PIDTimer__COMPARE         <<  \
                                                                  PIDTimer_MODE_SHIFT))
#define PIDTimer_MODE_TIMER_CAPTURE             ((uint32)(PIDTimer__CAPTURE         <<  \
                                                                  PIDTimer_MODE_SHIFT))
#define PIDTimer_MODE_QUAD                      ((uint32)(PIDTimer__QUAD            <<  \
                                                                  PIDTimer_MODE_SHIFT))
#define PIDTimer_MODE_PWM                       ((uint32)(PIDTimer__PWM             <<  \
                                                                  PIDTimer_MODE_SHIFT))
#define PIDTimer_MODE_PWM_DT                    ((uint32)(PIDTimer__PWM_DT          <<  \
                                                                  PIDTimer_MODE_SHIFT))
#define PIDTimer_MODE_PWM_PR                    ((uint32)(PIDTimer__PWM_PR          <<  \
                                                                  PIDTimer_MODE_SHIFT))

/* Quad Modes */
#define PIDTimer_MODE_X1                        ((uint32)(PIDTimer__X1              <<  \
                                                                  PIDTimer_QUAD_MODE_SHIFT))
#define PIDTimer_MODE_X2                        ((uint32)(PIDTimer__X2              <<  \
                                                                  PIDTimer_QUAD_MODE_SHIFT))
#define PIDTimer_MODE_X4                        ((uint32)(PIDTimer__X4              <<  \
                                                                  PIDTimer_QUAD_MODE_SHIFT))

/* Counter modes */
#define PIDTimer_COUNT_UP                       ((uint32)(PIDTimer__COUNT_UP        <<  \
                                                                  PIDTimer_UPDOWN_SHIFT))
#define PIDTimer_COUNT_DOWN                     ((uint32)(PIDTimer__COUNT_DOWN      <<  \
                                                                  PIDTimer_UPDOWN_SHIFT))
#define PIDTimer_COUNT_UPDOWN0                  ((uint32)(PIDTimer__COUNT_UPDOWN0   <<  \
                                                                  PIDTimer_UPDOWN_SHIFT))
#define PIDTimer_COUNT_UPDOWN1                  ((uint32)(PIDTimer__COUNT_UPDOWN1   <<  \
                                                                  PIDTimer_UPDOWN_SHIFT))

/* PWM output invert */
#define PIDTimer_INVERT_LINE                    ((uint32)(PIDTimer__INVERSE         <<  \
                                                                  PIDTimer_INV_OUT_SHIFT))
#define PIDTimer_INVERT_LINE_N                  ((uint32)(PIDTimer__INVERSE         <<  \
                                                                  PIDTimer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define PIDTimer_TRIG_RISING                    ((uint32)PIDTimer__TRIG_RISING)
#define PIDTimer_TRIG_FALLING                   ((uint32)PIDTimer__TRIG_FALLING)
#define PIDTimer_TRIG_BOTH                      ((uint32)PIDTimer__TRIG_BOTH)
#define PIDTimer_TRIG_LEVEL                     ((uint32)PIDTimer__TRIG_LEVEL)

/* Interrupt mask */
#define PIDTimer_INTR_MASK_TC                   ((uint32)PIDTimer__INTR_MASK_TC)
#define PIDTimer_INTR_MASK_CC_MATCH             ((uint32)PIDTimer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define PIDTimer_CC_MATCH_SET                   (0x00u)
#define PIDTimer_CC_MATCH_CLEAR                 (0x01u)
#define PIDTimer_CC_MATCH_INVERT                (0x02u)
#define PIDTimer_CC_MATCH_NO_CHANGE             (0x03u)
#define PIDTimer_OVERLOW_SET                    (0x00u)
#define PIDTimer_OVERLOW_CLEAR                  (0x04u)
#define PIDTimer_OVERLOW_INVERT                 (0x08u)
#define PIDTimer_OVERLOW_NO_CHANGE              (0x0Cu)
#define PIDTimer_UNDERFLOW_SET                  (0x00u)
#define PIDTimer_UNDERFLOW_CLEAR                (0x10u)
#define PIDTimer_UNDERFLOW_INVERT               (0x20u)
#define PIDTimer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define PIDTimer_PWM_MODE_LEFT                  (PIDTimer_CC_MATCH_CLEAR        |   \
                                                         PIDTimer_OVERLOW_SET           |   \
                                                         PIDTimer_UNDERFLOW_NO_CHANGE)
#define PIDTimer_PWM_MODE_RIGHT                 (PIDTimer_CC_MATCH_SET          |   \
                                                         PIDTimer_OVERLOW_NO_CHANGE     |   \
                                                         PIDTimer_UNDERFLOW_CLEAR)
#define PIDTimer_PWM_MODE_ASYM                  (PIDTimer_CC_MATCH_INVERT       |   \
                                                         PIDTimer_OVERLOW_SET           |   \
                                                         PIDTimer_UNDERFLOW_CLEAR)

#if (PIDTimer_CY_TCPWM_V2)
    #if(PIDTimer_CY_TCPWM_4000)
        #define PIDTimer_PWM_MODE_CENTER                (PIDTimer_CC_MATCH_INVERT       |   \
                                                                 PIDTimer_OVERLOW_NO_CHANGE     |   \
                                                                 PIDTimer_UNDERFLOW_CLEAR)
    #else
        #define PIDTimer_PWM_MODE_CENTER                (PIDTimer_CC_MATCH_INVERT       |   \
                                                                 PIDTimer_OVERLOW_SET           |   \
                                                                 PIDTimer_UNDERFLOW_CLEAR)
    #endif /* (PIDTimer_CY_TCPWM_4000) */
#else
    #define PIDTimer_PWM_MODE_CENTER                (PIDTimer_CC_MATCH_INVERT       |   \
                                                             PIDTimer_OVERLOW_NO_CHANGE     |   \
                                                             PIDTimer_UNDERFLOW_CLEAR)
#endif /* (PIDTimer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define PIDTimer_CMD_CAPTURE                    (0u)
#define PIDTimer_CMD_RELOAD                     (8u)
#define PIDTimer_CMD_STOP                       (16u)
#define PIDTimer_CMD_START                      (24u)

/* Status */
#define PIDTimer_STATUS_DOWN                    (1u)
#define PIDTimer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   PIDTimer_Init(void);
void   PIDTimer_Enable(void);
void   PIDTimer_Start(void);
void   PIDTimer_Stop(void);

void   PIDTimer_SetMode(uint32 mode);
void   PIDTimer_SetCounterMode(uint32 counterMode);
void   PIDTimer_SetPWMMode(uint32 modeMask);
void   PIDTimer_SetQDMode(uint32 qdMode);

void   PIDTimer_SetPrescaler(uint32 prescaler);
void   PIDTimer_TriggerCommand(uint32 mask, uint32 command);
void   PIDTimer_SetOneShot(uint32 oneShotEnable);
uint32 PIDTimer_ReadStatus(void);

void   PIDTimer_SetPWMSyncKill(uint32 syncKillEnable);
void   PIDTimer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   PIDTimer_SetPWMDeadTime(uint32 deadTime);
void   PIDTimer_SetPWMInvert(uint32 mask);

void   PIDTimer_SetInterruptMode(uint32 interruptMask);
uint32 PIDTimer_GetInterruptSourceMasked(void);
uint32 PIDTimer_GetInterruptSource(void);
void   PIDTimer_ClearInterrupt(uint32 interruptMask);
void   PIDTimer_SetInterrupt(uint32 interruptMask);

void   PIDTimer_WriteCounter(uint32 count);
uint32 PIDTimer_ReadCounter(void);

uint32 PIDTimer_ReadCapture(void);
uint32 PIDTimer_ReadCaptureBuf(void);

void   PIDTimer_WritePeriod(uint32 period);
uint32 PIDTimer_ReadPeriod(void);
void   PIDTimer_WritePeriodBuf(uint32 periodBuf);
uint32 PIDTimer_ReadPeriodBuf(void);

void   PIDTimer_WriteCompare(uint32 compare);
uint32 PIDTimer_ReadCompare(void);
void   PIDTimer_WriteCompareBuf(uint32 compareBuf);
uint32 PIDTimer_ReadCompareBuf(void);

void   PIDTimer_SetPeriodSwap(uint32 swapEnable);
void   PIDTimer_SetCompareSwap(uint32 swapEnable);

void   PIDTimer_SetCaptureMode(uint32 triggerMode);
void   PIDTimer_SetReloadMode(uint32 triggerMode);
void   PIDTimer_SetStartMode(uint32 triggerMode);
void   PIDTimer_SetStopMode(uint32 triggerMode);
void   PIDTimer_SetCountMode(uint32 triggerMode);

void   PIDTimer_SaveConfig(void);
void   PIDTimer_RestoreConfig(void);
void   PIDTimer_Sleep(void);
void   PIDTimer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define PIDTimer_BLOCK_CONTROL_REG              (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PIDTimer_BLOCK_CONTROL_PTR              ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PIDTimer_COMMAND_REG                    (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PIDTimer_COMMAND_PTR                    ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PIDTimer_INTRRUPT_CAUSE_REG             (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PIDTimer_INTRRUPT_CAUSE_PTR             ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PIDTimer_CONTROL_REG                    (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__CTRL )
#define PIDTimer_CONTROL_PTR                    ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__CTRL )
#define PIDTimer_STATUS_REG                     (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__STATUS )
#define PIDTimer_STATUS_PTR                     ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__STATUS )
#define PIDTimer_COUNTER_REG                    (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__COUNTER )
#define PIDTimer_COUNTER_PTR                    ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__COUNTER )
#define PIDTimer_COMP_CAP_REG                   (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__CC )
#define PIDTimer_COMP_CAP_PTR                   ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__CC )
#define PIDTimer_COMP_CAP_BUF_REG               (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define PIDTimer_COMP_CAP_BUF_PTR               ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define PIDTimer_PERIOD_REG                     (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__PERIOD )
#define PIDTimer_PERIOD_PTR                     ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__PERIOD )
#define PIDTimer_PERIOD_BUF_REG                 (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PIDTimer_PERIOD_BUF_PTR                 ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PIDTimer_TRIG_CONTROL0_REG              (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PIDTimer_TRIG_CONTROL0_PTR              ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PIDTimer_TRIG_CONTROL1_REG              (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PIDTimer_TRIG_CONTROL1_PTR              ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PIDTimer_TRIG_CONTROL2_REG              (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PIDTimer_TRIG_CONTROL2_PTR              ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PIDTimer_INTERRUPT_REQ_REG              (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__INTR )
#define PIDTimer_INTERRUPT_REQ_PTR              ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__INTR )
#define PIDTimer_INTERRUPT_SET_REG              (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define PIDTimer_INTERRUPT_SET_PTR              ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define PIDTimer_INTERRUPT_MASK_REG             (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define PIDTimer_INTERRUPT_MASK_PTR             ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define PIDTimer_INTERRUPT_MASKED_REG           (*(reg32 *) PIDTimer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define PIDTimer_INTERRUPT_MASKED_PTR           ( (reg32 *) PIDTimer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define PIDTimer_MASK                           ((uint32)PIDTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define PIDTimer_RELOAD_CC_SHIFT                (0u)
#define PIDTimer_RELOAD_PERIOD_SHIFT            (1u)
#define PIDTimer_PWM_SYNC_KILL_SHIFT            (2u)
#define PIDTimer_PWM_STOP_KILL_SHIFT            (3u)
#define PIDTimer_PRESCALER_SHIFT                (8u)
#define PIDTimer_UPDOWN_SHIFT                   (16u)
#define PIDTimer_ONESHOT_SHIFT                  (18u)
#define PIDTimer_QUAD_MODE_SHIFT                (20u)
#define PIDTimer_INV_OUT_SHIFT                  (20u)
#define PIDTimer_INV_COMPL_OUT_SHIFT            (21u)
#define PIDTimer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define PIDTimer_RELOAD_CC_MASK                 ((uint32)(PIDTimer_1BIT_MASK        <<  \
                                                                            PIDTimer_RELOAD_CC_SHIFT))
#define PIDTimer_RELOAD_PERIOD_MASK             ((uint32)(PIDTimer_1BIT_MASK        <<  \
                                                                            PIDTimer_RELOAD_PERIOD_SHIFT))
#define PIDTimer_PWM_SYNC_KILL_MASK             ((uint32)(PIDTimer_1BIT_MASK        <<  \
                                                                            PIDTimer_PWM_SYNC_KILL_SHIFT))
#define PIDTimer_PWM_STOP_KILL_MASK             ((uint32)(PIDTimer_1BIT_MASK        <<  \
                                                                            PIDTimer_PWM_STOP_KILL_SHIFT))
#define PIDTimer_PRESCALER_MASK                 ((uint32)(PIDTimer_8BIT_MASK        <<  \
                                                                            PIDTimer_PRESCALER_SHIFT))
#define PIDTimer_UPDOWN_MASK                    ((uint32)(PIDTimer_2BIT_MASK        <<  \
                                                                            PIDTimer_UPDOWN_SHIFT))
#define PIDTimer_ONESHOT_MASK                   ((uint32)(PIDTimer_1BIT_MASK        <<  \
                                                                            PIDTimer_ONESHOT_SHIFT))
#define PIDTimer_QUAD_MODE_MASK                 ((uint32)(PIDTimer_3BIT_MASK        <<  \
                                                                            PIDTimer_QUAD_MODE_SHIFT))
#define PIDTimer_INV_OUT_MASK                   ((uint32)(PIDTimer_2BIT_MASK        <<  \
                                                                            PIDTimer_INV_OUT_SHIFT))
#define PIDTimer_MODE_MASK                      ((uint32)(PIDTimer_3BIT_MASK        <<  \
                                                                            PIDTimer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define PIDTimer_CAPTURE_SHIFT                  (0u)
#define PIDTimer_COUNT_SHIFT                    (2u)
#define PIDTimer_RELOAD_SHIFT                   (4u)
#define PIDTimer_STOP_SHIFT                     (6u)
#define PIDTimer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define PIDTimer_CAPTURE_MASK                   ((uint32)(PIDTimer_2BIT_MASK        <<  \
                                                                  PIDTimer_CAPTURE_SHIFT))
#define PIDTimer_COUNT_MASK                     ((uint32)(PIDTimer_2BIT_MASK        <<  \
                                                                  PIDTimer_COUNT_SHIFT))
#define PIDTimer_RELOAD_MASK                    ((uint32)(PIDTimer_2BIT_MASK        <<  \
                                                                  PIDTimer_RELOAD_SHIFT))
#define PIDTimer_STOP_MASK                      ((uint32)(PIDTimer_2BIT_MASK        <<  \
                                                                  PIDTimer_STOP_SHIFT))
#define PIDTimer_START_MASK                     ((uint32)(PIDTimer_2BIT_MASK        <<  \
                                                                  PIDTimer_START_SHIFT))

/* MASK */
#define PIDTimer_1BIT_MASK                      ((uint32)0x01u)
#define PIDTimer_2BIT_MASK                      ((uint32)0x03u)
#define PIDTimer_3BIT_MASK                      ((uint32)0x07u)
#define PIDTimer_6BIT_MASK                      ((uint32)0x3Fu)
#define PIDTimer_8BIT_MASK                      ((uint32)0xFFu)
#define PIDTimer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define PIDTimer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define PIDTimer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(PIDTimer_QUAD_ENCODING_MODES     << PIDTimer_QUAD_MODE_SHIFT))       |\
         ((uint32)(PIDTimer_CONFIG                  << PIDTimer_MODE_SHIFT)))

#define PIDTimer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(PIDTimer_PWM_STOP_EVENT          << PIDTimer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(PIDTimer_PWM_OUT_INVERT          << PIDTimer_INV_OUT_SHIFT))         |\
         ((uint32)(PIDTimer_PWM_OUT_N_INVERT        << PIDTimer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(PIDTimer_PWM_MODE                << PIDTimer_MODE_SHIFT)))

#define PIDTimer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(PIDTimer_PWM_RUN_MODE         << PIDTimer_ONESHOT_SHIFT))
            
#define PIDTimer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(PIDTimer_PWM_ALIGN            << PIDTimer_UPDOWN_SHIFT))

#define PIDTimer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(PIDTimer_PWM_KILL_EVENT      << PIDTimer_PWM_SYNC_KILL_SHIFT))

#define PIDTimer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(PIDTimer_PWM_DEAD_TIME_CYCLE  << PIDTimer_PRESCALER_SHIFT))

#define PIDTimer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(PIDTimer_PWM_PRESCALER        << PIDTimer_PRESCALER_SHIFT))

#define PIDTimer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(PIDTimer_TC_PRESCALER            << PIDTimer_PRESCALER_SHIFT))       |\
         ((uint32)(PIDTimer_TC_COUNTER_MODE         << PIDTimer_UPDOWN_SHIFT))          |\
         ((uint32)(PIDTimer_TC_RUN_MODE             << PIDTimer_ONESHOT_SHIFT))         |\
         ((uint32)(PIDTimer_TC_COMP_CAP_MODE        << PIDTimer_MODE_SHIFT)))
        
#define PIDTimer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(PIDTimer_QUAD_PHIA_SIGNAL_MODE   << PIDTimer_COUNT_SHIFT))           |\
         ((uint32)(PIDTimer_QUAD_INDEX_SIGNAL_MODE  << PIDTimer_RELOAD_SHIFT))          |\
         ((uint32)(PIDTimer_QUAD_STOP_SIGNAL_MODE   << PIDTimer_STOP_SHIFT))            |\
         ((uint32)(PIDTimer_QUAD_PHIB_SIGNAL_MODE   << PIDTimer_START_SHIFT)))

#define PIDTimer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(PIDTimer_PWM_SWITCH_SIGNAL_MODE  << PIDTimer_CAPTURE_SHIFT))         |\
         ((uint32)(PIDTimer_PWM_COUNT_SIGNAL_MODE   << PIDTimer_COUNT_SHIFT))           |\
         ((uint32)(PIDTimer_PWM_RELOAD_SIGNAL_MODE  << PIDTimer_RELOAD_SHIFT))          |\
         ((uint32)(PIDTimer_PWM_STOP_SIGNAL_MODE    << PIDTimer_STOP_SHIFT))            |\
         ((uint32)(PIDTimer_PWM_START_SIGNAL_MODE   << PIDTimer_START_SHIFT)))

#define PIDTimer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(PIDTimer_TC_CAPTURE_SIGNAL_MODE  << PIDTimer_CAPTURE_SHIFT))         |\
         ((uint32)(PIDTimer_TC_COUNT_SIGNAL_MODE    << PIDTimer_COUNT_SHIFT))           |\
         ((uint32)(PIDTimer_TC_RELOAD_SIGNAL_MODE   << PIDTimer_RELOAD_SHIFT))          |\
         ((uint32)(PIDTimer_TC_STOP_SIGNAL_MODE     << PIDTimer_STOP_SHIFT))            |\
         ((uint32)(PIDTimer_TC_START_SIGNAL_MODE    << PIDTimer_START_SHIFT)))
        
#define PIDTimer_TIMER_UPDOWN_CNT_USED                                                          \
                ((PIDTimer__COUNT_UPDOWN0 == PIDTimer_TC_COUNTER_MODE)                  ||\
                 (PIDTimer__COUNT_UPDOWN1 == PIDTimer_TC_COUNTER_MODE))

#define PIDTimer_PWM_UPDOWN_CNT_USED                                                            \
                ((PIDTimer__CENTER == PIDTimer_PWM_ALIGN)                               ||\
                 (PIDTimer__ASYMMETRIC == PIDTimer_PWM_ALIGN))               
        
#define PIDTimer_PWM_PR_INIT_VALUE              (1u)
#define PIDTimer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_PIDTimer_H */

/* [] END OF FILE */
