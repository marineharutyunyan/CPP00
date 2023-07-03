#include "Brain.hpp"

Brain::Brain()
{
}

Brain::~Brain()
{
}

Brain::Brain(const Brain &brain)
{
    _ideas = &brain._ideas;
}

Brain& Brain::operator=(const Brain &brain)
{
    _ideas = &brain._ideas;
    return *this;
}
