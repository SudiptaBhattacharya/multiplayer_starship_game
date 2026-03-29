#include "../include/Menu.h"
#include <filesystem>

int main() {
    // std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    std::string userName;
    std::cout << "Enter your user name: " << std::endl;
    std::cin >> userName;

    // std::string userName;
    // std::cout << "Enter a string: ";
    // std::getline(std::cin, userName);
    bool isValid = false;
    for (char c : userName) {
        if (!std::isalpha(c)) {
            isValid = false;
        } else {
            isValid = true;
        }
    }
    while (!isValid) {
        std::cout << "Nice try! Enter a character string: " << std::endl;
        std::getline(std::cin, userName);
        for (char c : userName) {
            if (!std::isalpha(c)) {
                isValid = false;
            } else {
                isValid = true;
            }    
        }
    }
    
    Menu menu(500,500, userName);
    menu.renderMenu();
    return 0;
}