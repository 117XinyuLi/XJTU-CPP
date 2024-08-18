#include<iostream>
using namespace std;
class Base
{
private:
	int x;
public:
	Base(int a)
	{
		x = a;
	}
	void show()
	{
		cout << "x=" << x << endl;
	}
};
class derived :public Base
{
private:
	int y;
public:
	derived(int a, int b) :Base(a)
	{
		y = b;
	}
	void show()
	{
		Base::show();
		cout << "y=" << y << endl;
	}
};

void func1(Base b)
{
	b.show();
}

void func2(derived d)
{
	d.show();
}

int main()
{
	derived a(10, 20);
	a.show();
	Base* p1 = &a;
	p1->show();
	derived* p2 = &a;
	p2->show();
	func1(a);
	func2(a);
	return 0;
}
/*
输出：

访问derived的show函数得到
x=10
y=20

使用Base指针访问Base的show函数得到
x=10

使用derived指针访问derived的show函数得到
x=10
y=20

函数中对应的参数为Base类对象，调用Base类的show函数得到
x=10

函数中对应的参数为derived类对象，调用Base类的show函数得到
x=10
y=20
*/