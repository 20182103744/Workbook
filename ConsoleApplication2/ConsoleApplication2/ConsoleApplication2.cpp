// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class CBdrh
{
	int x, y;
public:
	CBdrh();
	CBdrh(int, int);
	CBdrh(CBdrh&om);
	void setdate(int a, int b);
	void display();
	~CBdrh();
	
};
CBdrh::~CBdrh()
{
	cout << "��������  x= " << x << "  y= " << y << endl;
}
CBdrh::CBdrh()
{
	x = 0;
	y = 0;
	cout << "Ĭ�Ϻ���  x= " << x << "  y= " << y << endl;
}
CBdrh::CBdrh(int a,int  b)
{
	x = a;
	y = b;
	cout << "���캯��  x= " << x << "  y= " << y<<endl;
}
CBdrh::CBdrh(CBdrh &om)
{
	x = om.x * 2;
	y = om.y * 2;
	cout << "���ƺ���  x= " << x << "  y= " << y << endl;
}
void CBdrh::setdate(int a,int b)
{
	x = a;
	y = b;
}
void CBdrh::display()
{
	cout << "display  x= " << x <<"  y= " << y<<endl;
}
CBdrh MyTest()
{
	CBdrh om(500,300);
	return om;
}
int main()
{	
	CBdrh ot(100,200);
	ot = MyTest();
	ot.display();
	MyTest().display();
    return 0;
}

