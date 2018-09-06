#include "stc12.h"
#include "audio.h"
#include "digitron.h"

//��ͷ��ʼ������
void Audio_Init(void)
{
	P1ASF = 0X01;//P1.0��ΪAD����ʹ��
	ADC_CONTR = 0XE0;//��ADת������Դ
					 //���ADת���ٶȣ�ÿ90��ʱ������ת��һ��
					 //��P1.0��ΪADC����

	ADC_RES = 0X00;//����ADת������Ĵ���
}

//��ͷ���ݶ�ȡ����
uchar Audio_Read(void)
{
	uchar valu,ADC_FLAG;

	ADC_CONTR |= 0X08;//����ADת��

	ADC_FLAG = (ADC_CONTR & 0X10) >> 4;//��ȡADת����ɱ�־

	if(ADC_FLAG == 1)//����Ƿ����ת��
	{
		ADC_CONTR &= 0XEF;//����ת����־

		valu =  ADC_RES;
	}

	return valu;
}

//��ͷ������ʾ����
void Audio_Show(void)
{
   uchar value;

   value =  Audio_Read();//��ȡAD����

   Digi_Num(value);//�����������ʾ����
}