/*------------------------*/
//傀儡师实验板配套例程
//实验名称：超声波测距
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年10月6日
//配套教程版本：V1.0
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
