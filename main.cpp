#include <iostream>
#include "utils.hpp"

int main() {
    std::string email;

    while (true) {
        std::cout << "Enter your email: ";
        std::cin >> email;

        try {
            check_email(email);
            std::cout << "Valid email entered.\n";
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << " Try again.\n";
        }
    }

    return 0;
}

