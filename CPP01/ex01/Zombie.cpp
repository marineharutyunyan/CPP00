#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
   std::cout << _name << " destuctor called" << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}

void Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}