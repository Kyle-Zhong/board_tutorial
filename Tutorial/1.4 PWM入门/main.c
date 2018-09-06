/*------------------------*/
//傀儡师实验板配套例程
//实验名称：PWM入门
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"

#define uint unsigned int

void Delay_ms(uint z);
void PWM(uint x);

sbit led = P0^0;

void main()
{
	while(1)
	{
		PWM(1);//PWM频率为50Hz，占空比为95%
	}
}

//PWM产生函数
void PWM(uint x)
{
	led = 1;
	Delay_ms(20 - x);
	led = 0;
	Delay_ms(x);
}

//毫秒延时函数，误差2us
void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}
