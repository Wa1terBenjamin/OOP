// 设计一个类Sample，它有两个private成员：name和数组A。设计一个友元类Process对类Sample的对象的数组A进行排序，并输出排序结果。

// 要求手动输入数组A的每个元素（数组长度为5）。
// 输入样例：
// 1 2 5 4 3
// 输出样例：
// 1 2 3 4 5
#include <iostream>
#include <string>

using namespace std;

class Process;

class Sample {
   private:
    string name;
    int A[5];

   public:
    Sample(int a[5]) {
        for (int i = 0; i < 5; i++)
            A[i] = a[i];
    }
    void Show() {
        for (int i = 0; i < 5; i++)
            cout << A[i] << ' ';
        cout << endl;
    }
    friend class Process;
};

class Process {
   public:
    void Sort(Sample& s, int size = 5) {
        for (int i = size - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (s.A[j] > s.A[j + 1]) {
                    int tmp = s.A[j];
                    s.A[j] = s.A[j + 1];
                    s.A[j + 1] = tmp;
                }
            }
        }
    }
};

int main() {
    int a[5]{};
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    Sample s(a);
    Process p;
    p.Sort(s);
    s.Show();
}