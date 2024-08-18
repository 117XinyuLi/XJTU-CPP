#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class student
{
public:
	string name;
	int id;
	int score;
};

int main()
{
	int n;
	cin >> n;
	student* s = new student[n];
	if (s == NULL)
	{
		cout << "Error!" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].name >> s[i].id >> s[i].score;
	}
	for (int i = 0; i < n; i++)
	{
		cout << s[i].name << " " << s[i].id << " " << s[i].score << endl;
	}
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += s[i].score;
	}
	cout << fixed << setprecision(2) << sum / n << endl;

	delete[] s;
	return 0;
}