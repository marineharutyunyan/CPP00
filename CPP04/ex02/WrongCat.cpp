#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destuctor called" << std::endl;

}

WrongCat::WrongCat(const WrongCat &wrongcat): WrongAnimal(wrongcat)
{
   
}

WrongCat& WrongCat::operator=(const WrongCat &wrongcat)
{
    WrongAnimal::operator=(wrongcat);
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl; 
}