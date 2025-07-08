🔐 Task 2 - Login and Registration System (C++)


---

🔎 Description

This is a simple Login and Registration System created in C++.
It allows users to register using a username and password, and later log in using those credentials. User data is stored in a text file.


💡 Features

Register new users (username + password)

Prevents duplicate usernames

Allows existing users to log in

Credentials are saved in users.txt file

Displays success and error messages



---

🛠️ Technologies Used

Language: C++

Concepts: File Handling, Strings, Loops, Conditionals, Input/Output



---

📥 How to Run

1. Copy the code below into a file named login_system.cpp


2. Open any C++ compiler like:

🔗 Programiz Online Compiler

CodeBlocks, Dev-C++, or VS Code



3. Compile and run the program




---

📌 Sample Output

=== Shreya's Login System ===
1. Register
2. Login
3. Exit
Enter your choice: 1
Enter new username: shreya
Enter new password: 1234
Registration successful!

=== Shreya's Login System ===
1. Register
2. Login
3. Exit
Enter your choice: 2
Enter username: shreya
Enter password: 1234
Login successful! Welcome, shreya!


---

📄 Output File

User data is saved to:

users.txt → contains lines like:
shreya 1234

> 🔒 For security, password hashing is recommended in real applications.




---

👩‍💻 Created by:

Shreya Parmar
C++ Intern @CodeAlpha


---

✅ Code: login_system.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    ifstream read("users.txt");
    string user, pass;
    while (read >> user >> pass) {
        if (user == username) {
            cout << "Username already exists!\n";
            return;
        }
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string user, pass;
    bool found = false;

    while (file >> user >> pass) {
        if (user == username && pass == password) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Login successful! Welcome, " << username << "!\n";
    else
        cout << "Invalid username or password.\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n=== Shreya's Login System ===\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            registerUser();
        else if (choice == 2)
            loginUser();
        else if (choice == 3)
            break;
        else
            cout << "Invalid choice.\n";
    }

    return 0;
}

