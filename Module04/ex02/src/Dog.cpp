/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 13:33:53 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	this->type = "Dog";
	this->_brain = new Brain();

	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[Dog]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal() {
	this->type = other.type;
	this->_brain = new Brain(*other._brain);

	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[Dog]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

Dog& Dog::operator = (const Dog& other) {
	this->type = other.type;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[Dog]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;

	return *this;
}

Dog::~Dog() {
	delete this->_brain;

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

void	Dog::eureka(const string& idea) {
	this->_brain->eureka(idea);
}

void	Dog::amnesia(const string& idea) {
	this->_brain->amnesia(idea);
}

void	Dog::listIdeas() {
	this->_brain->listIdeas();
}
