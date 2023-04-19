// 编写程序输出30以内所有素数（输出时各数之间用空格隔开）。

#include <iostream>

#include <cmath>

using namespace std;

int main() {
    for (int i = 2; i < 30; i++) {
        bool is_prime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0)
                is_prime = false;
        }
        if (is_prime)
            cout << i << " ";
    }
    return 0;
}
