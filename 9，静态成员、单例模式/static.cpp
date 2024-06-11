// 静态成员变量
#include <iostream>
#include <cstring>
using namespace std;
// 普通(非静态)成员变量:属于对象,对象的生命期        静态成员变量:不属于对象,进程级生命期

class A {
public:
    A( ) {
        //【int m_i;】定义m_i;
    }
    int m_i; // 声明
    static int m_si; // 声明
};

int A::m_si = 0; // 全局域中定义并初始化-->进程级生命期

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    A a, b; // 静态成员变量没有保存在对象中-->不属于对象
    cout << "a对象的大小: " << sizeof(a) << endl;
    cout << "b对象的大小: " << sizeof(b) << endl;

    A::m_si = 100; // 受到类作用域的约束，也受到访问控制限定符的约束-->属于类

    a.m_si = 8888; // A::m_si = 8888;
    cout << "b.m_si=" << b.m_si << endl; // A::m_si
    // 类的静态成员变量 被该类所有对象共享
    return 0;
}
