






void OTG_FS_IRQHandler(void)
{
//   USB_OTG_GINTSTS_TypeDef interrupt_status;

//   interrupt_status.d32 = FS_USB_OTG_GREGS->GINTSTS;
//   /* Ensure that we are in the device mode. */
//   if (interrupt_status.b.cmod == 0) {
//     interrupt_status.d32 &= FS_USB_OTG_GREGS->GINTMSK;
//     /* Clear pending interrupt flags. */
//     FS_USB_OTG_GREGS->GINTSTS = interrupt_status.d32;

//     if (interrupt_status.b.usbrst)
//       DevResetHandler();
//     if (interrupt_status.b.enumdne)
//       DevEnumerationDoneHandler();

//     if (interrupt_status.b.rxflvl)
//       DevRxFifoNonEmptylHandler();
//     if (interrupt_status.b.oepint)
//       DevOutEndPointTransactionHandler();
//     if (interrupt_status.b.iepint)
//       DevInEndPointTransactionHandler();

//     if (interrupt_status.b.usbsusp)
//       DevSuspendHandler();
//     if (interrupt_status.b.wkuint)
//       DevWakeupHandler();

//     if (interrupt_status.b.sof)
//       DevSofHandler();
//   }
//   else {

//   }
}