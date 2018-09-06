#ifndef _IIC_H_
#define _IIC_H_

#define uint unsigned int
#define uchar unsigned char

sbit SCL=P3^6;
sbit SDA=P3^7;

void IIC_Start(void);
void IIC_Stop(void);
void IIC_Write(unsigned char Byte);
uchar IIC_Read(void);

#endif