/*------------------------*/
//����ʦʵ�����������
//ʵ�����ƣ�����-�жϷ�
//���ߣ�zhong
//���̽���ʱ�䣺2017��7��28��
//����޸�ʱ�䣺2017��8��4��
//���׽̳̰汾��V1.0
/*------------------------*/

#include "stc12.h"
#include "intrins.h"

#define uint unsigned int
#define LED P0

void Con_Init(void);

void main()
{
	P0 = 0XFE;
	Con_Init();

	while(1);
}

//�ⲿ�жϳ�ʼ������
void Con_Init(void)
{
	//�����ⲿ�ж�0
	IT0 = 1;//�����ⲿ�ж�0�½��ز���
	EX0 = 1;//���ⲿ�ж�0�ж�����

	//�����ⲿ�ж�1
	IT1 = 1;// �����ⲿ�ж�1�½��ز���
	EX1 = 1;// ���ⲿ�ж�1�ж�����

	EA = 1;//�����ж�
}

//�ⲿ�ж�0������
void Key0_Handler(void) interrupt 0
{
	LED = _cror_(LED,1);
}

//�ⲿ�ж�1������
void Key1_Handler(void) interrupt 2
{
	LED = _crol_(LED,1);
}