/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:00 by fporto            #+#    #+#             */
/*   Updated: 2022/11/11 06:06:23 by fporto           ###   ########.fr       */
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
	size_t	nIdeas = sizeof(this->ideas) / sizeof(*this->ideas);
	for (size_t i = 0; i < nIdeas; i++)
		if (other.ideas[i] != "")
			this->ideas[i] = other.ideas[i];

	std::cout << PURPLE << "Copy constructor called for ";
	std::cout << YELLOW << "[Brain]" << WHITE;
	// std::cout << WHITE << "of type ";
	// std::cout << BLUE << type << WHITE;
	std::cout << std::endl;
}

Brain& Brain::operator = (const Brain& other) {
	size_t	nIdeas = sizeof(this->ideas) / sizeof(*this->ideas);
	for (size_t i = 0; i < nIdeas; i++)
		if (other.ideas[i] != "")
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



void	Brain::eureka(const string& idea) {
	size_t	nIdeas = sizeof(this->ideas) / sizeof(*this->ideas);
	for (size_t i = 0; i < nIdeas; i++) {
		if (this->ideas[i] == "") {
			this->ideas[i] = idea;
			return;
		}
	}
	std::cout << "Brain if full of ideas" << std::endl;
}

void	Brain::amnesia(const string& idea) {
	size_t	nIdeas = sizeof(this->ideas) / sizeof(*this->ideas);
	for (size_t i = 0; i < nIdeas; i++) {
		if (this->ideas[i] == idea) {
			this->ideas[i] = "";
			return;
		}
	}
	std::cout << "Brain donb't knous anyting" << std::endl;
}

void	Brain::listIdeas() {
	size_t	nIdeas = sizeof(this->ideas) / sizeof(*this->ideas);
	for (size_t i = 0; i < nIdeas; i++) {
		if (this->ideas[i] != "") {
			std::cout << this->ideas[i] << std::endl;
		}
	}
}
