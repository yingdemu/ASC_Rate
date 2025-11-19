#include "stm32f10x.h"                  // Device header
#include "Serial.h"
#include "OLED.h"
#include "Motor.h"

uint8_t  Car_Mode;
//-------------------
extern         uint16_t Content_PWM_str_left_right; //Content_PWM_...代表各个模式的PWM值，在外部用extern引用
extern         uint16_t Content_PWM_x_lef_Left;
extern         uint16_t Content_PWM_x_lef_Right;
extern         uint16_t Content_PWM_x_rig_Left;
extern         uint16_t Content_PWM_x_rig_Right;                 //在此处直接赋值可以改变PWM的初始值，需要在调车时将此处的值都赋好
extern         uint16_t  Content_PWM_rig_Left;
extern         uint16_t  Content_PWM_rig_Right;
extern         uint16_t  Content_PWM_lef_Left;
extern         uint16_t  Content_PWM_lef_Right;


void		Car_Right(void){
	
	Motor_SetPWM_Right(Content_PWM_rig_Right);
	Motor_SetPWM_Left(Content_PWM_rig_Left);

}
void		Car_Left(void)
{
	Motor_SetPWM_Right(Content_PWM_lef_Right);
	Motor_SetPWM_Left(Content_PWM_lef_Left);

}

void		Car_x_Right(void){
	Motor_SetPWM_Right(Content_PWM_x_rig_Right);
	Motor_SetPWM_Left(Content_PWM_x_rig_Left);

}

void		Car_x_Left(void)
{
		Motor_SetPWM_Right(Content_PWM_x_lef_Right);
	Motor_SetPWM_Left(Content_PWM_x_lef_Left);

}
	
	
void		Car_Straight(void)
{
		Motor_SetPWM_Right(Content_PWM_str_left_right);
	Motor_SetPWM_Left(Content_PWM_str_left_right);

}
	
	



void Car_Trail(void)
{
	OLED_Clear ();
	OLED_ShowString(2,2,"Going");
	
	while(1)
	{
		Car_Mode=Serial_GetMode();    //1->直行 2->左小  3->右小  4->左  5->右
		
		if(Car_Mode==1)
		{
			Car_Straight();
		}
		
		if(Car_Mode==2)
		{
			Car_x_Left();
		}
		
		if(Car_Mode==3)
		{
			Car_x_Right();
		}
		
		if(Car_Mode==4)
		{
			Car_Left();
		}
		
		if(Car_Mode==5)
		{
			Car_Right();
		}

	}
}

