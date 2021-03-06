/*******************************************************************************
* File Name: PIDControlTimer.h
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
#if !defined(CY_ISR_PIDControlTimer_H)
#define CY_ISR_PIDControlTimer_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void PIDControlTimer_Start(void);
void PIDControlTimer_StartEx(cyisraddress address);
void PIDControlTimer_Stop(void);

CY_ISR_PROTO(PIDControlTimer_Interrupt);

void PIDControlTimer_SetVector(cyisraddress address);
cyisraddress PIDControlTimer_GetVector(void);

void PIDControlTimer_SetPriority(uint8 priority);
uint8 PIDControlTimer_GetPriority(void);

void PIDControlTimer_Enable(void);
uint8 PIDControlTimer_GetState(void);
void PIDControlTimer_Disable(void);

void PIDControlTimer_SetPending(void);
void PIDControlTimer_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the PIDControlTimer ISR. */
#define PIDControlTimer_INTC_VECTOR            ((reg32 *) PIDControlTimer__INTC_VECT)

/* Address of the PIDControlTimer ISR priority. */
#define PIDControlTimer_INTC_PRIOR             ((reg32 *) PIDControlTimer__INTC_PRIOR_REG)

/* Priority of the PIDControlTimer interrupt. */
#define PIDControlTimer_INTC_PRIOR_NUMBER      PIDControlTimer__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable PIDControlTimer interrupt. */
#define PIDControlTimer_INTC_SET_EN            ((reg32 *) PIDControlTimer__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the PIDControlTimer interrupt. */
#define PIDControlTimer_INTC_CLR_EN            ((reg32 *) PIDControlTimer__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the PIDControlTimer interrupt state to pending. */
#define PIDControlTimer_INTC_SET_PD            ((reg32 *) PIDControlTimer__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the PIDControlTimer interrupt. */
#define PIDControlTimer_INTC_CLR_PD            ((reg32 *) PIDControlTimer__INTC_CLR_PD_REG)



#endif /* CY_ISR_PIDControlTimer_H */


/* [] END OF FILE */
