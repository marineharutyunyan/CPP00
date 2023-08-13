#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(const std::string &name, int gradeSign, int gradeExec);
        AForm(const AForm &obj);
        virtual ~AForm();
        AForm& operator=(const AForm &obj);
        std::string getName() const;
        int getSign() const;
        void setSign(const bool _sign);
        int getGradeExec() const;
        int getGradeSign() const;
        class GradeError : public std::exception
        {
            public:
                GradeError();
                GradeError(const std::string &errorTex);
                const char * what() const throw();
                void setErrorTex(const std::string &errorTex);
                virtual ~GradeError() throw();
            private:
                std::string _errorText;
        };
    void beSigned(Bureaucrat &obj);
    void check(Bureaucrat const & bobj) const;
    virtual void execute(Bureaucrat const & executor) const = 0;
	// virtual void inform() const = 0;
    private:
        const std::string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExec;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif