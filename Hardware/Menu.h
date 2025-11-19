#ifndef __MENU_H
#define __MENU_H

void Menu1(void) ;    //主界面
void Menu1_Change(void); //Menu1_Change函数
void Menu1_Change_rig(void)  ; //用于选择是调整 右转时左边还是右边的PWM
void Menu1_Change_rig_Left(void)  ; //用于调整右转时左侧的PWM
void Menu1_Change_rig_right(void) ;  //用于调整右转时右侧的PWM
void Menu1_Change_lef(void);   //用于选择是调整左转时左边还是右边的PWM
void Menu1_Change_lef_Left(void);   //用于调整左转时左侧的PWM
void Menu1_Change_lef_right(void);   //用于调整左转时左侧的PWM
void Menu1_Change_x_rig(void);	 //用于选择是调整右微调时左边还是右边的PWM
void Menu1_Change_x_rig_right(void); //用于调整左微调时右边的PWM
void Menu1_Change_x_rig_Left(void);  //用于调整右微调时左边的PWM
void Menu1_Change_x_lef(void);	  //用于选择是调整左微调时左边还是右边的PWM
void Menu1_Change_x_lef_right(void); //用于调整左微调时右边的PWM
void Menu1_Change_x_lef_Left(void);  //用于调整左微调时左边的PWM
void Menu1_Change_str(void);	 //用于进入直行PWM调整页面
void Menu1_Change_str_right_left(void);  //控制前进PWM的函数
void Menu1_Start(void); //Menu1_Start函数


#endif
