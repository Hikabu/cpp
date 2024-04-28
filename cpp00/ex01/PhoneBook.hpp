/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:31 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/24 14:00:02 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"
# include <string>

class PhoneBook
{
    private:
		Contact _contacts[8];
		int _nextIndex;
		std::string getInput(std::string message);
	
    public:
        PhoneBook() {};
        ~PhoneBook() {};
		void  addContact(void);
		void searchContact(void);
	
};

#endif
