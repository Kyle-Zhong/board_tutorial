#include "stc12.h"
#include "iic.h"

//IIC��ʼ����
void IIC_Start(void)
{				 
   SCL = 1;		
   SDA = 1;
   SDA = 0;
   SCL = 0;
}

//IIC��������
void IIC_Stop(void)
{
   SCL = 0;
   SDA = 0;
   SCL = 1;
   SDA = 1;
}

//IICдһ�����ݺ���
void IIC_Write(uchar Byte)
{
	uchar i;

	for(i = 0;i < 8;i++)
	{
		if(Byte & 0x80)
			SDA = 1;
		else
			SDA = 0;

		SCL = 1;
		SCL = 0;

		Byte <<= 1;
	}

	SDA = 1;
	SCL = 1;
	SCL = 0;
}

//IIC��һ�����ݺ���
uchar IIC_Read(void)
{
	uchar Byte,i;

	SCL = 0;
	SDA = 1;

	for(i = 0;i < 8;i++)
	{
		SCL = 1;

		Byte = (Byte << 1) | SDA;

		SCL = 0;
	}

	return Byte;
}
