// 类型推导 局限性
#include <iostream>
#include <typeinfo>
using namespace std;

void foo( auto v ) { // 11标准不支持，但14标准支持
}

class A {
public:
    auto a; // 声明
    auto b; // 声明
};


int main( void ) {
    foo( 100 );    
    return 0;
}
