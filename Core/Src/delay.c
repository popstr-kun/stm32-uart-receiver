//
// Created by ShenKun_Laptop on 2023/2/1.
//
#include "delay.h"

void delay_us(uint32_t time_us){
    uint32_t tempCTRL = SysTick->CTRL;
    uint32_t tempLOAD = SysTick->LOAD;

    SysTick->LOAD = (HAL_RCC_GetHCLKFreq()/8000000)*time_us;
    SysTick->VAL  = 0;
    SysTick->CTRL = 1;

    while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));

    SysTick->LOAD = tempLOAD;
    SysTick->CTRL = tempCTRL;
}