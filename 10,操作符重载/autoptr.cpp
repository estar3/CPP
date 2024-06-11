// 解引用 和 间接成员访问 操作符函数
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <memory>
using namespace std;
class A {
public:
    A() : m_f(open("./file", O_CREAT|O_RDWR, 0644)) {
        //【int m_f=open(...);】定义m_f,初值为文件描述符-->文件表等内核结构(动态资源)
        cout << "A() is invoked - 打开了file文件" << endl;
    }
    ~A() {
        close( m_f );
        cout << "~A() is invoked - 关闭了file文件" << endl;
        // 释放 m_f 本身所占内存空间
    }
    void foo( ) {
        write( m_f, "hello file", 10 );
        cout << "foo() is invoked - 书写了file文件" << endl;
    }
private:
    int m_f;
};
class Auto_ptr { // 智能指针类
public:
    Auto_ptr( A* a ) : m_a(a) {
        //【A* m_a=a;】
    }
    ~Auto_ptr( /* Auto_ptr* this */ ) {
        delete this->m_a; // 释放用户申请的堆内存
    }
    A& operator*() {
        return *m_a;
    }
    A* operator->() {
        return m_a;
    }
    Auto_ptr( Auto_ptr& that ) : m_a( that.m_a ) {
        //【A* m_a= that.m_a;】只复制了地址，没有复制地址指向的数据-->浅拷贝
        that.m_a = NULL;
    }
private:
    A* m_a; // 常规指针(保存的是用户申请的堆内存地址)
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    // 使用标准库设计的智能指针
    auto_ptr<A> pau(new A);
    (*pau).foo();
    pau->foo();

    auto_ptr<A> pbu = pau;
    (*pbu).foo();
    pbu->foo();

//  (*pau).foo(); // pau已经失效

    /* 使用自己的智能指针
    Auto_ptr pau(new A); // 定义 pau, 利用 pau.Auto_ptr( new A )
    (*pau).foo(); // pau.operator*().foo()
    pau->foo();   // pau.operator->()->foo();
    Auto_ptr pbu = pau;
    (*pbu).foo();
    pbu->foo();
//  (*pau).foo( ); // pau已经失效*/

    /* 常规指针
    A* pa = new A; // 定义 A类堆对象(堆内存),利用 A类堆对象.A()
    (*pa).foo( );
    pa->foo( );
    A* pb = pa;
    delete pa; // pa->~A()   释放 A类堆对象本身所占内存空间*/
    return 0;
} // pau.~Auto_ptr()  pbu.~Auto_ptr()   释放 pau/pbu 本身所占内存空间
