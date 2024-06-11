// 重载匹配的优先级
#include <iostream>
using namespace std;

void foo( char* c, short s ) { // _Z3fooPcs
    cout << "1. foo(char*,short)" << endl;
}
void foo( const char* c, short s ) { // _Z3fooPKcs
    cout << "2. foo(const char*,short)" << endl;
}
void foo( char* c, int s ) { // _Z3fooPci
    cout << "3. foo(char*,int)" << endl;
}
void foo( char* c, char s ) { // _Z3fooPcc
    cout << "4. foo(char*,char)" << endl;
}
void foo( ... ) { // _Z3fooz
    cout << "5. foo(...)" << endl;
}
int main( void ) {
    char* c;    short s;
    foo( c, s ); // _Z3fooPcs( c, s )
    // 普通方式调用重载关系的函数，根据 实参类型 和 形参类型 的匹配度确定到底调用哪个foo

    void(*pfunc)(const char*, short) = foo; // _Z3fooPKcs
    pfunc( c, s ); // 函数指针调用重载关系的函数，根据 函数指针本身类型 确定到底调用哪个foo
    return 0;
}




