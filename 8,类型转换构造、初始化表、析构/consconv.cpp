// 类型转换构造函数
#include <iostream>
using namespace std;
class Cat {
public:
    explicit Cat( const char* name ) : m_name(name) { // 类型转换构造函数
        //【string m_name(name);】
        cout << "Cat类的类型转换构造函数被调用" << endl;
    }
    void talk( ) {
        cout << m_name << ": 喵喵~~~" << endl;
    }
private:
    string m_name;
    friend class Dog;
};

class Dog {
public:
    Dog( const char* name ) : m_name(name) { // 类型转换构造函数
        //【string m_name(name);】
    }
    explicit Dog( const Cat& that ) : m_name(that.m_name) { // 类型转换构造函数(提供转换规则)
        //【string m_name=that.m_name;】
        cout << "Dog类的类型转换构造函数被调用" << endl;
    }
    void talk( ) {
        cout << m_name << ": 汪汪~~~" << endl;
    }
private:
    string m_name;
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
//  Cat smallwhite("小白"); // 定义smallwhite,利用smallwhite.Cat("小白")-->触发类型转换构造函数

//  Cat smallwhite = "小白"; // 定义 匿名Cat类对象, 利用 匿名Cat类对象.Cat("小白") --> 触发类型转换构造函数
                             // Cat smallwhite = 匿名Cat类对象;
    
    Cat smallwhite = static_cast<Cat>("小白"); // 定义 匿名Cat类对象, 利用 匿名Cat类对象.Cat("小白") --> 触发类型转换构造函数
                                               // Cat smallwhite = 匿名Cat类对象;
    smallwhite.talk( );

//  Dog bigyellow( smallwhite ); // 定义bigyellow,利用bigyellow.Dog( smallwhite )-->触发类型转换构造函数

//  Dog bigyellow = smallwhite; // 定义 匿名Dog类对象,利用 匿名Dog类对象.Dog(smallwhite)-->触发类型转换构造函数
                                // Dog bigyellow = 匿名Dog类对象;

    Dog bigyellow = static_cast<Dog>(smallwhite); // 定义 匿名Dog类对象,利用 匿名Dog类对象.Dog(smallwhite)-->触发类型转换构造函数
                                                 // Dog bigyellow = 匿名Dog类对象;
    bigyellow.talk( );

    return 0;
}
