/*------------------------*/
//傀儡师实验板配套例程
//实验名称：电机
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年9月1日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"
#include "motor.h"

void main()
{
	Motor_Init();

	while(1)
	{
		Car_Run(20,-20);
	}
}