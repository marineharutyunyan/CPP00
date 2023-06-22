#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
}
ClapTrap::~ClapTrap()
{
   std::cout << _name << " destuctor called" << std::endl;
}

void attack(const std::string& target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);