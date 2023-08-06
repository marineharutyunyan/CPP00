#include "Form.hpp"

Form::Form()
{
    std::cout << "Form constructor called" << std::endl;
}
   
Form::~Form()
{
   std::cout << "Form destuctor called" << std::endl;
}

Form::Form(const bool sign, const std::string &name) : _name(name)
{ 
    _sign = sign;
}

Form::Form(const Form &obj) :_name(obj._name), _sign(obj._sign)
{

}

Form& Form::operator=(const Form &obj)
{
    _sign = obj._sign;
    return *this;
}

std::string Form::getName() const
{
    return _name;
}

int Form::getSign() const
{
    return Form::_sign;
}

void Form::setSign(const bool sign)
{
    Form::_sign = sign;
}

std::ostream &operator<<(std::ostream &out, const Form &obj) {
	std::cout << obj.getName();
	std::cout << obj.getSign();
	return (out);
};