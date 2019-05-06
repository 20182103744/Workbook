// 日期时间程序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#include "stdafx.h"

#include<iostream>

using namespace std;

class CBadarihu

{

private:

	int year, month, day;

	int hour, minute, second, millisecond;

	int check();

public:

	int CBdrh(int ,int ,int);

	void time(int ,int, int ,int);

	void displayDate();

};

int CBadarihu::CBdrh(int Year ,int Month ,int Day)

{

	year = Year;

	month = Month;

	day = Day;

	if (check() == -1 || check() == 1)

	{
		int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			month += day / leapYearDays[month - 1];
			day%=leapYearDays[month - 2];
		}
		else
		{
			month += day / flatYearDays[month - 1];
		    day %= flatYearDays[month - 2];
		}
			year += month / 12;
			month %= 12;

	}

	return 0;

};



void CBadarihu::time(int x, int y, int z, int m)

{
	
	hour = x;

	minute = y;

	second = z;

	millisecond = m;
	if (check() == -1 || check() == 1)
	{
		second += millisecond / 1000;
		millisecond %= 1000;
		minute += second / 60;
		second %= 60;
		hour += minute / 60;
		minute %= 60;
		day += hour / 24;
		hour %= 24;
	}


};

void CBadarihu::displayDate()

{
	cout << "你的日期和时间为的正确形式为:" << endl;
	cout << year << "年" << month << "月" << day << "日" << hour << "时" << minute << "分" << second << "秒" << millisecond << "毫秒";

};

int CBadarihu::check()

{

	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

	if (month > 12 || month < 1)

		return -1;


	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))

	{

		if (leapYearDays[month - 1] < day || day < 1)

			return -1;

	}

	else

	{

		if (flatYearDays[month - 1] < day || day < 1)

			return -1;

	}
	if (millisecond < 1 || millisecond>=1000)
		return 1;
	if (second < 1 || second>60)
		return 1;
	if (minute < 1 || minute>60)
		return 1;
	if (hour < 0 || hour>24)
		return 1;
	//return 0;

};

int main()

{

	CBadarihu bdrh;

	bdrh.CBdrh(0,0,0);  //在此处填写你的日期

	bdrh.time(0,0,0,0);  //在此填写你的时间

	bdrh.displayDate();

	return 0;

}