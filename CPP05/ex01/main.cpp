#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{   
    try
    {
        //Bureaucrat obj(150, "MM");
        //std::cout << obj << std::endl;
        // obj.increment();
        //obj.decrement();
        //Bureaucrat obj1(15, "Buro1"); 
        Bureaucrat obj1(55, "Buro1");
        std::cout << obj1 << std::endl;
        Form fobj("fornmane", 45, 10);
        obj1.signForm(fobj);
        std::cout << fobj << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}