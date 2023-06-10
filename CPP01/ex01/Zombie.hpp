#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include<iostream>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void setName(std::string name);
        void announce( void );
    private:
        std::string _name;
};

#endif