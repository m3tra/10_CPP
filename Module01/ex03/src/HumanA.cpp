/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:42 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:11:54 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon& weapon) : _weapon(weapon) {
	std::cout << PURPLE << "Constructor called for ";
	std::cout << YELLOW << "[Human] ";
	std::cout << BLUE << name << WHITE;
	std::cout << std::endl;

	this->_name = name;
}

HumanA::~HumanA() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[Human] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;
}

void	HumanA::attack() {
	std::cout << BLUE << this->_name << WHITE;
	std::cout << " attacks with their ";
	std::cout << GREEN << this->_weapon.getType() << WHITE;
	std::cout << std::endl;
}
