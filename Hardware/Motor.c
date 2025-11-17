#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					
	
	PWM_Init();												
}  //让B12 B13 B14 B15供电，前两个左侧，后两个右侧

void Motor_SetPWM_Left(int8_t PWM)  //支持负数
{
	if (PWM >= 0)							
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);	
		GPIO_SetBits(GPIOB, GPIO_Pin_13);	
		PWM_SetCompare_Left(PWM);				
	}
	else									
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);	
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);	
		PWM_SetCompare_Left(-PWM);				
	}
}

void Motor_SetPWM_Right(int8_t PWM)
{
	if (PWM >= 0)							
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);	
		GPIO_SetBits(GPIOB, GPIO_Pin_15);	
		PWM_SetCompare_Right(PWM);				
	}
	else									
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_14);	
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);	
		PWM_SetCompare_Right(-PWM);				
	}
}

