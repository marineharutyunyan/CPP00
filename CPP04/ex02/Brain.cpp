#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain canstructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destuctor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    for(int i = 0; i < 100; i++)
    {
        _ideas[i] = brain._ideas[i];
    }
}

Brain& Brain::operator=(const Brain &brain)
{
    for(int i = 0; i < 100; i++)
    {
        _ideas[i] = brain._ideas[i];
    }
    return *this;
}
