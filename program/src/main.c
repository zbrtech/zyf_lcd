#include"key.h"//liruixin

uint tt=0;
uint year=2014,month=8,day=10,week=1,hour=9,minute=0,second=0;

void main()
{
	uint i,j;
  char web[29]="https://github.com/zengyongfa";

	TMOD=0x11;
	TH0=(65535-50000)/256;
  TL0=(65535-50000)%256;

	EA=1;
	ET0=1;
  TR0=1;

	init();
  time_init(year,month,day,week,hour,minute,second);

	while(1)
	{
  	if(tt>19){second++;tt=0;}

		if(key2==0)
		{
			delay(10);
	    if(key2==0)
		  {
			  while(!key2);
        write_com(0x80);

/*************************œ‘ æÕ¯÷∑*****************************/
				for(i=0;i<16;i++)
				{
					write_data(web[i]);
				}
				write_com(0x80+0x40);
				for(i=16;i<29;i++)
				{
					write_data(web[i]);
				}

				for(i=2;i>0;i++)//—” ±”√
				{
					for(j=1;j>0;j--)
					{
					  if(tt>19){second++;tt=0;}
						if(second>59){second=0;minute++;}
						if(minute>59){minute=0;hour++;}
						if(hour>23){hour=0;week++;day++;}
						if(week>7){week=1;}
						if(day>31){day=1;month++;}
						if(month>12){month=1;year++;}
					}

				}

				time_init(year,month,day,week,hour,minute,second);
			}
		}

	/*****************************************************************/

    key_scan(&year,&month,&day,&week,&hour,&minute,&second);

  	if(second>59){second=0;minute++;}
    if(minute>59){minute=0;hour++;}
    if(hour>23){hour=0;week++;day++;}
    if(week>7){week=1;}
    if(day>31){day=1;month++;}
    if(month>12){month=1;year++;}

		if(tt==0)
		{
	  	write_year(year);
	  	write_month(month);
	  	write_day(day);
	  	write_week(week);
	  	write_hour(hour);
  		write_minute(minute);
	  	write_second(second);
		}

  }


}

void timer0() interrupt 1
{

		TH0=(65535-50000)/256;
    TL0=(65535-50000)%256;
	  tt++;
}

