/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriafedorova <valeriafedorova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:19 by valeriafedo       #+#    #+#             */
/*   Updated: 2024/04/23 17:52:23 by valeriafedo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;
    std::string cmd_inpt;
    do
    {
        std::cout << "Enter the command: ADD, SEARCH, EXIT: " << std::endl;
        std::getline(std::cin, cmd_inpt);
        if (std::cin.eof())
            break;
        else if (cmd_inpt == "ADD")
            book.addContact();
        else if (cmd_inpt == "SEARCH")
            book.searchContact();
        else if (cmd_inpt == "EXIT")
            break ;
        else
            std::cout << "Command does not exist" << std::endl;
    }while (!std::cin.eof());

    return (0);
}