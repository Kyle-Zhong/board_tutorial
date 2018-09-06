#ifndef _DIGITRON_H_
#define _DIGITRON_H_

#define uint unsigned int
#define uchar unsigned char

sbit DIG1 = P4^0;//4��λѡ
sbit DIG2 = P4^1;
sbit DIG3 = P4^4;
sbit DIG4 = P4^5;
sbit EN1 = P0^5;//������ʹ�ܶ�

void Digi_Init(void);
void Digi_Show(uchar a,uchar b,uchar c,uchar num);
void Digi_Test(void);
void Delay_ms(uint z);

#endif