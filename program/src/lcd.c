#include"lcd.h"

void write_com(uchar com)
{
	lcdrs=0;
	P0=com;//
	delay(1);
	lcden=1;
	delay(1);   
	lcden=0;
}

void write_data(uchar date)
{
	lcdrs=1;
	P0=date;
	delay(1);
	lcden=1;
	delay(1);
	lcden=0;
}

void init()
{
	lcdwr=0;
	lcden=0;
	write_com(0x38);//设置16x2显示，5x7点阵，8位数据接口
	
	write_com(0x0c);//设置开显示，不显示光标
	//write_com(0x0e);//设置开显示，显示光标
	//write_com(0x0f);//设置开显示，显示光标并闪烁
	
	write_com(0x06);//写一个字符后地址指针加1
	//write_com(0x07);//写一个字符后地址指针不加1
	
	write_com(0x01);//显示清0,数据指针清0
	write_com(0x80);//1*** ****，DDRAM地址

}