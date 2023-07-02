#include "ClapTrap.hpp"

int main ()
{
    ClapTrap clapTrap("A");
    clapTrap.attack("B");
    clapTrap.beRepaired(5);
    clapTrap.takeDamage(5);
    clapTrap.printState();
    return 0;
}