#define _CRT_SECURE_NO_WARNINGS // MSVC中为了使用cstring中的函数而加的宏
#include<iostream>
#include<cstring>
using namespace std;
class Student {
    char* name;
    float g1, g2;
public:
    Student(const char* n, float a, float b) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        g1 = a; g2 = b;
        cout << "construct " << name << endl;
    }
    Student(const Student& s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        g1 = s.g1; g2 = s.g2;
		if (s.name==string("li"))
        {
            name = new char[4] {'l', 'i', 'u', '\0'};
            g1 = s.g1 - 10;
			g2 = s.g2 - 10;
        }
        cout << "copy " << name << endl;
    }
    ~Student() {
        cout << "destruct " << name << endl;
        delete[]name;
    }
    float getg1() { return g1; }
    float getg2() { return g2; }
    Student* getaddr() { return this; }
};
int main() {
    Student a("li", 90.0, 80.0);
    Student* st = new Student[2]{ Student("zhang",80.0,70.0),Student("wang",90.0,80.0) };
    cout << (st[0].getg1() + st[0].getg2()) / 2 << " " << (st[1].getg1() + st[1].getg2()) / 2 << endl;
    delete[] st;
    Student b(a);
    Student* ptrb = &b;
    cout << ptrb - b.getaddr() << endl;

}