
#include <iostream>
using namespace std;

class shape
{
protected:
    double value1, value2;

public:
    void get_data(double first_value, double second_value = 0)
    {
        value1 = first_value;
        value2 = second_value;
    }

    virtual void display_area()
    {
        cout << "Area of shape cannot be calculated." << endl;
    }

    virtual ~shape()
    {
    }
};

class triangle : public shape
{
public:
    void display_area()
    {
        double area;
        area = 0.5 * value1 * value2;

        cout << "Area of Triangle = " << area << endl;
    }
};

class rectangle : public shape
{
public:
    void display_area()
    {
        double area;
        area = value1 * value2;

        cout << "Area of Rectangle = " << area << endl;
    }
};

class circle : public shape
{
public:
    void display_area()
    {
        double area;
        const double PI = 3.14159;

        area = PI * value1 * value1;

        cout << "Area of Circle = " << area << endl;
    }
};

int main()
{
    int number_of_shapes, choice;
    double first_value, second_value;
    shape *shape_array[100];

    do
    {
        cout << "Enter number of shapes (1 to 100): ";
        cin >> number_of_shapes;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            number_of_shapes = 0;
        }

        if (number_of_shapes < 1 || number_of_shapes > 100)
        {
            cout << "Invalid input! Enter a number from 1 to 100."
                 << endl;
        }

    } while (number_of_shapes < 1 || number_of_shapes > 100);

    for (int i = 0; i < number_of_shapes; i++)
    {
        cout << "\nSelect shape " << i + 1 << ":" << endl;
        cout << "1. Triangle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Circle" << endl;

        do
        {
            cout << "Enter your choice (1-3): ";
            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                choice = 0;
            }

            if (choice < 1 || choice > 3)
            {
                cout << "Invalid choice! Try again." << endl;
            }

        } while (choice < 1 || choice > 3);

        if (choice == 1)
        {
            shape_array[i] = new triangle();

            do
            {
                cout << "Enter base: ";
                cin >> first_value;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    first_value = -1;
                }

                if (first_value <= 0)
                {
                    cout << "Base must be greater than zero." << endl;
                }

            } while (first_value <= 0);

            do
            {
                cout << "Enter height: ";
                cin >> second_value;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    second_value = -1;
                }

                if (second_value <= 0)
                {
                    cout << "Height must be greater than zero." << endl;
                }

            } while (second_value <= 0);

            shape_array[i]->get_data(first_value, second_value);
        }
        else if (choice == 2)
        {
            shape_array[i] = new rectangle();

            do
            {
                cout << "Enter length: ";
                cin >> first_value;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    first_value = -1;
                }

                if (first_value <= 0)
                {
                    cout << "Length must be greater than zero." << endl;
                }

            } while (first_value <= 0);

            do
            {
                cout << "Enter width: ";
                cin >> second_value;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    second_value = -1;
                }

                if (second_value <= 0)
                {
                    cout << "Width must be greater than zero." << endl;
                }

            } while (second_value <= 0);

            shape_array[i]->get_data(first_value, second_value);
        }
        else
        {
            shape_array[i] = new circle();

            do
            {
                cout << "Enter radius: ";
                cin >> first_value;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    first_value = -1;
                }

                if (first_value <= 0)
                {
                    cout << "Radius must be greater than zero." << endl;
                }

            } while (first_value <= 0);

            shape_array[i]->get_data(first_value);
        }
    }

    cout << "\n----- Area of All Shapes -----" << endl;

    for (int i = 0; i < number_of_shapes; i++)
    {
        shape_array[i]->display_area();
    }

    for (int i = 0; i < number_of_shapes; i++)
    {
        delete shape_array[i];
    }

    return 0;
}

