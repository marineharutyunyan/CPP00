#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _curIndex(0) {
    _maxContacts = 0;
    _filledIndex = 0;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::addContact()
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    if(_curIndex >= 8)
    {
        _curIndex = 0;
    }
    std::cout << "Enter first name" << std::endl;
    std::getline(std::cin , firstName);
    while(firstName.empty())
    {
        std::cout << "First name can't be empty" << std::endl;
        std::getline(std::cin , firstName);
    }
    _contacts[_curIndex].setFirstName(firstName);

    std::cout << "Enter last name" << std::endl;
    std::getline(std::cin ,lastName);
    while(lastName.empty())
    {
        std::cout << "Last name can't be empty" << std::endl;
        std::getline(std::cin ,lastName);
    }
    _contacts[_curIndex].setLastName(lastName);



    std::cout << "Enter nick name" << std::endl;
    std::getline(std::cin ,nickName);
    while(nickName.empty())
    {
        std::cout << "Nick name can't be empty" << std::endl;
        std::getline(std::cin ,nickName);
    }
    _contacts[_curIndex].setNickName(nickName);



    std::cout << "Enter phone number" << std::endl;
    std::getline(std::cin ,phoneNumber);
    while(phoneNumber.empty())
    {
        std::cout << "Phone number can't be empty" << std::endl;
        std::getline(std::cin ,phoneNumber);
    }
    _contacts[_curIndex].setPhoneNumber(phoneNumber);


 
    std::cout << "Enter darkest secret" << std::endl;
    std::getline(std::cin ,darkestSecret);
    while(darkestSecret.empty())
    {
        std::cout << "Darkest secret can't be empty" << std::endl;
        std::getline(std::cin ,darkestSecret);
    }
    _contacts[_curIndex].setDarkestSecret(darkestSecret);

    std::cout << "Contact succssesfully added" <<  std::endl;
    if(_maxContacts < 8)
    {
        _maxContacts++;
    }
    _curIndex++;
    if(_filledIndex < 8)
    {
        _filledIndex++;
    }
}

std::string truncated(std::string str)
{
    if(str.length() > 10)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::searchContact()
{
    std::cout << std::right;
    std::cout << std::setw(10) << "Index" << " | " << std::setw(10) << "First Name" << " | " << std::setw(10) << "Last Name" << " | " << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    int i;
    i = 0;
    while (i < _maxContacts)
    {
        std::cout << std::setw(10) << i << " | "
        << std::setw(10) << truncated(_contacts[i].getFirstName()) << " | "
        << std::setw(10) << truncated(_contacts[i].getLastName()) << " | "
        << std::setw(10) << truncated(_contacts[i].getNickName()) << std::endl;
        i++;
    }
    std::cout << std::string(50, '-') << std::endl;
    std::string strIndex;
    std::cout << "Enter the index of the contact to display: ";
    getline(std::cin , strIndex);
    char *endPtr;
    int index = std::strtol(strIndex.c_str(), &endPtr, 10);
    if (*endPtr == '\0'  && !strIndex.empty() && index >= 0 && index < _filledIndex)
    {
        std::cout << "Index: " << index << std::endl;
        std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
    }
    else 
    {
        std::cout << "Invalid index." << std::endl;
    }
}



