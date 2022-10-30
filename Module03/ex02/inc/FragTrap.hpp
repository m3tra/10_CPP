/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:16:25 by fporto            #+#    #+#             */
/*   Updated: 2022/10/30 06:23:17 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::string;

class	FragTrap : public ClapTrap {

private:

	FragTrap();

public:

	FragTrap(const string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator = (const FragTrap& other);
	~FragTrap();

	void	attack(const string& target);
	void	highFivesGuys(void);
};

#endif
