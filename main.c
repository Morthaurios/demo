
/*****************************************************************************************************************************
 * FILE NAME:   Sensor.c
 * AUTHOR:      morthaurios
 * DESCRIPTION: Dummy Sensor driver.
 *****************************************************************************************************************************/

/*****************************************************************************************************************************
 * INCLUDES
 *****************************************************************************************************************************/
#include "I2c.h"
#include "Mem.h"
#include "Sensor.h"

/*****************************************************************************************************************************
 * MACROS
 *****************************************************************************************************************************/

#define MEMORY_PAGE_SIZE    (256U)
#define SENSOR_MEASUREMENT_PAGE_SIZE    (MEMORY_PAGE_SIZE / 4U)

#define MEASUREMENT_MEMORY_ADDRESS      (0x0800U)

/*****************************************************************************************************************************
 * TYPE DEFINITIONS
 *****************************************************************************************************************************/


/*****************************************************************************************************************************
 * GLOBAL VARIABLES
 *****************************************************************************************************************************/


/*****************************************************************************************************************************
 * LOCAL VARIABLES
 *****************************************************************************************************************************/
static union
{
    uint8_t au8Bytes[MEMORY_PAGE_SIZE];
    uint32_t au8DWord[SENSOR_MEASUREMENT_PAGE_SIZE];
} uMeasurements;

/*****************************************************************************************************************************
 * FUNCTION DECLARATIONS
 *****************************************************************************************************************************/

 static void InitPeripherals(void);
 static void InitDevices(void);

/*****************************************************************************************************************************
 * FUNCTION DEFINITIONS
*****************************************************************************************************************************/

/*****************************************************************************************************************************
 * FUNCTION:        main
 * DESCRIPTION:     TBD
 * INPUT:           TBD
 * OUTPUT:          TBD
 * RETURN:          TBD
 *****************************************************************************************************************************/
void main(void)
{
    uint8_t u8MeasurementIndex = 0U;

    InitPeripherals();
    InitDevices();

    for(;;)
    {
        /* Read sensor. */
        if(E_OK == Sensor_Read(&uMeasurements.au8DWord[u8MeasurementIndex]))
        {
            u8MeasurementIndex++;
        }

        /* Store when we get a page size of measurements. */
        if(u8MeasurementIndex >= SENSOR_MEASUREMENT_PAGE_SIZE)
        {
            Mem_Write(MEASUREMENT_MEMORY_ADDRESS, uMeasurements.au8Bytes, (uint16_t) sizeof(uMeasurements));

            u8MeasurementIndex = 0U;
        }
    }
}

/*****************************************************************************************************************************
 * FUNCTION:        InitPeripherals
 * DESCRIPTION:     TBD
 * INPUT:           TBD
 * OUTPUT:          TBD
 * RETURN:          TBD
 *****************************************************************************************************************************/
static void InitPeripherals(void)
{
    if(E_OK != I2C_Init())
    {
        /* Trigger warning */
    }
}

/*****************************************************************************************************************************
 * FUNCTION:        InitDevices
 * DESCRIPTION:     TBD
 * INPUT:           TBD
 * OUTPUT:          TBD
 * RETURN:          TBD
 *****************************************************************************************************************************/
static void InitDevices(void)
{
    if(E_OK != Mem_Init())
    {
        /* Trigger warning */
    }

    if(E_OK != Sensor_Init())
    {
        /* Trigger warning */
    }
}