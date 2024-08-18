#include<iostream>

using namespace std;

int main() 
{
	int len = 0;
	cin >> len;
	int** arr = new int* [len];
	if (arr == NULL)
	{
		cout << "ÄÚ´æ·ÖÅäÊ§°Ü" << endl;
		return 0;
	}
	
	for (int i = 0; i < len; i++)
	{
		arr[i] = new int;
		if (!arr[i])
		{
			cout << "ÄÚ´æ·ÖÅäÊ§°Ü" << endl;
			return 0;
		}
		cin >> arr[i][0];
	}

	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i][0];
	}
	cout << sum;
	
	for (int i = 0; i < len; i++)
	{
		delete[] arr[i];
		arr[i] = NULL;
	}
	delete[] arr;
	arr = NULL;

	
	return 0;
}



