/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:44 by fporto            #+#    #+#             */
/*   Updated: 2022/08/02 20:33:52 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(string const type) : _type(type) {}

Weapon::~Weapon() {}

string	Weapon::getType() const {
	return (this->_type);
}

void	Weapon::setType(string const type) {
	this->_type = type;
}
