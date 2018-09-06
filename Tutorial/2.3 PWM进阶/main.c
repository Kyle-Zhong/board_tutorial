/*------------------------*/
//傀儡师实验板配套例程
//实验名称：PWM进阶
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"

void PCA_Init();

void main()
{
	PCA_Init();

	while(1);
}

//PCA初始化函数
void PCA_Init()
{
	CCON = 0X00;//初始化CCON
			    //关闭PCA计数器

	//清零计数器
	CL = 0;
	CH = 0;

	CMOD = 0X0E;//设置PCA工作模式
         		//空闲模式下PCA计数器继续工作
				//PCA计数器计数频率为系统时钟/8
				//关闭PCA计数器溢出中断

	CCAP0H = CCAP0L = 0XF3;//PWM0输出频率为5.8KHz，占空比为5%的PWM信号
	CCAPM0 = 0X42;//模块0为PWM输出模式
       			  //不翻转，在P1.3输出
				  //没有PCA中断

	CR = 1;//启动PCA计数器
}