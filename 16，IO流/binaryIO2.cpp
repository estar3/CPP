// 二进制IO
#include <iostream>
#include <fstream>
using namespace std;

// C++标准库中已经 设计的类   ofstream/ifstream  类

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    ifstream ifs( "./getline.txt", ios::ate );
    if( !ifs ) {
        cerr << "ifs流对象状态错误--打开文件失败" << endl;
    }
    
    ofstream ofs( "./zjw.txt", ios::out );
    if( !ofs ) {
        cerr << "ofs流对象状态错误--打开文件失败" << endl;
    }

    int size = ifs.tellg( );
    char buf[size];
    ifs.seekg(0,ios::beg);
    ifs.read(buf,size);

    ofs.write(buf,size);
    

    ofs.close( );
    ifs.close( );
    return 0;
}
