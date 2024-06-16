// lambda表达式
#include <iostream>
#include <typeinfo>
using namespace std;

int Max( int x, int y ) {
    return x > y ? x : y;
}

int main( void ) {
    int a=10, b=20;
    cout << Max(a,b) << endl;

    auto f = [](int x, int y)->int { return x > y ? x : y; };
    // 编译器根据lambda表达式  (1)生成一个类 (2)类内定义小括号操作符函数 (3)返回这个类匿名对象
    /*  
    class Z4mainEUliiE_ {
    public:
        int operator()(int x, int y) { // 小括号(函数)操作符函数
            return x > y ? x : y;
        }
    };
    auto f = Z4mainEUliiE_{};
    */
    cout << f(a,b) << endl; // cout << f.operator()(a,b) << endl;
    cout << "f的类型: " << typeid(f).name() << endl;

    // lambda表达式可以没有返回值类型，根据return推断
    cout << [](int x, int y) { return x + y; }(a,b) << endl;
    /*    
    class X {
    public:
        auto operator()(int x, int y)->decltype(x+y) {
            return x + y;
        }
    };
    cout << X{}(a,b) << endl; // cout << X{}.operator()(a,b) << endl;
    */

    // lambda表达式没有返回值类型，也没有return，则返回值类型直接为void
    [](int x, int y) { cout << x << ' ' << y << endl; }(a,b);
    /*
    class XX {
    public:
        void operator()(int x, int y) {
            cout << x << ' ' << y << endl; 
        }
    };
    XX{}(a,b); // XX{}.operator()(a,b)
    */

    // lambda表达式如果没有形参也可以不写
    []{ cout << "hello world" <<endl; }();
    /*
    class XXXX {
    public:
        void operator()(void) {
            cout << "hello world" <<endl;
        }
    };
    XXXX{}(); // XXXX{}.operator()()
    */
    return 0;
}
