// string类对象的使用方法
#include <iostream>
using namespace std;

// C++标准库设计的string类 内部有一个成员 char* m_psz-->一个字符串

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    string s1("hello"); // 定义s1,利用s1.string("hello")-->s1维护的字符串为"hello"
    cout << "s1:" << s1.c_str() << endl;
    cout << "s1:" << s1 << endl;

    // 如果在做初始化,并且“=”两边的类型完全一致,那么=xxx 和(xxx)无差别

    string s2(s1); // = s1; 定义s2,利用s2.string(s1)-->s2维护的字符串 和 s1维护的字符串 内容相同
    cout << "s2:" << s2.c_str() << endl;
    cout << "s2:" << s2 << endl;

    string s3; // 定义s3,利用s3.string()-->s3维护的字符串为"\0"
    cout << "s3被赋值前:" << s3.c_str() << endl;
    cout << "s3被赋值前:" << s3 << endl;

    // 如果在做赋值,并且“=”两边类型完全一致,那么将触发operator=函数的调用

    s3 = s2; // s3.operator=(s2)--> s3维护的字符串 和 s2维护的字符串 内容相同
    cout << "s3被赋值后:" << s3.c_str() << endl;
    cout << "s3被赋值后:" << s3 << endl;

    // 只要“=”两边的类型不一致，编译器将“=”右边的类型 转换为和“=”左边的类型一致

    string s4 = "hello"; 
    // 定义 匿名string类对象,利用 匿名string类对象.string("hello")-->匿名string类对象维护的"hello"
    // string s4 = 匿名的string类对象;-->s4维护的字符串 和 匿名的string类对象维护的字符串 内容相同
    // -->s4维护的字符串为"hello"
    cout << "s4:" << s4.c_str() << endl;
    cout << "s4:" << s4 << endl;

    string s5; // 定义s5,利用s5.string()-->s5维护的字符串为"\0"
    s5 = "hello"; 
    // 定义 匿名string类对象,利用 匿名string类对象.string("hello")-->匿名string类对象维护的"hello"
    // s5 = 匿名string类对象; --> s5维护的字符串 和 匿名string类对象维护的字符串 内容相同
    // -->s5维护的字符串内容为"hello"
    cout << "s5:" << s5.c_str() << endl;
    cout << "s5:" << s5 << endl;
    return 0;
}
