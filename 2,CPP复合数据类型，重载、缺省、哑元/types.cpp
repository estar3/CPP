// C++的复合类型 和 c的复合类型 的差别

#include <iostream>
#include <cstring>
using namespace std;

void TestStruct( ) {
    struct Student {
        int m_age; // 成员变量
        char m_name[256]; // 成员变量
        void getinfo( ) { // 成员函数
            cout << "姓名: " << m_name << ", 年龄: " << m_age << endl;
        }
    };
    /*struct*/ Student s;
    s.m_age = 22;
    strcpy( s.m_name, "张飞" );
    cout << "姓名: " << s.m_name << ", 年龄: " << s.m_age << endl;
    s.getinfo( );
}

void TestUnion( ) {
    union { // 匿名联合体,主要体现的是联合体中所有成员的内存排布方式(共用同一块内存空间)
        int i;
        char c[4];
    };
    i = 0x12345678; // 小端字节序：低数位 占 低地址
    cout << hex << (int)c[0] << ' ' << (int)c[1] << ' ' << (int)c[2] << ' ' << (int)c[3] << endl;
}

void TestEnum( ) {
    enum Color { red, green, blue };
    /*enum*/ Color c = red; // = 0 - error(C++语言对类型检查更加严格)
    cout << "c=" << c << endl;
}

void TestBool( ) {
    bool a = ""; // "hello"; // 0.000000001; // 123; // true;
    bool b = NULL;      // 0.000000000; // 0;   // false;
    cout << "a=" << a << ", b=" << b << endl;
}
int main( void ) {
    TestBool( );
//  TestEnum( );
//  TestUnion( );
//  TestStruct( );    
    return 0;
}




