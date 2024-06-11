// 构造函数的重载
#include <iostream>
using namespace std;
class Human {
public:
    void getinfo( /* Human* this */ ) { 
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
/*  Human( ) {
        cout << "1. Human()-->";
        m_age = 0;
        m_name = "无名";
    }
    Human( int age ) {
        cout << "2. Human(int)-->";
        m_age = age;
        m_name = "无名";
    }*/
    Human( int age=0, const char* name="无名" ) {
        cout << "3. Human(int,const char*)-->";
        m_age = age;
        m_name = name;
    }
private:
    int m_age;
    string m_name;
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Human h; // 定义h,利用h.Human()
    h.getinfo( );

    Human h2( 22 ); // 定义h2,利用h2.Human( 22 )
    h2.getinfo( );

    Human h3( 22, "张飞" ); // 定义h3,利用h3.Human(22,"张飞")
    h3.getinfo( );
    return 0;
}







