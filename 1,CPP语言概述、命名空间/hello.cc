// 体会 C++程序 和 C程序的差别(C++完全兼容C)

#include <stdio.h>

#include <iostream>

int main( void ) {
    printf( "hello world\n" );

    std::cout << "hello world" << std::endl;
    return 0;
}
