// 建立一个对象数组，存放N个学生的信息（学号，姓名，
// 成绩），编写一个函数max，用指向对象的指针作函数参数，在max函数中找出N个学生的最高成绩者，并输出其信息（学号，姓名，
// 成绩）。 样例输入：
// 3
// 1 demo_1 77
// 2 demo_2 87
// 3 demo_3 90
// 样例输出：
// 3 demo_3 90
#include <iostream>
#include <string>

using namespace std;

class Student {
    int number;
    string name;
    int grade;

   public:
    Student(int number, string name, int grade) {
        this->name = name, this->number = number, this->grade = grade;
    }
    int Grade() { return grade; }
    void Print() { cout << number << " " << name << " " << grade; }
};

Student* max(Student** sts, int num) {
    Student* tmp = new Student(0, "", 0);
    for (int i = 0; i < num; i++) {
        if (tmp->Grade() < sts[i]->Grade())
            tmp = sts[i];
    }
    return tmp;
}

int main() {
    int num;
    cin >> num;
    Student* sts[num];
    for (int i = 0; i < num; i++) {
        int number, grade;
        string name;
        cin >> number >> name >> grade;
        sts[i] = new Student(number, name, grade);
    }
    auto res = max(sts, num);
    res->Print();
    return 0;
}