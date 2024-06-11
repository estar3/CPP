// 名字空间声明 和 名字空间指令 二者的差别

#include <iostream>
using namespace std;

namespace ns1 {
    int g_value = 0;
    int g_other = 0;
}

namespace ns2 {
    int g_value = 0;
    int g_other = 0;
}

int main( void ) {
    using namespace ns1; // 名字空间指令,ns1中的内容在当前作用域可见,但ns1中所有内容都可见
    using ns2::g_value; // 名字空间声明,ns2中的g_value引入当前作用域,但只有g_value引入当前作用域

    g_value = 8888; 
    cout << "ns1::g_value=" << ns1::g_value << ", ns2::g_value=" << ns2::g_value << endl;

    g_other = 6666; 
    cout << "ns1::g_other=" << ns1::g_other << ", ns2::g_other=" << ns2::g_other << endl;
    return 0;
}
