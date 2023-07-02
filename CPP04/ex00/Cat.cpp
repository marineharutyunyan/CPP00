#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
}

Cat::~Cat()
{
    std::cout << "Cat destuctor called" << std::endl;

}

Cat::Cat(const Cat &cat): Animal(cat)
{
   
}

Cat& Cat::operator=(const Cat &cat)
{
    Animal::operator=(cat);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl; 
}