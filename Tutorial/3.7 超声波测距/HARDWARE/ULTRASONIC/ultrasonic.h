#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

#define uchar unsigned char
#define uint unsigned int

sbit echo = P3^3;
sbit trig = P3^4;
void Ultra_Init(void);
void Delay_us(uint z);
void  Ultra_Start(void);
void Conut(void);
void Ultra_Show(void);
void Ultra_Work(void);

#endif
