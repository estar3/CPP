// 成员函数的形参 -- this
#include <iostream>
#include <cstring>
using namespace std;
// 在这个程序中有两个对象(h/h2),每个对象中各有一份成员变量(共有两份成员变量),而成员函数只有1份
class Human {
public:
    void setinfo( /* Human* this */ int age=0, const char* name="无名" ) { // _ZN5Human7setinfoEiPKc
        this->m_age = age;
        strcpy( this->m_name, name );
    }
    void getinfo( /* Human* this */ ) { // _ZN5Human7getinfoEv
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
private:
    int m_age;
    char m_name[256];
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Human h; // 定义h(给h分配内存空间)
             // 在h所占据的内存空间中 定义m_age(给m_age分配内存空间),初值为随机数
             // 在h所占据的内存空间中 定义m_name(给m_name分配内存空间),初值为随机数
    cout << "h的大小: " << sizeof(h) << endl; // 260
    h.setinfo( 22, "zhangfei" ); // _ZN5Human7setinfoEiPKc( &h, 22, "zhangfei" )
    h.getinfo( ); // _ZN5Human7getinfoEv( &h )

    Human h2; // 定义h2(给h2分配内存空间)
              // 在h2所占据的内存空间中 定义m_age(给m_age分配内存空间),初值为随机数
              // 在h2所占据的内存空间中 定义m_name(给m_name分配内存空间),初值为随机数
    cout << "h2的大小: " << sizeof(h2) << endl; // 260
    h2.setinfo( 20, "zhaoyun" ); // _ZN5Human7setinfoEiPKc( &h2, 20 "zhaoyun" )
    h2.getinfo( ); // _ZN5Human7getinfoEv( &h2 )

    return 0;
}
