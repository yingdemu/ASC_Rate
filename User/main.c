#include "stm32f10x.h"                  // Device header
#include "Timer.h"
#include "Key.h"
#include "OLED.h"
#include "Motor.h"
#include "Menu.h"
#include "Serial.h"
#include "Car.h"

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


extern uint8_t Flag_Car_Tick;
extern uint8_t Flag_Car_Shizi_Tick;
extern uint8_t Flag_Car_Shizi_Tick2;
extern uint8_t Flag_Right_Low;
extern uint8_t Flag_Left_Low;

void TIM3_IRQHandler(void)
{
	static uint16_t Count;
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
	{
			if(Flag_Right_Low==1||Flag_Left_Low==1)
			{
			Car_Str_Low();
			}
		if(Flag_Car_Shizi_Tick2==1)
		{
		Car_Shizi_Tick2();
		}

		if(Flag_Car_Shizi_Tick==1)
		{
		Car_Shizi_Tick();
		}
		
		if(Flag_Car_Tick==1){
		Car_Tick();
		}
		Key_Tick();   //每ms进一次中断
		Serial_Tick();
		
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);

	}
}