#include "ScavTrap.hpp"

int main ()
{
    ScavTrap scavTrap("A");
    scavTrap.attack("B");
    scavTrap.beRepaired(5);
    scavTrap.takeDamage(5);
    scavTrap.guardGate();
    return 0;
}