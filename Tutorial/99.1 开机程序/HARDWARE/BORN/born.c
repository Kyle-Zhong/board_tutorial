#include "stc12.h"
#include "born.h"
#include "digitron.h"

/*---------------------
53-����1    26-����1  	 
50-����1#   25-����1#	 
47-����2	24-����2	 
44-����2#   23-����2#	 
42-����3	21-����3	
40-����4	20-����4	
38-����4#   19-����4#	 
36-����5	17-����5	
34-����5#   16-����5#	 
32-����6	15-����6	 
30-����6#   14-����6#
28-����7	13-����7	 
----------------------*/

//ģ�����Ҳ����������
uchar code music_table[] = 
{
0X80,0X54,0X2E,0X0F,0X00,
0X00,0X0F,0X2E,0X54,0X80,
0XAB,0XD2,0XEE,0XFF,0XFF,
0XEE,0XD2,0XAB
};

//���ȳ�ʼ������
void Born_Init(void)
{
	CCON = 0X00;//��ʼ��CCON
			  //�ر�PCA������
			  //���PCA���������־λCF
   			  //���ģ��0��ģ��1�жϱ�־λCCF0��CCF1

	AUXR1 = 0X7F;//��ת����P4.2���

	CL = 0;//���������
	CH = 0;

	CMOD = 0X08;//����PCA����ģʽ
         		//����ģʽ��PCA��������������
				// PCA����������Ƶ��Ϊ12MHz
				//�ر�PCA����������ж�

	CCAP0H = CCAP0L = 0X80;//PWM0���Ƶ��Ϊ46K,ռ�ձ�Ϊ50%��PWM�ź�

	CCAPM0 = 0X42;//ģ��0ΪPWM���0ģʽ       			     
				  //û��PCA�ж�

	CR = 1;//����PCA������
	EN = 0;
}

//��������
//pit����������ȡֵ��ΧΪ�Ϸ�ע���е�ֵ
void Pitch(uint pit)
{
	uint x,y;

	y = BEAT;

	while(y--)
	{
		for(x = 0;x < 17;x++)
		{
			CCAP0H = CCAP0L = music_table[x];
			Delay_4us(pit);
		}
	}
}

//�������ֺ���
//�Ͳ�Ϊ������������
void Music(uint *musictable)
{
	uint x;

	for(x = 0;musictable[x] != 255;x++)
	{
		Pitch(musictable[x]);
	}
}

void Start_Music(void)
{
	Pitch(26);
	Delay_ms(1);
	Pitch(24);
	Delay_ms(1);
	Pitch(21);
	Delay_ms(1);
}

//4us��ʱ����
void Delay_4us(uint z)
{
	while(z--);
}
