/*******************************************************************************
* File Name: QuadB.h  
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

#if !defined(CY_PINS_QuadB_H) /* Pins QuadB_H */
#define CY_PINS_QuadB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "QuadB_aliases.h"


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
} QuadB_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   QuadB_Read(void);
void    QuadB_Write(uint8 value);
uint8   QuadB_ReadDataReg(void);
#if defined(QuadB__PC) || (CY_PSOC4_4200L) 
    void    QuadB_SetDriveMode(uint8 mode);
#endif
void    QuadB_SetInterruptMode(uint16 position, uint16 mode);
uint8   QuadB_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void QuadB_Sleep(void); 
void QuadB_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(QuadB__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define QuadB_DRIVE_MODE_BITS        (3)
    #define QuadB_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - QuadB_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the QuadB_SetDriveMode() function.
         *  @{
         */
        #define QuadB_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define QuadB_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define QuadB_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define QuadB_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define QuadB_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define QuadB_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define QuadB_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define QuadB_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define QuadB_MASK               QuadB__MASK
#define QuadB_SHIFT              QuadB__SHIFT
#define QuadB_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in QuadB_SetInterruptMode() function.
     *  @{
     */
        #define QuadB_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define QuadB_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define QuadB_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define QuadB_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(QuadB__SIO)
    #define QuadB_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(QuadB__PC) && (CY_PSOC4_4200L)
    #define QuadB_USBIO_ENABLE               ((uint32)0x80000000u)
    #define QuadB_USBIO_DISABLE              ((uint32)(~QuadB_USBIO_ENABLE))
    #define QuadB_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define QuadB_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define QuadB_USBIO_ENTER_SLEEP          ((uint32)((1u << QuadB_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << QuadB_USBIO_SUSPEND_DEL_SHIFT)))
    #define QuadB_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << QuadB_USBIO_SUSPEND_SHIFT)))
    #define QuadB_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << QuadB_USBIO_SUSPEND_DEL_SHIFT)))
    #define QuadB_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(QuadB__PC)
    /* Port Configuration */
    #define QuadB_PC                 (* (reg32 *) QuadB__PC)
#endif
/* Pin State */
#define QuadB_PS                     (* (reg32 *) QuadB__PS)
/* Data Register */
#define QuadB_DR                     (* (reg32 *) QuadB__DR)
/* Input Buffer Disable Override */
#define QuadB_INP_DIS                (* (reg32 *) QuadB__PC2)

/* Interrupt configuration Registers */
#define QuadB_INTCFG                 (* (reg32 *) QuadB__INTCFG)
#define QuadB_INTSTAT                (* (reg32 *) QuadB__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define QuadB_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(QuadB__SIO)
    #define QuadB_SIO_REG            (* (reg32 *) QuadB__SIO)
#endif /* (QuadB__SIO_CFG) */

/* USBIO registers */
#if !defined(QuadB__PC) && (CY_PSOC4_4200L)
    #define QuadB_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define QuadB_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define QuadB_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define QuadB_DRIVE_MODE_SHIFT       (0x00u)
#define QuadB_DRIVE_MODE_MASK        (0x07u << QuadB_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins QuadB_H */


/* [] END OF FILE */
