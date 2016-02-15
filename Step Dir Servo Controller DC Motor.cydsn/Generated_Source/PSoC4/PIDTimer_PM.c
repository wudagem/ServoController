/*******************************************************************************
* File Name: PIDTimer_PM.c
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

#include "PIDTimer.h"

static PIDTimer_BACKUP_STRUCT PIDTimer_backup;


/*******************************************************************************
* Function Name: PIDTimer_SaveConfig
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
void PIDTimer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PIDTimer_Sleep
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
void PIDTimer_Sleep(void)
{
    if(0u != (PIDTimer_BLOCK_CONTROL_REG & PIDTimer_MASK))
    {
        PIDTimer_backup.enableState = 1u;
    }
    else
    {
        PIDTimer_backup.enableState = 0u;
    }

    PIDTimer_Stop();
    PIDTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: PIDTimer_RestoreConfig
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
void PIDTimer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PIDTimer_Wakeup
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
void PIDTimer_Wakeup(void)
{
    PIDTimer_RestoreConfig();

    if(0u != PIDTimer_backup.enableState)
    {
        PIDTimer_Enable();
    }
}


/* [] END OF FILE */
