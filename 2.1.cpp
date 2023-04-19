// 编写一个程序，输入N个学生数据，包括学号、姓名、成绩，要求输出这些学生数据并计算平均分。
// 输入第一行为学生个数，接下来输入N个学生的数据。输出时，先输出N个学生，再输出平均分数（保留小数点后两位）。

// 样例输入:

// 3

// test1 101 90

// test2 102 87

// tets3 103 83

// 样例输出：

// test1 101 90

// test2 102 87

// tets3 103 83

// 86.67

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Student {
   public:
    string name;
    int number;
    int grade;
};

int main() {
    int num;
    cin >> num;
    Student st[num];
    float sum = 0;
    for (int i = 0; i < num; i++) {
        cin >> st[i].name >> st[i].number >> st[i].grade;
        sum += st[i].grade;
    }
    for (int i = 0; i < num; i++) {
        cout << st[i].name << " ";
        cout << st[i].number << " ";
        cout << st[i].grade << endl;
    }
    sum /= num;
    cout << setiosflags(ios::fixed) << setprecision(2) << sum;
    return 0;
}