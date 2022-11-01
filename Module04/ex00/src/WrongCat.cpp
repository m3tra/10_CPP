/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2022/11/01 06:32:51 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";

	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[WrongCat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	this->type = other.type;

	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[WrongCat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& other) {
	this->type = other.type;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[WrongCat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;

	return *this;
}

WrongCat::~WrongCat() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[WrongCat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}



void	WrongCat::makeSound() const {
	std::cout << YELLOW << "[WrongCat]: ";
	std::cout << WHITE << "*rrrrrrrr*";
	std::cout << std::endl;
}
