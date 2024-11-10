#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to write to a file (create if not exists)
void write(const string &filename)
{
    ofstream output(filename);
    if (!output)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "Enter text to write (type 'quit' to stop): " << endl;
    string text;
    while (true)
    {
        getline(cin, text);
        if (text == "quit" || text == "Quit")
        {
            break;
        }
        output << text << endl;
    }
    output.close();
}

// Function to append to a file (create if not exists)
void append(const string &filename)
{
    ofstream output(filename, ios::app);
    if (!output)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "Enter text to append (type 'quit' to stop): " << endl;
    string text;
    while (true)
    {
        getline(cin, text);
        if (text == "quit" || text == "Quit")
        {
            break;
        }
        output << text << endl;
    }
    output.close();
}

int main()
{
    int choice;
    string filename;

    do
    {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Write to a file" << endl;
        cout << "2. Append to a file" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left by cin

        switch (choice)
        {
        case 1:
            cout << "Enter filename to write to: ";
            getline(cin, filename);
            write(filename);
            break;
        case 2:
            cout << "Enter filename to append to: ";
            getline(cin, filename);
            append(filename);
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}