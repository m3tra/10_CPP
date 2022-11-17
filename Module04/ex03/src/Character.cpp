/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:11:58 by fporto            #+#    #+#             */
/*   Updated: 2022/11/17 04:12:24 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "list.hpp"

Character::Character() : ICharacter() {
	this->_name = "no_name";
	this->_nEquipedItems = 0;
	for (size_t i = 0; i < 4; i++)
		this->_pocket[i] = NULL;
	this->_unequipped = newList();

	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[Character] " WHITE "of name " BLUE << this->_name << WHITE;
	std::cout << std::endl << std::endl;
}

Character::Character(string name) : ICharacter() {
	this->_name = name;
	this->_nEquipedItems = 0;
	for (size_t i = 0; i < 4; i++)
		this->_pocket[i] = NULL;
	this->_unequipped = newList();

	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[Character] " WHITE "of name " BLUE << name << WHITE;
	std::cout << std::endl << std::endl;
}

Character::Character(const Character& other) : ICharacter() {
	this->_name = other._name;
	this->_nEquipedItems = other._nEquipedItems;
	for (size_t i = 0; i < 4; i++)
		this->_pocket[i] = other._pocket[i];
	this->_unequipped = listDup(other._unequipped);

	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[Character] " BLUE << this->_name << WHITE;
	std::cout << std::endl << std::endl;
}

Character& Character::operator = (const Character& other) {
	this->_name = other._name;
	this->_nEquipedItems = other._nEquipedItems;
	for (size_t i = 0; i < 4; i++)
		this->_pocket[i] = other._pocket[i];
	this->_unequipped = listDup(other._unequipped);

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[Character] " BLUE << this->_name << WHITE;
	std::cout << std::endl << std::endl;
	return *this;
}

Character::~Character() {
	for (size_t i = 0; i < 4; i++)
		if (_pocket[i])
			delete _pocket[i];
	freeList(this->_unequipped);

	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[Character] " BLUE << this->getName() << WHITE;
	std::cout << std::endl;
}

string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	if (_nEquipedItems == 4) {
		std::cout << BLUE << this->getName() << WHITE " tried to equip " GREEN << m->getType();
		std::cout << WHITE " but couldn't because their pockets are full.";
		std::cout << std::endl << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
		if (!_pocket[i]) {
			_pocket[i] = m;
			break;
		}
	_nEquipedItems++;
	std::cout << BLUE << this->getName() << WHITE " equipped " GREEN << m->getType() << WHITE;
	std::cout << std::endl << std::endl;
}

void Character::unequip(int idx) {
	if (!_pocket[idx]) {
		std::cout << "No " GREEN << _pocket[idx]->getType() << WHITE " for ";
		std::cout << BLUE << this->getName() << WHITE " to unequip.";
		std::cout << std::endl << std::endl;
	}
	addToList(_unequipped, _pocket[idx]);
	_pocket[idx] = NULL;
	_nEquipedItems--;
	std::cout << YELLOW "[Character] " BLUE << this->getName() << WHITE " unequipped ";
	std::cout << GREEN << _pocket[idx]->getType() << WHITE;
	std::cout << std::endl << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3)
		_pocket[idx]->use(target);
	else
		std::cout << "No " << idx << "th item to use" << std::endl;
}
