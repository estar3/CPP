// 常对象 和 常函数
#include <iostream>
using namespace std;

class Integer {
public:
    void setinfo( /* Integer* this */ int i ) { // 非常函数
        m_i = i; 
    }
    void getinfo( /* Integer* this */ ) { // 非常函数
        cout << "非常函数getinfo: " << m_i << endl; 
    }
    void getinfo( /* const Integer* this */ ) const { // 常函数
        const_cast<Integer*>(this)->m_i = 8888;
        cout << "常函数getinfo: " << m_i << endl;

    }
private:
    /*mutable*/ int m_i; 
};

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Integer ix; // ix是 非常对象(不挑食)
    ix.setinfo( 1000 );
    ix.getinfo( ); // getinfo( &ix )-->实参类型为 Integer*，非常对象优先选择非常函数，也可以选择常函数

    const Integer cix = ix; // cix是 常对象(很挑食)
    cix.getinfo( ); // getinfo( &cix )-->实参类型为const Integer*, 常对象只能选择常函数，不会选择非常函数
    return 0;
}
