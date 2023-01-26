/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:49 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:13:30 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(string name) {
	std::cout << PURPLE << "Constructor called for ";
	std::cout << YELLOW << "[Human] ";
	std::cout << BLUE << name << WHITE;
	std::cout << std::endl;

	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[Human] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack() {
	std::cout << BLUE << this->_name << WHITE;
	std::cout << " attacks with their ";
	std::cout << GREEN << this->_weapon->getType() << WHITE;
	std::cout << std::endl;
}
