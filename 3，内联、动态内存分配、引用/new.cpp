// 动态(堆)内存分配
#include <iostream>
#include <cstdlib>
using namespace std;

int main( void ) {
    int* pm = (int*)malloc( 4 );
    cout << "*pm: " << *pm << endl;
    free( pm ); // 当这行代码执行结束,pm指向的堆内存已经被释放,pm变为野指针
    pm = NULL;
    free( pm ); // 给free传递的为野指针, 释放野指针后果未定义，释放空指针是安全的

    int* pn = new int(100);
    cout << "*pn: " << *pn << endl;
    delete pn; // 当这行代码执行结束,pn指针的堆内存已经被释放,pn变为野指针
    pn = NULL;
    delete pn; // 给delete传递的为野指针,释放野指针后果未定义, 释放空指针是安全的

    int* parr = new int[4]{ 10, 20, 30, 40 }; // 以数组方式new, 永远返回第一个元素的地址
    for( int i=0; i<4; i++ ) {
        cout << parr[i] << ' ';
    }
    cout << endl;
    delete[] parr; // 数组方式释放

    int(*p)[4] = new int[3][4]; // 以数组方式new, 永远返回第一个元素的地址
    delete[] p;

    try {
        new int[0xFFFFFFFF];
    }
    catch(...) {
    
    }
    return 0;
}
