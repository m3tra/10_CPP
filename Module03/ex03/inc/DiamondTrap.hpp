/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/30 06:30:11 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

using std::string;

class	DiamondTrap : public ScavTrap, FragTrap {

private:

	string	_name;
	using	FragTrap::_hitPts;
	using	ScavTrap::_energyPts;
	using	FragTrap::_attackDmg;

	DiamondTrap();

public:

	DiamondTrap(const string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator = (const DiamondTrap& other);
	~DiamondTrap();

	using	ScavTrap::attack;

	void	whoAmI();
};

#endif
