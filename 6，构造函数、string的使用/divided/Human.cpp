
#include "Human.h"
#include <cstring>
#include <iostream>
using namespace std;

Human::Human( int age, const char* name ) {
    // 定义 m_age 和 m_name
    m_age = age;
    strcpy( m_name, name );
}
    
void Human::getinfo( ) {
    cout << "姓名: " << m_name << ", 年龄: " << m_age << endl;
}
