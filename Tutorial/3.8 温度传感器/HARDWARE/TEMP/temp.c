#include "stc12.h"
#include "temp.h"
#include "digitron.h"
#include "intrins.h"

//΢����ʱ����
//������ʱʵ����Ҫdebug������
void Delay_us(uint n)
{
    while (n--)
    {
        _nop_();
        _nop_();
    }
}

//�¶ȴ�������λ����
void Temp_Init(void)
{
	uint x = 1;
	
	while(x)
	{
		DA = 0;//����������
		Delay_us(480);//�ȴ�480us
		DA = 1;//�ͷ�������
		Delay_us(60);//�ȴ�60us
		x = DA;//���DS18B20�Ƿ�����Ӧ
		Delay_us(420);//�ȴ�DS8B20�ͷ�������
	}	
}

//��DB18B20дһ������
void Temp_Write(uchar dat)
{
	uchar i;

	for(i = 0;i < 8;i++)
	{
		//д����ʱ��
		DA = 0;
		Delay_us(1);
		DA = 1;

		//��������
		dat >>= 1;
		DA = CY;

		Delay_us(20);

		DA = 1;
		Delay_us(1);
	}
}

//��DB18B20��һ������
uchar Temp_Read(void)
{
    uchar i;
    uchar dat = 0;

    for (i = 0;i < 8;i++)//��ȡһ��8λ����
    {
        dat >>= 1;

		//������ʱ��
        DA = 0;                   
        Delay_us(1);               
        DA = 1;                   
        Delay_us(1);
		
		//��ȡ����                
        if(DA) 
			dat |= 0x80; 
		
		//�ȴ���ȡ����	      
        Delay_us(60);              
    }

    return dat;
}

//�¶���ʾ����
void Temp_Show(void)
{
	uint temp;
	uchar th,tl;

	//��ʼADת��ָ��
	Temp_Init();
	Temp_Write(0XCC);
	Temp_Write(0X44);

	while(!DA);//�ȴ�ת�����

	//��ȡ�ݴ�洢������ָ��
	Temp_Init();
	Temp_Write(0XCC);
	Temp_Write(0XBE);

	tl = Temp_Read();//��ȡ�¶ȵ��ֽ�
	th = Temp_Read();//��ȡ�¶ȸ��ֽ�

	//�ϳɸߵ��¶����ݣ�ȡ���ֽڸ�4λ�͸��ֽڵ���λ���õ��¶ȵ�����ֵ
	tl = (tl & 0XF0) >> 4;
	temp = th;
	temp <<= 4;
	temp |= tl;

	Digi_Num(temp);
}
