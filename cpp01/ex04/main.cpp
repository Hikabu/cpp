/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:51:14 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/13 20:47:28 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	(void) av;
	(void) ac;
	std::ofstream ComesFromoldfile;
	std::ifstream original ("filname.txt");
	std::string letsReadOriginal;
	
	original.open ("filname.txt");
	
	if (original.is_open())
	{
		while ( getline (original,letsReadOriginal) )
		{
			std::cout << letsReadOriginal << std::endl;
			printf("im here\n");
		}
		original.close();
	}
	else
		std::cout << "Unable to open";
	// ComesFromoldfile.open ("itwasmade.txt");
	// ComesFromoldfile << "I HAVE WRITTED HERE SOME STRANGE LINE\n";
	// ComesFromoldfile.close();
	return (0);
}