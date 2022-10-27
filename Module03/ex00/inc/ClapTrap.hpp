/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/26 17:43:40 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include "Color.hpp"

using std::string;

class	ClapTrap {

protected:

	string			_name;
	unsigned int	_hitPts;
	unsigned int	_energyPts;
	unsigned int	_attackDmg;

public:

	ClapTrap(const string& name);
	~ClapTrap();

	string	getName(void) const;
	int		getHitPts(void) const;
	int		getEnergyPts(void) const;
	int		getAttackDmg(void) const;

	void	setHitPts(unsigned int const pts);
	void	setEnergyPts(unsigned int const pts);
	void	setAttackDmg(unsigned int const pts);

	void	showInitStats(void);

	void	attack(const string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
