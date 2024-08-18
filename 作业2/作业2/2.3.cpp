#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	Student(int id, string name, int score)
	{
		this->id = id;
		this->name = name;
		this->score = score;
	}
	Student()
	{
		this->id = 0;
		this->name = "";
		this->score = 0;
	}
	int id;
	string name;
	int score;
};

void max(Student* p, int n)
{
	int max = p[0].score;
	int index = 0;
	for (int i = 1; i < n; i++)
	{
		if (p[i].score > max)
		{
			max = p[i].score;
			index = i;
		}
	}
	cout << p[index].id << " " << p[index].name << " " << p[index].score << endl;
}

int main()
{
	int n;
	cin >> n;
	Student* p = new Student[n];
	if (p == NULL)
	{
		cout << "ÄÚ´æ·ÖÅäÊ§°Ü" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		int id, score;
		string name;
		cin >> id >> name >> score;
		p[i] = Student(id, name, score);
	}
	max(p, n);
	delete[] p;
	return 0;
}