/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:51:14 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/17 13:18:46 by vfedorov         ###   ########.fr       */
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
	std::ifstream original(av[1]);
	std::string letsReadOriginal;
	std::string byLine;
	
	if (ac != 4){
		std::cout << "And what about to put 3 arguments?" << std::endl;
		return(1);
	}
	if (!original.is_open()){
		std::cout << "There is no file like >>" << av[1] << std::endl;
		return (1);
	}
	while ( getline (original,byLine) ){
		letsReadOriginal += byLine;
		if (!original.eof())
			letsReadOriginal += '\n';
		std::cout << byLine << std::endl;	
	}
	std::cout << "\033[35m" <<"\tNow we will replace some elements" << std::endl;
	original.close();
	
	std::string toReplace = av[2];
	std::string forWhatToReplace = av[3];
	size_t searchCursor = 0;
	size_t toReplaceLenght = toReplace.length();
	size_t skipReplace = forWhatToReplace.length();

	if (toReplace.empty() || forWhatToReplace.empty()){
		std::cout << "And where are the elements for fraud?" << std::endl;
	}
	std::cout << "Go to itwasmade.txt" << std::endl;
	
	while ((searchCursor = letsReadOriginal.find(toReplace, searchCursor)) != std::string::npos)
	{
		letsReadOriginal.erase(searchCursor, toReplaceLenght);
		letsReadOriginal.insert(searchCursor, forWhatToReplace);
		searchCursor += skipReplace;
	}
	ComesFromoldfile.open ("itwasmade.txt");
	ComesFromoldfile << letsReadOriginal << std::endl;
	return (0);
}