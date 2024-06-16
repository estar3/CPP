// 非虚的世界 -- 没有虚函数的程序
#include <iostream>
using namespace std;
class Shape {
public:
    void Draw( ) {  cout << "Shape::Draw" << endl;  }
    int m_x;
    int m_y;
};
class Rect : public Shape {
public:
    void Draw( ) {  cout << "Rect::Draw" << endl;   }
    int m_rx;
    int m_ry;
};
class Circle : public Shape {
public:
    void Draw( ) {  cout << "Circle::Draw" << endl; }
    void foo( ) {}
    int m_radius;
};
// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    cout << "----------利用 对象 调用 非虚的成员函数----------" << endl;
    // 哪个类对象 优先调用 哪个类的 普通成员函数(对象的自恰性)
    Shape s;
    s.Draw( ); // Shape::Draw
    Rect r;
    r.Draw( ); // Rect::Draw
    Circle c;
    c.Draw( ); // Circle::Draw

    cout << "----------利用 指针 调用 非虚的成员函数----------" << endl;
    // 利用 基类类型的指针 只能调用 基类的普通成员函数
    Shape* ps = &s;
    ps->Draw( ); // Shape::Draw

    // 即便 基类类型指针 指向的是 子类对象，调用的也为 基类的普通成员函数
    ps = &r;
    ps->Draw( ); // Shape::Draw
    ps = &c;
    ps->Draw( ); // Shape::Draw
    // 一旦调用了 子类所特有的成员函数 将报告编译器错误
//  ps->foo( ); // error

    // 编译器 简单而粗暴的根据 指针本身的类型 来确定 到底调用那个类的普通成员函数
    return 0;
}
