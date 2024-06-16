// 虚析构函数 -- delete一个基类类型指针(指针子类对象),能够保证 调用 子类的析构函数
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

class A {
public:
    A() : m_a(open("./file", O_CREAT|O_RDWR, 0644)) {
        //【int m_a=open(...);】定义m_a,初值为文件描述符-->文件表等内核结构(动态资源)
        cout << "A() is invoked - 打开了file文件" << endl;
    }
    virtual ~A() {
        close( m_a );
        cout << "~A() is invoked - 关闭了file文件" << endl;
        // 释放 m_a 本身所占内存空间
    }
private:
    int m_a;
};

class B : public A {
public:
    B() : m_b(open("./cfg", O_CREAT|O_RDWR, 0644)) {
        //【A();】定义基类子对象,利用 基类子对象.A()
        //【int m_b=open(...);】定义m_b,初值为文件描述符-->文件表等内核结构(动态资源)
        cout << "B() is invoked - 打开了cfg文件" << endl;
    }
    ~B() {
        close( m_b );
        cout << "~B() is invoked - 关闭了cfg文件" << endl;
        // 对于基类子对象,利用 基类子对象.~A()
        // 释放 基类子对象、m_b本身所占内存空间
    }
private:
    int m_b;
};
// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    A* p = new B; // 定义 B类堆对象, 利用 B类堆对象.B()

    delete p; // p->虚析构函数( ~B() )   释放 B类堆对象所占内存空间
    return 0;
} // 释放 p 本身所占内存空间
