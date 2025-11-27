#include "stm32f10x.h"                  // Device header
#include "Serial.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"
#include "Delay.h"
int8_t  Car_Mode;
int8_t Car_Mode2;

uint8_t Flag_Car_Tick=0;
uint16_t Car_Tick_Num;
uint8_t Flag_Car_Shizi_Tick=0;

uint16_t Car_Shizi_Tick_Num;

uint16_t Car_Str_Low_Cnt=0;

uint8_t Flag_Car_Shizi_Tick2=0;

uint16_t Car_Shizi_Tick_Num2;
uint16_t Car_No_R_Tick_Cnt=0;
uint8_t 	Flag_Car_No_R_Tick=0;

uint16_t Car_No_L_Tick_Cnt=0;
uint8_t 	Flag_Car_No_L_Tick=0;

void 		Car_Straight();

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
extern         uint8_t Serial_Num;

uint8_t Flag_Right_Low=0;
uint8_t 	Flag_Wait2 =0;
uint8_t 	Flag_Wait1=0;

void		Car_Right(void){
	
	Motor_SetPWM_Right(Content_PWM_rig_Right);
	Motor_SetPWM_Left(Content_PWM_rig_Left);
		OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

OLED_ShowString (3,1,"Right");
	Flag_Car_Tick=0;
	Car_Tick_Num=0;
			Car_Str_Low_Cnt=0;
	Flag_Car_Shizi_Tick2 =0;
Flag_Wait2=1;
	Flag_Right_Low=1;
		Flag_Car_No_L_Tick=1;

while(1)
	{		

		Car_Mode2=Serial_GetMode();    //1->直行 2->左小  3->右小  4->左  5->右
		OLED_ShowNum(3,3,Car_Mode2,3);
		if((Car_Mode2 !=5) && (Car_Mode2 != 7) )
	{
//				if(Car_Mode2==4)
//		{
//			Car_Straight();
//			Delay_ms (500);
//			return ;
//		}

		return;
	}
	}
}


uint8_t Flag_Left_Low=0;
void		Car_Left(void)
{
	Motor_SetPWM_Right(Content_PWM_lef_Right);
	Motor_SetPWM_Left(Content_PWM_lef_Left);
		OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

OLED_ShowString (3,1,"Left");
		Car_Str_Low_Cnt=0;

	Flag_Car_Shizi_Tick =0;
	Flag_Car_Tick=0;
	Car_Tick_Num=0;
	Flag_Left_Low=1;
	Flag_Wait1=1;
	Flag_Car_No_R_Tick=1;
while(1)
	{		

		Car_Mode2=Serial_GetMode();    //1->直行 2->左小  3->右小  4->左  5->右
		OLED_ShowNum(3,3,Car_Mode2,3);
		if((Car_Mode2 !=4) && (Car_Mode2 != 7) )
	{
//		if(Car_Mode2==5)
//		{
//			Car_Straight();
//			Delay_ms (500);
//						return ;

//		}
		
		return;
	}
	}
}

void		Car_x_Right(void){
	
		if(Flag_Right_Low==1||Flag_Left_Low==1)
	{
	Content_PWM_x_rig_Right=30;
		Content_PWM_x_rig_Left=60;
	}else{
	Content_PWM_x_rig_Right=40;
		Content_PWM_x_rig_Left=80;
	}

	Motor_SetPWM_Right(Content_PWM_x_rig_Right);
	Motor_SetPWM_Left(Content_PWM_x_rig_Left);
		OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

OLED_ShowString (3,1,"x_Right");
	Flag_Car_Tick=0;
	Car_Tick_Num=0;

}

void		Car_x_Left(void)
{
	if(Flag_Right_Low==1||Flag_Left_Low==1)
	{
	Content_PWM_x_lef_Left=30;
		Content_PWM_x_lef_Right=60;
	}else{
	Content_PWM_x_lef_Right=80;
		Content_PWM_x_lef_Left=40;
	}

		Motor_SetPWM_Right(Content_PWM_x_lef_Right);
	Motor_SetPWM_Left(Content_PWM_x_lef_Left);
		OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

OLED_ShowString (3,1,"x_Left");
Flag_Car_Tick=0;
	Car_Tick_Num=0;
}
	
	
void		Car_Straight(void)
{
	
	if(Flag_Right_Low==1||Flag_Left_Low==1)
	{
	Content_PWM_str_left_right=50;
	}else{
	Content_PWM_str_left_right=80;
	}
		Motor_SetPWM_Right(Content_PWM_str_left_right);
	Motor_SetPWM_Left(Content_PWM_str_left_right);
			OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

OLED_ShowString (3,1,"Straight");

//Flag_Car_Tick=0;
//	Car_Tick_Num=0;
}
	

