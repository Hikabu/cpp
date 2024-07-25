/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:47:28 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/07/22 16:34:19 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

 Fixed::Fixed():_value(0) // member initializer list
 {
    std::cout << "Default constructor called" << std::endl;
 }
 
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = fixed.getRawBits();
    
}
 Fixed::~Fixed()
 {
    std::cout << "Destructor called" << std::endl;
 }
 
 const Fixed &Fixed::operator=(const Fixed &fixed)
 {
    std::cout << "Copy assign operator" << std::endl;
    this->_value = fixed.getRawBits();
    return (*this);
 } 
 
 int Fixed::getRawBits( void ) const
 {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
 }
 
 void Fixed::setRawBits(int const raw)
 {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
 }
 

 