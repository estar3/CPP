// 默认的拷贝构造 和 拷贝赋值 函数，在特定场景下(类中有指针成员) 会出现浅拷贝的缺陷
#include <iostream>
#include <cstring>
using namespace std;
// 模拟C++标准库的string类,自己设计一个String类
class String {
public:
    String( const char* psz="" ) : m_psz(new char[strlen(psz)+1]) {
        //【char* m_psz=new char[strlen(psz)+1];】定义m_psz,初值为指向一块堆内存(动态资源)
        strcpy( m_psz, psz );
    }
    ~String( /* String* this */ ) {
        delete[] this->m_psz;
        // 释放m_psz本身所占内存空间
    }
    char* c_str() { return m_psz;   }
    // 默认的拷贝构造函数
/*  String( const String& that ) {
       【char* m_psz=that.m_psz;】只复制了地址，没有复制地址指向的数据-->浅拷贝
    }*/
    // 深拷贝构造函数
    String( const String& that ) : m_psz(new char[strlen(that.m_psz)+1]) {
        //【char* m_psz=new char[strlen(that.m_psz)+1];】
        strcpy( m_psz, that.m_psz ); // 不复制地址，复制地址指向的数据-->深拷贝
    }
//  默认的拷贝赋值函数
/*  String& operator=( const String& that ) {
        this->m_psz = that.m_psz; // 只复制了地址,没有复制地址指向的数据-->浅拷贝
        return *this;
    }*/
    // 深拷贝赋值函数
    String& operator=( /* String* this */ const String& that ) {
        if( this!=&that ) { // 防止自赋值
            delete[] this->m_psz; // 释放旧资源
            this->m_psz = new char[strlen(that.m_psz)+1]; // 申请新资源
            strcpy( this->m_psz, that.m_psz ); // 复制新内容（数据）
        }
        return *this; // 返回自引用
    }
private:
    char* m_psz; // 指针型的成员变量
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    String s1("hello"); // 定义s1,利用 s1.String("hello")
    cout << "s1: " << s1.c_str() << ", s1中m_psz指针指向的堆内存地址: " << (void*)s1.c_str() << endl;

    String s2 = s1; //(s1) 定义s2,利用 s2.String( s1 )-->触发拷贝构造函数
    cout << "s2: " << s2.c_str() << ", s2中m_psz指针指向的堆内存地址: " << (void*)s2.c_str() << endl;

    String s3; // 定义s3,利用s3.String()-->维护一个字节的内存"\0"
    cout << "s3被赋值前:" << s3.c_str() << ", s3中的m_psz指针指向的堆内存地址: " << (void*)s3.c_str() << endl;

    s3 = s2; // s3.operator=(s2)
    cout << "s3被赋值后:" << s3.c_str() << ", s3中的m_psz指针指向的堆内存地址: " << (void*)s3.c_str() << endl;

    return 0;
} // s1.~String()  s2.~String()   释放s1/s2本身所占内存空间






