#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
}

Dog::~Dog()
{
    std::cout << "Dog destuctor called" << std::endl;

}

Dog::Dog(const Dog &dog): Animal(dog)
{

}

Dog& Dog::operator=(const Dog &dog)
{
    Animal::operator=(dog);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl; 
}

