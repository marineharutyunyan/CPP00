#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <exception>

class Form
{
    public:
        Form();
        Form(const bool _sign, const std::string &name);
        Form(const Form &obj);
        ~Form();
        Form& operator=(const Form &obj);
        std::string getName() const;
        int getSign() const;
        void setSign(const bool _sign);

    private:
        const std::string _name;
        bool _sign;
        const int gradeForSign;
        const int gradeForExec;
        
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif