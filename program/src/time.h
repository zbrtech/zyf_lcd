#ifndef _time_h_
#define _time_h_

#include"lcd.h"



void write_year(int year);
void write_month(int month);
void write_day(int day);
void write_week(int week);
void write_hour(int hour);
void write_minute(int minute);
void write_second(int second);
void time_init(int year,int month,int day,int week,int hour,int minute,int second);

#endif
