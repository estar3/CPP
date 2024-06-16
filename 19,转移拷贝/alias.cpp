// 左值引用/右值引用 和 左值/右值 的关系
#include <iostream>
using namespace std;

int foo( ) {
    int m=100;
    return m;
}
int main( void ) {
// 当前作用域的生命期
// 具名内存-->能够取址-->左值|非常左值(无const修饰)
//                           |常左值  (有const修饰)
    int a = 10;
    int& ra = a; // ok
    const int& cra = a; // ok

    const int b = 10;
//  int& rb = b; // error
    const int& crb = b; // ok

// 语句级的生命期(引用可以延长右值的生命期)
// 匿名内存-->不能取址-->右值|直接更改右值毫无意义(98/03标准给出结论)
//                           |11标准认为 给了真名就可以改
    const int& ri = 10; // ok
    int&& rri = 10;

    const int& rf = /*|100|*/foo( ); // (1)分配一块内存空间  (2)生成跳转指令
    int&& rrf = /*100*/foo();
    return 0;
}
