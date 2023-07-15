#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include<iostream>

class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &obj);
        void operator=(const ClapTrap &obj);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    protected:
        ClapTrap();
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
};

#endif