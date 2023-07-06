#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include<iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &obj);
        ~WrongAnimal();
        WrongAnimal& operator=(const WrongAnimal &obj);
        std::string getType() const;
        void makeSound() const;
    protected:
        std::string _type;
};

#endif