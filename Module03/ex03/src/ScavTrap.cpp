/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 05:07:14 by fporto            #+#    #+#             */
/*   Updated: 2022/10/26 18:14:46 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << PURPLE << "Constructor(default) called for ";
	std::cout << YELLOW << "[ScavTrap] ";
	std::cout << BLUE << "no_name" << WHITE;
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
