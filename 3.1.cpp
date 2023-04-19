// 定义学生类：
// （1）有平时（int）、期末成绩（int）、组成比例（float）三个私有数据成员；
// （2）有成员函数setProp，根据键盘输入，设置组成比例，取值在0到1之间，比如0.4，则表示成绩=平时*40%+期末*60%；
// （3）有计算并输出成绩函数compScore，根据组成比例计算并输出成绩。
// 定义教师类：
// （1）有私有数据成员stu，是学生对象指针；
// （2）有构造函数，带整型参数，以其值为大小创建学生对象数组，用stu指向；
// （3）有成员函数assign，参数为数组下标，可直接对一个学生对象设置平时、期末成绩。
// （4）有成员函数show，参数为数组下标，用于调用一个学生对象的compScore函数。
// main函数中：
// （1）在不定义学生对象的情况下，调用学生类的setProp函数，键盘输入并设置组成比例；
// （2）输入学生数，由此定义教师对象。
// （3）调用assign，为数组中每个学生对象给平时、期末成绩，两个成绩由键盘输入；
// （4）调用compScore，逐个计算并输出每个学生的成绩，以空格隔开。
// 举例1：
// 输入：0.4 3 70 90 60 80 55 88
// 输出：82 72 74.8
// 举例2：
// 输入：0.5 4 70 90 60 80 55 88 66 77
// 输出：80 70 71.5 71.5

#include <iostream>

using namespace std;

class Student;
class Teacher {
   private:
    Student* stu;

   public:
    Teacher(int num);

    void assign(int s_n);
    void show(int s_n);
};
class Student {
    friend void Teacher::assign(int s_n);

    static float prop;

   private:
    int ug, fg;

   public:
    Student() {}
    static bool SetProp(float p) {
        if (p < 0 || p > 1)
            return false;
        else {
            prop = p;
            return true;
        }
    }

    float compScore();
};

float Student::prop = 0.5;

float Student::compScore() {
    return ug * prop + fg * (1 - prop);
}

Teacher::Teacher(int num) {
    stu = new Student[num];
}

void Teacher::assign(int s_n) {
    int ug, fg;
    //cout << "请输入学生的平时成绩和期末成绩：";
    cin >> ug >> fg;
    stu[s_n].ug = ug;
    stu[s_n].fg = fg;
}

void Teacher::show(int s_n) {
    cout << stu[s_n].compScore() << " ";
}

int main() {
    float p;
    //cout << "请输入比例：";
    cin >> p;
    bool flag = Student::SetProp(p);
    while (!flag) {
        cerr << "输入的比例不合要求！请重新输入：" << endl;
        cin >> p;
        flag = Student::SetProp(p);
    }
    int num;
    //cout << "请输入学生人数：";
    cin >> num;
    Teacher t(num);
    for (int i = 0; i < num; i++) {
        t.assign(i);
    }
    //cout << "学生成绩：";
    for (int i = 0; i < num; i++) {
        t.show(i);
    }
    return 0;
}