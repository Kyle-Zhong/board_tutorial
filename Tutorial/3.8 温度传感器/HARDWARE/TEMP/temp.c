#include "stc12.h"
#include "temp.h"
#include "digitron.h"
#include "intrins.h"

//微秒延时函数
//具体延时实验需要debug来测量
void Delay_us(uint n)
{
    while (n--)
    {
        _nop_();
        _nop_();
    }
}

//温度传感器复位函数
void Temp_Init(void)
{
	uint x = 1;
	
	while(x)
	{
		DA = 0;//拉低数据线
		Delay_us(480);//等待480us
		DA = 1;//释放数据线
		Delay_us(60);//等待60us
		x = DA;//检查DS18B20是否有响应
		Delay_us(420);//等待DS8B20释放数据线
	}	
}

//给DB18B20写一节数据
void Temp_Write(uchar dat)
{
	uchar i;

	for(i = 0;i < 8;i++)
	{
		//写数据时序
		DA = 0;
		Delay_us(1);
		DA = 1;

		//发送数据
		dat >>= 1;
		DA = CY;

		Delay_us(20);

		DA = 1;
		Delay_us(1);
	}
}

//从DB18B20读一节数据
uchar Temp_Read(void)
{
    uchar i;
    uchar dat = 0;

    for (i = 0;i < 8;i++)//读取一节8位数据
    {
        dat >>= 1;

		//读数据时序
        DA = 0;                   
        Delay_us(1);               
        DA = 1;                   
        Delay_us(1);
		
		//读取数据                
        if(DA) 
			dat |= 0x80; 
		
		//等待读取结束	      
        Delay_us(60);              
    }

    return dat;
}

//温度显示函数
void Temp_Show(void)
{
	uint temp;
	uchar th,tl;

	//开始AD转换指令
	Temp_Init();
	Temp_Write(0XCC);
	Temp_Write(0X44);

	while(!DA);//等待转换完成

	//读取暂存存储器数据指令
	Temp_Init();
	Temp_Write(0XCC);
	Temp_Write(0XBE);

	tl = Temp_Read();//读取温度低字节
	th = Temp_Read();//读取温度高字节

	//合成高低温度数据，取低字节高4位和高字节低三位，得到温度的整数值
	tl = (tl & 0XF0) >> 4;
	temp = th;
	temp <<= 4;
	temp |= tl;

	Digi_Num(temp);
}
