#pragma once
#include <iostream>

class Contact {
    public:
        void setFirstName(const std::string &firstName);
        std::string getFirstName() const;
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
};