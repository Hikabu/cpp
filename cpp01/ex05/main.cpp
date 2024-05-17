/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:05:59 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/17 19:57:10 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl whyHarl;
    whyHarl.complain("DEBUG");
    whyHarl.complain("INFO");
    whyHarl.complain("WARNING");
    whyHarl.complain("ERROR");
}