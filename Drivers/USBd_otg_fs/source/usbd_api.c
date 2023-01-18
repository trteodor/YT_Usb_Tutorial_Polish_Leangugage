#include <usb_otg_regs.h>
#include "GPIO.h"

#define USB_OTG_FS_DP_Pin GPIO_PIN_12
#define USB_OTG_FS_DP_Port GPIOA
#define USB_OTG_FS_DM_Pin GPIO_PIN_11
#define USB_OTG_FS_DM_Port GPIOA

#define GPIO_AF10_OTG_FS                 ((uint8_t)0x0A)

void USBD_periphInit(void)
{
    /*As it's defined in RM we have to program following registers to init core:*/
    /*Global registers*/
    USB_OTG_GUSBCFG_TypeDef gusbcfg;
    USB_OTG_GINTMSK_TypeDef gintmsk;
    USB_OTG_GAHBCFG_TypeDef gahbcfg;
    USB_OTG_GCCFG_TypeDef   gccfg;
    /*Device register*/
    USB_OTG_DCFG_TypeDef    dcfg;
    // FS_USB_OTG_PREGS->PCGCCTL = 0;
    // FS_USB_OTG_DREGS->DCTL = 0;

    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = USB_OTG_FS_DP_Pin|USB_OTG_FS_DM_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    NVIC_SetPriority(OTG_FS_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
    NVIC_EnableIRQ(OTG_FS_IRQn);

    USE_OTG_FS_REGS();

    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN);

    /*Core/ global regs*/
    gahbcfg.d32 = 0;
    gahbcfg.b.txfelvl = 1;
    gahbcfg.b.gintmsk = 1;
    FS_USB_OTG_GREGS->GAHBCFG = gahbcfg.d32;

    gusbcfg.d32 = 0;
    gusbcfg.b.fdmod = 1; /* Force the device mode. */
    gusbcfg.b.trdt = 4;
    FS_USB_OTG_GREGS->GUSBCFG = gusbcfg.d32;

    gintmsk.d32 = 0;
    gintmsk.b.usbrstm = 1;
    gintmsk.b.enumdnem = 1;
    gintmsk.b.rxflvlm = 1;
    gintmsk.b.oepim = 1;
    gintmsk.b.iepim = 1;
    gintmsk.b.sofm = 1;
    FS_USB_OTG_GREGS->GINTMSK = gintmsk.d32;

    gccfg.d32 = 0;
    gccfg.b.novbussens = 1;
    gccfg.b.vbusbsen = 1;
    gccfg.b.pwrdwn = 1;
    FS_USB_OTG_GREGS->GCCFG = gccfg.d32;
    FS_USB_OTG_PREGS->PCGCCTL = 0;

    /*Device regs*/
    dcfg.d32 = 0;
    dcfg.b.nzlsohsk = 1;
    dcfg.b.dspd = 3;
    FS_USB_OTG_DREGS->DCFG = dcfg.d32;


    FS_USB_OTG_DREGS->DCTL = 0;
}



