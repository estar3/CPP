// 类型推导 和 类型计算 的差别( 1. 类型在确定类型时会更加精准 2.类型计算在初始值这块会更加灵活)
#include <iostream>
#include <typeinfo>
using namespace std;

int main( void ) {
    const int a = 10;

    auto b = a;
    //  b: int
    cout << "b的类型: " << typeid(b).name() << endl; // i
    cout << "&b: " << &b << ", &a: " << &a << endl; // 地址不同
    b++; // 允许更改

    decltype(a) c = 8888; // a;
    //  c: const int
    cout << "c的类型: " << typeid(c).name() << endl; // i
    cout << "&c: " << &c << ", &a: " << &a << endl; // 地址不同
//  c++; // 不允许更改
    return 0;
}
