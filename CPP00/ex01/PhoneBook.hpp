#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();
        
        void addContact();
        void searchContact();
    private:
        int _maxContactsNum;
        int _curIndex;
        Contact _contacts[8];
};

#endif