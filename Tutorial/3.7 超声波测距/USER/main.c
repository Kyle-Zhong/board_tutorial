/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ����������
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��10��6��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"
#include "intrins.h"
#include "ultrasonic.h"
#include "digitron.h"

void main()
{
	Digi_Init();
	Ultra_Init();

	while(1)
	{
		Ultra_Work();
	}
}
