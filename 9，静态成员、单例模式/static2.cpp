// 静态成员变量  和  静态成员函数
#include <iostream>
#include <cstring>
using namespace std;
// 普通(非静态)成员函数:属于对象(普通成员函数必须利用对象来调用) 
// 静态成员变量:不属于对象(静态成员函数不必须对象来调用)

class A {
public:
    int m_i; // 普通成员变量
    void foo( /* const A* this */ ) const { // 普通成员函数
        cout << "A::foo" << endl;    
        cout << m_i << endl; // ok
        cout << m_si << endl;// ok
        bar( );              // ok 以上三行代码证明普通成员函数内即可访问普通成员也可访问静态成员
    }

    static int m_si; // 静态成员变量

    static void bar( /*无this参数*/ ) /*const*/ { // 静态成员函数
        cout << "A::bar" << endl;
        cout << m_si << endl; // ok,证明静态成员函数内部可以访问静态成员
//      cout << m_i << endl;  // error
//      foo( );               // error,以上两代码证明静态成员函数内不可以访问非静态成员
    } 
};

int A::m_si = 0; // 全局域中定义并初始化-->进程级生命期

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    A a, b; // 静态成员变量没有保存在对象中-->不属于对象
    a.foo(); // foo(&a)
    b.foo(); // foo(&b)

    A::bar(); // 受到类作用域的约束，也受到访问控制限定符的约束-->属于类
    a.bar();  // A::bar();
    b.bar();  // A::bar();
    return 0;
}





