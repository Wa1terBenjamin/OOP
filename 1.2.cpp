// 定义一个函数，参数为三个int类型变量的引用。在函数中交换三个参数的值，使其按升序排序。然后在主函数中输入三个整型数，调用该函数，按升序输出这三个数。

// 例如：
// 输入： 3 4 -1
// 输出： -1 3 4

#include <iostream>

using namespace std;

void swap(int& a, int& b, int& c) {
    int tmp;
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (b > c) {
        tmp = b;
        b = c;
        c = tmp;
    }
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    swap(a, b, c);
    cout << a << ' ' << b << ' ' << c;
    return 0;
}