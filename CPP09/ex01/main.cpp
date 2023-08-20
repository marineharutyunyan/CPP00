#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc == 2)
    {
        try
        {
            RPN::calculate(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        std::cout << "Wrong number of arguments" << std::endl;
    }
    
   
    return 0;
}