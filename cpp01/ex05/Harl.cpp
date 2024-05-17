/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:22:40 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/17 20:01:16 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug()
{
    std::cout <<  "\033[36m" << "\t\t\t\t[DEBUG]" << std::endl;
    std::cout << "\t I love having extra bacon for my" << std::endl <<
        "\t7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl <<
        "\tI really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "\033[35m" << "\t\t\t\t[INFO]" << std::endl;
    std::cout <<   "\tI cannot believe adding extra bacon costs more money."  << std::endl <<
        "\tYou didn’t put enough bacon in my burger!"  << std::endl <<
        "\tIf you did, I wouldn’t be asking for more!"  << std::endl << std::endl;
}

void Harl::warning()
{
    std::cout << "\033[33m" <<  "\t\t\t\t[WARNING]" << std::endl;
    std::cout << "\tI think I deserve to have some extra bacon for free." << std::endl <<
    "\tI’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error()
{
    std::cout << "\033[31m" << "\t\t\t\t[ERROR]" << std::endl;
    std::cout << "\tThis is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*CopmlaintByLevel[4])(void) =  {&Harl::debug, &Harl::info,
        &Harl::warning, &Harl::error} ;
    std::string cases[4] = {"DEBUG", "INFO", "WARNING", "ERROR"} ;
    int i = 0;
    for (; i < 4; ++i) {
            if (level == cases[i])
                break;
        }
    switch (i)
    {
        case 0:
            (this->*CopmlaintByLevel[0])();
            break ;
        case 1:
            (this->*CopmlaintByLevel[1])(); 
            break ;   
        case 2:
            (this->*CopmlaintByLevel[2])();
            break ;
        case 3:
            (this->*CopmlaintByLevel[3])();
            break ;
        default:
            std::cout << "Unknown level: " << level << std::endl;
            break;
    }
}