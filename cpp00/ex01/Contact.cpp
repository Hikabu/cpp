/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:05 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/05/03 02:53:11 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
void Contact::setIndex(int i)
{
	Contact::_index = i;
}

void Contact::showIndex(int i) const
{
	if(_firstName.empty() || _surnameName.empty() || _nickName.empty())
		return ;
	std::cout << "\033[35m" << "        Here we go   " << std::endl;
	std::cout << "\033[32m" << "--->> Contact № " << i << "----" << std::endl;
	std::cout << "\033[36m" <<"Frist Name: " << _firstName << std::endl;
	std::cout << "Surname: " << _surnameName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phonenumber: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret <<  "\033[37m"   << std::endl;
}