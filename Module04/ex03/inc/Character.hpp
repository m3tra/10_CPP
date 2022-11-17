/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:59:31 by fporto            #+#    #+#             */
/*   Updated: 2022/11/16 15:27:23 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "Color.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "list.hpp"

using std::string;

class Character : public ICharacter {

private:

	string		_name;
	size_t		_nEquipedItems;
	AMateria*	_pocket[4];
	t_list*		_unequipped;

public:

	Character();
	Character(string name);
	Character(const Character& other);
	Character& operator = (const Character& other);
	virtual ~Character();

	string const &	getName() const;
	void			equip(AMateria* m);
	void			unequip(int idx);
	void			use(int idx, ICharacter& target);

};

#endif
