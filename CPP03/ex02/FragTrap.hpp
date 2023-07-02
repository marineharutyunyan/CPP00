#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include <iostream>
# include "ClapTrap.hpp"

class ClapTrap;

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap &obj);
        void operator=(const FragTrap &obj);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
    private:
        FragTrap();

};

# endif