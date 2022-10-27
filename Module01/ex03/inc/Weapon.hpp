/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:34:47 by fporto            #+#    #+#             */
/*   Updated: 2022/08/03 00:45:38 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

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
