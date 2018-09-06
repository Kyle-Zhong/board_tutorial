/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ���ʱ��
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��8��4��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"

#define uint unsigned int

void Timer_Init();

sbit beep = P0^3;

uint a;

void main()
{
	beep = 1;

	Timer_Init();

	while(1);
}

//��ʱ����ʼ������
void Timer_Init()
{
	TMOD = 0X01;
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;

	TR0 = 1;
	ET0 = 1;
	EA = 1;
}

//��ʱ��0�жϷ�����
void Timer0_Handler() interrupt 1
{
	a++;
	
	if(a == 20)//��ʱ��ÿ20�Σ���1s����һ�θú���
	{
		a = 0;//���㣬Ϊ��һ�μ�ʱ��׼��

		beep = ~beep;
	}	
}				 