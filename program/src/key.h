#ifndef _key_h_
#define _key_h_

#include"time.h"
           
sbit key1=P1^4;
sbit key2=P1^5;
sbit key3=P1^6;
sbit key4=P1^7;


void key_scan(uint *year,uint *month,uint *day,uint *week,uint *hour,uint *minute,uint *second);



#endif