// 左值引用/右值引用 的差别
#include <iostream>
using namespace std;

int main( void ) {
    // 左值引用 只能引用 左值，不能引用 右值
    int a, c;
    int& b = a;     // ok
//  int& d = a + c; // error

    // 右值引用 只能引用 右值，不能引用 左值
    int&& e = a + c; // ok
    e = 8888; // ok,通过右值引用 引用右值时，不会丧失修改目标内存的权限

//  int&& f = a;     // error

    // 常左值引用 既可以引用左值，也可以引用 右值
    const int& g = a + c; // ok
//  g = 8888; // error,但是当常左值引用 引用右值时，通过常左值引用 将丧失修改目标内存的权限

    const int& h = a;     // ok
    return 0;
}
