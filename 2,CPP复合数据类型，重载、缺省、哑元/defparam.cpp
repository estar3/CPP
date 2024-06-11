// 缺省参数:带默认值的形参
#include <iostream>
using namespace std;

void foo( int a, double b=3.14, float c=3.1, short d=2, char e='A' ); //  声明 

void foo( int a ) { // 连 声明 带 定义
}

int main( void ) {
    foo( 3, 3.14, 3.1, 2 );
    
    foo( 3, 3.14, 3.1, 2, 'B' );

//  foo( 10 ); // 匹配歧义
    return 0;
}

void foo( int a, double b, float c, short d, char e ) { // 定义
    cout << "e=" << e << endl;
}


