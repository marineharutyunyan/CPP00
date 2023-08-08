#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <exception>

class Form
{
    public:
        Form();
        Form(const bool sign, const std::string &name, int gradeSign, int gradeExec);
        Form(const Form &obj);
        ~Form();
        Form& operator=(const Form &obj);
        std::string getName() const;
        int getSign() const;
        void setSign(const bool _sign);
        int getGradeExec() const;
        int getGradeSign() const;
        class GradeError : public std::exception
        {
            public:
                const char * what() const throw();
                void setErrorTex(const std::string &errorTex);
                virtual ~GradeError() throw();
            private:
                std::string _errorText;
        };
    private:
        const std::string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExec;
        
};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif