// 非格式化IO
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
    char buf[256];
    while( 1 ) {
        ifs.getline(buf,256,'\n'); 
        if( !ifs ) {
            break;
        } else {
            cout << buf << endl;
            cout << "ifs流对象状态值: " << ifs.rdstate() << endl;
        }
    }
/*
    ifs.getline(buf,256,'\n'); // aa\n
    cout << buf << endl;
    cout << "ifs流对象状态值: " << ifs.rdstate() << endl;

    ifs.getline(buf,256,'\n');
    cout << buf << endl;
    cout << "ifs流对象状态值: " << ifs.rdstate() << endl;
    
    ifs.getline(buf,256,'\n');
    cout << buf << endl;
    cout << "ifs流对象状态值: " << ifs.rdstate() << endl;
    
    ifs.getline(buf,256,'\n');
    cout << buf << endl;
    cout << "ifs流对象状态值: " << ifs.rdstate() << endl;
    
    ifs.getline(buf,256,'\n');
    cout << buf << endl;
    cout << "ifs流对象状态值: " << ifs.rdstate() << endl;
    
    ifs.getline(buf,256,'\n');
    cout << buf << endl;
    cout << "ifs流对象状态值: " << ifs.rdstate() << endl;
*/    
    ifs.close( );
    return 0;
}
