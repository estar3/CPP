// 操作符重载
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
    Human sum( /* Human* this */ Human that ) {
        return Human( this->m_age+that.m_age, (this->m_name+"+"+that.m_name).c_str() );  
    }
    Human sub( /* Human* this */ Human that ) {
        return Human( this->m_age-that.m_age, (this->m_name+"-"+that.m_name).c_str() );  
    }
private:
    int m_age; 
    string m_name; 
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
      Human a(22,"张飞"), b(20,"赵云"), c(25,"关羽"), d(32,"马超");

      Human res = a.sum(b); // a + b; ==> a.operator+(b)  或  operator+(a,b)
      res.getinfo( );

      res = c.sub(d); // c - d; ==> c.operator-(d)  或  operator-(c,d)
      res.getinfo( );

    /*    
    int a=3, b=4, c=5, d=6;
    a + b;
    c - d;
    */
    return 0;
}
