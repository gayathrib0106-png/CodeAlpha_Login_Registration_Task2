#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool usernameExists(string username) {
    ifstream file("users.txt");

    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void registerUser() {
    string username, password;

    cout << "\n===== REGISTRATION =====\n";

    cout << "Enter Username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();

        cout << "Registration successful!\n";
    } else {
        cout << "Error opening users.txt!\n";
    }
}

void loginUser() {
    string username, password;
    string storedUsername, storedPassword;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    bool loginSuccessful = false;

    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            loginSuccessful = true;
            break;
        }
    }

    file.close();

    if (loginSuccessful) {
        cout << "\nLogin successful!\n";
        cout << "Welcome, " << username << "!\n";
    } else {
        cout << "\nInvalid username or password!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n============================\n";
        cout << " LOGIN & REGISTRATION SYSTEM\n";
        cout << "============================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}