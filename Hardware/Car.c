#include "stm32f10x.h"                  // Device header
#include "Serial.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"
#include "Delay.h"
uint8_t  Car_Mode;
uint8_t Flag_Car_Tick=0;
uint16_t Car_Tick_Num;

//-------------------
extern         int16_t Content_PWM_str_left_right; //Content_PWM_...代表各个模式的PWM值，在外部用extern引用
extern         int16_t Content_PWM_x_lef_Left;
extern         int16_t Content_PWM_x_lef_Right;
extern         int16_t Content_PWM_x_rig_Left;
extern         int16_t Content_PWM_x_rig_Right;                 //在此处直接赋值可以改变PWM的初始值，需要在调车时将此处的值都赋好
extern         int16_t  Content_PWM_rig_Left;
extern         int16_t  Content_PWM_rig_Right;
extern         int16_t  Content_PWM_lef_Left;
extern         int16_t  Content_PWM_lef_Right;


void		Car_Right(void){
	
	Motor_SetPWM_Right(Content_PWM_rig_Right);
	Motor_SetPWM_Left(Content_PWM_rig_Left);
		OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

		OLED_ShowNum(3,3,Content_PWM_rig_Right,3);  //验证程序是否可以走到这一步，  结果：可以
		OLED_ShowNum(4,3,Content_PWM_rig_Left,3);  //验证程序是否可以走到这一步，  结果：可以

	Flag_Car_Tick=0;
	Car_Tick_Num=0;
}
void		Car_Left(void)
{
	Motor_SetPWM_Right(Content_PWM_lef_Right);
	Motor_SetPWM_Left(Content_PWM_lef_Left);
		OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

		OLED_ShowNum(3,3,Content_PWM_lef_Right,3);  //验证程序是否可以走到这一步，  结果：可以
		OLED_ShowNum(4,3,Content_PWM_lef_Left,3);  //验证程序是否可以走到这一步，  结果：可以

	Flag_Car_Tick=0;
	Car_Tick_Num=0;
}

void		Car_x_Right(void){
	Motor_SetPWM_Right(Content_PWM_x_rig_Right);
	Motor_SetPWM_Left(Content_PWM_x_rig_Left);
		OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

		OLED_ShowNum(3,3,Content_PWM_x_rig_Right,3);  //验证程序是否可以走到这一步，  结果：可以
		OLED_ShowNum(4,3,Content_PWM_x_rig_Left,3);  //验证程序是否可以走到这一步，  结果：可以

	Flag_Car_Tick=0;
	Car_Tick_Num=0;
}

void		Car_x_Left(void)
{
		Motor_SetPWM_Right(Content_PWM_x_lef_Right);
	Motor_SetPWM_Left(Content_PWM_x_lef_Left);
		OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

		OLED_ShowNum(3,3,Content_PWM_x_lef_Right,3);  //验证程序是否可以走到这一步，  结果：可以
		OLED_ShowNum(4,3,Content_PWM_x_lef_Left,3);  //验证程序是否可以走到这一步，  结果：可以
Flag_Car_Tick=0;
	Car_Tick_Num=0;
}
	
	
void		Car_Straight(void)
{
		Motor_SetPWM_Right(Content_PWM_str_left_right);
	Motor_SetPWM_Left(Content_PWM_str_left_right);
	OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

		OLED_ShowNum(3,3,Content_PWM_str_left_right,3);  //验证程序是否可以走到这一步，  结果：可以

Flag_Car_Tick=0;
	Car_Tick_Num=0;
}
	

void Car_Back(void)
{
	Motor_SetPWM_Right(-90);
	Motor_SetPWM_Left(-90);
Flag_Car_Tick=0;
	Car_Tick_Num=0;
}


void Car_Tick(void)
{

	Car_Tick_Num++;
	if(Car_Tick_Num>=300){
	Car_Tick_Num=0;
		Car_Back();
		Delay_ms(500);
	}
}



uint8_t Keys;
void Car_Trail(void)
{
	OLED_Clear ();
	OLED_ShowString(2,2,"Going");
	
	while(1)
	{
		Keys=Key_GetNum();
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
			Delay_ms(50);

		}
		
		if(Car_Mode==5)
		{
			Car_Right();
			Delay_ms(50);

		}
		if(Car_Mode==6)
		{
			Flag_Car_Tick=1;
		//	Delay_ms(200);
		}

		if(Keys==1)
		{
					Motor_SetPWM_Right(0);
	Motor_SetPWM_Left(0);

			
			return ;
		}

	}
}

