// 对子类类型异常的捕获 放在 对基类类型异常捕获的 前面 
#include <iostream>
using namespace std;

class A { };
class B : public A {};

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
void foo( ) {
    throw B(); // 抛出的为 子类(B类)对象
}
int main( void ) {
    try {
        foo( );
    }
    catch( B& e ) { 
        cout << "B类型引用的catch捕获" << endl;
    }
    catch( A& e ) { 
        cout << "A类型引用的catch捕获" << endl;
    }
    return 0;
}
