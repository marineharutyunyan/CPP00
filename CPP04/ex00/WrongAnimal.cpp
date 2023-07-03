#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
   std::cout << "WrongAnimal destuctor called" << std::endl;
}
      
WrongAnimal::WrongAnimal(const std::string &type)
{
    _type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    _type = obj._type;
}

 WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
    _type = obj._type;
    return *this;
}

std::string WrongAnimal::getType() const
{
    return _type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal's sound" << std::endl; 
}