#include"time.h"

void write_year(int year)
{
	int we1000,we100,we10,we1;
	we1=year%10+48;
	we10=year%100/10+48;
	we100=year%1000/100+48;
	we1000=year/1000+48;
	write_com(0x80);
	write_data(we1000);
	write_data(we100);
	write_data(we10);
	write_data(we1);
}

void write_month(int month)
{
	int we10,we1;
	we1=month%10+48;
	we10=month%100/10+48;
	write_com(0x80+5);
	write_data(we10);
	write_data(we1);
}

void write_day(int day)
{
	int we10,we1;
	we1=day%10+48;
	we10=day%100/10+48;
	write_com(0x80+8);
	write_data(we10);
	write_data(we1);
}

void write_week(int week)
{
	char table[8][5]={"wrong","Monda","Tuesd","Wedne","Thurs","Frida","Satur","Sunda"};
  int num;
  write_com(0x80+11);
  for(num=0;num<5;num++)
    write_data(table[week][num]);
}

void write_hour(int hour)
{
	int we10,we1;
	we1=hour%10+48;
	we10=hour%100/10+48;
	write_com(0x80+0x40+4);
	write_data(we10);
	write_data(we1);
}

void write_minute(int minute)
{
	int we10,we1;
	we1=minute%10+48;
	we10=minute%100/10+48;
	write_com(0x80+0x40+7);
	write_data(we10);
	write_data(we1);
}

void write_second(int second)
{
	int we10,we1;
	we1=second%10+48;
	we10=second%100/10+48;
	write_com(0x80+0x40+10);
	write_data(we10);
	write_data(we1);
}

void time_init(int year,int month,int day,int week,int hour,int minute,int second)
{
	 write_com(0x80+4);
	 write_data('/');
	 write_com(0x80+7);
	 write_data('/');
	 write_com(0x80+10);
	 write_data(' ');
	
	 write_com(0x80+0x40);
	 write_data(' ');
	 write_com(0x80+0x40+1);
	 write_data(' ');
   write_com(0x80+0x40+2);
	 write_data(' ');
	 write_com(0x80+0x40+3);
	 write_data(' ');
	 	
	 write_com(0x80+0x40+6);
	 write_data(':');
	 write_com(0x80+0x40+9);
	 write_data(':');	
	 
	 write_com(0x80+0x40+12);
	 write_data(' ');
   write_com(0x80+0x40+13);
	 write_data(' ');
	 write_com(0x80+0x40+14);
	 write_data(' ');
	 write_com(0x80+0x40+15);
	 write_data(' ');
  
 	 write_year(year);
   write_month(month);
   write_day(day);
   write_week(week);
   write_hour(hour);
   write_minute(minute);
   write_second(second);
	
	
}

	

