
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class publication
{
protected:
    string title;
    float price;

public:
    void get_data()
    {
        cout << "Enter title: ";
        getline(cin >> ws, title);

        do
        {
            cout << "Enter price: ";
            cin >> price;

            if (cin.fail() || price <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                price = 0;
                cout << "Invalid price! Enter a positive value." << endl;
            }
        } while (price <= 0);
    }

    virtual void display()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    virtual ~publication()
    {
    }
};

class book : public publication
{
private:
    int page_count;

public:
    void get_book_data()
    {
        get_data();

        do
        {
            cout << "Enter page count: ";
            cin >> page_count;

            if (cin.fail() || page_count <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                page_count = 0;
                cout << "Invalid page count! Enter a positive number."
                     << endl;
            }
        } while (page_count <= 0);
    }

    void display()
    {
        publication::display();
        cout << "Page Count: " << page_count << endl;
    }
};

class tape : public publication
{
private:
    float playing_time;

public:
    void get_tape_data()
    {
        get_data();

        do
        {
            cout << "Enter playing time in minutes: ";
            cin >> playing_time;

            if (cin.fail() || playing_time <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                playing_time = 0;
                cout << "Invalid playing time! Enter a positive value."
                     << endl;
            }
        } while (playing_time <= 0);
    }

    void display()
    {
        publication::display();
        cout << "Playing Time: " << playing_time << " minutes" << endl;
    }
};

int main()
{
    publication *publication_array[100];
    int number_of_entries;
    int choice;
    int book_count = 0;
    int tape_count = 0;

    do
    {
        cout << "Enter number of publications (1 to 100): ";
        cin >> number_of_entries;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            number_of_entries = 0;
        }

        if (number_of_entries < 1 || number_of_entries > 100)
        {
            cout << "Invalid input! Enter a number from 1 to 100."
                 << endl;
        }
    } while (number_of_entries < 1 || number_of_entries > 100);

    for (int i = 0; i < number_of_entries; i++)
    {
        cout << "\nSelect publication type:" << endl;
        cout << "1. Book" << endl;
        cout << "2. Tape" << endl;

        do
        {
            cout << "Enter your choice (1-2): ";
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                choice = 0;
            }

            if (choice < 1 || choice > 2)
            {
                cout << "Invalid choice! Select 1 or 2." << endl;
            }
        } while (choice < 1 || choice > 2);

        if (choice == 1)
        {
            book *book_ptr = new book();
            book_ptr->get_book_data();
            publication_array[i] = book_ptr;
        }
        else
        {
            tape *tape_ptr = new tape();
            tape_ptr->get_tape_data();
            publication_array[i] = tape_ptr;
        }
    }

    cout << "\n----- Publication Details -----" << endl;

    for (int i = 0; i < number_of_entries; i++)
    {
        cout << "\nPublication " << i + 1 << ":" << endl;
        publication_array[i]->display();

        if (dynamic_cast<book *>(publication_array[i]) != NULL)
        {
            book_count++;
        }
        else if (dynamic_cast<tape *>(publication_array[i]) != NULL)
        {
            tape_count++;
        }
    }

    cout << "\n----- Publication Count -----" << endl;
    cout << "Total Books: " << book_count << endl;
    cout << "Total Tapes: " << tape_count << endl;

    for (int i = 0; i < number_of_entries; i++)
    {
        delete publication_array[i];
    }

    return 0;
}

