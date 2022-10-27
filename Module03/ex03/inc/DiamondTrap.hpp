/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/26 18:18:31 by fporto           ###   ########.fr       */
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

public:

	DiamondTrap(const string& name);
	~DiamondTrap();

	using	ScavTrap::attack;

	void	whoAmI();
};

#endif
