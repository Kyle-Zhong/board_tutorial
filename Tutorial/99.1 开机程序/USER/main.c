/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ���������
//���ߣ�zhong
//���̽���ʱ�䣺2017��11��9��
//����޸�ʱ�䣺2017��11��9��
//���׽̳̰汾��V1.0
/*------------------------*/
#include "stc12.h"
#include "born.h"
#include "digitron.h"

void main()
{
	Born_Init();
	Digi_Init();

	Start_Music();
	EN = 1;
	Digi_Start();

	while(1)
	{
		Digi_Show(1,32,1,16,1,17,1,17);		
	}
}