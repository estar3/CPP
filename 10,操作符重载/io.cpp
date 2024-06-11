// 输出、输入 操作符函数
#include <iostream>
using namespace std;
class Human { 
public:
    Human( int age=0, const char* name="无名" ) : m_age(age), m_name(name) {
        //【int m_age=age;】定义m_age,初值为age
        //【string m_name(name);】定义m_name,利用m_name.string(name)
    }
    void getinfo( /* Human* this */ ) { 
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
    // 成员形式的操作符函数
private:
    int m_age; 
    string m_name; 
    friend ostream& operator<<( ostream& os, const Human& that ) ;
    friend istream& operator>>( istream& is, Human& that ) ;
};
// 全局形式的操作符函数
ostream& operator<<( ostream& os, const Human& that ) {
    os << "姓名: " << that.m_name << ", 年龄: " << that.m_age;
    return os;
}
istream& operator>>( istream& is, Human& that ) {
    is >> that.m_name >> that.m_age;
    return is;
}
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Human a(22,"张飞"), b(20,"赵云"); // 非常左值
    const Human c(25,"关羽"), d(32,"马超"); // 常左值


    cout << a << endl; // cout.operator<<(a)  或  operator<<(cout,a)
//  a.getinfo( );
    cout << b << endl; // cout.operator<<(b)  或  operator<<(cout,b)
    cout << Human(45,"黄忠") << endl; // cout.operator<<( Human(45,"黄忠") )  或  operator<<(cout,Human(45,"黄忠"))

    cin >> a; // cin.operator>>(a)  或  operator>>(cin,a)
    cout << a << endl;

    /*
    int a=3, b=4; // 非常左值
    const int c=5, d=6; // 常左值
    
    cout << a << endl;

    cout << c;

    cout << 5;
    */
    return 0;
}
