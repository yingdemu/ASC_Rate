#include "stm32f10x.h"                  // Device header
#include "Timer.h"
#include "Key.h"
#include "OLED.h"
#include "Motor.h"
#include "Menu.h"

uint8_t Key_No; //返回按下的按键是哪个
uint8_t Mode_Num;//返回现在是哪个模式   1--发车模式，2--调试模式

int main(void)
{
	Timer_Init();
	OLED_Init();		
	Key_Init();
	Motor_Init();
		OLED_Clear();
	OLED_ShowString(1,1,"1->start");

	

	
	
	while (1)
	{
		
		Key_No=Key_GetNum();
		
		Menu1();
		
		
	}
	
	
}



void TIM3_IRQHandler(void)
{
	static uint16_t Count;
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
	{
		Key_Tick();   //每ms进一次中断
	
		
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);

	}
}