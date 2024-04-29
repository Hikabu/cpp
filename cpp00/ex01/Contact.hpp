/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:13 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/29 16:49:49 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

// # include "PhoneBook.hpp"

# include <iostream>
class Contact
{
    private:
        std::string	_firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
		
    public:
        Contact();
        ~Contact();

		void init(void);
        void	SetFirstName(std::string _firstName);
        void getInput(std::string &str, std::string message);
		// void    SetLastName(std::string _lastName);
		// void    SetNickName(std::string _nickName);
		// void    SetFhoneNumber(std::string _phoneNumber);
		// void    SetDarkestSecret(std::string _darkestSecret);
};

#endif