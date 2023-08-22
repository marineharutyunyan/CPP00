#include "Base.hpp"
#include <random>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    
    srand(time(NULL));
    int randNum = rand() % 3;
    if (randNum == 1)
    {
        return (new B);
    }
    else if (randNum == 2)
    {
        return (new C);
    }
    else
    {
        return (new A);
    }
}

void identify(Base* p) {
    
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;  
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Wrong name" << std::endl;
    }
};

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch(const std::exception& e)
    {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch(const std::exception& e)
    {
    }
    try {
       (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch(const std::exception& e) {
    }
};

int main() {
    Base *        obj;
    obj = generate();
    identify(obj);
    identify(*obj);
    return 0;
}