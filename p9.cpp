
//9. Write a program to create class ‘Search’ having data members (int a[ ], x) and 
//define member functions as void input(), void output(), void search(int position), 
//void add(int value) to display result. 




#include <iostream>

using namespace std;

class Search {
    int a[100];
    int x;

public:
    Search() {
        x = 0;
    }

    void input() {
        cout << "Enter number of elements: ";
        cin >> x;
        cout << "Enter elements:\n";
        for (int i = 0; i < x; i++) {
            cin >> a[i];
        }
    }

    void output() {
        cout << "Array elements: ";
        for (int i = 0; i < x; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    void search(int position) {
        if (position >= 1 && position <= x) {
            cout << "Element at position " << position << " is " << a[position - 1] << "\n";
        } else {
            cout << "Invalid position\n";
        }
    }

    void add(int value) {
        if (x < 100) {
            a[x] = value;
            x++;
            cout << "Value added successfully\n";
        } else {
            cout << "Array is full\n";
        }
    }
};

int main() {
    Search obj;
    int choice, pos, val;
    int x;

    obj.input();

    cout << "\n1. Output Array\n2. Search by Position\n3. Add Value\n4. Exit\n";
    
    while (true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            obj.output();
        } else if (choice == 2) {
            cout << "Enter position to search (1 to " << x << "): ";
            cin >> pos;
            obj.search(pos);
        } else if (choice == 3) {
            cout << "Enter value to add: ";
            cin >> val;
            obj.add(val);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
