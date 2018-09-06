/*------------------------*/
//傀儡师实验板配套例程
//实验名称：流水灯
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年10月6日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"
#include "intrins.h"

#define uint unsigned int//宏定义，用uint代替unsigned int

void Delay_ms(uint z);//声明毫秒延时函数

void main()
{
	P0 = 0XFE;

	while(1)
	{
		P0 = _crol_(P0,1);//循环左移
	
		Delay_ms(200);
	}
}

//毫秒延时函数，误差2us
void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}
