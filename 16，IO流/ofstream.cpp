
#include <iostream>
#include <fstream>
using namespace std;

// C++标准库中已经 设计的类   ofstream类

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    ofstream ofs1("./file", ios::out);
    if( !ofs1 ) { // ! ofs1.operator bool()
        cerr << "ofs1流对象状态错误--打开文件失败" << endl;
    }
    ofs1 << 1234 << ' ' << 56.78 << ' ' << "hello" << '\n';
    if( !ofs1 ) { // ! ofs1.operator bool()
        cerr << "ofs1流对象状态错误--写文件失败" << endl;
    }
    ofs1.close( );

    ofstream ofs2("./file", ios::app );
    if( !ofs2 ) { // ! ofs2.operator bool()
        cerr << "ofs2流对象状态错误--打开文件失败" << endl;
    }
    ofs2 << "world" << endl;
    if( !ofs2 ) {
        cerr << "ofs2流对象状态错误--写文件失败" << endl;
    }
    ofs2.close( );
    return 0;
}
