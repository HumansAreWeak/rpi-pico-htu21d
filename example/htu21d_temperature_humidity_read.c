#include "stdio.h"
#include "pico/stdlib.h"
#include "haw/HTU21D.h"

int main()
{
    stdio_init_all();

    // I2C Setup
    gpio_init(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_init(PICO_DEFAULT_I2C_SCL_PIN);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

    // Don't forget the internal pull ups! / Or use external instead
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    /* 
        Setup HTU21D 
    */

    // Create HTU21D struct
    htu21d_t htu21d = htu21d_init(i2c_default);

    // Enable Temperature measuring
    htu21d_set_temperature_measuring(&htu21d, 1);

    // Enable Humidity measuring
    htu21d_set_humidity_measuring(&htu21d, 1);

    // Set to highest resolution (longest delay!)
    htu21d_set_resolution(&htu21d, HTU21D_RES_HUMI12_TEMP14);

    // Deactivate the internal heater
    htu21d_set_heater(&htu21d, HTU21D_HEATER_OFF);

    while (1)
    {
        // Fetch all data from sensor
        htu21d_event(&htu21d);

        // Print the result out
        printf("Temperature: %.4f°C - Temperature: %.4f°F - Humidity: %.4f%%\n",
               htu21d_get_temperature_c(&htu21d),
               htu21d_get_temperature_f(&htu21d),
               htu21d_get_humidity(&htu21d));
    }

    return 0;
}