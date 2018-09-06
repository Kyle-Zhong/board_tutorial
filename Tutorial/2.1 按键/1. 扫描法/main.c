/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ�����-ɨ�跨
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��8��25��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"
#include "intrins.h"

#define uint unsigned int
#define LED P0

void Delay_ms(uint z);

sbit key0 = P3^1;
sbit key2 = P4^3;

void main()
{
	LED = 0XFE;//����LED0

	while(1)
	{
		if(key0 == 0)//��ⰴ��key0
		{
			Delay_ms(10);
			if(key0 == 0)//����
			{
				LED = _cror_(LED,1);//LED������һλ

				while(!key0);//���ּ��
			}
		}

		if(key2 == 0)//��ⰴ��key2
		{
			Delay_ms(10);
			if(key2 == 0)//����
			{
				LED = _crol_(LED,1);//LED������һλ

				while(!key2);//���ּ��
			}
		}
	}
}

void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}
