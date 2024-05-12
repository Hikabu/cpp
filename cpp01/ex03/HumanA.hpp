/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:52:24 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/12 22:02:32 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

class HumanA
{
	private:
		std::string _name;
	public:
		void	attack();
		void    setType();
		HumanA();
		~HumanA();
		HumanA(std::string name, const Weapon &_weapon);
		
};

#endif
