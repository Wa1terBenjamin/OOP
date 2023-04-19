// 编写函数实现3X3矩阵的转置

// 提示：矩阵可存放到二维数组中，用指针完成数的交换(swap)操作

// 输入

// 1 2 3
// 4 5 6
// 7 8 9

// 输出

// 1 4 7
// 2 5 8
// 3 6 9

#include <iostream>

using namespace std;

void TransposeMatrix(int**& m) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) {
            int tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }
}

int main() {
    int** m = new int*[3];
    for (int i = 0; i < 3; i++) {
        int* tmp = new int[3];
        for (int j = 0; j < 3; j++) {
            cin >> tmp[j];
        }
        m[i] = tmp;
    }
    TransposeMatrix(m);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
