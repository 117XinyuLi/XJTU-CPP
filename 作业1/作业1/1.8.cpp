#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	//�������30֮�ڵ�����
	for (int i = 2; i <= 30; i++)
	{
		bool flag = true;
		for (int j = 2; j <= sqrt(i);j++)
		{
			if (i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << i << " ";
		}
	}
}