/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:13 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 19:13:09 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include "PhoneBook.hpp"

class Contact
{
    private:
        std::string	_firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
		void getInput(std::string &str, std::string message);
    public:
        Contact();
        ~Contact();

		void init(void);
        void	SetFirstName(std::string _firstName);
		// void    SetLastName(std::string _lastName);
		// void    SetNickName(std::string _nickName);
		// void    SetFhoneNumber(std::string _phoneNumber);
		// void    SetDarkestSecret(std::string _darkestSecret);
};

#endif