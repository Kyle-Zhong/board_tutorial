/*------------------------*/
//傀儡师实验板配套例程
//实验名称：按键-中断法
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"
#include "intrins.h"

#define uint unsigned int
#define LED P0

void Con_Init(void);

void main()
{
	P0 = 0XFE;
	Con_Init();

	while(1);
}

//外部中断初始化函数
void Con_Init(void)
{
	//设置外部中断0
	IT0 = 1;//设置外部中断0下降沿捕获
	EX0 = 1;//打开外部中断0中断允许

	//设置外部中断1
	IT1 = 1;// 设置外部中断1下降沿捕获
	EX1 = 1;// 打开外部中断1中断允许

	EA = 1;//打开总中断
}

//外部中断0服务函数
void Key0_Handler(void) interrupt 0
{
	LED = _cror_(LED,1);
}

//外部中断1服务函数
void Key1_Handler(void) interrupt 2
{
	LED = _crol_(LED,1);
}