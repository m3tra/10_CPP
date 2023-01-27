/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:53:29 by fporto            #+#    #+#             */
/*   Updated: 2023/01/27 16:50:24 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("no_name"), _hitPts(10), _energyPts(10), _attackDmg(0) {
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[ClapTrap] ";
	std::cout << BLUE << _name << WHITE;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const string& name) : _name(name), _hitPts(10), _energyPts(10), _attackDmg(0) {
	std::cout << PURPLE << "Constructor called for ";
	std::cout << YELLOW << "[ClapTrap] ";
	std::cout << BLUE << name << WHITE;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPts(other._hitPts), _energyPts(other._energyPts), _attackDmg(other._attackDmg) {
	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[ClapTrap] ";
	std::cout << BLUE << _name << WHITE;
	std::cout << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& other) {
	this->_name = other._name;
	this->_hitPts = other._hitPts;
	this->_energyPts = other._energyPts;
	this->_attackDmg = other._attackDmg;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[ClapTrap] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[ClapTrap] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;
}



string	ClapTrap::getName(void) const {
	return (this->_name);
}

int	ClapTrap::getHitPts(void) const {
	return (this->_hitPts);
}

int	ClapTrap::getEnergyPts(void) const {
	return (this->_energyPts);
}

int	ClapTrap::getAttackDmg(void) const {
	return (this->_attackDmg);
}

void	ClapTrap::setHitPts(unsigned int const pts) {
	if (pts < 0)
		this->_hitPts = pts;
	else
		this->_hitPts = pts;
}

void	ClapTrap::setEnergyPts(unsigned int const pts) {
	if (pts < 0)
		this->_energyPts = pts;
	else
		this->_energyPts = pts;
}

void	ClapTrap::setAttackDmg(unsigned int const pts) {
	if (pts < 0)
		this->_attackDmg = pts;
	else
		this->_attackDmg = pts;
}



void	ClapTrap::showInitStats(void) {
	std::cout << BLUE << this->_name << WHITE;
	std::cout << " spawns with ";
	std::cout << BLUE << this->_hitPts << WHITE << " Hit Points, ";
	std::cout << BLUE << this->_energyPts << WHITE << " Energy Points and ";
	std::cout << BLUE << this->_attackDmg << WHITE << " Attack Damage.";
	std::cout << std::endl << std::endl;
}

void	ClapTrap::attack(const string& target) {
	if (this->_energyPts) {
		this->_energyPts--;

		std::cout << YELLOW << "ClapTrap ";
		std::cout << WHITE << this->_name;
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

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPts -= amount;
	if (this->_hitPts < 0)
		this->_energyPts = 0;

	std::cout << BLUE << this->_name << WHITE;
	std::cout << " takes ";
	std::cout << RED << amount << WHITE;
	std::cout << " points of damage!";
	std::cout << std::endl;
	std::cout << "    Remaining Health: ";
	std::cout << BLUE << this->_hitPts << WHITE;
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPts) {
		this->_energyPts--;
		this->_hitPts += amount;

		std::cout << BLUE << this->_name << WHITE;
		std::cout << " recovers ";
		std::cout << GREEN << amount << WHITE;
		std::cout << " hit points!";
		std::cout << std::endl;
		std::cout << "    Remaining Health: ";
		std::cout << BLUE << this->_hitPts << WHITE;
		std::cout << std::endl;
		std::cout << "    Remaining Energy: ";
		std::cout << BLUE << this->_energyPts << WHITE;
		std::cout << std::endl;
	}
}
