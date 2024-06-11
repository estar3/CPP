// 引用 作为 函数的形参
#include <iostream>
using namespace std;
// 经验之谈：在设计一个函数时，主要能保证函数内部不需要修改实参，那就大胆的带上const

void Swap( int& x, int& y ) { // 非常引用型参数，可以在函数内部直接修改实参
    int z = x;
    x = y;
    y = z;
}
void Swap( int* x, int* y ) { 
    int z = *x;
    *x = *y;
    *y = z;
}
void Print( const int& x, const int& y ) { // 常引用型参数,可以防止在函数内部意外修改实参
//  x = 8888;
    cout << x << ' ' << y << endl;
}
int main( void ) {
    int a=10, b=20;
    Swap( a, b );
//
//  Swap( &a, &b );
    cout << "a=" << a << ", b=" << b << endl;
    Print( a, b );

    Print( 6666, 9999 );
    return 0;
}







