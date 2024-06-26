// 多重继承 - 子类对象内部 包含 多个基类子对象
#include <iostream>
using namespace std;
class A {
public:
    A( ) {  cout << "A() is invoked" << endl;   }
    ~A( ) {  cout << "~A() is invoked" << endl;   }
    int m_a;
};
class B {
public:
    B( ) {  cout << "B() is invoked" << endl;   }
    ~B( ) {  cout << "~B() is invoked" << endl;   }
    int m_b;
};
class C {
public:
    C( ) {  cout << "C() is invoked" << endl;   }
    ~C( ) {  cout << "~C() is invoked" << endl;   }
    int m_c;
};
class D : public A, public B, public C { // 汇聚子类
public:
    D( ) {
        //【A();】
        //【B();】
        //【C();】
        //【int m_d;】
    }
    ~D( ) {
        // ~C()
        // ~B()
        // ~A()
        // ... ...
    }
    int m_d;
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    D d; // |A基类子对象|B基类子对象|C基类子对象|m_d| --> |m_a|m_b|m_c|m_d|
    cout << "汇聚子类对象d的大小: " << sizeof(d) << endl; // 16
    
    D* pd = &d;
    cout << "整个汇聚子类对象的首地址 D* pd:" << pd << endl;

    cout << "A基类子对象的首地址: " << &d.m_a << endl;
    cout << "B基类子对象的首地址: " << &d.m_b << endl;
    cout << "C基类子对象的首地址: " << &d.m_c << endl;
    cout << "D类自己的成员  &m_d: " << &d.m_d << endl;
    
    
    return 0;
} // d.~D()
