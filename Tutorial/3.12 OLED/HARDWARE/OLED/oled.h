#ifndef _OLED_H_
#define _OLED_H_

#define uint unsigned int
#define uchar unsigned char

#define	Brightness	0xCF 
#define X_WIDTH 	128
#define Y_WIDTH 	64

void Delay_ms(uint z);
void OLED_Com(uchar IIC_Command);
void OLED_Dat(uchar IIC_Data);
void OLED_Set_Pos(uchar x,uchar y);
void OLED_Fill(uchar bmp_dat);
void OLED_CLS(void);
void OLED_Init(void);
void OLED_ShowNum(uchar x,uchar y,uint a);
void OLED_Num(uchar x,uchar y,uint num);
void OLED_Show_let(uchar x,uchar y,uint a);
void OLED_Show_Caplet(uchar x,uchar y,uint a);
void OLED_Chn(uchar x,uchar y,uchar longsize,uchar *table);
void OLED_BMP(uchar x,uchar y,uchar size_x,uchar size_y,uchar *table);

#endif