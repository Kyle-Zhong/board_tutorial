/*------------------------*/
//傀儡师实验板配套例程
//实验名称：定时器
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"

#define uint unsigned int

void Timer_Init();

sbit beep = P0^3;

uint a;

void main()
{
	beep = 1;

	Timer_Init();

	while(1);
}

//定时器初始化函数
void Timer_Init()
{
	TMOD = 0X01;
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;

	TR0 = 1;
	ET0 = 1;
	EA = 1;
}

//定时器0中断服务函数
void Timer0_Handler() interrupt 1
{
	a++;
	
	if(a == 20)//定时器每20次，即1s进入一次该函数
	{
		a = 0;//清零，为下一次计时做准备

		beep = ~beep;
	}	
}				 