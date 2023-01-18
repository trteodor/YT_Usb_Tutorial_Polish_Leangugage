#include "System.h"
#include "GPIO.h"


#include "usbd_api.h"


int main(void) {
	PLL_Config84Mhz();
  ConfigSysTick1ms();
  

  USBD_periphInit();

  while(1)
  {
    

  }

}

















