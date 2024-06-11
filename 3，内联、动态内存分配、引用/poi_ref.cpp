// 引用 和 指针 的差别
#include <iostream>
using namespace std;

int main( void ) {
    int a=10, b=20;

    int* pa = &a; // 指针可以不做初始化,也可以做初始化
    pa = &b; // 指针在初始化后，可以随意变更其所指向的内存空间

    int& ra = a; // 引用必须初始化
    ra = b; // 引用在初始化后，不可以变更其所指向的内存空间

    pa = NULL; // 存在空指针
//  ra = NULL; // 不存在空引用

    int** ppa = &pa; // 存在二级指针
//  int&& rra = ra; // 不存在二级引用

    int*& rpa = pa; // 存在 指针的引用
//  int&* pra = &ra; // 不存在 引用的指针
    int* pra = &ra; // ok,但这并不是引用的指针

    int x, y, z;
    int* p[3] = {&x, &y, &z}; // 存在指针数组
//  int& r[3] = {x, y, z};  // 不存在引用数组
    
    int arr[3];
    int(&rarr)[3] = arr; // 存在数组引用
    return 0;
}







