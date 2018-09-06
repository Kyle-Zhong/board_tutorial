/*------------------------*/
//傀儡师实验板配套例程
//实验名称：喇叭
//作者：zhong
//工程建立时间：2017年7月28日
//最后修改时间：2017年8月27日
//配套教程版本：V1.0
/*------------------------*/

#include "stc12.h"
#include "born.h"
#include "music.h"

void main()
{
	Born_Init();

	while(1)
	{
		Music(LittleStar);
	}
}