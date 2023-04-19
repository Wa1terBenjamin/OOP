#include <iostream>

void global() {
    std::cout << "global:";
}
class Test {
   public:
    void member() { std::cout << "member:"; }
};

int main() {
    // 全局函数的地址
    void (*pTest)() = global;
    (*pTest)();
    std::cout << std::hex << reinterpret_cast<void*>(pTest) << std::endl;
    // 类成员函数的地址
    Test test;
    void (Test::*pMember)() = &Test::member;
    (test.*pMember)();
    std::cout << std::hex << reinterpret_cast<void*>(pMember) << std::endl;
}