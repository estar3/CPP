// 单例模式:设计一个类，保证用户在使用这个类时，只能出现一个对象
#include <iostream>
using namespace std;
// 饿汉式单例
class Singleton {
public://4        //5
    static Singleton& getInstance( ) {
        return s_instance;
    }
private:
    Singleton() {} // 1
    Singleton( const Singleton& that ) {} // 6
    static Singleton s_instance; // 唯一对象  2
};

Singleton Singleton::s_instance; // 3

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();
    Singleton& s3 = Singleton::getInstance();
    cout << "&s1: " << &s1 << ", &s2: " << &s2 << ", &s3: " << &s3 << endl;
    return 0;
}
