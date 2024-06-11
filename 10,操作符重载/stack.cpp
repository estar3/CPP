// 简易栈容器
#include <iostream>
using namespace std;

class Stack {
public:
    Stack( ) : m_size(0) {
        //【int m_a[20];】
        //【int m_size=0;】
    }
    void push( int data ) {  m_a[m_size++] = data;  } // 判满操作，自己实现
    int pop( ) {  return m_a[--m_size];   }  // 判空操作，自己实现
    int size( ) {   return m_size;  }
    const int& operator[]( /* const Stack* this */ size_t index ) const { // 常函数
        return this->m_a[index];
    }
    int& operator[]( /* Stack* this */ size_t index ) { // 非常函数
        return this->m_a[index];
    }
private:
    int m_a[20]; // 保存数据
    int m_size;  // 保存数据的个数
};

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    Stack s; // 非常容器
    for( int i=0; i<20; i++ ) 
        s.push( 1000+i );
    cout << "压栈后s容器中数据的个数: " << s.size() << endl;

    s[5] = 8888; // s.operator[](5)=8888; -- 非常容器的元素 是 非常左值
    for( int i=0; i<20; i++ ) 
        cout << s[i] << ' ';
    cout << endl;
    cout << "读数据后s容器中数据的个数: " << s.size() << endl;

    const Stack cs = s; // cs是 常容器
//  cs[5] = 6666; // cs.operator[](5)=6666; -- 编译器将报告 readonly 的错误

    /*
    int s[20]; -- 非常容器
    s[5] = 8888; -- 非常容器的元素 是 非常左值

    const int cs[20] = {....}; -- 常容器
    cs[5] = 6666; -- 编译器将报告 readonly 的错误, 常容器的元素 是 常左值
    */

    /*
    for( int i=0; i<20; i++ )
        cout << s.pop() << ' ';
    cout << endl;
    cout << "读取数据后s容器中数据的个数: " << s.size() << endl;
    */
    return 0;
}
