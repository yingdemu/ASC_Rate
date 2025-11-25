#ifndef __SERIAL_H
#define __SERIAL_H

void Serial_Init(void);
int8_t Serial_GetMode(void); //1->直行 2->左小  3->右小  4->左  5->右
int8_t Serial_GetState(void);
void Serial_Tick(void);


#endif
