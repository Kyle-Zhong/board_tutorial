/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ���ͷ
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��8��4��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"
#include "audio.h"
#include "digitron.h"

void main()
{
	Audio_Init();
	Digi_Init();

	while(1)
	{
		Audio_Show();
	}
}