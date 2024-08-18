#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	char* array;
	static char nullchar;
public:
	String(const char* p)
	{
		array = new char[strlen(p) + 1];
		strcpy(array, p);
	}
	~String()
	{
		delete[]array;
	}
	char& operator[](int index)
	{
		if (index >= 0 && index < strlen(array))
			return array[index];
		else
		{
			cout << "Index out of range." << endl;
			return nullchar;
		}
	}
	String& operator+(const String& s)
	{
		char* temp = new char[strlen(array) + strlen(s.array) + 1];
		strcpy(temp, array);
		strcat(temp, s.array);
		delete[]array;
		array = temp;
		return *this;
	}
	String& operator=(const String& s)
	{
		if (this == &s)
			return *this;
		delete[]array;
		array = new char[strlen(s.array) + 1];
		strcpy(array, s.array);
		return *this;
	}
	String operator+(const char* s)
	{
		char* temp = new char[strlen(array) + strlen(s) + 1];
		strcpy(temp, array);
		strcat(temp, s);
		String s1(temp);
		delete[]temp;
		return s1;
	}
	operator int()
	{
		return strlen(array);
	}
	friend ostream& operator<<(ostream& out, const String& s)
	{
		out << s.array;
		return out;
	}
};

char String::nullchar = '\0';

int main() {
	String string1("mystring"), string2("yourstring"), string3("herstring");
	cout<<string1<<endl;
	string1[7] = 'n';
	cout<<string1<<endl;
	string1[8] = 'n';
	cout<<string1 + string2 + string3<<endl;
	cout<<string1<<endl;
	cout<<string2 + "ab"<<endl;
	cout<<string2<<endl;
	cout<<string3 + 3<<endl;
	cout<<string3<<endl;
	return 0;
}