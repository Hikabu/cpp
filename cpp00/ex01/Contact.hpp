/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:13 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/05/01 16:53:02 by vfedorov         ###   ########.fr       */
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
        std::string _surnameName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
		int _index;
    public:
        Contact();
        ~Contact();
        std::string getInput(std::string message);
        void setIndex(int i);
        void init(void);
        void watch(int i);
};

#endif