#include "stc12.h"
#include "remote.h"
#include "digitron.h"

uchar retime;//��¼�ߵ�ƽʱ��
uchar bitnum;//���ݵ�λ��
uchar startflag;//������տ�ʼ��־λ
uchar reciveflag;//�������ݽ�����ɱ�־λ
uchar finishflag;//�������ݴ�����ɱ�־λ

uchar redata[33];//��ź�������
uchar recode[4];//����û����4����ֵ

uchar num = 0;//

//��ʱ��0��ʼ������
void Timer0_Init(void)
{
	TMOD = 0X02;//���óɹ�����ʽ2
	TH0 = TL0 = 0;

	ET0 = 1;//�򿪶�ʱ��0�ж�
	EA = 1;//�����ж�
	TR0 = 1;//������ʱ��
}

//��ʱ��0�жϷ�����
void Timer0_Handler(void) interrupt 1
{
	retime++;
}

//�ⲿ�ж�0��ʼ������
void Init0_Init(void)
{
	IT0 = 1;//���ó��½��ش���
	EX0 = 1;//���ⲿ�ж�0
	EA = 1;//�����ж�
}

//�ⲿ�ж�0������
void Init0_Handler(void) interrupt 0
{
	//����Ѿ����ڽ��յ��У����������
	if(startflag)
	{
		//��⵽�û��룬��ʼ��������
		if(retime < 63 && retime > 32)
			bitnum = 0;

		redata[bitnum] = retime;//��¼ÿ�θߵ�ƽ��ʱ��
		retime = 0;
		bitnum++;

		if(bitnum == 33)//�ж��Ƿ�������
		{
			bitnum = 0;
			reciveflag = 1;//��1������ɱ�־λ����ʾ�����Ѿ����
		}
	}
	else//����ʼ����
	{
		startflag = 1;//��1��ʼ��־λ
		retime = 0;
	}
}

//�������ݴ�����
void Remote_Handler(void)
{
	uchar k,x,y;
	uchar value;

	k = 1;

	for(x = 0;x < 4;x++)//ȡ4������
	{
		for(y = 0;y <= 8;y++)//ÿ������8λ
		{
			value >>= 1;

			//�жϺ���������1����0
			//����ߵ�ƽʱ�����6*255us��1.53ms����Ϊ�ߵ�ƽ
			if(redata[k] > 7)
				value |= 0X80;

			k++;
		}

		recode[x] = value;
		value = 0;
	}

	finishflag = 1;//��1������ɱ�־λ
}

//�����ֵ�жϺ���
uchar Remote_Count(void)
{
	uchar key;
	
	switch(recode[2])
	{
		case 34  : key = 0;
			break;
		case 97  : key = 1;
			break;
		case 227 : key = 2;
			break;
		case 43  : key = 3;
			break;
		case 225 : key = 4;
			break;
		case 99  : key = 5;
			break;
		case 171 : key = 6;
			break;
		case 168 : key = 7;
			break;
		case 170 : key = 8;
			break;
		case 169 : key = 9;
			break;
		default : key = 9;
	}

	return key;	
}

//����ң�ؽ��뺯��
//�����������ʾ��ֵ
uint Remote_Work(void)
{
	if(reciveflag == 1)
	{
		reciveflag =0;
		Remote_Handler();
	}
	if(finishflag == 1)
	{
		finishflag = 0;
		num = Remote_Count();
	}

	Digi_Num(num);

	return num;
}

//����ң�ؿ���LED����
void Remote_ConLED(void)
{
	uint key;

	key = Remote_Work();

	switch(key)
	{
		case 0 : P0 = 0XFF;
			break;
		case 1 : P0 = 0X7F;
			break;
		case 2 : P0 = 0XBF;
			break;
		case 3 : P0 = 0XDF;
			break;
		case 4 : P0 = 0XEF;
			break;
		case 5 : P0 = 0XF7;
			break;
		case 6 : P0 = 0XFB;
			break;
		case 7 : P0 = 0XFD;
			break;
		case 8 : P0 = 0XFE;
			break;
		case 9 : P0 = 0X00;
			break;
		default : P0 = 0XFF;
	}
}
