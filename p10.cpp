
//10. Write a C++ program to create a class Wallet to manage the details and 
//transactions of digital wallets. The class should contain the following data 
//members: Wallet ID, Owner Name, Balance, and Transaction Count. 
//Also display following details: 
//Details of the wallet having the highest balance. 
//Details of the wallet having the highest number of transactions. 
//The total number of transactions performed by all wallets. 
//Validate followings: 
//Additional Conditions: 
//Initial balance must be at least ?500. 
//Deposit amount must be ?100 or more. 
//Withdrawal is allowed only when the resulting balance remains at least 
//?500. 
//Every successful deposit or withdrawal should increase the wallet's 
//transaction count and the static total transaction count. 
//Invalid deposits and withdrawals should not be counted as 
//transactions.


#include <iostream>
#include <string>

using namespace std;

class Wallet {
    int walletID;
    string ownerName;
    float balance;
    int transactionCount;

public:
    static int totalTransactions;

    void input() {
        cout << "Enter Wallet ID: ";
        cin >> walletID;
        cout << "Enter Owner Name: ";
        cin >> ownerName;
        
        do {
            cout << "Enter Initial Balance (Minimum 500): ";
            cin >> balance;
            if (balance < 500) {
                cout << "Error: Initial balance must be at least 500.\n";
            }
        } while (balance < 500);
        
        transactionCount = 0;
    }

    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        
        if (amount >= 100) {
            balance += amount;
            transactionCount++;
            totalTransactions++;
            cout << "Deposit successful. New Balance: " << balance << "\n";
        } else {
            cout << "Error: Deposit amount must be 100 or more.\n";
        }
    }

    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        
        if ((balance - amount) >= 500) {
            balance -= amount;
            transactionCount++;
            totalTransactions++;
            cout << "Withdrawal successful. New Balance: " << balance << "\n";
        } else {
            cout << "Error: Withdrawal denied. Minimum balance of 500 must be maintained.\n";
        }
    }

    void display() {
        cout << walletID << "\t" << ownerName << "\t" << balance << "\t\t" << transactionCount << "\n";
    }

    float getBalance() {
        return balance;
    }

    int getTransactionCount() {
        return transactionCount;
    }

    int getWalletID() {
        return walletID;
    }
};

int Wallet::totalTransactions = 0;

int main() {
    int n;
    cout << "Enter the number of wallets: ";
    cin >> n;

    Wallet* wallets = new Wallet[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter details for Wallet " << i + 1 << " ---\n";
        wallets[i].input();
    }

    int choice;
    while (true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. Exit and Show Results\nEnter choice: ";
        cin >> choice;

        if (choice == 3) {
            break;
        }

        if (choice == 1 || choice == 2) {
            int searchID;
            cout << "Enter Wallet ID: ";
            cin >> searchID;
            
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (wallets[i].getWalletID() == searchID) {
                    found = true;
                    if (choice == 1) {
                        wallets[i].deposit();
                    } else {
                        wallets[i].withdraw();
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Wallet ID not found.\n";
            }
        } else {
            cout << "Invalid choice.\n";
        }
    }

    if (n > 0) {
        int maxBalIndex = 0;
        int maxTransIndex = 0;

        for (int i = 1; i < n; i++) {
            if (wallets[i].getBalance() > wallets[maxBalIndex].getBalance()) {
                maxBalIndex = i;
            }
            if (wallets[i].getTransactionCount() > wallets[maxTransIndex].getTransactionCount()) {
                maxTransIndex = i;
            }
        }

        cout << "\n=========================================================\n";
        cout << "Wallet with Highest Balance\n";
        cout << "=========================================================\n";
        cout << "ID\tName\tBalance\t\tTransactions\n";
        wallets[maxBalIndex].display();

        cout << "\n=========================================================\n";
        cout << "Wallet with Highest Number of Transactions\n";
        cout << "=========================================================\n";
        cout << "ID\tName\tBalance\t\tTransactions\n";
        wallets[maxTransIndex].display();

        cout << "\n=========================================================\n";
        cout << "Total number of transactions performed by all wallets: " << Wallet::totalTransactions << "\n";
        cout << "=========================================================\n";
    }

    delete[] wallets;

    return 0;
}
