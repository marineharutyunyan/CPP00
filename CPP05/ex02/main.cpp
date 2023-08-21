#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{   
    try
    {
        {
            Bureaucrat obj1(10, "Buro1");
            std::cout << obj1 << std::endl;
            PresidentialPardonForm fobj("fornmane");
            obj1.executeForm(fobj);
            obj1.signForm(fobj);
            obj1.executeForm(fobj);
        }
        {
            Bureaucrat obj1(140, "Buro1");
            std::cout << obj1 << std::endl;
            ShrubberyCreationForm fobj("fornmane");
            obj1.executeForm(fobj);
            obj1.signForm(fobj);
            obj1.executeForm(fobj);
        }
        {
            Bureaucrat obj1(60, "Buro1");
            std::cout << obj1 << std::endl;
            RobotomyRequestForm fobj("fornmane");
            obj1.executeForm(fobj);
            obj1.signForm(fobj);
            obj1.executeForm(fobj);
        }
        //std::cout << obj1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}