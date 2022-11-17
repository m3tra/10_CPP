/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:11:58 by fporto            #+#    #+#             */
/*   Updated: 2022/11/17 04:09:30 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	for (size_t i = 0; i < 4; i++)
		this->_known[i] = NULL;
	this->_nKnown = 0;

	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[MateriaSource]" WHITE << std::endl << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource() {
	for (size_t i = 0; i < 4; i++)
		this->_known[i] = other._known[i];
	this->_nKnown = other._nKnown;

	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[MateriaSource]" WHITE << std::endl << std::endl;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& other) {
	for (size_t i = 0; i < 4; i++)
		this->_known[i] = other._known[i];
	this->_nKnown = other._nKnown;

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[MateriaSource]" WHITE << std::endl << std::endl;

	return *this;
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4; i++)
		if (_known[i])
			delete _known[i];

	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[MateriaSource]" WHITE << std::endl;
}



void	MateriaSource::learnMateria(AMateria* materia) {
	if (this->_nKnown == 4) {
		std::cout << "Didn't learn " GREEN << materia->getType() << WHITE ". Cant't learn any more" << std::endl;
		delete materia;
		return;
	}
	for (size_t i = 0; i < 4; i++)
		if (this->_known[i] && this->_known[i]->getType() == materia->getType()) {
			std::cout << "Already learnt " GREEN << materia->getType() << WHITE << std::endl;
			delete materia;
			return;
		}
	for (size_t i = 0; i < 4; i++)
		if (!this->_known[i]) {
			this->_known[i] = materia;
			_nKnown++;
			std::cout << "Learnt " GREEN << materia->getType() << WHITE << std::endl;
			return;
		}
}

AMateria*	MateriaSource::createMateria(string const & type) {
	for (size_t i = 0; i < 4; i++)
		if (this->_known[i]->getType() == type)
			return this->_known[i]->clone();
	std::cout <<  GREEN << type << WHITE " not created. Unknown materia type" << std::endl << std::endl;
	return NULL;
}
