#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{   
    try
    {
        Bureaucrat obj1(10, "Buro1");
        std::cout << obj1 << std::endl;
        PresidentialPardonForm fobj("fornmane"); //TODO check others
        obj1.executeForm(fobj);
        obj1.signForm(fobj);
        obj1.executeForm(fobj);
        //std::cout << fobj << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}