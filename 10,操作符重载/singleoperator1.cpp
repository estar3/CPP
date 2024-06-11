// 运算类单目操作符函数
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
    Human operator-( /* const Human* this */ ) const {
        return Human(-this->m_age, ("-"+this->m_name).c_str() );
    }
private:
    int m_age; 
    string m_name; 
};
// 全局形式的操作符函数

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Human a(22,"张飞"), b(20,"赵云"); // 非常左值
    const Human c(25,"关羽"), d(32,"马超"); // 常左值

    Human res = -a; // a.operator-()  或  operator-(a)
    res.getinfo( );

    res = -c; // c.operator-()  或  operator-(c)
    res.getinfo( );

    res = -Human(45,"黄忠"); // Human(45,"黄忠").operator-()  或  operator-( Human(45,"黄忠") )
    res.getinfo( );

    /*
    int a=3, b=4; // 非常左值
    const int c=5, d=6; // 常左值
    
    |..| -a;

    |..| -c; 
    
    |-5| -5;
    */
    return 0;
}
