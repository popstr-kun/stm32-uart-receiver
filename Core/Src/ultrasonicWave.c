//
// Created by ShenKun_Laptop on 2023/2/1.
//
#include "ultrasonicWave.h"
#include "delay.h"

void ultrasonicWave_startMeasure(void){
    TRIG_GPIO_Port->BSRR = TRIG_Pin;
    delay_us(12);
    TRIG_GPIO_Port->BRR = TRIG_Pin;
}