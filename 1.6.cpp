// 编写函数，实现下面功能：读入两个字符串，比较其是否相等，如果不相等，输出较大的那个。

// 例如：“word”与“world”，第4个字母不同，"l"的ASCII码比"d"大，则输出world

// 输入：word
//      world

// 输出：world

#include <iostream>

using namespace std;

const char* compare(char* s1, char* s2) {
    for (int i = 0; s1[i] != '\0' && s2[i] != '0'; i++) {
        if (s1[i] < s2[i])
            return s2;
        else if (s1[i] > s2[i])
            return s1;
    }
    cout << "相等";
    return s1;
}

int main() {
    char* s1 = new char(10);
    char* s2 = new char(10);
    cin >> s1;
    cin >> s2;
    cout << compare(s1, s2);
    return 0;
}