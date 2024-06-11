// 体会 名字空间 可以划分更精细的逻辑空间(单元),能够有效避免名字冲突的问题

#include <iostream>

namespace ICBC {
    int g_money = 0;
    void save( int money ) {
        g_money += money;
    }
}
namespace CCB {
    int g_money = 0;
    void save( int money ) { // 连 声明 带 定义
        g_money += money;
    }
    void pay( int money ); // 声明
}

void CCB::pay( int money ) { // 定义(一定要保证和声明契合)
    g_money -= money;
}

namespace ICBC { // 编译器 将 合并为一个名字空间
    void pay( int money ) {
        g_money -= money;
    }
}
int main( void ) {
    ICBC::save( 10000 );
    ICBC::pay( 3000 );
    std::cout << "工行卡余额: " << ICBC::g_money << std::endl;

    CCB::save( 8000 );
    CCB::pay( 3000 );
    std::cout << "建行卡余额: " << CCB::g_money << std::endl;
    return 0;
}
