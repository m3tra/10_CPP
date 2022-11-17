/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:04:13 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 15:27:40 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "AMateria.hpp"

using std::string;

class AMateria;

class ICharacter {

public:

	virtual ~ICharacter() {}

	virtual string const &	getName() const = 0;
	virtual void			equip(AMateria* m) = 0;
	virtual void			unequip(int idx) = 0;
	virtual void			use(int idx, ICharacter& target) = 0;

};

#endif
