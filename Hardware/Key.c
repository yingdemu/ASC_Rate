#include "stm32f10x.h"                  // Device header


//全局变量，用于存储按键键码
uint8_t Key_Num;

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	  //初始化A0 B0 B10
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	  //代表 确定 上 下
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);		

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);					
	
	
}

uint8_t Key_GetNum(void)   //返回数字  0代表没有按下，1代表A0 2代表B0 3代表B1
{
	uint8_t Temp;			
	if (Key_Num)			
	{
		Temp = Key_Num;		
		Key_Num = 0;		
		return Temp;		
	}
	return 0;				
}

uint8_t Key_GetState(void)
{
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 0)		
	{
		return 1;		
	}
	
	
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0) == 0)		
	{
		return 2;		
	}
	
	
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) == 0)		
	{
		return 3;		
	}

	return 0;			
}

void Key_Tick(void)
{
	static uint8_t Count;					
	static uint8_t CurrState, PrevState;	
	
	Count ++;			
	if (Count >= 20)	
	{
		Count = 0;		
		
		PrevState = CurrState;			
		CurrState = Key_GetState();		
		
		//如果本次状态的键码为0，且上次键码不为0，即检测到按键松手瞬间
		if (CurrState == 0 && PrevState != 0)
		{
			Key_Num = PrevState;
		}
	}
}