#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", 25, 5) {
    _target = target;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) {
    _target = obj._target;
};

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj) {
        _target = obj._target;
    }
    return (*this);
};

void PresidentialPardonForm::action() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};