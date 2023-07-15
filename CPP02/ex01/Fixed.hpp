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
        Fixed& operator=(const Fixed &obj);
        ~Fixed();
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