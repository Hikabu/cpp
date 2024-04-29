/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:25 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/29 18:19:59 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact(void)
{  
    std::string str;

	_firstName = getInput("your firstName is ");
    _surnameName = getInput("your surName is ");
    _nickName = getInput("your nickName is ");
    _phoneNumber = getInput("your phoneNumber is ");
    _darkestSecret = getInput("your darkestSecret is ");
    std::cout << "Contact has been added" << std::endl;      
}

std::string PhoneBook::getInput(std::string message)
{
    std::string str;
    do
    {
		std::cout << message;
		std::getline(std::cin, str);
		if (std::cin.eof())
			exit (1);
		if (str.empty())
			std::cout << "I can not see any data. Please, try again." << std::endl;
	}	while (str.empty());
	return (str);
}