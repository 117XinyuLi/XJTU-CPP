#include<iostream>

using namespace std;

void sort_three_num(int& a, int& b, int& c)
{
	int temp = 0;
	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}
}

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	sort_three_num(a, b, c);
	cout << a << " " << b << " " << c << endl;
	

	return 0;
}