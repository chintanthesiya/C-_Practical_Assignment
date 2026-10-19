
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Telephone
{
    string name, phone;

public:
    void create_file()
    {
        ofstream fout("telephone.txt");

        fout << "Ram 56789125" << endl;
        fout << "Shyam 34565432" << endl;
        fout << "Rahim 23456789" << endl;
        fout << "Joseph 67213148" << endl;

        fout.close();
    }

    void display()
    {
        ifstream fin("telephone.txt");

        cout << left << setw(20) << "Name"
             << right << setw(15) << "Phone" << endl;

        cout << "-----------------------------------" << endl;

        while (fin >> name >> phone)
        {
            cout << left << setw(20) << name
                 << right << setw(15) << phone << endl;
        }

        fin.close();
    }

    void search_name()
    {
        string search;
        int found = 0;

        cout << "Enter name: ";
        cin >> search;

        ifstream fin("telephone.txt");

        while (fin >> name >> phone)
        {
            if (name == search)
            {
                cout << "Telephone number: " << phone << endl;
                found = 1;
                break;
            }
        }

        fin.close();

        if (found == 0)
            cout << "Name not found." << endl;
    }

    void search_phone()
    {
        string search;
        int found = 0;

        cout << "Enter telephone number: ";
        cin >> search;

        ifstream fin("telephone.txt");

        while (fin >> name >> phone)
        {
            if (phone == search)
            {
                cout << "Name: " << name << endl;
                found = 1;
                break;
            }
        }

        fin.close();

        if (found == 0)
            cout << "Telephone number not found." << endl;
    }

    void update_phone()
    {
        string search, new_phone;
        int found = 0;

        cout << "Enter name to update: ";
        cin >> search;

        ifstream fin("telephone.txt");
        ofstream fout("temp.txt");

        while (fin >> name >> phone)
        {
            if (name == search)
            {
                cout << "Enter new telephone number: ";
                cin >> new_phone;
                phone = new_phone;
                found = 1;
            }

            fout << name << " " << phone << endl;
        }

        fin.close();
        fout.close();

        remove("telephone.txt");
        rename("temp.txt", "telephone.txt");

        if (found == 1)
            cout << "Telephone number updated successfully." << endl;
        else
            cout << "Name not found." << endl;
    }

    void prefix_numbers()
    {
        ifstream fin("telephone.txt");
        ofstream fout("temp.txt");

        while (fin >> name >> phone)
        {
            phone = "2" + phone;
            fout << name << " " << phone << endl;
        }

        fin.close();
        fout.close();

        remove("telephone.txt");
        rename("temp.txt", "telephone.txt");

        cout << "Prefix 2 added to all telephone numbers." << endl;
    }
};

int main()
{
    Telephone t;
    int choice;

    t.create_file();

    do
    {
        cout << "\n===== TELEPHONE DIRECTORY =====" << endl;
        cout << "1. Display all records" << endl;
        cout << "2. Search telephone number by name" << endl;
        cout << "3. Search name by telephone number" << endl;
        cout << "4. Update telephone number" << endl;
        cout << "5. Prefix all numbers with 2" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            t.display();
            break;

        case 2:
            t.search_name();
            break;

        case 3:
            t.search_phone();
            break;

        case 4:
            t.update_phone();
            break;

        case 5:
            t.prefix_numbers();
            break;

        case 6:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}

