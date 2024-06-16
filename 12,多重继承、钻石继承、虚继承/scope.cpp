// 多重继承的名字冲突的问题
#include <iostream>
using namespace std;
class A { // 学生类
public:
    int m_a;
    int m_c; // 成绩
};
class B { // 老师类
public:
    int m_b;
    int m_c; // 工资
};
class D : public A, public B { // 助教类
public:
    int m_d;
//  int m_c; // 在业务上毫无意义，仅仅将基类的m_c隐藏
    void foo( ) {
        B::m_c = 8000; // 
    }
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    D d; // |A基类子对象|B基类子对象|m_d| --> |m_a m_c|m_b m_c|m_d|
    cout << "汇聚子类对象ｄ的大小: " << sizeof(d) << endl; // 20

    d.A::m_c = 100; // 
    return 0;
} 