void Car_Back(void)
{
	Motor_SetPWM_Right(-50);
	Motor_SetPWM_Left(-50);
				OLED_ShowString(3,1,"               ");
		OLED_ShowString(4,1,"               ");

OLED_ShowString (3,1,"Back");

Flag_Car_Tick=0;
	Car_Tick_Num=0;
}


void Car_Tick(void)
{

	Car_Tick_Num++;
	if(Car_Tick_Num>=500){
	Car_Tick_Num=0;
		Car_Back();
//		Delay_ms(50);
	}
}


//void Car_Shizi_Tick2(void)
//{
//	Car_Shizi_Tick_Num2++;
//	if(Car_Shizi_Tick_Num2>=20){
//	Car_Shizi_Tick_Num2=0;
//		Flag_Car_Shizi_Tick2 =0;
//		if(Car_Mode==4){
//		Car_Straight();
//		//	Delay_ms (30);

//		}
//		else{
//				Car_Right();

//		}
//	}
//}

//void Car_Shizi_Tick(void)
//{
//	Car_Shizi_Tick_Num++;
//	if(Car_Shizi_Tick_Num>=20){
//	Car_Shizi_Tick_Num=0;
//		Flag_Car_Shizi_Tick =0;
//		if(Car_Mode==5){
//		Car_Straight();
//		//	Delay_ms (30);

//		}
//		else{
//				Car_Left();

//		}
//	}
//}


uint8_t Keys;
void Car_Trail(void)
{
	OLED_Clear ();
	OLED_ShowString(2,2,"Going");
	
	while(1)
	{
		Keys=Key_GetNum();
		Car_Mode=Serial_GetMode();    //1->直行 2->左小  3->右小  4->左  5->右
			if(Car_Mode!=0){OLED_ShowNum(4,8,Car_Mode,1);}

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
//			Flag_Car_Shizi_Tick=1;
			Car_Left();

		}
		
		if(Car_Mode==5)
		{
//				Flag_Car_Shizi_Tick2=1;
			Car_Right();

		}
		if(Car_Mode==7)
		{
			Flag_Car_Tick=1;
		//	Delay_ms(200);
		}

		if(Keys==1)
		{
			Flag_Car_Tick=0;
			Flag_Car_Shizi_Tick=0;
			Flag_Car_Shizi_Tick2=0;
					Motor_SetPWM_Right(0);
	Motor_SetPWM_Left(0);

			
			return ;
		}
		


	}
}


void Car_Str_Low(void)
{
	Car_Str_Low_Cnt++;
	if(Car_Str_Low_Cnt>=700){
	
		Car_Str_Low_Cnt=0;
	Flag_Left_Low=0;
		Flag_Right_Low=0;
	}
}
uint16_t Wait_Tick1_Cnt;
uint8_t Car_Mode3;
void Wait_Tick1(void)         //十字
{
Wait_Tick1_Cnt++;
			Car_Mode3=Serial_GetMode();    //1->直行 2->左小  3->右小  4->左  5->右

	if(Car_Mode3==5)
	{
	Car_x_Left   ();
		Delay_ms (200);
		Wait_Tick1_Cnt=0;
	Flag_Wait1 =0;
		return ;

	}
	if(Wait_Tick1_Cnt>=600)
	{
		Wait_Tick1_Cnt=0;
	Flag_Wait1 =0;
		return ;
	}
}


uint16_t Wait_Tick2_Cnt;
uint8_t Car_Mode4;
void Wait_Tick2(void)   //十字
{
Wait_Tick2_Cnt++;
			Car_Mode4=Serial_GetMode();    //1->直行 2->左小  3->右小  4->左  5->右

	if(Car_Mode4==4)
	{
	Car_x_Right  ();
		Delay_ms (200);
		Wait_Tick2_Cnt=0;
	Flag_Wait2 =0;
		return ;

	}
	if(Wait_Tick2_Cnt>=600)
	{
		Wait_Tick2_Cnt=0;
	Flag_Wait2 =0;
		return ;
	}
}

//void Car_No_R_Tick(void)
//{

//	Car_No_R_Tick_Cnt++;
//	if(Car_No_R_Tick_Cnt>=450)
//	{
//	Flag_Car_No_R_Tick=0;
//	}
//}

//void Car_No_L_Tick(void)
//{

//	Car_No_L_Tick_Cnt++;
//	if(Car_No_L_Tick_Cnt>=100)
//	{
//	Flag_Car_No_L_Tick=0;
//	}
//}

