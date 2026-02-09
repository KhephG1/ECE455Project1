/*
 * GPIO_init.c
 *
 *  Created on: Feb 8, 2026
 *      Author: Kheph
 */

#include "_sys_init.h"
#include <math.h>

void init_trafficlight_gpio(void){
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	//traffic lights on PC0 through PC 2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
}

void init_shift_register_gpio(void){
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	//traffic lights on PC0 through PC 2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOC, GPIO_Pin_6 | GPIO_Pin_7);
	GPIO_SetBits(GPIOC, GPIO_Pin_8);

}

void init_adc(void){
	ADC_InitTypeDef ADC_Init_Structure;
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	ADC_StructInit(&ADC_Init_Structure);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);


	GPIO_Init(GPIOC, &GPIO_InitStructure);
	ADC_Init(ADC1, &ADC_Init_Structure);
	ADC_Cmd(ADC1, ENABLE);
	ADC_RegularChannelConfig(ADC1 ,ADC_Channel_13,1,ADC_SampleTime_3Cycles);
}




void test_traffic_light(void){
	//test traffic light GPIOs
	GPIO_SetBits(GPIOC, GPIO_Pin_0);
	for(int i = 0; i < 5000000; i++){
	}
	GPIO_ResetBits(GPIOC, GPIO_Pin_0);
	GPIO_SetBits(GPIOC, GPIO_Pin_1);
	for(int i = 0; i < 5000000; i++){
	}
	GPIO_ResetBits(GPIOC, GPIO_Pin_1);
	GPIO_SetBits(GPIOC, GPIO_Pin_2);
	for(int i = 0; i < 5000000; i++){
	}
	GPIO_ResetBits(GPIOC, GPIO_Pin_2);
	printf("traffic light complete\n");
}

void test_adc(void){
	for(int i= 0;i<6;i++){
		ADC_SoftwareStartConv(ADC1);
		while (ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)!= SET ){}
		double ADC_CODE;
		double ADC_Voltage;
		ADC_CODE = ADC_GetConversionValue(ADC1);
		ADC_Voltage = (ADC_CODE*3.3/pow(2, 12)) * 1000;
		for(int i = 0; i < 5000000; i++){
		}
	}
	printf("ADC test complete\n");
}
void test_shift_register(void){
	uint8_t pattern[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0};
	for(int i = 0; i < 20; i++){
		GPIO_SetBits(GPIOC, GPIO_Pin_7);
		if(pattern[i]){
			GPIO_SetBits(GPIOC, GPIO_Pin_6);
		}else{
			GPIO_ResetBits(GPIOC, GPIO_Pin_6);
		}
		GPIO_ResetBits(GPIOC,GPIO_Pin_7);
		for(int i = 0; i < 1000; i ++){
		}
	}

}

void system_test(void){
	test_traffic_light();
	test_adc();
	test_shift_register();
}




