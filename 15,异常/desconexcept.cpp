// 不要在析构函数中 "主动" 抛出异常
#include <iostream>
#include <cstdio>
using namespace std;

void foo( ) {
    throw "foo函数中抛出的异常";
}
void bar( ) {
    throw "bar函数中抛出的异常";
}

class A {
public:
    ~A() {  
        // throw "析构函数中抛出的异常";
        try {
            bar( );
        }
        catch( const char* e ) {
            cout << "析构函数中捕获异常信息: " << e << endl;
        }
    }
    
};
// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    try {
        A a;   
        foo( );
        // ...其他后续的代码...

    } // a.~A()  释放a本身所占内存空间

    catch( const char* e ) {
        cout << "main中捕获异常信息: " << e << endl;
    }
    return 0;
}
