// 构造函数中抛出异常
#include <iostream>
#include <cstdio>
using namespace std;
class A {
public:
    A() {   cout << "A() is invoked" << endl;   }
    ~A() {   cout << "~A() is invoked" << endl;   }
    
};

class C {
public:
    C( ) : m_p(new int) {
        //【A m_a;】定义m_a(给m_a分配内存空间),利用m_a.A()
        //【int* m_p=new int;】定义m_p,初值为指向一块堆内存(动态资源)
        cout << "C() is invoked" << endl;
        FILE* pfile = fopen("./cfg", "r");
        if( !pfile ) {
            delete m_p;
            // 对于m_a,利用 m_a.~A() 释放 m_a/m_p 本身所占内存空间
            throw -1;
        }
        // ...构造函数中的后续代码...
    }
    ~C( ) {
        delete m_p;
        cout << "~C() is invoked" << endl;
        // 对于m_a,利用 m_a.~A()
        // 释放 m_a/m_p 本身所占内存空间
    }
private:
    A m_a;
    int* m_p;
};
// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    try {
        C c; // 定义c,利用c.C()
    } // 如果c是完整对象将利用c.~C() ，如果c是残缺对象将不会调用~C()
    catch( ... ) {
        // ...
    }
    return 0;
}
