
#include <iostream>
#include <fstream>
using namespace std;

// C++标准库中已经 设计的类   ifstream类

// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {

    ifstream ifs2("./file", ios::ate);
    if( !ifs2 ) { // ! ifs2.operator bool()
        cerr << "ifs2流对象状态错误--打开文件失败" << endl;
    }

    cout << "------------第一次读取数据------------" << endl;
    int ii; double dd;  string ss1,ss2;
    ifs2 >> ii >> dd >> ss1 >> ss2; // ifs2.operator>>(ii).operator>>(dd).operator>>(ss1).operator>>(ss2)
    if( !ifs2 ) { // ! ifs2.operator bool()
        cout << "ifs2流对象状态错误--读文件失败" << endl;
        cout << "ifs2是0状态吗?" << ifs2.good() << ", ifs2是1状态吗?" << ifs2.bad() << ", ifs2是2状态吗?" << ifs2.eof()
             << ", ifs2是4状态吗?" << ifs2.fail() << endl;
        cout << "ifs2具体的状态值: " << ifs2.rdstate() << endl;
    }
    cout << ii << ' ' << dd << ' ' << ss1 << ' ' << ss2 << endl;

    cout << "------------第二次读取数据------------" << endl;
    ifs2.clear( );
    ifs2.seekg(0,ios::beg);

    ifs2 >> ii >> dd >> ss1 >> ss2; // ifs2.operator>>(ii).operator>>(dd).operator>>(ss1).operator>>(ss2)
    if( !ifs2 ) { // ! ifs2.operator bool()
        cout << "ifs2流对象状态错误--读文件失败" << endl;
        cout << "ifs2是0状态吗?" << ifs2.good() << ", ifs2是1状态吗?" << ifs2.bad() << ", ifs2是2状态吗?" << ifs2.eof()
             << ", ifs2是4状态吗?" << ifs2.fail() << endl;
        cout << "ifs2具体的状态值: " << ifs2.rdstate() << endl;
    }
    cout << ii << ' ' << dd << ' ' << ss1 << ' ' << ss2 << endl;


    ifs2.close( );
    return 0;
}
