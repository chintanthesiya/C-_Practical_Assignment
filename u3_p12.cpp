
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdio>
using namespace std;

class Employee
{
    int id;
    string name, address, phone;

public:
    void get_data()
    {
        cout << "Enter employee ID: ";
        cin >> id;

        cout << "Enter employee name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter employee address: ";
        getline(cin, address);

        cout << "Enter telephone number: ";
        cin >> phone;
    }

    void display()
    {
        cout << "\nEmployee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << phone << endl;
    }

    void add_record()
    {
        Employee e;
        ofstream fout("employee.txt", ios::app);

        e.get_data();

        fout << e.id << endl;
        fout << e.name << endl;
        fout << e.address << endl;
        fout << e.phone << endl;

        fout.close();

        cout << "Employee record added successfully." << endl;
    }

    void modify_record()
    {
        int search_id, found = 0;
        Employee e;

        cout << "Enter employee ID to modify: ";
        cin >> search_id;

        ifstream fin("employee.txt");
        ofstream fout("temp.txt");

        while (fin >> e.id)
        {
            fin.ignore(1000, '\n');
            getline(fin, e.name);
            getline(fin, e.address);
            getline(fin, e.phone);

            if (e.id == search_id)
            {
                cout << "\nEnter new employee details:\n";
                e.get_data();
                found = 1;
            }

            fout << e.id << endl;
            fout << e.name << endl;
            fout << e.address << endl;
            fout << e.phone << endl;
        }

        fin.close();
        fout.close();

        remove("employee.txt");
        rename("temp.txt", "employee.txt");

        if (found == 1)
            cout << "Employee record modified successfully." << endl;
        else
            cout << "Employee ID not found." << endl;
    }

    void search_record()
    {
        string search_name;
        int found = 0;
        Employee e;

        cout << "Enter employee name: ";
        cin >> ws;
        getline(cin, search_name);

        ifstream fin("employee.txt");

        while (fin >> e.id)
        {
            fin.ignore(1000, '\n');
            getline(fin, e.name);
            getline(fin, e.address);
            getline(fin, e.phone);

            if (e.name == search_name)
            {
                e.display();
                found = 1;
            }
        }

        fin.close();

        if (found == 0)
            cout << "Employee not found." << endl;
    }

    void display_all()
    {
        Employee e;
        int found = 0;

        ifstream fin("employee.txt");

        cout << "\n========== EMPLOYEE LIST ==========\n";
        cout << left << setw(8) << "ID"
             << setw(25) << "Name"
             << setw(30) << "Address"
             << "Telephone" << endl;

        cout << "---------------------------------------------------------------\n";

        while (fin >> e.id)
        {
            fin.ignore(1000, '\n');
            getline(fin, e.name);
            getline(fin, e.address);
            getline(fin, e.phone);

            cout << left << setw(8) << e.id
                 << setw(25) << e.name
                 << setw(30) << e.address
                 << e.phone << endl;

            found = 1;
        }

        fin.close();

        if (found == 0)
            cout << "No employee records found." << endl;
    }
};

int main()
{
    Employee e;
    int choice;

    do
    {
        cout << "\n===== EMPLOYEE RECORD SYSTEM =====" << endl;
        cout << "1. Add a new record" << endl;
        cout << "2. Modify an existing record" << endl;
        cout << "3. Search employee by name" << endl;
        cout << "4. Display all employee records" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            e.add_record();
            break;

        case 2:
            e.modify_record();
            break;

        case 3:
            e.search_record();
            break;

        case 4:
            e.display_all();
            break;

        case 5:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

