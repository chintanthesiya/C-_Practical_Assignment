#include <iostream>
using namespace std;

class Time {
private:
    int h; 
    int m; 

public:
    Time(int hours, int minutes) {
        h = hours;
        m = minutes;
    }

    void addMinutes(int extraMins) {
        int totalMins = m + extraMins;
        h = h + (totalMins / 60); 
        m = totalMins % 60;       

        h = h % 24; 
    }

    void display() {
        cout << h << " hours and " << m << " minutes" << endl;
    }
};

int main() {
    int h, m, minsToAdd;
    cout << "Enter initial hours: ";
    cin >> h;
    cout << "Enter initial minutes: ";
    cin >> m;
    Time myTime(h, m);
    cout << "\nInitial Time: ";
    myTime.display();
    cout << "\nEnter minutes to add: ";
    cin >> minsToAdd;
    myTime.addMinutes(minsToAdd);
    
    cout << "New Time: ";
    myTime.display();

    return 0;
}
