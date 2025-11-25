#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Key.h"
#include "Car.h"

int16_t Content_PWM_str_left_right=80;  //70 //Content_PWM_...代表各个模式的PWM值，在外部用extern引用
int16_t Content_PWM_x_lef_Left=40 ;      //40
int16_t Content_PWM_x_lef_Right=80;  //80
int16_t Content_PWM_x_rig_Left=80;   //80
int16_t Content_PWM_x_rig_Right=40;     //   40         //在此处直接赋值可以改变PWM的初始值，需要在调车时将此处的值都赋好
int16_t  Content_PWM_rig_Left=80;   ////80
int16_t  Content_PWM_rig_Right=-70;  //-73
int16_t  Content_PWM_lef_Left=-70;  //-73
int16_t  Content_PWM_lef_Right=80;  //80
//===============================================

int16_t Postion_Menu1=1;  //记录Menu1中光标的位置
int16_t Key_Menu1; //记录Menu1中的按键

int16_t Postion_Menu1_Change=1;  //记录Menu1_Change中光标的位置
int16_t Key_Menu1_Change; //记录Menu1_Change中的按键

int16_t Postion_Menu1_Change_str=1;  	
int16_t Key_Menu1_Change_str; 					

int16_t Postion_Menu1_Change_x_lef=1;  
int16_t Key_Menu1_Change_x_lef; 				

int16_t Postion_Menu1_Change_x_rig=1;  
int16_t Key_Menu1_Change_x_rig; 				

int16_t Postion_Menu1_Change_lef=1;  	
int16_t Key_Menu1_Change_lef; 					

int16_t Postion_Menu1_Change_rig=1;  	
int16_t Key_Menu1_Change_rig;			 		

int16_t Postion_Menu1_Change_str_right_left=80;  	
int16_t Key_Menu1_Change_str_right_left;			 		


int16_t Postion_Menu1_Change_x_lef_Left=40;  	
int16_t Key_Menu1_Change_x_lef_Left;			 		

int16_t Postion_Menu1_Change_x_lef_Right=80;  	
int16_t Key_Menu1_Change_x_lef_Right;			 		

int16_t  Key_Menu1_Change_rig_Left;
int16_t  Postion_Menu1_Change_rig_Left=80;

int16_t Key_Menu1_Change_rig_Right;   
int16_t Postion_Menu1_Change_rig_Right=-70;

int16_t  Key_Menu1_Change_lef_Left;
int16_t  Postion_Menu1_Change_lef_Left=-70;

int16_t Key_Menu1_Change_lef_Right;   
int16_t Postion_Menu1_Change_lef_Right=80;
//============================
int16_t Postion_Menu1_Change_x_rig_Right=40;
int16_t Key_Menu1_Change_x_rig_Right;

int16_t Postion_Menu1_Change_x_rig_Left=80;
int16_t Key_Menu1_Change_x_rig_Left;

int16_t Postion_Menu1_Start=1;
int16_t Key_Menu1_Start;

