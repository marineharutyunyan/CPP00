#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &obj);
        void operator=(const Fixed &obj);
        ~Fixed();
        void setRawBits( int const raw );
        int getRawBits( void ) const;
    private:
        int _intNum;
        static const int _fractionalBits = 8;
};      

#endif