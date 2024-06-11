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
class Derived : public Base {
//class Derived : protected Base {
//class Derived : private Base {
public:
    void fun( ) {
        m_a = 100; // ok
        Base::foo( );    // ok , 子类的foo函数将基类的foo函数隐藏,但是利用作用域限定符 可以指明 调用基类的foo
        m_b = 200; // ok
        bar( );    // ok , 子类的bar函数将基类的bar函数隐藏
//      m_c = 300; // error
//      hum( );    // error
    }
private:
    void foo( ) {   cout << "Derived::foo" << endl; }
    void bar( ) {   cout << "Derived::bar" << endl; }
    int m_d;
};

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    
    Derived d; 
    d.fun( );    
    return 0;
}
