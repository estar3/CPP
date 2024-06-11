// 继承最基本的特点:
// (1) 子类对象的内部 包含 基类(子)对象
// (2) 子类内部 可以访问 基类的 非私有(公有/保护)成员(变量/函数)
#include <iostream>
using namespace std;

class Base {
public:
    int m_a;
    void foo( ) {   cout << "Base::foo" << endl;    }
protected:
    int m_b;
    void bar( ) {   cout << "Base::bar" << endl;    }
private:
    int m_c;
    void hum( ) {   cout << "Base::hum" << endl;    }
};
//class Derived : public Base {
//class Derived : protected Base {
class Derived : private Base {
public:
    void fun( ) {
        m_a = 100; // ok
        foo( );    // ok,以上两行代码证明 子类内部可以访问基类的公有成员(变量/函数)
        m_b = 200; // ok
        bar( );    // ok,以上两行代码证明 子类内部可以访问基类的保护成员(变量/函数)
//      m_c = 300; // error
//      hum( );    // error,以上两行代码证明 子类内部不可以访问基类的私有成员(变量/函数)
    }
private:
    int m_d;
};

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Base b; // |m_a m_b m_c|
    cout << "基类对象b的大小: " << sizeof(b) << endl; // 12
    Derived d; // |基类子对象|m_d| --> |m_a m_b m_c|m_d| ==> 证明:子类对象的内部 包含 基类(子)对象
    cout << "子类对象d的大小: " << sizeof(d) << endl; // 16
    return 0;
}
