// 初始化大一统写法 -- 列表初始化
#include <iostream>
using namespace std;

struct BD {
    int m_year;
    int m_month;
    int m_day;
};
struct Student {
    int m_age;
    string m_name;
    BD m_bday;
};

class Human {
public:
    Human( int age=0, const char* name="无名" ) : m_name{name},m_age{age} {
        //【int m_age{age};】
        //【string m_name{age};】
    }
    int m_age;
    string m_name;
};

int main( void ) {
    int a{123}; // = 123;
    cout << "a=" << a << endl;

    int b[]{123,456,789}; // = {123,456,789};
    for( int i=0; i<3; i++ ) {
        cout << b[i] << ' ';
    }
    cout << endl;

    Student s{22,"张飞",{1997,5,2}}; // = {22,"张飞",{1997,5,2}};
    cout << s.m_name << ' ' << s.m_age << ' ' << s.m_bday.m_year << '-' << s.m_bday.m_month << '-' << s.m_bday.m_day << endl;

    Human h{20,"赵云"}; // 定义h,利用h.Human(...) //(20,"赵云");
    cout << "姓名: " << h.m_name << ", 年龄: " << h.m_age << endl;

    Human* ph{ new Human{25,"关羽"} }; // = new Human{25,"关羽"};//(25,"关羽");
    cout << "姓名: " << (*ph).m_name << ", 年龄: " << (*ph).m_age << endl;
    delete ph;
    ph = NULL;

    Human{32,"刘备"};//(32,"刘备"); // 定义匿名Human类对象,利用匿名Human类对象.Human(...)
    return 0;
}
