#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : AMateria
{   private: 
        std::string _type;
    public:
    Cure();
    Cure(const Cure &obj);
    Cure& operator=(const Cure &obj);
    ~Cure();
    Cure* clone() const;
    void use(ICharacter& target);
};