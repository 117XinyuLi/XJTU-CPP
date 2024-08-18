#define _CRT_SECURE_NO_WARNINGS // 在VS环境下，在CPP中使用C的字符串处理函数
#include <iostream>
#include <cstring>

using namespace std;

//定义类，含有静态与非静态成员与函数
class MyClass {
public:
	static int static_data; // 静态数据成员
	int non_static_data; // 非静态数据成员
	char* char_pointer; // 字符指针
	int& data_ref; // 引用
	//构造函数
	MyClass(const char* str) :data_ref(non_static_data) {
		char_pointer = new char[30];
		strcpy(char_pointer, str);
		cout << str << " is constructed." << endl;
		non_static_data = strlen(str);
    }
	//拷贝构造
	MyClass(const MyClass& obj) :data_ref(non_static_data) {
		char_pointer = new char[30];
		strcpy(char_pointer, obj.char_pointer);
		cout << obj.char_pointer << " is copied." << endl;
		non_static_data = obj.non_static_data;
		
	}
	//析构函数
    ~MyClass() {
		cout << char_pointer << " is destructed." << endl;
        delete[] char_pointer;
    }
    static void static_member_function() {
		cout << "static_member_function is called." << endl;
    }
    void non_static_member_function() {
		cout << char_pointer << "non_static_member_function is called." << endl;

    }
};

//初始化静态成员
int MyClass::static_data = 0;

//定义函数
void func(const char*str) {
	MyClass obj(str);
	cout << obj.char_pointer << " address is " << &obj << endl;
	cout << "static_data in " << obj.char_pointer << " is " << obj.static_data << endl;
	cout << "char_pointer in " << obj.char_pointer << " is " << obj.char_pointer << endl;
	cout << "non_static_data in " << obj.char_pointer << " is " << obj.non_static_data << endl;
	cout << "data_ref in " << obj.char_pointer << " is " << obj.data_ref << endl;
	cout << "address of static_data in " << obj.char_pointer << " is " << &obj.static_data << endl;
	cout << "address of char_pointer in " << obj.char_pointer << " is " << &obj.char_pointer << endl;
	cout << "address of non_static_data in " << obj.char_pointer << " is " << &obj.non_static_data << endl;
	cout << "address of data_ref in " << obj.char_pointer << " is " << &obj.data_ref << endl;
	cout << "size of " << obj.char_pointer<<" is " << sizeof(obj) << endl;
}

//创建全局对象
MyClass global_obj1("global_obj1");
MyClass global_obj2("global_obj2");

