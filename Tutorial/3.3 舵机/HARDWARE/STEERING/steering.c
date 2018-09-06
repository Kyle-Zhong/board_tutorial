#include "stc12.h"
#include "steering.h"

//�����ʼ������
void Steering_Init(void)
{
	CCON = 0X00;//��ʼ��CCON
			  //�ر�PCA������
			  //���PCA���������־λCF
   			  //���ģ��0��ģ��1�жϱ�־λCCF0��CCF1

	AUXR1 = 0X7F;//�����ת����P4.2��P4.3���

	CL = 0;//���������
	CH = 0;

	CMOD = 0X04;//����PCA����ģʽ
         		//����ģʽ��PCA��������������
				//PCA����������Ƶ��ȡ���ڶ�ʱ��0�����
				//�ر�PCA����������ж�

	CCAP0H = CCAP0L = 0XE0;//PWM0���Ƶ��Ϊ50Hzռ�ձ�Ϊ5%��PWM�ź�,��P4.2���
	CCAPM0 = 0X42;//ģ��0ΪPWM���ģʽ
				  //û��PCA�ж�

	CCAP1H = CCAP1L = 0XE0;//PWM1���Ƶ��Ϊ50Hzռ�ձ�Ϊ5%��PWM�ź�,��P4.3���
	CCAPM1 = 0X42;//ģ��1ΪPWM���ģʽ
				  //û��PCA�ж�

	CR = 1;//����PCA������
}

//��ʱ��0��ʼ������
void Timer0_Init(void)
{
	TMOD = 0X02;

	TL0 = TH0 = 256 - 78;

	TR0 = 1;
	ET0 = 1;
	EA = 1; 
}

//���1�Ƕȿ��ƺ�����180���25�ȷ�ÿ��Լ7�ȣ���angle1Խ��ת�ĽǶ�Խ��angle1ȡֵ��ΧΪ0~25
//��ʼ��ʱ����ĽǶ�Ϊ0��
void Steering1(uchar angle1)
{
	CCAP0H = CCAP0L = 0XE0 + angle1;
}

//���2�Ƕȿ��ƺ�����180���25�ȷ�ÿ��Լ7�ȣ���angle2Խ��ת�ĽǶ�Խ��angle2ȡֵ��ΧΪ0~25
//��ʼ��ʱ����ĽǶ�Ϊ0��
void Steering2(uchar angle2)
{
	CCAP1H = CCAP1L = 0XE0 + angle2;
}

void Steering_Test(void)
{
	 Steering1(2);
	 Steering2(12);
}
