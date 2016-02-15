/*******************************************************************************
* File Name: MotorControlReg.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_MotorControlReg_H) /* CY_CONTROL_REG_MotorControlReg_H */
#define CY_CONTROL_REG_MotorControlReg_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} MotorControlReg_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    MotorControlReg_Write(uint8 control) ;
uint8   MotorControlReg_Read(void) ;

void MotorControlReg_SaveConfig(void) ;
void MotorControlReg_RestoreConfig(void) ;
void MotorControlReg_Sleep(void) ; 
void MotorControlReg_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define MotorControlReg_Control        (* (reg8 *) MotorControlReg_Sync_ctrl_reg__CONTROL_REG )
#define MotorControlReg_Control_PTR    (  (reg8 *) MotorControlReg_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_MotorControlReg_H */


/* [] END OF FILE */
