/*******************************************************************************
* File Name: SerialDataTimer_PM.c
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

#include "SerialDataTimer.h"

static SerialDataTimer_BACKUP_STRUCT SerialDataTimer_backup;


/*******************************************************************************
* Function Name: SerialDataTimer_SaveConfig
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
void SerialDataTimer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: SerialDataTimer_Sleep
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
void SerialDataTimer_Sleep(void)
{
    if(0u != (SerialDataTimer_BLOCK_CONTROL_REG & SerialDataTimer_MASK))
    {
        SerialDataTimer_backup.enableState = 1u;
    }
    else
    {
        SerialDataTimer_backup.enableState = 0u;
    }

    SerialDataTimer_Stop();
    SerialDataTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: SerialDataTimer_RestoreConfig
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
void SerialDataTimer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: SerialDataTimer_Wakeup
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
void SerialDataTimer_Wakeup(void)
{
    SerialDataTimer_RestoreConfig();

    if(0u != SerialDataTimer_backup.enableState)
    {
        SerialDataTimer_Enable();
    }
}


/* [] END OF FILE */
