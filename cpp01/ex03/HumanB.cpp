/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:28:22 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/13 18:28:51 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB( const std::string &name)
{
    this->_name = name;
    this->_weapon = NULL;
}

void HumanB::attack() const
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << "Atack stranger but take heed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

HumanB::~HumanB()
{
    std::cout << "WE R DEAD enough" << std::endl;
}