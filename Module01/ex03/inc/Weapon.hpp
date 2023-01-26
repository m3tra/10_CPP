/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:47 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 12:15:23 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include "Color.hpp"

using std::string;

class	Weapon {

private:

	string	_type;

public:

	void	setType(string const type);
	string	getType() const;

	Weapon(string const type);
	~Weapon();
};

#endif
