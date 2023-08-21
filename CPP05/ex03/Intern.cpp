#include "Intern.hpp"

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {
    return (new RobotomyRequestForm(target));
};

AForm *Intern::makePresidentialPardonForm(const std::string &target) {
    return (new PresidentialPardonForm(target));
};

AForm *Intern::makeShrubberyCreationForm(const std::string &target) {
    return (new ShrubberyCreationForm(target));
};


AForm * Intern::makeForm(const std::string &name, const std::string &target)
{
    const int formCount = 3;
    std::string formNames[formCount] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    std::cout << "Intern creates " << name << std::endl;
    AForm *(Intern::*forms[formCount])(const std::string &target);

    forms[0] = &Intern::makeShrubberyCreationForm;
    forms[1] = &Intern::makePresidentialPardonForm;
    forms[2] = &Intern::makeRobotomyRequestForm;

    for (int i = 0; i < formCount; i++) {
        if (name == formNames[i]) {
            return ((this->*forms[i])(target));
        }
    }
    std::cout << "nameForm does not match any form" << std::endl;
    return (NULL);
}