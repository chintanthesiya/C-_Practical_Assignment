
#include <iostream>
using namespace std;

namespace student_data
{
    int total_marks(int marks1, int marks2, int marks3)
    {
        return marks1 + marks2 + marks3;
    }
}

class marks
{
private:
    string student_name;
    int roll_no;
    int marks1, marks2, marks3;
    int total;

public:
    void get_data()
    {
        cout << "Enter student name: ";
        getline(cin >> ws, student_name);

        do
        {
            cout << "Enter roll number: ";
            cin >> roll_no;

            if (cin.fail() || roll_no <= 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                roll_no = 0;
                cout << "Invalid roll number! Try again." << endl;
            }
        } while (roll_no <= 0);

        do
        {
            cout << "Enter marks of Subject 1 (0-100): ";
            cin >> marks1;

            if (cin.fail() || marks1 < 0 || marks1 > 100)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                marks1 = -1;
                cout << "Invalid marks! Enter marks from 0 to 100."
                     << endl;
            }
        } while (marks1 < 0 || marks1 > 100);

        do
        {
            cout << "Enter marks of Subject 2 (0-100): ";
            cin >> marks2;

            if (cin.fail() || marks2 < 0 || marks2 > 100)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                marks2 = -1;
                cout << "Invalid marks! Enter marks from 0 to 100."
                     << endl;
            }
        } while (marks2 < 0 || marks2 > 100);

        do
        {
            cout << "Enter marks of Subject 3 (0-100): ";
            cin >> marks3;

            if (cin.fail() || marks3 < 0 || marks3 > 100)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                marks3 = -1;
                cout << "Invalid marks! Enter marks from 0 to 100."
                     << endl;
            }
        } while (marks3 < 0 || marks3 > 100);
    }

    void display()
    {
        total = student_data::total_marks(marks1, marks2, marks3);

        cout << "\n----- Student Mark Details -----" << endl;
        cout << "Student Name: " << student_name << endl;
        cout << "Roll Number: " << roll_no << endl;
        cout << "Subject 1 Marks: " << marks1 << endl;
        cout << "Subject 2 Marks: " << marks2 << endl;
        cout << "Subject 3 Marks: " << marks3 << endl;
        cout << "Total Marks: " << total << " / 300" << endl;
    }
};

int main()
{
    marks student;

    student.get_data();
    student.display();

    return 0;
}

