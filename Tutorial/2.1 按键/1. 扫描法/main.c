/*------------------------*/
//傀儡师实验板配套例程
//实验名称：按键-扫描法
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月25日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"
#include "intrins.h"

#define uint unsigned int
#define LED P0

void Delay_ms(uint z);

sbit key0 = P3^1;
sbit key2 = P4^3;

void main()
{
	LED = 0XFE;//点亮LED0

	while(1)
	{
		if(key0 == 0)//检测按键key0
		{
			Delay_ms(10);
			if(key0 == 0)//消抖
			{
				LED = _cror_(LED,1);//LED灯右移一位

				while(!key0);//松手检测
			}
		}

		if(key2 == 0)//检测按键key2
		{
			Delay_ms(10);
			if(key2 == 0)//消抖
			{
				LED = _crol_(LED,1);//LED灯左移一位

				while(!key2);//松手检测
			}
		}
	}
}

void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}
