/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2022/11/01 06:33:18 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";

	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[Cat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}

Cat::Cat(const Cat& other) : Animal() {
	this->type = other.type;

	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[Cat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
	this->type = other.type;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[Cat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;

	return *this;
}

Cat::~Cat() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[Cat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}



void	Cat::makeSound() const {
	std::cout << YELLOW << "[Cat]: ";
	std::cout << WHITE << "*rrrrrrrr*";
	std::cout << std::endl;
}
