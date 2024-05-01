/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:31 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/05/01 16:33:48 by vfedorov         ###   ########.fr       */
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
		// void searchContact(void);
	
};

#endif