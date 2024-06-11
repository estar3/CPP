// 无参(缺省)构造构造函数
#include <iostream>
using namespace std;
class Human {
public:
//  如果类没有提供任何构造函数,编译器将提供一个无参构造函数
/*  Human( ) {
       【int m_age;】定义m_age,初值为随机数
       【string m_name;】定义m_name,利用m_name.string()
    }*/
    Human( int age=0, const char* name="无名" ) {
        //【int m_age;】定义m_age,初值为随机数
        //【string m_name;】定义m_name,利用m_name.string()
        cout << "Human类的缺省构造函数被调用" << endl;
        m_age = age;
        m_name = name;
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
    Human h; // 定义h,利用h.Human() --> h维护的内容为(无名0)
    h.getinfo( );

    Human h2(22,"张飞"); // 定义h2,利用h2.Human(22,"张飞") --> h2维护的内容为(张飞,22)
    h2.getinfo( );
    return 0;
}
