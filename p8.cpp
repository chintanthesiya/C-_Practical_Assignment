
//8. Define a class to represent a bank account. Include the following members : 
//DATA MEMBERS                    ------------------------                 
//Name of depositor                    
//Account Number                      
//Type of Account                       
//MEMBER FUNCTIONS ------------------------------ 
//(1) To assign initial values 
//(2) To Deposit the amount 
//(3) To withdraw an amount after checking the 
//Balance amount in account     (4) To display name and balance 
//Write C++ program to handle 10 customers.




#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    string name;
    long acc_number;
    string acc_type;
    float balance;

public:
    void assignValues() {
        cout << "Enter Name of Depositor: ";
        cin >> name;
        cout << "Enter Account Number: ";
        cin >> acc_number;
        cout << "Enter Type of Account: ";
        cin >> acc_type;
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited successfully.\n";
    }

    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    void display() {
        cout << name << "\t\t" << balance << endl;
    }

    long getAccountNumber() {
        return acc_number;
    }
};

int main() {
    BankAccount customers[10];

    for (int i = 0; i < 10; i++) {
        cout << "\n--- Enter details for Customer " << i + 1 << " ---\n";
        customers[i].assignValues();
    }

    long searchAcc;
    cout << "\nEnter Account Number for transaction: ";
    cin >> searchAcc;

    bool found = false;
    for (int i = 0; i < 10; i++) {
        if (customers[i].getAccountNumber() == searchAcc) {
            found = true;
            int choice;
            cout << "1. Deposit\n2. Withdraw\n3. Display Balance\nEnter your choice: ";
            cin >> choice;

            if (choice == 1) {
                customers[i].deposit();
            } else if (choice == 2) {
                customers[i].withdraw();
            } else if (choice == 3) {
                cout << "\nName\t\tBalance\n";
                cout << "------------------------\n";
                customers[i].display();
            } else {
                cout << "Invalid choice!\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Account not found!\n";
    }

    cout << "\n========================================\n";
    cout << "All Customers Final Record\n";
    cout << "Name\t\tBalance\n";
    cout << "========================================\n";
    for (int i = 0; i < 10; i++) {
        customers[i].display();
    }
    cout << "========================================\n";

    return 0;
}
