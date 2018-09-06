#include "stc12.h"
#include "intrins.h"
#include "ultrasonic.h"
#include "digitron.h"

uint Time;
float Distance;
uint Overflow_Flag;

//��������ʼ������
void Ultra_Init(void)
{
	TMOD = 0x01;

	TH0 = 0;
	TL0 = 0; 

	TR0 = 1; 	 
	ET0 = 1;
	EA = 1;
}

//��ʱ��0�жϷ�����
void Time0_Handler() interrupt 1
{
	Overflow_Flag = 1;
}

//΢����ʱ����
//������ʱʱ����Ҫdebug������	
void Delay_us(uint z)
{
	while(z--);
}

//��������������
void  Ultra_Start(void) 		
{
	trig = 1;
	Delay_us(6);
	trig = 0;
}

//���������ݴ�����
void Ultra_Conut(void)
{
	 Time = TH0*256+TL0;
	 TH0 = 0;
	 TL0 = 0;
	 Distance = Time * 0.017;
}

//��������ʾ����
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

//��������������
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
