#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat()
{
   std::cout << "Bureaucrat destuctor called" << std::endl;
}

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat constructor called" << std::endl;
}
      
Bureaucrat::Bureaucrat(const int grade, const std::string &name) : _name(name)
{ 
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) :_name(obj._name), _grade(obj._grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
    _grade = obj._grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return Bureaucrat::_grade;
}

void Bureaucrat::setGrade(const int grade)
{
    Bureaucrat::_grade = grade;
}

const char * Bureaucrat::GradeError::what() const throw()
{
    return  _errorText.c_str();
}

void Bureaucrat::GradeError::setErrorTex(const std::string &errorTex)
{
    Bureaucrat::GradeError::_errorText = errorTex;
}

void Bureaucrat::increment()
{
    Bureaucrat::_grade--;
    try {
        if (Bureaucrat::_grade < 1)
        {
            Bureaucrat::GradeError err;
            err.setErrorTex("Grade is too high exception");
            throw(Bureaucrat::GradeError());
        }
        if(Bureaucrat::_grade > 150)
        {
            Bureaucrat::GradeError err;
            err.setErrorTex("Grade is too high exception");
            throw(err);
        }
    } catch(Bureaucrat::GradeError e) {
        e.what();
    }
}

void Bureaucrat::decrement()
{   
    Bureaucrat::_grade++;
    try {
        if (Bureaucrat::_grade < 1)
        {
            Bureaucrat::GradeError err;
            err.setErrorTex("Grade is too high exception");
            throw err;
        }
        if(Bureaucrat::_grade > 150)
        {
            Bureaucrat::GradeError err;
            err.setErrorTex("Grade is too high exception");
            throw err;
        }
    } catch(Bureaucrat::GradeError e) {
        e.what();
    }
}