#include "stc12.h"
#include "digitron.h"

/*----------------------------------------------
���-��ʾ    ���-��ʾ   ���-��ʾ   ���-��ʾ
 0	- 0		  4	 - 4	  8	 - 8	  12 - C
 1	- 1		  5	 - 5	  9	 - 9	  13 - D
 2	- 2		  6	 - 6	  10 - A	  14 - E
 3	- 3		  7	 - 7	  11 - B	  15 - F
----------------------------------------------*/

uchar code table[] = 
{
0XC0,0XF9,0XA4,0XB0,
0X99,0X92,0X82,0XF8,
0X80,0X90,0X88,0X83,
0XC6,0XA1,0X86,0X8E
};

void Digi_Init(void)
{
	P4SW = 0X30;
}

//����ܾ�̬��ʾ����
//ǰ�����Ͳ�Ϊ������3���˶������3��λѡ��1��Ч
//���һ���Ͳ�Ϊ��ʾ�����ֻ���ĸ��ȡֵ��ΧΪ0~15
void Digi_Show(uchar a,uchar b,uchar c,uchar num)
{
	DIG1 = 1;
	DIG2 = !a;
	DIG3 = !b;
	DIG4 = !c;

	EN1 = 1;
	P2 = table[num];
	EN1 = 0;
}

//����ܾ�̬��ʾ��ʾ����
void Digi_Test(void)
{
	uint i;
	
	for(i = 0;i < 16;i++)
	{
		Digi_Show(1,1,1,i);
		
		Delay_ms(1000);
	}
}

//������ʱ���������2us
void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}

