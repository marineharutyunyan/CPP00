#include "FragTrap.hpp"

int main ()
{
    FragTrap fragTrap("A");
    fragTrap.attack("B");
    fragTrap.beRepaired(5);
    fragTrap.takeDamage(5);
    fragTrap.highFivesGuys();
    fragTrap.printState();
    return 0;
}