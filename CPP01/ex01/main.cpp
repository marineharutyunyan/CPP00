#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombies = new Zombie[N];

    int i = 0;
    while (i < N)
    {
        zombies[i].setName(name);
        zombies[i].announce();
        i++;
    }
    return zombies;
}

int main ()
{
    Zombie *mertObj = zombieHorde(5,"Mert");
    delete  mertObj;
    return 0;
}