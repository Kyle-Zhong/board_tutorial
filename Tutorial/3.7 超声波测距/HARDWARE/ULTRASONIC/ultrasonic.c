#include "stc12.h"
#include "intrins.h"
#include "ultrasonic.h"
#include "digitron.h"

uint Time;
float Distance;
uint Overflow_Flag;

//超声波初始化函数
void Ultra_Init(void)
{
	TMOD = 0x01;

	TH0 = 0;
	TL0 = 0; 

	TR0 = 1; 	 
	ET0 = 1;
	EA = 1;
}

//定时器0中断服务函数
void Time0_Handler() interrupt 1
{
	Overflow_Flag = 1;
}

//微妙延时函数
//具体延时时间需要debug来决定	
void Delay_us(uint z)
{
	while(z--);
}

//超声波启动函数
void  Ultra_Start(void) 		
{
	trig = 1;
	Delay_us(6);
	trig = 0;
}

//超声波数据处理函数
void Ultra_Conut(void)
{
	 Time = TH0*256+TL0;
	 TH0 = 0;
	 TL0 = 0;
	 Distance = Time * 0.017;
}

//超声波显示函数
void Ultra_Show(void)
{
 	if(Overflow_Flag == 1)
	{
		Overflow_Flag = 0;
		Digi_Num(9999);
	}
	else
		Digi_Num(Distance);
}

//超声波工作函数
void Ultra_Work(void)
{
	 Ultra_Start();

	 while(!echo);
	 TR0 = 1;	
	 while(echo);
	 TR0 = 0;

   	 Ultra_Conut();		

	 Ultra_Show();
}
