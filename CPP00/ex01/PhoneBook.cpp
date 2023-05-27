#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
    _curIndex = 0;
    std::cout << "Constructor called." << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Destructor called. Cleaning up object." << std::endl;
}

void PhoneBook::addContact()
{
    std::string tmp;
    std::cout << "ADD command called" <<  std::endl;
    std::cin >> tmp;
    _contacts[_curIndex++].setFirstName(tmp);
    std::cout << "Contact succssesfuly added" <<  std::endl;
    std::cout << "The name is" << _contacts[_curIndex - 1].getFirstName() <<std::endl;
}

void PhoneBook::searchContact()
{
    std::cout << "SEARCH command called" << std::endl;
}