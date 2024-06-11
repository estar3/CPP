// 
#include <iostream>
using namespace std;
#pragma pack(1)
class Human {
public:
private:
    int m_age;
    string m_name;
};

class Student : public Human {
public:
private:
    int m_no;
};

// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {    
    Human h; // |m_age m_name|
    cout << "基类对象h的大小: " << sizeof(h) << endl; // 36

    Student s; // |基类子对象|m_no| --> |m_age m_name|m_no|
    cout << "子类对象s的大小: " << sizeof(s) << endl; // 40

    Human* ph = &s; // Student*-->Human*
    Human& rh = s;
    // 以上两行代码，编译器认为访问范围缩小，是安全的(向上造型)

//  Student* ps = static_cast<Student*>(&h); // Human*-->Student*
//  Student& rs = static_cast<Student&>(h); 
    // 以上两行代码，编译器认为访问范围扩大，是有风险的
    // 通过强转虽然可以成功，但是风险依然存在,极其不建议大家这么做

    Student* ps = static_cast<Student*>(ph); // Human*-->Student*
    Student& rs = static_cast<Student&>(rh); 
    // 以上两行代码，没有风险的，极其建议大家这么做

    // 编译器 简单粗暴的根据 类型 来判断是否存在风险
    return 0;
}






