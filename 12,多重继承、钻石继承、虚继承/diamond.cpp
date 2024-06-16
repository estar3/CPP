// 钻石继承的问题
#include <iostream>
using namespace std;
class A { // 公共基类(人类)
public:
    int m_a; // 年龄
};
class X : public A { // 中间子类(学生类)
public:
    int m_x;
};
class Y : public A { // 中间子类(老师类)
public:
    int m_y;
};
class Z : public X, public Y { // 汇聚子类(助教类)
public:
    int m_z;
    void foo( ) {
        X::m_a = 100; // 歧义
    }
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Z z; // |X中间子类子对象|Y中间子类子对象|m_z| --> |A公共基类子对象 m_x|A公共基类子对象 m_y|m_z| --> |m_a m_x|m_a m_y|m_z|
    cout << "汇聚子类对象z的大小: " << sizeof(z) << endl; // 20

    z.Y::m_a = 100; // 歧义
    return 0;
} 
