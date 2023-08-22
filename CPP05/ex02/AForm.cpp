#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Name"), _sign(false), _gradeSign(1), _gradeExec(1) 
{
    std::cout << "AForm constructor called" << std::endl;
}
   
AForm::~AForm()
{
   std::cout << "AForm destuctor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec )
    : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{ 
    _sign = false;
    if (_gradeSign < 1 || _gradeExec < 1)
    {
        AForm::GradeError err;
        err.setErrorTex("Grade is too high exception");
        throw (err);
    }
    if(_gradeSign > 150 || _gradeExec > 150)
    {
        AForm::GradeError err;
        err.setErrorTex("Grade is too low exception");
        throw (err);
    }
}

AForm::AForm(const AForm &obj) : _name(obj._name), _sign(obj._sign), _gradeSign(obj._gradeSign), _gradeExec(obj._gradeExec)
{

}

AForm& AForm::operator=(const AForm &obj)
{
    _sign = obj._sign;
    return *this;
}

std::string AForm::getName() const
{
    return _name;
}

int AForm::getSign() const
{
    return AForm::_sign;
}

int AForm::getGradeSign() const
{
    return AForm::_gradeSign;
}

int AForm::getGradeExec() const
{
    return AForm::_gradeExec;
}

void AForm::setSign(const bool sign)
{
    AForm::_sign = sign;
}

void AForm::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() <= this->getGradeSign())
    {
        this->_sign = true;
    } else {
        AForm::GradeError err;
        err.setErrorTex("Grade is too low exception");
        throw (err);
    }
};

void AForm::check(Bureaucrat const & obj) const
{
    if (!(this->_sign == false))
    {
       throw (GradeError("Form is not signed to be executed!"));
    }
    
    if (obj.getGrade() <= this->_gradeExec)
    {
       throw (GradeError("Grade is to low to be executed."));
    }

};


void AForm::execute(Bureaucrat const & executor) const
{
    this->check(executor);
    this->action();
};


AForm::GradeError::GradeError( const std::string &errorTex ) {
    _errorText = errorTex;
};

AForm::GradeError::GradeError() {
};

const char * AForm::GradeError::what() const throw()
{
    return  AForm::GradeError::_errorText.c_str();
}

void AForm::GradeError::setErrorTex(const std::string &errorTex)
{
    _errorText = errorTex;
}

AForm::GradeError::~GradeError() throw() {};

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
	std::cout << "name: " << obj.getName() << ", Signe: " 
    << obj.getSign() << ",  GradeSign: " << obj.getGradeSign() 
    << ",  GradeSign: " <<  obj.getGradeExec();
	return (out);
};