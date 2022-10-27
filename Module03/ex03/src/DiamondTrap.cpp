/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:53:29 by fporto            #+#    #+#             */
/*   Updated: 2022/10/26 18:18:10 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << PURPLE << "Constructor called for ";
	std::cout << YELLOW << "[DiamondTrap] ";
	std::cout << BLUE << name << WHITE;
	std::cout << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[DiamondTrap] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;
}



void	DiamondTrap::whoAmI() {
	std::cout << YELLOW << "[DiamondTrap]" << WHITE << " name: ";
	std::cout << BLUE << this->_name;
	std::cout << std::endl;
	std::cout << YELLOW << "[ClapTrap]"  << WHITE << " name: ";
	std::cout << BLUE << ClapTrap::_name << WHITE;
	std::cout << std::endl;
}
