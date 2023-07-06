#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal("Cat"), _brain(new Brain())
{
    std::cout << "Cat constuctor called" << std::endl;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat destuctor called" << std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat)
{}

Cat& Cat::operator=(const Cat &cat)
{
    Animal::operator=(cat);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl; 
}