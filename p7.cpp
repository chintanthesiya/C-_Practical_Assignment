
//7. Create class STUDENT having rollno, name and age as data members, also 
//take subject with three subjects and initialize their value with minimum 
//passing marks. Using member function, modify marks of student with specific 
//rollno which is given by user.



#include <iostream>
#include <string>

using namespace std;

class STUDENT {
    int rollno;
    string name;
    int age;
    float sub1, sub2, sub3;

public:
    STUDENT() {
        sub1 = 35;
        sub2 = 35;
        sub3 = 35;
    }

    void input() {
        cout << "Enter Roll No: ";
        cin >> rollno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void display() {
        cout << rollno << "\t" << name << "\t" << age << "\t" 
             << sub1 << "\t" << sub2 << "\t" << sub3 << endl;
    }

    int getRollNo() {
        return rollno;
    }

    void modifyMarks() {
        cout << "Enter new marks for Subject 1: ";
        cin >> sub1;
        cout << "Enter new marks for Subject 2: ";
        cin >> sub2;
        cout << "Enter new marks for Subject 3: ";
        cin >> sub3;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    STUDENT* s = new STUDENT[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        s[i].input();
    }

    int searchRoll;
    cout << "\nEnter Roll No of the student to modify marks: ";
    cin >> searchRoll;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s[i].getRollNo() == searchRoll) {
            s[i].modifyMarks();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with Roll No " << searchRoll << " not found!\n";
    }

    cout << "\n=======================================================\n";
    cout << "RollNo\tName\tAge\tSub1\tSub2\tSub3\n";
    cout << "=======================================================\n";
    for (int i = 0; i < n; i++) {
        s[i].display();
    }
    cout << "=======================================================\n";

    delete[] s;

    return 0;
}
