#include<iostream>

using namespace std;

void test(const int& i)
{
	cout << i << endl;
	//i = 10;
}

int main()
{
	int a = 0;;
	int& b = a;
	const int& v = 10;
	//int& u = 10;
	test(10);
	cout << a << endl;

	return 0;
}