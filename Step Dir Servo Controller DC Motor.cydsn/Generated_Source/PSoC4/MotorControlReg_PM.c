/*******************************************************************************
* File Name: MotorControlReg_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "MotorControlReg.h"

/* Check for removal by optimization */
#if !defined(MotorControlReg_Sync_ctrl_reg__REMOVED)

static MotorControlReg_BACKUP_STRUCT  MotorControlReg_backup = {0u};

    
/*******************************************************************************
* Function Name: MotorControlReg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MotorControlReg_SaveConfig(void) 
{
    MotorControlReg_backup.controlState = MotorControlReg_Control;
}


/*******************************************************************************
* Function Name: MotorControlReg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void MotorControlReg_RestoreConfig(void) 
{
     MotorControlReg_Control = MotorControlReg_backup.controlState;
}


/*******************************************************************************
* Function Name: MotorControlReg_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MotorControlReg_Sleep(void) 
{
    MotorControlReg_SaveConfig();
}


/*******************************************************************************
* Function Name: MotorControlReg_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MotorControlReg_Wakeup(void)  
{
    MotorControlReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
