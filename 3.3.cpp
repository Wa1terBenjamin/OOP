// 有一个日期类（Date）和一个时间类（Time），Date类包含私有成员年(year)，月（month），日（day）。Time类包含私有成员小时（hour），分钟（min），秒（sec）。现将Time类声明为Date类的友元类，通过Time类中的display()函数引用Date类对象的数据，并输出年、月、日和时、分、秒。

// 输入：
// 2010 1 17
// 16 30 56

// 输出：
// 2010/1/17
// 16:30:56

#include <iostream>
#include <string>

using namespace std;

class Date {
   private:
    int year, month, day;

   public:
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    friend class Time;
};

class Time {
   private:
    int hour, min, sec;

   public:
    Time(int h, int m, int s) {
        hour = h;
        min = m;
        sec = s;
    }
    void display(const Date&);
};

void Time::display(const Date& d) {
    cout << d.year << "/" << d.month << "/" << d.day << endl;
    cout << hour << ":" << min << ":" << sec << endl;
}

int main() {
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    Date d(t1,t2,t3);
    cin >> t1 >> t2 >> t3;
    Time t(t1,t2,t3);
    t.display(d);
    return 0;
}