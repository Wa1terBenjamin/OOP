// 输入一个整型数组，其中有若干个0，其余为非0整数。使用指针编写程序，把0移至数组后面，非0整数移至数组前面并保持有序。输入-1表示结束。

// 例如：

// 输入：0 2 0 0 4 9 5 0 -1

// 输出：2 4 9 5 0 0 0 0

#include <iostream>
using namespace std;
int main() {
    int a[20]{0};
    int buffer = 0;
    int len = 0;
    while (1) {
        cin >> buffer;
        if (buffer == -1)
            break;
        a[len] = buffer;
        len++;
    }
    int b[len]{};
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != 0) {
            b[j] = a[i];
            j++;
        }
    }
    for (int i = j; i < len; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        cout << b[i] << ' ';
    }
    return 0;
}