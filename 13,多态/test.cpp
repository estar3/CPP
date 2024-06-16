// 一个需要多态的场景
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdio>
using namespace std;
// 设计一个 “通用” 的线程类
class Thread {
public:
    void start( /* Thread* this */ ) {
        pthread_create( &m_tid, NULL, threadfunc, this );
    }
    static void* threadfunc( void* arg ) {
        // 创建线程要执行的操作，不应该由类的设计者提供
        // 创建线程要执行的操作，应该由用户提供
        // 作为类的设计者应该调用用户提供的操作
        Thread* p = (Thread*)arg;
        p->run( );
    }
    virtual void run( ) = 0;
private:
    pthread_t m_tid;
};
// 以上代码模拟类的设计者
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
class MyThread : public Thread {
public:
    MyThread( int sec, char ch ) : m_sec(sec),m_ch(ch) {}
    void run( ) {
        for( ;; ) {
            usleep(1000*m_sec);
            cout << m_ch << flush;
        }
    }
private:
    char m_ch;
    int m_sec;
};
int main( void ) {
    MyThread t1(500,'+'), t2(1000,'*');
    t1.start( );
    t2.start( );
    getchar( );
    return 0;
}








