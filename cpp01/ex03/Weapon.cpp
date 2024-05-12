/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:29:02 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/12 20:31:56 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
Weapon::Weapon(){}

Weapon::Weapon(std::string name)
{
    this->_type = name;
}

Weapon::~Weapon(){}


void Weapon::setType(const std::string &chant)
{
    this->_type = chant;
}