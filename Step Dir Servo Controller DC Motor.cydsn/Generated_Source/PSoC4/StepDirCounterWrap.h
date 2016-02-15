/*******************************************************************************
* File Name: StepDirCounterWrap.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_StepDirCounterWrap_H)
#define CY_ISR_StepDirCounterWrap_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void StepDirCounterWrap_Start(void);
void StepDirCounterWrap_StartEx(cyisraddress address);
void StepDirCounterWrap_Stop(void);

CY_ISR_PROTO(StepDirCounterWrap_Interrupt);

void StepDirCounterWrap_SetVector(cyisraddress address);
cyisraddress StepDirCounterWrap_GetVector(void);

void StepDirCounterWrap_SetPriority(uint8 priority);
uint8 StepDirCounterWrap_GetPriority(void);

void StepDirCounterWrap_Enable(void);
uint8 StepDirCounterWrap_GetState(void);
void StepDirCounterWrap_Disable(void);

void StepDirCounterWrap_SetPending(void);
void StepDirCounterWrap_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the StepDirCounterWrap ISR. */
#define StepDirCounterWrap_INTC_VECTOR            ((reg32 *) StepDirCounterWrap__INTC_VECT)

/* Address of the StepDirCounterWrap ISR priority. */
#define StepDirCounterWrap_INTC_PRIOR             ((reg32 *) StepDirCounterWrap__INTC_PRIOR_REG)

/* Priority of the StepDirCounterWrap interrupt. */
#define StepDirCounterWrap_INTC_PRIOR_NUMBER      StepDirCounterWrap__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable StepDirCounterWrap interrupt. */
#define StepDirCounterWrap_INTC_SET_EN            ((reg32 *) StepDirCounterWrap__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the StepDirCounterWrap interrupt. */
#define StepDirCounterWrap_INTC_CLR_EN            ((reg32 *) StepDirCounterWrap__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the StepDirCounterWrap interrupt state to pending. */
#define StepDirCounterWrap_INTC_SET_PD            ((reg32 *) StepDirCounterWrap__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the StepDirCounterWrap interrupt. */
#define StepDirCounterWrap_INTC_CLR_PD            ((reg32 *) StepDirCounterWrap__INTC_CLR_PD_REG)



#endif /* CY_ISR_StepDirCounterWrap_H */


/* [] END OF FILE */
