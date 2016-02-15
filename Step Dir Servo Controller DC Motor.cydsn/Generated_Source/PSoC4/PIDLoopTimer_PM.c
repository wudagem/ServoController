/*******************************************************************************
* File Name: PIDLoopTimer_PM.c
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

#include "PIDLoopTimer.h"

static PIDLoopTimer_BACKUP_STRUCT PIDLoopTimer_backup;


/*******************************************************************************
* Function Name: PIDLoopTimer_SaveConfig
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
void PIDLoopTimer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PIDLoopTimer_Sleep
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
void PIDLoopTimer_Sleep(void)
{
    if(0u != (PIDLoopTimer_BLOCK_CONTROL_REG & PIDLoopTimer_MASK))
    {
        PIDLoopTimer_backup.enableState = 1u;
    }
    else
    {
        PIDLoopTimer_backup.enableState = 0u;
    }

    PIDLoopTimer_Stop();
    PIDLoopTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: PIDLoopTimer_RestoreConfig
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
void PIDLoopTimer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PIDLoopTimer_Wakeup
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
void PIDLoopTimer_Wakeup(void)
{
    PIDLoopTimer_RestoreConfig();

    if(0u != PIDLoopTimer_backup.enableState)
    {
        PIDLoopTimer_Enable();
    }
}


/* [] END OF FILE */
