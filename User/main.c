#include "stm32f10x.h"                  // Device header
#include "Timer.h"
#include "Key.h"
#include "OLED.h"
#include "Motor.h"
#include "Menu.h"
#include "Serial.h"

int main(void)
{
	Timer_Init();
	OLED_Init();		
	Key_Init();
	Motor_Init();
	Serial_Init();

	
	while (1)
	{
		

		
		Menu1();
		
		
	}
	
	
}



void TIM3_IRQHandler(void)
{
	static uint16_t Count;
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
	{
		Key_Tick();   //每ms进一次中断
		Serial_Tick();
		
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);

	}
}