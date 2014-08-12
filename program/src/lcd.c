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
	write_com(0x38);//����16x2��ʾ��5x7����8λ���ݽӿ�
	
	write_com(0x0c);//���ÿ���ʾ������ʾ���
	//write_com(0x0e);//���ÿ���ʾ����ʾ���
	//write_com(0x0f);//���ÿ���ʾ����ʾ��겢��˸
	
	write_com(0x06);//дһ���ַ����ַָ���1
	//write_com(0x07);//дһ���ַ����ַָ�벻��1
	
	write_com(0x01);//��ʾ��0,����ָ����0
	write_com(0x80);//1*** ****��DDRAM��ַ

}