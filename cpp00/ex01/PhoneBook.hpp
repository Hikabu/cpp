/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:31 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/05/03 08:13:13 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"
# include <string>

class PhoneBook
{
    private:
		Contact _contacts[8];
		
    public:
        PhoneBook() {};
        ~PhoneBook() {};
		void  addContact(void);
		void  init(void);
		void  searchContact(void);
		void  print(void);
		std::string getInput(std::string message); 
};

#endif