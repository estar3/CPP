// 虚继承---钻石继承问题的解决方法
// (1) 公共虚基类子对象 在 汇聚子类对象中 只有一份
// (2) 公共虚基类子对象 被 各个中间子类子对象共享
#include <iostream>
using namespace std;
#pragma pack(1)
class A { // 公共虚基类(人类)
public:
    int m_a; // 年龄
};
class X : virtual public A { // 中间子类(学生类)
public:
    int m_x;
    void setAge( /* X* this */ int age ) {
        this->m_a = age; // (1) this (2)X中间子类子对象 (3)指针1 (4)偏移量 (5)this+偏移量 (6)A公共虚基类子对象的首地址
    }
};
class Y : virtual public A { // 中间子类(老师类)
public:
    int m_y;
    int getAge( /* Y* this*/ ) {
        return this->m_a; // (1) this (2)Y中间子类子对象 (3)指针2 (4)偏移量 (5)this+偏移量 (6)A公共虚基类子对象的首地址
    }
};
class Z : public X, public Y { // 汇聚子类(助教类)
public:
    int m_z;
    void foo( ) {
        m_a = 100; 
    }
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Z z; // |X中间子类子对象|Y中间子类子对象|m_z|A公共虚基类子对象| --> |指针1 m_x|指针2 m_y|m_z|m_a|
    cout << "汇聚子类对象z的大小: " << sizeof(z) << endl; // 32
    z.setAge( 28 ); // setAge( &z, 28 )
    cout << z.getAge() << endl; // getAge( &z );
    return 0;
} 
