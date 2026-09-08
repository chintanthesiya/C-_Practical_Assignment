
// 2. Write a program to create class Num (int n1, int n2, int n3, int n4). Display 
// total and average of n1, n2, n3 and n4.


#include <iostream>
using namespace std;

class Num {
private:
    int n1, n2, n3, n4;

public:
    
    Num(int a, int b, int c, int d) {
        n1 = a;
        n2 = b;
        n3 = c;
        n4 = d;
    }

    void displayTotalAndAverage() {
        int total = n1 + n2 + n3 + n4;
        float average = total / 4.0; 
        cout << "The numbers are: " << n1 << ", " << n2 << ", " << n3 << ", " << n4 << endl;
        cout << "Total: " << total << endl;
        cout << "Average: " << average << endl;
    }
};

int main() {

    Num myNumbers(10, 25, 30, 40);
    myNumbers.displayTotalAndAverage();
    return 0;
}
