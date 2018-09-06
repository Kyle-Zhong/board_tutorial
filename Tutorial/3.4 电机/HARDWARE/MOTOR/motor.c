#include "stc12.h"
#include "motor.h"

//电机初始化函数
void Motor_Init(void)
{
	CCON = 0X00;//初始化CCON
			  //关闭PCA计数器
			  //清除PCA阵列溢出标志位CF
   			  //清除模块0、模块1中断标志位CCF0、CCF1

	CL = 0;//清零计数器
	CH = 0;

	CMOD = 0X0A;//设置PCA工作模式
         		//空闲模式下PCA计数器继续工作
				//PCA计数器计数频率为系统时钟频率的1/4
				//关闭PCA计数器溢出中断

	CCAP0H = CCAP0L = 0XFF;//PWM0输出频率为11KHz占空比为0%的PWM信号,在P1.3输出
	CCAPM0 = 0X42;//模块0为PWM输出模式
				  //没有PCA中断

	CCAP1H = CCAP1L = 0XFF;//PWM1输出频率为11KHz占空比为0%的PWM信号,在P1.4输出
	CCAPM1 = 0X42;//模块1为PWM输出模式
				  //没有PCA中断

	CR = 1;//启动PCA计数器
}

//电机1控制函数
//pos1控制电机1状态，BACK后退，STOP停止，FORW前进
//pwm1控制电机1转速，pwm1越大转速越大，取值范围为0~50
void Motor1(uchar pos1,uchar pwm1)
{
	//判断电机状态
	switch(pos1)
	{
		case 0 : AIN1 = 1;
				 AIN2 = 0;
		break;
		case 1 : AIN1 = 1;
				 AIN2 = 1;
		break;
		case 2 : AIN1 = 0;
				 AIN2 = 1;
		break;
		default : AIN1 = 1;
				  AIN2 = 1;
	}

	//调整电机转速
	if(pwm1 >= 0 && pwm1 <= 50)
	{
		pwm1 = 250 - pwm1;
		
		CCAP0H = CCAP0L = pwm1;
	}
	else
		CCAP0H = CCAP0L = 255;
}

//电机2控制函数
//pos2控制电机2状态，BACK后退，STOP停止，FORW前进
//pwm2控制电机2转速，pwm2越大转速越大，取值范围为0~50
void Motor2(uchar pos2,uchar pwm2)
{
	//判断电机状态
	switch(pos2)
	{
		case 0 : BIN1 = 1;
				 BIN2 = 0;
		break;
		case 1 : BIN1 = 1;
				 BIN2 = 1;
		break;
		case 2 : BIN1 = 0;
				 BIN2 = 1;
		break;
		default : BIN1 = 1;
				  BIN2 = 1;
	}

	//调整电机转速
	if(pwm2 >= 0 && pwm2 <= 50)
	{	
		pwm2 = 250 - pwm2;
			
		CCAP1H = CCAP1L = pwm2;
	}
	else
		CCAP1H = CCAP1L = 255;
}

//电机驱动函数
//直接控制小车两个电机运动
void Car_Run(int speed1,int speed2)
{
	//电机1方向控制及速度控制
	if(speed1 >= 0)
	{
		Motor1(FORW,speed1);
	}
	else
	{
		speed1 = -speed1;

		Motor1(BACK,speed1);
	}

	//电机2方向控制及速度控制
	if(speed2 >= 0)
	{
		Motor2(FORW,speed2);
	}
	else
	{
		speed2 = -speed2;

		Motor2(BACK,speed2);
	}	
}
