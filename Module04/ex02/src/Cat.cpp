/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2023/01/28 13:33:49 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	this->type = "Cat";
	this->_brain = new Brain();

	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[Cat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal() {
	this->type = other.type;
	this->_brain = new Brain(*other._brain);

	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[Cat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

Cat& Cat::operator = (const Cat& other) {
	this->type = other.type;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[Cat]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;

	return *this;
}

Cat::~Cat() {
	delete this->_brain;

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

void	Cat::eureka(const string& idea) {
	this->_brain->eureka(idea);
}

void	Cat::amnesia(const string& idea) {
	this->_brain->amnesia(idea);
}

void	Cat::listIdeas() {
	this->_brain->listIdeas();
}
