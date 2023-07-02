#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructer called " << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructer called " << std::endl;
}

FragTrap::FragTrap(FragTrap &obj) : ClapTrap(obj) 
{

}

void FragTrap::operator=(const FragTrap &obj)
{
    ClapTrap::operator=(obj);
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints -= 1;
        std::cout << "FragTrap " <<  _name  <<  " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "Hello highFivesGuys " << std::endl;
}