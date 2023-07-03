#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* a = new Dog();
    const Animal* b = new Dog();
    const Animal* c = new Dog();
    const Animal* d = new Cat();
    const Animal* e = new Cat();
    const Animal* animals[5] = {a, b, c, d, e};   

    for (int i =0; i< 5; i++)
    {
        delete (animals[i]);
    }
    // delete a;
    // delete b;
    // delete c;
    // delete d;
    // delete e;
    // delete[] animals;
    return 0;
}