int main() {

	//创建局部对象
	MyClass local_obj1("local_obj1");
	MyClass local_obj2("local_obj2");

	//动态创建对象
	MyClass* dynamic_obj1 = new MyClass("dynamic_obj1");
	MyClass* dynamic_obj2 = new MyClass("dynamic_obj2");

	cout << "global_obj1 address:" << &global_obj1 << endl;
	cout << "global_obj2 address:" << &global_obj2 << endl;
	cout << "local_obj1 address:" << &local_obj1 << endl;
	cout << "local_obj2 address:" << &local_obj2 << endl;
	cout << "dynamic_obj1 address:" << dynamic_obj1 << endl;
	cout << "dynamic_obj2 address:" << dynamic_obj2 << endl;
	cout << endl;

	//在函数中定义的局部对象
	func("func_obj1");
	func("func_obj2");

	// 全局对象
    cout << endl;
	cout << "static_data in global_obj1 is " << global_obj1.static_data << endl;
	cout << "char_pointer in global_obj1 is " << global_obj1.char_pointer << endl;
	cout << "non_static_data in global_obj1 is " << global_obj1.non_static_data << endl;
	cout << "data_ref in global_obj1 is " << global_obj1.data_ref << endl;
	cout << "address of static_data in global_obj1 is " << &global_obj1.static_data << endl;
	cout << "address of char_pointer in global_obj1 is " << &global_obj1.char_pointer << endl;
	cout << "address of non_static_data in global_obj1 is " << &global_obj1.non_static_data << endl;
	cout << "address of data_ref in global_obj1 is " << &global_obj1.data_ref << endl;
	cout << "size of global_obj1 is " << sizeof(global_obj1) << endl;
	
	cout << endl;
	cout << "static_data in global_obj2 is " << global_obj2.static_data << endl;
	cout << "char_pointer in global_obj2 is " << global_obj2.char_pointer << endl;
	cout << "non_static_data in global_obj2 is " << global_obj2.non_static_data << endl;
	cout << "data_ref in global_obj2 is " << global_obj2.data_ref << endl;
	cout << "address of static_data in global_obj2 is " << &global_obj2.static_data << endl;
	cout << "address of char_pointer in global_obj2 is " << &global_obj2.char_pointer << endl;
	cout << "address of non_static_data in global_obj2 is " << &global_obj2.non_static_data << endl;
	cout << "address of data_ref in global_obj2 is " << &global_obj2.data_ref << endl;
	cout << "size of global_obj2 is " << sizeof(global_obj2) << endl;
		
	// 局部对象
	cout << endl;
	cout << "static_data in local_obj1 is " << local_obj1.static_data << endl;
	cout << "char_pointer in local_obj1 is " << local_obj1.char_pointer << endl;
	cout << "non_static_data in local_obj1 is " << local_obj1.non_static_data << endl;
	cout << "data_ref in local_obj1 is " << local_obj1.data_ref << endl;
	cout << "address of static_data in local_obj1 is " << &local_obj1.static_data << endl;
	cout << "address of char_pointer in local_obj1 is " << &local_obj1.char_pointer << endl;
	cout << "address of non_static_data in local_obj1 is " << &local_obj1.non_static_data << endl;
	cout << "address of data_ref in local_obj1 is " << &local_obj1.data_ref << endl;
	cout << "size of local_obj1 is " << sizeof(local_obj1) << endl;
	
	cout << endl;
	cout << "static_data in local_obj2 is " << local_obj2.static_data << endl;
	cout << "char_pointer in local_obj2 is " << local_obj2.char_pointer << endl;
	cout << "non_static_data in local_obj2 is " << local_obj2.non_static_data << endl;
	cout << "data_ref in local_obj2 is " << local_obj2.data_ref << endl;
	cout << "address of static_data in local_obj2 is " << &local_obj2.static_data << endl;
	cout << "address of char_pointer in local_obj2 is " << &local_obj2.char_pointer << endl;
	cout << "address of non_static_data in local_obj2 is " << &local_obj2.non_static_data << endl;
	cout << "address of data_ref in local_obj2 is " << &local_obj2.data_ref << endl;
	cout << "size of local_obj2 is " << sizeof(local_obj2) << endl;
	
	// 动态对象
	cout << endl;
	cout << "static_data in dynamic_obj1 is " << dynamic_obj1->static_data << endl;
	cout << "char_pointer in dynamic_obj1 is " << dynamic_obj1->char_pointer << endl;
	cout << "non_static_data in dynamic_obj1 is " << dynamic_obj1->non_static_data << endl;
	cout << "data_ref in dynamic_obj1 is " << dynamic_obj1->data_ref << endl;
	cout << "address of static_data in dynamic_obj1 is " << &dynamic_obj1->static_data << endl;
	cout << "address of char_pointer in dynamic_obj1 is " << &dynamic_obj1->char_pointer << endl;
	cout << "address of non_static_data in dynamic_obj1 is " << &dynamic_obj1->non_static_data << endl;
	cout << "address of data_ref in dynamic_obj1 is " << &dynamic_obj1->data_ref << endl;
	cout << "size of dynamic_obj1 is " << sizeof(dynamic_obj1) << endl;
	
	
	cout << "static_data in dynamic_obj2 is " << dynamic_obj2->static_data << endl;
	cout << "char_pointer in dynamic_obj2 is " << dynamic_obj2->char_pointer << endl;
	cout << "non_static_data in dynamic_obj2 is " << dynamic_obj2->non_static_data << endl;
	cout << "data_ref in dynamic_obj2 is " << dynamic_obj2->data_ref << endl;
	cout << "address of static_data in dynamic_obj2 is " << &dynamic_obj2->static_data << endl;
	cout << "address of char_pointer in dynamic_obj2 is " << &dynamic_obj2->char_pointer << endl;
	cout << "address of non_static_data in dynamic_obj2 is " << &dynamic_obj2->non_static_data << endl;
	cout << "address of data_ref in dynamic_obj2 is " << &dynamic_obj2->data_ref << endl;
	cout << "size of dynamic_obj2 is " << sizeof(dynamic_obj2) << endl;

	// 静态成员地址
	cout << endl;
    cout << "Static data member address: " << &MyClass::static_data << endl;
	// 静态成员函数地址和非静态成员函数地址
	union {
		void* pv;
		void(MyClass::* f)();
	} u;
	u.f = &MyClass::non_static_member_function;
    cout << "Static member function address: " << & MyClass::static_member_function << endl;
	cout << "Non-static member function address: " << u.pv << endl;
	// main函数地址和func函数的地址
    cout << "Main function address: " << &main << endl;
    cout << "Func function address: " << &func << endl;

	delete dynamic_obj1;
	dynamic_obj1 = NULL;
	delete dynamic_obj2;
	dynamic_obj2 = NULL;

    return 0;
}

