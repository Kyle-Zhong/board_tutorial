/*------------------------*/
//傀儡师实验板配套例程
//实验名称：红外遥控
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
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