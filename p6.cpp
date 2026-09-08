// 6. Write a program to define a class called book. Write a program to read 
// information about 10 books and display books details in ascending order of 
// price in proper format. 


#include <iostream>
#include <string>

using namespace std;

class book {
public:
    string title;
    string author;
    float price;

    void input() {
        cout << "Enter Book Title: ";
        cin >> title;
        cout << "Enter Book Author: ";
        cin >> author;
        cout << "Enter Book Price: ";
        cin >> price;
    }

    void display() {
        cout << title << "\t" << author << "\t" << price << endl;
    }
};

void sortBooks(book arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].price > arr[j+1].price) {
                book temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    book books[10];

    for (int i = 0; i < 10; i++) {
        cout << "\n--- Enter details for Book " << i + 1 << " ---" << endl;
        books[i].input();
    }

    sortBooks(books, 10);

    cout << "\n============================================\n";
    cout << "Title\tAuthor\tPrice\n";
    cout << "============================================\n";
    
    for (int i = 0; i < 10; i++) {
        books[i].display();
    }
    
    cout << "============================================\n";

    return 0;
}
