/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:07:14 by fporto            #+#    #+#             */
/*   Updated: 2022/10/30 06:14:54 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[ScavTrap] ";
	std::cout << BLUE << _name << WHITE;
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const string& name) : ClapTrap(name) {
	this->setHitPts(100);
	this->setEnergyPts(50);
	this->setAttackDmg(20);
	std::cout << PURPLE << "Constructor called for ";
	std::cout << YELLOW << "[ScavTrap] ";
	std::cout << BLUE << name << WHITE;
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[ScavTrap] ";
	std::cout << BLUE << _name << WHITE;
	std::cout << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other)
{
	this->_name = other._name;
	this->_hitPts = other._hitPts;
	this->_energyPts = other._energyPts;
	this->_attackDmg = other._attackDmg;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[ScavTrap] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;

	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[ScavTrap] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;
}



void	ScavTrap::guardGate() {
	std::cout << YELLOW << "[ScavTrap]";
	std::cout << WHITE << " is now in Gate Keeper mode.";
	std::cout << std::endl;
}

void	ScavTrap::attack(const string& target) {
	if (this->_energyPts) {
		this->_energyPts--;

		std::cout << YELLOW << "[ScavTrap] ";
		std::cout << BLUE << this->_name << WHITE;
		std::cout << " attacks ";
		std::cout << RED << target << WHITE;
		std::cout << ", causing ";
		std::cout << RED << this->_attackDmg << WHITE;
		std::cout << " points of damage!";
		std::cout << std::endl;
		std::cout << "    Remaining Energy: ";
		std::cout << BLUE << this->_energyPts << WHITE;
		std::cout << std::endl;
	}
}
