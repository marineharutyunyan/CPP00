#include "Bureaucrat.hpp"

int main()
{ try
    {
        Bureaucrat obj("MM", 1);
        obj.increment();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}