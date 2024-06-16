// 二进制IO
#include <iostream>
#include <fstream>
using namespace std;

// C++标准库中已经 设计的类   ofstream/ifstream  类

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    ifstream ifs( "./getline.txt", ios::in );
    if( !ifs ) {
        cerr << "ifs流对象状态错误--打开文件失败" << endl;
    }
    
    ofstream ofs( "./zjw", ios::out );
    if( !ofs ) {
        cerr << "ofs流对象状态错误--打开文件失败" << endl;
    }

    char buf[3];
    while( 1 ) {
        ifs.read(buf,3); 
        if( !ifs ) {
            // 没读满3个字节
            int len = ifs.gcount( );
            ofs.write(buf, len );
            break;
        } else {
            // 读满3个字节
            ofs.write( buf, 3 );
        }
    }
    ofs.close( );
    ifs.close( );
    return 0;
}
