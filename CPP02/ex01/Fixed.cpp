#include "Fixed.hpp"
Fixed::Fixed()
{    
    std::cout << "Default constructor called" << std::endl;
    _intNum = 0;
}

Fixed::Fixed(const int num)
{    
    std::cout << "Parameterized constructor called" << std::endl;
    _intNum = num;
}

Fixed::Fixed(const float num)
{    
    std::cout << "Parameterized constructor called" << std::endl;
    _intNum = num;
}

Fixed::~Fixed()
{
   std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    _intNum = obj.getRawBits();

}

void Fixed::operator=(const Fixed &obj)
{
    if(this != &obj)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        _intNum = obj.getRawBits();
    }
}

const Fixed Fixed::operator<<(const Fixed &obj)
{
    if(this != &obj)
    {
        std::cout << "insertion operator called" << std::endl;
    }
    return obj;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _intNum;
}

void Fixed::setRawBits( int const raw )
{
    _intNum = raw;
}
