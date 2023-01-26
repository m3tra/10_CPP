/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:30:00 by fporto            #+#    #+#             */
/*   Updated: 2023/01/26 11:39:00 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#include "Color.hpp"

using std::string;

class Zombie {

private:

	string	_name;

public:

	void	announce(void);

	void	setName(string name);

	Zombie();
	~Zombie();
};

Zombie*	newZombie(string name);
void	randomChump(string name);

#endif
