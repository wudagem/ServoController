/*******************************************************************************
* File Name: LedPin.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LedPin_ALIASES_H) /* Pins LedPin_ALIASES_H */
#define CY_PINS_LedPin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define LedPin_0			(LedPin__0__PC)
#define LedPin_0_PS		(LedPin__0__PS)
#define LedPin_0_PC		(LedPin__0__PC)
#define LedPin_0_DR		(LedPin__0__DR)
#define LedPin_0_SHIFT	(LedPin__0__SHIFT)
#define LedPin_0_INTR	((uint16)((uint16)0x0003u << (LedPin__0__SHIFT*2u)))

#define LedPin_INTR_ALL	 ((uint16)(LedPin_0_INTR))


#endif /* End Pins LedPin_ALIASES_H */


/* [] END OF FILE */
