// 1、定义一个类，其中有静态数据成员、各种类型非静态数据成员（含字符指针），静态和非静态成员函数（含分配空间的构造函数、析构函数）。
// 2、定义全局对象、main函数中局部对象、另一个被main调用的外部函数func中定义局部对象（可以是形参），main函数中动态创建对象，每种对象至少2个。观察、分析各种对象地址。
// 3、输出对象中各个静态与非静态数据成员的值、地址、对象的存储空间大小等信息。由此理解对象的本质、静态数据成员是本类对象共享一份拷贝等问题。
// 4、对于上述各种对象，输出静态非静态成员函数地址，以及main、func的地址，并分析。
// 注意：本题作为实验报告内容，要求有代码、注释、结果截图及分析。以班为单位统一收，电子版，发我的邮箱libaohong32@163.com

#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Time {
    short hour;
    short minute;
    short second;

   public:
    Time() : hour(0), minute(0), second(0){};
    Time(short _hour, short _minute, short _second)
        : hour(_hour), minute(_minute), second(_second) {}
    bool operator<(Time x) {
        if (this->hour < x.hour)
            return true;
        else if (this->minute < x.minute)
            return true;
        else if (this->second < x.second)
            return true;
        else
            return false;
    }
    friend ostream& operator<<(ostream& os, const Time& s) {
        stringstream ss;
        ss << setiosflags(ios::right) << setfill('0') << setw(2) << s.hour
           << ":" << setw(2) << s.minute << ":" << setw(2) << s.second;
        string tmp;
        ss >> tmp;
        os << tmp;
        return os;
    }

    Time operator+(const short time_zone_gap) const {
        Time tmp;
        tmp.hour = hour + time_zone_gap;
        tmp.minute = minute;
        tmp.second = second;
        if (tmp.hour < 0)
            tmp.hour += 24;
        else if (tmp.hour >= 24)
            tmp.hour -= 24;
        return tmp;
    }
};

class Area {
   private:
    // 各种类型非静态数据成员（含字符指针）
    char* name;       // 地区名称
    short time_zone;  // 时区，东八区为+8，西六区为-6
    Time loc_time;    // 地方时，以小时为单位的浮点数
    // 静态数据成员
    static Time utc_time;  // UTC时间，全球每个地方都相同

   public:
    Area(){};
    // 分配空间的构造函数
    Area(const char* name, const short time_zone);
    // 析构函数
    ~Area();

    // 非静态成员函数

    // 地区名称Getter
    const char* GetName();
    // 地方时Getter
    const Time& GetLocal();
    // 时区Getter
    const short& GetTimeZone();
    // 地区名称变量地址Getter
    char** GetNameAdrr();

    // 静态成员函数

    // 当前UTC时间Getter
    static Time& GetUTC();
    // 当前UTC时间Setter
    static void SetUTC(Time f_utc);
};

// 初始化静态变量UTC
Time Area::utc_time = Time(0, 0, 0);

Area::Area(const char* name, const short time_zone) {
    this->name = new char(strlen(name));
    strcpy(this->name, name);  // 拷贝构造
    this->time_zone = time_zone;
    this->loc_time = utc_time + time_zone;
}

Area::~Area() {
    delete[] name;
}

const char* Area::GetName() {
    return name;
}

const Time& Area::GetLocal() {
    return loc_time;
}

const short& Area::GetTimeZone() {
    return time_zone;
}

char** Area::GetNameAdrr() {
    return &name;
}

Time& Area::GetUTC() {
    return utc_time;
}

void Area::SetUTC(Time f_utc) {
    utc_time = f_utc;
}
// 全局对象London
Area London("London", 0);
// 全局对象Berlin
Area Berlin("Berlin", +1);

// 依照时区比较两个地区的时间先后
void printEarlier(Area a, Area b) {
    auto a_zone = a.GetTimeZone();
    auto b_zone = b.GetTimeZone();
    if (a_zone > b_zone)
        cout << a.GetName();
    else
        cout << b.GetName();
    cout << " is earlier." << endl;
    cout << "Local Objects in Memory" << endl
         << "   a:  " << &a << endl
         << "   b:  " << &b << endl;
}

int main() {
    // 设置静态成员变量UTC协调世界时
    Area::SetUTC(Time(6, 0, 0));
    // 局部对象Beijing
    Area Beijing("Beijing", +8);
    // 局部对象Tokyo
    Area Tokyo("Tokyo", +9);
    // 动态对象NewYork
    Area* pNewYork = new Area("NewYork", -5);
    // 动态对象Paris
    Area* pParis = new Area("Paris", 0);

    cout << setiosflags(ios::left) << "\n\n";

    // NewYork's local time is 01:00:00 and time zone is -5.
    cout << pNewYork->GetName() << "'s local time is " << pNewYork->GetLocal()
         << " and time zone is UTC" << pNewYork->GetTimeZone() << ".\nUTC is "
         << pNewYork->GetUTC() << ".\n\n";

    // Area类的大小
    cout << "\nsizeof(Area): " << sizeof(Area) << endl;
    // Tokyo is earlier.
    printEarlier(Beijing, Tokyo);

    // 其他格式输出
    cout << "Global Objects in Memory:" << endl
         << setw(12) << "   London:" << setw(12) << &London << endl
         << setw(12) << "   Berlin:" << setw(12) << &Berlin << endl
         << "Local Objects on Stack:" << endl
         << setw(12) << "   Beijing:" << setw(12) << &Beijing << endl
         << setw(12) << "   Tokyo:" << setw(12) << &Tokyo << endl
         << "Dynamic Objects on Heap:" << endl
         << setw(12) << "   New York:" << setw(12) << pNewYork << &pNewYork
         << "(Pointer)" << endl
         << setw(12) << "   Paris:" << setw(12) << pParis << &pParis
         << "(Pointer)" << endl;

    
    Area* areas[] = {&London, &Berlin, &Beijing, &Tokyo, pNewYork, pParis};
    for (Area* area : areas) {
        cout << setw(22) << "   name: " << setw(10) << area->GetName()
             << "  Size: " << sizeof(area->GetName())
             << "  Address: " << area->GetNameAdrr() << endl;

        cout << setw(22) << "   time_zone: " << setw(10) << area->GetTimeZone()
             << "  Size: " << sizeof(area->GetTimeZone())
             << "  Address: " << &(area->GetTimeZone()) << endl;

        cout << setw(22) << "   loc_time: " << setw(10) << area->GetLocal()
             << "  Size: " << sizeof(area->GetLocal())
             << "  Address: " << &(area->GetLocal()) << endl;

        cout << setw(22) << "   utc_time(static): " << setw(10)
             << area->GetUTC() << "  Size: " << sizeof(area->GetUTC())
             << "  Address: " << &(area->GetUTC()) << endl;

        cout << "\n\n";
    }
    return 0;
}
