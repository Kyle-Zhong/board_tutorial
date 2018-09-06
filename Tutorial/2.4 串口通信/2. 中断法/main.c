/*------------------------*/
//傀儡师实验板配套例程
//实验名称：串口通讯-中断法
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"

#define uchar unsigned char

void Usart_Init();//串口初始化函数

void main()
{
	Usart_Init();//串口初始化

	while(1);
}

//串口初始化函数
void Usart_Init()
{
	TMOD = 0X20;//设置定时器1工作模式2
	TH1 = 0XFD;//波特率9600
	TL1 = 0XFD;

	REN = 1;//串口允许接收
	SM0 = 0;//设置串口1工作模式1
	SM1 = 1;

	ES = 1;//打开串口中断允许
	EA = 1;//打开总中断允许
	TR1 = 1;//启动定时器1
}

//串口中断服务函数
void USART_Handler() interrupt 4
{
	uchar a;

	RI = 0;//清除串口接收标志位
	
	a = SBUF;//串口接收数据
	P0 = a;
	SBUF = a;//串口发送数据

	while(!TI);//检测串口发送标志位，当发送完成时TI置1
	TI = 0;//清除串口发送标志位
}
