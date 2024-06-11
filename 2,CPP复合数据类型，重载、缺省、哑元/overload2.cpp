// 详谈同一作用域内
#include <iostream>
using namespace std;
namespace ns1 {
    void foo( char* c, short s ) {
        cout << "1. foo" << endl;
    }
    void foo( int i, double d ) {
        cout << "2. foo" << endl;
    }
}
namespace ns2 {
    void foo( const char* c, short s ) {
        cout << "3. foo" << endl;
    } 
    void foo( double d, int i ) {
        cout << "4. foo" << endl;
    }
}
int main( void ) {
    using namespace ns1; // 名字空间指令(ns1中foo在当前作用域可见-出现在可见表中)
    using ns2::foo; // 名字空间声明(ns2中的foo引入当前作用域-出现在定义表中)
    char* c;    short s;
    foo( c, s );  // 因为 第3个foo函数 将 第1个foo函数 隐藏，所以调用的为第3个foo
    
    return 0;
}
