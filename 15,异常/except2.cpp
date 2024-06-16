// 异常说明没有  和  异常说明为空
#include <iostream>
using namespace std;

void foo( ) { // 没有异常说明:承诺函数内部可能抛出任何类型的异常
    throw "hello world"; // 3.14; // -1;
}

void bar( ) throw() { // 异常说明为空:承诺函数内部绝不会抛出任何类型的异常
    throw -1;
}

void hum( ) throw(int,double); // 声明

void hum( ) throw(int,double) { // 定义
    // ...
}
// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    try {
        foo( );
//        bar( );
    }
    catch( ... ) { // 忽略异常（捕获异常，但不处理）
        // ...
    }
    /*
    catch( int& e ) {
        cout << "1. 捕获异常信息: " << e << endl;
    }
    catch( double& e ) {
        cout << "2. 捕获异常信息: " << e << endl;
    }
    catch( const char* e ) {
        cout << "3. 捕获异常信息: " << e << endl;
    }
    */
    return 0;
}
