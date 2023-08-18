#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    AForm *makeForm(const std::string &name, const std::string &target);
};

#endif