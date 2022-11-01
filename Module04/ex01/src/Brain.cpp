/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2022/11/01 04:07:57 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << PURPLE << "Default constructor called for ";
	std::cout << YELLOW << "[Brain]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

Brain::Brain(const Brain& other) {
	for (size_t i = 0; i < this->ideas->length(); i++)
		this->ideas[i] = other.ideas[i];

	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[Brain]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

Brain& Brain::operator = (const Brain& other) {
	for (size_t i = 0; i < this->ideas->length(); i++)
		this->ideas[i] = other.ideas[i];

	std::cout << PURPLE << "Copy assignment of ";
	std::cout << YELLOW << "[Brain]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;

	return *this;
}

Brain::~Brain() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[Brain]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << this->type << WHITE;
	std::cout << std::endl;
}
