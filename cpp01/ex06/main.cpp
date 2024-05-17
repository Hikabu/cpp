/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:03:09 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/17 22:53:17 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//we have 0 for debug
//we have 1 for info
//we have 2 for warning
//we have 3 for error

//if we have 1 we should display 1,2,3 
//if we have 2 we should display 2,3 

//in code it willl be like 
//if (level == 1)
//  print from level 1 
// int getArgForSwitch(char *av)
// {
    
// }
int main(int ac, char **av) 
{
    Harl PoorHarl;
    if (ac != 2){
        std::cout << "For what i need to complain????" << std::endl;
        return (0);
    }
    else
        PoorHarl.complain(av[1]);
    return (0);
}