#include <iostream>
#include <typeinfo>
using namespace std;
// 函数内部 不能定义 函数
/*
void foo( ) {
    int a = 10; // ok,函数内部可以有变量
    cout << 2*a << endl; // ok,函数内部可以有表达式，也可以有语句
    
    void bar( ) { // error, 函数内部 不能有 函数
        cout << "bar() is invoked" << endl;
    }
}
*/
// 函数内部 可以有 类型
// 编译器针对这种情况(函数内部有类型)如何工作:(1)先编函数内部的类型 (2)再编译函数体本身的代码
/*
int a;
void foo( int b ) {
    int c;
    class A {
    public:
        void bar( int d ) {
            a = 10;
//          b = 20; // error
//          c = 30; // error
            d = 40;
        }
    };
}
*/

// 成员函数内部 也可以有 类型
// 编译器针对这种情况(函数内部有类型)如何工作:(1)先编函数内部的类型 (2)再编译函数体本身的代码
int a;
class A {
public:
    void foo( /* A* this */ int b ) {
        class B {
        public:
            void bar( /* B* this */ int c ) {
                a = 10;
//              b = 20; // error
                c = 30;
                d = 40;
//              e = 50; // error
            }
        };
    }
private:
    static int d;
    int e;
};
int A::d;

int main( void ) {
    
    return 0;
}








