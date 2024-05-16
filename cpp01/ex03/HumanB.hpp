/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:25:07 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/13 18:32:26 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

class Weapon;
class HumanB //has name and weapon 
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		void	attack( void ) const;
		void	setWeapon(Weapon &weapon);
		HumanB(const std::string &name);
		~HumanB();
};

#endif