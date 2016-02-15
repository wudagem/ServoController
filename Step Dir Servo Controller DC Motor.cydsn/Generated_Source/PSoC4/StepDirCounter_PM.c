/*******************************************************************************
* File Name: StepDirCounter_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "StepDirCounter.h"

static StepDirCounter_backupStruct StepDirCounter_backup;


/*******************************************************************************
* Function Name: StepDirCounter_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  StepDirCounter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void StepDirCounter_SaveConfig(void) 
{
    #if (!StepDirCounter_UsingFixedFunction)

        StepDirCounter_backup.CounterUdb = StepDirCounter_ReadCounter();

        #if(!StepDirCounter_ControlRegRemoved)
            StepDirCounter_backup.CounterControlRegister = StepDirCounter_ReadControlRegister();
        #endif /* (!StepDirCounter_ControlRegRemoved) */

    #endif /* (!StepDirCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepDirCounter_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  StepDirCounter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void StepDirCounter_RestoreConfig(void) 
{      
    #if (!StepDirCounter_UsingFixedFunction)

       StepDirCounter_WriteCounter(StepDirCounter_backup.CounterUdb);

        #if(!StepDirCounter_ControlRegRemoved)
            StepDirCounter_WriteControlRegister(StepDirCounter_backup.CounterControlRegister);
        #endif /* (!StepDirCounter_ControlRegRemoved) */

    #endif /* (!StepDirCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepDirCounter_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  StepDirCounter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void StepDirCounter_Sleep(void) 
{
    #if(!StepDirCounter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(StepDirCounter_CTRL_ENABLE == (StepDirCounter_CONTROL & StepDirCounter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            StepDirCounter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            StepDirCounter_backup.CounterEnableState = 0u;
        }
    #else
        StepDirCounter_backup.CounterEnableState = 1u;
        if(StepDirCounter_backup.CounterEnableState != 0u)
        {
            StepDirCounter_backup.CounterEnableState = 0u;
        }
    #endif /* (!StepDirCounter_ControlRegRemoved) */
    
    StepDirCounter_Stop();
    StepDirCounter_SaveConfig();
}


/*******************************************************************************
* Function Name: StepDirCounter_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  StepDirCounter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void StepDirCounter_Wakeup(void) 
{
    StepDirCounter_RestoreConfig();
    #if(!StepDirCounter_ControlRegRemoved)
        if(StepDirCounter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            StepDirCounter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!StepDirCounter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
