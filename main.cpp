#include <iostream>
#include <map>
#include <string>
#include "utils.hpp"

using namespace std;

int main() {
    map<string, string> users;
    bool logged_in = false;
    int choice;
    string email, password;

    while (true) {
        cout << "\nMenu:\n";

        if (logged_in == false) {
            cout << "1. Sign up\n";
            cout << "2. Login\n";
        } else {
            cout << "3. Logout\n";
        }

        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 && logged_in == false) {
            cout << "Enter your email: ";
            cin >> email;

            try {
                check_email(email);
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
                continue;
            }

            cout << "Enter your password: ";
            cin >> password;

            users[email] = password;
            cout << "Sign up successful.\n";
        }
        else if (choice == 2 && logged_in == false) {
            cout << "Enter your email: ";
            cin >> email;

            cout << "Enter your password: ";
            cin >> password;

            if (users.find(email) != users.end() && users[email] == password) {
                logged_in = true;
                cout << "Login successful.\n";
            } else {
                cout << "Wrong email or password.\n";
            }
        }
        else if (choice == 3 && logged_in == true) {
            logged_in = false;
            cout << "Logout successful.\n";
        }
        else if (choice == 0) {
            cout << "Program ended.\n";
            break;
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
