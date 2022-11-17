/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Barrier.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:11:58 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:23:35 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Barrier.hpp"

Barrier::Barrier() : AMateria("barrier") {
	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[" GREEN "Barrier" YELLOW "]" WHITE << std::endl;
}

Barrier::Barrier(const Barrier& other) : AMateria(other._type) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[" GREEN "Barrier" YELLOW "]" WHITE << std::endl;
}

Barrier& Barrier::operator = (const Barrier& other) {
	this->_type = other._type;

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[" GREEN "Barrier" YELLOW "]" WHITE << std::endl << std::endl;

	return *this;
}

Barrier::~Barrier() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[" GREEN "Barrier" YELLOW "]" WHITE << std::endl;
}



void	Barrier::use(ICharacter& target) {
	std::cout << "* summons a" GREEN " barrier " WHITE "upon " BLUE << target.getName() << WHITE " *";
	std::cout << std::endl;
}

Barrier* Barrier::clone() const {
	Barrier*	ret = new Barrier(*this);
	std::cout << GREEN "barrier" WHITE " cloned" << std::endl << std::endl;

	return ret;
}
