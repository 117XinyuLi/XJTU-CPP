#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	char str[20] = { 0 };
	char* concat = new char[1];
	if (concat == NULL)
	{
		cout << "ÄÚ´æ·ÖÅäÊ§°Ü" << endl;
		return 0;
	}
	concat[0] = '\0';
	while (cin >> str)
	{		

		char* temp = new char[strlen(str) + strlen(concat) + 1];
		if (temp == NULL)
		{
			cout << "ÄÚ´æ·ÖÅäÊ§°Ü" << endl;
			return 0;
		}
		strcpy(temp, concat);
		strcat(temp, str);
		concat = new char[strlen(temp) + 1];
		if (concat == NULL)
		{
			cout << "ÄÚ´æ·ÖÅäÊ§°Ü" << endl;
			return 0;
		}
		strcpy(concat, temp);
		concat[strlen(temp)] = '\0';
		delete[] temp;
		temp = NULL;
	}
	
	cout << concat << endl;
	delete[] concat;
	concat = NULL;
	

	return 0;
}