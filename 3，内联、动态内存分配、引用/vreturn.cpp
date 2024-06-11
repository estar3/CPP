// 引用 作为 函数的返回值
#include <iostream>
using namespace std;

int g_value = 0;
int& foo( ) { // 非常引用型返回值,通过引用可以修改目标
    return g_value;
}
const int& fooo( ) { // 常引用型返回值,通过引用不可以修改目标
    return g_value;
}

int& bar( ) {
    static int s_value = 0; // 这句代码在程序启动时就执行，而且只执行一次，不是调用bar函数都执行
    cout << "s_value=" << s_value << endl;
    return s_value;
}

int& hum( ) {
    int* pn = new int;
    return *pn;
}

int& fun( int& x ) {
    return x; // 返回引用型参数本身
}
/*
int& boo( ) {
    int m=8888;
    return m; // 不能返回局部变量的别名,(c语言中应该有不要从函数中返回局部变量的指针)
}
*/
int main( void ) {
    foo( ) = 100;
    cout << "g_value=" << g_value << endl;

//  fooo( ) = 9999;

    bar( ) = 200;
    bar( );

    hum( ) = 300;

    int a_value = 0;
    fun( a_value ) = 400;
    cout << "a_value=" << a_value << endl;

//    boo( );
    return 0;
}







