// 小括号操作符函数
#include <iostream>
using namespace std;

class Compare {
public:
    int operator()(int x, int y) {
        return x > y ? x : y;
    }
    int operator()(int x, int y, int) {
        return x + y;
    }
    void operator()(void) {
        cout << "无聊" << endl;
    }
};

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Compare c;
    int a=10, b=20;

    cout << c(a,b) << endl; // c.operator()(a,b)

    cout << c(a,b,1) << endl; // c.operator()(a,b,1)

    c(); // c.operator()()
    return 0;
}






