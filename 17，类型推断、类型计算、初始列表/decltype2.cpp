// 类型计算的四种规则
#include <iostream>
#include <typeinfo>
using namespace std;

double foo( int x, int y );

int main( void ) {
    // 如果给decltype传递的为标识符表达式,编译器将根据标识符本身的类型，作为最终计算出的类型
    int a;
    decltype(a) c = a;
    //  c: int
    cout << "c的类型: " << typeid(c).name() << endl; // i
    cout << "&c: " << &c << ", &a: " << &a << endl; // 地址不同
    c++; // 允许更改

    // 如果给decltype传递的为函数表达式,编译器将根据函数返回值的类型，作为最终计算出的类型
    decltype( foo(10,20) ) d = a;
    //  d: double
    cout << "d的类型: " << typeid(d).name() << endl; // d
    cout << "&d: " << &d << ", &a: " << &a << endl; // 地址不同
    d++; // 允许更改

    // 如果给decltype传递的为其他表达式,并且表达式的结果为左值，编译器将该左值引用的类型，作为最终计算出的类型
    decltype(++a) e = a;
    //  e: int&
    cout << "e的类型: " << typeid(e).name() << endl; // i
    cout << "&e: " << &e << ", &a: " << &a << endl; // 地址相同
    e++; // 允许更改

    // 如果给decltype传递的为其他表达式,并且表达式的结果为右值，编译器将该右值本身的类型，作为最终计算出的类型
    decltype(a++) f = a; 
    //  f: int
    cout << "f的类型: " << typeid(f).name() << endl; // i
    cout << "&f: " << &f << ", &a: " << &a << endl; // 地址不同
    f++; // 允许更改
    return 0;
}
