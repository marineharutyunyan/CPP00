#include "Contact.hpp"

void Contact::setFirstName(const std::string &firstName)
{
    std::cout << "Enter firstname " <<  std::endl;
    _firstName = firstName;
}

std::string Contact::getFirstName () const
{
    return _firstName;
}