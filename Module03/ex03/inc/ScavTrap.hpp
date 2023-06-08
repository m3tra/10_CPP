/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2023/06/08 21:26:35 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::string;

class	ScavTrap : virtual public ClapTrap {

private:

	ScavTrap();

protected:

	static const int default_hitPts = 100;
	static const int default_energyPts = 50;
	static const int default_attackDmg = 20;

public:

	ScavTrap(const string& name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator = (const ScavTrap& other);
	~ScavTrap();

	void	guardGate();
	void	attack(const string& target);
};

#endif
