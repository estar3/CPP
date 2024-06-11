// 内联函数：编译器的一种优化策略
#include <iostream>
using namespace std;

void foo( int x ) { // 普通函数
    cout << "foo(int): " << x << endl;
}

inline void bar( int x ) { // 内联函数
    cout << "bar(int):" << x << endl;
}

int main( void ) {

    foo( 10 ); // 将此处替换为跳转指令
    //...
    foo( 20 ); // ...
    // ...
    foo( 30 ); // ...
    // ...

    bar( 10 ); // 将此处替换为 bar函数被编译后产生的二进制代码
    //...
    bar( 20 ); // ...
    // ...
    bar( 30 ); // ...
    // ...
    return 0;
}







