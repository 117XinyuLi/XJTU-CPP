#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	char input = 0;
	cin >> input;
	char* str = (char*)"abc";
	cout << str << endl;
	char* q = new char[5] {'d', 'e', 'f',0,0};
	cout << q << " " << strlen(q) + 2 << endl;
	strcpy(q, str);
	q[strlen(q)] = input;
	cout << q << endl;


	
	
	return 0;
}