//---------------------------------------------------------------------------------------------
void Menu1_Start(void) //Menu1_Start函数
{
	OLED_Clear ();
	while(1){
	OLED_ShowString(1,1,"OK?");
	OLED_ShowString(2,1,"Return");
		OLED_ShowNum(4,3,Postion_Menu1_Start,1);
				Key_Menu1_Start=Key_GetNum();
		
		
		if(Key_Menu1_Start==2)
			{
				Postion_Menu1_Start++;
				if(Postion_Menu1_Start==3){Postion_Menu1_Start=1;}
				
			}
		if(Key_Menu1_Start==3)
		{
				Postion_Menu1_Start--;
				if(Postion_Menu1_Start==0){Postion_Menu1_Start=2;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Start,1);
		if(Key_Menu1_Start==1)
		{
				if(Postion_Menu1_Start==1)
				{
				
				Car_Trail();             //开始循迹
				}
				if(Postion_Menu1_Start==2){
				OLED_Clear ();
					return;
				}
		}

	}
}



	
void Menu1_Change_str_right_left(void)  //控制前进PWM的函数
{
	OLED_Clear();
	
	while(1)
	{	OLED_ShowString(1,1,"str_lef&rigsid");
	OLED_ShowString(2,1,"PWM:");
	
	OLED_ShowNum(4,3,Postion_Menu1_Change_str_right_left,3);

			Key_Menu1_Change_str_right_left=Key_GetNum();
		
		if(Key_Menu1_Change_str_right_left==2)
			{
				Postion_Menu1_Change_str_right_left++;
				if(Postion_Menu1_Change_str==101){Postion_Menu1_Change_str=1;}
				
			}
		if(Key_Menu1_Change_str_right_left==3)
		{
				Postion_Menu1_Change_str_right_left--;
				if(Postion_Menu1_Change_str==0){Postion_Menu1_Change_str=100;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_str_right_left,3);
		if(Key_Menu1_Change_str_right_left==1)
		{
			Content_PWM_str_left_right=Postion_Menu1_Change_str_right_left;
				OLED_Clear();
			return;
		}

	
}

}




void Menu1_Change_str(void)	 //用于进入直行PWM调整页面
{
	OLED_Clear();
	while(1)
	{	OLED_ShowString(1,1,"left&right PWM");
	OLED_ShowString(2,1,"return");

	OLED_ShowNum(4,3,Postion_Menu1_Change_str,1);


			Key_Menu1_Change_str=Key_GetNum();
		
		if(Key_Menu1_Change_str==2)
			{
				Postion_Menu1_Change_str++;
				if(Postion_Menu1_Change_str==3){Postion_Menu1_Change_str=1;}
				
			}
		if(Key_Menu1_Change_str==3)
		{
				Postion_Menu1_Change_str--;
				if(Postion_Menu1_Change_str==0){Postion_Menu1_Change_str=2;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_str,1);
		if(Key_Menu1_Change_str==1)
		{
			if(Postion_Menu1_Change_str==1){Menu1_Change_str_right_left();}
			if(Postion_Menu1_Change_str==2){	OLED_Clear();
				return;}
		}

	
}}
	

//Key_Menu1_Change_x_lef_Left   Postion_Menu1_Change_x_lef_Left

void Menu1_Change_x_lef_Left(void)  //用于调整左微调时左边的PWM
{
	OLED_Clear();
	
	while(1)
	{	OLED_ShowString(1,1,"x_lef_Left");
	OLED_ShowString(2,1,"PWM:");
	
	OLED_ShowNum(4,3,Postion_Menu1_Change_x_lef_Left,3);

			Key_Menu1_Change_x_lef_Left=Key_GetNum();
		
		if(Key_Menu1_Change_x_lef_Left==2)
			{
				Postion_Menu1_Change_x_lef_Left++;
				if(Postion_Menu1_Change_x_lef_Left==101){Postion_Menu1_Change_x_lef_Left=1;}
				
			}
		if(Key_Menu1_Change_x_lef_Left==3)
		{
				Postion_Menu1_Change_x_lef_Left--;
				if(Postion_Menu1_Change_x_lef_Left==0){Postion_Menu1_Change_x_lef_Left=100;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_x_lef_Left,3);
		if(Key_Menu1_Change_x_lef_Left==1)
		{
			Content_PWM_x_lef_Left=Postion_Menu1_Change_x_lef_Left;
				OLED_Clear();
				return;
		}

	
}


}
	
	
	
	//Key_Menu1_Change_x_lef_Right   Postion_Menu1_Change_x_lef_Right

void Menu1_Change_x_lef_right(void) //用于调整左微调时右边的PWM
{
	OLED_Clear();
	
	while(1)
	{	OLED_ShowString(1,1,"x_lef_Right");
	OLED_ShowString(2,1,"PWM:");
	
	OLED_ShowNum(4,3,Postion_Menu1_Change_x_lef_Right,3);

			Key_Menu1_Change_x_lef_Right=Key_GetNum();
		
		if(Key_Menu1_Change_x_lef_Right==2)
			{
				Postion_Menu1_Change_x_lef_Right++;
				if(Postion_Menu1_Change_x_lef_Right==101){Postion_Menu1_Change_x_lef_Right=1;}
				
			}
		if(Key_Menu1_Change_x_lef_Right==3)
		{
				Postion_Menu1_Change_x_lef_Right--;
				if(Postion_Menu1_Change_x_lef_Right==0){Postion_Menu1_Change_x_lef_Right=100;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_x_lef_Right,3);
		if(Key_Menu1_Change_x_lef_Right==1)
		{
			Content_PWM_x_lef_Right=Postion_Menu1_Change_x_lef_Right;
				OLED_Clear();
				return;
		}

	
}

}
		
	
	
	
	
	//Key_Menu1_Change_x_lef   Postion_Menu1_Change_x_lef
void Menu1_Change_x_lef(void){	  //用于选择是调整左微调时左边还是右边的PWM

	OLED_Clear();

	while(1)
	{	OLED_ShowString(1,1,"1->left PWM");
	OLED_ShowString(2,1,"2->right PWM");
	OLED_ShowString(3,1,"3->return");

	OLED_ShowNum(4,3,Postion_Menu1_Change_x_lef,1);

			Key_Menu1_Change_x_lef=Key_GetNum();
		
		if(Key_Menu1_Change_x_lef==2)
			{
				Postion_Menu1_Change_x_lef++;
				if(Postion_Menu1_Change_x_lef==4){Postion_Menu1_Change_x_lef=1;}
				
			}
		if(Key_Menu1_Change_x_lef==3)
		{
				Postion_Menu1_Change_x_lef--;
				if(Postion_Menu1_Change_x_lef==0){Postion_Menu1_Change_x_lef=3;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_x_lef,1);
		if(Key_Menu1_Change_x_lef==1)
		{
			if(Postion_Menu1_Change_x_lef==1){Menu1_Change_x_lef_Left();}
			if(Postion_Menu1_Change_x_lef==2){Menu1_Change_x_lef_right();}
			if(Postion_Menu1_Change_x_lef==3){	OLED_Clear();
				return;}
		}

	

}}
	
void Menu1_Change_x_rig_Left(void)  //用于调整右微调时左边的PWM
{
	OLED_Clear();
	
	while(1)
	{	OLED_ShowString(1,1,"x_rig_Left");
	OLED_ShowString(2,1,"PWM:");
	
	OLED_ShowNum(4,3,Postion_Menu1_Change_x_rig_Left,3);

			Key_Menu1_Change_x_rig_Left=Key_GetNum();
		
		if(Key_Menu1_Change_x_rig_Left==2)
			{
				Postion_Menu1_Change_x_rig_Left++;
				if(Postion_Menu1_Change_x_rig_Left==101){Postion_Menu1_Change_x_rig_Left=1;}
				
			}
		if(Key_Menu1_Change_x_rig_Left==3)
		{
				Postion_Menu1_Change_x_rig_Left--;
				if(Postion_Menu1_Change_x_rig_Left==0){Postion_Menu1_Change_x_rig_Left=100;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_x_rig_Left,3);
		if(Key_Menu1_Change_x_rig_Left==1)
		{
			Content_PWM_x_rig_Left=Postion_Menu1_Change_x_rig_Left;
				OLED_Clear();
				return;
		}

	
}


}
	
	
	


void Menu1_Change_x_rig_right(void) //用于调整左微调时右边的PWM
{
	OLED_Clear();
	
	while(1)
	{	OLED_ShowString(1,1,"x_rig_Right");
	OLED_ShowString(2,1,"PWM:");
	
	OLED_ShowNum(4,3,Postion_Menu1_Change_x_rig_Right,3);

			Key_Menu1_Change_x_rig_Right=Key_GetNum();
		
		if(Key_Menu1_Change_x_rig_Right==2)
			{
				Postion_Menu1_Change_x_rig_Right++;
				if(Postion_Menu1_Change_x_rig_Right==101){Postion_Menu1_Change_x_rig_Right=1;}
				
			}
		if(Key_Menu1_Change_x_rig_Right==3)
		{
				Postion_Menu1_Change_x_rig_Right--;
				if(Postion_Menu1_Change_x_rig_Right==0){Postion_Menu1_Change_x_rig_Right=100;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_x_rig_Right,3);
		if(Key_Menu1_Change_x_rig_Right==1)
		{
			Content_PWM_x_rig_Right=Postion_Menu1_Change_x_rig_Right;
				OLED_Clear();
				return;
		}

	
}

}
		


//uint16_t Postion_Menu1_Change_x_rig=1;  
//uint16_t Key_Menu1_Change_x_rig; 				



void Menu1_Change_x_rig(void)	 //用于选择是调整右微调时左边还是右边的PWM
{	OLED_Clear();

	while(1)
	{	OLED_ShowString(1,1,"1->left PWM");
	OLED_ShowString(2,1,"2->right PWM");
	OLED_ShowString(3,1,"3->return");

	OLED_ShowNum(4,3,Postion_Menu1_Change_x_rig,1);

			Key_Menu1_Change_x_rig=Key_GetNum();
		
		if(Key_Menu1_Change_x_rig==2)
			{
				Postion_Menu1_Change_x_rig++;
				if(Postion_Menu1_Change_x_rig==4){Postion_Menu1_Change_x_rig=1;}
				
			}
		if(Key_Menu1_Change_x_rig==3)
		{
				Postion_Menu1_Change_x_rig--;
				if(Postion_Menu1_Change_x_rig==0){Postion_Menu1_Change_x_rig=3;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_x_rig,1);
		if(Key_Menu1_Change_x_rig==1)
		{
			if(Postion_Menu1_Change_x_rig==1){Menu1_Change_x_rig_Left();}
			if(Postion_Menu1_Change_x_rig==2){Menu1_Change_x_rig_right();}
			if(Postion_Menu1_Change_x_rig==3){	OLED_Clear();
				return;}
		}

	

}
}
	

void Menu1_Change_lef_right(void)   //用于调整左转时左侧的PWM
{
	OLED_Clear();
	
	while(1)
	{	OLED_ShowString(1,1,"lef_Right");
	OLED_ShowString(2,1,"PWM:");
	
	OLED_ShowNum(4,3,Postion_Menu1_Change_lef_Right,3);

			Key_Menu1_Change_lef_Right=Key_GetNum();
		
		if(Key_Menu1_Change_lef_Right==2)
			{
				Postion_Menu1_Change_lef_Right++;
				if(Postion_Menu1_Change_lef_Right==101){Postion_Menu1_Change_lef_Right=1;}
				
			}
		if(Key_Menu1_Change_lef_Right==3)
		{
				Postion_Menu1_Change_lef_Right--;
				if(Postion_Menu1_Change_lef_Right==0){Postion_Menu1_Change_lef_Right=100;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_lef_Right,3);
		if(Key_Menu1_Change_lef_Right==1)
		{
			Content_PWM_lef_Right=Postion_Menu1_Change_lef_Right;
				OLED_Clear();
				return;
		}

	
}
}
	

void Menu1_Change_lef_Left(void)   //用于调整左转时左侧的PWM
{

	OLED_Clear();
	
	while(1)
	{	OLED_ShowString(1,1,"lef_Left");
	OLED_ShowString(2,1,"PWM:");
	
	OLED_ShowNum(4,3,Postion_Menu1_Change_lef_Left,3);

			Key_Menu1_Change_lef_Left=Key_GetNum();
		
		if(Key_Menu1_Change_lef_Left==2)
			{
				Postion_Menu1_Change_lef_Left++;
				if(Postion_Menu1_Change_lef_Left==101){Postion_Menu1_Change_lef_Left=1;}
				
			}
		if(Key_Menu1_Change_lef_Left==3)
		{
				Postion_Menu1_Change_lef_Left--;
				if(Postion_Menu1_Change_lef_Left==0){Postion_Menu1_Change_lef_Left=100;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_lef_Left,3);
		if(Key_Menu1_Change_lef_Left==1)
		{
			Content_PWM_lef_Left=Postion_Menu1_Change_lef_Left;
				OLED_Clear();
				return;
		}

	
}

}
	
//uint16_t Postion_Menu1_Change_lef=1;
//uint16_t Key_Menu1_Change_lef;
	
void Menu1_Change_lef(void)   //用于选择是调整左转时左边还是右边的PWM
{
	OLED_Clear();

	while(1)
	{	OLED_ShowString(1,1,"1->left PWM");
	OLED_ShowString(2,1,"2->right PWM");
	OLED_ShowString(3,1,"3->return");

	OLED_ShowNum(4,3,Postion_Menu1_Change_lef,1);

			Key_Menu1_Change_lef=Key_GetNum();
		
		if(Key_Menu1_Change_lef==2)
			{
				Postion_Menu1_Change_lef++;
				if(Postion_Menu1_Change_lef==4){Postion_Menu1_Change_lef=1;}
				
			}
		if(Key_Menu1_Change_lef==3)
		{
				Postion_Menu1_Change_lef--;
				if(Postion_Menu1_Change_lef==0){Postion_Menu1_Change_lef=3;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_lef,1);
		if(Key_Menu1_Change_lef==1)
		{
			if(Postion_Menu1_Change_lef==1){Menu1_Change_lef_Left();}
			if(Postion_Menu1_Change_lef==2){Menu1_Change_lef_right();}
			if(Postion_Menu1_Change_lef==3){	OLED_Clear();
				return;}
		}

	

}
}
	
	//-------------------------------------------
void Menu1_Change_rig_right(void)   //用于调整右转时右侧的PWM
{
	OLED_Clear();
	
	while(1)
	{	OLED_ShowString(1,1,"rig_Right");
	OLED_ShowString(2,1,"PWM:");
	
	OLED_ShowNum(4,3,Postion_Menu1_Change_rig_Right,3);

			Key_Menu1_Change_rig_Right=Key_GetNum();
		
		if(Key_Menu1_Change_rig_Right==2)
			{
				Postion_Menu1_Change_rig_Right++;
				if(Postion_Menu1_Change_rig_Right==101){Postion_Menu1_Change_rig_Right=1;}
				
			}
		if(Key_Menu1_Change_rig_Right==3)
		{
				Postion_Menu1_Change_rig_Right--;
				if(Postion_Menu1_Change_rig_Right==0){Postion_Menu1_Change_rig_Right=100;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_rig_Right,3);
		if(Key_Menu1_Change_rig_Right==1)
		{
			Content_PWM_rig_Right=Postion_Menu1_Change_rig_Right;
				OLED_Clear();
				return;
		}

	
}
}
	

void Menu1_Change_rig_Left(void)   //用于调整右转时左侧的PWM
{

	OLED_Clear();
	
	while(1)
	{	OLED_ShowString(1,1,"rig_Left");
	OLED_ShowString(2,1,"PWM:");
	
	OLED_ShowNum(4,3,Postion_Menu1_Change_rig_Left,3);

			Key_Menu1_Change_rig_Left=Key_GetNum();
		
		if(Key_Menu1_Change_rig_Left==2)
			{
				Postion_Menu1_Change_rig_Left++;
				if(Postion_Menu1_Change_rig_Left==101){Postion_Menu1_Change_rig_Left=1;}
				
			}
		if(Key_Menu1_Change_rig_Left==3)
		{
				Postion_Menu1_Change_rig_Left--;
				if(Postion_Menu1_Change_rig_Left==0){Postion_Menu1_Change_rig_Left=100;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_rig_Left,3);
		if(Key_Menu1_Change_rig_Left==1)
		{
			Content_PWM_rig_Left=Postion_Menu1_Change_rig_Left;
				OLED_Clear();
				return;
		}

	
}

}
	
//uint16_t Postion_Menu1_Change_lef=1;
//uint16_t Key_Menu1_Change_lef;
	
void Menu1_Change_rig(void)   //用于选择是调整 右转时左边还是右边的PWM
{
	OLED_Clear();

	while(1)
	{	OLED_ShowString(1,1,"1->left PWM");
	OLED_ShowString(2,1,"2->right PWM");
	OLED_ShowString(3,1,"3->return");

	OLED_ShowNum(4,3,Postion_Menu1_Change_rig,1);

			Key_Menu1_Change_rig=Key_GetNum();
		
		if(Key_Menu1_Change_rig==2)
			{
				Postion_Menu1_Change_rig++;
				if(Postion_Menu1_Change_rig==4){Postion_Menu1_Change_rig=1;}
				
			}
		if(Key_Menu1_Change_rig==3)
		{
				Postion_Menu1_Change_rig--;
				if(Postion_Menu1_Change_rig==0){Postion_Menu1_Change_rig=3;}

		}

		OLED_ShowNum(4,3,Postion_Menu1_Change_rig,1);
		if(Key_Menu1_Change_rig==1)
		{
			if(Postion_Menu1_Change_rig==1){Menu1_Change_rig_Left();}
			if(Postion_Menu1_Change_rig==2){Menu1_Change_rig_right();}
			if(Postion_Menu1_Change_rig==3){	OLED_Clear();
				return;}
		}

	

}
}
	
//------------------------------------------------
void Menu1_Change(void) //Menu1_Change函数
{
	OLED_Clear();

	while(1)
	{	OLED_ShowString(1,1,"1->str 2->x_lef");
	OLED_ShowString(2,1,"3->x_rig 4->lef");
	OLED_ShowString(3,1,"5->rig 6->ret");            //1 直行 2 左调整 3 右调整 4 左  5 右 6 退出
	OLED_ShowNum(4,3,Postion_Menu1_Change,1);

			Key_Menu1_Change=Key_GetNum();
		
		if(Key_Menu1_Change==2)
			{
				Postion_Menu1_Change++;
				if(Postion_Menu1_Change==7){Postion_Menu1_Change=1;}
				
			}
		if(Key_Menu1_Change==3)
		{
				Postion_Menu1_Change--;
				if(Postion_Menu1_Change==0){Postion_Menu1_Change=6;}

		}
		
		OLED_ShowNum(4,3,Postion_Menu1_Change,1);
		if(Key_Menu1_Change==1)
		{
			if(Postion_Menu1_Change==1){Menu1_Change_str();}
			if(Postion_Menu1_Change==2){Menu1_Change_x_lef();}
			if(Postion_Menu1_Change==3){Menu1_Change_x_rig();}
			if(Postion_Menu1_Change==4){Menu1_Change_lef();}
			if(Postion_Menu1_Change==5){Menu1_Change_rig();}
			if(Postion_Menu1_Change==6){
				OLED_Clear();
				return;}
		}

	}
}	





void Menu1(void)     //主界面
{
	OLED_Clear();
	

	while(1)
	{OLED_ShowString(1,1,"1->start");
	OLED_ShowString(2,1,"2->change");
		Key_Menu1=Key_GetNum();
		
		if(Key_Menu1==2)
			{
				Postion_Menu1++;
				if(Postion_Menu1==3){Postion_Menu1=1;}
				
			}
		if(Key_Menu1==3)
		{
				Postion_Menu1--;
				if(Postion_Menu1==0){Postion_Menu1=2;}

		}
		
		OLED_ShowNum(4,3,Postion_Menu1,1);
		if(Key_Menu1==1)
		{
			if(Postion_Menu1==1){Menu1_Start();}
			if(Postion_Menu1==2){Menu1_Change();}
		}
	}

}
