/*******************************************************************************
* File Name: MotorA.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MotorA_H) /* Pins MotorA_H */
#define CY_PINS_MotorA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MotorA_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} MotorA_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   MotorA_Read(void);
void    MotorA_Write(uint8 value);
uint8   MotorA_ReadDataReg(void);
#if defined(MotorA__PC) || (CY_PSOC4_4200L) 
    void    MotorA_SetDriveMode(uint8 mode);
#endif
void    MotorA_SetInterruptMode(uint16 position, uint16 mode);
uint8   MotorA_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void MotorA_Sleep(void); 
void MotorA_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(MotorA__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define MotorA_DRIVE_MODE_BITS        (3)
    #define MotorA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MotorA_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the MotorA_SetDriveMode() function.
         *  @{
         */
        #define MotorA_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define MotorA_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define MotorA_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define MotorA_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define MotorA_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define MotorA_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define MotorA_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define MotorA_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define MotorA_MASK               MotorA__MASK
#define MotorA_SHIFT              MotorA__SHIFT
#define MotorA_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MotorA_SetInterruptMode() function.
     *  @{
     */
        #define MotorA_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define MotorA_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define MotorA_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define MotorA_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(MotorA__SIO)
    #define MotorA_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(MotorA__PC) && (CY_PSOC4_4200L)
    #define MotorA_USBIO_ENABLE               ((uint32)0x80000000u)
    #define MotorA_USBIO_DISABLE              ((uint32)(~MotorA_USBIO_ENABLE))
    #define MotorA_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define MotorA_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define MotorA_USBIO_ENTER_SLEEP          ((uint32)((1u << MotorA_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << MotorA_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorA_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << MotorA_USBIO_SUSPEND_SHIFT)))
    #define MotorA_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << MotorA_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorA_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(MotorA__PC)
    /* Port Configuration */
    #define MotorA_PC                 (* (reg32 *) MotorA__PC)
#endif
/* Pin State */
#define MotorA_PS                     (* (reg32 *) MotorA__PS)
/* Data Register */
#define MotorA_DR                     (* (reg32 *) MotorA__DR)
/* Input Buffer Disable Override */
#define MotorA_INP_DIS                (* (reg32 *) MotorA__PC2)

/* Interrupt configuration Registers */
#define MotorA_INTCFG                 (* (reg32 *) MotorA__INTCFG)
#define MotorA_INTSTAT                (* (reg32 *) MotorA__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define MotorA_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(MotorA__SIO)
    #define MotorA_SIO_REG            (* (reg32 *) MotorA__SIO)
#endif /* (MotorA__SIO_CFG) */

/* USBIO registers */
#if !defined(MotorA__PC) && (CY_PSOC4_4200L)
    #define MotorA_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define MotorA_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define MotorA_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define MotorA_DRIVE_MODE_SHIFT       (0x00u)
#define MotorA_DRIVE_MODE_MASK        (0x07u << MotorA_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins MotorA_H */


/* [] END OF FILE */
