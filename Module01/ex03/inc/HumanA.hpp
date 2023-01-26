/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:43 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:09:16 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"
#include "Color.hpp"

using std::string;

class	HumanA {

private:

	string	_name;
	Weapon&	_weapon;

public:

	void	attack();

	HumanA(string name, Weapon& weapon);
	~HumanA();

};

#endif
