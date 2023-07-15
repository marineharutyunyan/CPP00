Cure() : _type("cure")
{

}
    Cure(const Cure &obj);
    Cure& operator=(const Cure &obj);
    ~Cure();
    Cure* clone() const;
    void use(ICharacter& target);