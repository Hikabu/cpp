/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:25 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/05/01 17:00:19 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    PhoneBook::addContact(void)
{
    static int i;

    _contacts[i % 8].init();
    _contacts[i % 8].setIndex(i);
    i++;
}
void	Contact::init(void)
{  
    std::string str;

	_firstName = getInput("your firstName is ");
    _surnameName = getInput("your surName is ");
    _nickName = getInput("your nickName is ");
    _phoneNumber = getInput("your phoneNumber is ");
    _darkestSecret = getInput("your darkestSecret is ");
    std::cout << "Contact has been added" << std::endl;  
}

std::string Contact::getInput(std::string message)
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
void Contact::watch(int i)
{
	if (_firstName.empty() || _surnameName.empty() || _nickName.empty())
        return ;
	std::cout << "|" << std::setw(10) << i << "|";
	if (_firstName.length() > 10)
		std::cout << _firstName.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << _firstName;
	std::cout << "|";
	if (_surnameName.length() > 10)
		std::cout << _surnameName.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << _surnameName;
	std::cout << "|";
	if (_nickName.length() > 10)
		std::cout << _nickName.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << _nickName;
	std::cout << "|" << std::endl;
	
}  

void PhoneBook::print()
{
	std::cout << " -----------------PhoneBook-----------------" << std::endl;
	std::cout << "|index     |first name |last name |nickname |" << std::endl;
	for (int i = 0; i < 8; i++){
		_contacts[i].watch(i);
	}
	std::cout << " --------------------------------------------" << std::endl;
}
void PhoneBook::searchContact()
{
	int i;
	std::string index;

	std::cout << "Enter the index of the contact: ";
	std::getline(std::cin, index);
	if (std::cin.eof())
		exit (1);
	i = std::stoi(index);
	if (i >= 0 && i < 8)
		_contacts[i].init();
	else
		std::cout << "Index does not exist" << std::endl;
}