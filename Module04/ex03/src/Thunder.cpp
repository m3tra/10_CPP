/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Thunder.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:11:58 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 16:52:43 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Thunder.hpp"

Thunder::Thunder() : AMateria("thunder") {
	std::cout << PURPLE "Default constructor called for ";
	std::cout << YELLOW "[" GREEN "Thunder" YELLOW "]" WHITE << std::endl;
}

Thunder::Thunder(const Thunder& other) : AMateria(other._type) {
	std::cout << PURPLE "Copy constructor called for ";
	std::cout << YELLOW "[" GREEN "Thunder" YELLOW "]" WHITE << std::endl;
}

Thunder& Thunder::operator = (const Thunder& other) {
	this->_type = other._type;

	std::cout << PURPLE "Copy assignment of ";
	std::cout << YELLOW "[" GREEN "Thunder" YELLOW "]" WHITE << std::endl << std::endl;

	return *this;
}

Thunder::~Thunder() {
	std::cout << PURPLE "Destructor called for ";
	std::cout << YELLOW "[" GREEN "Thunder" YELLOW "]" WHITE << std::endl;
}



void	Thunder::use(ICharacter& target) {
	std::cout << "* shoots a" GREEN " thunder " WHITE "bolt at " BLUE << target.getName() << WHITE " *";
	std::cout << std::endl;
}

Thunder* Thunder::clone() const {
	Thunder*	ret = new Thunder(*this);
	std::cout << GREEN "thunder" WHITE " cloned" << std::endl << std::endl;

	return ret;
}
