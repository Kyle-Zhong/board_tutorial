/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ���ˮ��
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��10��6��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"
#include "intrins.h"

#define uint unsigned int//�궨�壬��uint����unsigned int

void Delay_ms(uint z);//����������ʱ����

void main()
{
	P0 = 0XFE;

	while(1)
	{
		P0 = _crol_(P0,1);//ѭ������
	
		Delay_ms(200);
	}
}

//������ʱ���������2us
void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}
