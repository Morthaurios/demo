#include "I2c.h"
#include "Mem.h"
#include "Sensor.h"
static union
{
    uint8_t au8Bytes[256];
    uint32_t au8DWord[64];
} uMeasurements;


void main(void)
{
    uint8_t u8MeasurementIndex = 0U;

    if(E_OK != I2C_Init())
    {
        /* Trigger warning */
    }

    if(E_OK != Mem_Init())
    {
        /* Trigger warning */
    }

    if(E_OK != Sensor_Init())
    {
        /* Trigger warning */
    }

    for(;;)
    {
        if(E_OK == Sensor_Read(&uMeasurements.au8DWord[u8MeasurementIndex]))
        {
            u8MeasurementIndex++;
        }

        if(u8MeasurementIndex >= 64U)
        {
            Mem_Write(0x800U, uMeasurements.au8Bytes, (uint16_t) sizeof(uMeasurements));

            u8MeasurementIndex = 0U;
        }
    }
}