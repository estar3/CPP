// typeid操作符 - 获取 对象的类型信息
// typeid操作符 无法获取 对象本身的常属性信息
#include <iostream>
#include <typeinfo>
using namespace std;

class A { // 编译器根据A类信息,将制作一张虚函数表  "A"...|A::foo的地址
//    virtual void foo() {}
};
class B : public A { // 编译器根据B类信息,将制作一张虚函数表  "B"...|A::foo的地址
};

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {

    B b; // |虚表指针|-->编译器根据B类信息制作的虚函数表
    A* pa = &b;
    A& ra = b;

    cout << "pa指针的目标对象的类型: " << typeid(*pa).name() << endl; 
                        // pa->b对象所占内存空间->虚表指针->编译器根据B类信息制作的虚函数表->"B"
    cout << "ra引用的目标对象的类型: " << typeid(ra).name() << endl;
                        // ra->b对象所占内存空间->虚表指针->编译器根据B类信息制作的虚函数表->"B"

    int m;
    const type_info& rty = typeid(m);
    // 1. 获取m的类型信息
    // 2. 创建一个 type_info类 的对象
    // 3. 将 获取的m的类型信息 保存到 type_info类对象的 各个 "私有"成员变量中
    // 4. 返回这个 type_info类对象的 "常"引用
    string rn = rty.name();
    cout << "m的类型: " << rn << endl; // i

    const int n = m;
    cout << "n的类型: " << typeid(n).name() << endl; // i

    cout << (typeid(m) == typeid(n)) << endl;
    cout << (typeid(m) != typeid(n)) << endl;
    return 0;
}
