#include <iostream>
using namespace std;

class Date {
    int day, month, year;

    bool isLeapYear(int y) {
        if (y % 400 == 0) return true;
        if (y % 100 == 0) return false;
        if (y % 4 == 0) return true;
        return false;
    }

    int getDaysInMonth(int m, int y) {
        if (m == 2) {
            if (isLeapYear(y)) return 29;
            return 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void addDays(int daysToAdd) {
        day += daysToAdd;

        while (day > getDaysInMonth(month, year)) {
            day -= getDaysInMonth(month, year);
            month++;

            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    int d, m, y, extraDays;

    cout << "Enter current date (DD MM YYYY): ";
    cin >> d >> m >> y;

    Date dateObj(d, m, y);

    cout << "Enter days to add: ";
    cin >> extraDays;

    dateObj.addDays(extraDays);

    cout << "New Date: ";
    dateObj.display();

    return 0;
}
