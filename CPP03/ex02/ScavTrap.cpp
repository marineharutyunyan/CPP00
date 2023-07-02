#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructer called " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructer called " << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &obj) : ClapTrap(obj) 
{

}

void ScavTrap::operator=(const ScavTrap &obj)
{
    ClapTrap::operator=(obj);
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints -= 1;
        std::cout << "ScavTrap " <<  _name  <<  " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap is now in Gate keeper mode. " << std::endl;
}
