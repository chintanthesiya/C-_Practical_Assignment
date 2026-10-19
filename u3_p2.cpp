
#include <iostream>
#include <string>
using namespace std;

class student
{
protected:
    string name;
    int rollno;

public:
    void get_data()
    {
        cout << "Enter student name: ";
        getline(cin >> ws, name);

        do
        {
            cout << "Enter roll number: ";
            cin >> rollno;

            if (cin.fail() || rollno <= 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                rollno = 0;
                cout << "Invalid roll number! Try again." << endl;
            }

        } while (rollno <= 0);
    }

    virtual void display()
    {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
    }

    virtual ~student()
    {
    }
};

class test : public student
{
private:
    float internal_marks;

public:
    void get_test_marks()
    {
        do
        {
            cout << "Enter internal test marks (0-100): ";
            cin >> internal_marks;

            if (cin.fail() || internal_marks < 0 ||
                internal_marks > 100)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                internal_marks = -1;
                cout << "Invalid marks! Enter marks from 0 to 100."
                     << endl;
            }

        } while (internal_marks < 0 || internal_marks > 100);
    }

    void display()
    {
        student::display();
        cout << "Internal Test Marks: " << internal_marks << endl;
    }
};

class sports : public student
{
private:
    float sports_marks;

public:
    void get_sports_marks()
    {
        do
        {
            cout << "Enter sports marks (0-100): ";
            cin >> sports_marks;

            if (cin.fail() || sports_marks < 0 ||
                sports_marks > 100)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                sports_marks = -1;
                cout << "Invalid marks! Enter marks from 0 to 100."
                     << endl;
            }

        } while (sports_marks < 0 || sports_marks > 100);
    }

    void display()
    {
        student::display();
        cout << "Sports Marks: " << sports_marks << endl;
    }
};

int main()
{
    test test_student;
    sports sports_student;

    student *ptr;

    cout << "Enter Internal Test Student Details" << endl;
    test_student.get_data();
    test_student.get_test_marks();

    cout << "\nEnter Sports Student Details" << endl;
    sports_student.get_data();
    sports_student.get_sports_marks();

    cout << "\n----- Internal Test Details -----" << endl;
    ptr = &test_student;
    ptr->display();

    cout << "\n----- Sports Test Details -----" << endl;
    ptr = &sports_student;
    ptr->display();

    return 0;
}

