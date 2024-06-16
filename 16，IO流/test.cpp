// 将类对象放置在bool上下文中
#include <iostream>
using namespace std;

class A {
public:
    A( int i ) : m_i(i) {
        //【int m_i=i;】
    }
    operator bool( /* const A* this */ ) const {
        cout << "A类的类型转换操作符函数被调用" << endl;
        return this->m_i;
    }
private:
    int m_i;
};

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    A a(8888), b(0);

    bool c = a; // bool c = a.operator bool() -> A类型转换操作符函数
    cout << "c=" << c << endl;

    bool d;
    d = b; // d = b.operator bool()
    cout << "d=" << d << endl;

    if( a ) { // a.operator bool()
        cout << "if语句的判定条件为true" << endl;
    }

    while( a ) { // a.operator bool()
        cout << "while循环的判定条件为true" << endl;
        break;
    }

    for( ; a ; ) { // a.operator bool()
        cout << "for循环的第二个判定条件为true" << endl;
        break;
    }

    cout << !a << endl; // ! a.operator bool()
    return 0;
}








