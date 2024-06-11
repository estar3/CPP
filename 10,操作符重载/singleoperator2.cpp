// 输出、输入 操作符函数
#include <iostream>
using namespace std;
class Human { 
public:
    Human( int age=0, const char* name="无名" ) : m_age(age), m_name(name) {
        //【int m_age=age;】定义m_age,初值为age
        //【string m_name(name);】定义m_name,利用m_name.string(name)
    }
    // 成员形式的操作符函数
    Human& operator++( /* Human* this */ ) {
        this->m_age += 1; // 直接加1
        return *this;
    }
    Human operator++( /* Human* this */ int ) {
        Human old = *this; // 备份b原来的值
        this->m_age += 1; // 直接加1
        return old; // 返回b原来的值
    }
private:
    int m_age; 
    string m_name; 
    friend ostream& operator<<( ostream& os, const Human& that ) ;
};
// 全局形式的操作符函数
ostream& operator<<( ostream& os, const Human& that ) {
    os << "姓名: " << that.m_name << ", 年龄: " << that.m_age;
    return os;
}
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Human a(22,"张飞"), b(20,"赵云"); // 非常左值

    cout << ++a << endl; // a.operator++()  或  operator++(a)    

    cout << /*| |*/ b++ << endl; // b.operator++(0)  或  operator++(b,0)
    cout << b << endl;

    /*
    int a=3, b=4; // 非常左值
    
    ++a;

    |4| b++;
    */
    return 0;
}
