/*******************************************************************************
* File Name: QuadB.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "QuadB.h"

static QuadB_BACKUP_STRUCT  QuadB_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: QuadB_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet QuadB_SUT.c usage_QuadB_Sleep_Wakeup
*******************************************************************************/
void QuadB_Sleep(void)
{
    #if defined(QuadB__PC)
        QuadB_backup.pcState = QuadB_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            QuadB_backup.usbState = QuadB_CR1_REG;
            QuadB_USB_POWER_REG |= QuadB_USBIO_ENTER_SLEEP;
            QuadB_CR1_REG &= QuadB_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(QuadB__SIO)
        QuadB_backup.sioState = QuadB_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        QuadB_SIO_REG &= (uint32)(~QuadB_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: QuadB_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to QuadB_Sleep() for an example usage.
*******************************************************************************/
void QuadB_Wakeup(void)
{
    #if defined(QuadB__PC)
        QuadB_PC = QuadB_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            QuadB_USB_POWER_REG &= QuadB_USBIO_EXIT_SLEEP_PH1;
            QuadB_CR1_REG = QuadB_backup.usbState;
            QuadB_USB_POWER_REG &= QuadB_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(QuadB__SIO)
        QuadB_SIO_REG = QuadB_backup.sioState;
    #endif
}


/* [] END OF FILE */
