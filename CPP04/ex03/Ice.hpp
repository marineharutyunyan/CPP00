#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : AMateria
{
    private: 
        std::string _type;
    public:
    Ice();
    Ice(const Ice &obj);
    Ice& operator=(const Ice &obj);
    ~Ice();
    Ice* clone() const;
    void use(ICharacter& target);
};