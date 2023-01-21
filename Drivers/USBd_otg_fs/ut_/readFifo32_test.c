#include "stdint.h"
#include "stdio.h"

uint32_t USB_OTG_BASE_ADDR[0x10000];

#define USB_OTG_DATA_FIFO_OFFSET         0x1000
#define USB_OTG_DATA_FIFO_SIZE           0x1000

#define FS_USB_OTG_FIFO \
  ((USB_OTG_FIFO *)(USB_OTG_BASE_ADDR + USB_OTG_DATA_FIFO_OFFSET))

typedef volatile uint32_t USB_OTG_FIFO[USB_OTG_DATA_FIFO_SIZE >> 2]; //Divide by 4 (type uint32_t/4=1024Word)
                                                                     //4092Bytes = 1024Words

// uint32_t AAAA[0][1024]
/* Copy 4 * ((len + 3) >> 2) bytes from the receive fifo to the dst
   buffer, which must be 4 byte aligned. */
void ReadFifo32(int num, uint32_t *dst, uint32_t len) {
  uint32_t i;

  for (i = 0; i < len; i += 4, ++dst)
  {
        // *dst = FS_USB_OTG_FIFO[num][0];
        printf("Num: %d, DstIsEqual: %p \n\r",num, FS_USB_OTG_FIFO[num]);
  }
}


int main()
{
    uint32_t dst[0x10000];

    ReadFifo32(0,dst,12);
    ReadFifo32(1,dst,12);
    ReadFifo32(2,dst,12);
}