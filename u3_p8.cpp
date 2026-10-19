
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream output_file;
    ifstream input_file;

    string student_name;
    float marks;

    output_file.open("student.txt");

    if (!output_file)
    {
        cout << "Error creating student file!" << endl;
        return 1;
    }

    cout << "Enter details of 5 students:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter name of student " << i + 1 << ": ";
        getline(cin >> ws, student_name);

        do
        {
            cout << "Enter marks (0-100): ";
            cin >> marks;

            if (cin.fail() || marks < 0 || marks > 100)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                marks = -1;
                cout << "Invalid marks! Enter marks between 0 and 100."
                     << endl;
            }

        } while (marks < 0 || marks > 100);

        output_file << student_name << endl;
        output_file << marks << endl;
    }

    output_file.close();

    input_file.open("student.txt");

    if (!input_file)
    {
        cout << "Error opening student file!" << endl;
        return 1;
    }

    cout << "\n----- Student Details -----" << endl;

    for (int i = 0; i < 5; i++)
    {
        getline(input_file, student_name);
        input_file >> marks;
        input_file.ignore(10000, '\n');

        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: " << student_name << endl;
        cout << "Marks: " << marks << endl;
    }

    input_file.close();

    return 0;
}

