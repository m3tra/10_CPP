/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2022/11/01 06:33:27 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";

	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[Dog]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}

Dog::Dog(const Dog& other) : Animal() {
	this->type = other.type;

	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[Dog]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
	this->type = other.type;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[Dog]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;

	return *this;
}

Dog::~Dog() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[Dog]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}



void	Dog::makeSound() const {
	std::cout << YELLOW << "[Dog]: ";
	std::cout << WHITE << "RURURURURURU";
	std::cout << std::endl;
}
