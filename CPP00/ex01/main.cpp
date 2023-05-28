#include "PhoneBook.hpp"
#include <iostream>

int main() {

    PhoneBook phoneBook;
    std::string command;

    while (true)
    {    
        std::cout << "Enter the command (ADD, SEARCH or EXIT)" << std::endl;
        std::getline(std::cin , command);
        if (std::cin.good() == false)
        {
            return 0;
        }
        if(command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "EXIT command called" <<  std::endl;
            return 0;
        }
        else
        {
            std::cout << "Wrong command!" << std::endl;
        }
    }
    return 0;
}