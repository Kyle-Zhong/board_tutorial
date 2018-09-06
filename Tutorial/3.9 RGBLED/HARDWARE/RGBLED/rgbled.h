#ifndef _RGBLED_H_
#define	_RGBLED_H_

#define uint unsigned int
#define uchar unsigned char

//发送数据1时序
#define CODE1{DATA = 1;\
	_nop_();_nop_();_nop_();_nop_();_nop_();\
	_nop_();_nop_();_nop_();\
	DATA = 0;\
	_nop_();\
}

//发送数据0时序
#define CODE0{DATA = 1;\
	_nop_();_nop_();\
	DATA = 0;\
	_nop_();_nop_();_nop_();_nop_();\							
}

sbit DATA = P3^5;

void Delay_ms(uint z);
void RGBLED_Rest(void);
void Send_Data(uchar *dat);
void RGBLED_Init(void);
void RGBLED_Set(uchar R,uchar G,uchar B);
void RGBLED_Test(void);

#endif