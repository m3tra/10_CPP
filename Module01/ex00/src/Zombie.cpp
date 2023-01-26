/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:29:55 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 11:38:58 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << PURPLE << "Constructor called for ";
	std::cout << YELLOW << "[Zombie]";
	std::cout << std::endl;
}

Zombie::~Zombie() {
	std::cout << PURPLE << "Destructor called for ";
	std::cout << YELLOW << "[Zombie] ";
	std::cout << BLUE << this->_name << WHITE;
	std::cout << std::endl;
}

void	Zombie::announce(void) {
	std::cout << BLUE << this->_name << WHITE;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(string name) {
	this->_name = name;
}
