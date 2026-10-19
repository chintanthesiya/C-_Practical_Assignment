
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ofstream output_file;
    ifstream input_file;
    ifstream read_file;
    ofstream copy_file;

    string file_name, copy_file_name;
    string line;
    string word;

    int word_count = 0;
    int line_count = 0;

    cout << "Enter file name: ";
    cin >> file_name;

    output_file.open(file_name.c_str());

    if (!output_file)
    {
        cout << "Error creating file!" << endl;
        return 1;
    }

    cin.ignore(10000, '\n');

    cout << "Enter content for the file." << endl;
    cout << "Enter END on a new line to finish:" << endl;

    while (getline(cin, line))
    {
        if (line == "END")
        {
            break;
        }

        output_file << line << endl;
    }

    output_file.close();

    cout << "\nContent written successfully." << endl;

    input_file.open(file_name.c_str());

    if (!input_file)
    {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\n----- File Content -----" << endl;

    while (getline(input_file, line))
    {
        cout << line << endl;
    }

    input_file.close();

    read_file.open(file_name.c_str());

    if (!read_file)
    {
        cout << "Error opening file for counting!" << endl;
        return 1;
    }

    while (getline(read_file, line))
    {
        line_count++;

        stringstream line_stream(line);

        while (line_stream >> word)
        {
            word_count++;
        }
    }

    read_file.close();

    cout << "\nTotal Lines: " << line_count << endl;
    cout << "Total Words: " << word_count << endl;

    cout << "\nEnter destination file name for copying: ";
    cin >> copy_file_name;

    if (file_name == copy_file_name)
    {
        cout << "Source and destination file names must be different."
             << endl;
        return 1;
    }

    input_file.open(file_name.c_str());
    copy_file.open(copy_file_name.c_str());

    if (!input_file || !copy_file)
    {
        cout << "Error opening source or destination file!" << endl;

        input_file.close();
        copy_file.close();

        return 1;
    }

    while (getline(input_file, line))
    {
        copy_file << line << endl;
    }

    input_file.close();
    copy_file.close();

    cout << "File copied successfully to "
         << copy_file_name << endl;

    return 0;
}

