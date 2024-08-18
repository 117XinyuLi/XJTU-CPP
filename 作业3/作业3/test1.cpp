#include<iostream>

using namespace std;

//间接基类A
class A {
public:
    int m_a;
	void print() {
		cout << "A::print()" << endl;
	}
};
//直接基类B
class B : virtual public A {  //虚继承
public:
    int m_b;
    void print() {
        cout << "B::print()" << endl;
    }
};
//直接基类C
class C : virtual public A {  //虚继承
public:
    int m_c;
	void print() {
		cout << "C::print()" << endl;
	}
};
//派生类D
class D : public B, public C {
public:
    void seta(int a) {
        m_a = a;
        cout << A::m_a << B::m_a << C::m_a << D::m_a;
    }  //正确
    void setb(int b) { m_b = b; }  //正确
    void setc(int c) { m_c = c; }  //正确
    void setd(int d) { m_d = d; }  //正确
	void print() {
		cout << "D::print()" << endl;
	}
    int m_d;
};
int main() {
    D d;
	d.print(); 
    d.seta(1);
	d.A::print();  //正确 
    return 0;
}