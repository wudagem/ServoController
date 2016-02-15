/*******************************************************************************
* File Name: MotorPWM_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
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

#include "MotorPWM.h"

static MotorPWM_BACKUP_STRUCT MotorPWM_backup;


/*******************************************************************************
* Function Name: MotorPWM_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MotorPWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: MotorPWM_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MotorPWM_Sleep(void)
{
    if(0u != (MotorPWM_BLOCK_CONTROL_REG & MotorPWM_MASK))
    {
        MotorPWM_backup.enableState = 1u;
    }
    else
    {
        MotorPWM_backup.enableState = 0u;
    }

    MotorPWM_Stop();
    MotorPWM_SaveConfig();
}


/*******************************************************************************
* Function Name: MotorPWM_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MotorPWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: MotorPWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MotorPWM_Wakeup(void)
{
    MotorPWM_RestoreConfig();

    if(0u != MotorPWM_backup.enableState)
    {
        MotorPWM_Enable();
    }
}


/* [] END OF FILE */
