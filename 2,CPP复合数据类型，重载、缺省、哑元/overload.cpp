// 函数之间的关系 - 重载(1.同一作用域内 2.函数名相同  3.形参表不同)
// 形参表是否相同 和 形参名无关，与 形参的个数 以及 每个"对应"形参的类型 有关
#include <iostream>
using namespace std;

void foo( char* c, short s ) {
    cout << "1. foo" << endl;
}
void foo( int i, double d ) {
    cout << "2. foo" << endl;
} 
void foo( const char* c, short s ) {
    cout << "3. foo" << endl;
} 
void foo( double d, int i ) {
    cout << "4. foo" << endl;
} 

// int foo( double d, int i ) {} // 是否为重载关系，和返回值类型无关
// void foo( int d, double i ) {} // 是否为重载关系，和 形参名无关

int main( void ) {
    char* c;    short s;
    foo( c, s );  // 1
    const char* cc;
    foo( cc, s ); // 3

    int i;  double d;
    foo( i, d ); // 2
    foo( d, i ); // 4
    return 0;
}




