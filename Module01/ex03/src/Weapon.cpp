/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:44 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:15:31 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(string const type) : _type(type) {
	std::cout << PURPLE << "Constructor called for ";
	std::cout << YELLOW << "[Weapon] ";
	std::cout << GREEN << type << WHITE;
	std::cout << std::endl;
}

Weapon::~Weapon() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[Weapon] ";
	std::cout << GREEN << this->_type << WHITE;
	std::cout << std::endl;
}

string	Weapon::getType() const {
	return (this->_type);
}

void	Weapon::setType(string const type) {
	this->_type = type;
}
