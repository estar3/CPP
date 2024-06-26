// 类型推导 和 引用 的联合使用 
#include <iostream>
#include <typeinfo>
using namespace std;

int main( void ) {
    int a = 10;
    const int b = 20;

    auto c = a;
    // auto: int      c: int
    cout << "c的类型: " << typeid(c).name() << endl; // i
    cout << "&c:" << &c << ", &a:" << &a << endl; // 地址不同
    c++; // 允许更改

    auto& d = a;
    // auto: int      d: int&
    cout << "d的类型: " << typeid(d).name() << endl; // i
    cout << "&d:" << &d << ", &a:" << &a << endl; // 地址相同
    d++; // 允许更改

    auto& e = b; // 指明按引用推导，目标带有常属性，则也可以自动推导出const(第二种自动推导const的情况)
    // auto: const int      e: const int&
    cout << "e的类型: " << typeid(e).name() << endl; // i
    cout << "&e:" << &e << ", &b:" << &b << endl; // 地址相同
//  e++; // 不允许更改
    return 0;
}
