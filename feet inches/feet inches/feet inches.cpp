// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class CFeet {
private:
	int inches;
	int Feet;
public:
	CFeet();
	void SetL(int, int);
	void DisPlay();
	void check();
	CFeet operator + (CFeet &ot);
};
CFeet::CFeet() {
}
void CFeet::SetL(int f, int i)
{
	Feet = f;
	inches = i;
}
void CFeet::check() {
	if (inches >= 12)
	{
		Feet += inches / 12;
		inches %= 12;
	}
}
void CFeet::DisPlay()
{
	cout << Feet << " feet " << inches << " inches" << endl;
}
CFeet CFeet::operator + (CFeet &ot) {
	CFeet temp;
	temp.SetL(Feet + ot.Feet, inches + ot.inches);
	return temp;
}
int main()
{
	CFeet od1, od2, od;
	od1.SetL(12, 12);
	od2.SetL(1, 1);
	od = od1 + od2;
	od.check();
	od.DisPlay();
	return 0;
}
