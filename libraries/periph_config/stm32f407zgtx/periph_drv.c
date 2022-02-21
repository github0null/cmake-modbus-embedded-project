#include "periph_interface.h"

#define DELAY_TIMER_NAME TIM6

void drv_delay_us(uint32_t us)
{
    if (us == 0) return;

    LL_TIM_DisableCounter(DELAY_TIMER_NAME);
    LL_TIM_SetCounter(DELAY_TIMER_NAME, 0);
    LL_TIM_ClearFlag_UPDATE(DELAY_TIMER_NAME);

    while (us--)
    {
        LL_TIM_EnableCounter(DELAY_TIMER_NAME);
        while (!LL_TIM_IsActiveFlag_UPDATE(DELAY_TIMER_NAME)) {}
        LL_TIM_ClearFlag_UPDATE(DELAY_TIMER_NAME);
    }
}

void drv_led_trigger(uint32_t led_num)
{
    switch (led_num)
    {
        case LED0:
            LL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
            break;
        default:
            break;
    }
}
