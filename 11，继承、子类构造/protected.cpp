// 保护继承  
#include <iostream>
using namespace std;

class Base {
public: // 原始标记
    int m_a;
    void foo( ) {   cout << "Base::foo" << endl;    }
protected: // 原始标记
    int m_b;
    void bar( ) {   cout << "Base::bar" << endl;    }
private: // 原始标记
    int m_c;
    void hum( ) {   cout << "Base::hum" << endl;    }
};
class Derived : protected Base { // 子类将对基类的成员重新标记访问控制限定 m_a/foo是protected  m_b/bar是protected  m_c/hum是private
public:
    void fun( ) { // 子类内部 能否访问基类的某个成员,编译器需要查看这个成员在 直接基类中的 访问控制标记
        m_a = 100; // ok
        Base::foo( );// ok 
        m_b = 200; // ok
        bar( );    // ok 
//      m_c = 300; // error
//      hum( );    // error
    }
private:
    int m_d;
};
class Grandson : public Derived {
public:
    void boo( ) { // 子类内部 能否访问基类的某个成员,编译器需要查看这个成员在 直接基类中的 访问控制标记
        m_a = 100; // ok
        foo( );    // ok
        m_b = 200; // ok
        bar( );    // ok
//      m_c = 300; // error
//      hum( );    // error
    }
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {    
    Derived d;  // 当 利用子类对象，在类外访问基类的成员时,编译器需要查看 相应子类的重新标记
//    d.m_a = 1000; // error
//    d.foo( );     // error
//    d.m_b = 2000; // error
//    d.bar( );     // error
//    d.m_c = 3000; // error
//    d.hum( );     // error
    return 0;
}
