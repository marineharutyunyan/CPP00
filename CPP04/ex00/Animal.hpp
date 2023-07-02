#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include<iostream>

class Animal
{
    public:
        Animal();
        Animal(const std::string &type);
        Animal(const Animal &obj);
        virtual ~Animal();
        Animal& operator=(const Animal &obj);
        std::string getType() const;
        virtual void makeSound() const;
    protected:
        std::string _type;
};

#endif