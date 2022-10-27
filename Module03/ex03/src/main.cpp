/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:40:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/26 18:20:25 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {

	ClapTrap	cTrap("Swagger");

	cTrap.showInitStats();
	cTrap.attack("Az8r");
	cTrap.takeDamage(3);
	cTrap.beRepaired(7);

	std::cout << std::endl;

	ScavTrap	sTrap("Manel");

	sTrap.showInitStats();
	sTrap.attack("Az8r");
	sTrap.takeDamage(10);
	sTrap.beRepaired(5);
	sTrap.guardGate();

	std::cout << std::endl;

	FragTrap	fTrap("Mitra");

	fTrap.showInitStats();
	fTrap.attack("Az8r");
	fTrap.takeDamage(4);
	fTrap.beRepaired(8);
	fTrap.highFivesGuys();

	std::cout << std::endl;

	DiamondTrap	dTrap("Monster");

	dTrap.showInitStats();
	dTrap.attack("Az8r");
	dTrap.takeDamage(8);
	dTrap.beRepaired(13);
	dTrap.whoAmI();

	std::cout << std::endl;

	return (0);
}
