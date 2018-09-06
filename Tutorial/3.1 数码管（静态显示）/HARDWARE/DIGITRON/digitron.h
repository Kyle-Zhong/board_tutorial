#ifndef _DIGITRON_H_
#define _DIGITRON_H_

#define uint unsigned int
#define uchar unsigned char

sbit DIG1 = P4^0;//4个位选
sbit DIG2 = P4^1;
sbit DIG3 = P4^4;
sbit DIG4 = P4^5;
sbit EN1 = P0^5;//锁存器使能端

void Digi_Init(void);
void Digi_Show(uchar a,uchar b,uchar c,uchar num);
void Digi_Test(void);
void Delay_ms(uint z);

#endif