// 学生类：
// （1）有姓名（char *name）、分数1（float g1）、分数2（float g2）等数据成员。
// （2）有带三个参数（char*,float,float）的构造函数，拷贝构造函数、析构函数。三者执行时要求分别输出字符串"construct"+name、"copy"+name、""destruct"+name。
// （3）有返回两个分数、对象地址的三个公有成员函数；不允许有其它成员函数。
// main函数：
// （1）定义学生对象a，信息是"li" 90.0 80.0。
// （2）定义大小为2的学生对象数组st，设置学生信息为：
// "zhang" 80.0 70.0
// "wang" 90.0 80.0
// （3）输出数组中每个学生的平均值：75 85
// （4）用a拷贝构造另一个学生对象b,拷贝时将信息修改为："liu" 80.0 70.0。注意"liu"比"li"多了个字符'u'，而80.0、70.0又比90.0、80.0都少10.0。
// （5）取b地址，并调用b的返回对象地址成员函数，输出两者的差：0
// 总结：
// 程序无键盘输入，屏幕输出为（注意次序）：
// construct li
// construct zhang
// construct wang
// 75 85
// destruct wang
// destruct zhang
// copy liu
// 0
// destruct liu
// destruct li
// 提示：
// （1）换行符为endl
// （2）对象数组初始化：A a[]={A(...),A(...)}; 或者A *a=new A[2]{A(...),A(...)};
// （3）若定义为静态数组且要提前释放，可考虑定义为局部数组。

#include <cstring>
#include <iostream>

using namespace std;

class Student {
    char* name;
    float g1;
    float g2;

   public:

    Student(const char* name, float g1, float g2);

    Student(Student const& st);

    ~Student();

    void Name() { cout << name; }

    float get_g1() { return g1; }
    float get_g2() { return g2; }

    Student* get_location() { return this; }
};

Student::Student(const char* name, float g1, float g2) {
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
    cout << "construct " << this->name << endl;
    this->g1 = g1;
    this->g2 = g2;
}

Student::Student(Student const& st) {
    char tmp[10];
    strcpy(tmp, st.name);
    strcat(tmp, "u");
    this->name = new char[strlen(tmp)];
    strcpy(this->name, tmp);
    cout << "copy " << this->name << endl;
    g1 = st.g1 - 10;
    g2 = st.g2 - 10;
}

Student::~Student() {
    cout << "destruct " << name << endl;
    delete[] name;
}

int main() {
    Student a("li", 90.0, 80.0);
    Student* st[2] = {new Student("zhang", 80.0, 70.0),
                      new Student("wang", 90.0, 80.0)};
    int Avrg1 = ((*st[0]).get_g1() + (*st[0]).get_g2()) / 2;
    int Avrg2 = ((*st[1]).get_g1() + (*st[1]).get_g2()) / 2;
    cout << Avrg1 << " " << Avrg2 << endl;
    delete st[1];
    delete st[0];
    Student b(a);
    cout << &b - b.get_location() << endl;
}