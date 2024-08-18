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
�����

����derived��show�����õ�
x=10
y=20

ʹ��Baseָ�����Base��show�����õ�
x=10

ʹ��derivedָ�����derived��show�����õ�
x=10
y=20

�����ж�Ӧ�Ĳ���ΪBase����󣬵���Base���show�����õ�
x=10

�����ж�Ӧ�Ĳ���Ϊderived����󣬵���Base���show�����õ�
x=10
y=20
*/