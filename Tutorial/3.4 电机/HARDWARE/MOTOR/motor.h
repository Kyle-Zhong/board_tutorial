#ifndef _MOTOR_H
#define	_MOTOR_H

#define uint unsigned int
#define uchar unsigned char

#define FORW 2
#define STOP 1
#define BACK 0

sbit AIN1 = P0^0;
sbit AIN2 = P0^1;
sbit BIN1 = P0^2; 
sbit BIN2 = P0^3;

void Motor_Init(void);
void Motor1(uchar pos1,uchar pwm1);
void Motor2(uchar pos2,uchar pwm2);
void Car_Run(int speed1,int speed2);

#endif