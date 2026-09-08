// 5. Write a program to create class employee with employee’s id, name and basic 
// salary. Calculate gross salary for each employee(HRA 20%, DA 30%, OA 10%). 
// Also count total number of employee records that are entered.


#include <iostream>
#include <string>

using namespace std;

class Employee {
    int id;
    string name;
    float basic_salary, gross_salary;
    
public:
    static int employee_count;

    void input() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name; 
        cout << "Enter Basic Salary: ";
        cin >> basic_salary;
        
        employee_count++;
        calculateGross();
    }

    void calculateGross() {
        float hra = basic_salary * 0.20; 
        float da = basic_salary * 0.30;  
        float oa = basic_salary * 0.10;  
        
        gross_salary = basic_salary + hra + da + oa;
    }

    void display() {
        cout << id << "\t" 
             << name << "\t" 
             << basic_salary << "\t\t" 
             << gross_salary << endl;
    }

    static void displayCount() {
        cout << "\nTotal number of employee records entered: " << employee_count << endl;
    }
};

int Employee::employee_count = 0;

int main() {
    int n;
    cout << "How many employees do you want to enter? ";
    cin >> n;

    Employee* emps = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter details for Employee " << i + 1 << " ---" << endl;
        emps[i].input();
    }

    cout << "\n======================================================\n";
    cout << "ID\tName\tBasic Salary\tGross Salary\n";
    cout << "======================================================\n";
    for (int i = 0; i < n; i++) {
        emps[i].display();
    }
    cout << "======================================================\n";

    Employee::displayCount();

    delete[] emps;

    return 0;
}
