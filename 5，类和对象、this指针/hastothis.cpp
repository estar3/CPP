// 必须自己明显写 this的情况
#include <iostream>
using namespace std;

class Integer; // 短式声明

void Print( Integer* v ) {
    // ...
}

class Integer {
public:
    void setinfo( /* Integer* this */ int i ) {
        this->i = i; // (1) 必须明显写this的情况
    }
    void getinfo( /* Integer* this */ ) {
        cout << /*this->*/i << endl; // 这里编译器自动补充this
        Print( this ); // (3)必须明显写this的情况
    }
    Integer& increment( /* Integer* this */ ) {
        ++/*this->*/i; // 这里编译器自动补充this
        return *this; // 返回基于this指针的自引用 (2)必须明显写this的情况
    }
private:
    int i; // m_xxx 
};

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Integer ix;
    ix.setinfo( 1000 );
    ix.getinfo( );

    ix.increment( ).increment( ).increment( ); // 串联调用
    ix.getinfo( );
    return 0;
}
