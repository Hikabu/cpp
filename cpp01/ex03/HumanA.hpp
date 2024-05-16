/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:52:24 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/13 18:32:04 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class Weapon;
class HumanA //can use weapon and it gas name
{
	private:
		std::string _name;
		const Weapon &_weapon;
	public:
		void	attack();
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		
};

#endif
