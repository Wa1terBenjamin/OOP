// 设计一个点类Point，它有两个私有数据成员x和y，表示点的坐标。另一个类为直线类Line，它有三个私有数据成员A、B和C，表示直线方程Ax+By+C=0。这两个类中都说明了一个友元函数dist（），用于计算一个点到直线的距离。点(x0,y0)到直线Ax+By+C=0的距离d的计算公式如下：

// dist = abs(A*x0 + B*y0 + C) / sqrt(A * A + B * B);

// 第一行输入点坐标，第二行输入a，b，c的值。

// 样例输入：
// 10 10
// 2 4 -3

// 样例输出：
// 12.75

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

class Point;
class Line;
float dist(Point& p, Line& l);

class Point {
   private:
    float x, y;

   public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    friend float dist(Point& p, Line& l);
};

class Line {
   private:
    int A, B, C;

   public:
    Line(int a, int b, int c) {
        A = a;
        B = b;
        C = c;
    }
    friend float dist(Point& p, Line& l);
};

float dist(Point& p, Line& l) {
    return abs(l.A * p.x + l.B * p.y + l.C) / sqrt(l.A * l.A + l.B * l.B);
}

int main() {
    float x, y, z;
    cin >> x >> y;
    Point p(x, y);
    cin >> x >> y >> z;
    Line l(x, y, z);
    cout << setiosflags(ios::fixed) << setprecision(2) << dist(p, l) << endl;
}