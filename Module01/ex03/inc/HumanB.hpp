/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:46 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:09:22 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "Color.hpp"

using std::string;

class	HumanB {

private:

	string	_name;
	Weapon*	_weapon;

public:

	void	attack();
	void	setWeapon(Weapon& weapon);

	HumanB(string name);
	~HumanB();

};

#endif
