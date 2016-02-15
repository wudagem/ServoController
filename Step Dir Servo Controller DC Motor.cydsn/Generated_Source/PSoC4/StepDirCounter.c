/*******************************************************************************
* File Name: StepDirCounter.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
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

uint8 StepDirCounter_initVar = 0u;


/*******************************************************************************
* Function Name: StepDirCounter_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void StepDirCounter_Init(void) 
{
        #if (!StepDirCounter_UsingFixedFunction && !StepDirCounter_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!StepDirCounter_UsingFixedFunction && !StepDirCounter_ControlRegRemoved) */
        
        #if(!StepDirCounter_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 StepDirCounter_interruptState;
        #endif /* (!StepDirCounter_UsingFixedFunction) */
        
        #if (StepDirCounter_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            StepDirCounter_CONTROL &= StepDirCounter_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                StepDirCounter_CONTROL2 &= ((uint8)(~StepDirCounter_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                StepDirCounter_CONTROL3 &= ((uint8)(~StepDirCounter_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (StepDirCounter_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                StepDirCounter_CONTROL |= StepDirCounter_ONESHOT;
            #endif /* (StepDirCounter_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            StepDirCounter_CONTROL2 |= StepDirCounter_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            StepDirCounter_RT1 &= ((uint8)(~StepDirCounter_RT1_MASK));
            StepDirCounter_RT1 |= StepDirCounter_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            StepDirCounter_RT1 &= ((uint8)(~StepDirCounter_SYNCDSI_MASK));
            StepDirCounter_RT1 |= StepDirCounter_SYNCDSI_EN;

        #else
            #if(!StepDirCounter_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = StepDirCounter_CONTROL & ((uint8)(~StepDirCounter_CTRL_CMPMODE_MASK));
            StepDirCounter_CONTROL = ctrl | StepDirCounter_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = StepDirCounter_CONTROL & ((uint8)(~StepDirCounter_CTRL_CAPMODE_MASK));
            
            #if( 0 != StepDirCounter_CAPTURE_MODE_CONF)
                StepDirCounter_CONTROL = ctrl | StepDirCounter_DEFAULT_CAPTURE_MODE;
            #else
                StepDirCounter_CONTROL = ctrl;
            #endif /* 0 != StepDirCounter_CAPTURE_MODE */ 
            
            #endif /* (!StepDirCounter_ControlRegRemoved) */
        #endif /* (StepDirCounter_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!StepDirCounter_UsingFixedFunction)
            StepDirCounter_ClearFIFO();
        #endif /* (!StepDirCounter_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        StepDirCounter_WritePeriod(StepDirCounter_INIT_PERIOD_VALUE);
        #if (!(StepDirCounter_UsingFixedFunction && (CY_PSOC5A)))
            StepDirCounter_WriteCounter(StepDirCounter_INIT_COUNTER_VALUE);
        #endif /* (!(StepDirCounter_UsingFixedFunction && (CY_PSOC5A))) */
        StepDirCounter_SetInterruptMode(StepDirCounter_INIT_INTERRUPTS_MASK);
        
        #if (!StepDirCounter_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)StepDirCounter_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            StepDirCounter_WriteCompare(StepDirCounter_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            StepDirCounter_interruptState = CyEnterCriticalSection();
            
            StepDirCounter_STATUS_AUX_CTRL |= StepDirCounter_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(StepDirCounter_interruptState);
            
        #endif /* (!StepDirCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepDirCounter_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void StepDirCounter_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (StepDirCounter_UsingFixedFunction)
        StepDirCounter_GLOBAL_ENABLE |= StepDirCounter_BLOCK_EN_MASK;
        StepDirCounter_GLOBAL_STBY_ENABLE |= StepDirCounter_BLOCK_STBY_EN_MASK;
    #endif /* (StepDirCounter_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!StepDirCounter_ControlRegRemoved || StepDirCounter_UsingFixedFunction)
        StepDirCounter_CONTROL |= StepDirCounter_CTRL_ENABLE;                
    #endif /* (!StepDirCounter_ControlRegRemoved || StepDirCounter_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: StepDirCounter_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  StepDirCounter_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void StepDirCounter_Start(void) 
{
    if(StepDirCounter_initVar == 0u)
    {
        StepDirCounter_Init();
        
        StepDirCounter_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    StepDirCounter_Enable();        
}


/*******************************************************************************
* Function Name: StepDirCounter_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void StepDirCounter_Stop(void) 
{
    /* Disable Counter */
    #if(!StepDirCounter_ControlRegRemoved || StepDirCounter_UsingFixedFunction)
        StepDirCounter_CONTROL &= ((uint8)(~StepDirCounter_CTRL_ENABLE));        
    #endif /* (!StepDirCounter_ControlRegRemoved || StepDirCounter_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (StepDirCounter_UsingFixedFunction)
        StepDirCounter_GLOBAL_ENABLE &= ((uint8)(~StepDirCounter_BLOCK_EN_MASK));
        StepDirCounter_GLOBAL_STBY_ENABLE &= ((uint8)(~StepDirCounter_BLOCK_STBY_EN_MASK));
    #endif /* (StepDirCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepDirCounter_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void StepDirCounter_SetInterruptMode(uint8 interruptsMask) 
{
    StepDirCounter_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: StepDirCounter_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   StepDirCounter_ReadStatusRegister(void) 
{
    return StepDirCounter_STATUS;
}


#if(!StepDirCounter_ControlRegRemoved)
/*******************************************************************************
* Function Name: StepDirCounter_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   StepDirCounter_ReadControlRegister(void) 
{
    return StepDirCounter_CONTROL;
}


/*******************************************************************************
* Function Name: StepDirCounter_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    StepDirCounter_WriteControlRegister(uint8 control) 
{
    StepDirCounter_CONTROL = control;
}

#endif  /* (!StepDirCounter_ControlRegRemoved) */


#if (!(StepDirCounter_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: StepDirCounter_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void StepDirCounter_WriteCounter(uint16 counter) \
                                   
{
    #if(StepDirCounter_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (StepDirCounter_GLOBAL_ENABLE & StepDirCounter_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        StepDirCounter_GLOBAL_ENABLE |= StepDirCounter_BLOCK_EN_MASK;
        CY_SET_REG16(StepDirCounter_COUNTER_LSB_PTR, (uint16)counter);
        StepDirCounter_GLOBAL_ENABLE &= ((uint8)(~StepDirCounter_BLOCK_EN_MASK));
    #else
        CY_SET_REG16(StepDirCounter_COUNTER_LSB_PTR, counter);
    #endif /* (StepDirCounter_UsingFixedFunction) */
}
#endif /* (!(StepDirCounter_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: StepDirCounter_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) The present value of the counter.
*
*******************************************************************************/
uint16 StepDirCounter_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(StepDirCounter_UsingFixedFunction)
		(void)CY_GET_REG16(StepDirCounter_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(StepDirCounter_COUNTER_LSB_PTR_8BIT);
	#endif/* (StepDirCounter_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(StepDirCounter_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(StepDirCounter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(StepDirCounter_STATICCOUNT_LSB_PTR));
    #endif /* (StepDirCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepDirCounter_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint16) Present Capture value.
*
*******************************************************************************/
uint16 StepDirCounter_ReadCapture(void) 
{
    #if(StepDirCounter_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(StepDirCounter_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG16(StepDirCounter_STATICCOUNT_LSB_PTR));
    #endif /* (StepDirCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepDirCounter_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint16) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void StepDirCounter_WritePeriod(uint16 period) 
{
    #if(StepDirCounter_UsingFixedFunction)
        CY_SET_REG16(StepDirCounter_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG16(StepDirCounter_PERIOD_LSB_PTR, period);
    #endif /* (StepDirCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepDirCounter_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint16) Present period value.
*
*******************************************************************************/
uint16 StepDirCounter_ReadPeriod(void) 
{
    #if(StepDirCounter_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(StepDirCounter_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(StepDirCounter_PERIOD_LSB_PTR));
    #endif /* (StepDirCounter_UsingFixedFunction) */
}


#if (!StepDirCounter_UsingFixedFunction)
/*******************************************************************************
* Function Name: StepDirCounter_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void StepDirCounter_WriteCompare(uint16 compare) \
                                   
{
    #if(StepDirCounter_UsingFixedFunction)
        CY_SET_REG16(StepDirCounter_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG16(StepDirCounter_COMPARE_LSB_PTR, compare);
    #endif /* (StepDirCounter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: StepDirCounter_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint16) Present compare value.
*
*******************************************************************************/
uint16 StepDirCounter_ReadCompare(void) 
{
    return (CY_GET_REG16(StepDirCounter_COMPARE_LSB_PTR));
}


#if (StepDirCounter_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: StepDirCounter_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void StepDirCounter_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    StepDirCounter_CONTROL &= ((uint8)(~StepDirCounter_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    StepDirCounter_CONTROL |= compareMode;
}
#endif  /* (StepDirCounter_COMPARE_MODE_SOFTWARE) */


#if (StepDirCounter_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: StepDirCounter_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void StepDirCounter_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    StepDirCounter_CONTROL &= ((uint8)(~StepDirCounter_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    StepDirCounter_CONTROL |= ((uint8)((uint8)captureMode << StepDirCounter_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (StepDirCounter_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: StepDirCounter_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void StepDirCounter_ClearFIFO(void) 
{

    while(0u != (StepDirCounter_ReadStatusRegister() & StepDirCounter_STATUS_FIFONEMP))
    {
        (void)StepDirCounter_ReadCapture();
    }

}
#endif  /* (!StepDirCounter_UsingFixedFunction) */


/* [] END OF FILE */

