/*------------------------*/
//傀儡师实验板配套例程
//实验名称：舵机
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"
#include "steering.h"

void main()
{
	Steering_Init();
	Timer0_Init();

	while(1)
	{
		Steering_Test();
	}
}