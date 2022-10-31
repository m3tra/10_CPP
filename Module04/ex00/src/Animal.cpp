/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2022/10/31 06:04:14 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("no_type") {
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[Animal] ";
	std::cout << WHITE << "of type ";
	std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[Animal] ";
	std::cout << WHITE << "of type ";
	std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

Animal& Animal::operator = (const Animal& other) {
	this->type = other.type;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[Animal] ";
	std::cout << WHITE << "of type ";
	std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;

	return *this;
}

Animal::~Animal() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[Animal] ";
	std::cout << WHITE << "of type ";
	std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}



string	Animal::getType() const {
	return (this->type);
}



void	Animal::makeSound() const {
	std::cout << YELLOW << "[Animal]: ";
	std::cout << WHITE << "*static noise*";
	std::cout << std::endl;
}
