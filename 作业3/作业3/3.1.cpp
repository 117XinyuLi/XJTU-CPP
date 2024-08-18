# include<iostream>

using namespace std;

class Student;
class Teacher
{
public:
	Teacher(int numStu);
	bool assign(int stuNo, int ordinary, int final);
	void show();
	~Teacher();
private:
	Student* pStu;
	int numStu;
};
class Student
{
	friend bool Teacher::assign(int stuNo, int ordinary, int final);
public:
	bool setProp(float ratio);
	void compScore();
	Teacher* pTea;

private:
	int ordinary;
	int final;
	static float ratio;
};

float Student::ratio = 0.5;

bool Student::setProp(float ratio)
{
	if (ratio <= 0 || ratio >= 1)
	{
		cout << "输入的比例不合法" << endl;
		return false;
	}
	else
	{
		this->ratio = ratio;
		return true;
	}
}

void Student::compScore()
{
	cout << ordinary * ratio + final * (1 - ratio) << " ";
}


Teacher::Teacher(int numStu)
{
	pStu = new Student[numStu];
	if (pStu == NULL)
	{
		cout << "内存分配失败" << endl;
		exit(1);
	}
	this->numStu = numStu;
}

bool Teacher::assign(int stuNo, int ordinary, int final)
{
	if (stuNo < 0 || stuNo >= numStu)
	{
		cout << "输入的学生序号不合法" << endl;
		return false;
	}
	else
	{
		pStu[stuNo].ordinary = ordinary;
		pStu[stuNo].final = final;
		return true;
	}
}

void Teacher::show()
{
	for (int i = 0; i < numStu; i++)
	{
		pStu[i].compScore();
	}
}

Teacher::~Teacher()
{
	if (pStu != NULL)
	{
		delete[]pStu;
		pStu = NULL;
	}
}

int main()
{	
	float ratio = 0;
	cin >> ratio;
	Student().setProp(ratio);
	int numStu = 0;
	cin >> numStu;
	Teacher t(numStu);
	int ordinary = 0;
	int final = 0;
	for (int i = 0; i < numStu; i++)
	{
		cin >> ordinary >> final;
		t.assign(i, ordinary, final);
	}
	t.show();

	
	return 0;
}
