#include "stc12.h"
#include "motor.h"

//�����ʼ������
void Motor_Init(void)
{
	CCON = 0X00;//��ʼ��CCON
			  //�ر�PCA������
			  //���PCA���������־λCF
   			  //���ģ��0��ģ��1�жϱ�־λCCF0��CCF1

	CL = 0;//���������
	CH = 0;

	CMOD = 0X0A;//����PCA����ģʽ
         		//����ģʽ��PCA��������������
				//PCA����������Ƶ��Ϊϵͳʱ��Ƶ�ʵ�1/4
				//�ر�PCA����������ж�

	CCAP0H = CCAP0L = 0XFF;//PWM0���Ƶ��Ϊ11KHzռ�ձ�Ϊ0%��PWM�ź�,��P1.3���
	CCAPM0 = 0X42;//ģ��0ΪPWM���ģʽ
				  //û��PCA�ж�

	CCAP1H = CCAP1L = 0XFF;//PWM1���Ƶ��Ϊ11KHzռ�ձ�Ϊ0%��PWM�ź�,��P1.4���
	CCAPM1 = 0X42;//ģ��1ΪPWM���ģʽ
				  //û��PCA�ж�

	CR = 1;//����PCA������
}

//���1���ƺ���
//pos1���Ƶ��1״̬��BACK���ˣ�STOPֹͣ��FORWǰ��
//pwm1���Ƶ��1ת�٣�pwm1Խ��ת��Խ��ȡֵ��ΧΪ0~50
void Motor1(uchar pos1,uchar pwm1)
{
	//�жϵ��״̬
	switch(pos1)
	{
		case 0 : AIN1 = 1;
				 AIN2 = 0;
		break;
		case 1 : AIN1 = 1;
				 AIN2 = 1;
		break;
		case 2 : AIN1 = 0;
				 AIN2 = 1;
		break;
		default : AIN1 = 1;
				  AIN2 = 1;
	}

	//�������ת��
	if(pwm1 >= 0 && pwm1 <= 50)
	{
		pwm1 = 250 - pwm1;
		
		CCAP0H = CCAP0L = pwm1;
	}
	else
		CCAP0H = CCAP0L = 255;
}

//���2���ƺ���
//pos2���Ƶ��2״̬��BACK���ˣ�STOPֹͣ��FORWǰ��
//pwm2���Ƶ��2ת�٣�pwm2Խ��ת��Խ��ȡֵ��ΧΪ0~50
void Motor2(uchar pos2,uchar pwm2)
{
	//�жϵ��״̬
	switch(pos2)
	{
		case 0 : BIN1 = 1;
				 BIN2 = 0;
		break;
		case 1 : BIN1 = 1;
				 BIN2 = 1;
		break;
		case 2 : BIN1 = 0;
				 BIN2 = 1;
		break;
		default : BIN1 = 1;
				  BIN2 = 1;
	}

	//�������ת��
	if(pwm2 >= 0 && pwm2 <= 50)
	{	
		pwm2 = 250 - pwm2;
			
		CCAP1H = CCAP1L = pwm2;
	}
	else
		CCAP1H = CCAP1L = 255;
}

//�����������
//ֱ�ӿ���С����������˶�
void Car_Run(int speed1,int speed2)
{
	//���1������Ƽ��ٶȿ���
	if(speed1 >= 0)
	{
		Motor1(FORW,speed1);
	}
	else
	{
		speed1 = -speed1;

		Motor1(BACK,speed1);
	}

	//���2������Ƽ��ٶȿ���
	if(speed2 >= 0)
	{
		Motor2(FORW,speed2);
	}
	else
	{
		speed2 = -speed2;

		Motor2(BACK,speed2);
	}	
}
