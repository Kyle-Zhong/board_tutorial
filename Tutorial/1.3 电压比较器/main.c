/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ���ѹ�Ƚ���
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��8��26��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"

//�����������������ż���ѹ�Ƚ����ɼ�����
sbit beep = P1^5;
sbit comp1 = P1^6;
sbit comp2 = P1^7;

void Beep(int n);
void Delay_ms(int m);

void main()
{
	while(comp1 == 0 && comp2 == 0)//����������
	{
		beep = 1;
	}
	while(comp1 == 0 && comp2 == 1)//������1����һ��
	{
		Beep(1000);
	}
	while(comp1 == 1 && comp2 == 1)//������0.1����һ��
	{
		Beep(100);
	}
}

//��������������
void Beep(int n)
{
	beep = 1;
	Delay_ms(n);
	beep = 0;
	Delay_ms(n);	
}

//������ʱ���������2us
void Delay_ms(int m)
{
	int x,y;

	for(x = m;x > 0;x--)
		for(y = 921;y > 0;y--);
}