/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:11:58 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:32:27 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("no_type") {
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[AMateria] " WHITE "of type ";
	std::cout << GREEN << _type << WHITE;
	std::cout << std::endl;
}

AMateria::AMateria(string const & type) : _type(type) {
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[AMateria] " WHITE "of type ";
	std::cout << GREEN << type << WHITE;
	std::cout << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[AMateria] " WHITE "of type ";
	std::cout << GREEN << _type << WHITE;
	std::cout << std::endl;
}

AMateria& AMateria::operator = (const AMateria& other) {
	this->_type = other._type;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[AMateria] " WHITE "of type ";
	std::cout << GREEN << this->_type << WHITE;
	std::cout << std::endl;

	return *this;
}

AMateria::~AMateria() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[AMateria] " WHITE "of type ";
	std::cout << GREEN << this->_type << WHITE;
	std::cout << std::endl << std::endl;
}



string const &	AMateria::getType() const {
	return	this->_type;
}

void	AMateria::use(ICharacter& target) {
		std::cout << GREEN << this->getType();
		std::cout << WHITE << ": * is used on " << target.getName() << " *";
		std::cout << std::endl;
}
