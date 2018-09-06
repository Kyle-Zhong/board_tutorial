#include "stc12.h"
#include "intrins.h"
#include "rgbled.h"

uchar bdata LED_DAT;
sbit bit0 = LED_DAT^0;
sbit bit1 = LED_DAT^1;
sbit bit2 = LED_DAT^2;
sbit bit3 = LED_DAT^3;
sbit bit4 = LED_DAT^4;
sbit bit5 = LED_DAT^5;
sbit bit6 = LED_DAT^6;
sbit bit7 = LED_DAT^7;

uchar RGB_DATA[3] = {0x00,0x00,0X00};

//毫秒延时函数，误差2us
void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}

//RGBLED复位函数
void RGBLED_Rest(void)
{
	uint x;
	for(x = 50;x > 0;x--);
}

//RGBLED数据发送函数
void Send_Data(uchar *dat)
{
	LED_DAT = *dat++;
	if(bit7 == 1)
		CODE1
	else
		CODE0
	if(bit6 == 1)
		CODE1
	else
		CODE0
	if(bit5 == 1)
		CODE1
	else
		CODE0
	if(bit4 == 1)
		CODE1
	else
		CODE0
	if(bit3 == 1)
		CODE1
	else
		CODE0
	if(bit2 == 1)
		CODE1
	else
		CODE0;
	if(bit1 == 1)
		CODE1
	else
		CODE0
	if(bit0 == 1)
		CODE1
	else
		CODE0

	LED_DAT = *dat++;
	if(bit7 == 1)
		CODE1
	else
		CODE0
	if(bit6 == 1)
		CODE1
	else
		CODE0
	if(bit5 == 1)
		CODE1
	else
		CODE0;
	if(bit4 == 1)
		CODE1
	else
		CODE0;
	if(bit3 == 1)
		CODE1
	else
		CODE0
	if(bit2 == 1)
		CODE1
	else
		CODE0;
	if(bit1 == 1)
		CODE1
	else
		CODE0;
	if(bit0 == 1)
		CODE1
	else
		CODE0

	LED_DAT = *dat;
	if(bit7 == 1)
		CODE1
	else
		CODE0
	if(bit6 == 1)
		CODE1
	else
		CODE0
	if(bit5 == 1)
		CODE1
	else
		CODE0
	if(bit4 == 1)
		CODE1
	else
		CODE0
	if(bit3 == 1)		 
		CODE1
	else
		CODE0
	if(bit2 == 1)
		CODE1
	else
		CODE0
	if(bit1 == 1)
		CODE1
	else
		CODE0
	if(bit0 == 1)
		CODE1
	else
		CODE0					
}

void RGBLED_Init(void)
{
	P4SW = 0X40;
}

//RGBLED设置函数
//R、G、B分别为红色、绿色和蓝色的颜色值，取值范围为0~255
void RGBLED_Set(uchar R,uchar G,uchar B)
{
	RGB_DATA[0] = G;
	RGB_DATA[1] = R;
	RGB_DATA[2] = B;

	RGBLED_Rest();
	Send_Data(RGB_DATA);
}		  

//RGBLED演示
void RGBLED_Test(void)
{
	uint r = 100,g,b;

	for(g = 0;g < 100;g++)
	{
		RGBLED_Set(r,g,b);

		Delay_ms(5);
	}

	for(r = 100;r > 0;r--)
	{
		RGBLED_Set(r,g,b);

		Delay_ms(5);
	}

	for(b = 0;b < 100;b++)
	{
		RGBLED_Set(r,g,b);

		Delay_ms(5);
	}

	for(g = 100;g > 0;g--)
	{
		RGBLED_Set(r,g,b);

		Delay_ms(5);
	}

	for(r = 0;r < 100;r++)
	{
		RGBLED_Set(r,g,b);

		Delay_ms(5);
	}

	for(b = 100;b > 0;b--)
	{
		RGBLED_Set(r,g,b);

		Delay_ms(5);
	}
}