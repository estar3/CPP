// 非格式化IO
#include <iostream>
#include <fstream>
using namespace std;

// C++标准库中已经 设计的类   ofstream/ifstream  类

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    ofstream ofs("./noformat.txt", ios::out);
    if( !ofs ) {
        cerr << "ofs流对象状态错误--打开文件失败" << endl;
    }
    for( char c=' '; c<='~'; c++ ) {
        ofs.put(c).flush();
    }
    ofs.close();

    ifstream ifs( "./noformat.txt", ios::in );
    if( !ifs ) {
        cerr << "ifs流对象状态错误--打开文件失败" << endl;
    }
    char c;
    // 单参的get
    while( 1 ) {
        ifs.get( c );
        if( !ifs ) {
            break;
        } else {
            cout << c;
        }
    }
    cout << endl;

    cout << "单参get读取数据后，ifs流对象的状态值: " << ifs.rdstate( ) << endl;

    ifs.clear( );
    ifs.seekg(0,ios::beg);

    // 无参的get
    while( 1 ) {
        c = ifs.get();
        if( c==EOF ) {
            break;
        } else {
            cout << c;
        }
    }
    cout << endl;


    ifs.close( );
    return 0;
}
