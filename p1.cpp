#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int rollno;
    string name;
    float oocp, ai, mf;
    float total, percentage;


    void input() {
        cout << "Enter Roll No: ";
        cin >> rollno;
        cout << "Enter First Name: ";
        cin >> name; 
        cout << "Enter marks for OOCP, AI, and MF (out of 100): ";
        cin >> oocp >> ai >> mf;
        
        
        calculate();
    }

    
    void calculate() {
        total = oocp + ai + mf;
        percentage = (total / 300.0) * 100.0; 
    }

   
    void display() {
        cout << rollno << "\t" 
             << name << "\t" 
             << oocp << "\t" 
             << ai << "\t" 
             << mf << "\t" 
             << total << "\t" 
             << percentage << "%" << endl;
    }
};


void sortStudents(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            
            bool swapNeeded = false;
            
            
            if (arr[j].percentage < arr[j+1].percentage) {
                swapNeeded = true;
            } 
           
            else if (arr[j].percentage == arr[j+1].percentage) {
                if (arr[j].mf < arr[j+1].mf) {
                    swapNeeded = true;
                }
            }

            
            if (swapNeeded) {
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

   
    Student* students = new Student[n];

    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Student " << i + 1 << " ---" << endl;
        students[i].input();
    }

    
    sortStudents(students, n);

   
    cout << "\n===========================================================\n";
    cout << "RollNo\tName\tOOCP\tAI\tMF\tTotal\tPercentage\n";
    cout << "===========================================================\n";
    
    for (int i = 0; i < n; i++) {
        students[i].display();
    }
    cout << "===========================================================\n";

    
    delete[] students;

    return 0;
}
