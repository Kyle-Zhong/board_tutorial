/*------------------------*/
//傀儡师实验板配套例程
//实验名称：点亮LED
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
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