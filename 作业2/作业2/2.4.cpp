#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	string IdPerson;
	string Name;
	string Sex;
	string Birthday;
	string HomeAddress;
	Person(string id, string name, string sex, string birthday, string home) :IdPerson(id), Name(name), Sex(sex), Birthday(birthday), HomeAddress(home) {};
	Person(const Person& p)
	{
		this->IdPerson = p.IdPerson;
		this->Name = p.Name;
		this->Sex = p.Sex;
		this->Birthday = p.Birthday;
		this->HomeAddress = p.HomeAddress;
	}
	
};

int main()
{	
	string IdPerson;
	string Name;
	string Sex;
	string Birthday;
	string HomeAddress;
	cin >> IdPerson >> Name >> Sex >> Birthday >> HomeAddress;
	Person p1(IdPerson, Name, Sex, Birthday, HomeAddress);
	cin >> IdPerson >> Name >> Sex >> Birthday >> HomeAddress;
	Person p2(IdPerson, Name, Sex, Birthday, HomeAddress);
	
	cout << p1.IdPerson << " " << p1.Name << " " << p1.Sex << " " << p1.Birthday << " " << p1.HomeAddress << endl;
	
	cout << p2.IdPerson << " " << p2.Name << " " << p2.Sex << " " << p2.Birthday << " " << p2.HomeAddress << endl;

	
	return 0;
}