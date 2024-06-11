// 单例模式:设计一个类，保证用户在使用这个类时，只能出现一个对象
#include <iostream>
using namespace std;
// 懒汉式单例:单例高级实现手法
class Singleton {
public:
    static Singleton& getInstance( ) {
        if( s_instance==NULL ) {
            s_instance = new Singleton; // 唯一的对象
            cout << "创建了唯一的对象" << endl;
        }
        ++s_counter;
        return *s_instance;
    }
    void releaseInstance( ) {
        if( --s_counter == 0 ) {
            delete s_instance;
            s_instance = NULL;
            cout << "销毁了唯一的对象" << endl;
        }
    }
private:
    Singleton() {} 
    Singleton( const Singleton& that ) {} 
    static Singleton* s_instance; // 并不是唯一对象,仅仅是一个指针而已
    static int s_counter; // 计数功能
};

Singleton* Singleton::s_instance = NULL; // 程序刚刚时，唯一的对象不存在 
int Singleton::s_counter = 0;

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Singleton& s1 = Singleton::getInstance(); // 第一次调用getInstance函数时,创建唯一的对象
    Singleton& s2 = Singleton::getInstance(); // 以后再调用getInstance函数时,返回第一次调用时创建的对象
    Singleton& s3 = Singleton::getInstance(); // ...
    cout << "&s1: " << &s1 << ", &s2: " << &s2 << ", &s3: " << &s3 << endl;
    s1.releaseInstance( ); //
    s2.releaseInstance( ); // 
    s3.releaseInstance( ); // 最后一次调用releaseInstance才将对象销毁
    return 0;
}
