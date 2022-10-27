/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:40:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/26 17:46:48 by fporto           ###   ########.fr       */
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

	ScavTrap	sTrap("Swagger");

	sTrap.showInitStats();
	sTrap.attack("Az8r");
	sTrap.takeDamage(3);
	sTrap.beRepaired(7);
	sTrap.guardGate();

	return (0);
}
