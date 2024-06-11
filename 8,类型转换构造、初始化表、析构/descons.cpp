// 析构函数
#include <iostream>
using namespace std;
class Human {
public:
//  如果类没有提供任何构造函数,编译器将提供一个无参构造函数
/*  Human( ) {
       【int m_age;】定义m_age,初值为随机数
       【string m_name;】定义m_name,利用m_name.string()
    }*/
    Human( int age=0, const char* name="无名" ) : m_age(age), m_name(name) {
        //【int m_age=age;】定义m_age,初值为age
        //【string m_name(name);】定义m_name,利用m_name.string(name)
        cout << "Human类的缺省构造函数被调用" << endl;
    }
//  如果类没有提供拷贝构造函数,编译器将提供一个默认的拷贝构造函数
/*  Human( const Human& that ) {  
       【int m_age=that.m_age;】定义m_age,初值为that.m_age
       【string m_name(that.m_name);】定义m_name,利用m_name.string(that.m_name)
    }*/
    Human( const Human& that ) : m_age(that.m_age), m_name(that.m_name) { 
        //【int m_age=that.m_age;】定义m_age,初值为that.m_age
        //【string m_name(that.m_name);】定义m_name,利用m_name.string(that.m_name)
        cout << "Human类的拷贝构造函数被调用" << endl;
    }
//  如果类没有提供拷贝赋值函数,编译器将提供一个默认拷贝赋值函数
/*  Human& operator=( const Human& that ) {
        this->m_age = that.m_age;
        this->m_name = that.m_name; // this->m_name.operator=(that.m_name)
        return *this;
    }*/
    Human& operator=( /* Human* this */ const Human& that ) { 
        // 编译器不会在 自定的拷贝赋值函数中 塞任何操作
        cout << "Human类的拷贝赋值函数被调用" << endl;
        this->m_age = that.m_age;
        this->m_name = that.m_name;
        return *this;
    }
//  如果类没有提供析构函数,那么编译器将提供一个默认的析构函数
/*  ~Human( ) {
        对于基本类型的成员变量m_age,什么都不做
        对于类类型的成员变量m_name,利用 m_name.~string()
        释放 m_age/m_name 本身所占内存空间
    }*/
    
    ~Human( ) {
        cout << "Human类的析构函数被调用" << endl;
        // 对于基本类型的成员变量m_age,什么都不做
        // 对于类类型的成员变量m_name,利用 m_name.~string()
        // 释放 m_age/m_name 本身所占内存空间
    }
    
    void getinfo( /* Human* this */ ) { 
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    cout << "-------------h的创建信息---------------" << endl;
    Human h; // 定义h,利用h.Human() --> h维护的内容为(无名0)
    h.getinfo( );

    cout << "-------------h2的创建信息---------------" << endl;
    Human h2(22,"张飞"); // 定义h2,利用h2.Human(22,"张飞") --> h2维护的内容为(张飞,22)
    h2.getinfo( );
    
    cout << "-------------h3的创建信息---------------" << endl;
    Human h3(h2); // = h2; // 定义h3,利用h3.Human( h2 ) --> h3维护的内容 和 h2维护的内容 相同
    h3.getinfo( );
    
    cout << "-------------h4的创建信息---------------" << endl;
    Human h4; // 定义h4,利用h.Human() --> h4维护的内容为(无名0)
    cout << "h4被赋值前 --- ";
    h4.getinfo( );
    h4 = h3; // h4.operator=(h3) --> h4维护的内容 和 h3维护的内容 相同
    cout << "h4被赋值后 --- ";
    h4.getinfo( );
    return 0;
} // (1) h.~Human()  h2.~Human()  h3.~Human()  h4.~Human()   (2) 释放 h/h2/h3/h4 这个四个对象 本身所占内存空间
