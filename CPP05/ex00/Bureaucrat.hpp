#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const int grade, const std::string &name);
        Bureaucrat(const Bureaucrat &obj);
        virtual ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &obj);
        std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
    private:
        const std::string _name;
        int _grade;
        class GradeError : public std::exception
        {
            public:
                GradeError(const std::string &message);
                virtual ~GradeError() throw();
                virtual const char* what() const throw();
                virtual void setMessage(const std::string &message);
            private:
                std::string m_message;
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif