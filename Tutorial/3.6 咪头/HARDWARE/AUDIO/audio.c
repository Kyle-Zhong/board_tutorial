#include "stc12.h"
#include "audio.h"
#include "digitron.h"

//咪头初始化函数
void Audio_Init(void)
{
	P1ASF = 0X01;//P1.0作为AD功能使用
	ADC_CONTR = 0XE0;//打开AD转换器电源
					 //最快AD转换速度，每90个时钟周期转换一次
					 //将P1.0作为ADC输入

	ADC_RES = 0X00;//清零AD转换结果寄存器
}

//咪头数据读取函数
uchar Audio_Read(void)
{
	uchar valu,ADC_FLAG;

	ADC_CONTR |= 0X08;//启动AD转换

	ADC_FLAG = (ADC_CONTR & 0X10) >> 4;//提取AD转换完成标志

	if(ADC_FLAG == 1)//检查是否完成转换
	{
		ADC_CONTR &= 0XEF;//清零转换标志

		valu =  ADC_RES;
	}

	return valu;
}

//咪头数据显示函数
void Audio_Show(void)
{
   uchar value;

   value =  Audio_Read();//读取AD数据

   Digi_Num(value);//在数码管中显示数据
}