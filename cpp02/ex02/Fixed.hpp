#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
#include <cmath>

class Fixed{
    private:
        int _value;
        static const int _bit = 8;
    
    public:
        Fixed();
        Fixed (const Fixed &fixed);
        Fixed (const int value );
        Fixed ( const float value);
        Fixed &operator = (const Fixed &fixed);
        ~Fixed();

        float toFloat(void) const;
        int toInt( void ) const;
        int getRawBits( void) const;
        void setRawBits( int const raw);

        //operators
        Fixed operator + ( const Fixed &value ) const;
        Fixed operator - ( const Fixed &value ) const;
        Fixed operator / ( const Fixed &value ) const;
        Fixed operator * ( const Fixed &value ) const;

        Fixed operator ++ (); //prefix
        Fixed operator ++ (int ); //postfix
        Fixed operator -- (); 
        Fixed operator -- (int ); 

        //comparison operators 
        bool    operator < ( const Fixed &value) const;
        bool    operator > ( const Fixed &value) const;
        bool    operator <= ( const Fixed &value) const;
        bool    operator >= ( const Fixed &value) const;
        bool    operator != ( const Fixed &value) const;
        bool    operator == ( const Fixed &value) const;

        //max/min functions

        static Fixed        &min(Fixed &a, Fixed &b);
        static const Fixed  &min(Fixed const &a, Fixed const &b);
        static Fixed        &max(Fixed &a, Fixed &b);
        static const Fixed  &max(Fixed const &a, Fixed const &b);
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed ); // should be global for output

#endif