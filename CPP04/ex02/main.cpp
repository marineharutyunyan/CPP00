#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // const Animal animal;
    const Animal* a = new Dog();
    const Animal* c = new Dog();
    const Animal* e = new Cat();
    const Animal* animals[3] = {a, c, e};   

    for (int i =0; i< 3; i++)
    {
        delete (animals[i]);
    }
    return 0;
}