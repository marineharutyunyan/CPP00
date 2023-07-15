#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{    
    _intNum = 0;
}

Fixed::Fixed(const int num)
{    
	_intNum = num * pow(2,  _fractionalBits);
}

Fixed::Fixed(const float num)
{    
    _intNum = roundf(num * pow(2, _fractionalBits));
}

Fixed::~Fixed()
{}

Fixed::Fixed(const Fixed &obj)
{
    _intNum = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &obj)
{
    if(this != &obj)
    {
        _intNum = obj.getRawBits();    
    }
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

bool Fixed::operator>(const Fixed &obj) const {
	return (this->getRawBits() > obj.getRawBits());
};

bool Fixed::operator<(const Fixed &obj) const {
	return (this->getRawBits() < obj.getRawBits());
};

bool Fixed::operator>=(const Fixed &obj) const {
	return (this->getRawBits() >= obj.getRawBits());
};

bool Fixed::operator<=(const Fixed &obj) const {
	return (this->getRawBits() <= obj.getRawBits());
};

bool Fixed::operator==(const Fixed &fixed) const {
	return (this->getRawBits() == fixed.getRawBits());
};

bool Fixed::operator!=(const Fixed &obj) const {
	return (this->getRawBits() != obj.getRawBits());
};

Fixed Fixed::operator+(const Fixed &obj) const {
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() + obj.getRawBits());
	return (tmp);
};

Fixed Fixed::operator-(const Fixed &obj) const {
	Fixed tmp;
	tmp.setRawBits(this->getRawBits() - obj.getRawBits());
	return (tmp);
};

Fixed Fixed::operator*(const Fixed &obj) const {
	Fixed tmp;
	tmp.setRawBits(roundf(this->toFloat() * obj.toFloat() * (1 << _fractionalBits)));
	return (tmp);
};

Fixed Fixed::operator/(const Fixed &obj) const {
	Fixed tmp;
	tmp.setRawBits(roundf((this->toFloat() / obj.toFloat()) * (1 << _fractionalBits)));
	return (tmp);
};

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;

	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
};

Fixed Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
};

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
};

Fixed Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
};

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2) {
    return (obj1 > obj2 ? obj2 : obj1);
};

const Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2) {
    return (obj1 > obj2 ? obj2 : obj1);
};

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2) {
	return (obj1 > obj2 ? obj1 : obj2);
};

const Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2) {
	return (obj1 > obj2 ? obj1 : obj2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	std::cout << obj.toFloat();
	return (out);
};