/*------------------------*/
//傀儡师实验板配套例程
//实验名称：咪头
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月4日
//配套教程版本：V1.0
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