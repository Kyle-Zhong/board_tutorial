#ifndef	_BORN_H_
#define	_BORN_H_

#define uint unsigned int
#define uchar unsigned char

#define BEAT 600//���ĳ��죬ԽСԽ��

sbit EN = P0^7;

void Born_Init(void);
void Pitch(uint pit);
void Music(uint *musictable);
void Delay_4us(uint z);

#endif