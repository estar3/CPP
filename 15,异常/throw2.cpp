// 关于捕获异常的几点建议
#include <iostream>
using namespace std;

class A {
public:
    A() { }
    A( const A& that ) {    cout << "A类拷贝构造函数被调用" << endl;    }
    ~A() {  }

};
// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
void foo( ) {
//    A a;
    throw A(); // 编译器会优化
}
int main( void ) {
    try {
        foo( );
    }
    catch( A& e ) {
        // ...
    }
    return 0;
}








