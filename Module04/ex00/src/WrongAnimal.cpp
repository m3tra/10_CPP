/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 12:45:36 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("no_type") {
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[WrongAnimal]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[WrongAnimal]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other) {
	this->type = other.type;

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[WrongAnimal]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;

	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[WrongAnimal]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}



string	WrongAnimal::getType() const {
	return (this->type);
}



void	WrongAnimal::makeSound() const {
	std::cout << YELLOW << "[WrongAnimal]: ";
	// std::cout << WHITE << "▓▚░▟▞▐▞▟▚░";
	std::cout << WHITE << "?:&>`'*/%?";
	std::cout << std::endl;
}
