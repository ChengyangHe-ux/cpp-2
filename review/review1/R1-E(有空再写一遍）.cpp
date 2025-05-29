#include <iostream>
using namespace std;

// 日期类
class Date {
private:
    int year, month, day;
    bool isLeapYear(int y) const {
        return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
    }
    int daysInMonth(int y, int m) const {
        if (m == 2) return isLeapYear(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    void addDay() {
        day++;
        if (day > daysInMonth(year, month)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
    void print() const {
        cout << year << " " << month << " " << day;
    }
};
class Time {
private:
    int hour, minute, second; 
public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
    void addSecond() {
        second++;
        if (second >= 60) {
            second = 0;
            minute++;
            if (minute >= 60) {
                minute = 0;
                hour++;
                if (hour >= 24) {
                    hour = 0;
                }
            }
        }
    }
    
    void print() const {
        cout << hour << " " << minute << " " << second;
    }
    bool needAddDay() const {
        return hour == 0 && minute == 0 && second == 0;
    }
};

// 日期时间类
class DateTime {
private:
    Date date;
    Time time;
public:
    DateTime(int y, int m, int d, int h, int min, int s) 
        : date(y, m, d), time(h, min, s) {}
    void addSeconds(int s) {
        for (int i = 0; i < s; ++i) {
            time.addSecond();
            if (time.needAddDay()) {
                date.addDay();
            }
        }
    }
    void print() const {
        date.print();
        cout << " ";
        time.print();
        cout << endl;
    }
};
int main() {
    int y, m, d, h, min, s, add_s;
    cin >> y >> m >> d >> h >> min >> s;
    cin >> add_s; 
    DateTime dt(y, m, d, h, min, s);
    dt.addSeconds(add_s);
    dt.print(); 
    return 0;
}