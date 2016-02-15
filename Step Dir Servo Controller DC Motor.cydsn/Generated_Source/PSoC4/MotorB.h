/*******************************************************************************
* File Name: MotorB.h  
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

#if !defined(CY_PINS_MotorB_H) /* Pins MotorB_H */
#define CY_PINS_MotorB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MotorB_aliases.h"


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
} MotorB_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   MotorB_Read(void);
void    MotorB_Write(uint8 value);
uint8   MotorB_ReadDataReg(void);
#if defined(MotorB__PC) || (CY_PSOC4_4200L) 
    void    MotorB_SetDriveMode(uint8 mode);
#endif
void    MotorB_SetInterruptMode(uint16 position, uint16 mode);
uint8   MotorB_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void MotorB_Sleep(void); 
void MotorB_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(MotorB__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define MotorB_DRIVE_MODE_BITS        (3)
    #define MotorB_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MotorB_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the MotorB_SetDriveMode() function.
         *  @{
         */
        #define MotorB_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define MotorB_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define MotorB_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define MotorB_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define MotorB_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define MotorB_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define MotorB_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define MotorB_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define MotorB_MASK               MotorB__MASK
#define MotorB_SHIFT              MotorB__SHIFT
#define MotorB_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MotorB_SetInterruptMode() function.
     *  @{
     */
        #define MotorB_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define MotorB_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define MotorB_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define MotorB_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(MotorB__SIO)
    #define MotorB_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(MotorB__PC) && (CY_PSOC4_4200L)
    #define MotorB_USBIO_ENABLE               ((uint32)0x80000000u)
    #define MotorB_USBIO_DISABLE              ((uint32)(~MotorB_USBIO_ENABLE))
    #define MotorB_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define MotorB_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define MotorB_USBIO_ENTER_SLEEP          ((uint32)((1u << MotorB_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << MotorB_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorB_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << MotorB_USBIO_SUSPEND_SHIFT)))
    #define MotorB_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << MotorB_USBIO_SUSPEND_DEL_SHIFT)))
    #define MotorB_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(MotorB__PC)
    /* Port Configuration */
    #define MotorB_PC                 (* (reg32 *) MotorB__PC)
#endif
/* Pin State */
#define MotorB_PS                     (* (reg32 *) MotorB__PS)
/* Data Register */
#define MotorB_DR                     (* (reg32 *) MotorB__DR)
/* Input Buffer Disable Override */
#define MotorB_INP_DIS                (* (reg32 *) MotorB__PC2)

/* Interrupt configuration Registers */
#define MotorB_INTCFG                 (* (reg32 *) MotorB__INTCFG)
#define MotorB_INTSTAT                (* (reg32 *) MotorB__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define MotorB_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(MotorB__SIO)
    #define MotorB_SIO_REG            (* (reg32 *) MotorB__SIO)
#endif /* (MotorB__SIO_CFG) */

/* USBIO registers */
#if !defined(MotorB__PC) && (CY_PSOC4_4200L)
    #define MotorB_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define MotorB_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define MotorB_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define MotorB_DRIVE_MODE_SHIFT       (0x00u)
#define MotorB_DRIVE_MODE_MASK        (0x07u << MotorB_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins MotorB_H */


/* [] END OF FILE */
