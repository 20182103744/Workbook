#include"stdafx.h"
#include <iostream>
using namespace std;
class CLinHaiCheng {
private:
	int Year;
	int Month;
	int Day;
	int Hour;
	int Minute;
	int Second;
	int check();
public:
	CLinHaiCheng();
	CLinHaiCheng(int y, int m, int d, int h, int mi, int s);
	~CLinHaiCheng() {
		cout << "被调用了" << endl;
	}
	void print();
	void AddYearDays();
	int SetDays(int y, int m, int d, int h, int mi, int s);
	int BackYear();
	int BackMonth();
	int BackDay();
	int BackHour();
	int BackMinute();
	int BackSecond();
};
CLinHaiCheng::CLinHaiCheng() {
	Year = 1999;
	Month = 26;
	Day = 12;
	Hour = 11;
	Minute = 19;
	Second = 59;
}
CLinHaiCheng::CLinHaiCheng(int y, int m, int d, int h, int mi, int s) {
	Year = y;
	Month = m;
	Day = d;
	Hour = h;
	Minute = mi;
	Second = s;
	Year = y;
	Month = m;
	Day = d;
	Hour = h;
	Minute = mi;
	Second = s;
	if (check() == -1 || check() == 1) {
		Month = 1;
		Day = 1;
		cout << "输入有误，月日置1" << endl;
	}
}
int CLinHaiCheng::BackYear() {
	return Year;
}
int CLinHaiCheng::BackMonth() {
	return Month;
}
int CLinHaiCheng::BackDay() {
	return Day;
}
int CLinHaiCheng::BackHour() {
	return Hour;
}
int CLinHaiCheng::BackMinute() {
	return Minute;
}
int CLinHaiCheng::BackSecond() {
	return Second;
}
int CLinHaiCheng::check() {
	Minute += Second / 60;
	Second %= 60;
	Hour += Minute / 60;
	Minute %= 60;
	Day += Hour / 24;
	Hour %= 24;
	int flatYearDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapYearDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (Month > 12 || Month < 1)
		return -1;
	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)) {
		if (leapYearDays[Month - 1] < 1 || Day < 1)
			return 1;
	}
	else {
		if (flatYearDays[Month - 1] < Day || Day < 1)
			return 1;
	}
	return 0;
}
int CLinHaiCheng::SetDays(int y, int m, int d, int h, int mi, int s) {
	Year = y;
	Month = m;
	Day = d;
	Hour = h;
	Minute = mi;
	Second = s;
	if (check() == -1 || check() == 1) {
	int flatYearDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int leapYearDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return -1;
	}
	return 0;
}
void CLinHaiCheng::AddYearDays() {

	Day++;
	if (Year % 400 == 0 && (Year % 4 == 0 && Year % 100 != 0)) {
		if (leapYearDays[Month - 1] < Day) {
			Month++;
			Day = 1;
		}
	}
	else {
		if (flatYearDays[Month - 1] < Day) {
			Month++;
			Day = 1;
		}
	}
	if (Month > 12) {
		Year++;
		Month = 1;
	}
}
void CLinHaiCheng::print() {
	cout << Year << "年" << Month << "月" << Day << "日" << Hour << "时" << Minute << "分" << Second << "秒" << endl;
}
int main() {
	int count = 1;
	CLinHaiCheng oj(1999, 11, 30, 72, 0, 0);
	/*while (!((oj.BackYear() == 2019) && (oj.BackMonth() == 4) && (oj.BackDay() == 28))) {
		oj.AddYearDays();
		count++;
	}
	cout << count << endl;*/
	oj.print();
	return 0;
}