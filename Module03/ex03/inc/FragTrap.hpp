/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2023/06/08 21:26:25 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::string;

class	FragTrap : virtual public ClapTrap {

private:

	FragTrap();

protected:

	static const int default_hitPts = 100;
	static const int default_energyPts = 100;
	static const int default_attackDmg = 30;

public:

	FragTrap(const string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator = (const FragTrap& other);
	~FragTrap();

	void	attack(const string& target);
	void	highFivesGuys(void);
};

#endif
