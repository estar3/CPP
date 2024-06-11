// 构造函数
#include <iostream>
#include <cstring>
using namespace std;
class Human {
public:
    Human( /* Human* this */ int age=0, const char* name="无名" ) {
        // 在this所指向的内存空间中 定义m_age(给m_age分配内存空间),初值为随机数
        // 在this所指向的内存空间中 定义m_name(给m_name分配内存空间),初值为随机数
        cout << "Human类的构造函数被调用" << endl;
        strcpy( this->m_name, name );
        this->m_age = age;
    }
//    void setinfo( /* Human* this */ int age=0, const char* name="无名" ) { 
//        this->m_age = age;
//        strcpy( this->m_name, name );
//    }
    void getinfo( /* Human* this */ ) { 
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age << endl;
    }
private:
    int m_age;
    char m_name[256];
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Human h(22,"张飞"); // 定义h(给h分配内存空间),利用h.Human(22,"张飞")  
    cout << "h对象定义完毕 " << endl;
//    h.setinfo( 22, "张飞" ); 
    h.getinfo( ); 

    return 0;
}







