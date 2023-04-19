/*
1、定义String类，用于实现字符串，其中有：
数据成员array，类型为char* 。
构造函数String(const char* p)、析构函数~String()。
根据以下main函数及运行结果，实现必要的运算符重载，使得输出符合指定结果。其中string1[index]，要求index的值在0到字符串不算结束符的长度减一），否则显示“Index
out of
range.”。而string3+3表示将字符串不算结束符的长度与3相加，且要求不能再重载+运算符。
2、主函数定义如下（不能修改）：
int main() {
    String string1("mystring"), string2("yourstring"), string3("herstring");
    cout << string1 << endl;
    string1[7] = 'n';
    cout << string1 << endl;
    string1[8] = 'n';
    cout << string1 + string2 + string3 << endl;
    cout << string1 << endl;
    cout << string2 + "ab" << endl;
    cout << string2 << endl;
    cout << string3 + 3 << endl;
    cout << string3 << endl;
    return 0;
}
3、无输入，输出信息为：
mystring
mystrinn
Index out of range.
mystrinnyourstringherstring
mystrinnyourstringherstring
yourstringab
yourstring
12
herstring
*/
#include <cstring>
#include <iostream>
using namespace std;

class String {
   private:
    char* array;

   public:
    String(const char* p = "") {
        array = new char[strlen(p) + 1];
        strcpy(array, p);
    }
    ~String() { delete[] array; }
    friend ostream& operator<<(ostream& os, const String& str) {
        os << str.array;
        return os;
    }
    char& operator[](int index) {
        if (index < 0 || index >= strlen(array)) {
            cout << "Index out of range." << endl;
            static char null_char = '\0';
            return null_char;
        }
        return array[index];
    }
    String operator+(const String& str) {
        strcat(array, str.array);
        return *this;
    }
    char* operator+(const char* str) {
        char* tmp = new char[strlen(array)];
        strcpy(tmp, array);
        strcat(tmp, str);
        return tmp;
    }
    int operator+(int num) { return strlen(array) + num; }
};

int main() {
    String string1("mystring"), string2("yourstring"), string3("herstring");
    cout << string1 << endl;
    string1[7] = 'n';
    cout << string1 << endl;
    string1[8] = 'n';
    cout << string1 + string2 + string3 << endl;
    cout << string1 << endl;
    cout << string2 + "ab" << endl;
    cout << string2 << endl;
    cout << string3 + 3 << endl;
    cout << string3 << endl;
    return 0;
}