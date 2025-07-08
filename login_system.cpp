#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if username already exists
bool isUsernameTaken(string username) {
    ifstream file("users.txt");
    string fileUsername, filePassword;
    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username) {
            return true;
        }
    }
    return false;
}

// Registration Function
void registerUser() {
    string username, password;

    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    // Check for duplicate
    if (isUsernameTaken(username)) {
        cout << "Error: Username already taken. Try another.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Save to file
    ofstream file("users.txt", ios::app); // append mode
    file << username << " " << password << endl;

    cout << "Registration successful!\n";
}

// Login Function
void loginUser() {
    string username, password;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string fileUsername, filePassword;

    while (file >> fileUsername >> filePassword) {
        if (fileUsername == username && filePassword == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Login failed: Invalid username or password.\n";
    }
   }
int main() {
    int choice;
    do {
        cout << "\n=== Login & Registration System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}