#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a new user
void registerUser()
{
    string username, password;
    
    cout << "\n===== REGISTRATION =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Check whether the username already exists
    ifstream file("users.txt");
    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username)
        {
            cout << "\nUsername already exists!\n";
            file.close();
            return;
        }
    }

    file.close();

    // Store the new user's credentials
    ofstream outFile("users.txt", ios::app);
    outFile << username << " " << password << endl;
    outFile.close();

    cout << "\nRegistration successful!\n";
}

// Function to login an existing user
void loginUser()
{
    string username, password;
    string storedUsername, storedPassword;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    // Read stored credentials and verify the user
    ifstream file("users.txt");

    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == username && storedPassword == password)
        {
            cout << "\nLogin successful!\n";
            cout << "Welcome, " << username << "!\n";
            file.close();
            return;
        }
    }

    file.close();

    cout << "\nInvalid username or password!\n";
}

// Main function
int main()
{
    int choice;

    cout << "========================================\n";
    cout << "      LOGIN & REGISTRATION SYSTEM\n";
    cout << "========================================\n";

    while (true)
    {
        cout << "\n1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {
            loginUser();
        }
        else if (choice == 3)
        {
            cout << "\nThank you for using the system!\n";
            break;
        }
        else
        {
            cout << "\nInvalid choice! Please select 1, 2, or 3.\n";
        }
    }

    return 0;
}