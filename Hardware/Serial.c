#include "stm32f10x.h"                  // Device header


uint8_t Serial_Num;
extern uint8_t 	Flag_Car_No_R_Tick;
extern uint8_t 	Flag_Car_No_L_Tick;

void Serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	  
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;             //PA8 9 10 11,分别对应从左至右
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);		
	
}

int8_t Serial_GetMode(void)    //1->直行 2->左小  3->右小  4->左  5->右
{
	uint8_t Temp;			
	if (Serial_Num)			
	{
		Temp = Serial_Num;		
		Serial_Num = 0;		
		return Temp;		
	}
	return 0;				
}

int8_t Serial_GetState(void)
{
	//直行
	if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0 )&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 1)&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) == 1)&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) ==0)) 		
	{
		return 1;		
	}
	//十字
		if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 1 )&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) == 1 )) 	
		{
				return 1;		

		}			

	//后退
if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0 )&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0)&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) == 0)&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) ==0)) 		
{
	return 6;
}
	
	//左小
	if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0 )&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 1)&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) == 0)&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) ==0)) 		
	{
	return 2;
	}

	//右小
	if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0 )&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0)&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) == 1)&&(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) ==0)) 		
	{
	return 3;
	}

	//左
	if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 1 )) 		
	{
		
	return 4;
	}

	//右
	
	if ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11) == 1 )) 		
	{
		
	return 5;
	}


	return 0;			
}

void Serial_Tick(void)
{
	static uint8_t Count;					
	
	Count ++;			
	if (Count >= 10)	
	{
		Count = 0;		
		
		Serial_Num=Serial_GetState();
	}
}