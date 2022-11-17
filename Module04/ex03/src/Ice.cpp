/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:11:58 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:23:40 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[" GREEN "Ice" YELLOW "]" WHITE << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other._type) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[" GREEN "Ice" YELLOW "]" WHITE << std::endl;
}

Ice& Ice::operator = (const Ice& other) {
	this->_type = other._type;

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[" GREEN "Ice" YELLOW "]" WHITE << std::endl << std::endl;

	return *this;
}

Ice::~Ice() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[" GREEN "Ice" YELLOW "]" WHITE << std::endl;
}



void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an" GREEN " ice " WHITE "bolt at " BLUE << target.getName() << WHITE " *";
	std::cout << std::endl;
}

Ice* Ice::clone() const {
	Ice*	ret = new Ice(*this);
	std::cout << GREEN "ice" WHITE " cloned" << std::endl << std::endl;

	return ret;
}
