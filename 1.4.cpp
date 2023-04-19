// 输入任意个（含1个）字符串，并将它们拼接在一起，并输出拼接后字符串。
// 说明及要求：
// 1、输入任意个字符串，字符串间用空格分隔，每个字符串最长为20（含空字符），比如输入：abx
// er f，则输出结果为abxerf。
// 2、不能使用string类或类似的类，但可以使用cstring头文件声明的库函数，如strlen、memset、strcat等。
// 3、提示：要输入字符串，可以定义长度为20的字符数组s，然后cin>>s。若输入空串，则表达式cin>>s结果为0。拼接后字符串的存放要使用动态数组，因为其长度动态变化。此外要防止内存泄漏、野指针使用。

#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char s[21];  // 定义长度为20的字符数组s
    char* res = nullptr;  // 存放拼接后字符串的动态数组，初始化为空指针
    int len_res = 0;  // 存放已拼接字符串的长度，初始化为0

    while (cin >> s) {          // 输入任意个字符串，直到输入结束
        int len_s = strlen(s);  // 获取输入字符串的长度
        char* tmp = new char[len_res + len_s + 1];
        // 临时数组，长度为已拼接字符串长度加上当前字符串长度再加1（为了存放末尾的'\0'）
        memset(tmp, 0, len_res + len_s + 1);  // 临时数组清零

        if (len_res > 0) {              // 如果已拼接字符串不为空
            memcpy(tmp, res, len_res);  // 将已拼接字符串拷贝到临时数组中
        }

        memcpy(tmp + len_res, s, len_s);  // 将新输入字符串拼接到临时数组中

        delete[] res;      // 释放原有的动态数组空q间
        res = tmp;         // 将拼接后的字符串存入动态数组
        len_res += len_s;  // 更新已拼接字符串的长度
    }

    cout << res << endl;  // 输出拼接后的字符串
    delete[] res;         // 释放动态数组空间
    return 0;
}
