/*******************************************************************************
* File Name: MotorA.h  
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

#if !defined(CY_PINS_MotorA_ALIASES_H) /* Pins MotorA_ALIASES_H */
#define CY_PINS_MotorA_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define MotorA_0			(MotorA__0__PC)
#define MotorA_0_PS		(MotorA__0__PS)
#define MotorA_0_PC		(MotorA__0__PC)
#define MotorA_0_DR		(MotorA__0__DR)
#define MotorA_0_SHIFT	(MotorA__0__SHIFT)
#define MotorA_0_INTR	((uint16)((uint16)0x0003u << (MotorA__0__SHIFT*2u)))

#define MotorA_INTR_ALL	 ((uint16)(MotorA_0_INTR))


#endif /* End Pins MotorA_ALIASES_H */


/* [] END OF FILE */
