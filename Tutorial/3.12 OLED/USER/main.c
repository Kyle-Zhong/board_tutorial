/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ�����LED
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��8��4��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"
#include "oled.h"
#include "table.h"

void main()
{
	uint size;

	OLED_Chn(16,0,5,Table_Chn);
	OLED_BMP(0,2,6,6,Table_BMP);
	
	size = sizeof(Table_BMP);
	
	OLED_Num(60,2,size);	
}