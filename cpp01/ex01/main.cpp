/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:47:31 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/11 20:42:50 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::string newBorn;
	std::cout << "And your horde name is: ";
	std::getline(std::cin, newBorn);
	if (newBorn.empty())
	{
		std::cout << "Seriously???" << std::endl;
		return (1);
	}
	int N = 0;
	std::cout << "You want to be a leader of what number of zombies: ";
	std::cin >> N;
	if (std::cin.fail() || N <= 0)
		return (std::cout << "We don't think it will be a horde... " << std::endl, 1);
	Zombie *forDelete = zombieHorde(N, newBorn);
		delete  [] forDelete ;
	return 0;
}
