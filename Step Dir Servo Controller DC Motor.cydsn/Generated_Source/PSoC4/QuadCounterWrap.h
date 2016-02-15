/*******************************************************************************
* File Name: QuadCounterWrap.h
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
#if !defined(CY_ISR_QuadCounterWrap_H)
#define CY_ISR_QuadCounterWrap_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void QuadCounterWrap_Start(void);
void QuadCounterWrap_StartEx(cyisraddress address);
void QuadCounterWrap_Stop(void);

CY_ISR_PROTO(QuadCounterWrap_Interrupt);

void QuadCounterWrap_SetVector(cyisraddress address);
cyisraddress QuadCounterWrap_GetVector(void);

void QuadCounterWrap_SetPriority(uint8 priority);
uint8 QuadCounterWrap_GetPriority(void);

void QuadCounterWrap_Enable(void);
uint8 QuadCounterWrap_GetState(void);
void QuadCounterWrap_Disable(void);

void QuadCounterWrap_SetPending(void);
void QuadCounterWrap_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the QuadCounterWrap ISR. */
#define QuadCounterWrap_INTC_VECTOR            ((reg32 *) QuadCounterWrap__INTC_VECT)

/* Address of the QuadCounterWrap ISR priority. */
#define QuadCounterWrap_INTC_PRIOR             ((reg32 *) QuadCounterWrap__INTC_PRIOR_REG)

/* Priority of the QuadCounterWrap interrupt. */
#define QuadCounterWrap_INTC_PRIOR_NUMBER      QuadCounterWrap__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable QuadCounterWrap interrupt. */
#define QuadCounterWrap_INTC_SET_EN            ((reg32 *) QuadCounterWrap__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the QuadCounterWrap interrupt. */
#define QuadCounterWrap_INTC_CLR_EN            ((reg32 *) QuadCounterWrap__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the QuadCounterWrap interrupt state to pending. */
#define QuadCounterWrap_INTC_SET_PD            ((reg32 *) QuadCounterWrap__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the QuadCounterWrap interrupt. */
#define QuadCounterWrap_INTC_CLR_PD            ((reg32 *) QuadCounterWrap__INTC_CLR_PD_REG)



#endif /* CY_ISR_QuadCounterWrap_H */


/* [] END OF FILE */
