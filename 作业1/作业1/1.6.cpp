#include<iostream>

using namespace std;

int my_strcmp(char* s1, char* s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	return s1[i] - s2[i];
}


int main()
{
	char* str1 = new char[100]; 
	char* str2 = new char[100];

	cin >> str1;
	cin >> str2;
	
	int is_equal = my_strcmp(str1, str2);

	if (is_equal > 0)
		cout << str1 << endl;
	else if (is_equal < 0)
		cout << str2 << endl;
	else
		cout << "equal" << endl;
	
	delete[] str1;
	str1 = NULL;
	delete[] str2;
	str2 = NULL;
}