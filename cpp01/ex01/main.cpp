/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:47:31 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/10 22:39:31 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zm;

    std::string newBorn;
    std::cout << "And your horde name is: ";
    std::getline(std::cin, newBorn);
    zombieHorde()
}