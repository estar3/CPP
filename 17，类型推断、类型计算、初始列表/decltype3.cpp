// 返回值类型后置
#include <iostream>
#include <typeinfo>
using namespace std;

auto foo( int x, double y )->decltype(x+y) {
    return x+y;
}

int main( void ) {
    auto f = foo( 10, 3.14 );
    //  f: double
    cout << "f的类型: " << typeid(f).name() << endl; // d
    return 0;
}
