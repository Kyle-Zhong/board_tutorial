/*------------------------*/
//傀儡师实验板配套例程
//实验名称：开机程序
//作者：zhong
//工程建立时间：2017年11月9日
//最后修改时间：2017年11月9日
//配套教程版本：V1.0
/*------------------------*/
#include "stc12.h"
#include "born.h"
#include "digitron.h"

void main()
{
	Born_Init();
	Digi_Init();

	Start_Music();
	EN = 1;
	Digi_Start();

	while(1)
	{
		Digi_Show(1,32,1,16,1,17,1,17);		
	}
}