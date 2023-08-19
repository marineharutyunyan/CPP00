#include "Span.hpp"

int main( void ) {
    try
    {
        std::srand(unsigned(std::time(nullptr)));
        std::vector<int> v(1000);
        std::generate(v.begin(), v.end(), std::rand);
        Span sp = Span(1000);
        sp.fillSpan(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        // Span s(3);
        // s.addNumber(2);
        // s.addNumber(15);
        // // s.longestSpan();
        // //s.shortestSpan();
        // s.addNumber(16);
        // Span sp = Span(5);
        // sp.addNumber(6);
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
        // std::cout << sp.shortestSpan() << std::endl;
        // std::cout << sp.longestSpan() << std::endl;

        // Span s(10000);
        
        // int a[] = {16,2,77,29};
        // std::vector<int> avector (a, a + sizeof(a) / sizeof(int));
        // std::vector<int>::iterator it = avector.begin();
        // while (it != avector.end()) {
        //     std::cout << *it << ", ";
        //     ++it;
        // }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
    return 0;
}