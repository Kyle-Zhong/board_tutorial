/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ�����ң��
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��8��4��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"
#include "remote.h"
#include "digitron.h"

void main()
{
	Timer0_Init();
	Init0_Init();
	Digi_Init();

	while(1)
	{
		Remote_ConLED();
	}
}