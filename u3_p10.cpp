
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class student
{
private:
    string name;
    int roll_no;
    float marks;

public:
    void get_data()
    {
        cout << "Enter student name: ";
        getline(cin >> ws, name);

        cout << "Enter roll number: ";
        cin >> roll_no;

        cout << "Enter marks: ";
        cin >> marks;
    }

    void write_file()
    {
        ofstream file("student.txt");

        if (!file)
        {
            cout << "Error creating file!" << endl;
            return;
        }

        file << name << endl;
        file << roll_no << endl;
        file << marks << endl;

        file.close();

        cout << "Student details saved successfully." << endl;
    }

    void display_backwards()
    {
        ifstream file("student.txt");

        if (!file)
        {
            cout << "Error opening file!" << endl;
            return;
        }

        string content;
        string line;

        while (getline(file, line))
        {
            content += line;
            content += '\n';
        }

        file.close();

        cout << "\nStudent object displayed backwards:" << endl;

        for (int i = static_cast<int>(content.length()) - 1; i >= 0; i--)
        {
            cout << content[i];
        }

        cout << endl;
    }
};

int main()
{
    student s;

    s.get_data();
    s.write_file();
    s.display_backwards();

    return 0;
}

