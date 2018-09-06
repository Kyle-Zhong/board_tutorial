#ifndef _REMOTE_H_
#define	_REMOTE_H_

#define uchar unsigned char
#define uint unsigned int

void Timer0_Init(void);
void Init0_Init(void);
void Remote_Handler(void);
uchar Remote_Count(void);
uint Remote_Work(void);
void Remote_ConLED(void);

#endif