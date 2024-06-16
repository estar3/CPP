// lambda表达式--捕获表
#include <iostream>
#include <typeinfo>
using namespace std;

int a = 10;
class Y {
public:
    Y():e(50) {}
    void foo( /* Y* this */ int c=30 ) {
        cout << "----------[]----------" << endl;
        [](int d=40) {
            cout << "a=" << a << endl;
            cout << "b=" << b << endl;
//          cout << "c=" << c << endl; // error
            cout << "d=" << d << endl;
//          cout << "e=" << e << endl; // error
        }();
        /*
        class X {
        public:
            void operator()(int d=40) {
                cout << "a=" << a << endl;
                cout << "b=" << b << endl;
//              cout << "c=" << c << endl; // error
                cout << "d=" << d << endl;
//              cout << "e=" << e << endl; // error
            }
        };
        X{}(); // X{}.operator()()
        */
        
        // lambda表达式将捕获外部变量c的“值”
        cout << "----------[c]----------" << endl;
        [c](int d=40) { cout << "c=" << /*++*/c << endl; }();
        /*        
        class XX {
        public:
            XX(int m):c(m) {} // 这里的c并不是foo函数的形参c,而是XX类的成员变量
            void operator()(int d=40) {
                cout << "c=" << ++c << endl; // 这里的c并不是foo函数形参c,而是XX类的一个成员变量
            }
        private:
            const int c; // 这里的c并不是foo函数形参c,而是XX类的一个成员变量
        };
        XX{c}(); // XX{c}.operator()()   这里c是foo函数的形参c 
        */

        // lambda表达式将捕获外部变量c的别名(引用)
        cout << "----------[&c]----------" << endl;
        [&c](int d=40) { cout << "c=" << ++c << endl; }();
        /*        
        class XXXX {
        public:
            XXXX(int& m):c(m) {} // 这里的c并不是foo函数的形参c,而是XXXX类的一个成员变量
            void operator()(int d=40) {
                cout << "c=" << c << endl; // 这里的c并不是foo函数的形参c,而是XXXX类的一个成员变量
            }
        private:
            int& c; // 这里的c并不是foo函数的形参c,而是XXXX类的一个成员变量
        };
        XXXX{c}(); // XXXX{c}.operator()()   这里的c是foo函数的形参c 
        */
        cout << "----------[this]----------" << endl;
        [this](int d=40) { cout << "e=" << e << endl; }();
    }
private:
    static int b;
    int e;
};
int Y::b = 20;
int main( void ) {
    Y y;
    y.foo( );
    return 0;
}
