#include "Fixed.hpp"

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

//operators

Fixed	Fixed::operator+(const Fixed &value) const {return Fixed(this->toFloat() + value.toFloat());}
Fixed	Fixed::operator-(const Fixed &value) const {return Fixed(this->toFloat() - value.toFloat());}
Fixed	Fixed::operator*(const Fixed &value) const {return Fixed(this->toFloat() * value.toFloat());}
Fixed	Fixed::operator/(const Fixed &value) const {return Fixed(this->toFloat() / value.toFloat());}

Fixed	Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed	Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed	Fixed::operator++(int) //dummy parameter for postfix
{
	Fixed tmp(*this);
	tmp._value = this->_value++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	tmp._value = this->_value--;
	return (tmp);
}

//comparison operators

bool	Fixed::operator<(const Fixed &value) const { return this->getRawBits() < value.getRawBits(); }
bool	Fixed::operator>(const Fixed &value) const { return this->getRawBits() > value.getRawBits(); }
bool	Fixed::operator<=(const Fixed &value) const { return this->getRawBits() <= value.getRawBits(); }
bool	Fixed::operator>=(const Fixed &value) const { return this->getRawBits() >= value.getRawBits(); }
bool	Fixed::operator!=(const Fixed &value) const { return this->getRawBits() != value.getRawBits(); }
bool	Fixed::operator==(const Fixed &value) const { return this->getRawBits() == value.getRawBits(); }

//max min functions

Fixed &Fixed::min(Fixed &a, Fixed &b) {return (a > b) ? b : a;}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {return (a > b) ? b : a;} 
Fixed &Fixed::max(Fixed &a, Fixed &b) {return (a > b) ? a : b;}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {return (a > b) ? a : b;} 

