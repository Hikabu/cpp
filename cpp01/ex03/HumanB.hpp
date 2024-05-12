/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:25:07 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/12 19:36:42 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
class HumanB
{
	private:

	public:
		void	attack();
		void	setType();
		void	setWeapon();
		HumanB(std::string who);
};

#endif