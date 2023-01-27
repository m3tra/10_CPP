/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:40:25 by fporto            #+#    #+#             */
/*   Updated: 2023/01/27 16:49:34 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap	cTrap("Swagger");

	cTrap.showInitStats();
	cTrap.attack("Az8r");
	cTrap.takeDamage(3);
	cTrap.beRepaired(7);

	std::cout << std::endl;

	ScavTrap	sTrap("Swagger");

	sTrap.showInitStats();
	sTrap.attack("Az8r");
	sTrap.takeDamage(3);
	sTrap.beRepaired(7);
	sTrap.guardGate();

	std::cout << std::endl;

	return (0);
}
