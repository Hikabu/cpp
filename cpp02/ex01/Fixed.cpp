#include "Fixed.hpp"

//default constructor 
Fixed::Fixed() // initialize in the constructor
{
    this->_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

//copy construtor 
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_value = fixed.getRawBits();
}
//int constructor 
Fixed::Fixed(const int value )
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_bit;
}

// float constructor 
Fixed::Fixed (const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value  * (1 << this->_bit)); // scaling factor for d.p
}

//copy assignment constructor 
Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = fixed.getRawBits();
    return (*this);
}

//copy insertion 

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return (out);
}

//destructor 
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
float  Fixed::toFloat ( void ) const{
    return ((float)this->_value / (float)(1 << this->_bit));
}

//by right shift operation
int Fixed::toInt ( void ) const {
    return (this->_value >> this->_bit);
}

int Fixed::getRawBits(void) const { return _value; }

void Fixed::setRawBits(int const raw) { _value = raw;}
