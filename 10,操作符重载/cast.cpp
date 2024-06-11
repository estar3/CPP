// 类型转换操作符函数  和 类型转换构造函数
#include <iostream>
using namespace std;

class Integer {
public:
    Integer( int i ) : m_i(i) {
        //【int m_i=i;】
        cout << "Integer类的类型转换构造函数被调用" << endl;
    }
    operator int( /* const Integer* this */ ) const {
        cout << "Integer类的类型转换操作符函数被调用" << endl;
        return this->m_i;
    }
private:
    int m_i;
};

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    int n = 666;
    
    // int --> Intger (基本类型-->类类型)
    Integer ix = n; // 定义 匿名Integer类对象,利用 匿名Integer类对象.Integer(n)-->类型转换构造函数
                    // Integer ix = n.operator Integer() -->int类中肯定没有一个成员函数operator Integer() (走不通)

    // Integer --> int (类类型-->基本类型)
    int m = ix; // 定义 匿名int类对象, 利用 匿名int类对象.int(ix)-->int类中肯定没有一个形参为Integer的构造函数(走不通)
                // int m = ix.operator int() --> 类型转换操作符函数
    return 0;
}
