#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << _name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << _name << " Constructor  with parameter called" << std::endl;
}

ClapTrap::~ClapTrap()
{
   std::cout << _name << " destuctor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    _name = obj._name;
    _hitPoints = obj._hitPoints;
    _energyPoints = obj._energyPoints;
    _attackDamage = obj._attackDamage;
}

void ClapTrap::operator=(const ClapTrap &obj)
{
    if(this != &obj)
    {
        _name = obj._name;
        _hitPoints = obj._hitPoints;
        _energyPoints = obj._energyPoints;
        _attackDamage = obj._attackDamage;
    }
}
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints -= 1;
        std::cout << "ClapTrap " <<  _name  <<  " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
   
    _hitPoints -= amount;
    std::cout << "ClapTrap " <<  _name  <<  " lost " << amount << " hit points " << std::endl;;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    _hitPoints += amount; 
    std::cout << "ClapTrap " <<  _name  <<  " repaired " << amount << " hit point " << std::endl;;
}