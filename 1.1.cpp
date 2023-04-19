// 先使用new创建数组，数组长度由输入确定，其类型为指向int的指针。
// 然后动态创建int类型变量，并用数组每个元素（指针类型）指向，并通过键盘输入每个变量的值。
// 最后输出这些变量的和。
// 例如：
// 输入 3 7 3 -1 //第1个数为数组大小
// 输出 9
// 提示：创建动态指针数组，则需要定义指针的指针；
// 注意：谢绝使用静态数组。
#include <vector>
#include <iostream>

using namespace std;

int main() {
    unsigned int lth;
    cin >> lth;
    int* ls = new int[lth];
    for (int i = 0; i < lth; i++) {
        cin >> ls[i];
    }
    int res = 0;
    for (int i = 0; i < lth; i++) {
        res += (ls[i]);
    }
    cout << res;
    delete ls;
    return 0;
}