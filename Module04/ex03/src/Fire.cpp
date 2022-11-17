/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:11:58 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:23:29 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Fire.hpp"

Fire::Fire() : AMateria("fire") {
	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[" GREEN "Fire" YELLOW "]" WHITE << std::endl;
}

Fire::Fire(const Fire& other) : AMateria(other._type) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[" GREEN "Fire" YELLOW "]" WHITE << std::endl;
}

Fire& Fire::operator = (const Fire& other) {
	this->_type = other._type;

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[" GREEN "Fire" YELLOW "]" WHITE << std::endl << std::endl;

	return *this;
}

Fire::~Fire() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[" GREEN "Fire" YELLOW "]" WHITE << std::endl;
}



void	Fire::use(ICharacter& target) {
	std::cout << "* shoots a" GREEN " fire " WHITE "bolt at " BLUE << target.getName() << WHITE " *";
	std::cout << std::endl;
}

Fire* Fire::clone() const {
	Fire*	ret = new Fire(*this);
	std::cout << GREEN "fire" WHITE " cloned" << std::endl << std::endl;

	return ret;
}
