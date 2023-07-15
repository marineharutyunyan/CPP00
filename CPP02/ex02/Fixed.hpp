#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &obj);
        ~Fixed();
        Fixed& operator=(const Fixed &obj);
        bool operator>(const Fixed &obj) const;
        bool operator<(const Fixed &obj) const;
        bool operator>=(const Fixed &obj) const;
        bool operator<=(const Fixed &obj) const;
        bool operator==(const Fixed &obj) const;
        bool operator!=(const Fixed &obj) const;
        Fixed operator+(const Fixed &obj) const;
        Fixed operator-(const Fixed &obj) const;
        Fixed operator*(const Fixed &obj) const;
        Fixed operator/(const Fixed &obj) const;
        Fixed operator++(int);
        Fixed operator++();
        Fixed operator--(int);
        Fixed operator--();
        static Fixed &min(Fixed &obj1, Fixed &obj2);
        static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
        static Fixed &max(Fixed &obj1, Fixed &obj2);
        static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
        void setRawBits( int const raw );
        int getRawBits( void ) const;
        float toFloat( void ) const;
        int toInt( void ) const;
    private:
        int _intNum;
        static const int _fractionalBits = 8;
};      

std::ostream& operator<<(std::ostream& out, const Fixed& obj);
#endif