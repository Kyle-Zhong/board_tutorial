#include "stc12.h"
#include "remote.h"
#include "digitron.h"

uchar retime;//记录高电平时间
uchar bitnum;//数据的位数
uchar startflag;//红外接收开始标志位
uchar reciveflag;//红外数据接收完成标志位
uchar finishflag;//红外数据处理完成标志位

uchar redata[33];//存放红外数据
uchar recode[4];//存放用户码和4个键值

uchar num = 0;//

//定时器0初始化函数
void Timer0_Init(void)
{
	TMOD = 0X02;//设置成工作方式2
	TH0 = TL0 = 0;

	ET0 = 1;//打开定时器0中断
	EA = 1;//打开总中断
	TR0 = 1;//启动定时器
}

//定时器0中断服务函数
void Timer0_Handler(void) interrupt 1
{
	retime++;
}

//外部中断0初始化函数
void Init0_Init(void)
{
	IT0 = 1;//设置成下降沿触发
	EX0 = 1;//打开外部中断0
	EA = 1;//打开总中断
}

//外部中断0服务函数
void Init0_Handler(void) interrupt 0
{
	//如果已经是在接收当中，则继续接收
	if(startflag)
	{
		//检测到用户码，开始接收数据
		if(retime < 63 && retime > 32)
			bitnum = 0;

		redata[bitnum] = retime;//记录每次高电平的时间
		retime = 0;
		bitnum++;

		if(bitnum == 33)//判断是否接收完成
		{
			bitnum = 0;
			reciveflag = 1;//置1接收完成标志位，表示接收已经完成
		}
	}
	else//否则开始接收
	{
		startflag = 1;//置1开始标志位
		retime = 0;
	}
}

//红外数据处理函数
void Remote_Handler(void)
{
	uchar k,x,y;
	uchar value;

	k = 1;

	for(x = 0;x < 4;x++)//取4组数据
	{
		for(y = 0;y <= 8;y++)//每组数据8位
		{
			value >>= 1;

			//判断红外数据是1还是0
			//如果高电平时间大于6*255us即1.53ms，则为高电平
			if(redata[k] > 7)
				value |= 0X80;

			k++;
		}

		recode[x] = value;
		value = 0;
	}

	finishflag = 1;//置1处理完成标志位
}

//红外键值判断函数
uchar Remote_Count(void)
{
	uchar key;
	
	switch(recode[2])
	{
		case 34  : key = 0;
			break;
		case 97  : key = 1;
			break;
		case 227 : key = 2;
			break;
		case 43  : key = 3;
			break;
		case 225 : key = 4;
			break;
		case 99  : key = 5;
			break;
		case 171 : key = 6;
			break;
		case 168 : key = 7;
			break;
		case 170 : key = 8;
			break;
		case 169 : key = 9;
			break;
		default : key = 9;
	}

	return key;	
}

//红外遥控解码函数
//在数码管上显示键值
uint Remote_Work(void)
{
	if(reciveflag == 1)
	{
		reciveflag =0;
		Remote_Handler();
	}
	if(finishflag == 1)
	{
		finishflag = 0;
		num = Remote_Count();
	}

	Digi_Num(num);

	return num;
}

//红外遥控控制LED函数
void Remote_ConLED(void)
{
	uint key;

	key = Remote_Work();

	switch(key)
	{
		case 0 : P0 = 0XFF;
			break;
		case 1 : P0 = 0X7F;
			break;
		case 2 : P0 = 0XBF;
			break;
		case 3 : P0 = 0XDF;
			break;
		case 4 : P0 = 0XEF;
			break;
		case 5 : P0 = 0XF7;
			break;
		case 6 : P0 = 0XFB;
			break;
		case 7 : P0 = 0XFD;
			break;
		case 8 : P0 = 0XFE;
			break;
		case 9 : P0 = 0X00;
			break;
		default : P0 = 0XFF;
	}
}
