#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _intNum(0)
{    
    std::cout << "Default constructor called" << std::endl;
    
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
	_intNum = num * pow(2,  _fractionalBits);
}

Fixed::Fixed(const float num)
{    
    std::cout << "Float constructor called" << std::endl;
    _intNum = roundf(num * pow(2, _fractionalBits));
}

Fixed::~Fixed()
{
   std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    _intNum = obj._intNum;

}

Fixed& Fixed::operator=(const Fixed &obj)
{
    _intNum = obj._intNum;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    return _intNum;
}

void Fixed::setRawBits( int const raw )
{
    _intNum = raw;
}

float  Fixed::toFloat( void ) const
{
	return (static_cast <float> (getRawBits()) / pow(2, _fractionalBits));
}

int  Fixed::toInt( void ) const
{
    return (this->getRawBits() / pow(2, _fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	std::cout << obj.toFloat();
	return (out);
};