// this 和 虚函数
#include <iostream>
using namespace std;
class Base {
public:
    Base( /* Base* this */ ) {
        cout << "构造函数中调用: ";
        this->vfun( );
    }
    ~Base( /* Base* this */ ) {
        cout << "析构函数中调用: ";
        this->vfun( );
    }
    void foo( /* Base* this */ ) {
        cout << "foo函数中调用: ";
        this->vfun( );
    }
    virtual void vfun( ) {   cout << "Base::vfun" << endl;   }
};
class Derived : public Base {
public:
    Derived( ) {
        //【Base();】定义基类子对象,利用 基类子对象.Base()
    }
    ~Derived( ) {
        // 对于 基类子对象, 利用 基类子对象.~Base()
    }
    void vfun( ) { cout << "Derived::vfun" << endl;  }
};
// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Derived d; // 定义d,利用d.Derived()
    d.foo( ); // foo( &d )
    return 0;
} // d.~Derived()   释放d本身所占内存空间
