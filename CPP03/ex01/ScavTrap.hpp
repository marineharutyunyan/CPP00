#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include <iostream>
# include "ClapTrap.hpp"

class ClapTrap;

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap &obj);
        void operator=(const ScavTrap &obj);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
    private:
        ScavTrap();

};

# endif