/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:31 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/29 18:24:04 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
# include <string>

class PhoneBook
{
    private:
		Contact _contacts[8];
		int _nextIndex;
		std::string _firstName;
    	std::string _surnameName;
    	std::string _nickName;
    	std::string _phoneNumber;
    	std::string _darkestSecret;
		
    public:
        PhoneBook() {};
        ~PhoneBook() {};
		void  addContact(void);
		std::string getInput(std::string message);
		// void searchContact(void);
	
};

#endif
