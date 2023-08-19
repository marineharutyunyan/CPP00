#include "easyfind.hpp"

int main( void ) {
    try
    {
        int a[] = {16,2,77,29};
        std::vector<int> avector (a, a + sizeof(a) / sizeof(int));
        int b = 22;
        ::easyfind(avector, b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
    return 0;
}