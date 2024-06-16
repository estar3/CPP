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
    // 深拷贝构造函数--体现的为资源的重建
    String( const String& that ) : m_psz(new char[strlen(that.m_psz)+1]) {
        //【char* m_psz=new char[strlen(that.m_psz)+1];】
        strcpy( m_psz, that.m_psz ); // 不复制地址，复制地址指向的数据-->深拷贝
        cout << "深拷贝构造函数被调用" << endl;
    }
    // 转移构造函数--体现的为资源的转移
    String( String&& that ) : m_psz(that.m_psz) {
        //【char* m_psz=that.m_psz;】
        that.m_psz = NULL;
        cout << "转移构造函数被调用" << endl;
    }
//  默认的拷贝赋值函数
/*  String& operator=( const String& that ) {
        this->m_psz = that.m_psz; // 只复制了地址,没有复制地址指向的数据-->浅拷贝
        return *this;
    }*/
    // 深拷贝赋值函数--体现的为资源的重建
    String& operator=( /* String* this */ const String& that ) {
        cout << "深拷贝赋值函数被调用" << endl;
        if( this!=&that ) { // 防止自赋值
            delete[] this->m_psz; // 释放旧资源
            this->m_psz = new char[strlen(that.m_psz)+1]; // 申请新资源
            strcpy( this->m_psz, that.m_psz ); // 复制新内容（数据）
        }
        return *this; // 返回自引用
    }
    // 转移赋值函数--体现的为资源的转移
    String& operator=( /* String* this */ String&& that ) {
        cout << "转移赋值函数被调用" << endl;
        delete[] this->m_psz; // 释放旧资源
        this->m_psz = that.m_psz; 
        that.m_psz = NULL; // 以上两句代码体现资源的转移
        return *this;
    }
private:
    char* m_psz; // 指针型的成员变量
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    String a("hello");
    
    cout << "--------------------------1----------------------------" << endl;
    String b = a; // 定义b,利用b.String(a)-->触发String类深拷贝构造函数
    
    cout << "--------------------------2----------------------------" << endl;
    String c = String("world"); // 定义c,利用c.String( String("world") )-->触发String类转移构造函数

    cout << "--------------------------3----------------------------" << endl;
    String d;
    d = a; // d.operator=(a)-->触发String类的深拷贝赋值函数
    
    cout << "--------------------------4----------------------------" << endl;
    d = String("hello world"); // d.operator=( String("hello world") )-->触发的为String类深拷贝赋值函数
    return 0;
}
