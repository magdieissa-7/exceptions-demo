#include <iostream>
#include <map>
#include <string>
#include "utils.hpp"

using namespace std;

int main() {
    map<string, string> users;
    bool logged_in = false;
    string current_user = "";
    int choice;

    while (true) {
        cout << "\nMenu:\n";

        if (!logged_in) {
            cout << "1. Sign up\n";
            cout << "2. Login\n";
        } else {
            cout << "3. Logout\n";
        }

        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (!logged_in && choice == 1) {
            string email, password;

            cout << "Enter your email: ";
            cin >> email;

            try {
                check_email(email);
            } catch (const invalid_argument& e) {
                cout << e.what() << "\n";
                continue;
            }

            cout << "Enter your password: ";
            cin >> password;

            users[email] = password;
            cout << "Sign up successful!\n";
        }
        else if (!logged_in && choice == 2) {
            string email, password;

            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> password;

            if (users.find(email) != users.end() && users[email] == password) {
                logged_in = true;
                current_user = email;
                cout << "Login successful!\n";
            } else {
                cout << "Invalid email or password.\n";
            }
        }
        else if (logged_in && choice == 3) {
            logged_in = false;
            current_user = "";
            cout << "Logged out successfully!\n";
        }
        else if (choice == 0) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
