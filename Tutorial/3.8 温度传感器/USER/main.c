/*------------------------*/
//傀儡师实验板配套例程
//实验名称：温度传感器
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"
#include "temp.h"
#include "digitron.h"

void main()
{
	Digi_Init();
	Temp_Init();

	while(1)
	{
		Temp_Show();
	}
}