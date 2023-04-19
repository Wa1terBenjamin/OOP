// 设计一个矩形类(Rectangle)，属性为矩形的左下和右上角的坐标，矩形水平放置。计算并输入矩形的周长和面积。
// 输入第一行为左下坐标，第二行为右上坐标。
// 输出第一行为周长，第二行为面积。
// 样例输入：
// 0 0
// 5 5
// 样例输出：
// 20
// 25
#include <iostream>
#include <utility>
using namespace std;

class Rectangle {
   public:
    pair<int, int> leftdown, rightup;
    int Perimeter();
    int Area();
};
int Rectangle::Perimeter() {
    return (rightup.first - leftdown.first + rightup.second - leftdown.second) *
           2;
}
int Rectangle::Area() {
    return (rightup.first - leftdown.first) *
           (rightup.second - leftdown.second);
}
int main() {
    Rectangle rc;
    cin >> rc.leftdown.first >> rc.leftdown.second;
    cin >> rc.rightup.first >> rc.rightup.second;
    cout << rc.Perimeter() << endl << rc.Area();
    return 0;
}