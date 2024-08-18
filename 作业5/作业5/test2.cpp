#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class A 
{
private:
    char* name;
public:
    A(const char* name) 
    {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
    }
    virtual ~A() 
    {
        cout << "destructor A" << endl;
        delete[] name;
    }
    virtual void show() 
    {
        cout << name << endl;
    }
};

class B : public A 
{
private:
    int age;
public:
    B(const char* name, int age) : A(name),age(age){}
    ~B() {
        cout << "destructor B" << endl;
    }
    void print() 
    {
        cout << age << endl;
    }
    void show()
    {
        cout << "B:";
        A::show();
        this->print();
    }
};

class C : public A {
private:
    char gender;
public:
    C(const char* name, char gender) :A(name), gender(gender) {}
    ~C() 
    {
        cout << "destructor C" << endl;
    }
    void print() 
    {
        cout << gender << endl;
    }
    void show()
    {
        cout << "C:";
        A::show();
        this->print();
    }
};

class manager 
{
private:
    A** array;
    int len;
public:
    manager(int size) 
    {
        array = new A * [size];
        len = 0;
        for(int i = 0; i < size; i++)
        {
            array[i] = NULL;
        }
    }
    ~manager() 
    {

        int i = 0;
		while (i <= len)
		{
			if (array[i] != NULL)
			{
				delete array[i];
				array[i] = NULL;
			}
			i++;
		}
		delete[] array;
    }
    void add(int index, const char* name, int age) 
    {
        B* b = new B(name, age);
        if (array[index])
        {
            delete array[index];
            len--;
        }
        array[index] = b;
        len++;
    }
    void add(int index, const char* name, char gender) 
    {
        C* c = new C(name, gender);
        if (array[index])
        {
            delete array[index];
            len--;
        }
        array[index] = c;
        len++;
    }
    void display() 
    {
		int i = 0;
        while (i<=len)
        {
			if (array[i])
			{
				array[i]->show();
			}
			i++;

        }
    }
};

int main() {
    manager m(4);
    m.add(0, "zhang", 18);
    m.add(1, "wang", 'F');
    m.add(3, "liu", 'M');
    m.display();
    return 0;
}