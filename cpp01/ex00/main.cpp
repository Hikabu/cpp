/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:46:06 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/10 17:00:32 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int main()
{
   
    {Zombie zm = Zombie();
    }
   
    std::string name;
    std::cout << "Write name: ";
    std::getline(std::cin, name);
    Zombie *forDelete = newZombie(name);
    forDelete->announce();
    randomChump("Joe Biden");
    delete (forDelete);
//    system ("leaks zombie");
//    zm.announce();
}