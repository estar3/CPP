// 纯虚函数 和 抽象类
#include <iostream>
using namespace std;

class A { // 抽象类
public:
    virtual void foo( ) = 0; // 纯虚函数
    void bar( ) {
        // ...
    }
};

class B : public A { 
public:
    void foo( ) {
        // ...
    }
};

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
//  A a; 
//  new A;

    B b;
    new B;
    return 0;
}








