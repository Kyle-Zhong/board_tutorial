#ifndef _DS18B20_H_
#define	_DS18B20_H_

#define uint unsigned int
#define uchar unsigned char

sbit DA = P1^1;

void Temp_Init(void);
void Temp_Write(uchar dat);
uchar Temp_Read(void);
void Temp_Show(void);
void Delay_us(uint n);

#endif