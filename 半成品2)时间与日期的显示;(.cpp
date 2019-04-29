// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
using namespace std;
class CBadarihu
{
private:
	int year, month, day;
	int hour, minute, second,milliscond;
	int check();
public:
	int CBdrh();
	void time();
	void setDate();
};
int CBadarihu::CBdrh()
{
	year = 2019;
	month = 4;
	day = 4;
	if (check() == -1 || check() == 1)
	{
		
		month = 1;
		day = 1;
		cout << "设置了错误日期，月日已置1  ";
	}
	return 0;
};

void CBadarihu::time()
{
	hour = 9;
	minute = 30;
	second = 31;
	milliscond = 1000;
	
};
void CBadarihu::setDate()
{
	cout << year << "年" << month << "月" << day << "日" <<  hour << "时" << minute << "分" << second << "秒" << milliscond<<"毫秒" ;
};
int CBadarihu::check()
{	
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (milliscond >= 1000)
	{	
		second++;
		if (second >= 60)
		{
			minute++;
			if (minute >= 60)
			{
				hour++;
				if (hour >= 60)
				{
					day++;
					if (day > leapYearDays[month - 1] || day > flatYearDays[month - 1])
					{
						month++;
						if (month > 12)
						{
							year++;
						}
					}
				}
			}
		}
		return 1;
	}
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
	}

	return 0;
}
int main()
{
	CBadarihu bdrh;
	bdrh.CBdrh();
	bdrh.time();
	bdrh.setDate();
	return 0;
}
