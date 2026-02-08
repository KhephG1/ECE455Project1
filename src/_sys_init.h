/*
 * GPIO_init.h
 *
 *  Created on: Feb 8, 2026
 *      Author: Kheph
 */

#ifndef STM32F4XX_STDPERIPH_DRIVER_INC__SYS_INIT_H_
#define STM32F4XX_STDPERIPH_DRIVER_INC__SYS_INIT_H_
#include "stm32f4xx.h"
void init_trafficlight_gpio(void);
void init_shift_register_gpio(void);
void init_adc(void);
void test_traffic_light(void);
void test_adc(void);
void test_shift_register(void);
void system_test(void);
#endif /* STM32F4XX_STDPERIPH_DRIVER_INC__SYS_INIT_H_ */
