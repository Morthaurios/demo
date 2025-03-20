#include "I2c.h"
#include "Mem.h"

const static uint8_t au8TxBuffer[256];
static uint8_t au8RxBuffer[256];

void main(void)
{
    I2C_Init();
    Mem_Init();

    for(;;)
    {
        I2C_Transmit(0x20U, au8TxBuffer, 10U);
        I2C_Transmit(0x20U, au8RxBuffer, 10U);
    }
}