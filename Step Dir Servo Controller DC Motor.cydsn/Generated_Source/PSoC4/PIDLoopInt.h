/*******************************************************************************
* File Name: PIDLoopInt.h
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
#if !defined(CY_ISR_PIDLoopInt_H)
#define CY_ISR_PIDLoopInt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void PIDLoopInt_Start(void);
void PIDLoopInt_StartEx(cyisraddress address);
void PIDLoopInt_Stop(void);

CY_ISR_PROTO(PIDLoopInt_Interrupt);

void PIDLoopInt_SetVector(cyisraddress address);
cyisraddress PIDLoopInt_GetVector(void);

void PIDLoopInt_SetPriority(uint8 priority);
uint8 PIDLoopInt_GetPriority(void);

void PIDLoopInt_Enable(void);
uint8 PIDLoopInt_GetState(void);
void PIDLoopInt_Disable(void);

void PIDLoopInt_SetPending(void);
void PIDLoopInt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the PIDLoopInt ISR. */
#define PIDLoopInt_INTC_VECTOR            ((reg32 *) PIDLoopInt__INTC_VECT)

/* Address of the PIDLoopInt ISR priority. */
#define PIDLoopInt_INTC_PRIOR             ((reg32 *) PIDLoopInt__INTC_PRIOR_REG)

/* Priority of the PIDLoopInt interrupt. */
#define PIDLoopInt_INTC_PRIOR_NUMBER      PIDLoopInt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable PIDLoopInt interrupt. */
#define PIDLoopInt_INTC_SET_EN            ((reg32 *) PIDLoopInt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the PIDLoopInt interrupt. */
#define PIDLoopInt_INTC_CLR_EN            ((reg32 *) PIDLoopInt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the PIDLoopInt interrupt state to pending. */
#define PIDLoopInt_INTC_SET_PD            ((reg32 *) PIDLoopInt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the PIDLoopInt interrupt. */
#define PIDLoopInt_INTC_CLR_PD            ((reg32 *) PIDLoopInt__INTC_CLR_PD_REG)



#endif /* CY_ISR_PIDLoopInt_H */


/* [] END OF FILE */