/*
local_obj2 is constructed.
dynamic_obj1 is constructed.
dynamic_obj2 is constructed.
global_obj1 address:00007FF77AE24470
global_obj2 address:00007FF77AE24458
local_obj1 address:00000001000FF9F8
local_obj2 address:00000001000FFA28
dynamic_obj1 address:000001B70FCF4440
dynamic_obj2 address:000001B70FCF4500

func_obj1 is constructed.
func_obj1 address is 00000001000FF8C8
static_data in func_obj1 is 0
char_pointer in func_obj1 is func_obj1
non_static_data in func_obj1 is 9
data_ref in func_obj1 is 9
address of static_data in func_obj1 is 00007FF77AE24450
address of char_pointer in func_obj1 is 00000001000FF8D0
address of non_static_data in func_obj1 is 00000001000FF8C8
address of data_ref in func_obj1 is 00000001000FF8C8
size of func_obj1 is 24
func_obj1 is destructed.
func_obj2 is constructed.
func_obj2 address is 00000001000FF8C8
static_data in func_obj2 is 0
char_pointer in func_obj2 is func_obj2
non_static_data in func_obj2 is 9
data_ref in func_obj2 is 9
address of static_data in func_obj2 is 00007FF77AE24450
address of char_pointer in func_obj2 is 00000001000FF8D0
address of non_static_data in func_obj2 is 00000001000FF8C8
address of data_ref in func_obj2 is 00000001000FF8C8
size of func_obj2 is 24
func_obj2 is destructed.

static_data in global_obj1 is 0
char_pointer in global_obj1 is global_obj1
non_static_data in global_obj1 is 11
data_ref in global_obj1 is 11
address of static_data in global_obj1 is 00007FF77AE24450
address of char_pointer in global_obj1 is 00007FF77AE24478
address of non_static_data in global_obj1 is 00007FF77AE24470
address of data_ref in global_obj1 is 00007FF77AE24470
size of global_obj1 is 24

static_data in global_obj2 is 0
char_pointer in global_obj2 is global_obj2
non_static_data in global_obj2 is 11
data_ref in global_obj2 is 11
address of static_data in global_obj2 is 00007FF77AE24450
address of char_pointer in global_obj2 is 00007FF77AE24460
address of non_static_data in global_obj2 is 00007FF77AE24458
address of data_ref in global_obj2 is 00007FF77AE24458
size of global_obj2 is 24

static_data in local_obj1 is 0
char_pointer in local_obj1 is local_obj1
non_static_data in local_obj1 is 10
data_ref in local_obj1 is 10
address of static_data in local_obj1 is 00007FF77AE24450
address of char_pointer in local_obj1 is 00000001000FFA00
address of non_static_data in local_obj1 is 00000001000FF9F8
address of data_ref in local_obj1 is 00000001000FF9F8
size of local_obj1 is 24

static_data in local_obj2 is 0
char_pointer in local_obj2 is local_obj2
non_static_data in local_obj2 is 10
data_ref in local_obj2 is 10
address of static_data in local_obj2 is 00007FF77AE24450
address of char_pointer in local_obj2 is 00000001000FFA30
address of non_static_data in local_obj2 is 00000001000FFA28
address of data_ref in local_obj2 is 00000001000FFA28
size of local_obj2 is 24

static_data in dynamic_obj1 is 0
char_pointer in dynamic_obj1 is dynamic_obj1
non_static_data in dynamic_obj1 is 12
data_ref in dynamic_obj1 is 12
address of static_data in dynamic_obj1 is 00007FF77AE24450
address of char_pointer in dynamic_obj1 is 000001B70FCF4448
address of non_static_data in dynamic_obj1 is 000001B70FCF4440
address of data_ref in dynamic_obj1 is 000001B70FCF4440
size of dynamic_obj1 is 8
static_data in dynamic_obj2 is 0
char_pointer in dynamic_obj2 is dynamic_obj2
non_static_data in dynamic_obj2 is 12
data_ref in dynamic_obj2 is 12
address of static_data in dynamic_obj2 is 00007FF77AE24450
address of char_pointer in dynamic_obj2 is 000001B70FCF4508
address of non_static_data in dynamic_obj2 is 000001B70FCF4500
address of data_ref in dynamic_obj2 is 000001B70FCF4500
size of dynamic_obj2 is 8

Static data member address: 00007FF77AE24450
Static member function address: 00007FF77AE1152D
Non-static member function address: 00007FF77AE112A3
Main function address: 00007FF77AE11352
Func function address: 00007FF77AE11190
dynamic_obj1 is destructed.
dynamic_obj2 is destructed.
local_obj2 is destructed.
local_obj1 is destructed.
global_obj2 is destructed.
global_obj1 is destructed.
*/