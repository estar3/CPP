// 子类的构造函数 和 析构函数
#include <iostream>
using namespace std;
class Human {
public:
    Human( int age=0, const char* name="无名" ) : m_age(age), m_name(name) {
        //【int m_age=age;】定义m_age,初值为age
        //【string m_name(name);】定义m_name,利用m_name.string(name)
        cout << "Human类的缺省构造函数被调用" << endl;
    }
    Human( const Human& that ) : m_age(that.m_age), m_name(that.m_name) { 
        //【int m_age=that.m_age;】定义m_age,初值为that.m_age
        //【string m_name(that.m_name);】定义m_name,利用m_name.string(that.m_name)
        cout << "Human类的拷贝构造函数被调用" << endl;
    }
    Human& operator=( /* Human* this */ const Human& that ) { 
        // 编译器不会在 自定的拷贝赋值函数中 塞任何操作
        cout << "Human类的拷贝赋值函数被调用" << endl;
        this->m_age = that.m_age;
        this->m_name = that.m_name;
        return *this;
    }
    ~Human( ) {
        cout << "Human类的析构函数被调用" << endl;
        // 对于基本类型的成员变量m_age,什么都不做
        // 对于类类型的成员变量m_name,利用 m_name.~string()
        // 释放 m_age/m_name 本身所占内存空间
    }    
    void getinfo( /* Human* this */ ) { 
        cout << "姓名: " << this->m_name << ", 年龄: " << this->m_age;
    }
private:
    int m_age; // 基本类型的成员变量
    string m_name; // 类类型的成员变量
};
class Student : public Human {
public:
    void getinfo( ) {
        Human::getinfo( );
        cout << ", 成绩: " << m_score << ", 评语: " << m_remark << endl;
    }
//  如果子类没有提供任何构造函数,编译器将提供一个无参构造函数
/*  Student( ) {
       【Human();】定义 基类子对象，利用 基类子对象.Human()
       【float m_score;】
       【string m_remark;】
    }*/
    Student( int age=0, const char* name="无名", float score=0.0, const char* remark="没有" ) 
                                        : Human(age,name),m_score(score), m_remark(remark) {
        //【Human(age,name);】定义 基类子对象，利用 基类子对象.Human(age,name)
        //【float m_score=score;】
        //【string m_remark(remark);】
        cout << "Student类的缺省构造函数被调用" << endl;
    }
//  如果子类没有提供析构函数，编译器将提供一个默认的析构函数
/*  ~Student( ) {
        对于m_remark,利用m_remark.~string()
        对于基类子对象,利用基类子对象.~Human()
        释放 m_score/m_remark/基本子对象 本身所占内存空间
    }*/
    ~Student( ) {
        cout << "Student类的析构函数被调用" << endl;
        // 对于m_remark,利用m_remark.~string()
        // 对于基类子对象,利用基类子对象.~Human()
        // 释放 m_score/m_remark/基本子对象 本身所占内存空间
    }
//  如果子类没有拷贝构造函数, 编译器将提供一个默认的拷贝构造函数
/*  Student( const Student& that ) {
       【Human(that);】定义基类子对象,利用 基类子对象.Human(that)-->触发Human类的拷贝构造函数
       【float m_score=that.m_score;】
       【string m_remark=that.m_remark;】
    }*/
    Student( const Student& that ) : Human(that), m_score(that.m_score), m_remark(that.m_remark) {
        //【Human(that);】定义 基类子对象,利用 基类子对象.Human(that)-->触发Human类的拷贝构造函数
        //【float m_score=that.m_score;】
        //【string m_remark=that.m_remark;】
        cout << "Student类的拷贝构造函数被调用" << endl;
    }
//  如果子类没有提供拷贝赋值函数,编译器将提供一个默认的拷贝赋值函数
/*  Student& operator=( const Student& that ) {
        Human& rh = *this;
        rh = that; // rh.operator=(that)-->触发Human类的拷贝赋值函数
        m_score = that.m_score;
        m_remark = that.m_remark;
        return *this;
    }*/
    Student& operator=( const Student& that ) {
        // 不会再拷贝赋值函数中塞任何操作
        cout << "Student类的拷贝赋值函数被调用" << endl;
        Human& rh = *this;
        rh = that; // rh.operator=(that)-->触发Human类的拷贝赋值函数
        m_score = that.m_score;
        m_remark = that.m_remark;
        return *this;
    }
private:
    float m_score;
    string m_remark;
};
// 以上的代码模拟类的设计者(例如:类库、被人设计的类、自己的设计的类)
// -------------------------------------
// 以下的代码模拟用户(使用类的人)
int main( void ) {
    cout << "---------s1创建信息----------" << endl;
    Student s1(22,"张飞",88.5,"良好");
    s1.getinfo( );
    
    cout << "---------s2创建信息----------" << endl;
    Student s2(s1); //= s1;
    s2.getinfo( );
    
    cout << "---------s3创建信息----------" << endl;
    Student s3;
    cout << "s3被赋值前 --- ";
    s3.getinfo( );
    s3 = s2; // s3.operator=( s2 )
    cout << "s3被赋值后 --- ";
    s3.getinfo( );
    cout << "---------main will be over----------" << endl;
    return 0;
} // s1.~Student()  释放s1本身所占内存空间






