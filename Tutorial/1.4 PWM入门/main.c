/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ�PWM����
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��8��4��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"

#define uint unsigned int

void Delay_ms(uint z);
void PWM(uint x);

sbit led = P0^0;

void main()
{
	while(1)
	{
		PWM(1);//PWMƵ��Ϊ50Hz��ռ�ձ�Ϊ95%
	}
}

//PWM��������
void PWM(uint x)
{
	led = 1;
	Delay_ms(20 - x);
	led = 0;
	Delay_ms(x);
}

//������ʱ���������2us
void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}
