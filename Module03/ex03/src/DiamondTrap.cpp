/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:53:29 by fporto            #+#    #+#             */
/*   Updated: 2022/10/30 06:34:20 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap("no_name"), FragTrap("no_name")
{
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[DiamondTrap] ";
	std::cout << BLUE << _name << WHITE;
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << PURPLE << "Constructor called for ";
	std::cout << YELLOW << "[DiamondTrap] ";
	std::cout << BLUE << name << WHITE;
	std::cout << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[DiamondTrap] ";
	std::cout << BLUE << _name << WHITE;
	std::cout << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& other)
{
	this->_name = other._name;
	this->_hitPts = other._hitPts;
	this->_energyPts = other._energyPts;
	this->_attackDmg = other._attackDmg;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[DiamondTrap] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;

	return *this;
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
