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
        
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed ); // should be global for output

#endif