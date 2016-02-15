/*******************************************************************************
* File Name: MotorB.h  
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

#if !defined(CY_PINS_MotorB_ALIASES_H) /* Pins MotorB_ALIASES_H */
#define CY_PINS_MotorB_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define MotorB_0			(MotorB__0__PC)
#define MotorB_0_PS		(MotorB__0__PS)
#define MotorB_0_PC		(MotorB__0__PC)
#define MotorB_0_DR		(MotorB__0__DR)
#define MotorB_0_SHIFT	(MotorB__0__SHIFT)
#define MotorB_0_INTR	((uint16)((uint16)0x0003u << (MotorB__0__SHIFT*2u)))

#define MotorB_INTR_ALL	 ((uint16)(MotorB_0_INTR))


#endif /* End Pins MotorB_ALIASES_H */


/* [] END OF FILE */
