#include<iostream>

using namespace std;

//��ӻ���A
class A {
public:
    int m_a;
	void print() {
		cout << "A::print()" << endl;
	}
};
//ֱ�ӻ���B
class B : virtual public A {  //��̳�
public:
    int m_b;
    void print() {
        cout << "B::print()" << endl;
    }
};
//ֱ�ӻ���C
class C : virtual public A {  //��̳�
public:
    int m_c;
	void print() {
		cout << "C::print()" << endl;
	}
};
//������D
class D : public B, public C {
public:
    void seta(int a) {
        m_a = a;
        cout << A::m_a << B::m_a << C::m_a << D::m_a;
    }  //��ȷ
    void setb(int b) { m_b = b; }  //��ȷ
    void setc(int c) { m_c = c; }  //��ȷ
    void setd(int d) { m_d = d; }  //��ȷ
	void print() {
		cout << "D::print()" << endl;
	}
    int m_d;
};
int main() {
    D d;
	d.print(); 
    d.seta(1);
	d.A::print();  //��ȷ 
    return 0;
}