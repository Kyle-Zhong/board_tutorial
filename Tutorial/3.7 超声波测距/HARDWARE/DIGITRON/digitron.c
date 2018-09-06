#include "stc12.h"
#include "digitron.h"

/*---------------------------------
编号-显示    编号-显示    编号-显示
 0  - 0		  12 - C	   24 -	O
 1	- 1		  13 - D	   25 -	P
 2	- 2		  14 - E	   26 -	Q
 3	- 3		  15 - F	   27 -	R
 4	- 4		  16 - G	   28 -	S
 5	- 5		  17 - H	   29 -	T
 6	- 6		  18 - I	   30 -	U
 7	- 7		  19 - J	   31 -	V
 8	- 8		  20 - K	   32 -	W
 9	- 9		  21 - L	   33 -	X
 10	- A		  22 - M	   34 -	Y
 11	- B		  23 - N	   35 -	Z
----------------------------------*/

//8段数码管段选码
uchar code table[] = 
{
0XC0,0XF9,0XA4,0XB0,
0X99,0X92,0X82,0XF8,
0X80,0X90,0X88,0X83,
0XC6,0XA1,0X86,0X8E
};

//米字数码管段选1
uchar code table1[] = 
{
0XC0,0XF9,0XE4,0X39,0XD9,0XD2,
0X3D,0X07,0XC0,0XD0,0XC8,0XC3,	 
0XC6,0XE1,0XC6,0XCE,0XC2,0XC9,		
0XF6,0XFF,0XFF,0XC7,0XC9,0XC9,		
0XC0,0XCC,0XC0,0XCC,0XD2,0XFE,		
0XC1,0XFF,0XC9,0XFF,0XFF,0XF6	
};

//米字数码管段选2
uchar code table2[] = 
{
0XFF,0XFF,0XE7,0XE7,0XE7,0XE7,
0XE7,0XFF,0XE7,0XE7,0XE7,0XE7,			
0XFF,0XE7,0XE7,0XE7,0XDF,0XE7,
0XBD,0XFF,0X39,0XFF,0XF9,0X7E,
0XFF,0XE7,0XEF,0X67,0XE7,0XBD,
0XFF,0XFF,0X5F,0X5C,0XBA,0XDB
};

uchar code point[] = 
{0X00,0X01,0X10,0X11};

void Digi_Init(void)
{
	P4SW = 0X30;
}

//数码管动态按位显示函数
//a、b、c、d分别为从左到右4个数码管的4个位选，1有效
//num1、num2、num3、num4分别为四个数码管的段选，其中num1取值范围为0~35，num2、num3、num4取值范围分别为0~15
//point控制数码管2和数码管3中间两个点，取值范围0~3，分别对应四种情况
void Digi_Show(uchar a,uchar num1,uchar b,uchar num2,uchar c,uchar num3,uchar d,uchar num4)
{
 	DIG1 = !a;
	DIG2 = 1;
	DIG3 = 1;
	DIG4 = 1;

	EN2 = 1;
	P2 = table2[num1];
	EN2 = 0;

	Delay_ms(2);

	EN1 = 1;
	P2 = table1[num1];
	EN1 = 0;
	
	Delay_ms(2);

	DIG1 = 1;
	DIG2 = !b;
	DIG3 = 1;
	DIG4 = 1;

	EN1 = 1;
	P2 = table[num2];
	EN1 = 0;
	
	Delay_ms(2);

	DIG1 = 1;
	DIG2 = 1;
	DIG3 = !c;
	DIG4 = 1;

	EN1 = 1;
	P2 = table[num3];
	EN1 = 0;

	Delay_ms(2);

	DIG1 = 1;
	DIG2 = 1;
	DIG3 = 1;
	DIG4 = !d;

	EN1 = 1;
	P2 = table[num4];
	EN1 = 0;

	Delay_ms(2);
}

//数码管整数显示函数
//给函数一个变量，能在数码管上显示出来
//变量取值范围：0~9999
void Digi_Num(uint num)
{
	uchar a,b,c,d;//从num分离出来的千位、百位、十位和个位
	
	if((num > 0) || (num < 9999))
	{
		a = num / 1000;
		b = num % 1000 / 100;
		c = num % 1000 % 100 / 10;
		d = num % 1000 % 100 % 10;

		Digi_Show(1,a,1,b,1,c,1,d);
	}
	else
		Digi_Show(1,9,1,9,1,9,1,9);	
}

//毫秒延时函数，误差2us
void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}
