/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:49 by fporto            #+#    #+#             */
/*   Updated: 2022/08/02 20:36:42 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(string name) {
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
