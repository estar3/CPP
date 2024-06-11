// 引用：一块内存的别名
#include <iostream>
using namespace std;

int main( void ) {
    int a = 10;
    int& b = a; // 这并不是利用a的数据给b赋值,而应该理解为 引用b是a所代表的内存的别名

    b = 20; // 对 引用b赋值，其实就是在对引用b的目标内存(a)赋值
    cout << "a=" << a << ", b=" << b << endl; // 读取引用b的值，其实读取的为引用b的目标内存(a)的值
    cout << "&a: " << &a << ", &b: " << &b << endl; // 取引用b的地址，其实取的为引用b的目标内存(a)的地址

    int c = 30;
    b = c; // 不要理解为 引用b的目标内存变为c,而应该理解为 用c中的数据给引用b的目标内存(a)赋值
    cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
    cout << "&a: " << &a << ", &b: " << &b << ", &c: " << &c << endl;

    int& d = b; // 不要理解为d是b的别名,而应该理解为d和b都是a的别名
    cout << "&a: " << &a << ", &b: " << &b << ", &d: " << &d << endl; 

    const int e = 10;
//  int& f = e; // error, 别名不能比真名 限定的更加宽松
    const int& g = e; // ok,

    const int& h = a; // ok,别名可以比真名 限定的更加严格
    return 0;
}







