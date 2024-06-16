// 异常说明: 给 调用者 承诺，函数内部绝对不会抛出 异常说明以外的 异常类型
#include <iostream>
using namespace std;

void foo( ) throw(int,double, const char*) { // 显示抛出异常
    throw "hello world"; // 3.14; // -1;
}

void bar( ) throw(int,double,const char*) { // 隐式抛出异常
    foo( );
    // 调用几十个不同函数，而且每个函数都可能抛出异常，并且抛出的异常类型都不同
}

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    try {
//        foo( );
        bar( );
    }
    catch( int& e ) {
        cout << "1. 捕获异常信息: " << e << endl;
    }
    catch( double& e ) {
        cout << "2. 捕获异常信息: " << e << endl;
    }
    catch( const char* e ) {
        cout << "3. 捕获异常信息: " << e << endl;
    }
    return 0;
}
