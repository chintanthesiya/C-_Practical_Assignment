
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class marksheet
{
private:
    string student_name;
    int roll_no;
    string class_name;
    string subject_name[3];
    int marks[3][5];

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

        cout << "Enter class: ";
        getline(cin >> ws, class_name);

        for (int i = 0; i < 3; i++)
        {
            cout << "Enter subject " << i + 1 << " name: ";
            getline(cin >> ws, subject_name[i]);

            for (int j = 0; j < 5; j++)
            {
                do
                {
                    cout << "Enter mark " << j + 1 << " for "
                         << subject_name[i] << " (0-100): ";
                    cin >> marks[i][j];

                    if (cin.fail() || marks[i][j] < 0 ||
                        marks[i][j] > 100)
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        marks[i][j] = -1;
                        cout << "Invalid marks! Enter marks from 0 to 100."
                             << endl;
                    }
                } while (marks[i][j] < 0 || marks[i][j] > 100);
            }
        }
    }

    void PrintMarkSheet()
    {
        int total_marks = 0;

        cout << "\n";
        cout << setfill('=') << setw(75) << "" << endl;
        cout << setfill(' ');

        cout << setw(45) << right << "STUDENT MARKSHEET" << endl;

        cout << setfill('=') << setw(75) << "" << endl;
        cout << setfill(' ');

        cout << "Student Name : " << student_name << endl;
        cout << "Roll Number  : " << roll_no << endl;
        cout << "Class        : " << class_name << endl;

        cout << setfill('-') << setw(75) << "" << endl;
        cout << setfill(' ');

        cout << left << setw(20) << "Subject";

        for (int j = 0; j < 5; j++)
        {
            cout << right << setw(10) << "Mark " << j + 1;
        }

        cout << endl;

        cout << setfill('-') << setw(75) << "" << endl;
        cout << setfill(' ');

        for (int i = 0; i < 3; i++)
        {
            cout << left << setw(20) << subject_name[i];

            for (int j = 0; j < 5; j++)
            {
                cout << right << setw(10) << marks[i][j];
                total_marks += marks[i][j];
            }

            cout << endl;
        }

        cout << setfill('-') << setw(75) << "" << endl;
        cout << setfill(' ');

        cout << left << setw(20) << "Total Marks";
        cout << right << setw(50) << total_marks << " / 1500" << endl;

        cout << left << setw(20) << "Percentage";
        cout << right << setw(50) << fixed << setprecision(2)
             << (total_marks / 15.0) << "%" << endl;

        cout << setfill('=') << setw(75) << "" << endl;
        cout << setfill(' ');

        cout << "Footnote: Each mark is out of 100." << endl;
        cout << "Maximum Marks: 1500" << endl;

        cout << "Result: ";
        if (total_marks >= 750)
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }

        cout << setfill('=') << setw(75) << "" << endl;
        cout << setfill(' ');
    }
};

int main()
{
    marksheet student;

    student.get_data();
    student.PrintMarkSheet();

    return 0;
}

