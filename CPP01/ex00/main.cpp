#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    return new Zombie(name);
}
void randomChump( std::string name )
{
    Zombie zombie(name);
    zombie.announce();
}

int main ()
{
    Zombie *mertObj = newZombie("Mert");
    randomChump("Fort");
    mertObj->announce();
    delete mertObj;
    return 0;
}