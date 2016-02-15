/*******************************************************************************
* File Name: QuadA.h  
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

#if !defined(CY_PINS_QuadA_H) /* Pins QuadA_H */
#define CY_PINS_QuadA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "QuadA_aliases.h"


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
} QuadA_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   QuadA_Read(void);
void    QuadA_Write(uint8 value);
uint8   QuadA_ReadDataReg(void);
#if defined(QuadA__PC) || (CY_PSOC4_4200L) 
    void    QuadA_SetDriveMode(uint8 mode);
#endif
void    QuadA_SetInterruptMode(uint16 position, uint16 mode);
uint8   QuadA_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void QuadA_Sleep(void); 
void QuadA_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(QuadA__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define QuadA_DRIVE_MODE_BITS        (3)
    #define QuadA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - QuadA_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the QuadA_SetDriveMode() function.
         *  @{
         */
        #define QuadA_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define QuadA_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define QuadA_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define QuadA_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define QuadA_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define QuadA_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define QuadA_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define QuadA_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define QuadA_MASK               QuadA__MASK
#define QuadA_SHIFT              QuadA__SHIFT
#define QuadA_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in QuadA_SetInterruptMode() function.
     *  @{
     */
        #define QuadA_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define QuadA_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define QuadA_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define QuadA_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(QuadA__SIO)
    #define QuadA_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(QuadA__PC) && (CY_PSOC4_4200L)
    #define QuadA_USBIO_ENABLE               ((uint32)0x80000000u)
    #define QuadA_USBIO_DISABLE              ((uint32)(~QuadA_USBIO_ENABLE))
    #define QuadA_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define QuadA_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define QuadA_USBIO_ENTER_SLEEP          ((uint32)((1u << QuadA_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << QuadA_USBIO_SUSPEND_DEL_SHIFT)))
    #define QuadA_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << QuadA_USBIO_SUSPEND_SHIFT)))
    #define QuadA_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << QuadA_USBIO_SUSPEND_DEL_SHIFT)))
    #define QuadA_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(QuadA__PC)
    /* Port Configuration */
    #define QuadA_PC                 (* (reg32 *) QuadA__PC)
#endif
/* Pin State */
#define QuadA_PS                     (* (reg32 *) QuadA__PS)
/* Data Register */
#define QuadA_DR                     (* (reg32 *) QuadA__DR)
/* Input Buffer Disable Override */
#define QuadA_INP_DIS                (* (reg32 *) QuadA__PC2)

/* Interrupt configuration Registers */
#define QuadA_INTCFG                 (* (reg32 *) QuadA__INTCFG)
#define QuadA_INTSTAT                (* (reg32 *) QuadA__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define QuadA_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(QuadA__SIO)
    #define QuadA_SIO_REG            (* (reg32 *) QuadA__SIO)
#endif /* (QuadA__SIO_CFG) */

/* USBIO registers */
#if !defined(QuadA__PC) && (CY_PSOC4_4200L)
    #define QuadA_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define QuadA_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define QuadA_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define QuadA_DRIVE_MODE_SHIFT       (0x00u)
#define QuadA_DRIVE_MODE_MASK        (0x07u << QuadA_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins QuadA_H */


/* [] END OF FILE */
