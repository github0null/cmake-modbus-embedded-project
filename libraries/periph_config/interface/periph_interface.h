#ifndef PERIPH_INTERFACE_H
#define PERIPH_INTERFACE_H

#include "main.h"

#define LED0 0

void drv_delay_us(uint32_t us);

void drv_led_trigger(uint32_t led_num);

#endif // !PERIPH_INTERFACE_H
