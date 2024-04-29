/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:05 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/29 16:48:45 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
// #include "PhoneBook.hpp"

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
