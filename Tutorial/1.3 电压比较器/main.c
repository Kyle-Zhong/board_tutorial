/*------------------------*/
//傀儡师实验板配套例程
//实验名称：电压比较器
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月26日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"

//声明蜂鸣器控制引脚及电压比较器采集引脚
sbit beep = P1^5;
sbit comp1 = P1^6;
sbit comp2 = P1^7;

void Beep(int n);
void Delay_ms(int m);

void main()
{
	while(comp1 == 0 && comp2 == 0)//蜂鸣器不响
	{
		beep = 1;
	}
	while(comp1 == 0 && comp2 == 1)//蜂鸣器1秒响一次
	{
		Beep(1000);
	}
	while(comp1 == 1 && comp2 == 1)//蜂鸣器0.1秒响一次
	{
		Beep(100);
	}
}

//蜂鸣器警报函数
void Beep(int n)
{
	beep = 1;
	Delay_ms(n);
	beep = 0;
	Delay_ms(n);	
}

//毫秒延时函数，误差2us
void Delay_ms(int m)
{
	int x,y;

	for(x = m;x > 0;x--)
		for(y = 921;y > 0;y--);
}