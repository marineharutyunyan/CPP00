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
    GradeTooHighException 
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) :_name(obj._name), _grade(obj._grade)
{}

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

void Bureaucrat::increment()
{
    _grade--;
}

void Bureaucrat::decrement()
{   if (check())
    {
        _grade++;
    }
    throw

}

bool Bureaucrat::isTooHigh()
{
    if (_grade < 1)
    {
        return false;
    }
    return true;
}