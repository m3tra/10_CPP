/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:11:58 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:23:04 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[" GREEN "Cure" YELLOW "]" WHITE << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other._type) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[" GREEN "Cure" YELLOW "]" WHITE << std::endl;
}

Cure& Cure::operator = (const Cure& other) {
	this->_type = other._type;

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[" GREEN "Cure" YELLOW "]" WHITE << std::endl << std::endl;

	return *this;
}

Cure::~Cure() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[" GREEN "Cure" YELLOW "]" WHITE << std::endl;
}



void	Cure::use(ICharacter& target) {
	std::cout << WHITE << "*" GREEN " heals " BLUE << target.getName() << WHITE "'s wounds *";
	std::cout << std::endl;
}

Cure* Cure::clone() const {
	Cure*	ret = new Cure(*this);
	std::cout << GREEN "cure" WHITE " cloned" << std::endl << std::endl;

	return ret;
}
