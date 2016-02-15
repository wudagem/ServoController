/*******************************************************************************
* File Name: Boot_P0_7.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Boot_P0_7_H) /* Pins Boot_P0_7_H */
#define CY_PINS_Boot_P0_7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Boot_P0_7_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Boot_P0_7_Write(uint8 value) ;
void    Boot_P0_7_SetDriveMode(uint8 mode) ;
uint8   Boot_P0_7_ReadDataReg(void) ;
uint8   Boot_P0_7_Read(void) ;
uint8   Boot_P0_7_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Boot_P0_7_DRIVE_MODE_BITS        (3)
#define Boot_P0_7_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Boot_P0_7_DRIVE_MODE_BITS))

#define Boot_P0_7_DM_ALG_HIZ         (0x00u)
#define Boot_P0_7_DM_DIG_HIZ         (0x01u)
#define Boot_P0_7_DM_RES_UP          (0x02u)
#define Boot_P0_7_DM_RES_DWN         (0x03u)
#define Boot_P0_7_DM_OD_LO           (0x04u)
#define Boot_P0_7_DM_OD_HI           (0x05u)
#define Boot_P0_7_DM_STRONG          (0x06u)
#define Boot_P0_7_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Boot_P0_7_MASK               Boot_P0_7__MASK
#define Boot_P0_7_SHIFT              Boot_P0_7__SHIFT
#define Boot_P0_7_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Boot_P0_7_PS                     (* (reg32 *) Boot_P0_7__PS)
/* Port Configuration */
#define Boot_P0_7_PC                     (* (reg32 *) Boot_P0_7__PC)
/* Data Register */
#define Boot_P0_7_DR                     (* (reg32 *) Boot_P0_7__DR)
/* Input Buffer Disable Override */
#define Boot_P0_7_INP_DIS                (* (reg32 *) Boot_P0_7__PC2)


#if defined(Boot_P0_7__INTSTAT)  /* Interrupt Registers */

    #define Boot_P0_7_INTSTAT                (* (reg32 *) Boot_P0_7__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Boot_P0_7_DRIVE_MODE_SHIFT       (0x00u)
#define Boot_P0_7_DRIVE_MODE_MASK        (0x07u << Boot_P0_7_DRIVE_MODE_SHIFT)


#endif /* End Pins Boot_P0_7_H */


/* [] END OF FILE */
