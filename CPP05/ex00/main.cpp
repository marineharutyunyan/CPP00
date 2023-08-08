#include "Bureaucrat.hpp"

int main()
{   
    try
    {
        Bureaucrat obj(150, "MM");
        std::cout << obj << std::endl;
        // obj.increment();
        obj.decrement();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}