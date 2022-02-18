#include "modbus_port.h"
#include "periph_interface.h"

void modbus_sleep_us(uint32_t us)
{
    drv_delay_us(us);
}
