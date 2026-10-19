
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Result
{
private:
    int roll_no;
    string name;
    float marks;

public:
    void display_heading()
    {
        cout << setfill('=') << setw(60) << "" << endl;
        cout << setfill(' ');

        cout << left << setw(10) << "Roll No"
             << setw(25) << "Candidate Name"
             << right << setw(10) << "Marks" << endl;

        cout << setfill('=') << setw(60) << "" << endl;
        cout << setfill(' ');
    }

    void display_candidate(int roll_no, string name, float marks)
    {
        cout << left << setw(10) << roll_no
             << setw(25) << name
             << right << setw(10) << fixed << setprecision(2)
             << marks << endl;
    }

    void display_merit_list()
    {
        ifstream file("merit.txt");

        if (!file)
        {
            cout << "Error: Unable to open merit.txt file." << endl;
            return;
        }

        int count = 0;
        char choice;

        while (file >> roll_no)
        {
            file >> ws;
            getline(file, name);
            file >> marks;

            if (file.fail())
            {
                break;
            }

            if (count % 10 == 0)
            {
                if (count > 0)
                {
                    cout << "\nPress Enter to display the next 10 "
                         << "candidates, or enter q to quit: ";

                    cin.get(choice);

                    if (choice == 'q' || choice == 'Q')
                    {
                        break;
                    }
                }

                display_heading();
            }

            display_candidate(roll_no, name, marks);
            count++;
        }

        file.close();

        if (count == 0)
        {
            cout << "No candidate records found in the file." << endl;
        }
        else
        {
            cout << "\nTotal candidates displayed: " << count << endl;
        }
    }
};

int main()
{
    Result result;
    result.display_merit_list();

    return 0;
}

