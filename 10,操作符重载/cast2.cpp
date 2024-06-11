// 类型转换构造函数 和 类型转换操作符函数
#include <iostream>
using namespace std;

class Dog; // 短式声明

class Cat {
public:
    Cat( const char* name ) : m_name(name) {
        //【string m_name(name);】
    }
    operator Dog( /* const Cat* this */ ) const;
    void talk( ) {
        cout << m_name << ": 喵喵~~~" << endl;
    }
private:
    string m_name;
    friend class Dog;
};

class Dog {
public:
    Dog( const char* name ) : m_name(name) { 
        //【string m_name(name);】
    }
    Dog( const Cat& that ) : m_name(that.m_name) { // 类型转换构造函数(提供转换规则)
        //【string m_name=that.m_name;】
        cout << "Dog类的类型转换构造函数被调用" << endl;
    }
    void talk( ) {
        cout << m_name << ": 汪汪~~~" << endl;
    }
private:
    string m_name;
};
Cat::operator Dog( /* const Cat* this */ ) const {
    cout << "Cat类的类型转换操作符函数被调用" << endl;
    return Dog( this->m_name.c_str() );
}
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Cat smallwhite("小白"); 

    // Cat --> Dog (类类型-->类类型)
    Dog bigyellow = smallwhite; // 定义 匿名Dog类对象,利用 匿名Dog类对象.Dog(smallwhite)-->触发类型转换构造函数
                                // Dog bigyellow = smallwhite.operator Dog() -->  触发类型转换操作符函数                              


    return 0;
}
