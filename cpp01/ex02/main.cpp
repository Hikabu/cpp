/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:29:23 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/12 17:18:00 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::cout << std::endl;
    
    std::string brain =  "\t\tHI THIS IS BRAIN";
    
    std::cout << brain << std::endl;
    
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << std::endl;
    
    std::cout << "The originall string's address is: "<< &brain << std::endl;
    std::cout << "The pointer's address: "<< stringPTR << std::endl;
    std::cout << "If we want refernce we will have address: " << &stringREF << std::endl;

    std::cout << std::endl;
    
    std::cout <<  "\033[35m" << "The originall string is : "<< brain << std::endl;
    std::cout << "The pointer is: "<< *stringPTR << std::endl;
    std::cout << "And refernce is looks like: " << stringREF << std::endl;
}