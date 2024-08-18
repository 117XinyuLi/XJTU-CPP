#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Base
{
private:
	char* name;
	int age;
protected:
	bool is_need_print;
public:
	Base(char* n, int a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		age = a;
		is_need_print = false;
		cout << "Base constructor" << endl;
	}
	~Base()
	{
		delete[]name;
		cout << "Base destructor" << endl;
	}
	void show()
	{
		cout << name << " " << age << " " ;
	}
};

class Leader :virtual public Base
{
private:
	char duty[10];
public:
	Leader(char* n, int a, char* d) :Base(n, a)
	{
		strcpy(duty, d);
		cout << "Leader constructor" << endl;
	}
	~Leader()
	{
		cout << "Leader destructor" << endl;
	}
	void show()
	{
		if (is_need_print)
		{
			Base::show();
			cout << duty ;
		}
		else
		{
			cout << duty;
		}
	}
};

class Engineer :virtual public Base
{
private:
	char major[10];
public:
	Engineer(char* n, int a, char* m) :Base(n, a)
	{
		strcpy(major, m);
		cout << "Engineer constructor" << endl;
	}
	~Engineer()
	{
		cout << "Engineer destructor" << endl;
	}
	void show()
	{
		if (is_need_print)
		{
			Base::show();
			cout << major;
		}
		else
		{
			cout << major;
		}
	}
};

class Chairman :public Leader, public Engineer
{
public:
	Chairman(char* n, char* d, char* m, int a) :Leader(n, a, d), Engineer(n, a, m), Base(n, a)
	{
		cout << "Chairman constructor" << endl;
	}
	~Chairman()
	{
		cout << "Chairman destructor" << endl;
	}
	void show()
	{
		is_need_print = true;
		Leader::show();
		cout << " ";
		is_need_print = false;
		Engineer::show();
		cout << endl;
	}
};

int main()
{
	Chairman a((char*)"Li", (char*)"chair", (char*)"computer", 20);
	a.show();
	return 0;
}