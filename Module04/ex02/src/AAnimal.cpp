/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 13:41:24 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("no_type") {
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[Animal] ";
	std::cout << WHITE << "of type ";
	std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[Animal] ";
	std::cout << WHITE << "of type ";
	std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal& other) {
	this->type = other.type;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[Animal] ";
	std::cout << WHITE << "of type ";
	std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;

	return *this;
}

AAnimal::~AAnimal() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[Animal] ";
	std::cout << WHITE << "of type ";
	std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}



string	AAnimal::getType() const {
	return (this->type);
}



void	AAnimal::makeSound() const {
	std::cout << YELLOW << "[Animal]: ";
	std::cout << WHITE << "*random_sound*";
	std::cout << std::endl;
}
