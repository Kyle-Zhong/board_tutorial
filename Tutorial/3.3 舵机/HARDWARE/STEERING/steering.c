#include "stc12.h"
#include "steering.h"

//舵机初始化函数
void Steering_Init(void)
{
	CCON = 0X00;//初始化CCON
			  //关闭PCA计数器
			  //清除PCA阵列溢出标志位CF
   			  //清除模块0、模块1中断标志位CCF0、CCF1

	AUXR1 = 0X7F;//输出翻转，从P4.2和P4.3输出

	CL = 0;//清零计数器
	CH = 0;

	CMOD = 0X04;//设置PCA工作模式
         		//空闲模式下PCA计数器继续工作
				//PCA计数器计数频率取决于定时器0溢出率
				//关闭PCA计数器溢出中断

	CCAP0H = CCAP0L = 0XE0;//PWM0输出频率为50Hz占空比为5%的PWM信号,在P4.2输出
	CCAPM0 = 0X42;//模块0为PWM输出模式
				  //没有PCA中断

	CCAP1H = CCAP1L = 0XE0;//PWM1输出频率为50Hz占空比为5%的PWM信号,在P4.3输出
	CCAPM1 = 0X42;//模块1为PWM输出模式
				  //没有PCA中断

	CR = 1;//启动PCA计数器
}

//定时器0初始化函数
void Timer0_Init(void)
{
	TMOD = 0X02;

	TL0 = TH0 = 256 - 78;

	TR0 = 1;
	ET0 = 1;
	EA = 1; 
}

//舵机1角度控制函数，180°分25等份每份约7度，即angle1越大转的角度越大，angle1取值范围为0~25
//初始化时舵机的角度为0°
void Steering1(uchar angle1)
{
	CCAP0H = CCAP0L = 0XE0 + angle1;
}

//舵机2角度控制函数，180°分25等份每份约7度，即angle2越大转的角度越大，angle2取值范围为0~25
//初始化时舵机的角度为0°
void Steering2(uchar angle2)
{
	CCAP1H = CCAP1L = 0XE0 + angle2;
}

void Steering_Test(void)
{
	 Steering1(2);
	 Steering2(12);
}
