#include <iostream>
using namespace std;
/*
class A { // 空类  
};
int main( void ) {
    A a; // 空类对象占1个字节的内存空间(保存了1个字节的垃圾数据)
    A& ra = a;
    cout << "a对象的大小: " << sizeof(a) << endl;
    return 0;
}
*/

class A {
public:
    int m_i;
//  A m_a; // 类中 不能包含 本类对象 作为成员 
    static A m_a; // 类中 能包含 本类的静态对象 作为成员
};
int main( void ) {
    A a; // 定义a(给a分配内存空间)
    cout << "a对象的大小: " << sizeof(a) << endl;
    return 0;
}
