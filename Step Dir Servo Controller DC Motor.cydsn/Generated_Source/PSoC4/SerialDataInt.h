/*******************************************************************************
* File Name: SerialDataInt.h
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
#if !defined(CY_ISR_SerialDataInt_H)
#define CY_ISR_SerialDataInt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SerialDataInt_Start(void);
void SerialDataInt_StartEx(cyisraddress address);
void SerialDataInt_Stop(void);

CY_ISR_PROTO(SerialDataInt_Interrupt);

void SerialDataInt_SetVector(cyisraddress address);
cyisraddress SerialDataInt_GetVector(void);

void SerialDataInt_SetPriority(uint8 priority);
uint8 SerialDataInt_GetPriority(void);

void SerialDataInt_Enable(void);
uint8 SerialDataInt_GetState(void);
void SerialDataInt_Disable(void);

void SerialDataInt_SetPending(void);
void SerialDataInt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SerialDataInt ISR. */
#define SerialDataInt_INTC_VECTOR            ((reg32 *) SerialDataInt__INTC_VECT)

/* Address of the SerialDataInt ISR priority. */
#define SerialDataInt_INTC_PRIOR             ((reg32 *) SerialDataInt__INTC_PRIOR_REG)

/* Priority of the SerialDataInt interrupt. */
#define SerialDataInt_INTC_PRIOR_NUMBER      SerialDataInt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SerialDataInt interrupt. */
#define SerialDataInt_INTC_SET_EN            ((reg32 *) SerialDataInt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SerialDataInt interrupt. */
#define SerialDataInt_INTC_CLR_EN            ((reg32 *) SerialDataInt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SerialDataInt interrupt state to pending. */
#define SerialDataInt_INTC_SET_PD            ((reg32 *) SerialDataInt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SerialDataInt interrupt. */
#define SerialDataInt_INTC_CLR_PD            ((reg32 *) SerialDataInt__INTC_CLR_PD_REG)



#endif /* CY_ISR_SerialDataInt_H */


/* [] END OF FILE */
