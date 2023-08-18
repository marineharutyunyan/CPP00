#include "Intern.hpp"

AForm * Intern::makeForm(const std::string &name, const std::string &target)
{
    int i;
	std::string formsList[] = {"robotomy request", "presidental pardon",  "shrubbery creation"};
    AForm *form = NULL; 

	for(i = 0; formsList[i] != name && i < 3; i++)
    {}

    switch (i)
    {
        case 0:
            form = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            break;
        case 1:
            form = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            break;
        case 2:
            form = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            break;
        default:
            std::cout << "Form name is wrong." << std::endl;
            break;
    }

    return form;
}