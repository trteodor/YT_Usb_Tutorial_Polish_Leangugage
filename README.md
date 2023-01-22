# USB_OTG_DEVICE BARE METAL STACK EXAMPLE 

**_DIRECTORY: "Application" contain provided example_**

This repository contains the sources created during the USB tutorial video in Polish leanguage. 
The video is available at this link:
https://youtu.be/730B1NHwu7o 

Directory: Driver/USBd_otg_fs/* contain prepared files for usb_otg_fs device driver
Dicrectory: applications/*/* the prepared examples have been placed...

This project was created only for educational purposes.
Created software is prepared for Board- BlackPill with STM32F401CCU6:


![BlackPill](https://github.com/trteodor/YT_Usb_Tutorial_Polish_Leangugage/blob/master/BlackPill_stm32f401ccu6.png)

**_The example presents composite device: VCP+HID (Mouse)_**

* You are ready to start adventure with this USB STACK examples when you have this tools in your environment (environment variables)!

    * arm-none-eabi-gcc 9.3.1
    * OpenOCD 0.11.0
    * make 4.2.1 / or 3.81

    * The versions aren't important on 99% ;) 

To clone this repo please use following command: 
* git clone --recurse-submodules 

Finally:

 **_Call "make" in this project at him location compile provided example

You can call "make flash" to program MCU.
# General References:

* https://wydawnictwo.btc.pl/elektronika/204656-usb-dla-niewtajemniczonych-w-przykladach-na-mikrokontrolery-stm32-e-book.html

* https://www.usb.org/

* https://github.com/hathach/tinyusb?fbclid=IwAR2eV_u5AAk7GbArpe6f22GNZaFtwJsuoiuO3vi2VzL7FNbEQ0NLS_DfuY4

* https://www.elektroda.pl/rtvforum/topic3310418.html

* https://github.com/x893/STM32F103-DualCDC

* https://sudonull.com/post/68144-CDC-MSC-USB-Composite-Device-on-STM32-HAL

**How to tinyUSB in STM32CubeIDE:**

* https://anvilelectronics.ovh/tinyusb-na-stm32-device-cdc/


The last only as Curiosity: 

https://github.com/alambe94/I-CUBE-USBD-Composite?fbclid=IwAR2vQEj_NNZ7KUWyuTjpTuLJg-uFVfsuOl11_1ine6B1eP6DTmZ_XS_4VLw

Another usefull documents/ links used during video/ writing the driver are available in: Docs/*