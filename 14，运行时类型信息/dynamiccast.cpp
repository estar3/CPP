// 动态类型转换: 基类类型指针 转换为 子类类型指针
//             : 基类类型引用 转换为 子类类型引用
#include <iostream>
using namespace std;

class A { // 编译器根据A类信息,将制作一张虚函数表  "A"...|A::foo的地址
    virtual void foo() {}
};
class B : public A { // 编译器根据B类信息,将制作一张虚函数表  "B"...|A::foo的地址
};
class C : public B { // 编译器根据C类信息,将制作一张虚函数表   "C"...|A::foo的地址
};
class D { // 编译器根据D类信息,不会制作虚函数表
};

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    B b; // |虚表指针|-->编译器根据B类信息制作的虚函数表

    A* pa = &b; // B*-->A*(子类类型指针-->基类类型指针)编译器可以隐式转换

    cout << "----------dynamic_cast----------" << endl;
    B* pb = dynamic_cast<B*>(pa); // pa-->b对象所占内存空间-->虚表指针-->编译器根据B类信息制作的虚函数表-->"B"
    cout << "A* pa--->B* pb: " << pb << endl;
    C* pc = dynamic_cast<C*>(pa); // pa-->b对象所占内存空间-->虚表指针-->编译器根据B类信息制作的虚函数表-->"B"
    cout << "A* pa--->C* pc: " << pc << endl;
    D* pd = dynamic_cast<D*>(pa); // pa-->b对象所占内存空间-->虚表指针-->编译器根据B类信息制作的虚函数表-->"B"
    cout << "A* pa--->D* pd: " << pd << endl;
    
    cout << "----------static_cast----------" << endl;
    pb = static_cast<B*>(pa); // A*-->B* 的反向 B*-->A*可以隐式
    cout << "A* pa--->B* pb: " << pb << endl;
    pc = static_cast<C*>(pa); // A*-->C* 的反向 C*-->A*可以隐式
    cout << "A* pa--->C* pc: " << pc << endl;
//  pd = static_cast<D*>(pa); // A*-->D* 的反向 D*-->A*不可以隐式
//  cout << "A* pa--->D* pd: " << pd << endl;
    return 0;
}
