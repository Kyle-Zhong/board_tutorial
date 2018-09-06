#include "stc12.h"
#include "digitron.h"

void main()
{
	Digi_Init();
	
	while(1)
	{
		Digi_Num(1234);		
	}
}