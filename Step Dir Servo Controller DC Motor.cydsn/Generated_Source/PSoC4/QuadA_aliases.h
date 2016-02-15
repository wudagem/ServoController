/*******************************************************************************
* File Name: QuadA.h  
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

#if !defined(CY_PINS_QuadA_ALIASES_H) /* Pins QuadA_ALIASES_H */
#define CY_PINS_QuadA_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define QuadA_0			(QuadA__0__PC)
#define QuadA_0_PS		(QuadA__0__PS)
#define QuadA_0_PC		(QuadA__0__PC)
#define QuadA_0_DR		(QuadA__0__DR)
#define QuadA_0_SHIFT	(QuadA__0__SHIFT)
#define QuadA_0_INTR	((uint16)((uint16)0x0003u << (QuadA__0__SHIFT*2u)))

#define QuadA_INTR_ALL	 ((uint16)(QuadA_0_INTR))


#endif /* End Pins QuadA_ALIASES_H */


/* [] END OF FILE */
