#include<iostream>

using namespace std;


int my_strlen(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

void my_strconcat(char* des, char* scr)
{
	int i = 0;
	int j = my_strlen(des);
	while (scr[i] != '\0')
	{
		des[j] = scr[i];
		i++;
		j++;
	}
	des[j] = '\0';
}


void concat_all_str(char** str, int count)
{
	int total_len = 0;
	for (int i = 0; i < count; i++)
	{
		total_len += my_strlen(str[i]);
	}
	char* result = new char[total_len + 1];
	result[0] = '\0';
	for (int i = 0; i < count; i++)
	{
		my_strconcat(result, str[i]);
	}
	cout << result << endl;
	delete[] result;
	result = NULL;
}


int main()
{
	char** str = new char* [10];
	for (int i = 0; i < 10; i++)
	{
		str[i] = new char[10];
	}
	int count = 0;
	while (cin >> str[count])
	{
		
		count += 1;
	}
	
	concat_all_str(str, count);

	for (int i = 0; i < count; i++)
	{
		delete[] str[i];
		str[i] = NULL;
	}
	delete[] str;
	str = NULL;
}