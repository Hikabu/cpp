/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfedorov <vfedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:25:33 by vfedorov          #+#    #+#             */
/*   Updated: 2024/05/13 18:19:16 by vfedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <string>
#include <iostream>

class Weapon   //we gave human armor and weapon 
{
    private:
        std::string _type;

    public:
        Weapon();
        ~Weapon();
        Weapon(std::string name);
        void setType(const std::string &chant);
        const std::string &getType( void ) const;
};

#endif