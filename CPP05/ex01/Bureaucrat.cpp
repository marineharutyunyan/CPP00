#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat constructor called" << std::endl;
}
   
Bureaucrat::~Bureaucrat()
{
   std::cout << "Bureaucrat destuctor called" << std::endl;
}

Bureaucrat::Bureaucrat(const int grade, const std::string &name) : _name(name)
{
    if (grade < 1)
    {
        Bureaucrat::GradeError err;
        err.setErrorTex("Grade is too high exception");
        throw (err);
    }
    if(grade > 150)
    {
        Bureaucrat::GradeError err;
        err.setErrorTex("Grade is too low exception");
        throw (err);
    }
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
    return _grade;
}

void Bureaucrat::setGrade(const int grade)
{
   _grade = grade;
}

const char * Bureaucrat::GradeError::what() const throw()
{
    return  Bureaucrat::GradeError::_errorText.c_str();
}

void Bureaucrat::GradeError::setErrorTex(const std::string &errorTex)
{
    _errorText = errorTex;
}

Bureaucrat::GradeError::~GradeError() throw() {};

void Bureaucrat::increment()
{
    if (_grade <= 1)
    {
        Bureaucrat::GradeError err;
        err.setErrorTex("Grade is too high exception");
        throw (err);
    }
    _grade--;
}

void Bureaucrat::decrement()
{   
    if(_grade >= 150)
    {
        Bureaucrat::GradeError err;
        err.setErrorTex("Grade is too low exception");
        throw (err);
    }
    _grade++;
}

void Bureaucrat::signForm(Form &obj)
{
    try {
        obj.beSigned(*this);
        std::cout << this->getName() << " signed " << obj.getName() << std::endl;
    } catch (const  Form::GradeError& e) 
    {
        std::cout << this->getName() << " couldn’t sign " << obj.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
};