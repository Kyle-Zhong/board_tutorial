#ifndef _STREEING_H_
#define	_STREEING_H_

#define uint unsigned int
#define uchar unsigned char

void Steering_Init(void);
void Timer0_Init(void);
void Steering1(uchar angle1);
void Steering2(uchar angle2);
void Steering_Test(void);
void Delay_ms(uint z);

#endif