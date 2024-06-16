// 类型推导 绝对不是 类型照抄
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

    auto d = b;
    // auto: int      d: int
    cout << "d的类型: " << typeid(d).name() << endl; // i
    cout << "&d:" << &d << ", &b:" << &b << endl; // 地址不同
    d++; // 允许更改

    const auto e = b;
    // auto: int      e: const int
    cout << "e的类型: " << typeid(e).name() << endl; // i
    cout << "&e:" << &e << ", &b:" << &b << endl; // 地址不同
//  e++; // 不允许更改

    auto f = &b; // 如果初始化数据的类型为常指针，则可以自动推导出const(这是第一种自动推导const的情况)
    // auto: const int*      f: const int*
    cout << "f的类型: " << typeid(f).name() << endl; // PKi
//  *f = 8888; // 不允许更改
    f = NULL; // 允许更改
    return 0;
}








