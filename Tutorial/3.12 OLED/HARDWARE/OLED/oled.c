#include "stc12.h"
#include "oled.h"
#include "table.h"
#include "iic.h"

//������ʱ���������2us
void Delay_ms(uint z)
{
	uint x,y;

	for(x = z;x > 0;x--)
		for(y = 921;y > 0;y--);
}

//OLEDд�����
void OLED_Com(uchar IIC_Command)
{
	IIC_Start();
	IIC_Write(0x78);            
	IIC_Write(0x00);	
	IIC_Write(IIC_Command);
	IIC_Stop();
}

//OLEDд���ݺ���
void OLED_Dat(uchar IIC_Data)
{
	IIC_Start();
	IIC_Write(0x78);
	IIC_Write(0x40);		
	IIC_Write(IIC_Data);
	IIC_Stop();
}

//OLED�������꺯��
void OLED_Set_Pos(uchar x,uchar y) 
{ 
	OLED_Com(0xb0 + y);
	OLED_Com(((x & 0xf0) >> 4) | 0x10);
	OLED_Com((x & 0x0f) | 0x01);
} 

//OLEDȫ��
void OLED_Fill(uchar bmp_dat) 
{
	uchar y,x;

	for(y = 0;y < 8;y++)
	{
		OLED_Com(0Xb0 + y);
		OLED_Com(0X01);
		OLED_Com(0X10);
		for(x = 0;x < X_WIDTH;x++)
		OLED_Dat(bmp_dat);	   
	}
}

//OLED��λ
void OLED_CLS(void)
{
	OLED_Fill(0X00);
}

//OLED��ʼ������
void OLED_Init(void)
{
	Delay_ms(500);//��ʼ��֮ǰ����ʱ����Ҫ��
	OLED_Com(0XAE);
	OLED_Com(0X00);
	OLED_Com(0X10);
	OLED_Com(0X40);
	OLED_Com(0X81);
	OLED_Com(0XCF);
	OLED_Com(0XA1);
	OLED_Com(0XC8);
	OLED_Com(0XA6);
	OLED_Com(0XA8);
	OLED_Com(0X3F);
	OLED_Com(0XD3);
	OLED_Com(0X00);
	OLED_Com(0XD5);
	OLED_Com(0X80);
	OLED_Com(0XD9);
	OLED_Com(0XF1);
	OLED_Com(0XDA);
	OLED_Com(0X12);
	OLED_Com(0XDB);
	OLED_Com(0X40);				   
	OLED_Com(0X20);
	OLED_Com(0X02);
	OLED_Com(0X8D);
	OLED_Com(0X14);
	OLED_Com(0XA4);
	OLED_Com(0XA6); 
	OLED_Com(0XAF);
	OLED_Fill(0X00); //��ʼ����
	OLED_CLS();
	OLED_Set_Pos(0,0);
} 

//OLED��ʾ���ֺ���
//�����С��8*16
void OLED_ShowNum(uchar x,uchar y,uint a)
{
	uint i = 0;

	//��ʾ������Ļ���Ҷˣ��Զ�����
	if(x > 120)
	{
		x = 0;
		y++;
	}

	OLED_Set_Pos(x,y);
	for(i = 0;i < 8;i++)
		OLED_Dat(Table_Num[a * 16 + i]);
	OLED_Set_Pos(x,y + 1);
	for(i = 0;i < 8;i++)
		OLED_Dat(Table_Num[a * 16 + i + 8]);
	
	x += 8;	
}

//OLED��ʾһ��4λ��
//x��yΪ��λ��������
//yȡֵ��Χ��0��1��2��3
//numȡֵ��Χ��0~9999
void OLED_Num(uchar x,uchar y,uint num)
{
	uint a,b,c,d;
	
	if((num > 0) || (num < 9999))
	{
		a = num / 1000;
		b = num % 1000 / 100;
		c = num % 1000 % 100 / 10;
		d = num % 1000 % 100 % 10;

		y *= 2;

		OLED_ShowNum(x,y,a);
		x += 8;
		OLED_ShowNum(x,y,b);
		x += 8;
		OLED_ShowNum(x,y,c);
		x += 8;
		OLED_ShowNum(x,y,d);
	}
}

//OLED��ʾСд��ĸ����
//�����С��8*16
void OLED_Show_let(uchar x,uchar y,uint a)
{
	uint i = 0;

	//��ʾ������Ļ���Ҷˣ��Զ�����
	if(x > 120)
	{
		x = 0;
		y++;
	}

	OLED_Set_Pos(x,y);
	for(i = 0;i < 8;i++)
		OLED_Dat(Table_Let[a * 16 + i]);
	OLED_Set_Pos(x,y + 1);
	for(i = 0;i < 8;i++)
		OLED_Dat(Table_Let[a * 16 + i + 8]);
	
	x += 8;
}

//OLED��ʾ��д��ĸ����
//�����С��8*16
void OLED_Show_Caplet(uchar x,uchar y,uint a)
{
	uint i = 0;

	//��ʾ������Ļ���Ҷˣ��Զ�����
	if(x > 120)
	{
		x = 0;
		y++;
	}

	OLED_Set_Pos(x,y);
	for(i = 0;i < 8;i++)
		OLED_Dat(Table_Caplet[a * 16 + i]);
	OLED_Set_Pos(x,y + 1);
	for(i = 0;i < 8;i++)
		OLED_Dat(Table_Caplet[a * 16 + i + 8]);
	
	x += 8;
}

//OLED��ʾ���ĺ���
//�����С��16*16
//longsizeΪ�����ַ�����
//tableΪ�����ַ�������
void OLED_Chn(uchar x,uchar y,uchar longsize,uchar *table)
{
	uint i,j = 0,k;

	//��ʾ������Ļ���Ҷˣ��Զ�����
	if(x > 112)
	{
		x = 0;
		y++;
	}

	for(k = 0;k < longsize;k++)
	{
		//��ӡ���Ͻ�
		OLED_Set_Pos(x + k * 16,y);
		for(i = 0;i < 8;i++)
		{
			OLED_Dat(table[j]);
	
			j++;
		}

		//��ӡ���Ͻ�
		OLED_Set_Pos(x + 8 + k * 16,y);
		for(i = 0;i < 8;i++)
		{
			OLED_Dat(table[j]);
	
			j++;
		}

		//��ӡ���½�
		OLED_Set_Pos(x + k * 16,y + 1);
		for(i = 0;i < 8;i++)
		{
			OLED_Dat(table[j]);
	
			j++;
		}

		//��ӡ���½�
		OLED_Set_Pos(x + 8 + k * 16,y + 1);
		for(i = 0;i < 8;i++)
		{
			OLED_Dat(table[j]);
	
			j++;
		}
	}				
}

//OLED��ʾͼ��
//size_x��size_y����ͼ����ʾ�ĳ��Ϳ�
//tableΪͼ������
void OLED_BMP(uchar x,uchar y,uchar size_x,uchar size_y,uchar *table)
{
	uint row,column,j = 0,k;

	for(column = y;column < size_y + y;column++)
	{
		for(row = x;row < size_x + x;row++)
		{
			OLED_Set_Pos(row * 8,column);
			for(k = 0;k < 8;k++)
			{
				OLED_Dat(table[j]);

				j++;
			}
		}		
	}
}
