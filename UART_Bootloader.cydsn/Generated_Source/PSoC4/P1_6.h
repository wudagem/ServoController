/*******************************************************************************
* File Name: P1_6.h  
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

#if !defined(CY_PINS_P1_6_H) /* Pins P1_6_H */
#define CY_PINS_P1_6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P1_6_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P1_6_Write(uint8 value) ;
void    P1_6_SetDriveMode(uint8 mode) ;
uint8   P1_6_ReadDataReg(void) ;
uint8   P1_6_Read(void) ;
uint8   P1_6_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P1_6_DRIVE_MODE_BITS        (3)
#define P1_6_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P1_6_DRIVE_MODE_BITS))

#define P1_6_DM_ALG_HIZ         (0x00u)
#define P1_6_DM_DIG_HIZ         (0x01u)
#define P1_6_DM_RES_UP          (0x02u)
#define P1_6_DM_RES_DWN         (0x03u)
#define P1_6_DM_OD_LO           (0x04u)
#define P1_6_DM_OD_HI           (0x05u)
#define P1_6_DM_STRONG          (0x06u)
#define P1_6_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define P1_6_MASK               P1_6__MASK
#define P1_6_SHIFT              P1_6__SHIFT
#define P1_6_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P1_6_PS                     (* (reg32 *) P1_6__PS)
/* Port Configuration */
#define P1_6_PC                     (* (reg32 *) P1_6__PC)
/* Data Register */
#define P1_6_DR                     (* (reg32 *) P1_6__DR)
/* Input Buffer Disable Override */
#define P1_6_INP_DIS                (* (reg32 *) P1_6__PC2)


#if defined(P1_6__INTSTAT)  /* Interrupt Registers */

    #define P1_6_INTSTAT                (* (reg32 *) P1_6__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define P1_6_DRIVE_MODE_SHIFT       (0x00u)
#define P1_6_DRIVE_MODE_MASK        (0x07u << P1_6_DRIVE_MODE_SHIFT)


#endif /* End Pins P1_6_H */


/* [] END OF FILE */
