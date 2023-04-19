// 按递增的顺序实现10个整数的冒泡排序。

// 例如：

// 输入：2 94 5 68 523 44 86 100 123 999

// 输出：2 5 44 68 86 94 100 123 523 999

#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size() - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

int main(int argc, char* argv[]) {
    int x = 0;
    vector<int> a{};
    while (cin >> x) {
        a.push_back(x);
    }
    BubbleSort(a);
    for (auto i : a)
        cout << i << " ";
    return 0;
}