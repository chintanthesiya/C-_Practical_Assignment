
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Customer
{
    int account_no;
    string account_type, name, payment_date;
    float old_balance, new_balance, last_payment;

public:
    void get_data()
    {
        cout << "Enter account number: ";
        cin >> account_no;

        cout << "Enter account type: ";
        cin >> account_type;

        cout << "Enter customer name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter old balance: ";
        cin >> old_balance;

        cout << "Enter last payment: ";
        cin >> last_payment;

        cout << "Enter date of last payment (DD-MM-YYYY): ";
        cin >> payment_date;

        new_balance = old_balance - last_payment;
    }

    void write_file()
    {
        ofstream fout("customer.txt", ios::app);

        fout << account_no << endl;
        fout << account_type << endl;
        fout << name << endl;
        fout << old_balance << endl;
        fout << new_balance << endl;
        fout << last_payment << endl;
        fout << payment_date << endl;

        fout.close();
    }

    void display()
    {
        cout << "\nAccount Number      : " << account_no << endl;
        cout << "Account Type        : " << account_type << endl;
        cout << "Customer Name       : " << name << endl;
        cout << "Old Balance         : " << fixed << setprecision(2)
             << old_balance << endl;
        cout << "Last Payment        : " << last_payment << endl;
        cout << "Date of Last Payment: " << payment_date << endl;
        cout << "Current Balance     : " << new_balance << endl;

        if (new_balance > 0)
            cout << "Account Status      : Payment Due" << endl;
        else if (new_balance == 0)
            cout << "Account Status      : Fully Paid" << endl;
        else
            cout << "Account Status      : Credit Balance" << endl;
    }

    void read_file()
    {
        ifstream fin("customer.txt");

        if (!fin)
        {
            cout << "Customer file not found." << endl;
            return;
        }

        while (fin >> account_no)
        {
            fin.ignore(1000, '\n');
            getline(fin, account_type);
            getline(fin, name);
            fin >> old_balance;
            fin >> new_balance;
            fin >> last_payment;
            fin.ignore(1000, '\n');
            getline(fin, payment_date);

            display();
            cout << "-----------------------------------" << endl;
        }

        fin.close();
    }
};

int main()
{
    Customer c;
    int choice;

    do
    {
        cout << "\n===== CUSTOMER ACCOUNT SYSTEM =====" << endl;
        cout << "1. Add customer record" << endl;
        cout << "2. Display customer records" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            c.get_data();
            c.write_file();
            cout << "Customer record saved successfully." << endl;
            break;

        case 2:
            c.read_file();
            break;

        case 3:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}

