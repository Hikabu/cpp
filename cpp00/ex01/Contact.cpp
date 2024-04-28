/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:05 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 19:11:06 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{

}

std::string getInput(std::string message)
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
