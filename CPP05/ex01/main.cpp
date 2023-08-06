#include "Bureaucrat.hpp"

int main()
{ try
    {
        Bureaucrat obj(1, "MM");
        obj.increment();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}