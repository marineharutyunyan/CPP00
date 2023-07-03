#include "Animal.hpp"

Animal::~Animal()
{
   std::cout << "Animal destuctor called" << std::endl;
}

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
}
      
Animal::Animal(const std::string &type)
{
    _type = type;
}

Animal::Animal(const Animal &obj)
{
    _type = obj._type;
}

 Animal& Animal::operator=(const Animal &obj)
{
    _type = obj._type;
    return *this;
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "Animal's sound" << std::endl; 
}