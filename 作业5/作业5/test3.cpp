#include <iostream>
using namespace std;

class A
{
private:
	int a;
public:
	A(int a = 0) :a(a) {}
	virtual A& operator+(const int& x)
	{
		a += x;
		return *this;
	}
	virtual void show()
	{
		cout << "a=" << a << endl;
	}
};

class B :public A
{
private:
	int b;
public:
	B(int a = 0, int b = 0) :A(a), b(b) {}
	B& operator+(const int& x)
	{
		b += x;
		return *this;
	}
	void show()
	{
		A::show();
		cout << "b=" << b << endl;
	}
};

void add(A& a, int x)
{
	a = a + x;
}

int main() 
{
	A myA, * p;
	B myB(2, 3);
	add(myA, 3); p = &myA; p->show();
	add(myB, 3); p = &myB; p->show();
	return 0;
}
