
#include "app_main.h"

void app_main()
{
    while (true)
    {
        drv_led_trigger(LED0);
        drv_delay_us(500 * 1000);
    }
}
