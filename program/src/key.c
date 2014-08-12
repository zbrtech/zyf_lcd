#include"key.h"

void key_scan(uint *year,uint *month,uint *day,uint *week,uint *hour,uint *minute,uint *second)
{
  static	uint keynum=0;
	if(key4==0)             
	{
		delay(10);
		if(key4==0)
		{
			keynum++;              
                                
			while(!key4);

			if(keynum==1)
			{
				TR0=0;
				write_com(0x80+0x40+11);
				write_com(0x0f);
			}
			if(keynum==2)
			{
				write_com(0x80+0x40+8);
			}
			if(keynum==3)
			{
							write_com(0x80+0x40+5);
			}
			if(keynum==4)
			{
				write_com(0x80+15);
			}
			if(keynum==5)
			{
				write_com(0x80+9);
			}
			if(keynum==6)
			{
				write_com(0x80+6);
			}
			if(keynum==7)
			{
				write_com(0x80+3);
			}
			if(keynum==8)
		  {
			  keynum=0;
				write_com(0x0c);
				TR0=1;
			}
		}
	}

	if(key1==0)
	{
		delay(10);
		if(key1==0)
		{
			while(!key1);
			switch(keynum)
			{
				case 1:*second=0;write_second(*second);write_com(0x80+0x40+11);break;
				case 2:(*minute)++;if(*minute==60)*minute=0;write_minute(*minute);write_com(0x80+0x40+8);break;
				case 3:(*hour)++;if(*hour==24)*hour=0;write_hour(*hour);write_com(0x80+0x40+5);break;
				case 4:(*week)++;if(*week==8)*week=1;write_week(*week);write_com(0x80+15);break;
				case 5:(*day)++;if(*day==30)*day=1;write_day(*day);write_com(0x80+9);break;
				case 6:(*month)++;if(*month==13)*month=1;write_month(*month);write_com(0x80+6);break;
				case 7:(*year)++;if(*year==2021)*year=2000;write_year(*year);write_com(0x80+3);break;
				default:break;
			}
		}
	}

	if(key3==0)
	{
		delay(10);
		if(key3==0)
		{
			while(!key3);
			switch(keynum)
			{
				case 1:*second=0;write_second(*second);write_com(0x80+0x40+11);break;
				case 2:(*minute)--;if(*minute==-1)*minute=59;write_minute(*minute);write_com(0x80+0x40+8);break;
				case 3:(*hour)--;if(*hour==-1)*hour=23;write_hour(*hour);write_com(0x80+0x40+5);break;
				case 4:(*week)--;if(*week==0)*week=7;write_week(*week);write_com(0x80+15);break;
				case 5:(*day)--;if(*day==0)day=30;write_day(*day);write_com(0x80+9);break;
				case 6:(*month)--;if(*month==0)*month=12;write_month(*month);write_com(0x80+6);break;
				case 7:(*year)--;if(*year==1999)*year=2020;write_year(*year);write_com(0x80+3);break;
				default:break;
			}
		}
	}



}
