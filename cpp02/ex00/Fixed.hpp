/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:47:33 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/07/21 05:18:53 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
// #include <ieee754.h>
# include <iostream>

// Orthodox Canonical Form
class Fixed
{
    private:
        int _value;
        static const int _bits = 8;
        
    public:
        Fixed (); // default constructor but not allocate 
        Fixed (const Fixed &fixed); // copy create new object by b(a)
        const Fixed &operator = (const Fixed &fixed); // corretly copy to another  existing object
        ~Fixed (); //just destructor 

        int getRawBits( void ) const;
        void setRawBits (int const raw);
};

#endif