#include "Form.hpp"

Form::Form() : _name("Default Name"), _sign(false), _gradeSign(1), _gradeExec(1) 
{
    std::cout << "Form constructor called" << std::endl;
}
   
Form::~Form()
{
   std::cout << "Form destuctor called" << std::endl;
}

Form::Form(const bool sign, const std::string &name, int gradeSign, int gradeExec )
    : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{ 
    _sign = sign;
    if (_gradeSign < 1 || _gradeExec < 1)
    {
        Form::GradeError err;
        err.setErrorTex("Grade is too high exception");
        throw (err);
    }
    if(_gradeSign > 150 || _gradeExec > 150)
    {
        Form::GradeError err;
        err.setErrorTex("Grade is too low exception");
        throw (err);
    }
}

Form::Form(const Form &obj) : _name(obj._name), _sign(obj._sign), _gradeSign(obj._gradeSign), _gradeExec(obj._gradeExec)
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

int Form::getGradeSign() const
{
    return Form::_gradeSign;
}

int Form::getGradeExec() const
{
    return Form::_gradeExec;
}

void Form::setSign(const bool sign)
{
    Form::_sign = sign;
}

const char * Form::GradeError::what() const throw()
{
    return  Form::GradeError::_errorText.c_str();
}

void Form::GradeError::setErrorTex(const std::string &errorTex)
{
    _errorText = errorTex;
}

Form::GradeError::~GradeError() throw() {};

std::ostream &operator<<(std::ostream &out, const Form &obj) {
	std::cout << obj.getName();
	std::cout << obj.getSign();
	std::cout << obj.getGradeSign();
	std::cout << obj.getGradeExec();
	return (out);
};