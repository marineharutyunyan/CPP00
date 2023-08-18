#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm ;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const int grade, const std::string &name);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &obj);
        std::string getName() const;
        int getGrade() const;
        void setGrade(const int grade);

        void increment();
        void decrement();
        class GradeError : public std::exception
        {
            public:
                const char * what() const throw();
                void setErrorTex(const std::string &errorTex);
                virtual ~GradeError() throw();
            private:
                std::string _errorText;
        };
        void executeForm(AForm const & obj);
        void signForm(AForm &obj);
    private:
        const std::string _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif