#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal("Dog"), _brain(new Brain())
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog destuctor called" << std::endl;
}

Dog::Dog(const Dog &dog): Animal(dog)
{
    _brain = new Brain(*dog._brain);
}

Dog& Dog::operator=(const Dog &dog)
{
    Animal::operator=(dog);
    *_brain = *dog._brain;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl; 
}

