#include "stc12.h"
#include "born.h"

/*---------------------
53-低音1    26-中音1  	 
50-低音1#   25-中音1#	 
47-低音2	24-中音2	 
44-低音2#   23-中音2#	 
42-低音3	21-中音3	
40-低音4	20-中音4	
38-低音4#   19-中音4#	 
36-低音5	17-中音5	
34-低音5#   16-中音5#	 
32-低音6	15-中音6	 
30-低音6#   14-中音6#
28-低音7	13-中音7	 
----------------------*/

//模拟正弦波所需的数组
uchar code table[] = 
{
0X80,0X54,0X2D,0X03,0X02,
0X02,0X03,0X2D,0X54,0X80,
0XAA,0XD1,0XEF,0XFC,0XFC,
0XEF,0XD1,0XAA
};

//喇叭初始化函数
void Born_Init(void)
{
	CCON = 0X00;//初始化CCON
			  //关闭PCA计数器
			  //清除PCA阵列溢出标志位CF
   			  //清除模块0、模块1中断标志位CCF0、CCF1

	AUXR1 = 0X7F;//翻转，在P4.2输出

	CL = 0;//清零计数器
	CH = 0;

	CMOD = 0X08;//设置PCA工作模式
         		//空闲模式下PCA计数器继续工作
				// PCA计数器计数频率为12MHz
				//关闭PCA计数器溢出中断

	CCAP0H = CCAP0L = 0X80;//PWM0输出频率为46K,占空比为50%的PWM信号

	CCAPM0 = 0X42;//模块0为PWM输出0模式       			     
				  //没有PCA中断

	CR = 1;//启动PCA计数器
	EN = 0;
}

//音调函数
//pit控制音调，取值范围为上方注释中的值
void Pitch(uint pit)
{
	uint x,y;

	y = BEAT;

	while(y--)
	{
		for(x = 0;x < 18;x++)
		{
			CCAP0H = CCAP0L = table[x];
			Delay_4us(pit);
		}
	}
}

//演奏音乐函数
//型参为音乐数组名字
void Music(uint *musictable)
{
	uint x;

	for(x = 0;musictable[x] != 255;x++)
	{
		Pitch(musictable[x]);
	}
}

//4us延时函数
void Delay_4us(uint z)
{
	while(z--);
}
