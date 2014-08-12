#ifndef _lcd_h_
#define _lcd_h_


#include"delay.h"


sbit lcdrs=P2^7;
sbit lcdwr=P2^5;
sbit lcden=P2^6;


void write_com(uchar com);
void write_data(uchar date);
void init();

#endif