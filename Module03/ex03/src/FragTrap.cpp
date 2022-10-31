/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:07:14 by fporto            #+#    #+#             */
/*   Updated: 2022/10/31 04:52:37 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[FragTrap] ";
	std::cout << BLUE << _name << WHITE;
	std::cout << std::endl;
}

FragTrap::FragTrap(const string& name) : ClapTrap(name) {
	this->setHitPts(100);
	this->setEnergyPts(100);
	this->setAttackDmg(30);
	std::cout << PURPLE << "Constructor called for ";
	std::cout << YELLOW << "[FragTrap] ";
	std::cout << BLUE << name << WHITE;
	std::cout << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[FragTrap] ";
	std::cout << BLUE << _name << WHITE;
	std::cout << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other) {
	this->_name = other._name;
	this->_hitPts = other._hitPts;
	this->_energyPts = other._energyPts;
	this->_attackDmg = other._attackDmg;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[FragTrap] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;

	return *this;
}

FragTrap::~FragTrap() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[FragTrap] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;
}



void	FragTrap::attack(const string& target) {
	if (this->_energyPts) {
		this->_energyPts--;

		std::cout << YELLOW << "[FragTrap] ";
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

void	FragTrap::highFivesGuys(void) {
	std::cout << YELLOW << "[FragTrap] " WHITE << "*";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << " requests a high five*" << WHITE;
	std::cout << std::endl;
}
