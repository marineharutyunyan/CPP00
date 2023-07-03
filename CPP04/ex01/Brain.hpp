#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain &brain);
    Brain& operator=(const Brain &brain);
    ~Brain();
    std::string _ideas[100]; 
};

#endif