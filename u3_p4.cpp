
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float number1, number2, number3;

    cout << "Enter three float values: ";
    cin >> number1 >> number2 >> number3;

    cout << "\nFormatted Output:" << endl;

    cout << setfill('+') << right << fixed << setprecision(2);

    cout << setw(5) << number1 << endl;
    cout << setw(5) << number2 << endl;
    cout << setw(5) << number3 << endl;

    return 0;
}

